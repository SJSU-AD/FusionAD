#include "control/lat_controller.h"

namespace fusionad{
namespace control{
namespace lat_controller{

  stanley::stanley()
  {
    controlGain = 0;
  }
  stanley::~stanley()
  {
  }

  double stanley::computeHeadingError(const double &vehHeading, const double &pathHeading)
  {
    headingError = vehHeading - pathHeading;
  }
  double stanley::computePathHeading(const Eigen::pathMatrix42d &trajectory, const int &targetIndex)
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
    ColPivHouseholderQR<Matrix4d> dec(designMatrix);
    Vector4d x = dec.solve(responseVector);                      
    Eigen::Vector3d pathYawCoeff;
    pathYawCoeff << pathYawCoeff(0)*3,
                    pathYawCoeff(1)*2,
                    pathYawCoeff(2);                    
    //Calculate pathSlope at index value;
  }
  double stanley::computeNonLinControlTerm(const double &linear_velocity, const double &position, const double &waypoint)
  {
    double nonLinControl = std::atan();
  }
  double stanley::computeCrossTrackError(const double &routeTheta, const double &dx, const double &delta_y)
  {

  }
  double stanley::computeSteeringAngle(const Eigen::Vector2d &vehPos, const Eigen::Vector2d &targetPos, 
                                      const std::vector<double> &routeX, const std::vector<double> &routeY,
                                      const double &vehSpeed, const int &wpIndex)
  {
    int trimmedIndex;
    Eigen::pathMatrix42d trimmedRoute;
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
    computePathHeading(trimmedRoute, trimmedIndex)
  }
}
}
}