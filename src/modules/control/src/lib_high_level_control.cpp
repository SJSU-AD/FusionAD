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
        catch(const char* msg)
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
      throw "Incoming path empty, path is not set!";
    }
  }

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
        throw "Waypoint Theta not finite!";
      }
      else
      {
        return waypoint_theta;
      }
    }
    else
    {
      throw "Path is not set!";
    }
  }

  float Waypoints::ComputeWaypointTheta(const int& index)
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
        throw "Waypoint Theta calculation fault!";
      }
      else
      {
        return waypoint_heading;
      }
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
      // Note: see test/test_data_and_doc/transform_test.m for all kinds of proof for transform and checking
      
      // Extract location of the waypoint
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
        throw "Waypoint Ahead calculation error!";
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
      throw "Path not set! Exception Thrown!"; 
    }    
  }

  bool Waypoints::IsWaypointAligned(const int& index, const float& current_vehicle_heading, const float& heading_thereshold)
  {
    double waypoint_roll, waypoint_pitch, waypoint_yaw;
    tf2::Quaternion waypoint_quaternion;
    tf2::convert(current_path_list_.poses[index].pose.orientation, waypoint_quaternion);
    tf2::Matrix3x3 waypoint_quaternion_matrix(waypoint_quaternion);
    waypoint_quaternion_matrix.getRPY(waypoint_roll, waypoint_pitch, waypoint_yaw);
    float absolute_heading_delta = std::abs(static_cast<float>(waypoint_yaw) - current_vehicle_heading);

    if(!std::isfinite(absolute_heading_delta) || !std::isfinite(heading_thereshold))
    {
      throw "Waypoint alignment calculation fault!";
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

  void SetROSQuaternionFromRPY(geometry_msgs::Quaternion& ROS_quaternion, const float& roll,const float& pitch,const float& yaw)
  {
    tf2::Quaternion tf_quaternion;
    tf_quaternion.setRPY(roll,pitch,yaw);
    tf2::convert(tf_quaternion,ROS_quaternion);
  }

}
}
}