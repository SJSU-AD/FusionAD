#include "localization/frame_tf_calibrate/frame_calibration.h"
/*
TODO: Need to monitor geodesy covariances
*/

/*
INPUTS: /gps/geodesy_odom
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
        calibrated_pose_pub = frameCalibrationNode_nh.advertise<geometry_msgs::Point>("/localization/calibrated_pose", 10);

        // publisher for orientation calibration (yaw)
        calibrated_yaw_pub = frameCalibrationNode_nh.advertise<std_msgs::Float32>("/localization/calibrated_yaw", 10);

        // publisher for transformed messages
        geodesy_tf_pub = frameCalibrationNode_nh.advertise<nav_msgs::Odometry>("/localization/geodesy_tf", 10);
        lidar_tf_pub = frameCalibrationNode_nh.advertise<nav_msgs::Odometry>("/localization/lidar_tf", 10);

        // subscriber for gps position calibration
        geodesy_sub = frameCalibrationNode_nh.subscribe("/gps/geodesy_odom", 10, &FrameCalibrationNode::geodesyCallback, this);
       
        // subscriber for orientation calibration (yaw)
        yaw_sub = frameCalibrationNode_nh.subscribe("/localization/rotated_yaw", 50, &FrameCalibrationNode::yawCallback, this);

        // subscriber for lidar tf
        lidar_sub = frameCalibrationNode_nh.subscribe("/loam_odom_with_covar", 10, &FrameCalibrationNode::lidarCallback, this);
    }

    void FrameCalibrationNode::yawCallback(const std_msgs::Float32& yaw_msg)
    {
        // Perform while yaw is not calibrated
        if(!yaw_is_calibrated)
        {
            
            ROS_INFO_ONCE("Collecting Yaw Samples");

            // Accumulate samples
            yaw_accumulation += yaw_msg.data;

            // Increment sample counter
            yaw_samples_counter++;

            // Calculate average of samples once threshold is hit
            if(yaw_samples_counter >= MSG_THRESHOLD)
            {

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
        // covariance remains unchanged
        geodesy_tf_msg.pose.covariance[0] = geodesy_msg.pose.covariance[0];
        geodesy_tf_msg.pose.covariance[7] = geodesy_msg.pose.covariance[7];
        
        // creating a temporary geometry PoseStamped message to facilitate homogeneous transform
        geometry_msgs::PointStamped temp_geodesy_tf_point;
        temp_geodesy_tf_point.header.frame_id = "gps";
        temp_geodesy_tf_point.header.stamp = ros::Time();
        temp_geodesy_tf_point.point.x = geodesy_msg.pose.pose.position.x;
        temp_geodesy_tf_point.point.y = geodesy_msg.pose.pose.position.y;

        // threshold standard deviation for publishing geodesy 
        float THRESHOLD_POSE_STD_DEV = 0.15; // [m]

        if(std::sqrt(geodesy_tf_msg.pose.covariance[0]) <= THRESHOLD_POSE_STD_DEV)
        {
            try
            {
                // creating a pointstamped message to place the results into
                geometry_msgs::PointStamped geodesy_tf_point;

                geodesy_listener.transformPoint("odom", temp_geodesy_tf_point, geodesy_tf_point);
                
                // stuff the message into the geodesy_tf_msg for publishing
                geodesy_tf_msg.pose.pose.position.x = geodesy_tf_point.point.x;
                geodesy_tf_msg.pose.pose.position.y = geodesy_tf_point.point.y;
                geodesy_tf_msg.header.frame_id = geodesy_tf_point.header.frame_id;
                geodesy_tf_msg.header.stamp = ros::Time::now();

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
                if(geodesy_samples_counter >= MSG_THRESHOLD)
                {    
                    // Declare floats to store averaged data
                    geometry_msgs::Point geodesy_pose_calibrated;

                    // Take average of x and y position samples
                    geodesy_pose_calibrated.x = geodesy_x_accumulation / geodesy_samples_counter;
                    geodesy_pose_calibrated.y = geodesy_y_accumulation / geodesy_samples_counter;

                    // Publish averaged samples
                    calibrated_pose_pub.publish(geodesy_pose_calibrated);
                    // Calibration is complete
                    geodesy_calibrated_x_value = geodesy_pose_calibrated.x;
                    geodesy_calibrated_y_value = geodesy_pose_calibrated.y;
                    ROS_INFO("Geodesy Position Calibration Completed");
                    geodesy_is_calibrated = true;
                }
            }  
        }      
    }

    void FrameCalibrationNode::lidarCallback(const nav_msgs::Odometry& lidar_msg)
    {
        if(geodesy_is_calibrated)
        {
            geometry_msgs::PointStamped lidar_tf_point;

            lidar_tf_msg.pose.covariance[0] = lidar_msg.pose.covariance[0];
            lidar_tf_msg.pose.covariance[7] = lidar_msg.pose.covariance[7];

            // creating a temporary geometry PoseStamped message to facilitate homogeneous transform
            geometry_msgs::PointStamped temp_lidar_tf_point;
            temp_lidar_tf_point.header.frame_id = "/camera_init";
            temp_lidar_tf_point.header.stamp = ros::Time();

            // manually doing the rotation (loam reads in ZX-plane and we want XY-plane)
            temp_lidar_tf_point.point.x = lidar_msg.pose.pose.position.z;
            temp_lidar_tf_point.point.y = (-1)*lidar_msg.pose.pose.position.x;

            try
            {
                // creating a pointstamped message to place the results into
                geometry_msgs::PointStamped lidar_tf_point;

                lidar_listener.transformPoint("odom", temp_lidar_tf_point, lidar_tf_point);
                
                // stuff the message into the lidar_tf_msg for publishing
                lidar_tf_msg.pose.pose.position.x = lidar_tf_point.point.x + geodesy_calibrated_x_value;
                lidar_tf_msg.pose.pose.position.y = lidar_tf_point.point.y + geodesy_calibrated_y_value;
                lidar_tf_msg.header.frame_id = lidar_tf_point.header.frame_id;
                lidar_tf_msg.header.stamp = ros::Time::now();

                lidar_tf_pub.publish(lidar_tf_msg);

                ROS_INFO("/camera_init: (%.2f, %.2f) -----> odom: (%.2f, %.2f) at time %.2f",
                temp_lidar_tf_point.point.x, temp_lidar_tf_point.point.y,
                lidar_tf_point.point.x, lidar_tf_point.point.y, lidar_tf_point.header.stamp.toSec());
            }
            catch(tf::TransformException& lidar_exception)
            {
                ROS_ERROR("Received an exception when trying to transform a point from \"/camera_init\" to \"odom\": %s",
                lidar_exception.what());
            }
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