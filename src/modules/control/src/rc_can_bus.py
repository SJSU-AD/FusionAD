#!/usr/bin/env python
'''
TODO: Possibly clean up the method for timing

NOTE: Must be plugged into the CAN device with a completed CAN network to work

Hardware Included: USB2CAN Device
                   Globe Pow-R Steer EPAS Motor
                   Kartech Linear Actuator
                   SME Propulsion Motor

NOTE: bus = can.interface.Bus(channel='can0', bustype='socketcan_ctypes')
                                                       ^^^^^^^^^^^^^^^^^
      Take note of this change in bustype!

      Only send lists with a UNIFORM data type through the CAN Network
        Example: Only send [int,int,int,int,int,int,int,int]
                        or [string,string,string,string,string,string,string,string]

      The SME Propulsion Motor Controller requires 5 seconds of power messages until operation can begin
      Afterwards, the controller must receive power messages and propulsion control messages with a 50 ms time delay
      between the two different messages
'''
import rospy
from sensor_msgs.msg import Joy
import can
import time
import os


# establishing the CAN connection and setting bitrate to 250 kbps
os.system('sudo /sbin/ip link set can0 up type can bitrate 250000')

# initializing the bus to channel 0 and bustype 'socketcan_ctypes'
bus = can.interface.Bus(channel='can0', bustype='socketcan_ctypes')

steering_arbitration_id = 0x18FF00F9
braking_arbitration_id = 0xFF0000

# propulsion power request arbitration id
prop_power_arbitration_id = 0x204
# arbitration id for commanding the motor
propulsion_arbitration_id = 0x304

# 8 byte message for moving the steering motor
steering_data = [0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00]
# 8 byte message for zeroing the steering
zero_steering_data = [0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]

