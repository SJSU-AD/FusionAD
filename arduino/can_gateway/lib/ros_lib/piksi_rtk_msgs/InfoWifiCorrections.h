#ifndef _ROS_piksi_rtk_msgs_InfoWifiCorrections_h
#define _ROS_piksi_rtk_msgs_InfoWifiCorrections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class InfoWifiCorrections : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _received_corrections_type;
      _received_corrections_type received_corrections;
      typedef float _latency_type;
      _latency_type latency;

    InfoWifiCorrections():
      header(),
      received_corrections(0),
      latency(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->received_corrections >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->received_corrections >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->received_corrections >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->received_corrections >> (8 * 3)) & 0xFF;
      offset += sizeof(this->received_corrections);
      union {
        float real;
        uint32_t base;
      } u_latency;
      u_latency.real = this->latency;
      *(outbuffer + offset + 0) = (u_latency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->received_corrections =  ((uint32_t) (*(inbuffer + offset)));
      this->received_corrections |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->received_corrections |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->received_corrections |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->received_corrections);
      union {
        float real;
        uint32_t base;
      } u_latency;
      u_latency.base = 0;
      u_latency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency = u_latency.real;
      offset += sizeof(this->latency);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/InfoWifiCorrections"; };
    const char * getMD5(){ return "925248c7afa695eb59c83cfd29d8c57c"; };

  };

}
#endif