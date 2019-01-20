#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Joy
import time
import threading
import can
import os

####################
## Multithreading ##
####################

class ThreadCAN(object):
    """Multithreading approach to timing"""
    def __init__(self):
        rospy.init_node('Can_Bus_Node', anonymous = True)
        # # establishing the CAN connection and setting bitrate to 250 kbps
        # os.system('sudo /sbin/ip link set can0 up type can bitrate 250000')
        # initializing the bus to channel 0 and bustype 'socketcan_ctypes'
        self.bus = can.interface.Bus(channel='vcan0', bustype='socketcan_ctypes')

        rospy.Subscriber('/joy', Joy, self.joyCallback, queue_size = 100)
        
        self.joy_steering_input = 0
        self.joy_braking_input = 0
        self.joy_prop_input = 0
        self.safety_switch = 0

        self.next_call = time.time()
        self.control_ready = False
        self.power_cycle_completed = False
        self.power_message_counter = 0
        self.POWER_CYCLE_MSG_COUNT = 100

        #####################
        ## Arbitration IDs ##
        #####################
        self.steering_arbitration_id = 0x18FF00F9
        self.braking_arbitration_id = 0xFF0000
        # propulsion power request arbitration id
        self.power_arbitration_id = 0x204
        # arbitration id for commanding the motor
        self.prop_arbitration_id = 0x304

        # mask for hex messages
        self.MASKER = 0xFF

        ##################
        ## CAN Messages ##
        ##################
        # 8 byte message for moving the steering motor
        self.steering_data = [0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00]
        # 8 byte message for zeroing the steering
        self.zero_steering_data = [0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]

        # 8 byte message for stopping the propulsion motor
        self.zero_prop_data = [0x00, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00]
        # 8 byte message for requesting power to the propulsion motor
        self.power_request_data = [0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
        # 8 byte message for moving the prop motor @ 511 rpm
        self.prop_data = [0x00, 0x00, 0xFF, 0x7F, 0x00, 0x0D, 0x00, 0x00]
        # 8 byte message for moving the linear actuator
        '''
        NOTE: byte #3 (0-7) contains a nibble 
            The first bit, C must stay present
            The math is done with byte #2 and the other nibble of byte #3
        '''
        self.braking_data = [0x0F, 0x4A, 0xF4, 0xC1, 0x00, 0x00, 0x00, 0x00]
        # 8 byte message for zeroing the linear actuator
        self.zero_braking_data = [0x7E, 0x02, 0x12, 0x34, 0x56, 0xAB, 0xCD, 0xEF]

        self.power_msg = can.Message(arbitration_id = self.power_arbitration_id, data = self.power_request_data, extended_id = False)
        self.zero_control_msg = can.Message(arbitration_id = self.prop_arbitration_id, data = self.zero_prop_data, extended_id = False)
        self.zero_steering_msg = can.Message(arbitration_id = self.steering_arbitration_id, data = self.zero_steering_data, extended_id = True)
        self.zero_braking_msg = can.Message(arbitration_id = self.braking_arbitration_id, data = self.zero_braking_data, extended_id = True)
        
        self.main()

    def joyCallback(self, joy_msg):
        # declaring the steering axis on the joy node
        STEERING_AXIS = 0
        # declaring the braking button on the joy node
        BRAKING_BUTTON = 6
        # declaring the propulsion axis on the joy node
        PROP_AXIS = 4
        # declaring the safety button
        SAFETY_BUTTON = 5

        self.joy_steering_input = joy_msg.axes[STEERING_AXIS]
        self.joy_braking_input = joy_msg.buttons[BRAKING_BUTTON]
        self.joy_prop_input = joy_msg.axes[PROP_AXIS]
        self.safety_switch = joy_msg.buttons[SAFETY_BUTTON]

    def send_power_msg(self):
        """Send the power message (heartbeat) to the SME motor controller"""
        if (self.power_message_counter == 0):
            self.next_call += 0.1
        else:
            self.next_call += 0.05

        self.send_power_thread = threading.Timer(self.next_call-time.time(), self.send_power_msg)
        self.send_power_thread.start()

        self.power_message_counter += 1
        self.bus.send(self.power_msg)
        # print("Power Message #{}".format(self.power_message_counter))
        # print('%.09f' % time.time())
        if(self.power_message_counter == self.POWER_CYCLE_MSG_COUNT):
            self.power_cycle_completed = True
            self.control_ready = True
            # print("Power Cycling Completed!")

    def send_control_msg(self):
        """Send the control message to the SME motor controller"""
        self.next_call += 0.05
        control_msg = self.calc_control_msg(self.joy_prop_input)
        
        self.send_control_thread = threading.Timer(self.next_call-time.time(), self.send_control_msg)
        self.send_control_thread.start()

        if(self.control_ready):
            self.bus.send(control_msg)
            # print("Control Message")
            # print('%.09f' % time.time())
            pass

    def send_steering_msg(self):
        """Send the steering message to the EPAS Motor"""
        steering_msg = self.calc_steering_msg(self.joy_steering_input)
        # self.bus.send(steering_msg)

    def send_braking_msg(self):
        """Send the braking message to the Kartech Linear Actuator"""
        braking_msg = self.calc_braking_msg(self.joy_braking_input)
        # self.bus.send(braking_msg)

    def propulsion_cycle(self):
        """Initialize the propulsion control logic"""
        self.send_power_msg()
        if(self.power_cycle_completed == False):
            self.send_control_msg()

    def calc_control_msg(self, joy_prop_input):
        """Calculate and assemble the propulsion CAN message for operation"""
        # if the safety switch is pressed then assemble control messages
        # else send the zero control message
        if(self.safety_switch == 1):
            MAX_PROP_MESSAGE = 0x01F4
            MIN_PROP_MESSAGE = 0x0000
            # 511 RPM 
            MAX_PROP_INPUT = 1
            MIN_PROP_INPUT = 0
            PROP = self.joy_prop_input
            
            if PROP < MIN_PROP_INPUT:
                PROP = MIN_PROP_INPUT
            if PROP > MAX_PROP_INPUT:
                PROP = MAX_PROP_INPUT

            if (PROP >= 0) and (PROP <= 1):
                propulsion_map = int(round((PROP-MIN_PROP_INPUT)*(MAX_PROP_MESSAGE-MIN_PROP_MESSAGE)/(MAX_PROP_INPUT-MIN_PROP_INPUT)+MIN_PROP_MESSAGE))
                self.prop_data[1] = int(propulsion_map >> 8 & self.MASKER)
                self.prop_data[0] = int(propulsion_map & self.MASKER)
            else:
                self.prop_data[1] = 0x00
                self.prop_data[0] = 0x00 

            # create the can message
            prop_calc_msg = can.Message(arbitration_id = self.prop_arbitration_id, data = self.prop_data, extended_id = False)
        else:
            prop_calc_msg = self.zero_control_msg

        return prop_calc_msg

    def calc_steering_msg(self, joy_steering_input):
        """Calculate and assemble the steering CAN message for operation"""
        if(self.safety_switch == 1):
            rev = self.joy_steering_input
            
            # positive full lock bytes
            POS_FULL_LOCK = 0x00180000
            # zero full lock bytes
            ZERO_FULL_LOCK = 0x00000000

            # maximum number of revolutions (positive)
            MAX_REV = 1
            # 0 REVOLUTIONS
            ZERO_REV = 0

            # establishing the limits of the joy node (from -1 to 1)
            if(rev > 1):
                rev = 1
            if(rev < -1):
                rev = -1

            # mapping out values for steering 
            steering_map = int(round(((-1)*rev-ZERO_REV)*(POS_FULL_LOCK-ZERO_FULL_LOCK)/(MAX_REV-ZERO_REV)+ZERO_FULL_LOCK))
            self.steering_data[5] = int(steering_map >> 24 & self.MASKER)    
            self.steering_data[4] = int(steering_map >> 16 & self.MASKER)    
            self.steering_data[3]= int(steering_map >> 8 & self.MASKER)
            self.steering_data[2] = int(steering_map & self.MASKER)
            
            steering_calc_msg = can.Message(arbitration_id = self.steering_arbitration_id, data = self.steering_data, extended_id = True)
        else:
            steering_calc_msg = self.zero_steering_msg
        
        return steering_calc_msg

    def calc_braking_msg(self, joy_braking_input):
        """Calculate and assemble the braking message for operation"""
        brake = self.joy_braking_input
        MAX_BRAKE_MESSAGE = 0xCDAC
        MIN_BRAKE_MESSAGE = 0xC1F4

        MAX_BRAKE_DISTANCE = 1
        MIN_BRAKE_DISTANCE = 0

        if(brake < 0):
            brake = 0
        if(brake > 1):
            brake = 1

        braking_map = int(round((brake-MAX_BRAKE_DISTANCE)*(MAX_BRAKE_MESSAGE-MIN_BRAKE_MESSAGE)/(MAX_BRAKE_DISTANCE-MIN_BRAKE_DISTANCE)+MAX_BRAKE_MESSAGE))
        self.braking_data[3] = int(braking_map >> 8 & self.MASKER)
        self.braking_data[4] = int(braking_map & self.MASKER)

        braking_calc_msg = can.Message(arbitration_id = self.braking_arbitration_id, data = self.braking_data, extended_id = True)

        return braking_calc_msg
    
    def main(self):
        self.propulsion_cycle()
        rate = rospy.Rate(10)

        while not rospy.is_shutdown():
            self.send_steering_msg()
            self.send_braking_msg()
            rate.sleep()

        self.send_power_thread.cancel()
        self.send_control_thread.cancel()
        rospy.loginfo("Successfully killed threads")

# def main():
#     rospy.init_node('Can_Bus_Node', anonymous = True)
#     driver = ThreadCAN()
#     driver.propulsion_cycle()
    
#     try:
#         driver.vehicle_operation()
#     except rospy.ROSInterruptException:
#         pass
        
# if __name__ == '__main__':
#     main()
# def Can_Node():
#     rospy.init_node('Can_Bus_Node', anonymous = True)
#     driver = ThreadCAN()
#     driver.propulsion_cycle()

#     # 10 Hz rate
#     rate = rospy.Rate(10)
#     while not rospy.is_shutdown():
#         driver.send_steering_msg()
#         driver.send_braking_msg()
#         rate.sleep()
    
if __name__ == '__main__':
    try:
        ThreadCAN()
    except rospy.ROSInterruptException:
        pass