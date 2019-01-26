#ifndef _ROS_nmea_msgs_Gprmc_h
#define _ROS_nmea_msgs_Gprmc_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace nmea_msgs
{

  class Gprmc : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _message_id_type;
      _message_id_type message_id;
      typedef double _utc_seconds_type;
      _utc_seconds_type utc_seconds;
      typedef const char* _position_status_type;
      _position_status_type position_status;
      typedef double _lat_type;
      _lat_type lat;
      typedef double _lon_type;
      _lon_type lon;
      typedef const char* _lat_dir_type;
      _lat_dir_type lat_dir;
      typedef const char* _lon_dir_type;
      _lon_dir_type lon_dir;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _track_type;
      _track_type track;
      typedef const char* _date_type;
      _date_type date;
      typedef float _mag_var_type;
      _mag_var_type mag_var;
      typedef const char* _mag_var_direction_type;
      _mag_var_direction_type mag_var_direction;
      typedef const char* _mode_indicator_type;
      _mode_indicator_type mode_indicator;

    Gprmc():
      header(),
      message_id(""),
      utc_seconds(0),
      position_status(""),
      lat(0),
      lon(0),
      lat_dir(""),
      lon_dir(""),
      speed(0),
      track(0),
      date(""),
      mag_var(0),
      mag_var_direction(""),
      mode_indicator("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_message_id = strlen(this->message_id);
      varToArr(outbuffer + offset, length_message_id);
      offset += 4;
      memcpy(outbuffer + offset, this->message_id, length_message_id);
      offset += length_message_id;
      union {
        double real;
        uint64_t base;
      } u_utc_seconds;
      u_utc_seconds.real = this->utc_seconds;
      *(outbuffer + offset + 0) = (u_utc_seconds.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_utc_seconds.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_utc_seconds.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_utc_seconds.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_utc_seconds.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_utc_seconds.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_utc_seconds.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_utc_seconds.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->utc_seconds);
      uint32_t length_position_status = strlen(this->position_status);
      varToArr(outbuffer + offset, length_position_status);
      offset += 4;
      memcpy(outbuffer + offset, this->position_status, length_position_status);
      offset += length_position_status;
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
      uint32_t length_lat_dir = strlen(this->lat_dir);
      varToArr(outbuffer + offset, length_lat_dir);
      offset += 4;
      memcpy(outbuffer + offset, this->lat_dir, length_lat_dir);
      offset += length_lat_dir;
      uint32_t length_lon_dir = strlen(this->lon_dir);
      varToArr(outbuffer + offset, length_lon_dir);
      offset += 4;
      memcpy(outbuffer + offset, this->lon_dir, length_lon_dir);
      offset += length_lon_dir;
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_track;
      u_track.real = this->track;
      *(outbuffer + offset + 0) = (u_track.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_track.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_track.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_track.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track);
      uint32_t length_date = strlen(this->date);
      varToArr(outbuffer + offset, length_date);
      offset += 4;
      memcpy(outbuffer + offset, this->date, length_date);
      offset += length_date;
      union {
        float real;
        uint32_t base;
      } u_mag_var;
      u_mag_var.real = this->mag_var;
      *(outbuffer + offset + 0) = (u_mag_var.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mag_var.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mag_var.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mag_var.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mag_var);
      uint32_t length_mag_var_direction = strlen(this->mag_var_direction);
      varToArr(outbuffer + offset, length_mag_var_direction);
      offset += 4;
      memcpy(outbuffer + offset, this->mag_var_direction, length_mag_var_direction);
      offset += length_mag_var_direction;
      uint32_t length_mode_indicator = strlen(this->mode_indicator);
      varToArr(outbuffer + offset, length_mode_indicator);
      offset += 4;
      memcpy(outbuffer + offset, this->mode_indicator, length_mode_indicator);
      offset += length_mode_indicator;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_message_id;
      arrToVar(length_message_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message_id-1]=0;
      this->message_id = (char *)(inbuffer + offset-1);
      offset += length_message_id;
      union {
        double real;
        uint64_t base;
      } u_utc_seconds;
      u_utc_seconds.base = 0;
      u_utc_seconds.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_utc_seconds.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_utc_seconds.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_utc_seconds.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_utc_seconds.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_utc_seconds.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_utc_seconds.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_utc_seconds.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->utc_seconds = u_utc_seconds.real;
      offset += sizeof(this->utc_seconds);
      uint32_t length_position_status;
      arrToVar(length_position_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_position_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_position_status-1]=0;
      this->position_status = (char *)(inbuffer + offset-1);
      offset += length_position_status;
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
      uint32_t length_lat_dir;
      arrToVar(length_lat_dir, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lat_dir; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lat_dir-1]=0;
      this->lat_dir = (char *)(inbuffer + offset-1);
      offset += length_lat_dir;
      uint32_t length_lon_dir;
      arrToVar(length_lon_dir, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lon_dir; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lon_dir-1]=0;
      this->lon_dir = (char *)(inbuffer + offset-1);
      offset += length_lon_dir;
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_track;
      u_track.base = 0;
      u_track.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_track.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_track.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_track.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->track = u_track.real;
      offset += sizeof(this->track);
      uint32_t length_date;
      arrToVar(length_date, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_date; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_date-1]=0;
      this->date = (char *)(inbuffer + offset-1);
      offset += length_date;
      union {
        float real;
        uint32_t base;
      } u_mag_var;
      u_mag_var.base = 0;
      u_mag_var.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mag_var.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mag_var.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mag_var.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mag_var = u_mag_var.real;
      offset += sizeof(this->mag_var);
      uint32_t length_mag_var_direction;
      arrToVar(length_mag_var_direction, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mag_var_direction; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mag_var_direction-1]=0;
      this->mag_var_direction = (char *)(inbuffer + offset-1);
      offset += length_mag_var_direction;
      uint32_t length_mode_indicator;
      arrToVar(length_mode_indicator, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mode_indicator; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mode_indicator-1]=0;
      this->mode_indicator = (char *)(inbuffer + offset-1);
      offset += length_mode_indicator;
     return offset;
    }

    const char * getType(){ return "nmea_msgs/Gprmc"; };
    const char * getMD5(){ return "02533bac67f17457b2e3538525ba1aae"; };

  };

}
#endif