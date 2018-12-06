#include "localization/wheel_odom/odometry.h"

namespace fusionad
{
namespace localization
{
namespace wheel_odometry_node
{
    WheelOdometryNode::WheelOdometryNode()
    {
    }

    WheelOdometryNode::~WheelOdometryNode()
    {
    }

    void WheelOdometryNode::initRosComm()
    {
        // create a timer at 50 Hz
        odometry_timer = odometrynode_nh.createTimer(ros::Duration(0.02), &WheelOdometryNode::timerCallback, this);
        // main publisher for odometry
        odometry_pub = odometrynode_nh.advertise<nav_msgs::Odometry>("/localization/wheel_odom_twist", 50);
        // subscribers for odometry
        odometry_left_sub = odometrynode_nh.subscribe("/localization/left_encoder_reading", 50, &WheelOdometryNode::leftodometryCallback, this);
        odometry_right_sub = odometrynode_nh.subscribe("/localization/right_encoder_reading", 50, &WheelOdometryNode::rightodometryCallback, this);
        odometry_steering_sub = odometrynode_nh.subscribe("/control/steering_response", 50, &WheelOdometryNode::steeringCallback, this);
        odometry_imu_sub = odometrynode_nh.subscribe("/localization/rotated_yaw", 50, &WheelOdometryNode::imuCallback, this);
    }

    void WheelOdometryNode::leftodometryCallback(const std_msgs::Int32& left_odometry_msg)
    {
        // encoder counts are from the Arduinos (Signwise Quadrature Encoder)
        left_angular_vel = ((2*M_PI*(left_odometry_msg.data-previous_left_odometry_msg))/(pulses_per_rotation*DT));
        previous_left_odometry_msg = left_odometry_msg.data;
    }

    void WheelOdometryNode::rightodometryCallback(const std_msgs::Int32& right_odometry_msg)
    {
        // negative sign to account for the encoder difference
        right_angular_vel = ((2*M_PI*((-1)*right_odometry_msg.data-previous_right_odometry_msg))/(pulses_per_rotation*DT));
        previous_right_odometry_msg = (-1)*right_odometry_msg.data;
    }

    void WheelOdometryNode::steeringCallback(const std_msgs::Int16& steering_msg)
    {
        // steering angle from the linear actuator potentiometer connected to an Arduino
        double steering_analog_intercept = 322;
        double steering_analog_slope = 424.2424;
        steering_angle = (steering_msg.data-steering_analog_intercept)/steering_analog_slope;
    }

    void WheelOdometryNode::imuCallback(const std_msgs::Float32& yaw_msg)
    {
        // getting yaw estimate from the imu_tf_adapter node, which rotates the yaw to adhere to ROS standards
        if (yaw_msg_count <= yaw_msg_threshold)
        {
            ROS_INFO("Collecting Yaw Samples");
            yaw_msg_storage[yaw_msg_count] = yaw_msg.data;
            yaw_msg_count += 1;
            imu_calibration();
        }
    }

    void WheelOdometryNode::imu_calibration()
    {
        // function to calibrate the initialized yaw value
        // collects 100 samples of yaw messages and averages them
        // if the threshold (100 samples) is met, then calculate the average of the values
        if (yaw_msg_count == yaw_msg_threshold)
        {
            float yaw_msg_sum = 0;
            for (int n = 0; n < yaw_msg_threshold; n++)
            {
                yaw_msg_sum += yaw_msg_storage[n];
            }
            previous_yaw = yaw_msg_sum/yaw_msg_threshold;
            ROS_INFO("Yaw Calibration Completed!");
        }
    }

    //TODO: Possibly add position dead-reckoning from wheel odometry
    // void WheelOdometryNode::pose_calibration()
    // {
    //     // function to calibrate the initialized x and y pose
    //     // collects 100 samples of GPS messages and averages them
    //     // ikf the threshold (100 samples) is met, then calculate the average of the values
    // }

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
            
            //vel_magnitude = vel_array[SAMPLE_SIZE/2];
            
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
        // bicycle model dead-reckoning
        
        // velocity magnitude estimate
        vel_magnitude = (left_angular_vel+right_angular_vel)*WHEEL_RADIUS/2; // [m/s]
        // calculating median of the velocities
        wheel_odom_median_filter();
        
        // yaw estimate from odometry and steering
        yaw_estimate = previous_yaw + (vel_magnitude/WHEELBASE)*tan(steering_angle)*DT; // [rad]
        previous_yaw = yaw_estimate;
        
        // velocity estimate in x and y
        x_velocity = vel_magnitude * cos(yaw_estimate); // [m/s]
        y_velocity = vel_magnitude * sin(yaw_estimate); // [m/s]
        
        /*
        TODO: Possibly add position dead-reckoning from wheel odometry
        // position estimate in x and y
        x_position = previous_x_position + x_velocity*DT; // [m]
        y_position = previous_y_position + y_velocity*DT; // [m]

        // getting the previous x and y positions
        previous_x_position = x_position; // [m]
        previous_y_position = y_position; // [m]

        // position messages
        position_estimate.pose.pose.position.x = x_position;
        position_estimate.pose.pose.position.y = y_position;

        // position covariances
        float x_pose_covariance = 0; // [m^2]
        float y_pose_covariance = 0; // [m^2]

        position_estimate.covariance[0] = x_pose_covariance;
        position_estimate.covariance[7] = y_pose_covariance;
        */

        // twist messages
        velocity_estimate.twist.linear.x = x_velocity; // [m/s]
        velocity_estimate.twist.linear.y = y_velocity; // [m/s]
        
        // velocity covariances 
        float x_vel_covariance = 0.0021878/2; // [m^2/s^2]
        float y_vel_covariance = 0.0021878/2; // [m^2/s^2]

        velocity_estimate.covariance[0] = x_vel_covariance;
        velocity_estimate.covariance[7] = y_vel_covariance;
    }

    void WheelOdometryNode::timerCallback(const ros::TimerEvent& event)
    {
        odometry_state_estimation();
        full_odom_message.twist = velocity_estimate;

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
