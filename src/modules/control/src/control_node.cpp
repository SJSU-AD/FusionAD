#include "control/control_node.h"

namespace fusionad
{
namespace control
{
namespace node
{
  control_node::control_node()
  {
  }

  control_node::~control_node()
  {
  }

  void control_node::initRosComm()
  {
    control_main_pub = control_nh.advertise<interface::ControlCmd>("/control/controlcmd", 100);
    ROS_INFO("Control Node Master Publisher Set!");
    control_main_sub = control_nh.subscribe("/planning/trajectory", 100, &control_node::pathCallback, this);
    ROS_INFO("Control Node Path Subscriber Set!");
  }

}
}
}