#ifndef STANLEY_NODE_H
#define STANLEY_NODE_H

#include "ros/ros.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/TwistStamped.h"
#include <vector>
//#include "control/control_msg.h" Replace with new msg pkg

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
    
  private:
    ros::NodeHandle control_nh;
    ros::Publisher control_main_pub;
    ros::Subscirber control_main_sub;
    

    void pathCallback(const geometry_msgs::Path& trajectory_msg);
    //void publishControlCmd(const interface::ControlCmd& OutGoingMsg);

};
}
}
}
#endif  