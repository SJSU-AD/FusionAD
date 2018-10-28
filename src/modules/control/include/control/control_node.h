#ifndef STANLEY_NODE_H
#define STANLEY_NODE_H

#include "ros/ros.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/TwistStamped.h"
#include "sensor_msgs/Imu.h"
#include <control/lat_controller.h>
#include "std_msgs/Bool.h"
#include <vector>
#include <interface/Controlcmd.h>
#include <interface/Chassis_state.h>
#include "Eigen/Dense"
#include <cmath>
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
    bool goalReached, debug, externalFailFlag;
    
  private:
    fusionad::control::lat_controller::stanley lat_control;
    ros::NodeHandle control_nh;
    ros::Publisher control_main_pub;
    ros::Publisher control_debug_pub;
    ros::Subscriber path_sub;
    ros::Subscriber localization_sub;
    ros::Subscriber imu_sub;
    ros::Subscriber obstacle_sub;
    ros::Subscriber mode_sub;
    typedef Eigen::Matrix<float, 4, 2> pathMatrix42f; 
    Eigen::Vector2f position;
    bool pathInitialized, stateInitialized, imuInitialized, internalFailFlag;
    bool autonomousDrivingFlag, obstacleDetected;
    double roll, pitch, yaw;
    float controlGain, linear_velocity, vehicle_heading;
    int targetPointIndex;
    ros::Timer control_cmd_timer;

    const float magnetic_declination_rad = M_PI_2;

    //Heading Estimator
    /*
    float prev_pos[2] = {0, 0};
    Eigen::Vector2f orientation_pos_vector;
    float estimated_orientation;
    */

    //TODO: Safety Mechanism bool
    //bool isWorking;

    //Variable Definition
    std::vector<float> pathPointListX;
    std::vector<float> pathPointListY;
    std::vector<float>::size_type dynamicArraySize;

    void pathCallback(const nav_msgs::Path& trajectory_msg);
    void stateCallback(const interface::Chassis_state& veh_state_msg);
    void imuCallback(const sensor_msgs::Imu& inertial_msg);
    void obstacleCallback(const std_msgs::Bool& obstacleDetection_msg);
    void modeCallback(const std_msgs::Bool& autonomous_mode_msg);
    void masterTimerCallback(const ros::TimerEvent& controlTimeEvent);
    
};
}
}
}
#endif  