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

  float GetWaypointTheta(const int& index)
  {
    if(!IsPathEmpty())
    {
      Eigen::Matrix3f designMatrix;
      Eigen::Vector3f responseVector;
      //Fit with Two point forward at beginning
      if(targetIndex == 0)                              
      {
        designMatrix <<   std::pow(current_path_list_.poses[targetIndex].pose.position.x,2)  , current_path_list_.poses[targetIndex].pose.position.x,     1,
                          std::pow(current_path_list_.poses[targetIndex+1].pose.position.x,2), current_path_list_.poses[targetIndex+1].pose.position.x,   1,
                          std::pow(current_path_list_.poses[targetIndex+2].pose.position.x,2), current_path_list_.poses[targetIndex+2].pose.position.x,   1;                        
      
        responseVector << current_path_list_.poses[targetIndex].pose.position.y,
                          current_path_list_.poses[targetIndex+1].pose.position.y,
                          current_path_list_.poses[targetIndex+2].pose.position.y;
      }
      //Fit with Two points before
      else if(targetIndex == (GetPathSize() - 1))                   
      {
        designMatrix <<   std::pow(current_path_list_.poses[targetIndex-2].pose.position.x,2)  , current_path_list_.poses[targetIndex-2].pose.position.x, 1,
                          std::pow(current_path_list_.poses[targetIndex-1].pose.position.x,2),   current_path_list_.poses[targetIndex-1].pose.position.x, 1,
                          std::pow(current_path_list_.poses[targetIndex].pose.position.x,2),     current_path_list_.poses[targetIndex].pose.position.x,   1;
      
        responseVector << current_path_list_.poses[targetIndex-2].pose.position.x,
                          current_path_list_.poses[targetIndex-1].pose.position.x,
                          current_path_list_.poses[targetIndex].pose.position.x; 
      }
      // Normal index fitting
      else  
      {
        designMatrix <<   std::pow(current_path_list_.poses[targetIndex-1].pose.position.x,2), current_path_list_.poses[targetIndex-1].pose.position.x, 1,
                          std::pow(current_path_list_.poses[targetIndex].pose.position.x,2),   current_path_list_.poses[targetIndex].pose.position.x,   1,
                          std::pow(current_path_list_.poses[targetIndex+1].pose.position.x,2), current_path_list_.poses[targetIndex+1].pose.position.x, 1;
      
        responseVector << current_path_list_.poses[targetIndex-1].pose.position.y,
                          current_path_list_.poses[targetIndex].pose.position.y,
                          current_path_list_.poses[targetIndex+1].pose.position.y;                               
      }

      Eigen::ColPivHouseholderQR<Eigen::Matrix3f> dec(designMatrix);
      Eigen::Vector3f x = dec.solve(responseVector);  
      Eigen::Vector2f pathYawCoeff;

      // Taking the derivative of the function
      pathYawCoeff << x(0)*2,
                      x(1);     
                
      //Calculate pathSlope at index value;
      pathSlope = pathYawCoeff(0) * current_path_list_.poses[targetIndex].pose.position.x +
                  pathYawCoeff(1);   

      float nextXpos;
      float nextYpos;

      float targetXpos;
      float targetYpos;

      if(targetIndex == (GetPathSize() - 1))
      {
        nextXpos = current_path_list_.poses[targetIndex].pose.position.x;
        nextYpos = current_path_list_.poses[targetIndex].pose.position.y;

        targetXpos = current_path_list_.poses[targetIndex-1].pose.position.x;
        targetYpos = current_path_list_.poses[targetIndex-1].pose.position.y;
      }
      else
      {
        nextXpos = current_path_list_.poses[targetIndex+1].pose.position.x;
        nextYpos = current_path_list_.poses[targetIndex+1].pose.position.y;

        targetXpos = current_path_list_.poses[targetIndex].pose.position.x;
        targetYpos = current_path_list_.poses[targetIndex].pose.position.y;

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
      return std::sqrt(std::pow(dx,2) + std::pow(dy,2))
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
      return true
    }
    else
    {
      throw "Path not set! Exception Thrown!"; 
    }    
  }
}
}
}