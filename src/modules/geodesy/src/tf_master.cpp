#include "geodesy/tf_master.h"

namespace fusionad
{
namespace geodesy
{
namespace node
{
  tf_master_node::tf_master_node():
  imuInitialized(false)
  {
  }

  tf_master_node::~tf_master_node()
  {
  }

  void tf_master_node::initRosComm()
  {
    // tf Main publisher
    tf_master_main_pub = tf_master_nh.advertise<interface::Tf_rotate>("/geodesy/tf", 100);
    ROS_INFO_ONCE("tf Master Node Master Publisher Set!");

    // raw IMU data
    imu_sub = tf_master_nh.subscribe("/imu", 100, &tf_master_node::imuCallback, this);
    ROS_INFO_ONCE("tf Master Node IMU Subscriber Set!");
    ROS_INFO_ONCE("Waiting for IMU messages...");
  }

  void tf_master_node::imuCallback(const sensor_msgs::Imu& inertial_msg)
  {
    double roll = 0, pitch = 0 , yaw = 0;
    tf::Quaternion chassis_quaternion(inertial_msg.orientation.x,
                                      inertial_msg.orientation.y,
                                      inertial_msg.orientation.z,
                                      inertial_msg.orientation.w);
    tf::Matrix3x3 temp_rotation_matrix(chassis_quaternion);
    temp_rotation_matrix.getRPY(roll, pitch, yaw);

    tf_rotation.yaw = yaw;
    tf_master_main_pub.publish(tf_rotation);

    if(!imuInitialized)
    {
      imuInitialized = true;
      ROS_INFO_ONCE("IMU successfully initialized");
    }
  } 
} // node  
} // geodesy
} // fusionad

int main(int argc, char **argv)
{
  ros::init(argc, argv, "tf_master");
  fusionad::geodesy::node::tf_master_node tf_master;

  tf_master.initRosComm();
  while(ros::ok())
  {
    ros::spinOnce();
  }

  return 0;
}
