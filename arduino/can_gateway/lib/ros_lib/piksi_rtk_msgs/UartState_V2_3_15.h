#ifndef _ROS_piksi_rtk_msgs_UartState_V2_3_15_h
#define _ROS_piksi_rtk_msgs_UartState_V2_3_15_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class UartState_V2_3_15 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _latency_avg_type;
      _latency_avg_type latency_avg;
      typedef int32_t _latency_lmin_type;
      _latency_lmin_type latency_lmin;
      typedef int32_t _latency_lmax_type;
      _latency_lmax_type latency_lmax;
      typedef int32_t _latency_current_type;
      _latency_current_type latency_current;
      typedef int32_t _obs_period_avg_type;
      _obs_period_avg_type obs_period_avg;
      typedef int32_t _obs_period_pmin_type;
      _obs_period_pmin_type obs_period_pmin;
      typedef int32_t _obs_period_pmax_type;
      _obs_period_pmax_type obs_period_pmax;
      typedef int32_t _obs_period_current_type;
      _obs_period_current_type obs_period_current;

    UartState_V2_3_15():
      header(),
      latency_avg(0),
      latency_lmin(0),
      latency_lmax(0),
      latency_current(0),
      obs_period_avg(0),
      obs_period_pmin(0),
      obs_period_pmax(0),
      obs_period_current(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_avg;
      u_latency_avg.real = this->latency_avg;
      *(outbuffer + offset + 0) = (u_latency_avg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency_avg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency_avg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency_avg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency_avg);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_lmin;
      u_latency_lmin.real = this->latency_lmin;
      *(outbuffer + offset + 0) = (u_latency_lmin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency_lmin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency_lmin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency_lmin.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency_lmin);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_lmax;
      u_latency_lmax.real = this->latency_lmax;
      *(outbuffer + offset + 0) = (u_latency_lmax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency_lmax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency_lmax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency_lmax.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency_lmax);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_current;
      u_latency_current.real = this->latency_current;
      *(outbuffer + offset + 0) = (u_latency_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency_current);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_avg;
      u_obs_period_avg.real = this->obs_period_avg;
      *(outbuffer + offset + 0) = (u_obs_period_avg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_period_avg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_period_avg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_period_avg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_period_avg);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_pmin;
      u_obs_period_pmin.real = this->obs_period_pmin;
      *(outbuffer + offset + 0) = (u_obs_period_pmin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_period_pmin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_period_pmin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_period_pmin.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_period_pmin);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_pmax;
      u_obs_period_pmax.real = this->obs_period_pmax;
      *(outbuffer + offset + 0) = (u_obs_period_pmax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_period_pmax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_period_pmax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_period_pmax.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_period_pmax);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_current;
      u_obs_period_current.real = this->obs_period_current;
      *(outbuffer + offset + 0) = (u_obs_period_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_period_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_period_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_period_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_period_current);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_avg;
      u_latency_avg.base = 0;
      u_latency_avg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency_avg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency_avg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency_avg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency_avg = u_latency_avg.real;
      offset += sizeof(this->latency_avg);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_lmin;
      u_latency_lmin.base = 0;
      u_latency_lmin.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency_lmin.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency_lmin.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency_lmin.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency_lmin = u_latency_lmin.real;
      offset += sizeof(this->latency_lmin);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_lmax;
      u_latency_lmax.base = 0;
      u_latency_lmax.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency_lmax.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency_lmax.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency_lmax.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency_lmax = u_latency_lmax.real;
      offset += sizeof(this->latency_lmax);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_current;
      u_latency_current.base = 0;
      u_latency_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency_current = u_latency_current.real;
      offset += sizeof(this->latency_current);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_avg;
      u_obs_period_avg.base = 0;
      u_obs_period_avg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_period_avg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_period_avg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_period_avg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_period_avg = u_obs_period_avg.real;
      offset += sizeof(this->obs_period_avg);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_pmin;
      u_obs_period_pmin.base = 0;
      u_obs_period_pmin.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_period_pmin.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_period_pmin.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_period_pmin.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_period_pmin = u_obs_period_pmin.real;
      offset += sizeof(this->obs_period_pmin);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_pmax;
      u_obs_period_pmax.base = 0;
      u_obs_period_pmax.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_period_pmax.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_period_pmax.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_period_pmax.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_period_pmax = u_obs_period_pmax.real;
      offset += sizeof(this->obs_period_pmax);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_current;
      u_obs_period_current.base = 0;
      u_obs_period_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_period_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_period_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_period_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_period_current = u_obs_period_current.real;
      offset += sizeof(this->obs_period_current);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/UartState_V2_3_15"; };
    const char * getMD5(){ return "eab7c26cb7da9615284c0c7450fdcec3"; };

  };

}
#endif