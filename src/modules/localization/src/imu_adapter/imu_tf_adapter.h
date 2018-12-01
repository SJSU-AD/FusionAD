#ifndef IMU_TF_ADAPTER_H
#define IMU_TF_ADAPTER_H

#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32.h"
#include "math.h"
#include "Eigen/Dense"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "geometry_msgs/TwistWithCovariance.h"
#include "sensor_msgs/Imu.h"
#include <tf2/LinearMath/Quaternion.h>
#include "tf/tf.h"

namespace fusionad
{
namespace localization
{
namespace node
{
class ImuAdapterNode
{
    public:
        ImuAdapterNode();
        ~ImuAdapterNode();
        void initRosComm();

    private:
        // initialize the nodehandle
        ros::NodeHandle imuadapter_nh;

        // initialize timer
        ros::Timer imu_timer;
        // initialize publisher
        ros::Publisher imu_pub;
        ros::Publisher imu_yaw_pub;

        // initialize subscriber
        ros::Subscriber imu_sub;

        // initialize the imu message through sensor_msgs
        sensor_msgs::Imu imuMsg;
        sensor_msgs::Imu adaptMsg;

        // declare the callbacks
        void imuCallback(const sensor_msgs::Imu& imuMsg);
        void timerCallback(const ros::TimerEvent& event);
};
}//node
}//localization
}//fusionad
#endif