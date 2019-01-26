#ifndef _ROS_interface_Tf_rotate_h
#define _ROS_interface_Tf_rotate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/TwistWithCovarianceStamped.h"
#include "geometry_msgs/AccelWithCovarianceStamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

namespace interface
{

  class Tf_rotate : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::TwistWithCovarianceStamped _twistStampCovar_type;
      _twistStampCovar_type twistStampCovar;
      typedef geometry_msgs::AccelWithCovarianceStamped _accelStampCovar_type;
      _accelStampCovar_type accelStampCovar;
      typedef geometry_msgs::PoseWithCovarianceStamped _poseStampCovar_type;
      _poseStampCovar_type poseStampCovar;
      typedef double _yaw_type;
      _yaw_type yaw;

    Tf_rotate():
      header(),
      twistStampCovar(),
      accelStampCovar(),
      poseStampCovar(),
      yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->twistStampCovar.serialize(outbuffer + offset);
      offset += this->accelStampCovar.serialize(outbuffer + offset);
      offset += this->poseStampCovar.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_yaw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_yaw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_yaw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_yaw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->twistStampCovar.deserialize(inbuffer + offset);
      offset += this->accelStampCovar.deserialize(inbuffer + offset);
      offset += this->poseStampCovar.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
     return offset;
    }

    const char * getType(){ return "interface/Tf_rotate"; };
    const char * getMD5(){ return "4588ca6c7be7ef877d3a7a9a83f5fc10"; };

  };

}
#endif