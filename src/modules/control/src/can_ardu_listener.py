#!/usr/bin/env python
"""
Monitors the CAN Network messages and parses the steering encoder and torque feedback messages

Publisher
---------
Topic: /control/steering_response
    Msg: std_msgs/float64
"""
import rospy
import can
import os
import struct
from interface.msg import Controlcmd
from interface.msg import Can_Interface

class CanListener(object):
    """Parses CAN steering and torque feedback messages and publishes the steering messages"""
    def __init__(self):
        # initialize controlcmd message
        self.feedback_msg = Controlcmd()

        # declare publisher for steering feedback
        self.steeringFeedbackPub = rospy.Publisher("/control/steering_response", Controlcmd, queue_size = 100)

    def steering_callback(self, Can_Interface):
        """Callback handler from the CAN Arduino Gateway"""
        self.steering_feedback_conversion(Can_Interface.steering_can_data)

    def steering_feedback_conversion(self, input_can_msg):
        """Function to convert the data from the steering message from bits to revolutions"""
        # steering conversion in rev/bit
        steering_conversion = -0.00000095367431640625 
        negative_steering_slope = 0.2733129308
        positive_steering_slope = 0.2224731787

        print(input_can_msg)
        unpacked_steering_data = self.bytearray_to_float(2, 5, input_can_msg)
        self.feedback_msg.steeringAngle = unpacked_steering_data * steering_conversion
        
        if(self.feedback_msg.steeringAngle <= 0):
            self.feedback_msg.steeringAngle = self.feedback_msg.steeringAngle * negative_steering_slope
        else:
            self.feedback_msg.steeringAngle = self.feedback_msg.steeringAngle * positive_steering_slope

        self.steeringFeedbackPub.publish(self.feedback_msg)  
    
    def bytearray_to_float(self, first_byte, last_byte, input_message):
        new_data = struct.unpack('i', input_message[first_byte:(last_byte+1)])
        return new_data[0]

    def can_data_converter(self):
        """Take the CAN steering data, convert to radians, republish"""
        rospy.Subscriber("/control/can_controlcmd", Can_Interface, self.steering_callback)
        rospy.spin()

def main():
    rospy.init_node("can_ardu_listener_node", anonymous=False)
    canConverter = CanListener()

    try:
        canConverter.can_data_converter()
    except rospy.ROSInterruptException:
        pass

if __name__ == '__main__':
    main()
