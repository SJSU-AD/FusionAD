#ifndef LAT_CONTROLLER_H
#define LAT_CONTROLLER_H

//Declare all used external libraries
#include "Eigen/Dense"
#include <cmath>
#include <vector>
#include <iostream>
#include <limits>
#include <interface/Stanley_debug.h>

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
    interface::Stanley_debug debug_info;
    // Steering Limit is set to 21 deg
    float steering_limit = 0.36652;
    float computeSteeringAngle(const Eigen::Vector2f &vehPos,const std::vector<float> &routeX,
                                const std::vector<float> &routeY,const float &vehSpeed,
                                const int &wpIndex, const float &vehTheta,const float &gain, const int &pathSize);
  private:
    float pathSlope;
    typedef Eigen::Matrix<float, 4, 2> pathMatrix42f; 
    float computePathHeading(const std::vector<float> &navX, const std::vector<float> &navY ,const int &targetIndex, const int &navSize);
    float estimatePathHeading(const std::vector<float> &pathX, const std::vector<float> &pathY, const int &index);
    float computeCrossTrackError(const float &routeTheta, const float &dx, const float &delta_y);
};
}
}
}
#endif  