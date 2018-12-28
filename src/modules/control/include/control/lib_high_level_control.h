#ifndef LIB_HIGH_LEVEL_CONTROL_H
#define LIB_HIGH_LEVEL_CONTROL_H

// Include all relevant libraries

// C++ headers
#include <vector>
#include <cmath>
#include <algorithm>

// ROS headers
#include "nav_msgs/Path.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/TwistStamped.h"
#include "std_msgs/Bool.h"
#include <interface/Controlcmd.h>
#include <interface/Chassis_state.h>
#include "Eigen/Dense"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/convert.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

namespace fusionad
{
namespace control
{
namespace libraries
{
class Waypoints
{
  private:
    nav_msgs::Path current_path_list_;

  public:
    Waypoints();
    ~Waypoints();

    void SetPath(const nav_msgs::Path& incoming_path_list);
    
    size_t GetPathSize() const
    {
      return current_path_list_.poses.size();
    }

    bool IsPathEmpty() const
    {
      return current_path_list_.poses.empty();
    }

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

//float getAbsoluteRelativeAngle(const int& index, const interface::Chassis_state& currentPosition);

}    
}
}


#endif