#include "localization/frame_tf_calibrate/frame_calibration.h"
/*
TODO: Need to test the current logic
      Create static transform node (separate from this one) to broadcast transforms
      Change the frame ids
*/

/*
INPUTS: /gps/geodesy   <-- NOTE: will change to /gps/geodesy_odom later, just works with current bags
        /localization/rotated_yaw
        /localization/loam_odom_with_covar

        TF Listeners: Geodesy TF Message
                      Lidar TF Message

OUTPUTS: /localization/calibrated_x_pose
         /localization/calibrated_y_pose
         /localization/calibrated_yaw
         /localization/geodesy_tf
         /localization/lidar_tf
*/

namespace fusionad
{
namespace localization
{
namespace frame_calibration_node
{
    FrameCalibrationNode::FrameCalibrationNode(){}

    FrameCalibrationNode::~FrameCalibrationNode(){}

    void FrameCalibrationNode::initRosComm()
    {
        // publisher for gps position calibration
        calibrated_x_pose_pub = frameCalibrationNode_nh.advertise<std_msgs::Float32>("/localization/calibrated_x_pose", 10);
        calibrated_y_pose_pub = frameCalibrationNode_nh.advertise<std_msgs::Float32>("/localization/calibrated_y_pose", 10);
        
        // publisher for orientation calibration (yaw)
        calibrated_yaw_pub = frameCalibrationNode_nh.advertise<std_msgs::Float32>("/localization/calibrated_yaw", 10);

        // publisher for transformed messages
        geodesy_tf_pub = frameCalibrationNode_nh.advertise<nav_msgs::Odometry>("/localization/geodesy_tf", 10);
        //imu_tf_pub = frameCalibrationNode_nh.advertise<sensor_msgs::Imu>("/localization/imu_tf", 10);
        lidar_tf_pub = frameCalibrationNode_nh.advertise<nav_msgs::Odometry>("/localization/lidar_tf", 10);

        // subscriber for gps position calibration
        geodesy_sub = frameCalibrationNode_nh.subscribe("/gps/geodesy", 10, &FrameCalibrationNode::geodesyCallback, this);
       
        // subscriber for orientation calibration (yaw)
        yaw_sub = frameCalibrationNode_nh.subscribe("/localization/rotated_yaw", 50, &FrameCalibrationNode::yawCallback, this);

        // subscriber for lidar tf
        lidar_sub = frameCalibrationNode_nh.subscribe("/loam_odom_with_covar", 10, &FrameCalibrationNode::lidarCallback, this);
    }

    void FrameCalibrationNode::yawCallback(const std_msgs::Float32& yaw_msg)
    {
        //tf2_ros::TransformListener imu_listener(imu_buffer);

        // Perform while yaw is not calibrated
        if(!yaw_is_calibrated)
        {
            
            ROS_INFO_ONCE("Collecting Yaw Samples");

            // Accumulate samples
            yaw_accumulation += yaw_msg.data;

            // Increment sample counter
            yaw_samples_counter++;

            // Calculate average of samples once threshold is hit
            if(yaw_samples_counter >= MSG_THRESHOLD){

                // Store and calculate calibrated data
                std_msgs::Float32 calibrated_yaw;
                calibrated_yaw.data = yaw_accumulation / yaw_samples_counter;

                // Publish data to /localization/calibrated_yaw
                calibrated_yaw_pub.publish(calibrated_yaw);

                // Yaw is now callibrated
                ROS_INFO("Yaw Calibration Completed");
                yaw_is_calibrated = true;
            }
        }
    }

