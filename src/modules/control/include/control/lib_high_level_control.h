/** lib_high_level_control.h
 * @author Menson Li
 * 
 * @email menson168@gmail.com
 * 
 * @desc The header file for high level control's library functions.
 * 
 */

#ifndef LIB_HIGH_LEVEL_CONTROL_H
#define LIB_HIGH_LEVEL_CONTROL_H

// Include all relevant library headers

// C++ headers
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>

// ROS Message headers
#include "nav_msgs/Path.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/TwistStamped.h"
#include "geometry_msgs/Quaternion.h"
#include "std_msgs/Bool.h"
#include <interface/Controlcmd.h>
#include <interface/Chassis_state.h>

// Mathematical library headers (Eigen and TF2)
#include "Eigen/Dense"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/convert.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

// Declare corresponding namespace
namespace fusionad
{
namespace control
{
namespace libraries
{
/** Waypoints Class
 * - An object for storing the path's list of waypoints as well as its class functions.
 * - When a new path is received, the Setpath function will be called to store the incoming
 *   path and automatically calcuates the heading angle of each waypoint. 
 */
class Waypoints
{
  private:
    // Internal data member for storing the incoming path from planner 
    // - Refered as the path data member in later code comments
    nav_msgs::Path current_path_list_;
    float ComputeWaypointTheta(const int& index);

  public:
    Waypoints();
    ~Waypoints();

    bool SetPath(const nav_msgs::Path& incoming_path_list);
    
    /** GetPathSize() const
     * 
     * @memberOf_ Waypoints
     * 
     * @returns {size_t} This function returns the size of the internal path data member.
     */    
    size_t GetPathSize() const
    {
      return current_path_list_.poses.size();
    }

    /** IsPathEmpty() const
     * 
     * @memberOf_ Waypoints
     * 
     * @returns {bool} This function returns true if the internal path data member is empty.
     */   
    bool IsPathEmpty() const
    {
      return current_path_list_.poses.empty();
    }

    /** GetWaypointPosition(const int& index) const
     * 
     * @memberOf_ Waypoints
     * 
     * @param {index} An int type data that represents the index of the referenced waypoint within the path 
     *                data member.
     * 
     * @returns {geometry_msgs::Point} This function returns the position component 
     *                                 of the specific waypoint.
     */   
    geometry_msgs::Point GetWaypointPosition(const int& index) const
    {
      return current_path_list_.poses[index].pose.position;
    }    

    float GetWaypointTheta(const int& index);
    float GetWaypointRelativePlaneDistance(const int& index, const geometry_msgs::Point& current_vehicle_position);
    // This function compares the relative location of the current index and the position of the vehicle
    // to determine whether the waypoint is within logical/reachable space ("Aheadness")
    bool IsWaypointAhead(const int& index, const geometry_msgs::Pose& current_vehicle_pose);
    bool IsWaypointAligned(const int& index, const float& current_vehicle_heading, const float& heading_thereshold);
};

void SetROSQuaternionFromRPY(geometry_msgs::Quaternion& ROS_quaternion, const float& roll,const float& pitch,const float& yaw);
//float getAbsoluteRelativeAngle(const int& index, const interface::Chassis_state& currentPosition);

}    
}
}


#endif