# 8 byte message for stopping the propulsion motor
stop_propulsion_data = [0x00, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00]
# 8 byte message for requesting power to the propulsion motor
prop_power_request_data = [0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
# 8 byte message for moving the propulsion motor @ 511 rpm
propulsion_data = [0xF4, 0x01, 0xFF, 0x7F, 0x00, 0x0D, 0x00, 0x00]

# 8 byte message for moving the linear actuator
'''
NOTE: byte #3 (0-7) contains a nibble 
      The first bit, C must stay present
      The math is done with byte #2 and the other nibble of byte #3
'''
braking_data = [0x0F, 0x4A, 0xF4, 0xC1, 0x00, 0x00, 0x00, 0x00]
# 8 byte message for zeroing the linear actuator
zero_braking_data = [0x7E, 0x02, 0x12, 0x34, 0x56, 0xAB, 0xCD, 0xEF]

class CanDriver:
    """Converts joy input into appropriate CAN Message and sends the message"""
    # initializing the node
    rospy.init_node('controller', anonymous = True)
    def __init__(self):
        # subscriber to the joystick
        joy_subscriber = rospy.Subscriber('joy', Joy, self.joyCallback, queue_size = 1)
        # cyclic time cycle of 5 milliseconds required
        self.main()

    def joyCallback(self, data):
        
        # declaring the steering axis on the joy node
        STEERING_AXIS = 0
        # declaring the braking button on the joy node
        BRAKING_BUTTON = 6
        # declaring the propulsion axis on the joy node
        PROPULSION_AXIS = 3
        # declaring the safety button
        SAFETY_BUTTON = 7

        joy_steering_input = data.axes[STEERING_AXIS]
        joy_braking_input = data.buttons[BRAKING_BUTTON]
        joy_propulsion_input = data.axes[PROPULSION_AXIS]
        safety_switch = data.buttons[SAFETY_BUTTON]

        # mask for hex
        MASKER = 0xFF
        
        # the safety switch must be pressed for operation
        if safety_switch == 1:
            ####################
            ## Steering Logic ##
            ####################
            # rev = joy_steering_input
            # # positive full lock bytes
            # POS_FULL_LOCK = 0x00180000
            # # zero full lock bytes
            # ZERO_FULL_LOCK = 0x00000000
            # # negative full lock bytes
            # #NEG_FULL_LOCK = 0xFFE80000
            # # maximum number of revolutions (positive)
            # MAX_REV = 1
            # # 0 REVOLUTIONS
            # ZERO_REV = 0
            # # minimum number of revolutions (negative)
            # #NEG_REV = -1
            # #establishing the limits of the joy node (from -1 to 1)
            # if rev > 1:
            #     rev = 1
            # if rev < -1:
            #     rev = -1
            # # turn right
            # if rev <= 0 and rev >= -1:
            #     steering_map = int(round(((-1)*rev-ZERO_REV)*(POS_FULL_LOCK-ZERO_FULL_LOCK)/(MAX_REV-ZERO_REV)+ZERO_FULL_LOCK))
            #     steering_data[5] = int(steering_map >> 24 & MASKER)    
            #     steering_data[4] = int(steering_map >> 16 & MASKER)    
            #     steering_data[3]= int(steering_map >> 8 & MASKER)
            #     steering_data[2] = int(steering_map & MASKER)

            #         # turn left
            #         # mapping out negative values for steering   
            # elif rev >= 0 and rev <= 1:
            #     steering_map = int(round(((-1)*rev-ZERO_REV)*(POS_FULL_LOCK-ZERO_FULL_LOCK)/(MAX_REV-ZERO_REV)+ZERO_FULL_LOCK))
            #     steering_data[5] = int(steering_map >> 24 & MASKER)    
            #     steering_data[4] = int(steering_map >> 16 & MASKER)    
            #     steering_data[3]= int(steering_map >> 8 & MASKER)
            #     steering_data[2] = int(steering_map & MASKER)

            # ###################
              ## Braking Logic ##
              ###################
            # BRAKE = joy_braking_input
            # MAX_BRAKE_MESSAGE = 0xCDAC
            # MIN_BRAKE_MESSAGE = 0xC1F4

            # MAX_BRAKE_DISTANCE = 1
            # MIN_BRAKE_DISTANCE = 0

            # if BRAKE < 0:
            #     BRAKE = 0
            # if BRAKE > 1:
            #     BRAKE = 1

            # braking_map = int(round((BRAKE-MAX_BRAKE_DISTANCE)*(MAX_BRAKE_MESSAGE-MIN_BRAKE_MESSAGE)/(MAX_BRAKE_DISTANCE-MIN_BRAKE_DISTANCE)+MAX_BRAKE_MESSAGE))
            # braking_data[3] = int(braking_map >> 8 & MASKER)
            # braking_data[4] = int(braking_map & MASKER)

            ######################
            ## Propulsion Logic ##
            ######################
            MAX_PROP_MESSAGE = 0xF401
            MIN_PROP_MESSAGE = 0x0000
            # 511 RPM 
            MAX_PROP_RPM = 1 
            MIN_PROP_RPM = 0

            PROP = joy_propulsion_input
            if PROP < 0:
                PROP = 0
            if PROP > 1:
                PROP = 1

            propulsion_map = int(round((PROP-MAX_PROP_RPM)*(MAX_PROP_MESSAGE-MIN_PROP_MESSAGE)/(MAX_PROP_RPM-MIN_PROP_RPM)+MAX_PROP_MESSAGE))
            propulsion_data[0] = int(propulsion_map >> 8 & MASKER)
            propulsion_data[1] = int(propulsion_map & MASKER)
            
        # when the safety button is not pressed, send zero messages
        else:
            propulsion_data[0] = 0x00
            propulsion_data[1] = 0x00

            steering_data[5] = 0x00
            steering_data[4] = 0x00
            steering_data[3] = 0x00
            steering_data[2] = 0x00
        

    def main(self):
        start_time = time.clock()
        # steering_zero_msg = can.Message(arbitration_id = steering_arbitration_id, data = zero_steering_data, extended_id = True)
        # braking_zero_msg = can.Message(arbitration_id = braking_arbitration_id, data = zero_braking_data, extended_id = True)

        # bus.send(steering_zero_msg)
        # bus.send(braking_zero_msg)

        TIME_DELAY = 5
        while not rospy.is_shutdown():
            frequency_start_time = time.clock()
            FREQUENCY_STATE = False
            # 0x66 is 0.4 rev/s            
            # print steering_data
            present_time = time.clock()
            power_propulsion_msg = can.Message(arbitration_id = prop_power_arbitration_id, data = prop_power_request_data, extended_id = False)
            # steering_msg = can.Message(arbitration_id = steering_arbitration_id, data = steering_data, extended_id = True)
            # braking_msg = can.Message(arbitration_id = braking_arbitration_id, data = braking_data, extended_id = True)
            propulsion_msg = can.Message(arbitration_id = propulsion_arbitration_id, data = propulsion_data, extended_id = False)
            bus.send(steering_msg)
            #bus.send(braking_msg)
            bus.send(power_propulsion_msg)
            power_time = time.clock()
            control_state = False
			# only allow messages to go through if cyclic delay is met
            if abs(present_time-start_time) >= TIME_DELAY:
                while control_state == False:
                    control_time = time.clock()
                    # regulate the 50 ms period offset required
                    if abs(power_time - control_time) >= 0.05:
                        bus.send(propulsion_msg)
                        # exiting the send control message loop
                        control_state = True
                        # print('Sleeping')
            while FREQUENCY_STATE == False:
                frequency_time = time.clock()
                if abs(frequency_start_time-frequency_time) >= 0.100:
                    # resetting the overall time.clock()
                    frequency_start_time = frequency_time
                    # exiting the while loop
                    FREQUENCY_STATE = True

    

if __name__ == '__main__':
    try:
        CanDriver()
    except rospy.ROSInterruptException:
        pass
