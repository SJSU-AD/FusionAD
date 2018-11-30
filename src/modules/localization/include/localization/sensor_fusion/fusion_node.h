#ifndef FUSION_NODE_H
#define FUSION_NODE_H

#include "kalman_filter.h"
#include "measurement_packet.h"
#include "ros/ros.h"

namespace fusionad
{
namespace localization
{

class FusionNode {
public:
    /**
     * Constructor
     */
    FusionNode();

    /**
     * Destructor
     */
    ~FusionNode();

    /**
     * InitRosComm initializes all ROS related
     * variables such as Publishers, Subscribers, 
     * and NodeHandles.
     */
    void InitRosComm();

    /**
     * InitializeFilter initializes all matrices
     * of the kalman filter
     */
    void InitializeFilter();

private:
    fusionad::localization::kalman_filter filter;

    ros::NodeHandle fusion_nh;
    ros::Publisher fusion_main_pub;
    ros::Publisher fusion_debug_pub;
    ros::Subscriber imu_sub;
    ros::Subscriber wheel_odom_sub;
    ros::Subscriber gps_sub;

    bool is_initialized;
    long long previous_timestamp;

    Eigen::MatrixXd R_gps;    // GPS measurement noise
    Eigen::MatrixXd R_odom;   // Wheel odometry measurement noise
    Eigen::MatrixXd H_gps;    // Measurement function for GPS
    Eigen::MatrixXd H_odom;   // Measurement function for odometry

    /**
     * ProcessMeasurement handles the feeding of data into
     * the kalman filter
     * @param measurement_pack packaged measurement information
     */
    void ProcessMeasurement(const MeasurementPackage &measurement_pack);

    /**
     * IMU Callback handles packaging of incoming IMU data
     * into MeasurementPacket objects
     * @param inertial_msg Incoming IMU data
     */
    void IMU_Callback(const sensor_msgs::Imu& inertial_msg);

    /**
     * Wheel Odom Callback handles packaging of incoming Odometry data
     * into MeasurementPacket objects
     * @param odom_msg Incoming Odometry data
     */
    void Wheel_Odom_Callback(const sensor_msgs::Imu& odom_msg);

    /**
     * GPS Callback handles packaging of incoming GPS data
     * into MeasurementPacket objects
     * @param gps_msg Incoming GPS data
     */
    void GPS_Callback(const sensor_msgs::Imu& gps_msg);
};

}
}

#endif