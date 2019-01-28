#ifndef _ROS_interface_Controlcmd_h
#define _ROS_interface_Controlcmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace interface
{

  class Controlcmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _debugControl_type;
      _debugControl_type debugControl;
      typedef bool _inOperation_type;
      _inOperation_type inOperation;
      typedef double _steeringAngle_type;
      _steeringAngle_type steeringAngle;
      typedef double _throttle_type;
      _throttle_type throttle;

    Controlcmd():
      header(),
      debugControl(0),
      inOperation(0),
      steeringAngle(0),
      throttle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_debugControl;
      u_debugControl.real = this->debugControl;
      *(outbuffer + offset + 0) = (u_debugControl.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->debugControl);
      union {
        bool real;
        uint8_t base;
      } u_inOperation;
      u_inOperation.real = this->inOperation;
      *(outbuffer + offset + 0) = (u_inOperation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->inOperation);
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
      } u_throttle;
      u_throttle.real = this->throttle;
      *(outbuffer + offset + 0) = (u_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_throttle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_throttle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_throttle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_throttle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->throttle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_debugControl;
      u_debugControl.base = 0;
      u_debugControl.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->debugControl = u_debugControl.real;
      offset += sizeof(this->debugControl);
      union {
        bool real;
        uint8_t base;
      } u_inOperation;
      u_inOperation.base = 0;
      u_inOperation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->inOperation = u_inOperation.real;
      offset += sizeof(this->inOperation);
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
      } u_throttle;
      u_throttle.base = 0;
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->throttle = u_throttle.real;
      offset += sizeof(this->throttle);
     return offset;
    }

    const char * getType(){ return "interface/Controlcmd"; };
    const char * getMD5(){ return "4efea77d816a7047e6e034ed24214648"; };

  };

}
#endif