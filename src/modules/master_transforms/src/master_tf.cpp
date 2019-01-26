#include "master_tf.h"

/*
NOTE: This node prepares the tf message to broadcast by using the input of the rotated yaw message
      (according to REP-105) and performing the 2D rotation required from sensor location to front-axle. 
      Only the x-position is offset (with respect to the vehicle on the red car) so there is no y-position component in the 
      2-D transform. 

NOTE: Lidar tf logic has been commented out until the loam_velodyne odometry has been verified to be accurate
      Calibration logic has also been commented out for the same reason ^^^^^

Subscribers
----------------------------------------
Topic:  /localization/rotated_imu
            Msg: sensor_msgs::Imu
Topic:  /localization/calibration
            Msg: geometry_msgs::Pose

Publisher
---------------------------------------
Geodesy TF Broadcast
Lidar TF Broadcast
*/

namespace fusionad
{
namespace master_tf
{
namespace master_tf_node
{
    MasterTfNode::MasterTfNode()
    {}

    MasterTfNode::~MasterTfNode()
    {}

    void MasterTfNode::initRosComm()
    {
        // initializing the timer
        master_tf_timer = masterTfNode_nh.createTimer(ros::Duration(0.02), &MasterTfNode::timerCallback, this);

        // initializing the subscribers
        imu_sub = masterTfNode_nh.subscribe("/localization/rotated_imu", 50, &MasterTfNode::imuCallback, this);
        // calibrated_sub = masterTfNode_nh.subscribe("/localization/calibrated_yaw", 10, &MasterTfNode::calibrationCallback, this);
    }

    void MasterTfNode::imuCallback(const sensor_msgs::Imu& imu_msg)
    {
        double roll = 0, pitch = 0, yaw = 0;

        tf::Quaternion imu_quaternion(imu_msg.orientation.x,
                                      imu_msg.orientation.y,
                                      imu_msg.orientation.z,
                                      imu_msg.orientation.w);
        tf::Matrix3x3 temporary_rot_matrix(imu_quaternion);
        temporary_rot_matrix.getRPY(roll, pitch, yaw);
        rot_yaw = yaw;
    }

    // void MasterTfNode::calibrationCallback(const geometry_msgs::Pose& pose_msg)
    // {
    //     double roll = 0, pitch = 0, yaw = 0;

    //     tf::Quaternion imu_quaternion(pose_msg.orientation.x,
    //                                   pose_msg.orientation.y,
    //                                   pose_msg.orientation.z,
    //                                   pose_msg.orientation.w);
    //     tf::Matrix3x3 temporary_rot_matrix(imu_quaternion);
    //     temporary_rot_matrix.getRPY(roll, pitch, yaw);
    //     calibrated_yaw = yaw
    // }

    void MasterTfNode::timerCallback(const ros::TimerEvent& event)
    {
        /*
        Red Car Sensor Locations
        the sensors are not offset in the y-axis of the vehicle base_link

        GPS to front axle: -34.5" = -0.8763 [m]
        Lidar to front axle: -14.75" = -0.37465 [m]
        IMU to front axle: 5" = 0.127 [m]
        Wheelbase: -27.5" = -0.6985 [m]
        */

        /*
        Black Car Sensor Locations

        GPS to front axle:
            x-position = 1.47955 [m]
            y-position = 0 [m]

        Lidar to front axle
            x-position = 
            y-position = 
        */
        float x_position_rot = 1.47955;
        float y_position_rot = 0;

        geodesy_broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(x_position_rot*std::cos(rot_yaw) - y_position_rot*std::sin(rot_yaw), 
                    x_position_rot*std::sin(rot_yaw) + y_position_rot*std::cos(rot_yaw), 0)),
                        ros::Time::now(),"odom", "gps"));

        // // if the calibration has been completed, start creating the lidar tf2 message
        // if (calibration_complete)
        // {
        //     // initialize a quaternion message from roll pitch yaw 
        //     // (roll, pitch, yaw)
        //     tf::Quaternion lidar_quat_msg;
        //     lidar_quat_msg.setRPY(0, 0, calibrated_yaw);

        //     // build the lidar transform message and broadcast it 
        //     lidar_broadcaster.sendTransform(
        //         tf::StampedTransform(
        //             tf::Transform(tf::Quaternion(lidar_quat_msg[0], lidar_quat_msg[1], lidar_quat_msg[2], lidar_quat_msg[3]), 
        //                 tf::Vector3(0.37465*std::cos(rot_yaw), 0.37465*std::sin(rot_yaw), 0)),
        //                     ros::Time::now(), "odom", "/camera_init"));
        // }
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
