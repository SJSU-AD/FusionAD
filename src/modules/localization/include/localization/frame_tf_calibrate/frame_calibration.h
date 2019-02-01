#ifndef FRAME_CALIBRATION_H
#define FRAME_CALIBRATION_H

/*
NOTE: This node listens to the tf broadcasts and performs the homogeneous transforms.
      Another major function of this node is to "calibrate" the initial position and orientation
      of the vehicle. The homogeneous transforms are applied and then the result is published.
      
Subscribers
--------------------------------------------------
Topic:  /gps/geodesy_odom
            Msg: nav_msgs::Odometry
Topic:  /imu
            Msg: sensor_msgs::Imu
Topic:  /localization/loam_odom_with_covar
            Msg: nav_msgs::Odometry

TF Listeners: Geodesy TF Message
              Lidar TF Message

Publishers
-------------------------------------------------
Topic: /localization/calibration
            Msg: geometry_msgs::Pose
Topic: /localization/rotated_imu
            Msg: sensor_msgs::Imu
Topic: /localization/geodesy_tf
            Msg: nav_msgs::Odometry
Topic: /localization/lidar_tf
            Msg: nav_msgs::Odometry
*/


#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/Imu.h"
#include "std_msgs/Float32.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Point.h"
#include "tf/transform_broadcaster.h"
#include "tf/transform_listener.h"
#include <cmath>

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

        // booleans to know when calibration is finished
        bool yaw_is_calibrated = false;
        bool geodesy_is_calibrated = false;

        // counters to keep track of # of samples
        unsigned int yaw_samples_counter = 0;
        unsigned int geodesy_samples_counter = 0;

        // variables to store samples
        float yaw_accumulation = 0; 
        float geodesy_x_accumulation = 0;
        float geodesy_y_accumulation = 0;

        float geodesy_calibrated_x_value = 0;
        float geodesy_calibrated_y_value = 0;

        // initializing nodehandle
        ros::NodeHandle frameCalibrationNode_nh;
        
        // initialize publishers
        ros::Publisher calibrated_pose_pub;

        // publish transformed measurements
        ros::Publisher geodesy_tf_pub;
        ros::Publisher lidar_tf_pub;
        ros::Publisher imu_tf_pub;

        // initialize subscribers
        ros::Subscriber geodesy_sub;
        ros::Subscriber imu_sub;
        ros::Subscriber lidar_sub;

        // inputs to the calibration message
        float calibrated_yaw;
        sensor_msgs::Imu rot_msg;

        // messages after transform
        nav_msgs::Odometry geodesy_tf_msg;
        sensor_msgs::Imu imu_tf_msg;
        nav_msgs::Odometry previous_geodesy_tf_msg;

        bool first_message_sent = false;

        nav_msgs::Odometry lidar_tf_msg;
        
        tf::TransformListener geodesy_listener;
        tf::TransformListener lidar_listener;
        
        // message threshold for calibration
        const int MSG_THRESHOLD = 100;


        // declaring callbacks
        void geodesyCallback(const nav_msgs::Odometry& geodesy_msg);
        void yawCallback(const sensor_msgs::Imu& imu_msg);
        void lidarCallback(const nav_msgs::Odometry& lidar_msg);
};
}// frame_calibration_node
}// localization
}// fusionad


#endif