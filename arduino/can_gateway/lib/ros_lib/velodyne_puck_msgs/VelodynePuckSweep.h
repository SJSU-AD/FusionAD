#ifndef _ROS_velodyne_puck_msgs_VelodynePuckSweep_h
#define _ROS_velodyne_puck_msgs_VelodynePuckSweep_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "velodyne_puck_msgs/VelodynePuckScan.h"

namespace velodyne_puck_msgs
{

  class VelodynePuckSweep : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      velodyne_puck_msgs::VelodynePuckScan scans[16];

    VelodynePuckSweep():
      header(),
      scans()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      offset += this->scans[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      offset += this->scans[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "velodyne_puck_msgs/VelodynePuckSweep"; };
    const char * getMD5(){ return "e0395900ded93e728803e208b8b88005"; };

  };

}
#endif