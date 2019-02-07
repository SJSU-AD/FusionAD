#include "control/can_ardu_interface.h"

namespace fusionad
{
namespace control
{
namespace can_ardu_interface_node
{
    CanArduInterfaceNode::CanArduInterfaceNode()
    {}

    CanArduInterfaceNode::~CanArduInterfaceNode()
    {}

    void CanArduInterfaceNode::initRosComm()
    {
        // publisher for can messages
        can_msg_pub = caninterfacenode_nh.advertise<interface::Can_Interface>("/control/can_controlcmd", 25);

        // high lvl control subscriber
        high_lvl_sub = caninterfacenode_nh.subscribe("/control/controlcmd", 25, &CanArduInterfaceNode::controlCallback, this);
    }

    void CanArduInterfaceNode::controlCallback(const interface::Controlcmd& control_msg)
    {
        // left turn
        float positive_steering_slope = 0.2224731787;
        
        // right turn
        float negative_steering_slope = 0.2733129308;

        float remapped_steering_input;

        // remapping the steering input
        if(control_msg.steeringAngle >= 0)
        {
            remapped_steering_input = control_msg.steeringAngle/positive_steering_slope;
        }
        else
        {
            remapped_steering_input = control_msg.steeringAngle/negative_steering_slope;
        }
        
        interface::Can_Interface can_interface_msg;

        // function for calculating steering msg
        can_interface_msg.steering_can_data = steering_desired_to_can(remapped_steering_input);
        
        // function for calculating throttle msg
        can_interface_msg.propulsion_can_data = throttle_desired_to_can(control_msg.throttle);
        
        // publish the can interface msg
        can_msg_pub.publish(can_interface_msg);   
    }

    float CanArduInterfaceNode::steering_desired_to_can(float steering_desired)
    {
        byte steering_data[8] = {0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00};

        int pos_full_lock = 0x00180000;
        int zero_full_lock = 0x00000000;

        // steering limits which are determined experimentally
        // maximum number of radians (positive)
        float max_angle = 1.4833248751;
        float zero_angle = 0;
        float neg_angle = -1.2074071982;

        if(steering_desired > max_angle)
        {
            steering_desired = max_angle;
        }
        if(steering_desired < neg_angle)
        {
            steering_desired = neg_angle;
        }

        if((steering_desired <= max_angle) and (steering_desired >= neg_angle))
        {
            float steering_map = ((-1)*steering_input-zero_angle)*(pos_full_lock-zero_full_lock)/(max_angle-zero_angle)+zero_full_lock;
            
        }
    }

    float CanArduInterfaceNode::throttle_desired_to_can(float throttle_desired)
    {

    }
} // can_ardu_interface_node
} // control
} // fusionad
