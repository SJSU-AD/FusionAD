#ifndef LAT_CONTROLLER_H
#define LAT_CONTROLLER_H

//Declare all used external libraries
#include "Eigen/Dense"
#include "math.h"
#include <vector>
#include <iostream>


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
          double controlGain;
          //TODO: Declare a custom ROS control message output after message definition is complete
          //ROS --> steering message.
          typedef Eigen::Matrix<double, 4, 2> pathMatrix42d; 
          double computeHeadingError(const double &vehHeading, const double &pathHeading);
          double computePathHeading(const Eigen::pathMatrix42d &trajectory, const Eigen::Vector2d &pos, const int &targetIndex);
          double computeNonLinControlTerm(const double &linear_velocity, const double &position, const double &waypoint);
          double computeCrossTrackError(const double &routeTheta, const double &dx, const double &delta_y);
          double computeSteeringAngle(const Eigen::Vector2d &vehPos, const Eigen::Vector2d &targetPos, 
                                      const std::vector<double> &route, 
                                      const double &vehSpeed, const int &wpIndex);
      };
    }
  }
}
#endif  