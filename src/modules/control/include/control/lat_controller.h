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
    float computeSteeringAngle(const Eigen::Vector2f &vehPos,const std::vector<float> &routeX,
                                const std::vector<float> &routeY,const float &vehSpeed,
                                const int &wpIndex, const float &vehTheta,const float &gain);

  private:
    typedef Eigen::Matrix<float, 4, 2> pathMatrix42f; 
    float computeHeadingError(const float &vehHeading, const float &pathHeading);
    float computePathHeading(const pathMatrix42f &trajectory, const int &targetIndex);
    float computeCrossTrackError(const float &routeTheta, const float &dx, const float &delta_y);
};
}
}
}
#endif  