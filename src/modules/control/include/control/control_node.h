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
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/convert.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>


namespace fusionad
{
namespace control
{
namespace node
{
class ControlNode
{
  public:
    ControlNode();
    ~ControlNode();
    void initRosComm();
    bool getParameter();
    bool goalReached, debug, externalFailFlag;
    
  private:
    // ROS Node, publishers, and subscribers
    ros::NodeHandle control_nh;
    ros::Publisher control_main_pub;
    ros::Publisher control_debug_pub;
    ros::Subscriber path_sub;
    ros::Subscriber localization_sub;
    ros::Subscriber obstacle_sub;
    ros::Subscriber mode_sub;

    // System flags and triggers
    bool pathInitialized, stateInitialized, internalFailFlag;
    bool autonomousDrivingFlag, obstacleDetected;

    // Declare control gain variable
    float controlGain_p, controlGain_d;
    
    // Vehicle State Variables
    typedef Eigen::Matrix<float, 4, 2> pathMatrix42f; 
    Eigen::Vector2f position;    
    double roll, pitch, yaw;    
    float linear_velocity, vehicle_heading;
    
    // Waypoint Selection variables
    int targetPointIndex;
    
    // Control Timer and timer variables
    ros::Timer control_cmd_timer;
    const float control_loop_rate = 25;                 // Hertz
    float control_loop_time = 1/control_loop_rate;

    // Lateral controller objects
    fusionad::control::lat_controller::Stanley lat_control{control_loop_time};

    //TODO: Safety Mechanism bool
    //bool isWorking;

    //Path Variables
    std::vector<float> pathPointListX;
    std::vector<float> pathPointListY;
    std::vector<float>::size_type dynamicArraySize;

    int getTargetWaypoint(const interface::Chassis_state& current_position);

    void pathCallback(const nav_msgs::Path& trajectory_msg);
    void stateCallback(const interface::Chassis_state& veh_state_msg);
    void obstacleCallback(const std_msgs::Bool& obstacleDetection_msg);
    void modeCallback(const std_msgs::Bool& autonomous_mode_msg);
    void masterTimerCallback(const ros::TimerEvent& controlTimeEvent);
    
};
}
}
}
#endif  