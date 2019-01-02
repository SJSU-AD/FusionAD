#include "control/control_node.h"

namespace fusionad
{
namespace control
{
namespace node
{
  ControlNode::ControlNode():
  pathInitialized(false),
  stateInitialized(false),
  autonomousDrivingFlag(false),
  obstacleDetected(false),
  debug(false),
  internalFailFlag(false),
  externalFailFlag(false)
  {
    roll = 0;
    pitch = 0;
    yaw = 0;
    controlGain_p = 0;
    controlGain_d = 0;
    targetPointIndex = 0;
    dynamicArraySize = 0;
  }

  ControlNode::~ControlNode()
  {
  }

  void ControlNode::initRosComm()
  {
    //Create Timer Function for running the control stack
    control_cmd_timer = control_nh.createTimer(ros::Duration(control_loop_time), &ControlNode::masterTimerCallback, this);  
    
    //Control Main publisher
    control_main_pub = control_nh.advertise<interface::Controlcmd>("/control/controlcmd", 100);
    ROS_INFO_ONCE("Control Node Master Publisher Set!");

    if(debug)
    {
      //Control debug publisher
      control_debug_pub = control_nh.advertise<interface::Stanley_debug>("/control/debug", 100);
      ROS_WARN_ONCE("Control DEBUG Publisher Set!");      
    }

    //Control Trajectory Subscriber
    path_sub = control_nh.subscribe("/planning/trajectory", 100, &ControlNode::pathCallback, this);
    ROS_INFO_ONCE("Control Node Path Subscriber Set!");

    //Control State Subscriber
    localization_sub = control_nh.subscribe("/localization/state", 100, &ControlNode::stateCallback, this);
    ROS_INFO_ONCE("Control Node Path Subscriber Set!");

    obstacle_sub = control_nh.subscribe("/localization/obstacle", 100, &ControlNode::obstacleCallback, this);
    ROS_INFO_ONCE("Control Node Obstacle Subscriber Set!");

    mode_sub = control_nh.subscribe("/control/mode", 100, &ControlNode::modeCallback, this);
    ROS_INFO_ONCE("Control Node Mode Subscriber Set!");
    
  }

  bool ControlNode::getParameter()
  {
    //Obtain parameter to initialize the node
    std::string node_name = ros::this_node::getName();
    if(!control_nh.param<float>(node_name+"/control_p_gain",controlGain_p, 1 ))
    {
      ROS_WARN("Param control gain not set, using default - 1");
      return false;
    }
    if(!control_nh.param<bool>(node_name+"/debug",debug, false))
    {
      ROS_WARN("Param control debug not set, using default - false");
      return false;
    }
    if(!control_nh.param<float>(node_name+"/control_d_gain",controlGain_d, 1))
    {
      ROS_WARN("Param control derivative gain not set, using default - 1");
      return false;
    }
    ROS_INFO_ONCE("-------- Param Retrieved - Good --------");
    return true;    
  }
  


  void ControlNode::pathCallback(const nav_msgs::Path& trajectory_msg)
  {
    //Flush all vectors at the end
    pathPointListX.clear();
    pathPointListY.clear(); 
    dynamicArraySize = trajectory_msg.poses.size();
    
    lat_control.debug_info.pathSize = dynamicArraySize;
    //pathPointListX.resize(dynamicArraySize);
    //pathPointListY.resize(dynamicArraySize);
    if(pathPointListX.empty())
    {
      for(size_t i = 0; i < trajectory_msg.poses.size(); i++)
      {
        pathPointListX.push_back(trajectory_msg.poses[i].pose.position.x);
        pathPointListY.push_back(trajectory_msg.poses[i].pose.position.y);
      }
    }
    else
    {
      internalFailFlag = true;
      ROS_FATAL("Path List not flushed! Abort!");
    }

    if(!pathInitialized)
    {
      pathInitialized = true;
    }
  }

  void ControlNode::stateCallback(const interface::Chassis_state& veh_state_msg)
  {
    // Unpack orientation of the vehicle
    tf2::Quaternion quaternion;
    tf2::convert(veh_state_msg.Position.pose.orientation, quaternion);
    tf2::Matrix3x3 quaternion_matrix(quaternion);
    quaternion_matrix.getRPY(roll, pitch, yaw);
    vehicle_heading = static_cast<float>(yaw);

    // Unpack linear velocity
    linear_velocity = sqrt(std::pow(veh_state_msg.Speed.twist.linear.x, 2) 
                           + std::pow(veh_state_msg.Speed.twist.linear.y,2));
    
    // Unpack vehicle planar position
    position(0) = veh_state_msg.Position.pose.position.x;
    position(1) = veh_state_msg.Position.pose.position.y;  
  
    if(!stateInitialized)
    {
      stateInitialized = true;
    }
  }

