#include "control_sil/control_sil_node.h"

using namespace fusionad::control::sil_test;

SIL_control_node::SIL_control_node()
{
  initial_position.position.x = 0;
  initial_position.position.y = 0;
  initial_position.position.z = 0;
}

SIL_control_node::~SIL_control_node()
{
}

void SIL_control_node::initRosComm()
{
  // Initialize the timer for generating model simulation event
  sil_timer = control_sil_nh.createTimer(ros::Duration(sil_time_step), &SIL_control_node::ModelSILCallback, this);
  // Initialize the timer for path planner publication
  planner_timer = control_sil_nh.createTimer(ros::Duration(1/planner_pub_freq), &SIL_control_node::PlannerCallback, this);

  // Initialize all publishers
  sim_vehicle_state_pub = control_sil_nh.advertise<interface::Chassis_state>("/localization/state", 100);
  ROS_INFO_ONCE("[Control] Software in the loop state publisher set!");
  planner_pub = control_sil_nh.advertise<nav_msgs::Path>("/planning/trajectory", 100);
  ROS_INFO_ONCE("[Control] Software in the loop path publisher set!");
  rviz_pub = control_sil_nh.advertise<geometry_msgs::PoseStamped>("/localization/rviz", 100);
  ROS_INFO_ONCE("[Control] Software in the loop state rviz publisher set!");

  // Initialize all subscribers
  sim_vehicle_command_sub = control_sil_nh.subscribe("/control/controlcmd", 100, &SIL_control_node::ControlCommandCallback, this);
  ROS_INFO_ONCE("[Control] Software in the loop control command subscriber set!");
}

bool SIL_control_node::getParameter()
{
  // Obtain node name
  std::string node_name = ros::this_node::getName();

  // Pass in params from launch
  if(!control_sil_nh.param<float>(node_name+"/simulation_time_step", sil_time_step, 0.01))
  {
    ROS_WARN("[Control_SIL] Simulation time step not set, using default 0.01");
    return false;    
  }  
  float vehicle_wheelbase = 0;
  if(!control_sil_nh.param<float>(node_name+"/vehicle_wheelbase", vehicle_wheelbase, 2.3622))
  {
    ROS_WARN("[Control_SIL] Vehicle Wheelbase not set, using default 2.3622 meters");
    return false;    
  }    
  // Create initial position variables
  float initial_x, initial_y;
  if(!control_sil_nh.param<float>(node_name+"/initial_x_position", initial_x, 0.0))
  {
    ROS_WARN("[Control_SIL] Initial X position of the vehicle not set, using default 0");
    return false;    
  }
  if(!control_sil_nh.param<float>(node_name+"/initial_y_position", initial_y, 0.0))
  {
    ROS_WARN("[Control_SIL] Initial Y position of the vehicle not set, using default 0");
    return false;    
  }
  // Create heading value variable
  float initial_vehicle_heading = 0;    // Radians
  if(!control_sil_nh.param<float>(node_name+"/initial_vehicle_heading", initial_vehicle_heading, 0.0))
  {
    ROS_WARN("[Control_SIL] Initial heading of the vehicle not set, using default 0");
    return false;    
  }    
  // Set up the initial position ros message type
  tf2::Quaternion initial_vehicle_rotation;
  initial_vehicle_rotation.setRPY(0, 0, initial_vehicle_heading);
  tf2::convert(initial_vehicle_rotation, initial_position.orientation);
  initial_position.position.x = initial_x;
  initial_position.position.y = initial_y;

  // Initialize the vehicle model against listed initial position and zero velocity with its wheel base
  vehicle_kinematic.SetInitialCondition(initial_position, 0, vehicle_wheelbase);
  return true;
}

void SIL_control_node::ModelSILCallback(const ros::TimerEvent& sil_timer_event)
{
  // Perform Model Calculation here
  float servo_response = steering_servo.ComputeSteeringModel(command_steering_angle, sil_time_step);
  geometry_msgs::Pose model_process_value = vehicle_kinematic.ComputeModel(servo_response, command_velocity, sil_time_step);

  // Publish the new pose
  // Create the chassis_state message object
  interface::Chassis_state sil_state;
  sil_state.header.stamp = ros::Time::now();  
  sil_state.header.frame_id = "map";
  sil_state.Position.pose = model_process_value;
  sil_state.Speed.twist.linear.x = command_velocity;
  sim_vehicle_state_pub.publish(sil_state);
  sil_state.Position.header.stamp = ros::Time::now();
  sil_state.Position.header.frame_id = "map";
  rviz_pub.publish(sil_state.Position);
}

void SIL_control_node::ControlCommandCallback(const interface::Controlcmd &command_msg)
{
  command_steering_angle = command_msg.steeringAngle;
  // For now, we will just assume an on-off velocity command
  if(command_msg.throttle > 0)
  {
    command_velocity = 1.0;   // meter per seconds
  }
  else
  {
    command_velocity = 0;
  }
}

void SIL_control_node::PlannerCallback(const ros::TimerEvent& sil_timer_event)
{
  nav_msgs::Path planned_path;
  size_t size_of_path = sizeof(sil_pathArrayX)/sizeof(sil_pathArrayX[0]);
  for(int i = 0; i < size_of_path; i++)
  {
    geometry_msgs::PoseStamped path_point;
    path_point.pose.position.x = sil_pathArrayX[i];
    path_point.pose.position.y = sil_pathArrayY[i];
    planned_path.poses.push_back(path_point);
  }
  planned_path.header.frame_id = "map";
  planner_pub.publish(planned_path);
}

int main(int argc, char **argv)
{
  //ROS node initialization as "control_sil_sim"
  ros::init(argc, argv, "control_sil_sim");
  SIL_control_node control_sil_simulator;
  if(!control_sil_simulator.getParameter())
  {
    ROS_FATAL("Parameter Failed! Abort!");
  }
  else
  {
    ROS_INFO("[CONTRO_SIL] Paramter retrieved.");
  }
  control_sil_simulator.initRosComm();
  while(ros::ok())
  {
    //Execute all callbacks first to initiate the variables
    ros::spinOnce();
  }
  return 0;
}