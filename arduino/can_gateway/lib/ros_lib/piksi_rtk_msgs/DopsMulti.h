#ifndef _ROS_piksi_rtk_msgs_DopsMulti_h
#define _ROS_piksi_rtk_msgs_DopsMulti_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class DopsMulti : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef uint16_t _gdop_type;
      _gdop_type gdop;
      typedef uint16_t _pdop_type;
      _pdop_type pdop;
      typedef uint16_t _tdop_type;
      _tdop_type tdop;
      typedef uint16_t _hdop_type;
      _hdop_type hdop;
      typedef uint16_t _vdop_type;
      _vdop_type vdop;
      typedef uint8_t _flags_type;
      _flags_type flags;

    DopsMulti():
      header(),
      tow(0),
      gdop(0),
      pdop(0),
      tdop(0),
      hdop(0),
      vdop(0),
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
      *(outbuffer + offset + 0) = (this->gdop >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gdop >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gdop);
      *(outbuffer + offset + 0) = (this->pdop >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pdop >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pdop);
      *(outbuffer + offset + 0) = (this->tdop >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tdop >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tdop);
      *(outbuffer + offset + 0) = (this->hdop >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hdop >> (8 * 1)) & 0xFF;
      offset += sizeof(this->hdop);
      *(outbuffer + offset + 0) = (this->vdop >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vdop >> (8 * 1)) & 0xFF;
      offset += sizeof(this->vdop);
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
      this->gdop =  ((uint16_t) (*(inbuffer + offset)));
      this->gdop |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->gdop);
      this->pdop =  ((uint16_t) (*(inbuffer + offset)));
      this->pdop |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pdop);
      this->tdop =  ((uint16_t) (*(inbuffer + offset)));
      this->tdop |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->tdop);
      this->hdop =  ((uint16_t) (*(inbuffer + offset)));
      this->hdop |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->hdop);
      this->vdop =  ((uint16_t) (*(inbuffer + offset)));
      this->vdop |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->vdop);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/DopsMulti"; };
    const char * getMD5(){ return "c8ec518c5a95442b85a41a69915d3477"; };

  };

}
#endif