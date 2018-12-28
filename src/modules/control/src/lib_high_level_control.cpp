#include "control/lib_high_level_control.h"

namespace fusionad
{
namespace control
{
namespace libraries
{

  Waypoints::Waypoints()
  {
  }

  Waypoints::~Waypoints()
  {
  }

  void Waypoints::SetPath(const nav_msgs::Path& incoming_path_list)
  {
    current_path_list_ = incoming_path_list;
    if(!IsPathEmpty())
    {
      for(int i = 0; i < GetPathSize(); i++)
      {
        tf2::Quaternion waypoint_quaternion;
        waypoint_quaternion.setRPY(0,0,GetWaypointTheta(i));
        tf2::convert(waypoint_quaternion,current_path_list_.poses[i].pose.orientation);
      }
    }
    else
    {
      throw "Incoming path empty, path is not set!";
    }
  }

  float Waypoints::GetWaypointTheta(const int& index)
  {
    if(!IsPathEmpty())
    {
      Eigen::Matrix3f designMatrix;
      Eigen::Vector3f responseVector;
      //Fit with Two point forward at beginning
      if(index == 0)                              
      {
        designMatrix <<   std::pow(current_path_list_.poses[index].pose.position.x,2)  , current_path_list_.poses[index].pose.position.x,     1,
                          std::pow(current_path_list_.poses[index+1].pose.position.x,2), current_path_list_.poses[index+1].pose.position.x,   1,
                          std::pow(current_path_list_.poses[index+2].pose.position.x,2), current_path_list_.poses[index+2].pose.position.x,   1;                        
      
        responseVector << current_path_list_.poses[index].pose.position.y,
                          current_path_list_.poses[index+1].pose.position.y,
                          current_path_list_.poses[index+2].pose.position.y;
      }
      //Fit with Two points before
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

      if(index == (GetPathSize() - 1))
      {
        nextXpos = current_path_list_.poses[index].pose.position.x;
        nextYpos = current_path_list_.poses[index].pose.position.y;

        targetXpos = current_path_list_.poses[index-1].pose.position.x;
        targetYpos = current_path_list_.poses[index-1].pose.position.y;
      }
      else
      {
        nextXpos = current_path_list_.poses[index+1].pose.position.x;
        nextYpos = current_path_list_.poses[index+1].pose.position.y;

        targetXpos = current_path_list_.poses[index].pose.position.x;
        targetYpos = current_path_list_.poses[index].pose.position.y;

      }

      //Now estimate the direction of the path to generate heading.
      //Find the linear representation of the slope
      float b = targetYpos - (pathSlope * targetXpos);
      
      //Find the next Y point of the slope to get the linear interpolated vector
      float nextYslope = (pathSlope*nextXpos) + b;

      //Linear interpolate the vector
      float heading_dx = nextXpos - targetXpos;
      float heading_dy = nextYslope - targetYpos;    

      return atan2(heading_dy, heading_dx);
    }
    else
    {
      throw "Path not set! Exception Thrown!"; 
    }

  }

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
      throw "Path not set! Exception Thrown!"; 
    }
  }

  bool Waypoints::IsWaypointAhead(const int& index, const geometry_msgs::Pose& current_vehicle_pose)
  {
    if(!IsPathEmpty())
    {
      //TODO: See matlab file for transform proof and work
      //      Check against the heading signs, might need to check the sign to determine how to perform transform
      
      // NOTE: This is a different kinda transform compared to the later error extraction
      //       This transform is to relatively transform the waypoint coordinates into the vehicle's fixed
      //       fixed body frame.
      return true;
    }
    else
    {
      throw "Path not set! Exception Thrown!"; 
    }    
  }

  bool Waypoints::IsWaypointAligned(const int& index, const float& current_vehicle_heading, const float& heading_thereshold)
  {
    double roll, pitch, yaw;
    tf2::Quaternion waypoint_quaternion;
    tf2::convert(current_path_list_.poses[index].pose.orientation, waypoint_quaternion);
    tf2::Matrix3x3 waypoint_quaternion_matrix(waypoint_quaternion);
    waypoint_quaternion_matrix.getRPY(roll, pitch, yaw);
    float absolute_heading_delta = std::abs(static_cast<float>(yaw) - current_vehicle_heading);

    if(absolute_heading_delta <= heading_thereshold)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}
}
}