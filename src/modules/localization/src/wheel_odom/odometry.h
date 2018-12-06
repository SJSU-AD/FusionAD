#ifndef ODOMETRY_H
#define ODOMETRY_H
//TODO: Possibly add x and y-position dead reckoning to wheel odometry code
/*
Takes wheel odometry from Arduino encoders and translates to vehicle velocity
Uses an initialized orientation estimate from the IMU by collecting 100 samples
and then averaging them out before vehicle operation
'''
NOTE: This script is to handle the raw wheel odometry values from the Signwise 600 P/R rotary encoder.
      It also takes in various inputs from topics such as steering, and yaw from the IMU to dead-reckon 
      position and velocity in the X and Y frame.

      TOPIC SUBSCRIBERS: /localization/right_encoder_reading
                         /localization/left_encoder_reading
                         /control/steering_response
                         /localization/rotated_yaw

      TOPIC PUBLISHER:   /localization/wheel_odom_twist

'''
*/

#include "ros/ros.h"
//#include "interface/Tf_rotate.h"
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
#include "stdio.h"
#include <queue>
#include <algorithm>
//#include <tf2/LinearMath/Quaternion.h>

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

        // quaternion rotation initialization
        /*reference
        http://wiki.ros.org/tf2/Tutorials/Quaternions
        */
        //tf::Quaternion q_rot;

        // initialize timer
        ros::Timer odometry_timer;
        // initialize publisher
        ros::Publisher odometry_pub;

        // initialize subscriber
        ros::Subscriber odometry_left_sub;
        ros::Subscriber odometry_right_sub;
        ros::Subscriber odometry_steering_sub;
        ros::Subscriber odometry_imu_sub;

                
        // Kalman Filter Preparation
        // Odometry messages
        nav_msgs::Odometry full_odom_message;
        geometry_msgs::TwistWithCovariance velocity_estimate;
        //geometry_msgs::PoseWithCovariance position_estimate;
        
        // Imu message to extract yaw
        // use the Tf_rotate for its custom message
        // wheelbase in meters
        const float WHEELBASE = 0.7112;
        // wheel radius in meters
        const float WHEEL_RADIUS = 0.1397;
        // time interval
        const float DT = 0.02;
        // left angular velocity
        float left_angular_vel = 0;
        // right angular velocity
        float right_angular_vel = 0;
        // steering angle (need to change this to float)
        float steering_angle = 0;
        // previous odometry values
        long previous_right_odometry_msg = 0;
        long previous_left_odometry_msg = 0;

        // pulses per rotation
        const long pulses_per_rotation = 1200;
        
        // odometry_state_estimation() variables for dead-reckoning
        float vel_magnitude = 0;
        float x_velocity = 0;
        float y_velocity = 0;
        
        float x_position = 0;
        float y_position = 0;
        float previous_x_position = 0;
        float previous_y_position = 0;
        
        float yaw_estimate = 0;
        float previous_yaw = 0;

        // initialize subscriber messages
        long left_odometry_msg = 0;
        long right_odometry_msg = 0;
        float steering_msg = 0;

        float yaw_msg = 0;
        // number of messages to store into yaw_msg_storage
        const int yaw_msg_threshold = 100;
        // array to store yaw messages
        float yaw_msg_storage[100];
        unsigned int yaw_msg_count = 0;

        // initializing a deque for a running median
        std::deque<float> vel_deque;
        
        // declare support functions
        // performs a calibration for the yaw estimate
        void imu_calibration();
        // calculates the current velocity state of the vehicle
        void odometry_state_estimation();
        // does the median filter calculation for the wheel odometry
        void wheel_odom_median_filter();
        // declare the callbacks
        void leftodometryCallback(const std_msgs::Int32& left_odometry_msg);
        void rightodometryCallback(const std_msgs::Int32& right_odometry_msg);
        void steeringCallback(const std_msgs::Int16& steering_msg);
        void imuCallback(const std_msgs::Float32& yaw_msg);
        //void robot_localization_matrices();
        void timerCallback(const ros::TimerEvent& event);
        

}; // WheelOdometryNode
} // wheel_odometry_node
} // localization
} // fusionad
#endif