  void ControlNode::obstacleCallback(const std_msgs::Bool& obstacleDetection_msg)
  {
    obstacleDetected = obstacleDetection_msg.data;
  }

  void ControlNode::modeCallback(const std_msgs::Bool& autonomous_mode_msg)
  {
    autonomousDrivingFlag = autonomous_mode_msg.data;
  }

  int getTargetWaypoint(const nav_msgs::Path& current_path, const interface::Chassis_state& current_position)
  {
    //TODO: Implement node side logic and clean up after selector algorithm PR is approved.
  }

  void ControlNode::masterTimerCallback(const ros::TimerEvent& controlTimeEvent)
  {
    interface::Controlcmd control_core_command;
    if(obstacleDetected)
    {
      ROS_WARN("Obstacle Ahead, Vehicle Stopped!");
    }

    float steering_angle = 0;
    float cmd_linear_vel = 0;   

    if((stateInitialized) && (pathInitialized) && (!obstacleDetected) && (!internalFailFlag) && (!goalReached) && (autonomousDrivingFlag) && (!externalFailFlag))
    {
      std::cout << "Entered Timer loop " << std::endl;
      //TODO: Add new backward search prevention algo
      //Compute the closest waypoint
      std::vector<float> distance;
      for(size_t i = 0; i < pathPointListX.size(); i++)
      {
        distance.push_back(std::sqrt(std::pow((position(0) - pathPointListX[i]),2)
                               + std::pow((position(1) - pathPointListY[i]),2)));
      }

      float least_distance = distance[0];

      for(size_t j=0; j < distance.size(); j++)
      {
        if(least_distance > distance[j])
        {
          least_distance = distance[j];
          targetPointIndex = j;
        }
      }

      lat_control.debug_info.currentWPIndex = targetPointIndex;
      lat_control.debug_info.distance_to_wp = least_distance;

      //Check if goal is reached
      /* Goal reached definition:
          - Reference index is last index
          - Vehicle's relative distance to the last index waypoint is less than 20 cm
      */
      if((targetPointIndex == (distance.size() - 1)) && (least_distance <= 20))
      {
        //Goal reached
        goalReached = true;
        ROS_INFO("Goal reached. End of Path. Autonomy mode set to manual.");
        autonomousDrivingFlag = false;
        return;
      }

      steering_angle = lat_control.computeSteeringAngle(position,
                                                        pathPointListX,
                                                        pathPointListY,
                                                        linear_velocity,
                                                        targetPointIndex,
                                                        vehicle_heading,
                                                        controlGain_p,
                                                        controlGain_d,
                                                        dynamicArraySize
                                                        );
      //TODO: Implement longitudinal Control --> blocker: Planning
      //TODO: Replace throttle function with a lamda function --> lamda(throttle, brake)
      cmd_linear_vel = 50; //In percentage

      //IF DEBUG IS TRUE
      if(debug)
      {
        control_core_command.debugControl = true;
        lat_control.debug_info.stanleyGain_p = controlGain_p;
        lat_control.debug_info.stanleyGain_d = controlGain_d;
        //lat_control.debug_info.estimated_heading = estimated_orientation;
        control_debug_pub.publish(lat_control.debug_info);
      }   

        // Check calculation integrity of lateral controller, invalid calculation will bring vehicle to halt
      if(lat_control.debug_info.pathHeadingCalcInvalid     || 
         lat_control.debug_info.crossTrackErrorCalcInvalid ||
         lat_control.debug_info.headingErrorCalcInvalid    || 
         lat_control.debug_info.steeringAngleCalcInvalid)
      {
        ROS_FATAL("Lateral Controller Error, Vehicle operation stopped! ");
        control_core_command.steeringAngle = 0;
        control_core_command.throttle = 0; 
        control_core_command.inOperation = false;
      }
      else
      {
        control_core_command.steeringAngle = steering_angle;
        control_core_command.throttle = cmd_linear_vel; 
        control_core_command.inOperation = true;
      }  
    }
    else
    {
      control_core_command.inOperation = false;
      control_core_command.steeringAngle = 0;
      control_core_command.throttle = 0;
    }

    //PUBLISH CONTROL MESSAGE
    control_main_pub.publish(control_core_command);
  }
}
}
}

int main(int argc, char **argv)
{
  //ROS node initialization as "control core"
  ros::init(argc, argv, "core_control");
  fusionad::control::node::ControlNode core_control;
  if(!core_control.getParameter())
  {
    ROS_FATAL("Parameter Failed! Abort!");
    core_control.externalFailFlag = true;
  }
  core_control.initRosComm();
  while(ros::ok())
  {
    //Execute all callbacks first to initiate the variables
    ros::spinOnce();
  }
  return 0;
}
