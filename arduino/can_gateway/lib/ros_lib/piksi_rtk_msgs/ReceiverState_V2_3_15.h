#ifndef _ROS_piksi_rtk_msgs_ReceiverState_V2_3_15_h
#define _ROS_piksi_rtk_msgs_ReceiverState_V2_3_15_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class ReceiverState_V2_3_15 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _num_sat_type;
      _num_sat_type num_sat;
      typedef bool _rtk_mode_fix_type;
      _rtk_mode_fix_type rtk_mode_fix;
      uint32_t sat_length;
      typedef uint8_t _sat_type;
      _sat_type st_sat;
      _sat_type * sat;
      uint32_t cn0_length;
      typedef uint8_t _cn0_type;
      _cn0_type st_cn0;
      _cn0_type * cn0;
      typedef uint8_t _system_error_type;
      _system_error_type system_error;
      typedef uint8_t _io_error_type;
      _io_error_type io_error;
      typedef uint8_t _swift_nap_error_type;
      _swift_nap_error_type swift_nap_error;
      typedef uint8_t _external_antenna_present_type;
      _external_antenna_present_type external_antenna_present;
      typedef uint8_t _num_gps_sat_type;
      _num_gps_sat_type num_gps_sat;
      uint32_t cn0_gps_length;
      typedef uint8_t _cn0_gps_type;
      _cn0_gps_type st_cn0_gps;
      _cn0_gps_type * cn0_gps;
      typedef uint8_t _num_sbas_sat_type;
      _num_sbas_sat_type num_sbas_sat;
      uint32_t cn0_sbas_length;
      typedef uint8_t _cn0_sbas_type;
      _cn0_sbas_type st_cn0_sbas;
      _cn0_sbas_type * cn0_sbas;
      typedef uint8_t _num_glonass_sat_type;
      _num_glonass_sat_type num_glonass_sat;
      uint32_t cn0_glonass_length;
      typedef uint8_t _cn0_glonass_type;
      _cn0_glonass_type st_cn0_glonass;
      _cn0_glonass_type * cn0_glonass;
      typedef const char* _fix_mode_type;
      _fix_mode_type fix_mode;
      enum { STR_FIX_MODE_INVALID =  Invalid };
      enum { STR_FIX_MODE_SPP =  SPP };
      enum { STR_FIX_MODE_DGNSS =  DGNSS };
      enum { STR_FIX_MODE_FLOAT_RTK =  FLOAT_RTK };
      enum { STR_FIX_MODE_FIXED_RTK =  FIXED_RTK };
      enum { STR_FIX_MODE_DEAD_RECKONING =  DEAD_RECKONING };
      enum { STR_FIX_MODE_SBAS =  SBAS };
      enum { STR_FIX_MODE_UNKNOWN =  Unknown };

    ReceiverState_V2_3_15():
      header(),
      num_sat(0),
      rtk_mode_fix(0),
      sat_length(0), sat(NULL),
      cn0_length(0), cn0(NULL),
      system_error(0),
      io_error(0),
      swift_nap_error(0),
      external_antenna_present(0),
      num_gps_sat(0),
      cn0_gps_length(0), cn0_gps(NULL),
      num_sbas_sat(0),
      cn0_sbas_length(0), cn0_sbas(NULL),
      num_glonass_sat(0),
      cn0_glonass_length(0), cn0_glonass(NULL),
      fix_mode("")
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
      offset += sizeof(this->sat[i]);
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
      *(outbuffer + offset + 0) = (this->system_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->system_error);
      *(outbuffer + offset + 0) = (this->io_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->io_error);
      *(outbuffer + offset + 0) = (this->swift_nap_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->swift_nap_error);
      *(outbuffer + offset + 0) = (this->external_antenna_present >> (8 * 0)) & 0xFF;
      offset += sizeof(this->external_antenna_present);
      *(outbuffer + offset + 0) = (this->num_gps_sat >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_gps_sat);
      *(outbuffer + offset + 0) = (this->cn0_gps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cn0_gps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cn0_gps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cn0_gps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cn0_gps_length);
      for( uint32_t i = 0; i < cn0_gps_length; i++){
      *(outbuffer + offset + 0) = (this->cn0_gps[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cn0_gps[i]);
      }
      *(outbuffer + offset + 0) = (this->num_sbas_sat >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_sbas_sat);
      *(outbuffer + offset + 0) = (this->cn0_sbas_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cn0_sbas_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cn0_sbas_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cn0_sbas_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cn0_sbas_length);
      for( uint32_t i = 0; i < cn0_sbas_length; i++){
      *(outbuffer + offset + 0) = (this->cn0_sbas[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cn0_sbas[i]);
      }
      *(outbuffer + offset + 0) = (this->num_glonass_sat >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_glonass_sat);
      *(outbuffer + offset + 0) = (this->cn0_glonass_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cn0_glonass_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cn0_glonass_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cn0_glonass_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cn0_glonass_length);
      for( uint32_t i = 0; i < cn0_glonass_length; i++){
      *(outbuffer + offset + 0) = (this->cn0_glonass[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cn0_glonass[i]);
      }
      uint32_t length_fix_mode = strlen(this->fix_mode);
      varToArr(outbuffer + offset, length_fix_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->fix_mode, length_fix_mode);
      offset += length_fix_mode;
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
        this->sat = (uint8_t*)realloc(this->sat, sat_lengthT * sizeof(uint8_t));
      sat_length = sat_lengthT;
      for( uint32_t i = 0; i < sat_length; i++){
      this->st_sat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_sat);
        memcpy( &(this->sat[i]), &(this->st_sat), sizeof(uint8_t));
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
      this->system_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->system_error);
      this->io_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->io_error);
      this->swift_nap_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->swift_nap_error);
      this->external_antenna_present =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->external_antenna_present);
      this->num_gps_sat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_gps_sat);
      uint32_t cn0_gps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cn0_gps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cn0_gps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cn0_gps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cn0_gps_length);
      if(cn0_gps_lengthT > cn0_gps_length)
        this->cn0_gps = (uint8_t*)realloc(this->cn0_gps, cn0_gps_lengthT * sizeof(uint8_t));
      cn0_gps_length = cn0_gps_lengthT;
      for( uint32_t i = 0; i < cn0_gps_length; i++){
      this->st_cn0_gps =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_cn0_gps);
        memcpy( &(this->cn0_gps[i]), &(this->st_cn0_gps), sizeof(uint8_t));
      }
      this->num_sbas_sat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_sbas_sat);
      uint32_t cn0_sbas_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cn0_sbas_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cn0_sbas_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cn0_sbas_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cn0_sbas_length);
      if(cn0_sbas_lengthT > cn0_sbas_length)
        this->cn0_sbas = (uint8_t*)realloc(this->cn0_sbas, cn0_sbas_lengthT * sizeof(uint8_t));
      cn0_sbas_length = cn0_sbas_lengthT;
      for( uint32_t i = 0; i < cn0_sbas_length; i++){
      this->st_cn0_sbas =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_cn0_sbas);
        memcpy( &(this->cn0_sbas[i]), &(this->st_cn0_sbas), sizeof(uint8_t));
      }
      this->num_glonass_sat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_glonass_sat);
      uint32_t cn0_glonass_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cn0_glonass_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cn0_glonass_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cn0_glonass_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cn0_glonass_length);
      if(cn0_glonass_lengthT > cn0_glonass_length)
        this->cn0_glonass = (uint8_t*)realloc(this->cn0_glonass, cn0_glonass_lengthT * sizeof(uint8_t));
      cn0_glonass_length = cn0_glonass_lengthT;
      for( uint32_t i = 0; i < cn0_glonass_length; i++){
      this->st_cn0_glonass =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_cn0_glonass);
        memcpy( &(this->cn0_glonass[i]), &(this->st_cn0_glonass), sizeof(uint8_t));
      }
      uint32_t length_fix_mode;
      arrToVar(length_fix_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fix_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fix_mode-1]=0;
      this->fix_mode = (char *)(inbuffer + offset-1);
      offset += length_fix_mode;
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/ReceiverState_V2_3_15"; };
    const char * getMD5(){ return "88c8f10862fd18e3d9be4baddbd4a786"; };

  };

}
#endif