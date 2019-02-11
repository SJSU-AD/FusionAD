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
from interface.msg import Chassis_state

class CanListener(object):
    """Parses CAN steering and torque feedback messages and publishes the steering messages"""
    def __init__(self):
        rospy.init_node('can_listener', anonymous = True)
        
        # establishing the CAN connection and setting bitrate to 250 kbps
        # os.system('sudo /sbin/ip link set can0 up type can bitrate 250000')

        # initializing the buses to channel 0 and bustype 'socketcan_ctypes'
        self.steering_sensor_bus = can.interface.Bus(channel='can0', bustype='socketcan_ctypes')
        # self.torque_sensor_bus = can.interface.Bus(channel='can0', bustype='socketcan_ctypes')
        
        # create the filters for the CAN network
        steering_filter = [{"can_id":0x18FF0113, "can_mask":0x1FFFFFFF, "extended":True}]
        # steering_filter = [{"can_id":0x18FF00F9, "can_mask":0x1FFFFFFF, "extended":True}]
        # torque_filter = [{"can_id":0x18FF0313, "can_mask":0x1FFFFFFF, "extended":True}]

        self.steering_sensor_bus.set_filters(steering_filter)
        # self.torque_sensor_bus.set_filters(torque_filter)

        # # initialize masker
        # self.MASKER = 0xFF

        # initialize controlcmd message
        self.feedback_msg = Controlcmd()
        
        # amount of input torque for manual takeover in [N*m]
        self.manual_takeover_threshold = 15

        # declare publisher for steering feedback
        self.steeringFeedbackPub = rospy.Publisher("/control/steering_response", Controlcmd, queue_size = 100)
        # self.manualTakeoverPub = rospy.Publisher("/control/autonomous_status", Chassis_state, queue_size = 100)

        self.main()

    def steering_feedback_conversion(self):
        """Function to convert the data from the steering message from bits to revolutions"""
        # steering conversion in rev/bit
        steering_conversion = -0.00000095367431640625 
        negative_steering_slope = 0.2733129308
        positive_steering_slope = 0.2224731787
        # read the steering message every 0.1 seconds
        steering_msg = self.steering_sensor_bus.recv(0.1)
        if(steering_msg is not None):
            unpacked_steering_data = self.bytearray_to_float(2, 5, steering_msg.data)
            self.feedback_msg.steeringAngle = unpacked_steering_data * steering_conversion
            
            if(self.feedback_msg.steeringAngle <= 0):
                self.feedback_msg.steeringAngle = self.feedback_msg.steeringAngle * negative_steering_slope
            else:
                self.feedback_msg.steeringAngle = self.feedback_msg.steeringAngle * positive_steering_slope

            self.steeringFeedbackPub.publish(self.feedback_msg)  

    # def torque_feedback_conversion(self):
    #     """Function to convert the data from the input torque message from bits to N*m"""
    #     # torque conversionb in N*m/bit
    #     torque_conversion = 0.00000095367431640625
    #     # read the torque message every 0.01 seconds
    #     torque_msg = self.torque_sensor_bus.recv(0.01)

    #     if(torque_msg is not None):
    #         unpacked_torque_data = self.bytearray_to_float(0, 3, torque_msg.data)
    #         input_torque = unpacked_torque_data * torque_conversion
    #         if(input_torque >= self.manual_takeover_threshold):
    #             manual_takeover_msg = Chassis_state()
    #             manual_takeover_msg.inAutonomousMode = False
    #             self.manualTakeoverPub.publish(manual_takeover_msg)
    
    def bytearray_to_float(self, first_byte, last_byte, input_message):
        new_data = struct.unpack('i', input_message[first_byte:(last_byte+1)])
        return new_data[0]

    def main(self):
        while not rospy.is_shutdown():
            self.steering_feedback_conversion()
            # self.torque_feedback_conversion()

if __name__ == '__main__':
    try:
        CanListener()
    except rospy.ROSInterruptException:
        pass
