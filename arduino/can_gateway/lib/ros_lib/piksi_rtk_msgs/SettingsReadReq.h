#ifndef _ROS_SERVICE_SettingsReadReq_h
#define _ROS_SERVICE_SettingsReadReq_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace piksi_rtk_msgs
{

static const char SETTINGSREADREQ[] = "piksi_rtk_msgs/SettingsReadReq";

  class SettingsReadReqRequest : public ros::Msg
  {
    public:
      typedef const char* _section_setting_type;
      _section_setting_type section_setting;
      typedef const char* _setting_type;
      _setting_type setting;

    SettingsReadReqRequest():
      section_setting(""),
      setting("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_section_setting = strlen(this->section_setting);
      varToArr(outbuffer + offset, length_section_setting);
      offset += 4;
      memcpy(outbuffer + offset, this->section_setting, length_section_setting);
      offset += length_section_setting;
      uint32_t length_setting = strlen(this->setting);
      varToArr(outbuffer + offset, length_setting);
      offset += 4;
      memcpy(outbuffer + offset, this->setting, length_setting);
      offset += length_setting;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_section_setting;
      arrToVar(length_section_setting, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_section_setting; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_section_setting-1]=0;
      this->section_setting = (char *)(inbuffer + offset-1);
      offset += length_section_setting;
      uint32_t length_setting;
      arrToVar(length_setting, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_setting; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_setting-1]=0;
      this->setting = (char *)(inbuffer + offset-1);
      offset += length_setting;
     return offset;
    }

    const char * getType(){ return SETTINGSREADREQ; };
    const char * getMD5(){ return "5e0ca67b77ad0356e13015bb542e7b59"; };

  };

  class SettingsReadReqResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    SettingsReadReqResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return SETTINGSREADREQ; };
    const char * getMD5(){ return "937c9679a518e3a18d831e57125ea522"; };

  };

  class SettingsReadReq {
    public:
    typedef SettingsReadReqRequest Request;
    typedef SettingsReadReqResponse Response;
  };

}
#endif
