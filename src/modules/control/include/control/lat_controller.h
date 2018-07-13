#ifndef LAT_CONTROLLER_H
#define LAT_CONTROLLER_H

//Declare all used external libraries
#include "Eigen/Dense"
#include "math.h"
#include <vector>
#include <iostream>
#include <limits>


//Namespace declaration
namespace fusionad
{
namespace control
{
namespace lat_controller
{
class stanley
{
  public:
    stanley();
    ~stanley();
  private:
    //TODO: Declare a custom ROS control message output after message definition is complete
    //ROS --> steering message.
    typedef Eigen::Matrix<double, 4, 2> pathMatrix42d; 
    double computeHeadingError(const double &vehHeading, const double &pathHeading);
    double computePathHeading(const Eigen::pathMatrix42d &trajectory, const int &targetIndex);
    double computeCrossTrackError(const double &routeTheta, const double &dx, const double &delta_y);
    double computeSteeringAngle(const Eigen::Vector2d &vehPos, const Eigen::Vector2d &targetPos, 
                                const std::vector<double> &routeX, const std::vector<double> &routeY,
                                const double &vehSpeed, const int &wpIndex, const double &vehTheta, 
                                const double &gain);
};
}
}
}
#endif  