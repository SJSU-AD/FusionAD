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
                                      const std::vector<double> &route, 
                                      const double &vehSpeed, const int &wpIndex)
  {

  }
}
}
}