#ifndef _ROS_piksi_rtk_msgs_ImuAuxMulti_h
#define _ROS_piksi_rtk_msgs_ImuAuxMulti_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class ImuAuxMulti : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _imu_type_type;
      _imu_type_type imu_type;
      typedef int16_t _temp_type;
      _temp_type temp;
      typedef uint8_t _imu_conf_type;
      _imu_conf_type imu_conf;

    ImuAuxMulti():
      header(),
      imu_type(0),
      temp(0),
      imu_conf(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->imu_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->imu_type);
      union {
        int16_t real;
        uint16_t base;
      } u_temp;
      u_temp.real = this->temp;
      *(outbuffer + offset + 0) = (u_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->temp);
      *(outbuffer + offset + 0) = (this->imu_conf >> (8 * 0)) & 0xFF;
      offset += sizeof(this->imu_conf);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->imu_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->imu_type);
      union {
        int16_t real;
        uint16_t base;
      } u_temp;
      u_temp.base = 0;
      u_temp.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->temp = u_temp.real;
      offset += sizeof(this->temp);
      this->imu_conf =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->imu_conf);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/ImuAuxMulti"; };
    const char * getMD5(){ return "1d0e477b2db08e26ff9772a2136dfba7"; };

  };

}
#endif