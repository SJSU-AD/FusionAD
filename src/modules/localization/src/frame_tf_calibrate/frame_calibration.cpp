#include "localization/frame_tf_calibrate/frame_calibration.h"
/*
NOTE: This node listens to the tf broadcasts and performs the homogeneous transforms.
      Another major function of this node is to "calibrate" the initial position and orientation
      of the vehicle. The homogeneous transforms are applied and then the result is published.
      Also contains logic to filter out GPS points that are outside of a certain threshold which is
      calculated by taking the distance between each GPS point. 

NOTE: The covariance in the eth-zurich swift package provides a filtered gps signal and a non-filtered gps signal.
      A covariance of 1 [m^2] is typically done with their "single point estimation" and a covariance of 0.0049 and 
      25 [m^2] has been filtered. Because the 1 [m^2] covariance is typically noisy due to the lack of filtering and the 
      25 [m^2] covariance is filtered and smooth, the two covariances are swapped. This allows the EKF to take in the 
      previously 25 [m^2] measurements and apply a larger Kalman Gain (trusting this measurement more). 

Subscribers
--------------------------------------------------
Topic:  /gps/geodesy_odom
            Msg: nav_msgs::Odometry
Topic:  /imu
            Msg: sensor_msgs::Imu
Topic:  /localization/loam_odom_with_covar
            Msg: nav_msgs::Odometry

TF Listeners: Geodesy TF Message
              Lidar TF Message

Publishers
-------------------------------------------------
Topic: /localization/calibration
            Msg: geometry_msgs::Pose
Topic: /localization/rotated_imu
            Msg: sensor_msgs::Imu
Topic: /localization/geodesy_tf
            Msg: nav_msgs::Odometry
Topic: /localization/lidar_tf
            Msg: nav_msgs::Odometry
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
        // publisher for gps position and orientation calibration
        calibrated_pose_pub = frameCalibrationNode_nh.advertise<geometry_msgs::Pose>("/localization/calibration", 10);

        // publishers for transformed messages
        geodesy_tf_pub = frameCalibrationNode_nh.advertise<nav_msgs::Odometry>("/localization/geodesy_tf", 10);
        lidar_tf_pub = frameCalibrationNode_nh.advertise<nav_msgs::Odometry>("/localization/lidar_tf", 10);
        imu_tf_pub = frameCalibrationNode_nh.advertise<sensor_msgs::Imu>("/localization/rotated_imu", 50);

        // subscriber for gps position calibration
        geodesy_sub = frameCalibrationNode_nh.subscribe("/gps/geodesy_odom", 10, &FrameCalibrationNode::geodesyCallback, this);
       
        // subscriber for orientation calibration (yaw)
        imu_sub = frameCalibrationNode_nh.subscribe("/imu", 50, &FrameCalibrationNode::yawCallback, this);

        // subscriber for lidar tf
        lidar_sub = frameCalibrationNode_nh.subscribe("/loam_odom_with_covar", 10, &FrameCalibrationNode::lidarCallback, this);
    }

    void FrameCalibrationNode::yawCallback(const sensor_msgs::Imu& imu_msg)
    {
        double roll = 0, pitch = 0, yaw = 0, vehicle_heading = 0;
        const float imu_residual_offset = -0.3567612546;
        const float yaw_offset = M_PI_2;

        rot_msg = imu_msg;

        // rename the imu frame to base_link, which is much more common within ROS
        rot_msg.header.frame_id = "base_link";

        tf::Quaternion imu_quaternion(imu_msg.orientation.x,
                                      imu_msg.orientation.y,
                                      imu_msg.orientation.z,
                                      imu_msg.orientation.w);
        tf::Matrix3x3 temporary_rot_matrix(imu_quaternion);
        temporary_rot_matrix.getRPY(roll, pitch, yaw);

        float adjusted_yaw = yaw + yaw_offset + imu_residual_offset;

        if(adjusted_yaw > M_PI)
        {
            vehicle_heading = adjusted_yaw - 2*M_PI;
        }
        else if(adjusted_yaw < (-1)*M_PI)
        {
            vehicle_heading = (2*M_PI) + adjusted_yaw;
        }
        else
        {
            vehicle_heading = adjusted_yaw;
        }

        tf::Quaternion new_imu_quaternion = tf::createQuaternionFromRPY(roll, pitch, vehicle_heading);

        rot_msg.orientation.x = new_imu_quaternion[0];
        rot_msg.orientation.y = new_imu_quaternion[1];
        rot_msg.orientation.z = new_imu_quaternion[2];
        rot_msg.orientation.w = new_imu_quaternion[3];

        imu_tf_pub.publish(rot_msg);

        // perform while yaw is not calibrated
        if(!yaw_is_calibrated)
        {
            
            ROS_INFO_ONCE("Collecting Yaw Samples");

            // accumulate samples
            yaw_accumulation += vehicle_heading;

            // increment sample counter
            yaw_samples_counter++;

            // calculate average of samples once threshold is hit
            if(yaw_samples_counter >= MSG_THRESHOLD)
            {
                // store and calculate calibrated data
                calibrated_yaw = yaw_accumulation / yaw_samples_counter;

                // yaw is now calibrated
                ROS_INFO("Yaw Calibration Completed");
                yaw_is_calibrated = true;
            }
        }
    }

    void FrameCalibrationNode::geodesyCallback(const nav_msgs::Odometry& geodesy_msg)
    {
        /*
        NOTE: The covariance in the eth-zurich swift package provides a filtered gps signal and a non-filtered gps signal.
        A covariance of 1 [m^2] is typically done with their "single point estimation" and a covariance of 0.0049 and 
        25 [m^2] has been filtered. Because the 1 [m^2] covariance is typically noisy due to the lack of filtering and the 
        25 [m^2] covariance is filtered and smooth, the two covariances are swapped. This allows the EKF to take in the 
        previously 25 [m^2] measurements and apply a larger Kalman Gain (trusting this measurement more). 
        */

        if (geodesy_msg.pose.covariance[0] == 1)
        {
            geodesy_tf_msg.pose.covariance[0] = 25;
            geodesy_tf_msg.pose.covariance[7] = 25;
        }
        else if (geodesy_msg.pose.covariance[0] == 25)
        {
            geodesy_tf_msg.pose.covariance[0] = 1;
            geodesy_tf_msg.pose.covariance[7] = 1;
        }
        else
        {
            geodesy_tf_msg.pose.covariance[0] = geodesy_msg.pose.covariance[0];
            geodesy_tf_msg.pose.covariance[7] = geodesy_msg.pose.covariance[7];
        }
        
        // creating a temporary geometry PoseStamped message to facilitate homogeneous transform
        geometry_msgs::PointStamped temp_geodesy_tf_point;
        temp_geodesy_tf_point.header.frame_id = "gps";
        temp_geodesy_tf_point.header.stamp = ros::Time();
        temp_geodesy_tf_point.point.x = geodesy_msg.pose.pose.position.x;
        temp_geodesy_tf_point.point.y = geodesy_msg.pose.pose.position.y;

        // threshold standard deviation for publishing geodesy 
        float threshold_pose_std_dev;
        frameCalibrationNode_nh.getParam("/frame_calibration/threshold_pose_std_dev", threshold_pose_std_dev);
        
        if(std::sqrt(geodesy_tf_msg.pose.covariance[0]) <= threshold_pose_std_dev)
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
                // geodesy_tf_msg.child_frame_id = temp_geodesy_tf_point.header.frame_id;
                geodesy_tf_msg.header.stamp = ros::Time::now();
                
                if(!first_message_sent)
                {
                    geodesy_tf_pub.publish(geodesy_tf_msg);
                    first_message_sent = true;    
                }
                else
                {
                    // calculate the euclidian distance between point (n) and point (n-1)
                    float distance_comparison;
                    float gps_threshold;

                    frameCalibrationNode_nh.getParam("/frame_calibration/gps_threshold", gps_threshold);
                    distance_comparison = std::sqrt(std::pow(geodesy_tf_msg.pose.pose.position.x - previous_geodesy_tf_msg.pose.pose.position.x, 2) + std::pow(geodesy_tf_msg.pose.pose.position.y - previous_geodesy_tf_msg.pose.pose.position.y, 2));
                    
                    // if the distance between point (n) and point (n-1) is less than the threshold, then publish the gps msg
                    if(std::abs(distance_comparison) <= gps_threshold)
                    {
                        geodesy_tf_pub.publish(geodesy_tf_msg);
                    }
                }

                ROS_INFO("gps: (%.2f, %.2f) -----> odom: (%.2f, %.2f) at time %.2f",
                temp_geodesy_tf_point.point.x, temp_geodesy_tf_point.point.y,
                geodesy_tf_point.point.x, geodesy_tf_point.point.y, geodesy_tf_point.header.stamp.toSec());
                
                // store previous messages for distance calculation
                previous_geodesy_tf_msg.pose.pose.position.x = geodesy_tf_msg.pose.pose.position.x;
                previous_geodesy_tf_msg.pose.pose.position.y = geodesy_tf_msg.pose.pose.position.y;
            }
            catch(tf::TransformException& geodesy_exception)
            {
                ROS_ERROR("Received an exception when trying to transform a point from \"gps\" to \"odom\": %s",
                geodesy_exception.what());
            }

            // perform while geodesy is not calibrated
            if(!geodesy_is_calibrated)
            {
                ROS_INFO_ONCE("Collecting Geodesy Samples");

                // collect x sample and add to previous samples
                geodesy_x_accumulation += geodesy_tf_msg.pose.pose.position.x;

                // collect y sample and add to previous samples
                geodesy_y_accumulation += geodesy_tf_msg.pose.pose.position.y;

                // increment geodesy samples counter
                geodesy_samples_counter++;

                // calculate average of samples once threshold is hit
                if(geodesy_samples_counter >= MSG_THRESHOLD)
                {    
                    // initialize a Pose message to store averaged data
                    geometry_msgs::Pose pose_calibrated;

                    // take average of x and y position samples
                    pose_calibrated.position.x = geodesy_x_accumulation / geodesy_samples_counter;
                    pose_calibrated.position.y = geodesy_y_accumulation / geodesy_samples_counter;

                    pose_calibrated.orientation.x = rot_msg.orientation.x;
                    pose_calibrated.orientation.y = rot_msg.orientation.y;
                    pose_calibrated.orientation.z = rot_msg.orientation.z;
                    pose_calibrated.orientation.w = rot_msg.orientation.w;

                    // publish averaged samples
                    calibrated_pose_pub.publish(pose_calibrated);
                    
                    // calibration is complete
                    geodesy_calibrated_x_value = pose_calibrated.position.x;
                    geodesy_calibrated_y_value = pose_calibrated.position.y;
                    ROS_INFO("Geodesy Position Calibration Completed");
                    geodesy_is_calibrated = true;
                }
            }  
        }      
    }

    void FrameCalibrationNode::lidarCallback(const nav_msgs::Odometry& lidar_msg)
    {
        if(geodesy_is_calibrated && yaw_is_calibrated)
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