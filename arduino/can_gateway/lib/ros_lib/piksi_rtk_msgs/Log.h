#ifndef _ROS_piksi_rtk_msgs_Log_h
#define _ROS_piksi_rtk_msgs_Log_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class Log : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _level_type;
      _level_type level;
      typedef const char* _text_type;
      _text_type text;

    Log():
      header(),
      level(0),
      text("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->level);
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->level);
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/Log"; };
    const char * getMD5(){ return "479c0d9a1959331b49466f8b39ceb6bb"; };

  };

}
#endif