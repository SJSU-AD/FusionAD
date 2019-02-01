#ifndef CAN_ARDU_INTERFACE_H
#define CAN_ARDU_INTERFACE_H

#include "ros/ros.h"
#include "interface/Can_Interface.h"
#include "interface/Controlcmd.h"

namespace fusionad
{
namespace control
{
namespace can_ardu_interface_node
{
class CanArduInterfaceNode
{
    public:
        CanArduInterfaceNode();
        ~CanArduInterfaceNode();
        void initRosComm();
    
    private:
        // initializing the nodehandle
        ros::NodeHandle caninterfacenode_nh;

        // initialize publisher
        ros::Publisher can_msg_pub;

        // initialize subscriber
        ros::Subscriber high_lvl_sub;
        
        // declare callbacks
        void controlCallback(const interface::Controlcmd& control_msg);
        
        // declare functions
        float steering_desired_to_can(float steering_desired);
        float throttle_desired_to_can(float throttle_desired);

}; // CanArduInterfaceNode
}  // can_ardu_interface_node
}  // control
}  // fusionad
#endif CAN_ARDU_INTERFACE_H
