#ifndef _ROS_SERVICE_gen_twist_covar_srv_h
#define _ROS_SERVICE_gen_twist_covar_srv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace covar
{

static const char GEN_TWIST_COVAR_SRV[] = "covar/gen_twist_covar_srv";

  class gen_twist_covar_srvRequest : public ros::Msg
  {
    public:
      typedef uint8_t _twist_sample_limit_type;
      _twist_sample_limit_type twist_sample_limit;

    gen_twist_covar_srvRequest():
      twist_sample_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->twist_sample_limit >> (8 * 0)) & 0xFF;
      offset += sizeof(this->twist_sample_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->twist_sample_limit =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->twist_sample_limit);
     return offset;
    }

    const char * getType(){ return GEN_TWIST_COVAR_SRV; };
    const char * getMD5(){ return "1351aa841cd716c8a63cc8daa557be0a"; };

  };

  class gen_twist_covar_srvResponse : public ros::Msg
  {
    public:
      typedef uint8_t _ack_type;
      _ack_type ack;

    gen_twist_covar_srvResponse():
      ack(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ack >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ack);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->ack =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ack);
     return offset;
    }

    const char * getType(){ return GEN_TWIST_COVAR_SRV; };
    const char * getMD5(){ return "42183b41820ee2706b0f1af935a4a359"; };

  };

  class gen_twist_covar_srv {
    public:
    typedef gen_twist_covar_srvRequest Request;
    typedef gen_twist_covar_srvResponse Response;
  };

}
#endif
