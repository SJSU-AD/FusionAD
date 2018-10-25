#include "control/lat_controller.h"

namespace fusionad{
namespace control{
namespace lat_controller{

  stanley::stanley()
  {
  }
  stanley::~stanley()
  {
  }
  
  /*float stanley::estimatePathHeading(const std::vector<float> &pathX, const std::vector<float> &pathY, const int& index)
  {
    //Linear interpolate the vector
    float heading_dx = pathX[index + 1] - pathX[index];
    float heading_dy = pathY[index + 1] - pathY[index];

    float untouched_theta = atan2(heading_dy, heading_dx);
    float pathHeadingTheta;
    if((abs(untouched_theta)/untouched_theta) < 0)
    {
      //Because ATAN2 has a range of (-pi, +pi)
      //If the atan2 return ngative, put in the phase shift
      pathHeadingTheta = (2*M_PI) - abs(untouched_theta); 
    }
    else
    {
      //if the value is positive, leave it as is
      pathHeadingTheta = untouched_theta;
    }

    if(std::isfinite(pathHeadingTheta))
    {
      debug_info.est_pathHeading = pathHeadingTheta;
      return pathHeadingTheta;
    }
    else
    {
      debug_info.isCalculationInvalid = true;
      std::cout << "Path Heading Calculation Is Not Finite!" << std::endl;
      return std::numeric_limits<float>::quiet_NaN();
    }      
  }*/

  float stanley::computePathHeading(const std::vector<float> &navX, const std::vector<float> &navY ,const int &targetIndex, const int &navSize)
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
      debug_info.isCalculationInvalid = true;
      std::cout << "Path Heading Calculation Is Not Finite!" << std::endl;
      return std::numeric_limits<float>::quiet_NaN();
    }  
  }

  /*float stanley::computePathHeading(const pathMatrix42f &trajectory, const int &targetIndex)
  {
    //TODO: Complete path Heading interpolation
    Eigen::Matrix4f designMatrix;
    Eigen::Vector4f responseVector;
    designMatrix << pow(trajectory(0,0),3) , pow(trajectory(0,0),2), trajectory(0,0), 1,
                    pow(trajectory(1,0),3) , pow(trajectory(1,0),2), trajectory(1,0), 1,
                    pow(trajectory(2,0),3) , pow(trajectory(2,0),2), trajectory(2,0), 1,
                    pow(trajectory(3,0),3) , pow(trajectory(3,0),2), trajectory(3,0), 1;
    
    responseVector << trajectory(0,1),
                      trajectory(1,1),
                      trajectory(2,1),
                      trajectory(3,1);

    Eigen::ColPivHouseholderQR<Eigen::Matrix4f> dec(designMatrix);
    pathYawCoeff = dec.solve(responseVector);  

    pathYawCoeff << pathYawCoeff(0)*3,
                    pathYawCoeff(1)*2,
                    pathYawCoeff(2);     
               
    //Calculate pathSlope at index value;
    float pathSlope = pathYawCoeff(0)*pow(trajectory(targetIndex,0),2) +
                       pathYawCoeff(1)*trajectory(targetIndex,0) +
                       pathYawCoeff(2);

    float nextXpos = trajectory(targetIndex+1,0);
    float nextYpos = trajectory(targetIndex+1,1);

    float targetXpos = trajectory(targetIndex,0);
    float targetYpos = trajectory(targetIndex,1);

    //Now estimate the direction of the path to generate heading.
    //Find the linear representation of the slope
    float b = targetYpos - (pathSlope * targetXpos);
    
    //Find the next Y point of the slope to get the linear interpolated vector
    float nextYslope = (pathSlope*nextXpos) + b;

    //Linear interpolate the vector
    float heading_dx = nextXpos - targetXpos;
    float heading_dy = nextYslope - targetYpos;

    float untouched_theta = atan2(heading_dy, heading_dx);
    float pathHeadingTheta;
    if((abs(untouched_theta)/untouched_theta) < 0)
    {
      //Because ATAN2 has a range of (-pi, +pi)
      //If the atan2 return ngative, put in the phase shift
      pathHeadingTheta = (2*M_PI) - abs(untouched_theta); 
    }
    else
    {
      //if the value is positive, leave it as is
      pathHeadingTheta = untouched_theta;
    }

    if(std::isfinite(pathHeadingTheta))
    {
      debug_info.pathHeading = pathHeadingTheta;
      return pathHeadingTheta;
    }
    else
    {
      debug_info.isCalculationInvalid = true;
      std::cout << "Path Heading Calculation Is Not Finite!" << std::endl;
      return std::numeric_limits<float>::quiet_NaN();
    }  
  }
  */
  float stanley::computeCrossTrackError(const float &routeTheta, const float &dx, const float &dy)
  {
    // See computeCTE.m for proof  @Menson_Li
    float lateralError = ((std::sin(routeTheta) * dx) - (std::cos(routeTheta) * dy));    
    
    /**************************NaN Check*****************************/

    if(std::isfinite(lateralError))
    {
      debug_info.CTE = lateralError;
      return lateralError;
    }
    else
    {
      debug_info.isCalculationInvalid = true;
      std::cout << "Lateral Error Calculation Is Not Finite!" << std::endl;
      return std::numeric_limits<float>::quiet_NaN();
    }    
  }

  //A positive steering angle denotes the vehicle to turn its steering wheel CCW (left)
  float stanley::computeSteeringAngle(const Eigen::Vector2f &vehPos, const std::vector<float> &routeX, const std::vector<float> &routeY,
                                      const float &vehSpeed, const int &wpIndex, const float& vehTheta, const float &gain,const int &pathSize)
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
    if(std::isfinite(headingDelta))
    {
      debug_info.headingError = headingDelta;
    }
    else
    {
      debug_info.isCalculationInvalid = true;
      std::cout << "Heading Error Calculation Is Not Finite!" << std::endl;
    }    
    //Apply stanley kinematic control law
    float unfilteredSteeringAngle = headingDelta + std::atan((gain * crossTrackError)/vehSpeed);

    float steeringAngle = 0;

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
      debug_info.isCalculationInvalid = true;
      std::cout << "Steering Angle Calculation Is Not Finite! Returning -69 as steering angle." << std::endl;
      return -69;
    }
  }
}
}
}