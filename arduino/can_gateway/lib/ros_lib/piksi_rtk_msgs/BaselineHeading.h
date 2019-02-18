#ifndef _ROS_piksi_rtk_msgs_BaselineHeading_h
#define _ROS_piksi_rtk_msgs_BaselineHeading_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class BaselineHeading : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef uint32_t _heading_type;
      _heading_type heading;
      typedef uint8_t _n_sats_type;
      _n_sats_type n_sats;
      typedef uint8_t _flags_type;
      _flags_type flags;

    BaselineHeading():
      header(),
      tow(0),
      heading(0),
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
      *(outbuffer + offset + 0) = (this->heading >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->heading >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->heading >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->heading >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heading);
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
      this->heading =  ((uint32_t) (*(inbuffer + offset)));
      this->heading |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->heading |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->heading |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->heading);
      this->n_sats =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->n_sats);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/BaselineHeading"; };
    const char * getMD5(){ return "2898fbd48c60846b0ee32eacef99afae"; };

  };

}
#endif