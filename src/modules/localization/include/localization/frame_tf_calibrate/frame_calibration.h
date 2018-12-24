#ifndef FRAME_CALIBRATION_H
#define FRAME_CALIBRATION_H

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/Imu.h"
#include "std_msgs/Float32.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Point.h"
#include "tf/transform_broadcaster.h"
#include "tf/transform_listener.h"

namespace fusionad
{
namespace localization
{
namespace frame_calibration_node
{
class FrameCalibrationNode
{
    public:
        FrameCalibrationNode();
        ~FrameCalibrationNode();
        void initRosComm();

    private:

        // Booleans to know when calibration is finished
        bool yaw_is_calibrated = false;
        bool geodesy_is_calibrated = false;

        // Counters to keep track of # of samples
        unsigned int yaw_samples_counter = 0;
        unsigned int geodesy_samples_counter = 0;

        // Variables to store samples
        float yaw_accumulation = 0; 
        float geodesy_x_accumulation = 0;
        float geodesy_y_accumulation = 0;

        float geodesy_calibrated_x_value = 0;
        float geodesy_calibrated_y_value = 0;

        // initializing nodehandle
        ros::NodeHandle frameCalibrationNode_nh;

        // initialize publishers
        // publisher for calibrated x and y positions
        ros::Publisher calibrated_pose_pub;

        // publisher for calibrated yaw orientation
        ros::Publisher calibrated_yaw_pub;

        // publish transformed measurements
        ros::Publisher geodesy_tf_pub;
        ros::Publisher lidar_tf_pub;

        // initialize subscribers
        ros::Subscriber geodesy_sub;
        ros::Subscriber yaw_sub;
        ros::Subscriber lidar_sub;

        // messages after transform
        nav_msgs::Odometry geodesy_tf_msg;
        sensor_msgs::Imu imu_tf_msg;
        nav_msgs::Odometry lidar_tf_msg;
        
        tf::TransformListener geodesy_listener;
        tf::TransformListener lidar_listener;
        
        // message threshold for calibration
        const int MSG_THRESHOLD = 100;

        // declaring callbacks
        void geodesyCallback(const nav_msgs::Odometry& geodesy_msg);
        void yawCallback(const std_msgs::Float32& yaw_msg);
        void lidarCallback(const nav_msgs::Odometry& lidar_msg);
};
}// frame_calibration_node
}// localization
}// fusionad


#endif