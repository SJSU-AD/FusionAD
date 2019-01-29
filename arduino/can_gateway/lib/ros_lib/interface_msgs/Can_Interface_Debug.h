#ifndef _ROS_interface_Can_Interface_Debug_h
#define _ROS_interface_Can_Interface_Debug_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace interface
{

  class Can_Interface_Debug : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _isCanBusInitialized_type;
      _isCanBusInitialized_type isCanBusInitialized;
      typedef bool _isGatewayInitialized_type;
      _isGatewayInitialized_type isGatewayInitialized;
      typedef bool _canMode_type;
      _canMode_type canMode;

    Can_Interface_Debug():
      header(),
      isCanBusInitialized(0),
      isGatewayInitialized(0),
      canMode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isCanBusInitialized;
      u_isCanBusInitialized.real = this->isCanBusInitialized;
      *(outbuffer + offset + 0) = (u_isCanBusInitialized.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isCanBusInitialized);
      union {
        bool real;
        uint8_t base;
      } u_isGatewayInitialized;
      u_isGatewayInitialized.real = this->isGatewayInitialized;
      *(outbuffer + offset + 0) = (u_isGatewayInitialized.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isGatewayInitialized);
      union {
        bool real;
        uint8_t base;
      } u_canMode;
      u_canMode.real = this->canMode;
      *(outbuffer + offset + 0) = (u_canMode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->canMode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isCanBusInitialized;
      u_isCanBusInitialized.base = 0;
      u_isCanBusInitialized.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isCanBusInitialized = u_isCanBusInitialized.real;
      offset += sizeof(this->isCanBusInitialized);
      union {
        bool real;
        uint8_t base;
      } u_isGatewayInitialized;
      u_isGatewayInitialized.base = 0;
      u_isGatewayInitialized.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isGatewayInitialized = u_isGatewayInitialized.real;
      offset += sizeof(this->isGatewayInitialized);
      union {
        bool real;
        uint8_t base;
      } u_canMode;
      u_canMode.base = 0;
      u_canMode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->canMode = u_canMode.real;
      offset += sizeof(this->canMode);
     return offset;
    }

    const char * getType(){ return "interface/Can_Interface_Debug"; };
    const char * getMD5(){ return "9d09d03cd3ea9b42a3c93b8ab7efd96a"; };

  };

}
#endif