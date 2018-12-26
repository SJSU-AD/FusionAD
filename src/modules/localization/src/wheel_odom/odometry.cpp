#include "localization/wheel_odom/odometry.h"

//NOTE: Currently commented out calibration phase of the odometry node

/*
Takes wheel odometry from Arduino encoders and translates to vehicle velocity and position
NOTE: This script is to handle the raw wheel odometry values from the Signwise 600 P/R rotary encoder.
      It also takes in various inputs from topics yaw from the IMU to dead-reckon position and velocity in the X and Y frame.
      Dead-reckoning requires previous pose to be tracked, we take advantage of this by subscribing to
      the output of the EKF and using those pose messages as the previous pose of the wheel odometry.

SUBSCRIBERS:  
-------------------------------------------
TOPIC:  /localization/right_encoder_reading
            Msg: std_msgs::Int16
TOPIC:  /localization/left_encoder_reading
            Msg: std_msgs::Int16
TOPIC:  /localization/odometry/filtered
            Msg: nav_msgs::Odometry
TOPIC:  /localization/rotated_imu
            Msg: sensor_msgs::Imu

PUBLISHER:
-------------------------------------------  
TOPIC:  /localization/wheel_odom
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
        imu_sub = odometrynode_nh.subscribe("/localization/rotated_imu", 50, &WheelOdometryNode::imuCallback, this);
        ekf_odom_sub = odometrynode_nh.subscribe("/odometry/filtered", 50, &WheelOdometryNode::ekfCallback, this);
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

    void WheelOdometryNode::ekfCallback(const nav_msgs::Odometry& ekf_odom_msg)
    {
        previous_x_position = ekf_odom_msg.pose.pose.position.x;
        previous_y_position = ekf_odom_msg.pose.pose.position.y;
    }

    void WheelOdometryNode::imuCallback(const sensor_msgs::Imu& yaw_msg)
    {
        double roll = 0, pitch = 0, yaw = 0;

        tf::Quaternion imu_quaternion(yaw_msg.orientation.x,
                                      yaw_msg.orientation.y,
                                      yaw_msg.orientation.z,
                                      yaw_msg.orientation.w);
        tf::Matrix3x3 temporary_rot_matrix(imu_quaternion);
        temporary_rot_matrix.getRPY(roll, pitch, yaw);
        yaw_estimate = yaw;
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
            // NOTE: moving median logic
            // vel_deque.pop_back();
            // vel_deque.push_back(vel_magnitude);
            // 
        }
    }

    void WheelOdometryNode::odometry_state_estimation()
    {        
        // velocity magnitude estimate
        vel_magnitude = (left_angular_vel+right_angular_vel)*WHEEL_RADIUS/2; // [m/s]
        // calculating median of the velocities
        wheel_odom_median_filter();
        
        ////////////////////////
        // VELOCITY ESTIMATE //
        ///////////////////////

        // yaw estimate from odometry and steering
        // yaw_estimate = previous_yaw + (vel_magnitude/WHEELBASE)*tan(steering_angle)*DT; // [rad]
        // previous_yaw = yaw_estimate;
        
        // velocity estimate in x and y
        x_velocity = vel_magnitude * cos(yaw_estimate); // [m/s]
        y_velocity = vel_magnitude * sin(yaw_estimate); // [m/s]

        // twist messages
        velocity_estimate.twist.linear.x = x_velocity; // [m/s]
        velocity_estimate.twist.linear.y = y_velocity; // [m/s]
        
        // velocity variances from a straight-line test at constant velocity
        float x_vel_covariance = 0.0021878/2; // [m^2/s^2]
        float y_vel_covariance = 0.0021878/2; // [m^2/s^2]

        velocity_estimate.covariance[0] = x_vel_covariance;
        velocity_estimate.covariance[7] = y_vel_covariance;
        
        ///////////////////////
        // POSITION ESTIMATE //
        ///////////////////////

        // position estimate in x and y
        x_position = previous_x_position + x_velocity*DT; // [m]
        y_position = previous_y_position + y_velocity*DT; // [m]

        // getting the previous x and y positions
        previous_x_position = x_position; // [m]
        previous_y_position = y_position; // [m]

        // position messages
        position_estimate.pose.position.x = x_position;
        position_estimate.pose.position.y = y_position;

        // position covariances from a straight-line test at constant velocity
        float x_pose_covariance = 0.0021878/2; // [m^2]
        float y_pose_covariance = 0.0021878/2; // [m^2]

        position_estimate.covariance[0] = x_pose_covariance;
        position_estimate.covariance[7] = y_pose_covariance;
    
    }

    void WheelOdometryNode::timerCallback(const ros::TimerEvent& event)
    {// publishes the wheel odometry message if the calibration was completed
        odometry_state_estimation();
        full_odom_message.twist = velocity_estimate;
        full_odom_message.pose = position_estimate;

        // declaring the header frame of the wheel_odom message
        full_odom_message.header.frame_id = "odom";
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
