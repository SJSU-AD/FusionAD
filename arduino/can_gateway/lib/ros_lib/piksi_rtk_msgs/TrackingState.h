#ifndef _ROS_piksi_rtk_msgs_TrackingState_h
#define _ROS_piksi_rtk_msgs_TrackingState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class TrackingState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t state_length;
      typedef uint8_t _state_type;
      _state_type st_state;
      _state_type * state;
      uint32_t sat_length;
      typedef uint16_t _sat_type;
      _sat_type st_sat;
      _sat_type * sat;
      uint32_t code_length;
      typedef uint8_t _code_type;
      _code_type st_code;
      _code_type * code;
      uint32_t cn0_length;
      typedef float _cn0_type;
      _cn0_type st_cn0;
      _cn0_type * cn0;

    TrackingState():
      header(),
      state_length(0), state(NULL),
      sat_length(0), sat(NULL),
      code_length(0), code(NULL),
      cn0_length(0), cn0(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->state_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->state_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->state_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->state_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_length);
      for( uint32_t i = 0; i < state_length; i++){
      *(outbuffer + offset + 0) = (this->state[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state[i]);
      }
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
      *(outbuffer + offset + 0) = (this->code_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->code_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->code_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->code_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->code_length);
      for( uint32_t i = 0; i < code_length; i++){
      *(outbuffer + offset + 0) = (this->code[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->code[i]);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t state_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      state_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      state_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      state_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->state_length);
      if(state_lengthT > state_length)
        this->state = (uint8_t*)realloc(this->state, state_lengthT * sizeof(uint8_t));
      state_length = state_lengthT;
      for( uint32_t i = 0; i < state_length; i++){
      this->st_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_state);
        memcpy( &(this->state[i]), &(this->st_state), sizeof(uint8_t));
      }
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
      uint32_t code_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      code_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      code_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      code_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->code_length);
      if(code_lengthT > code_length)
        this->code = (uint8_t*)realloc(this->code, code_lengthT * sizeof(uint8_t));
      code_length = code_lengthT;
      for( uint32_t i = 0; i < code_length; i++){
      this->st_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_code);
        memcpy( &(this->code[i]), &(this->st_code), sizeof(uint8_t));
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
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/TrackingState"; };
    const char * getMD5(){ return "e7984ffda35159a5c451b134b22b20b1"; };

  };

}
#endif