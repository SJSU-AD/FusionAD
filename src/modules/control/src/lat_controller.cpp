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

  float Stanley::computePathHeading(const std::vector<float> &navX, const std::vector<float> &navY ,const int &targetIndex, const int &navSize)
  {
    Eigen::Matrix3f designMatrix;
    Eigen::Vector3f responseVector;
     //Fit with Two point forward at beginning
    if(targetIndex == 0)                              
    {
      designMatrix <<   std::pow(navX[targetIndex],2)  , navX[targetIndex],     1,
                        std::pow(navX[targetIndex+1],2), navX[targetIndex+1],   1,
                        std::pow(navX[targetIndex+2],2), navX[targetIndex+2],   1;                        
    
      responseVector << navY[targetIndex],
                        navY[targetIndex+1],
                        navY[targetIndex+2];
    }
    //Fit with Two points before
    else if(targetIndex == (navSize - 1))                   
    {
      designMatrix <<   std::pow(navX[targetIndex-2],2)  , navX[targetIndex-2], 1,
                        std::pow(navX[targetIndex-1],2),   navX[targetIndex-1], 1,
                        std::pow(navX[targetIndex],2),     navX[targetIndex],   1;
    
      responseVector << navY[targetIndex-2],
                        navY[targetIndex-1],
                        navY[targetIndex]; 
    }
    // Normal index fitting
    else  
    {
      designMatrix <<   std::pow(navX[targetIndex-1],2), navX[targetIndex-1], 1,
                        std::pow(navX[targetIndex],2),   navX[targetIndex],   1,
                        std::pow(navX[targetIndex+1],2), navX[targetIndex+1], 1;
    
      responseVector << navY[targetIndex-1],
                        navY[targetIndex],
                        navY[targetIndex+1];                               
    }

    Eigen::ColPivHouseholderQR<Eigen::Matrix3f> dec(designMatrix);
    Eigen::Vector3f x = dec.solve(responseVector);  
    Eigen::Vector2f pathYawCoeff;

    // Taking the derivative of the function
    pathYawCoeff << x(0)*2,
                    x(1);     
              
    //Calculate pathSlope at index value;
    pathSlope = pathYawCoeff(0) * navX[targetIndex] +
                pathYawCoeff(1);   

    float nextXpos = navX[targetIndex + 1];
    float nextYpos = navY[targetIndex + 1];

    float targetXpos = navX[targetIndex];
    float targetYpos = navY[targetIndex];

    //Now estimate the direction of the path to generate heading.
    //Find the linear representation of the slope
    float b = targetYpos - (pathSlope * targetXpos);
    
    //Find the next Y point of the slope to get the linear interpolated vector
    float nextYslope = (pathSlope*nextXpos) + b;

    //Linear interpolate the vector
    float heading_dx = nextXpos - targetXpos;
    float heading_dy = nextYslope - targetYpos;

    float pathHeadingTheta = atan2(heading_dy, heading_dx);


    /**************************NaN Check*****************************/
    if(std::isfinite(pathHeadingTheta))
    {
      debug_info.pathHeading = pathHeadingTheta;
      return pathHeadingTheta;
    }
    else
    {
      debug_info.pathHeadingCalcInvalid = true;
      ROS_FATAL("Path Heading Calculation Is Not Finite!");
      return std::numeric_limits<float>::quiet_NaN();
    }  
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
  float Stanley::computeSteeringAngle(const Eigen::Vector2f &vehPos, const std::vector<float> &routeX, const std::vector<float> &routeY,
                                      const float &vehSpeed, const int &wpIndex, const float& vehTheta, const float p_gain, const float d_gain
                                      ,const int &pathSize)
  {
    //obtain the path heading
    //float unusedpathTheta = estimatePathHeading(routeX, routeY, wpIndex);
    //float unused_pathTheta = computePathHeading(trimmedRoute, trimmedIndex);
    float pathTheta = computePathHeading(routeX, routeY, wpIndex, pathSize);
    //Find the global x delta of veh2path
    float tracking_dx = vehPos(0) - routeX[wpIndex];
    //Find the global y delta of veh2path
    float tracking_dy = vehPos(1) - routeY[wpIndex];
    //Compute Cross track error (lateral error of the veh to the path)
    float crossTrackError = computeCrossTrackError(pathTheta, tracking_dx, tracking_dy);
    //Find heading difference between vehicle orientation and the path
    //Follows the convention of left turn is positive 
    float headingDelta = pathTheta - vehTheta;

    // Vehicle State Debug Message
    debug_info.vehicle_Position.x = vehPos(0);
    debug_info.vehicle_Position.y = vehPos(1);
    debug_info.vehicle_Position.z = 0;
    debug_info.vehicle_heading = vehTheta;

    /**************************NaN Check*****************************/
    if(std::isfinite(headingDelta))
    { 
      debug_info.headingError = headingDelta;
    }
    else
    {
      debug_info.headingErrorCalcInvalid = true;
      ROS_FATAL("Heading Error Calculation Is Not Finite!");
    }    
    
    //Apply Stanley kinematic control law
    float unfilteredSteeringAngle = 0;

    if(std::isfinite(control_interval))
    {
      debug_info.control_loop_period = control_interval;
    }
    else
    {
      ROS_FATAL("Control Loop Period Is Not Finite!");
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
    }

    unfilteredSteeringAngle = headingDelta + 
                              std::atan(((p_gain*crossTrackError) + 
                              (d_gain * crossTrackError_dot))/ vehSpeed);

    float steeringAngle = 0;

    previous_crossTrackError = crossTrackError;

    // Saturation function for limiting steering output
    if(std::abs(unfilteredSteeringAngle) > steering_limit)
    {
      steeringAngle = (std::abs(unfilteredSteeringAngle)/unfilteredSteeringAngle) * steering_limit;
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
      ROS_FATAL("Steering Angle Calculation Is Not Finite! Returning -69 as steering angle.");
      return -69;
    }
  }
}
}
}