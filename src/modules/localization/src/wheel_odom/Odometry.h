#ifndef ODOMETRY_H
#define ODOMETRY_H
// TODO: RENAME FILES TO Odometry_Node
/*
Takes wheel odometry from Arduino encoders and translates to vehicle velocity
The IMU messages are already taken care of in the razor_9_dof_imu package
just need to subscribe to this specific topic
'''
NOTE: This script is to handle the raw wheel odometry values from the Signwise 600 P/R rotary encoder.
      It also takes in various inputs from topics such as steering, and yaw from the IMU to dead-reckon 
      position and velocity in the X and Y frame.

      TOPIC INPUTS: /localization/right_encoder_reading
                    /localization/left_encoder_reading
                    /control/steering_response
                    /geodesy/tf

      TOPIC OUTPUTS: /localization/odom_state_estimate

'''
*/

#include "ros/ros.h"
//#include "interface/Tf_rotate.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Int32.h"
#include "math.h"
//#include "Eigen/Dense"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "geometry_msgs/TwistWithCovariance.h"
#include "sensor_msgs/Imu.h"
//#include <tf2/LinearMath/Quaternion.h>

namespace fusionad
{
namespace localization
{
namespace odometry_node
{
class OdometryNode
{
    public:
        OdometryNode();
        ~OdometryNode();
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
        //ros::Subscriber odometry_imu_sub;

        // Kalman Filter Preparation
        // Odometry messages
        //nav_msgs::Odometry odometry_position_estimate;
        //geometry_msgs::PoseWithCovariance position_estimate;
        nav_msgs::Odometry full_odom_message;
        geometry_msgs::TwistWithCovariance velocity_estimate;
        //sensor_msgs::Imu imu_estimate
        //sensor_msgs::NavSatFix gps_position_estimate;
        // use the Tf_rotate for its custom message
        //interface::Tf_rotate tf_rotation;
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
        const long pulses_per_rotation = 2400;
        // pie
        const float PI = 3.14159;

        // odometry_state_estimation() variables for dead-reckoning
        float vel_magnitude = 0;
        float x_velocity = 0;
        float y_velocity = 0;
        // covariances 
        float x_vel_covariance = 0;
        float y_vel_covariance = 0;
        /*
        float x_position = 0;
        float y_position = 0;
        */
        float yaw_estimate = 0;
        float previous_yaw = 0;

        // initialize subscriber messages
        long left_odometry_msg = 0;
        long right_odometry_msg = 0;
        float steering_msg = 0;
        float yaw_msg = 0;
        
        // declare the callbacks
        void leftodometryCallback(const std_msgs::Int32& left_odometry_msg);
        void rightodometryCallback(const std_msgs::Int32& right_odometry_msg);
        void steeringCallback(const std_msgs::Float64& steering_msg);
        //void yawCallback(const std_msgs::Float64& imu_msg);
        void odometry_state_estimation();
        //void robot_localization_matrices();
        void timerCallback(const ros::TimerEvent& event);
        //void imuCallback(const sensor_msgs::Float64& imu_msg);

}; // OdometryNode
} // odometry_node
} // localization
} // fusionad
#endif