    void FrameCalibrationNode::geodesyCallback(const nav_msgs::Odometry& geodesy_msg)
    {
        //geodesy_buffer.transform()
        //tf2_ros::TransformListener geodesy_listener(geodesy_buffer);

        // covariance remains unchanged
        geodesy_tf_msg.pose.covariance[0] = geodesy_msg.pose.covariance[0];
        geodesy_tf_msg.pose.covariance[7] = geodesy_msg.pose.covariance[7];
        
        // creating a temporary geometry PoseStamped message to facilitate homogeneous transform
        geometry_msgs::PointStamped temp_geodesy_tf_point;
        temp_geodesy_tf_point.header.frame_id = "gps";
        temp_geodesy_tf_point.header.stamp = ros::Time();
        temp_geodesy_tf_point.point.x = geodesy_msg.pose.pose.position.x;
        temp_geodesy_tf_point.point.y = geodesy_msg.pose.pose.position.y;

        try
        {
        // creating a pointstamped message to place the results into
        geometry_msgs::PointStamped geodesy_tf_point;

        geodesy_listener.transformPoint("odom", temp_geodesy_tf_point, geodesy_tf_point);
        
        // stuff the message into the geodesy_tf_msg for publishing
        geodesy_tf_msg.pose.pose.position.x = geodesy_tf_point.point.x;
        geodesy_tf_msg.pose.pose.position.y = geodesy_tf_point.point.y;
        geodesy_tf_msg.header.frame_id = geodesy_tf_point.header.frame_id;
        geodesy_tf_msg.header.stamp = ros::Time();

        geodesy_tf_pub.publish(geodesy_tf_msg);

        ROS_INFO("gps: (%.2f, %.2f) -----> odom: (%.2f, %.2f) at time %.2f",
        temp_geodesy_tf_point.point.x, temp_geodesy_tf_point.point.y,
        geodesy_tf_point.point.x, geodesy_tf_point.point.y, geodesy_tf_point.header.stamp.toSec());
        }
        catch(tf::TransformException& geodesy_exception)
        {
            ROS_ERROR("Received an exception when trying to transform a point from \"gps\" to \"odom\": %s",
            geodesy_exception.what());
        }

        // Perform while geodesy is not calibrated
        if(!geodesy_is_calibrated)
        {
            ROS_INFO_ONCE("Collecting Geodesy Samples");

            // Collect x sample and add to previous samples
            geodesy_x_accumulation += geodesy_tf_msg.pose.pose.position.x;

            // Collect y sample and add to previous samples
            geodesy_y_accumulation += geodesy_tf_msg.pose.pose.position.y;

            // Increment geodesy samples counter
            geodesy_samples_counter++;

            // Calculate average of samples once threshold is hit
            if(geodesy_samples_counter >= MSG_THRESHOLD){
                
                // Declare floats to store averaged data
                std_msgs::Float32 geodesy_calibrated_x;
                std_msgs::Float32 geodesy_calibrated_y;

                // Take average of x and y position samples
                geodesy_calibrated_x.data = geodesy_x_accumulation / geodesy_samples_counter;
                geodesy_calibrated_y.data = geodesy_y_accumulation / geodesy_samples_counter;

                // Publish averaged samples
                calibrated_x_pose_pub.publish(geodesy_calibrated_x);
                calibrated_y_pose_pub.publish(geodesy_calibrated_y);

                // Calibration is complete
                ROS_INFO("Geodesy Position Calibration Completed");
                geodesy_is_calibrated = true;
            }
        }        
    }

    void FrameCalibrationNode::lidarCallback(const nav_msgs::Odometry& lidar_msg)
    {
        //tf2_ros::TransformListener lidar_listener(lidar_buffer);
        geometry_msgs::PointStamped lidar_tf_point;

        lidar_tf_msg.pose.covariance[0] = lidar_msg.pose.covariance[0];
        lidar_tf_msg.pose.covariance[7] = lidar_msg.pose.covariance[7];

        // creating a temporary geometry PoseStamped message to facilitate homogeneous transform
        geometry_msgs::PointStamped temp_lidar_tf_point;
        temp_lidar_tf_point.header.frame_id = "lidar_link";
        temp_lidar_tf_point.header.stamp = ros::Time();
        temp_lidar_tf_point.point.x = lidar_msg.pose.pose.position.x;
        temp_lidar_tf_point.point.y = lidar_msg.pose.pose.position.y;

        try
        {
        // creating a pointstamped message to place the results into
        geometry_msgs::PointStamped lidar_tf_point;

        lidar_listener.transformPoint("odom", temp_lidar_tf_point, lidar_tf_point);
        
        // stuff the message into the lidar_tf_msg for publishing
        lidar_tf_msg.pose.pose.position.x = lidar_tf_point.point.x;
        lidar_tf_msg.pose.pose.position.y = lidar_tf_point.point.y;
        lidar_tf_msg.header.frame_id = lidar_tf_point.header.frame_id;
        lidar_tf_msg.header.stamp = ros::Time();

        lidar_tf_pub.publish(lidar_tf_msg);

        ROS_INFO("gps: (%.2f, %.2f) -----> odom: (%.2f, %.2f) at time %.2f",
        temp_lidar_tf_point.point.x, temp_lidar_tf_point.point.y,
        lidar_tf_point.point.x, lidar_tf_point.point.y, lidar_tf_point.header.stamp.toSec());
        }
        catch(tf::TransformException& lidar_exception)
        {
            ROS_ERROR("Received an exception when trying to transform a point from \"gps\" to \"odom\": %s",
            lidar_exception.what());
        }
    }
}// frame_calibration_node
}// localization
}// fusionad

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Frame_Calibration");
    fusionad::localization::frame_calibration_node::FrameCalibrationNode Frame_Calibration;

    Frame_Calibration.initRosComm();

    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}