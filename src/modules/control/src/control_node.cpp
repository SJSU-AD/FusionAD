#include "control/control_node.h"

namespace fusionad
{
namespace control
{
namespace node
{
  control_node::control_node()
  {
    least_distance = 0;
    roll = 0;
    pitch = 0;
    yaw = 0;
    controlGain = 0;
    targetPointIndex = 0;
    dynamicArraySize = 0;
  }

  control_node::~control_node()
  {
  }

  void control_node::initRosComm()
  {
    //Create Timer Function for running the control stack, currently set to 100 hz
    ros::Timer core_control_timer = control_nh.createTimer(ros::Duration(0.01), &control_node::masterTimerCallback, this);  
    
    //Control Main publisher
    control_main_pub = control_nh.advertise<interface::Controlcmd>("/control/controlcmd", 100);
    ROS_INFO("Control Node Master Publisher Set!");

    //Control Trajectory Subscriber
    path_sub = control_nh.subscribe("/planning/trajectory", 100, &control_node::pathCallback, this);
    ROS_INFO("Control Node Path Subscriber Set!");

    //Control State Subscriber
    localization_sub = control_nh.subscribe("/localization/state", 100, &control_node::stateCallback, this);
    ROS_INFO("Control Node Path Subscriber Set!");

    imu_sub = control_nh.subscribe("/imu", 100, &control_node::imuCallback, this);
    ROS_INFO("Control Node IMU Subscriber Set!");
  }

  bool control_node::getParameter()
  {
    //Obtain parameter to initialize the node
    std::string node_name = ros::this_node::getName();
    if(!control_nh.param<double>(node_name+"/control_gain",controlGain, 1 ))
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
    dynamicArraySize = trajectory_msg.poses.size();
    pathPointListX.resize(dynamicArraySize);
    pathPointListY.resize(dynamicArraySize);
    if(dynamicArraySize != 0)
    {
      for(size_t i = 0; i < trajectory_msg.poses.size(); i++)
      {
        pathPointListX.push_back(trajectory_msg.poses[i].pose.position.x);
        pathPointListY.push_back(trajectory_msg.poses[i].pose.position.y);
      }
    }
    else
    {
      ROS_FATAL("Path List not flushed! Abort!");
    }
  }

  void control_node::stateCallback(const interface::Chassis_state& veh_state_msg)
  {
    position(0) = veh_state_msg.Position.pose.position.x;
    position(1) = veh_state_msg.Position.pose.position.x;
    linear_velocity = veh_state_msg.Speed.twist.linear.x;
  }

  void control_node::imuCallback(const sensor_msgs::Imu& inertial_msg)
  {
    tf::Quaternion chassis_quaternion(inertial_msg.orientation.x,
                              inertial_msg.orientation.y,
                              inertial_msg.orientation.z,
                              inertial_msg.orientation.w);
    tf::Matrix3x3 temp_rotation_matrix(chassis_quaternion);
    temp_rotation_matrix.getRPY(roll, pitch, yaw);
  }

  void control_node::masterTimerCallback(const ros::TimerEvent& controlTimeEvent)
  {
    //Compute the closest waypoint
    std::vector<double> distance;
    for(size_t i = 0; i < pathPointListX.size(); i++)
    {
      distance.push_back(sqrt(pow((position(0) - pathPointListX[i]),2)
                           + pow((position(1) - pathPointListY[i]),2)));
    }
    for(size_t j=0; j < distance.size(); j++)
    {
      if(least_distance > distance[j])
      {
        least_distance = distance[j];
        targetPointIndex = j;
      }
    }

    //Check if goal is reached
    if(targetPointIndex == (distance.size() - 1))
    {
      //Goal reached
      goalReached = true;
    }
    else
    {
      goalReached = false;
    }

    interface::Controlcmd control_core_command;
    double steering_angle;
    double cmd_linear_vel;

    if(!goalReached)
    {
      steering_angle = lat_control.computeSteeringAngle(position,
                                            pathPointListX,
                                            pathPointListX,
                                            linear_velocity,
                                            targetPointIndex,
                                            yaw,
                                            controlGain
                                            );

      //TODO: Implement longitudinal Control --> blocker: Planning
      //TODO: Replace throttle function with a lamda function --> lamda(throttle, brake)
      cmd_linear_vel = 50; //In percentage
    }
    else
    {
      steering_angle = 0;
      cmd_linear_vel = 0;
    }

    if(debug)
    {
      control_core_command.debugControl = true;
    }
    else
    {
      control_core_command.debugControl = false;
    }

    control_core_command.steeringAngle = steering_angle;
    control_core_command.throttle = cmd_linear_vel;   

    //PUBLISH CONTROL MESSAGE
    control_main_pub.publish(control_core_command);

    //Flush all vectors at the end
    pathPointListX.clear();
    pathPointListY.clear();
    dynamicArraySize = 0;
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