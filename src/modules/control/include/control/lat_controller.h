#ifndef LAT_CONTROLLER_H
#define LAT_CONTROLLER_H

//Declare all used external libraries
#include "Eigen/Dense"
#include "ros/ros.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <limits>
#include <interface/Stanley_debug.h>
#include <interface/Chassis_state.h>
#include <geometry_msgs/Pose.h>
#include <algorithm>
#include <stdexcept>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/convert.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

//Namespace declaration
namespace fusionad
{
namespace control
{
namespace lat_controller
{
class Stanley
{
  public:
    Stanley(float loop_time = 1);
    ~Stanley();
    interface::Stanley_debug debug_info;
    // Steering Limit is set to 21 deg
    float steering_limit = 0.36652;
    float previous_crossTrackError = 0;
    float control_interval;
    float computeSteeringAngle(const geometry_msgs::Pose waypoint_pose, const interface::Chassis_state vehicle_state,
                               const float &p_gain, const float &soft_gain, const float &d_gain);
  private:
    float computeCrossTrackError(const float &routeTheta, const float &dx, const float &delta_y);
};
}
}
}
#endif  