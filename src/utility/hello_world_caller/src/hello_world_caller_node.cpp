#include "hello_world_caller/hello_world_caller_node.h"

//Constructor
rosTutorialHWCaller::hello_world_caller::hello_world_caller():
hw_enabled(false),
publishIndex(0)
{
}

//Destructor
rosTutorialHWCaller::hello_world_caller::~hello_world_caller()
{
}

//Initialize ROS Communitcation
void rosTutorialHWCaller::hello_world_caller::initRosComm()
{
  helloworld_pub = hw_caller_nh.advertise<std_msgs::String>("/util/hwMsgs", 100);
  ROS_INFO("Hello World Publisher Has Been Set!");
  helloworld_sub = hw_caller_nh.subscribe("/util/toggleHW", 100, &rosTutorialHWCaller::hello_world_caller::hwTriggerCallback, this);
  ROS_INFO("Hello World Toggle Subscriber Has Been Set!");
}

//Hellow World Trigger Callback Function
void rosTutorialHWCaller::hello_world_caller::hwTriggerCallback(const std_msgs::Bool& hwTrigger_msg)
{
  //Store incoming ROS message data
  hw_enabled = hwTrigger_msg.data;
  if(hw_enabled)
  {
    //Publish the hello world message if the trigger has been enabled
    publishNewOutgoingMsg(publishIndex);
    publishIndex++;
  }
}

//Hello World String Publisher
void rosTutorialHWCaller::hello_world_caller::publishNewOutgoingMsg(const int& index)
{
  outgoing_ss << "Hello World! Count: " << index;
  outgoing_msg.data = outgoing_ss.str();
  helloworld_pub.publish(outgoing_msg);
  outgoing_ss.str("");
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "hello_world_caller_node");
  rosTutorialHWCaller::hello_world_caller hw_object;
  hw_object.initRosComm();
  while(ros::ok())
  {
    ros::spinOnce();
  }
  return 0;
}
