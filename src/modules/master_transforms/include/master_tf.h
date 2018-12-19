#ifndef MASTER_TF_H
#define MASTER_TF_H

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Bool.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf/transform_broadcaster.h"
#include "tf2/LinearMath/Quaternion.h"

namespace fusionad
{
namespace master_tf
{
namespace master_tf_node
{
class MasterTfNode
{
    public:
        MasterTfNode();
        ~MasterTfNode();
        void initRosComm();
    
    private:
        // initializing the nodehandle
        ros::NodeHandle masterTfNode_nh;

        // initialize the timer
        ros::Timer master_tf_timer;

        // initialize the subscribers
        ros::Subscriber calibrated_x_sub;
        ros::Subscriber calibrated_y_sub;
        ros::Subscriber calibrated_yaw_sub;
        ros::Subscriber uncalibrated_yaw_sub;

        // tf2_ros::TransformBroadcaster gps_tf_broadcaster;
        // tf2_ros::TransformBroadcaster imu_tf_broadcaster;
        // tf2_ros::TransformBroadcaster lidar_tf_broadcaster;

        // geometry_msgs::TransformStamped gps_tf;
        // geometry_msgs::TransformStamped imu_tf;
        // geometry_msgs::TransformStamped lidar_tf;
        
        tf::TransformBroadcaster geodesy_broadcaster;
        tf::TransformBroadcaster lidar_broadcaster;

        float calibrated_x_pose;
        float calibrated_y_pose;
        float calibrated_yaw;
        float rot_yaw;
        bool calibration_complete = false;

        // initialize callback functions for calibrated messages from the frame_calibration node
        void xPoseCallback(const std_msgs::Float32& cal_x_msg);
        void yPoseCallback(const std_msgs::Float32& cal_y_msg);
        void yawCallback(const std_msgs::Float32& cal_yaw_msg);
        void rotatedYawCallback(const std_msgs::Float32& rot_yaw_msg);
        void timerCallback(const ros::TimerEvent& event);

}; // MasterTfNode
} // master_tf_node
} // master_tf
} // fusionad

#endif
