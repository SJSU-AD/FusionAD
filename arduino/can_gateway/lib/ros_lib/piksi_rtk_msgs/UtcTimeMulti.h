#ifndef _ROS_piksi_rtk_msgs_UtcTimeMulti_h
#define _ROS_piksi_rtk_msgs_UtcTimeMulti_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class UtcTimeMulti : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _flags_type;
      _flags_type flags;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef uint16_t _year_type;
      _year_type year;
      typedef uint8_t _month_type;
      _month_type month;
      typedef uint8_t _day_type;
      _day_type day;
      typedef uint8_t _hours_type;
      _hours_type hours;
      typedef uint8_t _minutes_type;
      _minutes_type minutes;
      typedef uint8_t _seconds_type;
      _seconds_type seconds;
      typedef uint32_t _ns_type;
      _ns_type ns;

    UtcTimeMulti():
      header(),
      flags(0),
      tow(0),
      year(0),
      month(0),
      day(0),
      hours(0),
      minutes(0),
      seconds(0),
      ns(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flags);
      *(outbuffer + offset + 0) = (this->tow >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tow >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tow >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tow >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tow);
      *(outbuffer + offset + 0) = (this->year >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->year >> (8 * 1)) & 0xFF;
      offset += sizeof(this->year);
      *(outbuffer + offset + 0) = (this->month >> (8 * 0)) & 0xFF;
      offset += sizeof(this->month);
      *(outbuffer + offset + 0) = (this->day >> (8 * 0)) & 0xFF;
      offset += sizeof(this->day);
      *(outbuffer + offset + 0) = (this->hours >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hours);
      *(outbuffer + offset + 0) = (this->minutes >> (8 * 0)) & 0xFF;
      offset += sizeof(this->minutes);
      *(outbuffer + offset + 0) = (this->seconds >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seconds);
      *(outbuffer + offset + 0) = (this->ns >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ns >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ns >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ns >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ns);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
      this->tow =  ((uint32_t) (*(inbuffer + offset)));
      this->tow |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tow |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tow |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tow);
      this->year =  ((uint16_t) (*(inbuffer + offset)));
      this->year |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->year);
      this->month =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->month);
      this->day =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->day);
      this->hours =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->hours);
      this->minutes =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->minutes);
      this->seconds =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->seconds);
      this->ns =  ((uint32_t) (*(inbuffer + offset)));
      this->ns |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ns |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->ns |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->ns);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/UtcTimeMulti"; };
    const char * getMD5(){ return "305f41bf5fdb87de324a10b06c47c614"; };

  };

}
#endif