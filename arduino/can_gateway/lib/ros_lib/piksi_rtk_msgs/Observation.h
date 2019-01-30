#ifndef _ROS_piksi_rtk_msgs_Observation_h
#define _ROS_piksi_rtk_msgs_Observation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class Observation : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef int32_t _ns_residual_type;
      _ns_residual_type ns_residual;
      typedef uint16_t _wn_type;
      _wn_type wn;
      typedef uint8_t _n_obs_type;
      _n_obs_type n_obs;
      uint32_t P_length;
      typedef uint32_t _P_type;
      _P_type st_P;
      _P_type * P;
      uint32_t L_i_length;
      typedef int32_t _L_i_type;
      _L_i_type st_L_i;
      _L_i_type * L_i;
      uint32_t L_f_length;
      typedef uint8_t _L_f_type;
      _L_f_type st_L_f;
      _L_f_type * L_f;
      uint32_t D_i_length;
      typedef int16_t _D_i_type;
      _D_i_type st_D_i;
      _D_i_type * D_i;
      uint32_t D_f_length;
      typedef uint8_t _D_f_type;
      _D_f_type st_D_f;
      _D_f_type * D_f;
      uint32_t cn0_length;
      typedef uint8_t _cn0_type;
      _cn0_type st_cn0;
      _cn0_type * cn0;
      uint32_t lock_length;
      typedef uint8_t _lock_type;
      _lock_type st_lock;
      _lock_type * lock;
      uint32_t flags_length;
      typedef uint8_t _flags_type;
      _flags_type st_flags;
      _flags_type * flags;
      uint32_t sid_sat_length;
      typedef uint8_t _sid_sat_type;
      _sid_sat_type st_sid_sat;
      _sid_sat_type * sid_sat;
      uint32_t sid_code_length;
      typedef uint8_t _sid_code_type;
      _sid_code_type st_sid_code;
      _sid_code_type * sid_code;

    Observation():
      header(),
      tow(0),
      ns_residual(0),
      wn(0),
      n_obs(0),
      P_length(0), P(NULL),
      L_i_length(0), L_i(NULL),
      L_f_length(0), L_f(NULL),
      D_i_length(0), D_i(NULL),
      D_f_length(0), D_f(NULL),
      cn0_length(0), cn0(NULL),
      lock_length(0), lock(NULL),
      flags_length(0), flags(NULL),
      sid_sat_length(0), sid_sat(NULL),
      sid_code_length(0), sid_code(NULL)
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
      } u_ns_residual;
      u_ns_residual.real = this->ns_residual;
      *(outbuffer + offset + 0) = (u_ns_residual.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ns_residual.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ns_residual.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ns_residual.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ns_residual);
      *(outbuffer + offset + 0) = (this->wn >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wn >> (8 * 1)) & 0xFF;
      offset += sizeof(this->wn);
      *(outbuffer + offset + 0) = (this->n_obs >> (8 * 0)) & 0xFF;
      offset += sizeof(this->n_obs);
      *(outbuffer + offset + 0) = (this->P_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->P_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->P_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->P_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->P_length);
      for( uint32_t i = 0; i < P_length; i++){
      *(outbuffer + offset + 0) = (this->P[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->P[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->P[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->P[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->P[i]);
      }
      *(outbuffer + offset + 0) = (this->L_i_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->L_i_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->L_i_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->L_i_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->L_i_length);
      for( uint32_t i = 0; i < L_i_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_L_ii;
      u_L_ii.real = this->L_i[i];
      *(outbuffer + offset + 0) = (u_L_ii.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_L_ii.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_L_ii.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_L_ii.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->L_i[i]);
      }
      *(outbuffer + offset + 0) = (this->L_f_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->L_f_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->L_f_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->L_f_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->L_f_length);
      for( uint32_t i = 0; i < L_f_length; i++){
      *(outbuffer + offset + 0) = (this->L_f[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->L_f[i]);
      }
      *(outbuffer + offset + 0) = (this->D_i_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->D_i_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->D_i_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->D_i_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->D_i_length);
      for( uint32_t i = 0; i < D_i_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_D_ii;
      u_D_ii.real = this->D_i[i];
      *(outbuffer + offset + 0) = (u_D_ii.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_D_ii.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->D_i[i]);
      }
      *(outbuffer + offset + 0) = (this->D_f_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->D_f_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->D_f_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->D_f_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->D_f_length);
      for( uint32_t i = 0; i < D_f_length; i++){
      *(outbuffer + offset + 0) = (this->D_f[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->D_f[i]);
      }
      *(outbuffer + offset + 0) = (this->cn0_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cn0_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cn0_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cn0_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cn0_length);
      for( uint32_t i = 0; i < cn0_length; i++){
      *(outbuffer + offset + 0) = (this->cn0[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cn0[i]);
      }
      *(outbuffer + offset + 0) = (this->lock_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lock_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lock_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lock_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lock_length);
      for( uint32_t i = 0; i < lock_length; i++){
      *(outbuffer + offset + 0) = (this->lock[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lock[i]);
      }
      *(outbuffer + offset + 0) = (this->flags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flags_length);
      for( uint32_t i = 0; i < flags_length; i++){
      *(outbuffer + offset + 0) = (this->flags[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flags[i]);
      }
      *(outbuffer + offset + 0) = (this->sid_sat_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sid_sat_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sid_sat_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sid_sat_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sid_sat_length);
      for( uint32_t i = 0; i < sid_sat_length; i++){
      *(outbuffer + offset + 0) = (this->sid_sat[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sid_sat[i]);
      }
      *(outbuffer + offset + 0) = (this->sid_code_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sid_code_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sid_code_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sid_code_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sid_code_length);
      for( uint32_t i = 0; i < sid_code_length; i++){
      *(outbuffer + offset + 0) = (this->sid_code[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sid_code[i]);
      }
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
      } u_ns_residual;
      u_ns_residual.base = 0;
      u_ns_residual.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ns_residual.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ns_residual.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ns_residual.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ns_residual = u_ns_residual.real;
      offset += sizeof(this->ns_residual);
      this->wn =  ((uint16_t) (*(inbuffer + offset)));
      this->wn |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->wn);
      this->n_obs =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->n_obs);
      uint32_t P_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      P_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      P_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      P_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->P_length);
      if(P_lengthT > P_length)
        this->P = (uint32_t*)realloc(this->P, P_lengthT * sizeof(uint32_t));
      P_length = P_lengthT;
      for( uint32_t i = 0; i < P_length; i++){
      this->st_P =  ((uint32_t) (*(inbuffer + offset)));
      this->st_P |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_P |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_P |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_P);
        memcpy( &(this->P[i]), &(this->st_P), sizeof(uint32_t));
      }
      uint32_t L_i_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      L_i_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      L_i_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      L_i_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->L_i_length);
      if(L_i_lengthT > L_i_length)
        this->L_i = (int32_t*)realloc(this->L_i, L_i_lengthT * sizeof(int32_t));
      L_i_length = L_i_lengthT;
      for( uint32_t i = 0; i < L_i_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_L_i;
      u_st_L_i.base = 0;
      u_st_L_i.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_L_i.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_L_i.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_L_i.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_L_i = u_st_L_i.real;
      offset += sizeof(this->st_L_i);
        memcpy( &(this->L_i[i]), &(this->st_L_i), sizeof(int32_t));
      }
      uint32_t L_f_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      L_f_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      L_f_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      L_f_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->L_f_length);
      if(L_f_lengthT > L_f_length)
        this->L_f = (uint8_t*)realloc(this->L_f, L_f_lengthT * sizeof(uint8_t));
      L_f_length = L_f_lengthT;
      for( uint32_t i = 0; i < L_f_length; i++){
      this->st_L_f =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_L_f);
        memcpy( &(this->L_f[i]), &(this->st_L_f), sizeof(uint8_t));
      }
      uint32_t D_i_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      D_i_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      D_i_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      D_i_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->D_i_length);
      if(D_i_lengthT > D_i_length)
        this->D_i = (int16_t*)realloc(this->D_i, D_i_lengthT * sizeof(int16_t));
      D_i_length = D_i_lengthT;
      for( uint32_t i = 0; i < D_i_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_D_i;
      u_st_D_i.base = 0;
      u_st_D_i.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_D_i.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_D_i = u_st_D_i.real;
      offset += sizeof(this->st_D_i);
        memcpy( &(this->D_i[i]), &(this->st_D_i), sizeof(int16_t));
      }
      uint32_t D_f_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      D_f_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      D_f_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      D_f_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->D_f_length);
      if(D_f_lengthT > D_f_length)
        this->D_f = (uint8_t*)realloc(this->D_f, D_f_lengthT * sizeof(uint8_t));
      D_f_length = D_f_lengthT;
      for( uint32_t i = 0; i < D_f_length; i++){
      this->st_D_f =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_D_f);
        memcpy( &(this->D_f[i]), &(this->st_D_f), sizeof(uint8_t));
      }
      uint32_t cn0_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cn0_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cn0_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cn0_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cn0_length);
      if(cn0_lengthT > cn0_length)
        this->cn0 = (uint8_t*)realloc(this->cn0, cn0_lengthT * sizeof(uint8_t));
      cn0_length = cn0_lengthT;
      for( uint32_t i = 0; i < cn0_length; i++){
      this->st_cn0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_cn0);
        memcpy( &(this->cn0[i]), &(this->st_cn0), sizeof(uint8_t));
      }
      uint32_t lock_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lock_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lock_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lock_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lock_length);
      if(lock_lengthT > lock_length)
        this->lock = (uint8_t*)realloc(this->lock, lock_lengthT * sizeof(uint8_t));
      lock_length = lock_lengthT;
      for( uint32_t i = 0; i < lock_length; i++){
      this->st_lock =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_lock);
        memcpy( &(this->lock[i]), &(this->st_lock), sizeof(uint8_t));
      }
      uint32_t flags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->flags_length);
      if(flags_lengthT > flags_length)
        this->flags = (uint8_t*)realloc(this->flags, flags_lengthT * sizeof(uint8_t));
      flags_length = flags_lengthT;
      for( uint32_t i = 0; i < flags_length; i++){
      this->st_flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_flags);
        memcpy( &(this->flags[i]), &(this->st_flags), sizeof(uint8_t));
      }
      uint32_t sid_sat_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sid_sat_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sid_sat_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sid_sat_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sid_sat_length);
      if(sid_sat_lengthT > sid_sat_length)
        this->sid_sat = (uint8_t*)realloc(this->sid_sat, sid_sat_lengthT * sizeof(uint8_t));
      sid_sat_length = sid_sat_lengthT;
      for( uint32_t i = 0; i < sid_sat_length; i++){
      this->st_sid_sat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_sid_sat);
        memcpy( &(this->sid_sat[i]), &(this->st_sid_sat), sizeof(uint8_t));
      }
      uint32_t sid_code_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sid_code_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sid_code_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sid_code_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sid_code_length);
      if(sid_code_lengthT > sid_code_length)
        this->sid_code = (uint8_t*)realloc(this->sid_code, sid_code_lengthT * sizeof(uint8_t));
      sid_code_length = sid_code_lengthT;
      for( uint32_t i = 0; i < sid_code_length; i++){
      this->st_sid_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_sid_code);
        memcpy( &(this->sid_code[i]), &(this->st_sid_code), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/Observation"; };
    const char * getMD5(){ return "9fb93688b90e872c3a77668a53e5ecc9"; };

  };

}
#endif