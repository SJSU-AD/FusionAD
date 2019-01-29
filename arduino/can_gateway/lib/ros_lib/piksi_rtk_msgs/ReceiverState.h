#ifndef _ROS_piksi_rtk_msgs_ReceiverState_h
#define _ROS_piksi_rtk_msgs_ReceiverState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class ReceiverState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _num_sat_type;
      _num_sat_type num_sat;
      typedef bool _rtk_mode_fix_type;
      _rtk_mode_fix_type rtk_mode_fix;
      uint32_t sat_length;
      typedef uint16_t _sat_type;
      _sat_type st_sat;
      _sat_type * sat;
      uint32_t cn0_length;
      typedef float _cn0_type;
      _cn0_type st_cn0;
      _cn0_type * cn0;
      uint32_t tracking_running_length;
      typedef uint8_t _tracking_running_type;
      _tracking_running_type st_tracking_running;
      _tracking_running_type * tracking_running;
      typedef uint8_t _system_error_type;
      _system_error_type system_error;
      typedef uint8_t _io_error_type;
      _io_error_type io_error;
      typedef uint8_t _swift_nap_error_type;
      _swift_nap_error_type swift_nap_error;
      typedef uint8_t _external_antenna_present_type;
      _external_antenna_present_type external_antenna_present;

    ReceiverState():
      header(),
      num_sat(0),
      rtk_mode_fix(0),
      sat_length(0), sat(NULL),
      cn0_length(0), cn0(NULL),
      tracking_running_length(0), tracking_running(NULL),
      system_error(0),
      io_error(0),
      swift_nap_error(0),
      external_antenna_present(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->num_sat >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_sat);
      union {
        bool real;
        uint8_t base;
      } u_rtk_mode_fix;
      u_rtk_mode_fix.real = this->rtk_mode_fix;
      *(outbuffer + offset + 0) = (u_rtk_mode_fix.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rtk_mode_fix);
      *(outbuffer + offset + 0) = (this->sat_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sat_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sat_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sat_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sat_length);
      for( uint32_t i = 0; i < sat_length; i++){
      *(outbuffer + offset + 0) = (this->sat[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sat[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sat[i]);
      }
      *(outbuffer + offset + 0) = (this->cn0_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cn0_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cn0_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cn0_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cn0_length);
      for( uint32_t i = 0; i < cn0_length; i++){
      union {
        float real;
        uint32_t base;
      } u_cn0i;
      u_cn0i.real = this->cn0[i];
      *(outbuffer + offset + 0) = (u_cn0i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cn0i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cn0i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cn0i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cn0[i]);
      }
      *(outbuffer + offset + 0) = (this->tracking_running_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tracking_running_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tracking_running_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tracking_running_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tracking_running_length);
      for( uint32_t i = 0; i < tracking_running_length; i++){
      *(outbuffer + offset + 0) = (this->tracking_running[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tracking_running[i]);
      }
      *(outbuffer + offset + 0) = (this->system_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->system_error);
      *(outbuffer + offset + 0) = (this->io_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->io_error);
      *(outbuffer + offset + 0) = (this->swift_nap_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->swift_nap_error);
      *(outbuffer + offset + 0) = (this->external_antenna_present >> (8 * 0)) & 0xFF;
      offset += sizeof(this->external_antenna_present);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->num_sat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_sat);
      union {
        bool real;
        uint8_t base;
      } u_rtk_mode_fix;
      u_rtk_mode_fix.base = 0;
      u_rtk_mode_fix.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rtk_mode_fix = u_rtk_mode_fix.real;
      offset += sizeof(this->rtk_mode_fix);
      uint32_t sat_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sat_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sat_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sat_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sat_length);
      if(sat_lengthT > sat_length)
        this->sat = (uint16_t*)realloc(this->sat, sat_lengthT * sizeof(uint16_t));
      sat_length = sat_lengthT;
      for( uint32_t i = 0; i < sat_length; i++){
      this->st_sat =  ((uint16_t) (*(inbuffer + offset)));
      this->st_sat |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_sat);
        memcpy( &(this->sat[i]), &(this->st_sat), sizeof(uint16_t));
      }
      uint32_t cn0_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cn0_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cn0_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cn0_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cn0_length);
      if(cn0_lengthT > cn0_length)
        this->cn0 = (float*)realloc(this->cn0, cn0_lengthT * sizeof(float));
      cn0_length = cn0_lengthT;
      for( uint32_t i = 0; i < cn0_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_cn0;
      u_st_cn0.base = 0;
      u_st_cn0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cn0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cn0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cn0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cn0 = u_st_cn0.real;
      offset += sizeof(this->st_cn0);
        memcpy( &(this->cn0[i]), &(this->st_cn0), sizeof(float));
      }
      uint32_t tracking_running_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tracking_running_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tracking_running_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tracking_running_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tracking_running_length);
      if(tracking_running_lengthT > tracking_running_length)
        this->tracking_running = (uint8_t*)realloc(this->tracking_running, tracking_running_lengthT * sizeof(uint8_t));
      tracking_running_length = tracking_running_lengthT;
      for( uint32_t i = 0; i < tracking_running_length; i++){
      this->st_tracking_running =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_tracking_running);
        memcpy( &(this->tracking_running[i]), &(this->st_tracking_running), sizeof(uint8_t));
      }
      this->system_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->system_error);
      this->io_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->io_error);
      this->swift_nap_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->swift_nap_error);
      this->external_antenna_present =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->external_antenna_present);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/ReceiverState"; };
    const char * getMD5(){ return "3bca929a4e134714778225bff42f183c"; };

  };

}
#endif