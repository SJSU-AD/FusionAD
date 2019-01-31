#ifndef _ROS_velodyne_puck_msgs_VelodynePuckPoint_h
#define _ROS_velodyne_puck_msgs_VelodynePuckPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace velodyne_puck_msgs
{

  class VelodynePuckPoint : public ros::Msg
  {
    public:
      typedef float _time_type;
      _time_type time;
      typedef double _x_type;
      _x_type x;
      typedef double _y_type;
      _y_type y;
      typedef double _z_type;
      _z_type z;
      typedef double _azimuth_type;
      _azimuth_type azimuth;
      typedef double _distance_type;
      _distance_type distance;
      typedef double _intensity_type;
      _intensity_type intensity;

    VelodynePuckPoint():
      time(0),
      x(0),
      y(0),
      z(0),
      azimuth(0),
      distance(0),
      intensity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_time;
      u_time.real = this->time;
      *(outbuffer + offset + 0) = (u_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time);
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->z);
      union {
        double real;
        uint64_t base;
      } u_azimuth;
      u_azimuth.real = this->azimuth;
      *(outbuffer + offset + 0) = (u_azimuth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_azimuth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_azimuth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_azimuth.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_azimuth.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_azimuth.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_azimuth.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_azimuth.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->azimuth);
      union {
        double real;
        uint64_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_distance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_distance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_distance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_distance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        double real;
        uint64_t base;
      } u_intensity;
      u_intensity.real = this->intensity;
      *(outbuffer + offset + 0) = (u_intensity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_intensity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_intensity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_intensity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_intensity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_intensity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_intensity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_intensity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->intensity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_time;
      u_time.base = 0;
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time = u_time.real;
      offset += sizeof(this->time);
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        double real;
        uint64_t base;
      } u_azimuth;
      u_azimuth.base = 0;
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->azimuth = u_azimuth.real;
      offset += sizeof(this->azimuth);
      union {
        double real;
        uint64_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        double real;
        uint64_t base;
      } u_intensity;
      u_intensity.base = 0;
      u_intensity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_intensity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_intensity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_intensity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_intensity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_intensity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_intensity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_intensity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->intensity = u_intensity.real;
      offset += sizeof(this->intensity);
     return offset;
    }

    const char * getType(){ return "velodyne_puck_msgs/VelodynePuckPoint"; };
    const char * getMD5(){ return "4f9dbdcdc2cb5386e16b2ab1f416979d"; };

  };

}
#endif