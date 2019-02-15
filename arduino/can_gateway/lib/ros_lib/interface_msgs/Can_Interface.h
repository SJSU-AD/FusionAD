#ifndef _ROS_interface_Can_Interface_h
#define _ROS_interface_Can_Interface_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace interface
{

  class Can_Interface : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint8_t steering_can_data[8];
      uint8_t propulsion_can_data[8];
      typedef bool _hold_steering_position_type;
      _hold_steering_position_type hold_steering_position;

    Can_Interface():
      header(),
      steering_can_data(),
      propulsion_can_data(),
      hold_steering_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 8; i++){
      *(outbuffer + offset + 0) = (this->steering_can_data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steering_can_data[i]);
      }
      for( uint32_t i = 0; i < 8; i++){
      *(outbuffer + offset + 0) = (this->propulsion_can_data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->propulsion_can_data[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_hold_steering_position;
      u_hold_steering_position.real = this->hold_steering_position;
      *(outbuffer + offset + 0) = (u_hold_steering_position.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hold_steering_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 8; i++){
      this->steering_can_data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->steering_can_data[i]);
      }
      for( uint32_t i = 0; i < 8; i++){
      this->propulsion_can_data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->propulsion_can_data[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_hold_steering_position;
      u_hold_steering_position.base = 0;
      u_hold_steering_position.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hold_steering_position = u_hold_steering_position.real;
      offset += sizeof(this->hold_steering_position);
     return offset;
    }

    const char * getType(){ return "interface/Can_Interface"; };
    const char * getMD5(){ return "bbef8b8f29fffda27ca4b5edaaf2fafb"; };

  };

}
#endif