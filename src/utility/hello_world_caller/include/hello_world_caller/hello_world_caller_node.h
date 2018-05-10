#ifndef HELLO_WORLD_CALLER_NODE_H
#define HELLO_WORLD_CALLER_NODE_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include <sstream>

namespace rosTutorialHWCaller
{
  class hello_world_caller
  {
    public:
      hello_world_caller();
      ~hello_world_caller();
      void initRosComm();

    private:
      ros::NodeHandle hw_caller_nh;
      ros::Publisher helloworld_pub;
      ros::Subscriber helloworld_sub;
      std_msgs::String outgoing_msg;
      std_msgs::Bool enable_hw_msg;
      std::stringstream outgoing_ss;

      bool hw_enabled;
      int publishIndex;

      void hwTriggerCallback(const std_msgs::Bool& hwTrigger_msg);
      void publishNewOutgoingMsg(const int& index);
  };
}

#endif //HELLO_WORLD_CALLER_NODE_H
