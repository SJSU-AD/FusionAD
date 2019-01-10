#!/usr/bin/env python
'''
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
propulsion_data = [0x00, 0x00, 0xFF, 0x7F, 0x00, 0x0D, 0x00, 0x00]

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
        joy_subscriber = rospy.Subscriber('/joy', Joy, self.joyCallback, queue_size = 1)
        # cyclic time cycle of 5 milliseconds required
        self.main()

    def joyCallback(self, data):
        
        # declaring the steering axis on the joy node
        STEERING_AXIS = 0
        # declaring the braking button on the joy node
        BRAKING_BUTTON = 6
        # declaring the propulsion axis on the joy node
        PROPULSION_AXIS = 4
        # declaring the safety button
        SAFETY_BUTTON = 5

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
            # NEG_REV = -1
            # #establishing the limits of the joy node (from -1 to 1)
            # if rev > MAX_REV:
            #     rev = MAX_REV
            # if rev < NEG_REV:
            #     rev = NEG_REV
            # # turn right
            # if rev <= MAX_REV and rev >= NEG_REV:
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

            # MIN_BRAKE_INPUT = 0
            # MAX_BRAKE_INPUT = 1

            # if BRAKE < MIN_BRAKE_INPUT:
            #     BRAKE = 0
            # if BRAKE > 1:
            #     BRAKE = 1

            # braking_map = int(round((BRAKE-MIN_BRAKE_INPUT)*(MAX_BRAKE_MESSAGE-MIN_BRAKE_MESSAGE)/(MAX_BRAKE_INPUT-MIN_BRAKE_INPUT)+MIN_BRAKE_MESSAGE))
            # braking_data[3] = int(braking_map >> 8 & MASKER)
            # braking_data[4] = int(braking_map & MASKER)

            ######################
            ## Propulsion Logic ##
            ######################
            # MAX_PROP_MESSAGE = 0xF401
            # MIN_PROP_MESSAGE = 0x0000
            
            # 250 RPM
            MAX_PROP_MESSAGE = 0x00FA
            MIN_PROP_MESSAGE = 0x0000

            # 500 RPM 
            MAX_PROP_INPUT = 1
            MIN_PROP_INPUT = 0
            PROP = joy_propulsion_input
            
            if PROP < MIN_PROP_INPUT:
                PROP = MIN_PROP_INPUT
            if PROP > MAX_PROP_INPUT:
                PROP = MAX_PROP_INPUT

            if (PROP >= 0) and (PROP <= 1):
                propulsion_map = int(round((PROP-MIN_PROP_INPUT)*(MAX_PROP_MESSAGE-MIN_PROP_MESSAGE)/(MAX_PROP_INPUT-MIN_PROP_INPUT)+MIN_PROP_MESSAGE))

                propulsion_data[1] = int(propulsion_map >> 8 & MASKER)
                propulsion_data[0] = int(propulsion_map & MASKER)
                

            else:
                propulsion_data[0] = 0x00
                propulsion_data[1] = 0x00    
            
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
            frequency_state = False
            POWER_CONTROL_PERIOD = 0.025
            OVERALL_PERIOD = 0.05
            # 0x66 is 0.4 rev/s            
            # print steering_data
            present_time = time.clock()
            power_propulsion_msg = can.Message(arbitration_id = prop_power_arbitration_id, data = prop_power_request_data, extended_id = False)
            steering_msg = can.Message(arbitration_id = steering_arbitration_id, data = steering_data, extended_id = True)
            braking_msg = can.Message(arbitration_id = braking_arbitration_id, data = braking_data, extended_id = True)
            propulsion_msg = can.Message(arbitration_id = propulsion_arbitration_id, data = propulsion_data, extended_id = False)
            # bus.send(steering_msg)
            # bus.send(braking_msg)
            bus.send(power_propulsion_msg)
            control_state = False
			# only allow messages to go through if cyclic delay is met
            if abs(present_time-start_time) >= TIME_DELAY:
                power_time = time.clock()
                while control_state == False:
                    control_time = time.clock()
                    # regulate the 50 ms period offset required
                    
                    if abs(power_time - control_time) >= POWER_CONTROL_PERIOD:
                        bus.send(propulsion_msg)
                        # exiting the send control message loop
                        control_state = True
                        power_time = control_time
                        # print('Sleeping')
            while frequency_state == False:
                frequency_time = time.clock()
                if abs(frequency_start_time-frequency_time) >= OVERALL_PERIOD:
                    # resetting the overall time.clock()
                    frequency_start_time = frequency_time
                    # exiting the while loop
                    frequency_state = True

    

if __name__ == '__main__':
    try:
        CanDriver()
    except rospy.ROSInterruptException:
        pass
