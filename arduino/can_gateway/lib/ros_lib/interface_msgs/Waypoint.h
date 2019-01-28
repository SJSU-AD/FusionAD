#ifndef _ROS_interface_Waypoint_h
#define _ROS_interface_Waypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Twist.h"

namespace interface
{

  class Waypoint : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef geometry_msgs::Twist _velocity_type;
      _velocity_type velocity;

    Waypoint():
      header(),
      pose(),
      velocity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "interface/Waypoint"; };
    const char * getMD5(){ return "8f34bc4c8885bf4335f77287c96fe295"; };

  };

}
#endif