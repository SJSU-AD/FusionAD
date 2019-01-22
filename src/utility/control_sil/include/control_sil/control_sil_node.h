#ifndef CONTROL_SIL_NODE_H_
#define CONTROL_SIL_NODE_H_

// C++ headers
#include <stdexcept>

// ROS related headers
#include "ros/ros.h"
#include <interface/Controlcmd.h>
#include <interface/Chassis_state.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Path.h>

// Computation related headers
#include "Eigen/Dense"
#include <algorithm>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/convert.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

// Include the control sil model library
#include "control_sil/sil_vehicle_model.h"

// Include the path header file
#include "control_sil/sil_path.h"

namespace fusionad
{
namespace control
{
namespace sil_test
{

class SIL_control_node
{
  public:
    SIL_control_node();
    ~SIL_control_node();
    void initRosComm();
    bool getParameter();

  private:
    // ROS object instantiation
    ros::NodeHandle control_sil_nh;
    ros::Publisher sim_vehicle_state_pub;
    ros::Publisher planner_pub;
    ros::Publisher rviz_pub;
    ros::Subscriber sim_vehicle_command_sub;
    
    // Create timer
    ros::Timer sil_timer;
    float sil_time_step = 0.001;      //Seconds
    ros::Timer planner_timer;
    float planner_pub_freq = 10;      // Hz

    // SIL initial condition
    geometry_msgs::Pose initial_position;
    const float initial_steering_angle = 0;

    // Simulation Callback
    void ModelSILCallback(const ros::TimerEvent& sil_timer_event);
    // Control command callback
    void ControlCommandCallback(const interface::Controlcmd &command_msg);
    // Path publisher callback
    void PlannerCallback(const ros::TimerEvent& sil_timer_event);

    // Command variables
    float command_steering_angle = 0;
    float command_velocity = 0;
    
    // Create steering model and vehicle model
    fusionad::control::vehicle_model::SIL_SteeringServoModel steering_servo;
    fusionad::control::vehicle_model::SIL_KinematicBicycleModel vehicle_kinematic;
};

}
}
}

#endif