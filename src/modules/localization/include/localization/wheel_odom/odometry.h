#ifndef ODOMETRY_H
#define ODOMETRY_H

/*
Takes wheel odometry from Arduino encoders and translates to vehicle velocity in the base_link frame

NOTE: This script is to handle the raw wheel odometry values from the Signwise 600 P/R rotary encoder and 
      calculate velocity in the base_link frame

Subscribers:  
-------------------------------------------
Topic:  /localization/right_encoder_reading
            Msg: std_msgs::Int16
Topic:  /localization/left_encoder_reading
            Msg: std_msgs::Int16

Publisher:
-------------------------------------------  
Topic:  /localization/wheel_odom
            Msg: nav_msgs::Odometry
*/

#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Int16.h"
#include "std_msgs/Float32.h"
#include "math.h"
#include "Eigen/Dense"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "geometry_msgs/TwistWithCovariance.h"
#include "sensor_msgs/Imu.h"
#include "tf/transform_broadcaster.h"
#include "tf/transform_listener.h"
#include "stdio.h"
#include <queue>
#include <algorithm>

namespace fusionad
{
namespace localization
{
namespace wheel_odometry_node
{
class WheelOdometryNode
{
    public:
        WheelOdometryNode();
        ~WheelOdometryNode();
        void initRosComm();
        
    private:
        // initialize the nodehandle
        ros::NodeHandle odometrynode_nh;

        // initialize timer
        ros::Timer odometry_timer;
        // initialize publisher
        ros::Publisher odometry_pub;

        // initialize subscriber
        ros::Subscriber left_encoder_sub;
        ros::Subscriber right_encoder_sub;
                
        // Kalman Filter Preparation
        // Odometry messages
        nav_msgs::Odometry full_odom_message;
        geometry_msgs::TwistWithCovariance velocity_estimate;
        geometry_msgs::PoseWithCovariance position_estimate;
        
        // red car wheel radius in meters
        // const float WHEEL_RADIUS = 0.1397;
        
        // black car wheel radius in meters
        const float WHEEL_RADIUS = 0.28675; 

        // time interval
        const float DT = 0.02;
        // left angular velocity
        float left_angular_vel = 0;
        // right angular velocity
        float right_angular_vel = 0;

        // previous odometry values
        long previous_right_encoder_msg = 0;
        long previous_left_encoder_msg = 0;

        // pulses per rotation
        const long pulses_per_rotation = 1200;
        
        // odometry_state_estimation() variables for dead-reckoning
        float vel_magnitude = 0;

        // initialize subscriber messages
        long left_odometry_msg = 0;
        long right_odometry_msg = 0;

        bool calibration_completed = false;

        // initializing a deque for a running median
        std::deque<float> vel_deque;
        
        // declare support functions
        // calculates the current velocity state of the vehicle
        void odometry_state_estimation();
        // does the median filter calculation for the wheel odometry
        void wheel_odom_median_filter();

        // declare the callbacks
        void leftEncoderCallback(const std_msgs::Int32& left_encoder_msg);
        void rightEncoderCallback(const std_msgs::Int32& right_encoder_msg);
        void timerCallback(const ros::TimerEvent& event);
        

}; // WheelOdometryNode
} // wheel_odometry_node
} // localization
} // fusionad
#endif
