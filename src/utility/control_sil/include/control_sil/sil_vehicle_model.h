#ifndef SIL_VEHICLE_MODEL_H_
#define SIL_VEHICLE_MODEL_H_

// ROS message headers
#include <geometry_msgs/Pose.h>
#include <interface/Controlcmd.h>

// Computation header
#include <cmath>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/convert.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

namespace fusionad
{
namespace control
{
namespace vehicle_model
{
class SIL_SteeringServoModel
{
  public:
    SIL_SteeringServoModel();
    ~SIL_SteeringServoModel();
    float ComputeSteeringModel(const float setpoint_angle, const float time_step);
  private:
    float last_steering_angle;
    float last_setpoint_angle;
    float last_time_stamp;
};

class SIL_KinematicBicycleModel
{
  public:
    SIL_KinematicBicycleModel();
    ~SIL_KinematicBicycleModel();
    bool SetInitialCondition(const geometry_msgs::Pose &init_pose, const float &init_velocity, const float &wheelbase);
    geometry_msgs::Pose ComputeModel(const float &steering_angle, const float &velocity, const float &time_step);
  private:
    float vehicle_wheelbase;
    geometry_msgs::Pose last_pose;
    float last_velocity;
    bool IsModelInitialized;
};
}
}
}



#endif 