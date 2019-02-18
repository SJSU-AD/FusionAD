#include "localization/wheel_odom/odometry.h"

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

namespace fusionad
{
namespace localization
{
namespace wheel_odometry_node
{
    WheelOdometryNode::WheelOdometryNode()
    {}

    WheelOdometryNode::~WheelOdometryNode()
    {}

    void WheelOdometryNode::initRosComm()
    {
        // create a timer at 50 Hz
        odometry_timer = odometrynode_nh.createTimer(ros::Duration(0.02), &WheelOdometryNode::timerCallback, this);
       
        // main publisher for odometry
        odometry_pub = odometrynode_nh.advertise<nav_msgs::Odometry>("/localization/wheel_odom", 50);
        
        // subscribers for odometry
        left_encoder_sub = odometrynode_nh.subscribe("/localization/left_encoder_reading", 50, &WheelOdometryNode::leftEncoderCallback, this);
        right_encoder_sub = odometrynode_nh.subscribe("/localization/right_encoder_reading", 50, &WheelOdometryNode::rightEncoderCallback, this);
    }

    void WheelOdometryNode::leftEncoderCallback(const std_msgs::Int32& left_encoder_msg)
    {
        // encoder counts are from the Arduinos (Signwise Quadrature Encoder)
        left_angular_vel = ((2*M_PI*(left_encoder_msg.data-previous_left_encoder_msg))/(pulses_per_rotation*DT));
        previous_left_encoder_msg = left_encoder_msg.data;
    }

    void WheelOdometryNode::rightEncoderCallback(const std_msgs::Int32& right_encoder_msg)
    {
        // negative sign to account for the encoder difference
        right_angular_vel = ((2*M_PI*((-1)*right_encoder_msg.data-previous_right_encoder_msg))/(pulses_per_rotation*DT));
        previous_right_encoder_msg = (-1)*right_encoder_msg.data;
    }

    void WheelOdometryNode::wheel_odom_median_filter()
    {
        // function to perform median filtering to the velocity message data
        const int SAMPLE_SIZE = 10;

        vel_deque.push_back(vel_magnitude);
        if(vel_deque.size() >= SAMPLE_SIZE)
        {
            // start doing the median filtering

            float vel_array[SAMPLE_SIZE];

            for(int i = 0; i < SAMPLE_SIZE; i++)
            {
                vel_array[i] = vel_deque[i];
            }

            int n = sizeof(vel_array)/sizeof(vel_array[0]);
            std::sort(vel_array, vel_array+n);

            float median_vel = vel_array[SAMPLE_SIZE/2];

            vel_magnitude = median_vel;

            // pop the original queue
            vel_deque.pop_front();
        }
    }

    void WheelOdometryNode::odometry_state_estimation()
    {        
        // velocity magnitude estimate
        vel_magnitude = (left_angular_vel+right_angular_vel)*WHEEL_RADIUS/2; // [m/s]
        // calculating median of the velocities
        wheel_odom_median_filter();
        
        ////////////////////////
        // Velocity Estimate  //
        ///////////////////////
        
        velocity_estimate.twist.linear.x = vel_magnitude; // [m/s]
        
        // velocity variances from a straight-line test at constant velocity
        float x_vel_covariance = 0.0021878/2; // [m^2/s^2]

        velocity_estimate.covariance[0] = x_vel_covariance;
        // velocity_estimate.covariance[7] = y_vel_covariance;
    }

    void WheelOdometryNode::timerCallback(const ros::TimerEvent& event)
    {// publishes the wheel odometry message if the calibration was completed
        odometry_state_estimation();
        full_odom_message.twist = velocity_estimate;

        // declaring the header frame of the wheel_odom message
        full_odom_message.header.frame_id = "odom";
        full_odom_message.child_frame_id = "base_link";
        // timestamping the message
        full_odom_message.header.stamp = ros::Time::now();
        odometry_pub.publish(full_odom_message);
    }
    
} // wheel_odometry_node
} // localization
} // fusionad

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Odometry");
    fusionad::localization::wheel_odometry_node::WheelOdometryNode Odometry;

    Odometry.initRosComm();
    
    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}