#ifndef STANLEY_NODE_H
#define STANLEY_NODE_H

#include "ros"


namespace fusionad
{
namespace control
{
namespace lat_controller
{
class control_node
{
  public:
    control_node();
    ~control_node();
  private:
    ros::NodeHandle control_nh;


};
}
}



#endif  