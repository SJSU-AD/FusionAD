#include "control/lat_controller.h"

namespace fusionad{
namespace control{
namespace lat_controller{

  Stanley::Stanley(float loop_time):control_interval(loop_time)
  {
    //control_interval = loop_time;
  }
  Stanley::~Stanley()
  {
  }

  float Stanley::computeCrossTrackError(const float &routeTheta, const float &dx, const float &dy)
  {
    // See computeCTE.m for proof  @Menson_Li
    float lateralError = ((std::sin(routeTheta) * dx) - (std::cos(routeTheta) * dy));    
    
    /**************************NaN Check*****************************/

    if(std::isfinite(lateralError))
    {
      debug_info.CrosstrackError = lateralError;
      return lateralError;
    }
    else
    {
      debug_info.crossTrackErrorCalcInvalid = true;
      ROS_FATAL("Lateral Error Calculation Is Not Finite!");
      return std::numeric_limits<float>::quiet_NaN();
    }    
  }

  //A positive steering angle denotes the vehicle to turn its steering wheel CCW (left)
  float Stanley::computeSteeringAngle(const geometry_msgs::Pose waypoint_pose, const interface::Chassis_state vehicle_state,
                                      const float &p_gain, const float &soft_gain, const float &d_gain)
  {
    double roll, pitch, yaw;

    // Unpack orientation of the vehicle
    tf2::Quaternion conv_quaternion;
    tf2::convert(vehicle_state.Position.pose.orientation, conv_quaternion);
    tf2::Matrix3x3 veh_quaternion_matrix(conv_quaternion);
    veh_quaternion_matrix.getRPY(roll, pitch, yaw);
    float vehicle_theta = static_cast<float>(yaw);    

    // Unpack the orientation of th waypoint
    tf2::convert(waypoint_pose.orientation, conv_quaternion);
    tf2::Matrix3x3 wp_quaternion_matrix(conv_quaternion);
    wp_quaternion_matrix.getRPY(roll, pitch, yaw);
    float pathTheta = static_cast<float>(yaw);  

    // Get vehicle speed
    // Unpack linear velocity
    float vehSpeed = sqrt(std::pow(vehicle_state.Speed.twist.linear.x, 2) 
                          + std::pow(vehicle_state.Speed.twist.linear.y,2));         
    
    //Find the global x delta of veh2path
    float tracking_dx = vehicle_state.Position.pose.position.x - waypoint_pose.position.x;
    //Find the global y delta of veh2path
    float tracking_dy = vehicle_state.Position.pose.position.y - waypoint_pose.position.y;
    //Compute Cross track error (lateral error of the veh to the path)
    float crossTrackError = computeCrossTrackError(pathTheta, tracking_dx, tracking_dy);
    //Find heading difference between vehicle orientation and the path
    //Follows the convention of left turn is positive 
    float headingDelta = pathTheta - vehicle_theta;
    debug_info.headingError = headingDelta;

    // Vehicle State Debug Message
    debug_info.vehicle_Position = vehicle_state.Position.pose.position;
    debug_info.vehicle_heading = vehicle_theta;
    
    //Apply Stanley kinematic control law
    float unfilteredSteeringAngle = 0;

    if(std::isfinite(control_interval))
    {
      debug_info.control_loop_period = control_interval;
    }
    else
    {
      ROS_FATAL("Control Loop Period Is Not Finite!");
      throw std::domain_error("Control Loop Period Is Not Finite!");
    } 


    float crossTrackError_dot = (crossTrackError-previous_crossTrackError) / control_interval;

    if(std::isfinite(crossTrackError_dot))
    {
      debug_info.CrosstrackError_dot = crossTrackError_dot;
    }
    else
    {
      debug_info.headingErrorCalcInvalid = true;
      ROS_FATAL("CTE derivative Calculation Is Not Finite!");
      throw std::domain_error("CTE derivative Calculation Is Not Finite!");
    }

    unfilteredSteeringAngle = headingDelta + 
                              std::atan(((p_gain*crossTrackError) + 
                              (d_gain * crossTrackError_dot))/ (soft_gain + vehSpeed));

    float steeringAngle = 0;

    previous_crossTrackError = crossTrackError;

    // Saturation function for limiting steering output
    if(std::abs(unfilteredSteeringAngle) > steering_limit)
    {
      steeringAngle = ((std::signbit(unfilteredSteeringAngle)) ? (-1) : (1))   * steering_limit;
    }
    else
    {
      steeringAngle = unfilteredSteeringAngle;
    }

    /**************************NaN Check*****************************/

    if(std::isfinite(steeringAngle))
    {
      debug_info.steeringAngle = steeringAngle;
      return steeringAngle;
    }
    else
    {
      debug_info.steeringAngleCalcInvalid = true;
      ROS_FATAL("Steering Angle Calculation Is Not Finite!");
      throw std::domain_error("Steering Angle Calculation Is Not Finite!");
    }
  }
}
}
}