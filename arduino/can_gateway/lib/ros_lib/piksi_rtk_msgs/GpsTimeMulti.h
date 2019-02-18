#ifndef _ROS_piksi_rtk_msgs_GpsTimeMulti_h
#define _ROS_piksi_rtk_msgs_GpsTimeMulti_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class GpsTimeMulti : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _wn_type;
      _wn_type wn;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef int32_t _ns_residual_type;
      _ns_residual_type ns_residual;
      typedef uint8_t _flags_type;
      _flags_type flags;

    GpsTimeMulti():
      header(),
      wn(0),
      tow(0),
      ns_residual(0),
      flags(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->wn >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wn >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wn >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wn >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wn);
      *(outbuffer + offset + 0) = (this->tow >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tow >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tow >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tow >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tow);
      union {
        int32_t real;
        uint32_t base;
      } u_ns_residual;
      u_ns_residual.real = this->ns_residual;
      *(outbuffer + offset + 0) = (u_ns_residual.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ns_residual.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ns_residual.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ns_residual.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ns_residual);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flags);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->wn =  ((uint32_t) (*(inbuffer + offset)));
      this->wn |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->wn |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->wn |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->wn);
      this->tow =  ((uint32_t) (*(inbuffer + offset)));
      this->tow |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tow |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tow |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tow);
      union {
        int32_t real;
        uint32_t base;
      } u_ns_residual;
      u_ns_residual.base = 0;
      u_ns_residual.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ns_residual.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ns_residual.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ns_residual.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ns_residual = u_ns_residual.real;
      offset += sizeof(this->ns_residual);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/GpsTimeMulti"; };
    const char * getMD5(){ return "c23173761fc276afe3f4db2728518721"; };

  };

}
#endif