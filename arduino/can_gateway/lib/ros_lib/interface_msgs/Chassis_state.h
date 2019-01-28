#ifndef _ROS_interface_Chassis_state_h
#define _ROS_interface_Chassis_state_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/TwistStamped.h"

namespace interface
{

  class Chassis_state : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _debugLocalization_type;
      _debugLocalization_type debugLocalization;
      typedef bool _inAutonomousMode_type;
      _inAutonomousMode_type inAutonomousMode;
      typedef geometry_msgs::PoseStamped _Position_type;
      _Position_type Position;
      typedef geometry_msgs::TwistStamped _Speed_type;
      _Speed_type Speed;

    Chassis_state():
      header(),
      debugLocalization(0),
      inAutonomousMode(0),
      Position(),
      Speed()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_debugLocalization;
      u_debugLocalization.real = this->debugLocalization;
      *(outbuffer + offset + 0) = (u_debugLocalization.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->debugLocalization);
      union {
        bool real;
        uint8_t base;
      } u_inAutonomousMode;
      u_inAutonomousMode.real = this->inAutonomousMode;
      *(outbuffer + offset + 0) = (u_inAutonomousMode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->inAutonomousMode);
      offset += this->Position.serialize(outbuffer + offset);
      offset += this->Speed.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_debugLocalization;
      u_debugLocalization.base = 0;
      u_debugLocalization.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->debugLocalization = u_debugLocalization.real;
      offset += sizeof(this->debugLocalization);
      union {
        bool real;
        uint8_t base;
      } u_inAutonomousMode;
      u_inAutonomousMode.base = 0;
      u_inAutonomousMode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->inAutonomousMode = u_inAutonomousMode.real;
      offset += sizeof(this->inAutonomousMode);
      offset += this->Position.deserialize(inbuffer + offset);
      offset += this->Speed.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "interface/Chassis_state"; };
    const char * getMD5(){ return "a8389b53fd684d1763eb31c37f9fa8ad"; };

  };

}
#endif