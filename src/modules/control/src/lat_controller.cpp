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
  double stanley::computePathHeading(const Eigen::pathMatrix42d &trajectory, const Eigen::Vector2d &pos, const int &targetIndex)
  {
    //TODO: Complete path Heading interpolation
  }
  double stanley::computeNonLinControlTerm(const double &linear_velocity, const double &position, const double &waypoint)
  {
    double nonLinControl = std::atan()
  }
  double stanley::computeCrossTrackError(const double &routeTheta, const double &dx, const double &delta_y)
  {

  }
  double stanley::computeSteeringAngle(const Eigen::Vector2d &vehPos, const Eigen::Vector2d &targetPos, 
                                      const std::vector<double> &routeX, const std::vector<double> &routeY,
                                      const double &vehSpeed, const int &wpIndex)
  {
    Eigen::pathMatrix42d trimmedRoute;
    //Stored the trimmed route into the matrix
    if(wpIndex != 0)
    {
      for(int j = wpIndex+2 , i = 0 ; j >= wpIndex-1 , i < 4 ; j--, i++)
      {
        trimmedRoute(i,0) = routeX[j];
        trimmedRoute(i,1) = routeY[j];
      }
    }
    else if(wpIndex == 0)
    {
      for(int j = wpIndex+3 , i = 0; j >= wpIndex , i < 4; j-- , i++)
      {
        trimmedRoute(i,0) = routeX[j];
        trimmedRoute(i,1) = routeY[j];
      }
    }
    //Now the trimmed route matrix is populated

  }
}
}
}