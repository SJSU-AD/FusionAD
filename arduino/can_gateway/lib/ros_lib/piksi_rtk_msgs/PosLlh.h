#ifndef _ROS_piksi_rtk_msgs_PosLlh_h
#define _ROS_piksi_rtk_msgs_PosLlh_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class PosLlh : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _tow_type;
      _tow_type tow;
      typedef double _lat_type;
      _lat_type lat;
      typedef double _lon_type;
      _lon_type lon;
      typedef double _height_type;
      _height_type height;
      typedef uint16_t _h_accuracy_type;
      _h_accuracy_type h_accuracy;
      typedef uint16_t _v_accuracy_type;
      _v_accuracy_type v_accuracy;
      typedef uint8_t _n_sats_type;
      _n_sats_type n_sats;
      typedef uint8_t _flags_type;
      _flags_type flags;

    PosLlh():
      header(),
      tow(0),
      lat(0),
      lon(0),
      height(0),
      h_accuracy(0),
      v_accuracy(0),
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
      union {
        double real;
        uint64_t base;
      } u_lat;
      u_lat.real = this->lat;
      *(outbuffer + offset + 0) = (u_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lat.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lat.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lat.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lat.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lat.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lat);
      union {
        double real;
        uint64_t base;
      } u_lon;
      u_lon.real = this->lon;
      *(outbuffer + offset + 0) = (u_lon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lon.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lon.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lon.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lon.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lon.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lon);
      union {
        double real;
        uint64_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->h_accuracy >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->h_accuracy >> (8 * 1)) & 0xFF;
      offset += sizeof(this->h_accuracy);
      *(outbuffer + offset + 0) = (this->v_accuracy >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->v_accuracy >> (8 * 1)) & 0xFF;
      offset += sizeof(this->v_accuracy);
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
      union {
        double real;
        uint64_t base;
      } u_lat;
      u_lat.base = 0;
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lat = u_lat.real;
      offset += sizeof(this->lat);
      union {
        double real;
        uint64_t base;
      } u_lon;
      u_lon.base = 0;
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lon = u_lon.real;
      offset += sizeof(this->lon);
      union {
        double real;
        uint64_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->height = u_height.real;
      offset += sizeof(this->height);
      this->h_accuracy =  ((uint16_t) (*(inbuffer + offset)));
      this->h_accuracy |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->h_accuracy);
      this->v_accuracy =  ((uint16_t) (*(inbuffer + offset)));
      this->v_accuracy |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->v_accuracy);
      this->n_sats =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->n_sats);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/PosLlh"; };
    const char * getMD5(){ return "8d021811eaa897569f2acbd0dbd803b3"; };

  };

}
#endif