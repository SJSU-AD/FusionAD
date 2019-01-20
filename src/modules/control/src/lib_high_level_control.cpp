/** lib_high_level_control.cpp
 * @author Menson Li
 * 
 * @email menson168@gmail.com
 * 
 * @desc The source code file for high level control's library functions.
 * 
 */

// Include the header file
#include "control/lib_high_level_control.h"

// Declare corresponding namespace
namespace fusionad
{
namespace control
{
namespace library
{

Waypoints::Waypoints()
{
}

Waypoints::~Waypoints()
{
}

/** SetPath(const nav_msgs::Path& incoming_path_list)
 * 
 * @memberOf_ Waypoints
 * 
 * @desc This function takes the incoming path message and store it in the internal path data member. 
 *       It also perform heading computation for each waypoint and store the information in the internal
 *       path data memeber for later reference.
 * 
 * @param {incoming_path_list} A ROS-nav_msgs::Path type data that represents the path information from
 *                             the planner.
 * 
 * @returns {bool} This function returns true if all the procedure of initializing the internal path data member
 *                 is successful, false if failed.
 * 
 * @exception {invalid_argument} Exception will be thrown if the incoming path is empty. 
 *            (does not contain any waypoint information)
 */
bool Waypoints::SetPath(const nav_msgs::Path& incoming_path_list)
{
  current_path_list_.poses.clear();
  current_path_list_ = incoming_path_list;
  // Only perform path stuffing if the current path data is empty
  if(!incoming_path_list.poses.empty())
  {
    for(int i = 0; i < GetPathSize(); i++)
    {
      tf2::Quaternion waypoint_quaternion;
      float waypoint_theta = 0;
      try
      {
        waypoint_theta = ComputeWaypointTheta(i);
      }
      catch(std::exception& _exception)
      {
        return false;
      }
      waypoint_quaternion.setRPY(0,0,waypoint_theta);
      tf2::convert(waypoint_quaternion,current_path_list_.poses[i].pose.orientation);
    }
    return true;
  }
  else
  {
    throw std::invalid_argument("Incoming path empty, path is not set!");
  }
}

/** GetWaypointTheta(const int& index)
 * 
 * @memberOf_ Waypoints
 * 
 * @desc This function retrieves the yaw value of a specific waypoint in the path data member.
 * 
 * @param {index} An int type data that represents the index of the referenced waypoint within the path 
 *                data member.
 * 
 * @returns {waypoint_theta} The heading of the referenced waypoint from the internal path data member.
 * 
 * @exception {logic_error} Exception will be thrown if the internal path data member is empty.
 *                               (Implicitly represent the internal path data member was not initialized)
 */
float Waypoints::GetWaypointTheta(const int& index)
{
  if(!IsPathEmpty())
  {
    double waypoint_roll, waypoint_pitch, waypoint_yaw;
    tf2::Quaternion waypoint_quaternion;
    tf2::convert(current_path_list_.poses[index].pose.orientation, waypoint_quaternion);
    tf2::Matrix3x3 waypoint_quaternion_matrix(waypoint_quaternion);
    waypoint_quaternion_matrix.getRPY(waypoint_roll, waypoint_pitch, waypoint_yaw);
    float waypoint_theta = static_cast<float>(waypoint_yaw);
    if(!std::isfinite(waypoint_theta))
    {
      throw std::domain_error("Waypoint Theta not finite!");
    }
    else
    {
      return waypoint_theta;
    }
  }
  else
  {
    throw std::logic_error("Path is not set!");
  }
}

/** ComputeWaypointTheta(const int& index)
 * 
 * @memberOf_ Waypoints
 * 
 * @desc This function computes the yaw value of a specific waypoint in the path data member by performing
 *       quadratic fit of the specific waypoint with its neighboring waypoints.
 * 
 * @param {index} An int type data that represents the index of the referenced waypoint within the path 
 *                data member.
 * 
 * @returns {waypoint_theta} The computed heading of the referenced waypoint from quadratic fit.
 * 
 * @exception {logic_error} Exception will be thrown if the internal path data member is empty.
 *                               (Implicitly represent the internal path data member was not initialized)
 * 
 * @exception {domain_error} Exception will be thrown if the calculation produced a non-finite value (NaN).
 */
float Waypoints::ComputeWaypointTheta(const int& index)
{
  if(!IsPathEmpty())
  {
    Eigen::Matrix3f designMatrix;
    Eigen::Vector3f responseVector;
    //Fit with Two point forward at the beginning of list
    if(index == 0)                              
    {
      designMatrix <<   std::pow(current_path_list_.poses[index].pose.position.x,2)  , current_path_list_.poses[index].pose.position.x,     1,
                        std::pow(current_path_list_.poses[index+1].pose.position.x,2), current_path_list_.poses[index+1].pose.position.x,   1,
                        std::pow(current_path_list_.poses[index+2].pose.position.x,2), current_path_list_.poses[index+2].pose.position.x,   1;                        
    
      responseVector << current_path_list_.poses[index].pose.position.y,
                        current_path_list_.poses[index+1].pose.position.y,
                        current_path_list_.poses[index+2].pose.position.y;
    }
    //Fit with Two points before at the end of list
    else if(index == (GetPathSize() - 1))                   
    {
      designMatrix <<   std::pow(current_path_list_.poses[index-2].pose.position.x,2)  , current_path_list_.poses[index-2].pose.position.x, 1,
                        std::pow(current_path_list_.poses[index-1].pose.position.x,2),   current_path_list_.poses[index-1].pose.position.x, 1,
                        std::pow(current_path_list_.poses[index].pose.position.x,2),     current_path_list_.poses[index].pose.position.x,   1;
    
      responseVector << current_path_list_.poses[index-2].pose.position.x,
                        current_path_list_.poses[index-1].pose.position.x,
                        current_path_list_.poses[index].pose.position.x; 
    }
    // Normal index fitting
    else  
    {
      designMatrix <<   std::pow(current_path_list_.poses[index-1].pose.position.x,2), current_path_list_.poses[index-1].pose.position.x, 1,
                        std::pow(current_path_list_.poses[index].pose.position.x,2),   current_path_list_.poses[index].pose.position.x,   1,
                        std::pow(current_path_list_.poses[index+1].pose.position.x,2), current_path_list_.poses[index+1].pose.position.x, 1;
    
      responseVector << current_path_list_.poses[index-1].pose.position.y,
                        current_path_list_.poses[index].pose.position.y,
                        current_path_list_.poses[index+1].pose.position.y;                               
    }

    Eigen::ColPivHouseholderQR<Eigen::Matrix3f> dec(designMatrix);
    Eigen::Vector3f x = dec.solve(responseVector);  
    Eigen::Vector2f pathYawCoeff;

    // Taking the derivative of the function
    pathYawCoeff << x(0)*2,
                    x(1);     
              
    //Calculate pathSlope at index value;
    float pathSlope = pathYawCoeff(0) * current_path_list_.poses[index].pose.position.x +
                      pathYawCoeff(1);   

    float nextXpos;
    float nextYpos;

    float targetXpos;
    float targetYpos;

    //Now estimate the direction of the path to generate heading.
    //Find the linear representation of the slope
    float b = current_path_list_.poses[index].pose.position.y - (pathSlope * current_path_list_.poses[index].pose.position.x);

    float heading_dx = 0;
    float heading_dy = 0;    

    if(index == (GetPathSize() - 1))
    {
      nextXpos = current_path_list_.poses[index].pose.position.x;
      nextYpos = current_path_list_.poses[index].pose.position.y;

      targetXpos = current_path_list_.poses[index-1].pose.position.x;
      targetYpos = current_path_list_.poses[index-1].pose.position.y;
      
      // Take the direct backward differencing of the positions to get path heading if at last waypoint
      heading_dx = nextXpos - targetXpos;
      heading_dy = nextYpos - targetYpos;
    }
    else
    {
      nextXpos = current_path_list_.poses[index+1].pose.position.x;
      nextYpos = current_path_list_.poses[index+1].pose.position.y;

      targetXpos = current_path_list_.poses[index].pose.position.x;
      targetYpos = current_path_list_.poses[index].pose.position.y;

      //Find the next Y point of the slope to get the linear interpolated vector
      float nextYslope = (pathSlope*nextXpos) + b;

      //Linear interpolate the vector
      heading_dx = nextXpos - targetXpos;
      heading_dy = nextYslope - targetYpos;   
    }

    float waypoint_heading = atan2(heading_dy, heading_dx);

    if(!std::isfinite(waypoint_heading))
    {
      throw std::domain_error("Waypoint Theta calculation fault!");
    }
    else
    {
      return waypoint_heading;
    }
  }
  else
  {
    throw std::logic_error("Path is not set!"); 
  }
}

/** GetWaypointRelativePlaneDistance(const int& index, const geometry_msgs::Point& current_vehicle_position)
 * 
 * @memberOf_ Waypoints
 * 
 * @desc This function computes the relative plane distance between the give vehicle position and the specific waypoint.
 * 
 * @param {index} An int type data that represents the index of the referenced waypoint within the path 
 *                data member.
 * 
 * @param {current_vehicle_position} A ROS-geometry_msgs::Point type data that represents the position of the vehicle
 *                                   in 3D space, for this function, only the 2D components were used (x and y).
 * 
 * @returns {float} The computed plane distance.
 * 
 * @exception {logic_error} Exception will be thrown if the internal path data member is empty.
 * 
 * @exception {domain_error} Exception will be thrown if the calculation produced a non-finite value (NaN).
 */
float Waypoints::GetWaypointRelativePlaneDistance(const int& index, const geometry_msgs::Point& current_vehicle_position)
{
  if(!IsPathEmpty())
  {
    float dx = current_path_list_.poses[index].pose.position.x - current_vehicle_position.x;
    float dy = current_path_list_.poses[index].pose.position.y - current_vehicle_position.y;
    return std::sqrt(std::pow(dx,2) + std::pow(dy,2));
  }
  else
  {
    throw std::logic_error("Path is not set!"); 
  }
}

/** IsWaypointAhead(const int& index, const geometry_msgs::Pose& current_vehicle_pose)
 * 
 * @memberOf_ Waypoints
 * 
 * @desc This function determine whether the waypoint is "ahead" of the vehicle. A homogeneous transformation is applied to the
 *       location of the waypoint from its world/map frame to the body fixed frame of the vehicle. Since the X axis of the body fixed
 *       frame of the vehicle is aligned with the heading vector of the vehicle in world/map frame, if the waypoint lies in the positive
 *       X axis of the vehicle body fixed frame, then it is "ahead" of the vehicle, and vice versa if the waypoint is in the negative region
 *       of the X axis. See test/test_data_and_doc/transform_test.m for all kinds of proof for transform and checking.
 * 
 * @param {index} An int type data that represents the index of the referenced waypoint within the path 
 *                data member.
 * 
 * @param {current_vehicle_pose} A ROS-geometry_msgs::Pose type data that represents the position and orientation
 *                               of the vehicle in 3D space. Since we are assuming the vehicle is only in planar motion
 *                               motion, only the x, y, and yaw equivalent of the quaternion should be populated.
 * 
 * @returns {bool} True if the waypoint is "ahead" of the vehicle, false if it isn't.
 * 
 * @exception {logic_error} Exception will be thrown if the internal path data member is empty.
 * 
 * @exception {domain_error} Exception will be thrown if the calculation produced a non-finite value (NaN).
 */
bool Waypoints::IsWaypointAhead(const int& index, const geometry_msgs::Pose& current_vehicle_pose)
{
  if(!IsPathEmpty())
  { 
    // Extract location of the waypoint from the ROS msg type
    float waypoint_x_position = current_path_list_.poses[index].pose.position.x;
    float waypoint_y_position = current_path_list_.poses[index].pose.position.y;

    // Extract location and orientation of the vehicle
    float car_x_position = current_vehicle_pose.position.x;
    float car_y_position = current_vehicle_pose.position.y;
    tf2::Quaternion car_quaternion;
    tf2::convert(current_vehicle_pose.orientation, car_quaternion);
    tf2::Matrix3x3 car_quaternion_matrix(car_quaternion);
    double car_roll = 0, car_pitch = 0, car_yaw = 0;
    car_quaternion_matrix.getRPY(car_roll, car_pitch, car_yaw);     

    float car_theta = static_cast<float>(car_yaw);

    // Calculate the X component of the relative location of the waypoint w.r.t. the vehicle's body fixed frame.
    // Vehicle body fixed frame: X axis is aligned with the heading of the vehicle.

    float waypoint_wrt_vehicle_dx = (waypoint_x_position*std::cos(car_theta))
                                    - (car_y_position*std::sin(car_theta))
                                    - (car_x_position*std::cos(car_theta))
                                    + (waypoint_y_position*std::sin(car_theta));
    
    if(!std::isfinite(waypoint_wrt_vehicle_dx))
    {
      throw std::domain_error("Waypoint Ahead calculation error!");
    }

    // Check if waypoint is ahead of the vehicle by whether they are in the positive or negative X axis 
    // w.r.t. the vehicle's body fixed frame

    if(waypoint_wrt_vehicle_dx > 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    throw std::logic_error("Path is not set!"); 
  }    
}

/** IsWaypointAligned(const int& index, const float& current_vehicle_heading, const float& heading_thereshold)
 * 
 * @memberOf_ Waypoints
 * 
 * @desc This function determine whether the waypoint is aligned with the orientation of the vehicle. It calculates
 *       the difference between the heading of a specific waypoint and the heading of the vehicle in world/map frame,
 *       and determine if the difference is between the specific thereshold.
 * 
 * @param {index} An int type data that represents the index of the referenced waypoint within the path 
 *                data member.
 * 
 * @param {current_vehicle_heading} A float type data that represents the heading of the vehicle in RADIANS.
 * 
 * @param {heading_thereshold} A float type data that represent the tolerance on the difference between the specific
 *                             waypoint's heading and the vehicle's heading.
 * 
 * @returns {bool} True if the difference between the specific waypoint's heading and the vehicle's heading is within
 *                 the given thereshold, false if it isn't.
 * 
 * @exception {logic_error} Exception will be thrown if the internal path data member is empty.
 * 
 * @exception {domain_error} Exception will be thrown if the calculation produced a non-finite value (NaN).
 */
bool Waypoints::IsWaypointAligned(const int& index, const float& current_vehicle_heading, const float& heading_thereshold)
{
  if(!IsPathEmpty())
  {   
    // Extract the yaw value from the path msg
    double waypoint_roll, waypoint_pitch, waypoint_yaw;
    tf2::Quaternion waypoint_quaternion;
    tf2::convert(current_path_list_.poses[index].pose.orientation, waypoint_quaternion);
    tf2::Matrix3x3 waypoint_quaternion_matrix(waypoint_quaternion);
    waypoint_quaternion_matrix.getRPY(waypoint_roll, waypoint_pitch, waypoint_yaw);

    // Calculate the difference in theta
    float absolute_heading_delta = std::abs(static_cast<float>(waypoint_yaw) - current_vehicle_heading);

    if(!std::isfinite(absolute_heading_delta) || !std::isfinite(heading_thereshold))
    {
      throw std::domain_error("Waypoint alignment calculation fault!");
    }

    if(absolute_heading_delta <= heading_thereshold)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    throw std::logic_error("Path is not set!");     
  }
}

/** SetROSQuaternionFromRPY(geometry_msgs::Quaternion& ROS_quaternion, const float& roll,const float& pitch,const float& yaw)
 * 
 * @desc This function set a ROS-geometry_msgs::Quaternion type quaternion data from the 
 *       given roll, pitch and yaw value.
 * 
 * @param {ROS_quaternion} A ROS-geometry_msgs::Quaternion type pointer that points to the quarternion message data to be written.
 * 
 * @param {roll, pitch, yaw} Float type data that represents the roll, pitch, and yaw values to be set to the ROS-quaternion message.
 * 
 * @returns {void}
 */
void SetROSQuaternionFromRPY(geometry_msgs::Quaternion& ROS_quaternion, const float& roll,const float& pitch,const float& yaw)
{
  tf2::Quaternion tf_quaternion;
  tf_quaternion.setRPY(roll,pitch,yaw);
  tf2::convert(tf_quaternion,ROS_quaternion);
}
}
}
}