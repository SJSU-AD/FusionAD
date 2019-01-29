#ifndef _ROS_piksi_rtk_msgs_MagRaw_h
#define _ROS_piksi_rtk_msgs_MagRaw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class MagRaw : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef uint8_t _tow_f_type;
      _tow_f_type tow_f;
      typedef int16_t _mag_x_type;
      _mag_x_type mag_x;
      typedef int16_t _mag_y_type;
      _mag_y_type mag_y;
      typedef int16_t _mag_z_type;
      _mag_z_type mag_z;

    MagRaw():
      header(),
      tow(0),
      tow_f(0),
      mag_x(0),
      mag_y(0),
      mag_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->tow >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tow >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tow >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tow >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tow);
      *(outbuffer + offset + 0) = (this->tow_f >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tow_f);
      union {
        int16_t real;
        uint16_t base;
      } u_mag_x;
      u_mag_x.real = this->mag_x;
      *(outbuffer + offset + 0) = (u_mag_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mag_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mag_x);
      union {
        int16_t real;
        uint16_t base;
      } u_mag_y;
      u_mag_y.real = this->mag_y;
      *(outbuffer + offset + 0) = (u_mag_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mag_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mag_y);
      union {
        int16_t real;
        uint16_t base;
      } u_mag_z;
      u_mag_z.real = this->mag_z;
      *(outbuffer + offset + 0) = (u_mag_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mag_z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mag_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->tow =  ((uint32_t) (*(inbuffer + offset)));
      this->tow |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tow |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tow |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tow);
      this->tow_f =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->tow_f);
      union {
        int16_t real;
        uint16_t base;
      } u_mag_x;
      u_mag_x.base = 0;
      u_mag_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mag_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mag_x = u_mag_x.real;
      offset += sizeof(this->mag_x);
      union {
        int16_t real;
        uint16_t base;
      } u_mag_y;
      u_mag_y.base = 0;
      u_mag_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mag_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mag_y = u_mag_y.real;
      offset += sizeof(this->mag_y);
      union {
        int16_t real;
        uint16_t base;
      } u_mag_z;
      u_mag_z.base = 0;
      u_mag_z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mag_z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mag_z = u_mag_z.real;
      offset += sizeof(this->mag_z);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/MagRaw"; };
    const char * getMD5(){ return "79dfa3690a8019ef8383e9c5637520d8"; };

  };

}
#endif