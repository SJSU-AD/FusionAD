#include "master_tf.h"

/*
TODO: figure out whether we should use tf library or tf2 library
*/
namespace fusionad
{
namespace master_tf
{
namespace master_tf_node
{
    MasterTfNode::MasterTfNode()
    {
    }

    MasterTfNode::~MasterTfNode()
    {
    }

    void MasterTfNode::initRosComm()
    {
        // initializing the timer
        master_tf_timer = masterTfNode_nh.createTimer(ros::Duration(0.02), &MasterTfNode::timerCallback, this);

        // initializing the subscribers
        uncalibrated_yaw_sub = masterTfNode_nh.subscribe("/localization/rotated_yaw", 50, &MasterTfNode::rotatedYawCallback, this);
        calibrated_x_sub = masterTfNode_nh.subscribe("/localization/calibrated_x_pose", 10, &MasterTfNode::xPoseCallback, this);
        calibrated_y_sub = masterTfNode_nh.subscribe("/localization/calibrated_y_pose", 10, &MasterTfNode::yPoseCallback, this);
        calibrated_yaw_sub = masterTfNode_nh.subscribe("/localization/calibrated_yaw", 10, &MasterTfNode::yawCallback, this);
    }

    void MasterTfNode::xPoseCallback(const std_msgs::Float32& cal_x_msg)
    {
        // if the callback has been triggered (calibration has been completed), make the bool true
        calibrated_x_pose = cal_x_msg.data;
        calibration_complete = true;
    }

    void MasterTfNode::yPoseCallback(const std_msgs::Float32& cal_y_msg)
    {
        calibrated_y_pose = cal_y_msg.data;
    }

    void MasterTfNode::yawCallback(const std_msgs::Float32& cal_yaw_msg)
    {
        calibrated_yaw = cal_yaw_msg.data;
    }

    void MasterTfNode::rotatedYawCallback(const std_msgs::Float32& rot_yaw_msg)
    {
        rot_yaw = rot_yaw_msg.data;
    }

    void MasterTfNode::timerCallback(const ros::TimerEvent& event)
    {
        /*
        GPS to front axle: -34.5" = -0.8763 [m]
        Lidar to front axle: -14.75" = -0.37465 [m]
        IMU to front axle: 5" = 0.127 [m]
        Wheelbase: -27.5" = -0.6985 [m]
        */

        /*
        // set up the tf2 message for gps according to dimensions above
        gps_tf.header.stamp = ros::Time::now();
        gps_tf.header.frame_id = "odom";
        gps_tf.child_frame_id = "gps_link";
        gps_tf.transform.translation.x = -0.8763;
        
        // broadcast the gps tf2 message
        gps_tf_broadcaster.sendTransform(gps_tf);
        
        tf::TransformBroadcaster geodesy_broadcaster;
        */

        // tf::Quaternion geodesy_quat_msg;
        // geodesy_quat_msg.setRPY(0, 0, rot_yaw);

        // Assembling and broadcasting the geodesy_broadcaster message 
        // geodesy_broadcaster.sendTransform(
        //     tf::StampedTransform(
        //         tf::Transform(tf::Quaternion(geodesy_quat_msg[0], geodesy_quat_msg[1], geodesy_quat_msg[2], geodesy_quat_msg[3]), tf::Vector3(0.8763, 0.0, 0)),
        //             ros::Time::now(),"odom", "gps"));

        geodesy_broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.8763*std::cos(rot_yaw), 0.8763*std::sin(rot_yaw), 0)),
                    ros::Time::now(),"odom", "gps"));

        // TODO: Figure out a way to do the linear transformation for IMU
        // // set up the tf2 message for imu according to dimensions above
        // imu_tf.header.stamp = ros::Time::now();
        // imu_tf.header.frame_id = "base_link";
        // imu_tf.child_frame_id = "base_imu_link";
        // imu_tf.transform.translation.x = 0.127;

        // // broadcast the imu tf2 message 
        // imu_tf_broadcaster.sendTransform(imu_tf);

        // if the calibration has been completed, start creating the lidar tf2 message
        if (calibration_complete == true)
        {
            /*
            lidar_tf.header.stamp = ros::Time::now();
            lidar_tf.header.frame_id = "odom";
            lidar_tf.child_frame_id = "base_lidar_link";
            lidar_tf.transform.translation.x = -0.37465;
            tf2::Quaternion lidar_quat;
            // (roll, pitch, yaw)
            lidar_quat.setRPY(0, 0, calibrated_yaw);
            lidar_tf.transform.rotation.x = lidar_quat[0];
            lidar_tf.transform.rotation.y = lidar_quat[1];
            lidar_tf.transform.rotation.z = lidar_quat[2];
            lidar_tf.transform.rotation.z = lidar_quat[3];

            // broadcast the lidar tf2 message
            lidar_tf_broadcaster.sendTransform(lidar_tf);
            */
            

            // (roll, pitch, yaw)
            tf::Quaternion lidar_quat_msg;
            lidar_quat_msg.setRPY(0, 0, calibrated_yaw);
            
            lidar_broadcaster.sendTransform(
                tf::StampedTransform(
                    tf::Transform(tf::Quaternion(lidar_quat_msg[0], lidar_quat_msg[1], lidar_quat_msg[2], lidar_quat_msg[3]), 
                        tf::Vector3(0.37465*std::cos(rot_yaw), 0.37465*std::sin(rot_yaw), 0)),
                            ros::Time::now(), "odom", "/camera_init"));
            // lidar_broadcaster.sendTransform(
            //     tf::StampedTransform(
            //         tf::Transform(tf::Quaternion(0,0,0,1), tf::Vector3(0.37465, 0.0, 0)),
            //             ros::Time::now(),"odom", "/camera_init"));
        }
    }
}
}
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Master_Tf");
    fusionad::master_tf::master_tf_node::MasterTfNode Master_Tf;

    Master_Tf.initRosComm();
    
    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}
