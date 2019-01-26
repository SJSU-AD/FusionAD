#ifndef _ROS_interface_Can_Interface_h
#define _ROS_interface_Can_Interface_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace interface
{

  class Can_Interface : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _isCanBusInitialized_type;
      _isCanBusInitialized_type isCanBusInitialized;
      typedef uint32_t _can_id_type;
      _can_id_type can_id;
      typedef bool _extended_message_type;
      _extended_message_type extended_message;
      int8_t can_data[8];

    Can_Interface():
      header(),
      isCanBusInitialized(0),
      can_id(0),
      extended_message(0),
      can_data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isCanBusInitialized;
      u_isCanBusInitialized.real = this->isCanBusInitialized;
      *(outbuffer + offset + 0) = (u_isCanBusInitialized.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isCanBusInitialized);
      *(outbuffer + offset + 0) = (this->can_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->can_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->can_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->can_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->can_id);
      union {
        bool real;
        uint8_t base;
      } u_extended_message;
      u_extended_message.real = this->extended_message;
      *(outbuffer + offset + 0) = (u_extended_message.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->extended_message);
      for( uint32_t i = 0; i < 8; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_can_datai;
      u_can_datai.real = this->can_data[i];
      *(outbuffer + offset + 0) = (u_can_datai.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->can_data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isCanBusInitialized;
      u_isCanBusInitialized.base = 0;
      u_isCanBusInitialized.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isCanBusInitialized = u_isCanBusInitialized.real;
      offset += sizeof(this->isCanBusInitialized);
      this->can_id =  ((uint32_t) (*(inbuffer + offset)));
      this->can_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->can_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->can_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->can_id);
      union {
        bool real;
        uint8_t base;
      } u_extended_message;
      u_extended_message.base = 0;
      u_extended_message.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->extended_message = u_extended_message.real;
      offset += sizeof(this->extended_message);
      for( uint32_t i = 0; i < 8; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_can_datai;
      u_can_datai.base = 0;
      u_can_datai.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->can_data[i] = u_can_datai.real;
      offset += sizeof(this->can_data[i]);
      }
     return offset;
    }

    const char * getType(){ return "interface/Can_Interface"; };
    const char * getMD5(){ return "5678b3f538ed59cc1b06d5565c677f0a"; };

  };

}
#endif