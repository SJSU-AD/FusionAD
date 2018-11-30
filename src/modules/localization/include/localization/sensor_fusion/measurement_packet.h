#ifndef MEASUREMENT_PACKAGE_H_
#define MEASUREMENT_PACKAGE_H_

#include "Eigen/Dense"

class MeasurementPackage {
public:
    long long timestamp;

    enum SensorType {
        IMU,
        GPS,
        WHEEL_ODOM
    } sensor_type;

    Eigen::VectorXd raw_measurements;
};

#endif 