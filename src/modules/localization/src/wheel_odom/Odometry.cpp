#include "Odometry.h"
// TODO: Add odomReadMe.md
//       Need to initialize yaw values from the TF_master node
//       as the initial value of yaw_estimate
//       incorporate counter for getting IMU values for initializing yaw estimate
namespace fusionad
{
namespace localization
{
namespace odometry_node
{
    OdometryNode::OdometryNode()
    {
    }

    OdometryNode::~OdometryNode()
    {
    }

    void OdometryNode::initRosComm()
    {
        // create a timer at 50 Hz
        odometry_timer = odometrynode_nh.createTimer(ros::Duration(0.02), &OdometryNode::timerCallback, this);
        // main publisher for odometry
        odometry_pub = odometrynode_nh.advertise<nav_msgs::Odometry>("/localization/twist", 50);
        // subscribers for odometry
        odometry_left_sub = odometrynode_nh.subscribe("/localization/left_encoder_reading", 50, &OdometryNode::leftodometryCallback, this);
        odometry_right_sub = odometrynode_nh.subscribe("/localization/right_encoder_reading", 50, &OdometryNode::rightodometryCallback, this);
        odometry_steering_sub = odometrynode_nh.subscribe("/control/steering_response", 50, &OdometryNode::steeringCallback, this);
        //odometry_imu_sub = odometrynode_nh.subscribe("/geodesy/tf", 50, &OdometryNode::);
    }

    void OdometryNode::leftodometryCallback(const std_msgs::Int32& left_odometry_msg)
    {
        left_angular_vel = ((2*M_PI*(left_odometry_msg.data-previous_left_odometry_msg))/(pulses_per_rotation*DT));
        previous_left_odometry_msg = left_odometry_msg.data;
    }

    void OdometryNode::rightodometryCallback(const std_msgs::Int32& right_odometry_msg)
    {
        right_angular_vel = ((2*M_PI*((-1)*right_odometry_msg.data-previous_right_odometry_msg))/(pulses_per_rotation*DT));
        previous_right_odometry_msg = (-1)*right_odometry_msg.data;
    }

    void OdometryNode::steeringCallback(const std_msgs::Float64& steering_msg)
    {
        double steering_analog_intercept = 322;
        double steering_analog_slope = 424.2424;
        steering_angle = (steering_msg.data-steering_analog_intercept)/steering_analog_slope;
    }

    void OdometryNode::odometry_state_estimation()
    {
        //TODO: Need to change how deque is grabbing values
        // bicycle model dead-reckoning
        
        // velocity magnitude estimate
        vel_magnitude = (left_angular_vel+right_angular_vel)*WHEEL_RADIUS;

        std::deque<float> vel_deque;
        // moving median of SAMPLE_SIZE samples
        const int SAMPLE_SIZE = 10;

        vel_deque.push_back(vel_magnitude);
        if(vel_deque.size() >= SAMPLE_SIZE)
        {
            // start doing the moving median filtering
            //std::queue<float> temp_vel_queue(vel_queue);
            float vel_array[SAMPLE_SIZE];

            for(int i = 0; SAMPLE_SIZE-1; ++i)
            {
                vel_array[i] = vel_deque[i];
            }

            int n = sizeof(vel_array)/sizeof(vel_array[0]);
            std::sort(vel_array, vel_array+n);
            vel_magnitude = vel_array[SAMPLE_SIZE/2];

            // pop the original queue
            vel_deque.pop_front();
            vel_deque.pop_back();
            vel_deque.push_back(vel_magnitude);
        }

        // yaw estimate from odometry and steering
        yaw_estimate = previous_yaw + (vel_magnitude/WHEELBASE)*tan(steering_angle)*DT;
        previous_yaw = yaw_estimate;

        // velocity estimate in x and y
        x_velocity = vel_magnitude * cos(yaw_estimate);
        y_velocity = vel_magnitude * sin(yaw_estimate);
        
        // twist messages
        velocity_estimate.twist.linear.x = x_velocity;
        velocity_estimate.twist.linear.y = y_velocity;
        //velocity_estimate.linear.z = 0;
        // covariances 
        float x_vel_covariance = 0.0021878;
        float y_vel_covariance = 0.0021878;

        velocity_estimate.covariance[0] = x_vel_covariance;
        velocity_estimate.covariance[7] = y_vel_covariance;
    }

    void OdometryNode::timerCallback(const ros::TimerEvent& event)
    {
        odometry_state_estimation();
        full_odom_message.twist = velocity_estimate;
        odometry_pub.publish(full_odom_message);
    }
    
} // odometry_node
} // localization
} // fusionad

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Odometry");
    fusionad::localization::odometry_node::OdometryNode Odometry;

    Odometry.initRosComm();
    
    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}