#ifndef _ROS_piksi_rtk_msgs_AgeOfCorrections_h
#define _ROS_piksi_rtk_msgs_AgeOfCorrections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class AgeOfCorrections : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef uint16_t _age_type;
      _age_type age;

    AgeOfCorrections():
      header(),
      tow(0),
      age(0)
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
      *(outbuffer + offset + 0) = (this->age >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age >> (8 * 1)) & 0xFF;
      offset += sizeof(this->age);
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
      this->age =  ((uint16_t) (*(inbuffer + offset)));
      this->age |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->age);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/AgeOfCorrections"; };
    const char * getMD5(){ return "94c5e09b6a4cc653e4fede2c22a046bf"; };

  };

}
#endif