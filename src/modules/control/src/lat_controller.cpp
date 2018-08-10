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

  float stanley::computeHeadingError(const float &vehHeading, const float &pathHeading)
  {
    //Follows the convention of left turn is positive 
    float headingError = pathHeading - vehHeading;
    
    if(std::isfinite(headingError))
    {
      debug_info.headingError = headingError;
      return headingError;
    }
    else
    {
      debug_info.isCalculationInvalid = true;
      std::cout << "Heading Error Calculation Is Not Finite!" << std::endl;
      return std::numeric_limits<float>::quiet_NaN();
    }    
  }
  
  float stanley::computePathHeading(const pathMatrix42f &trajectory, const int &targetIndex)
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
    Eigen::Vector4f x = dec.solve(responseVector);  

    Eigen::Vector3d pathYawCoeff;
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

    float pathHeadingTheta = atan2(heading_dy, heading_dx);
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

  float stanley::computeCrossTrackError(const float &routeTheta, const float &dx, const float &dy)
  {
    float cosTheta = std::cos(routeTheta);
    float sinTheta = std::sin(routeTheta);
    float lateralError = (-1) * ((cosTheta * dy) - (sinTheta * dx));    
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
                                      const float &vehSpeed, const int &wpIndex, const float& vehTheta, const float &gain)
  {
    int trimmedIndex;
    pathMatrix42f trimmedRoute;
    //Stuff the trimmed route into the matrix
    if(wpIndex != 0)
    {
      for(int j = wpIndex+2 , i = 0 ; j >= wpIndex-1 , i < 4 ; j--, i++)
      {
        trimmedRoute(i,0) = routeX[j];
        trimmedRoute(i,1) = routeY[j];
      }
      trimmedIndex = 0;
    }
    else if(wpIndex == 0)
    {
      for(int j = wpIndex+3 , i = 0; j >= wpIndex , i < 4; j-- , i++)
      {
        trimmedRoute(i,0) = routeX[j];
        trimmedRoute(i,1) = routeY[j];
      }
      trimmedIndex = 1;
    }
    //Now the trimmed route matrix is populated

    //obtain the path heading
    float pathTheta = computePathHeading(trimmedRoute, trimmedIndex);
    //Find the global x delta of veh2path
    float tracking_dx = vehPos(0) - trimmedRoute(trimmedIndex,0);
    //Find the global y delta of veh2path
    float tracking_dy = vehPos(1) - trimmedRoute(trimmedIndex,1);
    //Compute Cross track error (lateral error of the veh to the path)
    float crossTrackError = computeCrossTrackError(pathTheta, tracking_dx, tracking_dy);
    //Find heading difference between vehicle orientation and the path
    float headingDelta = computeHeadingError(vehTheta , pathTheta);
    //Apply stanley kinematic control law
    float steeringAngle = headingDelta + std::atan((gain * crossTrackError)/vehSpeed);
    if(std::isfinite(steeringAngle))
    {
      debug_info.steeringAngle = steeringAngle;
      return steeringAngle;
    }
    else
    {
      debug_info.isCalculationInvalid = true;
      std::cout << "Steering Angle Calculation Is Not Finite!" << std::endl;
      return std::numeric_limits<float>::quiet_NaN();
    }
  }
}
}
}