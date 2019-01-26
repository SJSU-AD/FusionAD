// Include all arduino headers
#include <Arduino.h>
#include <mcp_can.h>
#include <Timer.h>

// Include all ros headers
#include <ros.h>
#include <interface/Can_Interface.h>

// Declare can timer
Timer can_timer;

// Declare ros node handle
ros::NodeHandle can_nh;

// Declare the outgoing message
interface::Can_Interface received_can_message;

// Declare ros publisher and subscriber for relaying the CAN message
ros::Publisher can_relay_pub("/can_gateway/receive", &received_can_message);
ros::Subscriber<interface::Can_Interface> can_relay_sub("/can_gateway/send", &can_gateway_send_callback);

void setup() 
{
  can_timer.every(300, steering_health_callback)
}

void loop() 
{
  can_timer.update();

}

void steering_health_callback()
{

}

void can_gateway_send_callback()
{

}