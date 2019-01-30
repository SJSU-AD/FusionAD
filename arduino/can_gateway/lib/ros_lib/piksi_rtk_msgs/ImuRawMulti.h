#ifndef _ROS_piksi_rtk_msgs_ImuRawMulti_h
#define _ROS_piksi_rtk_msgs_ImuRawMulti_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class ImuRawMulti : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef uint8_t _tow_f_type;
      _tow_f_type tow_f;
      typedef int16_t _acc_x_type;
      _acc_x_type acc_x;
      typedef int16_t _acc_y_type;
      _acc_y_type acc_y;
      typedef int16_t _acc_z_type;
      _acc_z_type acc_z;
      typedef int16_t _gyr_x_type;
      _gyr_x_type gyr_x;
      typedef int16_t _gyr_y_type;
      _gyr_y_type gyr_y;
      typedef int16_t _gyr_z_type;
      _gyr_z_type gyr_z;

    ImuRawMulti():
      header(),
      tow(0),
      tow_f(0),
      acc_x(0),
      acc_y(0),
      acc_z(0),
      gyr_x(0),
      gyr_y(0),
      gyr_z(0)
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
      } u_acc_x;
      u_acc_x.real = this->acc_x;
      *(outbuffer + offset + 0) = (u_acc_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->acc_x);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_y;
      u_acc_y.real = this->acc_y;
      *(outbuffer + offset + 0) = (u_acc_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->acc_y);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_z;
      u_acc_z.real = this->acc_z;
      *(outbuffer + offset + 0) = (u_acc_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->acc_z);
      union {
        int16_t real;
        uint16_t base;
      } u_gyr_x;
      u_gyr_x.real = this->gyr_x;
      *(outbuffer + offset + 0) = (u_gyr_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyr_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyr_x);
      union {
        int16_t real;
        uint16_t base;
      } u_gyr_y;
      u_gyr_y.real = this->gyr_y;
      *(outbuffer + offset + 0) = (u_gyr_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyr_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyr_y);
      union {
        int16_t real;
        uint16_t base;
      } u_gyr_z;
      u_gyr_z.real = this->gyr_z;
      *(outbuffer + offset + 0) = (u_gyr_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyr_z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyr_z);
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
      } u_acc_x;
      u_acc_x.base = 0;
      u_acc_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->acc_x = u_acc_x.real;
      offset += sizeof(this->acc_x);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_y;
      u_acc_y.base = 0;
      u_acc_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->acc_y = u_acc_y.real;
      offset += sizeof(this->acc_y);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_z;
      u_acc_z.base = 0;
      u_acc_z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->acc_z = u_acc_z.real;
      offset += sizeof(this->acc_z);
      union {
        int16_t real;
        uint16_t base;
      } u_gyr_x;
      u_gyr_x.base = 0;
      u_gyr_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyr_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyr_x = u_gyr_x.real;
      offset += sizeof(this->gyr_x);
      union {
        int16_t real;
        uint16_t base;
      } u_gyr_y;
      u_gyr_y.base = 0;
      u_gyr_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyr_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyr_y = u_gyr_y.real;
      offset += sizeof(this->gyr_y);
      union {
        int16_t real;
        uint16_t base;
      } u_gyr_z;
      u_gyr_z.base = 0;
      u_gyr_z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyr_z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyr_z = u_gyr_z.real;
      offset += sizeof(this->gyr_z);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/ImuRawMulti"; };
    const char * getMD5(){ return "e32f07f6279690082bb3d37f42a5fc90"; };

  };

}
#endif