#ifndef FRAME_CALIBRATION_H
#define FRAME_CALIBRATION_H

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/Float32.h"

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
        // initializing nodehandle
        ros::NodeHandle frameCalibrationNode_nh;

        // initializing the timer
        ros::Timer calibration_timer;

        // initialize publishers
        // publisher for calibrated x and y positions
        ros::Publisher calibrated_x_pose_pub;
        ros::Publisher calibrated_y_pose_pub;

        // publisher for calibrated yaw orientation
        ros::Publisher calibrated_yaw_pub;

        // initialize subscribers
        ros::Subscriber geodesy_sub;
        ros::Subscriber yaw_sub;

        // messages after transform
        nav_msgs::Odometry geodesy_tf_msg;

        nav_msgs::Odometry calibrated_odom_msg;
        
        // message threshold for calibration
        const int MSG_THRESHOLD = 100;
        // initializing array with 100 elements
        float msg_storage[99];
        
        float calibrated_yaw;
        float yaw_msg_storage[99];
        unsigned int yaw_msg_count = 0;
        bool yaw_msg_calibration_status = false;
        
        float calibrated_x_pos = 0;
        float calibrated_y_pos = 0;
        
        float geodesy_x_msg_storage[99];
        float geodesy_y_msg_storage[99]; 
        unsigned int geodesy_msg_count = 0;
        bool geodesy_msg_calibration_status = false;

        // void geodesy_x_calibration();
        // void geodesy_y_calibration();

        float message_calibration(unsigned int& msg_count, float msg_storage[99]);
        // declaring callbacks
        void geodesyCallback(const nav_msgs::Odometry& geodesy_msg);
        void yawCallback(const std_msgs::Float32& yaw_msg);
        void timerCallback(const ros::TimerEvent& event);

};
}// frame_calibration_node
}// localization
}// fusionad


#endif