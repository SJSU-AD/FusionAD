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
    controlGain_p = 0;
    controlGain_d = 0;
    targetPointIndex = 0;
    dynamicArraySize = 0;
    waypoint_proximity_range = 0;
    waypoint_heading_error_range = 0;
    controlGain_soft = 0;
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
    ROS_INFO_ONCE("Control Node State Subscriber Set!");

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
    if(!control_nh.param<float>(node_name+"/control_soft_gain",controlGain_soft, 0.5))
    {
      ROS_WARN("Param control soft gain not set, using default - 0.5");
      return false;
    }    
    if(!control_nh.param<float>(node_name+"/waypoint_proximity_range", waypoint_proximity_range, 1))
    {
      ROS_WARN("Param Waypoint Proximity Range not set, using default - 1 meter");
      return false;
    }    
    if(!control_nh.param<float>(node_name+"/waypoint_heading_error_range", waypoint_heading_error_range, M_PI_2))
    {
      ROS_WARN("Param Waypoint Heading Error Range not set, using default - PI/2 Radians");
      return false;
    }        
    ROS_INFO_ONCE("-------- Param Retrieved - Good --------");
    return true;    
  }
  


  void ControlNode::pathCallback(const nav_msgs::Path& trajectory_msg)
  {
    path.setPath(trajectory_msg);

    if(!pathInitialized)
    {
      pathInitialized = true;
    }
  }

  void ControlNode::stateCallback(const interface::Chassis_state& veh_state_msg)
  {

    vehicle_state_msg = veh_state_msg;

  
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

  int ControlNode::getTargetWaypoint(const interface::Chassis_state& current_position)
  {
    double roll, pitch, yaw;    
    // Unpack orientation of the vehicle
    tf2::Quaternion quaternion;
    tf2::convert(current_position.Position.pose.orientation, quaternion);
    tf2::Matrix3x3 quaternion_matrix(quaternion);
    quaternion_matrix.getRPY(roll, pitch, yaw);
    float vehicle_heading = static_cast<float>(yaw);

    // Create vector to store the filtered list
    std::vector<int> filtered_index;

    // If the path class is not empty
    if(!path.isPathEmpty())
    {
      for(size_t i = 0; i < path.getPathSize(); i++)      // Note: Consider a faster or smarter search algo in the future
      {
        // Check if the waypoint is within proximity
        float waypoint_distance = path.getWaypointRelativePlaneDistance(i, current_position.Position.pose.position);
        if(waypoint_distance <= waypoint_proximity_range)
        {
          // Check if the waypoint is ahead of the vehicle
          if(path.isWaypointAhead(i, current_position.Position.pose))
          {
            // Check if the waypoint is aligned with the vehicle
            if(path.isWaypointAligned(i, vehicle_heading, waypoint_heading_error_range))
            {
              filtered_index.push_back(i);
            }
          }
        }
      }
      int targetPointIndex = 0;
      float least_distance = 0;

      // Now search within the filtered out points for the closest waypoint
      if(filtered_index.size() == 0)
      {
        ROS_FATAL("There is no waypoint that meets all the requirement of the waypoint selector");
        throw std::runtime_error("No waypoint meets the waypoint selector requirement.");
      }
      else
      {
        // Find the closest waypoint from the list of filtered waypoint.
        least_distance = path.getWaypointRelativePlaneDistance(filtered_index[0], current_position.Position.pose.position);
        targetPointIndex = filtered_index[0];

        for(size_t j=0; j < filtered_index.size(); j++)
        {
          float current_wp_distance = path.getWaypointRelativePlaneDistance(filtered_index[j], current_position.Position.pose.position);
          if(least_distance > current_wp_distance)
          {
            least_distance = current_wp_distance;
            targetPointIndex = filtered_index[j];
          }
        }        
      }
      lat_control.debug_info.currentWPIndex = targetPointIndex;
      lat_control.debug_info.distance_to_wp = least_distance;

      return targetPointIndex;
    }
  }

  bool ControlNode::checkAutonomousMode() const
  {
    return (stateInitialized) && (pathInitialized) && (!obstacleDetected) && (!internalFailFlag) && (!goalReached) && (autonomousDrivingFlag) && (!externalFailFlag) && (!path.isPathEmpty());
  }

  void ControlNode::masterTimerCallback(const ros::TimerEvent& controlTimeEvent)
  {
    interface::Controlcmd control_core_command;
    if(obstacleDetected)
    {
      ROS_WARN("Obstacle Ahead, Vehicle Stopped!");
    }

    // Timestamp debug message
    lat_control.debug_info.header.stamp = ros::Time::now();

    // Initialize the steering angle and linear velocity variables
    float steering_angle = 0;
    float cmd_linear_vel = 0;   

    // Initilaize path selection process flag
    bool is_path_good = false;

    // Check if autonomous mode is on:
    if(checkAutonomousMode())
    {
      int target_waypoint_index = 0;
      
      // Try getting the target waypoint
      try
      {
        target_waypoint_index = getTargetWaypoint(vehicle_state_msg);
        is_path_good = true;
        lat_control.debug_info.pathSize = path.getPathSize();

      }
      catch(const std::runtime_error& runtime_err)
      {
        ROS_FATAL("%s", runtime_err.what());
        is_path_good = false;
      }

      // Perform path tracking if the path selection process is successful
      if(is_path_good)
      {
        //Check if goal is reached
        /* 
        Goal reached definition:
          - Vehicle's relative distance to the last waypoint is less than 0.3 meters
        */
        float distance_to_last_waypoint = path.getWaypointRelativePlaneDistance(path.getPathSize() - 1, vehicle_state_msg.Position.pose.position);
        if(distance_to_last_waypoint <= 0.5)    
        {
          //Goal reached
          goalReached = true;
          ROS_INFO("Goal reached. End of Path. Autonomy mode set to manual.");
          autonomousDrivingFlag = false;
          steering_angle = 0;
          cmd_linear_vel = 0; 
        }
        else    // If goal is not reached, do regular path tracking
        {
          try
          {
            steering_angle = lat_control.computeSteeringAngle(path.getWaypointPose(target_waypoint_index),
                                                              vehicle_state_msg, controlGain_p, controlGain_soft,
                                                              controlGain_d);
          }
          catch(const std::domain_error& domain_err)
          {
            steering_angle = 0;
            cmd_linear_vel = 0; 
            ROS_FATAL("%s", domain_err.what());
          }
          
          //TODO: Implement longitudinal Control --> blocker: Planning
          //TODO: Replace throttle function with a lamda function --> lamda(throttle, brake)
          cmd_linear_vel = 50; //In percentage
        }
      }
      

      //IF DEBUG IS TRUE
      if(debug)
      {
        lat_control.debug_info.stanleyGain_p = controlGain_p;
        lat_control.debug_info.stanleyGain_d = controlGain_d;
        //lat_control.debug_info.estimated_heading = estimated_orientation;
        control_debug_pub.publish(lat_control.debug_info);
      }   

        // Check calculation integrity of lateral controller, invalid calculation will bring vehicle to halt
      if(lat_control.debug_info.crossTrackErrorCalcInvalid ||
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