#ifndef STANLEY_NODE_H
#define STANLEY_NODE_H

#include "ros/ros.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/TwistStamped.h"
#include "sensor_msgs/Imu.h"
#include <control/lat_controller.h>
#include <vector>
#include <interface/Controlcmd.h>
#include <interface/Chassis_state.h>
#include "Eigen/Dense"
#include <string>
#include "tf/tf.h"
#include <algorithm>


namespace fusionad
{
namespace control
{
namespace node
{
class control_node
{
  public:
    control_node();
    ~control_node();
    void initRosComm();
    bool getParameter();
    bool goalReached;    
    bool debug;
    
  private:
    fusionad::control::lat_controller::stanley lat_control;
    ros::NodeHandle control_nh;
    ros::Publisher control_main_pub;
    ros::Subscriber path_sub;
    ros::Subscriber localization_sub;
    ros::Subscriber imu_sub;
    typedef Eigen::Matrix<double, 4, 2> pathMatrix42d; 
    Eigen::Vector2d position;
    double roll, pitch, yaw, controlGain, linear_velocity;
    int targetPointIndex;
    double least_distance;
    //TODO: Safety Mechanism bool
    //bool isWorking;

    //Variable Definition
    std::vector<double> pathPointListX;
    std::vector<double> pathPointListY;
    std::vector<double>::size_type dynamicArraySize;

    void pathCallback(const nav_msgs::Path& trajectory_msg);
    void stateCallback(const interface::Chassis_state& veh_state_msg);
    void imuCallback(const sensor_msgs::Imu& inertial_msg);
    void masterTimerCallback(const ros::TimerEvent& controlTimeEvent);
    


};
}
}
}
#endif  