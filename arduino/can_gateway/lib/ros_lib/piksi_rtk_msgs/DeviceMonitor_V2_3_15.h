#ifndef _ROS_piksi_rtk_msgs_DeviceMonitor_V2_3_15_h
#define _ROS_piksi_rtk_msgs_DeviceMonitor_V2_3_15_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class DeviceMonitor_V2_3_15 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _dev_vin_type;
      _dev_vin_type dev_vin;
      typedef int16_t _cpu_vint_type;
      _cpu_vint_type cpu_vint;
      typedef int16_t _cpu_vaux_type;
      _cpu_vaux_type cpu_vaux;
      typedef int16_t _cpu_temperature_type;
      _cpu_temperature_type cpu_temperature;
      typedef int16_t _fe_temperature_type;
      _fe_temperature_type fe_temperature;

    DeviceMonitor_V2_3_15():
      header(),
      dev_vin(0),
      cpu_vint(0),
      cpu_vaux(0),
      cpu_temperature(0),
      fe_temperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_dev_vin;
      u_dev_vin.real = this->dev_vin;
      *(outbuffer + offset + 0) = (u_dev_vin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dev_vin.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->dev_vin);
      union {
        int16_t real;
        uint16_t base;
      } u_cpu_vint;
      u_cpu_vint.real = this->cpu_vint;
      *(outbuffer + offset + 0) = (u_cpu_vint.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cpu_vint.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cpu_vint);
      union {
        int16_t real;
        uint16_t base;
      } u_cpu_vaux;
      u_cpu_vaux.real = this->cpu_vaux;
      *(outbuffer + offset + 0) = (u_cpu_vaux.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cpu_vaux.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cpu_vaux);
      union {
        int16_t real;
        uint16_t base;
      } u_cpu_temperature;
      u_cpu_temperature.real = this->cpu_temperature;
      *(outbuffer + offset + 0) = (u_cpu_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cpu_temperature.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cpu_temperature);
      union {
        int16_t real;
        uint16_t base;
      } u_fe_temperature;
      u_fe_temperature.real = this->fe_temperature;
      *(outbuffer + offset + 0) = (u_fe_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fe_temperature.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fe_temperature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_dev_vin;
      u_dev_vin.base = 0;
      u_dev_vin.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dev_vin.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->dev_vin = u_dev_vin.real;
      offset += sizeof(this->dev_vin);
      union {
        int16_t real;
        uint16_t base;
      } u_cpu_vint;
      u_cpu_vint.base = 0;
      u_cpu_vint.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cpu_vint.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cpu_vint = u_cpu_vint.real;
      offset += sizeof(this->cpu_vint);
      union {
        int16_t real;
        uint16_t base;
      } u_cpu_vaux;
      u_cpu_vaux.base = 0;
      u_cpu_vaux.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cpu_vaux.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cpu_vaux = u_cpu_vaux.real;
      offset += sizeof(this->cpu_vaux);
      union {
        int16_t real;
        uint16_t base;
      } u_cpu_temperature;
      u_cpu_temperature.base = 0;
      u_cpu_temperature.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cpu_temperature.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cpu_temperature = u_cpu_temperature.real;
      offset += sizeof(this->cpu_temperature);
      union {
        int16_t real;
        uint16_t base;
      } u_fe_temperature;
      u_fe_temperature.base = 0;
      u_fe_temperature.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fe_temperature.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->fe_temperature = u_fe_temperature.real;
      offset += sizeof(this->fe_temperature);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/DeviceMonitor_V2_3_15"; };
    const char * getMD5(){ return "54b454c5f7be4348e9710a8df0100d12"; };

  };

}
#endif