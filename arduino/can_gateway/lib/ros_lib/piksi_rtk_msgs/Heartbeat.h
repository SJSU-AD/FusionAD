#ifndef _ROS_piksi_rtk_msgs_Heartbeat_h
#define _ROS_piksi_rtk_msgs_Heartbeat_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class Heartbeat : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _system_error_type;
      _system_error_type system_error;
      typedef uint8_t _io_error_type;
      _io_error_type io_error;
      typedef uint8_t _swift_nap_error_type;
      _swift_nap_error_type swift_nap_error;
      typedef uint8_t _sbp_minor_version_type;
      _sbp_minor_version_type sbp_minor_version;
      typedef uint8_t _sbp_major_version_type;
      _sbp_major_version_type sbp_major_version;
      typedef uint8_t _external_antenna_present_type;
      _external_antenna_present_type external_antenna_present;

    Heartbeat():
      header(),
      system_error(0),
      io_error(0),
      swift_nap_error(0),
      sbp_minor_version(0),
      sbp_major_version(0),
      external_antenna_present(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->system_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->system_error);
      *(outbuffer + offset + 0) = (this->io_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->io_error);
      *(outbuffer + offset + 0) = (this->swift_nap_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->swift_nap_error);
      *(outbuffer + offset + 0) = (this->sbp_minor_version >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sbp_minor_version);
      *(outbuffer + offset + 0) = (this->sbp_major_version >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sbp_major_version);
      *(outbuffer + offset + 0) = (this->external_antenna_present >> (8 * 0)) & 0xFF;
      offset += sizeof(this->external_antenna_present);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->system_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->system_error);
      this->io_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->io_error);
      this->swift_nap_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->swift_nap_error);
      this->sbp_minor_version =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sbp_minor_version);
      this->sbp_major_version =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sbp_major_version);
      this->external_antenna_present =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->external_antenna_present);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/Heartbeat"; };
    const char * getMD5(){ return "f302769a534aa6ff5a3f6b1f1c11f4bc"; };

  };

}
#endif