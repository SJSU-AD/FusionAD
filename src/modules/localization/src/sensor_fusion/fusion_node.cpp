#include "localization/sensor_fusion/kalman_filter.h"

namespace fusionad
{
namespace localization
{

FusionNode::FusionNode() {
    is_initialized = false;

    previous_timestamp = 0;

    R_gps = MatrixXd(2, 2);
    R_odom = MatrixXd(2, 2);
    H_gps = MatrixXd(2, 4);
    H_odom = MatrixXd(2, 4);

    /*
    R_gps << x_variance, 0,
            0, y_variance;
    */

   /*
    R_odom << x_variance, 0,
            0, y_variance;
    */

    H_gps   <<  1, 0, 0, 0,
                0, 1, 0, 0;

    H_odom  <<  0, 0, 1, 0,
                0, 0, 0, 1;
}

FusionNode::~FusionNode() {}

void FusionNode::InitRosComm() {

}

void FusionNode::InitializeFilter() {
    /*
    * Initialize: x_, P_, F_, B_, Q_, H_, R_
    */
}

void FusionNode::IMU_Callback(const sensor_msgs::Imu& inertial_msg) {
    //Check if initialized
    //if not, add yaw values to runninng average
}

void FusionNode::Wheel_Odom_Callback(const sensor_msgs::Imu& odom_msg) {

}

void FusionNode::GPS_Callback(const sensor_msgs::Imu& gps_msg) {

}

}
}