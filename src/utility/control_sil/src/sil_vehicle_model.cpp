#include "control_sil/sil_vehicle_model.h"

using namespace fusionad::control::vehicle_model;

SIL_SteeringServoModel::SIL_SteeringServoModel()
{
  last_steering_angle = 0;
  last_setpoint_angle = 0;
}

SIL_SteeringServoModel::~SIL_SteeringServoModel()
{
}

float SIL_SteeringServoModel::ComputeSteeringModel(const float setpoint_angle, const float time_step)
{
  float current_time_stamp = 0;
  float error = last_steering_angle - setpoint_angle;
  if(setpoint_angle == last_setpoint_angle)
  {
    current_time_stamp = last_time_stamp+time_step;
  }
  else
  {
    last_time_stamp = 0;
    current_time_stamp = time_step;
    last_setpoint_angle = setpoint_angle;
  }
  last_steering_angle += error * 
                         (1 - (1 + (std::pow(5.8, current_time_stamp) * std::exp((-1) * 5.8 * current_time_stamp))));
  last_time_stamp = current_time_stamp;                         
  return last_steering_angle;                        
}

SIL_KinematicBicycleModel::SIL_KinematicBicycleModel():
IsModelInitialized(false)
{
}

SIL_KinematicBicycleModel::~SIL_KinematicBicycleModel()
{
}

bool SIL_KinematicBicycleModel::SetInitialCondition(const geometry_msgs::Pose &init_pose, const float &init_velocity, const float &wheelbase)
{
  last_velocity = init_velocity;
  last_pose = init_pose;
  vehicle_wheelbase = wheelbase;
  IsModelInitialized = true;
  return true;
}

geometry_msgs::Pose SIL_KinematicBicycleModel::ComputeModel(const float &steering_angle, const float &velocity, const float &time_step)
{
  geometry_msgs::Pose current_pose;  
  if(IsModelInitialized)
  {
    tf2::Quaternion model_quaternion;
    tf2::convert(last_pose.orientation, model_quaternion);
    tf2::Matrix3x3 model_quaternion_matrix(model_quaternion);
    double last_heading = 0, last_roll = 0, last_pitch = 0;
    model_quaternion_matrix.getRPY(last_roll, last_pitch, last_heading);
    float last_sai = static_cast<float>(last_heading);

    // Compute the bicycle model
    float beta = std::atan(0.5*std::tan(steering_angle));
    current_pose.position.x = (velocity*std::cos(last_sai+beta))*time_step+last_pose.position.x; 
    current_pose.position.y = (velocity*std::sin(last_sai+beta))*time_step+last_pose.position.y;  
    float current_sai = ((velocity/(0.5 * vehicle_wheelbase)) * std::sin(beta)) * time_step + last_sai;
    model_quaternion.setRPY(0 , 0, current_sai);
    tf2::convert(model_quaternion, current_pose.orientation);

    // Store the current position as last position
    last_pose = current_pose;
    return current_pose;
  }
  else
  {
    current_pose.position.x = 0;
    current_pose.position.y = 0;
    current_pose.position.z = 0;
    tf2::Quaternion model_quaternion;
    model_quaternion.setRPY(0, 0, 0);    
    tf2::convert(model_quaternion, current_pose.orientation);    
    last_pose = current_pose;
    return current_pose;
  }
}