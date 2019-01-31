#ifndef _ROS_interface_Stanley_debug_h
#define _ROS_interface_Stanley_debug_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace interface
{

  class Stanley_debug : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _vehicle_Position_type;
      _vehicle_Position_type vehicle_Position;
      typedef double _vehicle_heading_type;
      _vehicle_heading_type vehicle_heading;
      typedef double _vehicle_speed_type;
      _vehicle_speed_type vehicle_speed;
      typedef double _stanleyGain_p_type;
      _stanleyGain_p_type stanleyGain_p;
      typedef double _stanleyGain_d_type;
      _stanleyGain_d_type stanleyGain_d;
      typedef double _control_loop_period_type;
      _control_loop_period_type control_loop_period;
      typedef double _CrosstrackError_type;
      _CrosstrackError_type CrosstrackError;
      typedef double _headingError_type;
      _headingError_type headingError;
      typedef double _pathHeading_type;
      _pathHeading_type pathHeading;
      typedef double _steeringAngle_type;
      _steeringAngle_type steeringAngle;
      typedef double _CrosstrackError_dot_type;
      _CrosstrackError_dot_type CrosstrackError_dot;
      typedef int32_t _pathSize_type;
      _pathSize_type pathSize;
      typedef double _distance_to_wp_type;
      _distance_to_wp_type distance_to_wp;
      typedef int32_t _currentWPIndex_type;
      _currentWPIndex_type currentWPIndex;
      typedef bool _crossTrackErrorCalcInvalid_type;
      _crossTrackErrorCalcInvalid_type crossTrackErrorCalcInvalid;
      typedef bool _headingErrorCalcInvalid_type;
      _headingErrorCalcInvalid_type headingErrorCalcInvalid;
      typedef bool _steeringAngleCalcInvalid_type;
      _steeringAngleCalcInvalid_type steeringAngleCalcInvalid;

    Stanley_debug():
      header(),
      vehicle_Position(),
      vehicle_heading(0),
      vehicle_speed(0),
      stanleyGain_p(0),
      stanleyGain_d(0),
      control_loop_period(0),
      CrosstrackError(0),
      headingError(0),
      pathHeading(0),
      steeringAngle(0),
      CrosstrackError_dot(0),
      pathSize(0),
      distance_to_wp(0),
      currentWPIndex(0),
      crossTrackErrorCalcInvalid(0),
      headingErrorCalcInvalid(0),
      steeringAngleCalcInvalid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->vehicle_Position.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_vehicle_heading;
      u_vehicle_heading.real = this->vehicle_heading;
      *(outbuffer + offset + 0) = (u_vehicle_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vehicle_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vehicle_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vehicle_heading.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vehicle_heading.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vehicle_heading.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vehicle_heading.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vehicle_heading.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vehicle_heading);
      union {
        double real;
        uint64_t base;
      } u_vehicle_speed;
      u_vehicle_speed.real = this->vehicle_speed;
      *(outbuffer + offset + 0) = (u_vehicle_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vehicle_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vehicle_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vehicle_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vehicle_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vehicle_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vehicle_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vehicle_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vehicle_speed);
      union {
        double real;
        uint64_t base;
      } u_stanleyGain_p;
      u_stanleyGain_p.real = this->stanleyGain_p;
      *(outbuffer + offset + 0) = (u_stanleyGain_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stanleyGain_p.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stanleyGain_p.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stanleyGain_p.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_stanleyGain_p.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_stanleyGain_p.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_stanleyGain_p.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_stanleyGain_p.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->stanleyGain_p);
      union {
        double real;
        uint64_t base;
      } u_stanleyGain_d;
      u_stanleyGain_d.real = this->stanleyGain_d;
      *(outbuffer + offset + 0) = (u_stanleyGain_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stanleyGain_d.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stanleyGain_d.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stanleyGain_d.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_stanleyGain_d.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_stanleyGain_d.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_stanleyGain_d.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_stanleyGain_d.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->stanleyGain_d);
      union {
        double real;
        uint64_t base;
      } u_control_loop_period;
      u_control_loop_period.real = this->control_loop_period;
      *(outbuffer + offset + 0) = (u_control_loop_period.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_control_loop_period.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_control_loop_period.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_control_loop_period.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_control_loop_period.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_control_loop_period.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_control_loop_period.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_control_loop_period.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->control_loop_period);
      union {
        double real;
        uint64_t base;
      } u_CrosstrackError;
      u_CrosstrackError.real = this->CrosstrackError;
      *(outbuffer + offset + 0) = (u_CrosstrackError.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_CrosstrackError.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_CrosstrackError.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_CrosstrackError.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_CrosstrackError.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_CrosstrackError.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_CrosstrackError.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_CrosstrackError.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->CrosstrackError);
      union {
        double real;
        uint64_t base;
      } u_headingError;
      u_headingError.real = this->headingError;
      *(outbuffer + offset + 0) = (u_headingError.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_headingError.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_headingError.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_headingError.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_headingError.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_headingError.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_headingError.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_headingError.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->headingError);
      union {
        double real;
        uint64_t base;
      } u_pathHeading;
      u_pathHeading.real = this->pathHeading;
      *(outbuffer + offset + 0) = (u_pathHeading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pathHeading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pathHeading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pathHeading.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pathHeading.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pathHeading.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pathHeading.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pathHeading.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pathHeading);
      union {
        double real;
        uint64_t base;
      } u_steeringAngle;
      u_steeringAngle.real = this->steeringAngle;
      *(outbuffer + offset + 0) = (u_steeringAngle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steeringAngle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steeringAngle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steeringAngle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_steeringAngle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_steeringAngle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_steeringAngle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_steeringAngle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->steeringAngle);
      union {
        double real;
        uint64_t base;
      } u_CrosstrackError_dot;
      u_CrosstrackError_dot.real = this->CrosstrackError_dot;
      *(outbuffer + offset + 0) = (u_CrosstrackError_dot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_CrosstrackError_dot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_CrosstrackError_dot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_CrosstrackError_dot.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_CrosstrackError_dot.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_CrosstrackError_dot.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_CrosstrackError_dot.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_CrosstrackError_dot.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->CrosstrackError_dot);
      union {
        int32_t real;
        uint32_t base;
      } u_pathSize;
      u_pathSize.real = this->pathSize;
      *(outbuffer + offset + 0) = (u_pathSize.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pathSize.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pathSize.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pathSize.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pathSize);
      union {
        double real;
        uint64_t base;
      } u_distance_to_wp;
      u_distance_to_wp.real = this->distance_to_wp;
      *(outbuffer + offset + 0) = (u_distance_to_wp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_to_wp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_to_wp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_to_wp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_distance_to_wp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_distance_to_wp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_distance_to_wp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_distance_to_wp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->distance_to_wp);
      union {
        int32_t real;
        uint32_t base;
      } u_currentWPIndex;
      u_currentWPIndex.real = this->currentWPIndex;
      *(outbuffer + offset + 0) = (u_currentWPIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currentWPIndex.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currentWPIndex.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currentWPIndex.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->currentWPIndex);
      union {
        bool real;
        uint8_t base;
      } u_crossTrackErrorCalcInvalid;
      u_crossTrackErrorCalcInvalid.real = this->crossTrackErrorCalcInvalid;
      *(outbuffer + offset + 0) = (u_crossTrackErrorCalcInvalid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->crossTrackErrorCalcInvalid);
      union {
        bool real;
        uint8_t base;
      } u_headingErrorCalcInvalid;
      u_headingErrorCalcInvalid.real = this->headingErrorCalcInvalid;
      *(outbuffer + offset + 0) = (u_headingErrorCalcInvalid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headingErrorCalcInvalid);
      union {
        bool real;
        uint8_t base;
      } u_steeringAngleCalcInvalid;
      u_steeringAngleCalcInvalid.real = this->steeringAngleCalcInvalid;
      *(outbuffer + offset + 0) = (u_steeringAngleCalcInvalid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steeringAngleCalcInvalid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->vehicle_Position.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_vehicle_heading;
      u_vehicle_heading.base = 0;
      u_vehicle_heading.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vehicle_heading.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vehicle_heading.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vehicle_heading.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vehicle_heading.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vehicle_heading.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vehicle_heading.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vehicle_heading.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vehicle_heading = u_vehicle_heading.real;
      offset += sizeof(this->vehicle_heading);
      union {
        double real;
        uint64_t base;
      } u_vehicle_speed;
      u_vehicle_speed.base = 0;
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vehicle_speed = u_vehicle_speed.real;
      offset += sizeof(this->vehicle_speed);
      union {
        double real;
        uint64_t base;
      } u_stanleyGain_p;
      u_stanleyGain_p.base = 0;
      u_stanleyGain_p.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stanleyGain_p.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stanleyGain_p.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stanleyGain_p.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_stanleyGain_p.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_stanleyGain_p.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_stanleyGain_p.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_stanleyGain_p.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->stanleyGain_p = u_stanleyGain_p.real;
      offset += sizeof(this->stanleyGain_p);
      union {
        double real;
        uint64_t base;
      } u_stanleyGain_d;
      u_stanleyGain_d.base = 0;
      u_stanleyGain_d.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stanleyGain_d.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stanleyGain_d.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stanleyGain_d.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_stanleyGain_d.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_stanleyGain_d.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_stanleyGain_d.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_stanleyGain_d.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->stanleyGain_d = u_stanleyGain_d.real;
      offset += sizeof(this->stanleyGain_d);
      union {
        double real;
        uint64_t base;
      } u_control_loop_period;
      u_control_loop_period.base = 0;
      u_control_loop_period.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_control_loop_period.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_control_loop_period.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_control_loop_period.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_control_loop_period.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_control_loop_period.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_control_loop_period.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_control_loop_period.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->control_loop_period = u_control_loop_period.real;
      offset += sizeof(this->control_loop_period);
      union {
        double real;
        uint64_t base;
      } u_CrosstrackError;
      u_CrosstrackError.base = 0;
      u_CrosstrackError.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_CrosstrackError.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_CrosstrackError.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_CrosstrackError.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_CrosstrackError.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_CrosstrackError.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_CrosstrackError.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_CrosstrackError.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->CrosstrackError = u_CrosstrackError.real;
      offset += sizeof(this->CrosstrackError);
      union {
        double real;
        uint64_t base;
      } u_headingError;
      u_headingError.base = 0;
      u_headingError.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_headingError.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_headingError.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_headingError.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_headingError.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_headingError.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_headingError.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_headingError.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->headingError = u_headingError.real;
      offset += sizeof(this->headingError);
      union {
        double real;
        uint64_t base;
      } u_pathHeading;
      u_pathHeading.base = 0;
      u_pathHeading.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pathHeading.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pathHeading.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pathHeading.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pathHeading.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pathHeading.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pathHeading.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pathHeading.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pathHeading = u_pathHeading.real;
      offset += sizeof(this->pathHeading);
      union {
        double real;
        uint64_t base;
      } u_steeringAngle;
      u_steeringAngle.base = 0;
      u_steeringAngle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steeringAngle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steeringAngle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steeringAngle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_steeringAngle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_steeringAngle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_steeringAngle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_steeringAngle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->steeringAngle = u_steeringAngle.real;
      offset += sizeof(this->steeringAngle);
      union {
        double real;
        uint64_t base;
      } u_CrosstrackError_dot;
      u_CrosstrackError_dot.base = 0;
      u_CrosstrackError_dot.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_CrosstrackError_dot.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_CrosstrackError_dot.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_CrosstrackError_dot.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_CrosstrackError_dot.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_CrosstrackError_dot.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_CrosstrackError_dot.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_CrosstrackError_dot.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->CrosstrackError_dot = u_CrosstrackError_dot.real;
      offset += sizeof(this->CrosstrackError_dot);
      union {
        int32_t real;
        uint32_t base;
      } u_pathSize;
      u_pathSize.base = 0;
      u_pathSize.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pathSize.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pathSize.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pathSize.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pathSize = u_pathSize.real;
      offset += sizeof(this->pathSize);
      union {
        double real;
        uint64_t base;
      } u_distance_to_wp;
      u_distance_to_wp.base = 0;
      u_distance_to_wp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_to_wp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_to_wp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_to_wp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_distance_to_wp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_distance_to_wp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_distance_to_wp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_distance_to_wp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->distance_to_wp = u_distance_to_wp.real;
      offset += sizeof(this->distance_to_wp);
      union {
        int32_t real;
        uint32_t base;
      } u_currentWPIndex;
      u_currentWPIndex.base = 0;
      u_currentWPIndex.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_currentWPIndex.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_currentWPIndex.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_currentWPIndex.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->currentWPIndex = u_currentWPIndex.real;
      offset += sizeof(this->currentWPIndex);
      union {
        bool real;
        uint8_t base;
      } u_crossTrackErrorCalcInvalid;
      u_crossTrackErrorCalcInvalid.base = 0;
      u_crossTrackErrorCalcInvalid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->crossTrackErrorCalcInvalid = u_crossTrackErrorCalcInvalid.real;
      offset += sizeof(this->crossTrackErrorCalcInvalid);
      union {
        bool real;
        uint8_t base;
      } u_headingErrorCalcInvalid;
      u_headingErrorCalcInvalid.base = 0;
      u_headingErrorCalcInvalid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->headingErrorCalcInvalid = u_headingErrorCalcInvalid.real;
      offset += sizeof(this->headingErrorCalcInvalid);
      union {
        bool real;
        uint8_t base;
      } u_steeringAngleCalcInvalid;
      u_steeringAngleCalcInvalid.base = 0;
      u_steeringAngleCalcInvalid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->steeringAngleCalcInvalid = u_steeringAngleCalcInvalid.real;
      offset += sizeof(this->steeringAngleCalcInvalid);
     return offset;
    }

    const char * getType(){ return "interface/Stanley_debug"; };
    const char * getMD5(){ return "f77a66d1ad539af8dd29531c5054c480"; };

  };

}
#endif