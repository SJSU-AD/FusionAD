#ifndef _ROS_piksi_rtk_msgs_BaselineNed_h
#define _ROS_piksi_rtk_msgs_BaselineNed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class BaselineNed : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef int32_t _n_type;
      _n_type n;
      typedef int32_t _e_type;
      _e_type e;
      typedef int32_t _d_type;
      _d_type d;
      typedef uint16_t _h_accuracy_type;
      _h_accuracy_type h_accuracy;
      typedef uint16_t _v_accuracy_type;
      _v_accuracy_type v_accuracy;
      typedef uint8_t _n_sats_type;
      _n_sats_type n_sats;
      typedef uint8_t _flags_type;
      _flags_type flags;

    BaselineNed():
      header(),
      tow(0),
      n(0),
      e(0),
      d(0),
      h_accuracy(0),
      v_accuracy(0),
      n_sats(0),
      flags(0)
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
      union {
        int32_t real;
        uint32_t base;
      } u_n;
      u_n.real = this->n;
      *(outbuffer + offset + 0) = (u_n.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_n.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_n.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_n.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->n);
      union {
        int32_t real;
        uint32_t base;
      } u_e;
      u_e.real = this->e;
      *(outbuffer + offset + 0) = (u_e.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_e.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_e.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_e.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->e);
      union {
        int32_t real;
        uint32_t base;
      } u_d;
      u_d.real = this->d;
      *(outbuffer + offset + 0) = (u_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_d.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_d.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_d.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d);
      *(outbuffer + offset + 0) = (this->h_accuracy >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->h_accuracy >> (8 * 1)) & 0xFF;
      offset += sizeof(this->h_accuracy);
      *(outbuffer + offset + 0) = (this->v_accuracy >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->v_accuracy >> (8 * 1)) & 0xFF;
      offset += sizeof(this->v_accuracy);
      *(outbuffer + offset + 0) = (this->n_sats >> (8 * 0)) & 0xFF;
      offset += sizeof(this->n_sats);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flags);
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
      union {
        int32_t real;
        uint32_t base;
      } u_n;
      u_n.base = 0;
      u_n.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_n.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_n.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_n.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->n = u_n.real;
      offset += sizeof(this->n);
      union {
        int32_t real;
        uint32_t base;
      } u_e;
      u_e.base = 0;
      u_e.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_e.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_e.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_e.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->e = u_e.real;
      offset += sizeof(this->e);
      union {
        int32_t real;
        uint32_t base;
      } u_d;
      u_d.base = 0;
      u_d.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_d.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_d.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_d.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->d = u_d.real;
      offset += sizeof(this->d);
      this->h_accuracy =  ((uint16_t) (*(inbuffer + offset)));
      this->h_accuracy |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->h_accuracy);
      this->v_accuracy =  ((uint16_t) (*(inbuffer + offset)));
      this->v_accuracy |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->v_accuracy);
      this->n_sats =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->n_sats);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/BaselineNed"; };
    const char * getMD5(){ return "d181eb2c9a6abff7c97c58dc9f4c0a7f"; };

  };

}
#endif