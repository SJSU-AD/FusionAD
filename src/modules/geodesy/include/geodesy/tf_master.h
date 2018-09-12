#ifndef TF_MASTER_H
#define TF_MASTER_H

#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include "geometry_msgs/TwistStamped.h"
#include "std_msgs/Bool.h"
#include "interface/Tf_rotate.h"
#include "tf/tf.h"
#include "Eigen/Dense"
#include <cmath>
#include <string>
#include <algorithm>

namespace fusionad
{
namespace geodesy
{
namespace node
{
class tf_master_node
{
  public:
    tf_master_node();
    ~tf_master_node();
    void initRosComm();
    bool getParameter();
  
  private:
    ros::NodeHandle tf_master_nh;
    ros::Publisher tf_master_main_pub;
    ros::Subscriber imu_sub;
    interface::Tf_rotate tf_rotation;

    bool imuInitialized;

    void imuCallback(const sensor_msgs::Imu& inertial_msg);
};
} // node
} // geodesy
} // fusionad
#endif