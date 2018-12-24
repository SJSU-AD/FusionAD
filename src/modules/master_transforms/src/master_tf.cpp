#include "master_tf.h"

/*
INPUTS: /localization/rotated_yaw
        /localization/calibrated_x_pose
        /localization/calibrated_y_pose

OUTPUTS: Geodesy TF Broadcast
         Lidar TF Broadcast
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
        rotated_yaw_sub = masterTfNode_nh.subscribe("/localization/rotated_yaw", 50, &MasterTfNode::rotatedYawCallback, this);
        calibrated_yaw_sub = masterTfNode_nh.subscribe("/localization/calibrated_yaw", 10, &MasterTfNode::yawCallback, this);
        // calibrated_pose_sub = masterTfNode_nh.subscribe("/localization/calibrated_pose", 10, &MasterTfNode::poseCallback, this);
    }

    void MasterTfNode::yawCallback(const std_msgs::Float32& cal_yaw_msg)
    {
        calibrated_yaw = cal_yaw_msg.data;
        calibration_complete = true;
    }

    // void MasterTfNode::poseCallback(const geometry_msgs::Point& cal_pose_msg)
    // {
    //     calibrated_x_pose = cal_pose_msg.x;
    //     calibrated_y_pose = cal_pose_msg.y;
    //     calibration_complete = true;
    // }

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

        // build the geodesy transform message and broadcast it
        geodesy_broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.8763*std::cos(rot_yaw), 0.8763*std::sin(rot_yaw), 0)),
                    ros::Time::now(),"odom", "gps"));

        // if the calibration has been completed, start creating the lidar tf2 message
        if (calibration_complete == true)
        {
            // initialize a quaternion message from roll pitch yaw 
            // (roll, pitch, yaw)
            tf::Quaternion lidar_quat_msg;
            lidar_quat_msg.setRPY(0, 0, calibrated_yaw);

            // build the lidar transform message and broadcast it 
            lidar_broadcaster.sendTransform(
                tf::StampedTransform(
                    tf::Transform(tf::Quaternion(lidar_quat_msg[0], lidar_quat_msg[1], lidar_quat_msg[2], lidar_quat_msg[3]), 
                        tf::Vector3(0.37465*std::cos(rot_yaw), 0.37465*std::sin(rot_yaw), 0)),
                            ros::Time::now(), "odom", "/camera_init"));
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
