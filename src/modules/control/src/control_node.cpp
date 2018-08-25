#include "control/control_node.h"

namespace fusionad
{
namespace control
{
namespace node
{
  control_node::control_node():
  pathInitialized(false),
  stateInitialized(false),
  imuInitialized(false),
  autonomousDrivingFlag(false),
  obstacleDetected(false),
  debug(false),
  failFlag(false)
  {
    roll = 0;
    pitch = 0;
    yaw = 0;
    controlGain = 0;
    targetPointIndex = 0;
    dynamicArraySize = 0;
    estimated_orientation = 0;
  }

  control_node::~control_node()
  {
  }

  void control_node::initRosComm()
  {
    //Create Timer Function for running the control stack, currently set to 25 hz
    control_cmd_timer = control_nh.createTimer(ros::Duration(0.04), &control_node::masterTimerCallback, this);  
    
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
    path_sub = control_nh.subscribe("/planning/trajectory", 100, &control_node::pathCallback, this);
    ROS_INFO_ONCE("Control Node Path Subscriber Set!");

    //Control State Subscriber
    localization_sub = control_nh.subscribe("/localization/state", 100, &control_node::stateCallback, this);
    ROS_INFO_ONCE("Control Node Path Subscriber Set!");

    imu_sub = control_nh.subscribe("/imu", 100, &control_node::imuCallback, this);
    ROS_INFO_ONCE("Control Node IMU Subscriber Set!");

    obstacle_sub = control_nh.subscribe("/localization/obstacle", 100, &control_node::obstacleCallback, this);
    ROS_INFO_ONCE("Control Node Obstacle Subscriber Set!");

    mode_sub = control_nh.subscribe("/control/mode", 100, &control_node::modeCallback, this);
    ROS_INFO_ONCE("Control Node Mode Subscriber Set!");
  }

  bool control_node::getParameter()
  {
    //Obtain parameter to initialize the node
    std::string node_name = ros::this_node::getName();
    if(!control_nh.param<float>(node_name+"/control_gain",controlGain, 1 ))
    {
      ROS_WARN("Param control gain not set, using default - 1");
      return false;
    }
    if(!control_nh.param<bool>(node_name+"/debug",debug, false))
    {
      ROS_WARN("Param control debug not set, using default - false");
      return false;
    }
    ROS_INFO_ONCE("-------- Param Retrieved - Good --------");
    return true;    
  }
  


  void control_node::pathCallback(const nav_msgs::Path& trajectory_msg)
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
      failFlag = true;
      ROS_FATAL("Path List not flushed! Abort!");
    }

    if(!pathInitialized)
    {
      pathInitialized = true;
    }
  }

  void control_node::stateCallback(const interface::Chassis_state& veh_state_msg)
  {
    position(0) = veh_state_msg.Position.pose.position.x;
    position(1) = veh_state_msg.Position.pose.position.y;
    //linear_velocity = veh_state_msg.Speed.twist.linear.x;
    linear_velocity = 0.5;
    //std::cout << position(0) << std::endl;
    orientation_pos_vector(0) = position(0) - prev_pos[0];   //X delta
    orientation_pos_vector(1) = position(1) - prev_pos[1];   //Y delta
    float veh_theta = std::atan2(orientation_pos_vector(1), orientation_pos_vector(0));
    

    prev_pos[0] = position(0);
    prev_pos[1] = position(1);

    if(std::isfinite(estimated_orientation))
    {
      lat_control.debug_info.estimated_heading = estimated_orientation;
    }
    else
    {
      std::cout << "Heading Error Calculation Is Not Finite!" << std::endl;
      failFlag = true;
    }   

    if(!stateInitialized)
    {
      stateInitialized = true;
    }
  }

  void control_node::imuCallback(const sensor_msgs::Imu& inertial_msg)
  {
    tf::Quaternion chassis_quaternion(inertial_msg.orientation.x,
                                      inertial_msg.orientation.y,
                                      inertial_msg.orientation.z,
                                      inertial_msg.orientation.w);
    tf::Matrix3x3 temp_rotation_matrix(chassis_quaternion);
    temp_rotation_matrix.getRPY(roll, pitch, yaw);

    lat_control.debug_info.imu_heading = yaw;
    if(!imuInitialized)
    {
      imuInitialized = true;
    }
  }

  void control_node::obstacleCallback(const std_msgs::Bool& obstacleDetection_msg)
  {
    obstacleDetected = obstacleDetection_msg.data;
  }

  void control_node::modeCallback(const std_msgs::Bool& autonomous_mode_msg)
  {
    autonomousDrivingFlag = autonomous_mode_msg.data;
  }

  void control_node::masterTimerCallback(const ros::TimerEvent& controlTimeEvent)
  {
    interface::Controlcmd control_core_command;
    if(obstacleDetected)
    {
      ROS_WARN("Obstacle Ahead, Vehicle Stopped!");
    }

    float steering_angle;
    float cmd_linear_vel;   

    if((imuInitialized) && (stateInitialized) && (pathInitialized) && (!obstacleDetected) && (!failFlag) && (!goalReached) && (autonomousDrivingFlag))
    {
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
      if((targetPointIndex == (distance.size() - 1)))
      {
        //Goal reached
        goalReached = true;
        ROS_WARN("Goal reached. End of Path. Autonomy mode set to manual.");
        autonomousDrivingFlag = false;
      }
      else
      {
        goalReached = false;
      }

      //Changed the controller to run on estimation 
      /*steering_angle = lat_control.computeSteeringAngle(position,
                                            pathPointListX,
                                            pathPointListY,
                                            linear_velocity,
                                            targetPointIndex,
                                            yaw,
                                            controlGain
                                            );*/
      steering_angle = lat_control.computeSteeringAngle(position,
                                                    pathPointListX,
                                                    pathPointListY,
                                                    linear_velocity,
                                                    targetPointIndex,
                                                    estimated_orientation,
                                                    controlGain,
                                                    dynamicArraySize
                                                    );
      //TODO: Implement longitudinal Control --> blocker: Planning
      //TODO: Replace throttle function with a lamda function --> lamda(throttle, brake)
      cmd_linear_vel = 50; //In percentage

      //IF DEBUG IS TRUE
      if(debug)
      {
        control_core_command.debugControl = true;
        control_debug_pub.publish(lat_control.debug_info);
      }
      else
      {
        control_core_command.debugControl = false;
      }     

      control_core_command.steeringAngle = steering_angle;
      control_core_command.throttle = cmd_linear_vel; 
      control_core_command.inOperation = true;  
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
  fusionad::control::node::control_node core_control;
  if(!core_control.getParameter())
  {
    ROS_FATAL("Parameter Failed! Abort!");
    //TODO:Put a backup plan here, in case failure to retrieve param
  }
  core_control.initRosComm();
  while(ros::ok())
  {
    //Execute all callbacks first to initiate the variables
    ros::spinOnce();
  }
  return 0;
}
