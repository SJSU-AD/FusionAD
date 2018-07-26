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

  double stanley::computeHeadingError(const double &vehHeading, const double &pathHeading)
  {
    //Follows the convention of left turn is positive 
    double headingError = pathHeading - vehHeading;
    
    if(std::isfinite(headingError))
    {
      return headingError;
    }
    else
    {
      std::cout << "Heading Error Calculation Is Not Finite!" << std::endl;
      return std::numeric_limits<double>::quiet_NaN();
    }    
  }
  
  double stanley::computePathHeading(const pathMatrix42d &trajectory, const int &targetIndex)
  {
    //TODO: Complete path Heading interpolation
    Eigen::Matrix4d designMatrix;
    Eigen::Vector4d responseVector;
    designMatrix << pow(trajectory(0,0),3) , pow(trajectory(0,0),2), trajectory(0,0), 1,
                    pow(trajectory(1,0),3) , pow(trajectory(1,0),2), trajectory(1,0), 1,
                    pow(trajectory(2,0),3) , pow(trajectory(2,0),2), trajectory(2,0), 1,
                    pow(trajectory(3,0),3) , pow(trajectory(3,0),2), trajectory(3,0), 1;
    
    responseVector << trajectory(0,1),
                      trajectory(1,1),
                      trajectory(2,1),
                      trajectory(3,1);

    Eigen::ColPivHouseholderQR<Eigen::Matrix4d> dec(designMatrix);
    Eigen::Vector4d x = dec.solve(responseVector);  

    Eigen::Vector3d pathYawCoeff;
    pathYawCoeff << pathYawCoeff(0)*3,
                    pathYawCoeff(1)*2,
                    pathYawCoeff(2);     
               
    //Calculate pathSlope at index value;
    double pathSlope = pathYawCoeff(0)*pow(trajectory(targetIndex,0),2) +
                       pathYawCoeff(1)*trajectory(targetIndex,0) +
                       pathYawCoeff(2);

    double nextXpos = trajectory(targetIndex+1,0);
    double nextYpos = trajectory(targetIndex+1,1);

    double targetXpos = trajectory(targetIndex,0);
    double targetYpos = trajectory(targetIndex,1);

    //Now estimate the direction of the path to generate heading.
    //Find the linear representation of the slope
    double b = targetYpos - (pathSlope * targetXpos);
    
    //Find the next Y point of the slope to get the linear interpolated vector
    double nextYslope = (pathSlope*nextXpos) + b;

    //Linear interpolate the vector
    double heading_dx = nextXpos - targetXpos;
    double heading_dy = nextYslope - targetYpos;

    double pathHeadingTheta = atan2(heading_dy, heading_dx);

    //The derived path heading should match the two possible heading theta from slope
    if(pathHeadingTheta != atan(pathSlope))
    {
      if(pathHeadingTheta != (atan(pathSlope) + 3.14159265))
      {
        std::cout << "Path Heading don't match predicted slope value!" << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
      }
    }
    else
    {
      //Path heading is correct, return the value
      return pathHeadingTheta;
    }
  }

  double stanley::computeCrossTrackError(const double &routeTheta, const double &dx, const double &dy)
  {
    double cosTheta = std::cos(routeTheta);
    double sinTheta = std::sin(routeTheta);
    double lateralError = (-1) * ((cosTheta * dy) - (sinTheta * dx));    
    if(std::isfinite(lateralError))
    {
      return lateralError;
    }
    else
    {
      std::cout << "Lateral Error Calculation Is Not Finite!" << std::endl;
      return std::numeric_limits<double>::quiet_NaN();
    }    
  }

  //A positive steering angle denotes the vehicle to turn its steering wheel CCW (left)
  double stanley::computeSteeringAngle(const Eigen::Vector2d &vehPos, const std::vector<double> &routeX, const std::vector<double> &routeY,
                                      const double &vehSpeed, const int &wpIndex, const double& vehTheta, const double &gain)
  {
    int trimmedIndex;
    pathMatrix42d trimmedRoute;
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
    double pathTheta = computePathHeading(trimmedRoute, trimmedIndex);
    //Find the global x delta of veh2path
    double tracking_dx = vehPos(0) - trimmedRoute(trimmedIndex,0);
    //Find the global y delta of veh2path
    double tracking_dy = vehPos(1) - trimmedRoute(trimmedIndex,1);
    //Compute Cross track error (lateral error of the veh to the path)
    double crossTrackError = computeCrossTrackError(pathTheta, tracking_dx, tracking_dy);
    //Find heading difference between vehicle orientation and the path
    double headingDelta = computeHeadingError(vehTheta , pathTheta);
    //Apply stanley kinematic control law
    double steeringAngle = headingDelta + std::atan((gain * crossTrackError)/vehSpeed);
    if(std::isfinite(steeringAngle))
    {
      return steeringAngle;
    }
    else
    {
      std::cout << "Steering Angle Calculation Is Not Finite!" << std::endl;
      return std::numeric_limits<double>::quiet_NaN();
    }
  }
}
}
}