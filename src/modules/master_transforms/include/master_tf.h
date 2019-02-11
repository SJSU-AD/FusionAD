#ifndef MASTER_TF_H
#define MASTER_TF_H

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

#include "ros/ros.h"
#include "math.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Bool.h"
#include "geometry_msgs/Pose.h"
#include "sensor_msgs/Imu.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf/transform_broadcaster.h"

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
        ros::Subscriber imu_sub;
        // ros::Subscriber calibration_sub;
        
        tf::TransformBroadcaster geodesy_broadcaster;
        tf::TransformBroadcaster lidar_broadcaster;
        tf::TransformBroadcaster map_to_odom;

        float calibrated_yaw = 0;
        float rot_yaw = 0;
        bool calibration_complete = false;

        // initialize callback functions for calibrated messages from the frame_calibration node
        void ekfCallback(const nav_msgs::Odometry& ekf_msg);
        // void calibrationCallback(const geometry_msgs::Pose& pose_msg);
        void timerCallback(const ros::TimerEvent& event);

}; // MasterTfNode
} // master_tf_node
} // master_tf
} // fusionad

#endif
