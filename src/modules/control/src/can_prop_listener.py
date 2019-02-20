#!/usr/bin/env python
"""
Monitors the CAN Network messages and parses the drive switch (gear selection) as well as the propulsion potentiometer

Only look at byte 4 from the switch 

Publisher
---------
Topic: /control/controlcmd
    Msg: interface/Controlcmd
"""
import rospy
import can
import os
import struct
from interface.msg import Controlcmd

class CanListener(object):
    """Parses CAN steering and torque feedback messages and publishes the steering messages"""
    def __init__(self):
        rospy.init_node('can_listener', anonymous = True)

        # initializing the buses to channel 0 and bustype 'socketcan_ctypes'        
        self.prop_pot_bus = can.interface.Bus(channel='can0', bustype='socketcan_ctypes')
        self.switch_mode_bus = can.interface.Bus(channel='can0', bustype='socketcan_ctypes')

        # create the filters for the CAN network
        prop_pot_filter = [{"can_id":0x284, "can_mask":0x1FFFFFFF, "extended":False}]
        switch_mode_filter = [{"can_id":0x384, "can_mask":0x1FFFFFFF, "extended":False}]

        self.prop_pot_bus.set_filters(prop_pot_filter)
        self.switch_mode_bus.set_filters(switch_mode_filter)

        # initialize controlcmd message
        self.controlCommand = Controlcmd()

        self.switch_data = 0

        # declare publisher for steering feedback
        self.throttleDesiredPub = rospy.Publisher("/control/controlcmd", Controlcmd, queue_size = 100)

        self.main()

    def pot_feedback_conversion(self):
        """Function to convert the data from the pot message from bits to throttle desired"""
        
        pot_msg = self.prop_pot_bus.recv(0.1)
        switch_msg = self.switch_mode_bus.recv(0.1)

        # Parameters for mapping from pot message to desired throttle percentage
        input_max = 0x11AF
        input_min = 0x023F
        
        output_max = 100
        output_min = 0

        if(switch_msg is not None):
            self.switch_data = self.bytearray_to_float(4, 5, switch_msg.data)
        
        if(pot_msg is not None):
            throttle_data = self.bytearray_to_float(0, 1, pot_msg.data)
            
            self.controlCommand.throttle = (throttle_data - input_min) * (output_max - output_min) / (input_max - input_min) + output_min

            if(self.switch_data == 0) or (self.switch_data == 8):
                self.controlCommand.throttle = 0

            if(self.switch_data == 2) or (self.switch_data == 10):
                self.controlCommand.throttle = (-1) * self.controlCommand.throttle

            self.throttleDesiredPub.publish(self.controlCommand)

    def bytearray_to_float(self, first_byte, last_byte, input_message):
        new_data = struct.unpack('h', input_message[first_byte:(last_byte+1)])
        return new_data[0]

    def main(self):
        while not rospy.is_shutdown():
            self.pot_feedback_conversion()

if __name__ == '__main__':
    try:
        CanListener()
    except rospy.ROSInterruptException:
        pass
