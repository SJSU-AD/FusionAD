#!/usr/bin/env python
"""
Takes steering and throttle input from the high level control and then generates the appropriate CAN
messages to send to the steering and propulsion motors.

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

NOTE: Uses interface/Controlcmd.msg 
           interface/Can_Interface.msg

        Subscribes
        ----------
        Topic: /control/controlcmd
            Msg: Chassis_state.msg

        Publishes
        ---------
        Topic: /control/can_controlcmd
            Msg: Can_Interface.msg
"""
import rospy
from interface.msg import Controlcmd
from interface.msg import Can_Interface

class CanDriver(object):
    """Converts high-lvl input into appropriate CAN Message and sends the message"""
    # initializing the node
    def __init__(self):
        """Initialize can message publisher and data for the can messages"""
        self.canMsgPublisher = rospy.Publisher("/control/can_controlcmd", Can_Interface, queue_size=1000)

        self.steering_arbitration_id = 0x18FF00F9
        self.braking_arbitration_id = 0xFF0000

        # propulsion power request arbitration id
        self.prop_power_arbitration_id = 0x204
        # arbitration id for commanding the motor
        self.propulsion_arbitration_id = 0x304

        # 8 byte message for moving the steering motor
        self.steering_data = [0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02]
        # 8 byte message for zeroing the steering
        self.zero_steering_data = [0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]

        # 8 byte message for stopping the propulsion motor
        self.stop_prop_data = [0x00, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00]
        # 8 byte message for requesting power to the propulsion motor
        self.prop_power_request_data = [0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
        # 8 byte message for moving the propulsion motor @ 511 rpm
        self.prop_data = [0x00, 0x00, 0xFF, 0x7F, 0x00, 0x0D, 0x00, 0x00]

        # 8 byte message for moving the linear actuator
        """
        NOTE: byte #3 (0-7) contains a nibble 
            The first bit, C must stay present
            The math is done with byte #2 and the other nibble of byte #3
        """
        self.braking_data = [0x0F, 0x4A, 0xF4, 0xC1, 0x00, 0x00, 0x00, 0x00]
        # 8 byte message for zeroing the linear actuator
        self.zero_braking_data = [0x7E, 0x02, 0x12, 0x34, 0x56, 0xAB, 0xCD, 0xEF]

        # mask for hex
        self.MASKER = 0xFF

        # initialize a interface/Can_Interface message and assign to CanDriver
        self.canInterfaceMsg = Can_Interface()
        
    def high_lvl_callback(self, Controlcmd):
        """Callback handler from high level control, linear fit from experimental data according to ISS-72"""
        # left turn
        positive_steering_slope = 0.2224731787
        # right turn
        negative_steering_slope = 0.2733129308

        # remap the steering input
        if (Controlcmd.steeringAngle >= 0):
            remapped_rev_input = Controlcmd.steeringAngle/positive_steering_slope
        else:
            remapped_rev_input = Controlcmd.steeringAngle/negative_steering_slope

        self.steering_control(remapped_rev_input)
        self.prop_control(Controlcmd.throttle)
        self.can_message_assembly()

    def braking_control(self, desired_braking):
        """TODO: Add braking logic"""
        ###################
        ## Braking Logic ##
        ###################
        # BRAKE = desired_braking
        # MAX_BRAKE_MESSAGE = 0xCDAC
        # MIN_BRAKE_MESSAGE = 0xC1F4

        # MIN_BRAKE_INPUT = 0
        # MAX_BRAKE_INPUT = 1

        # if BRAKE < MIN_BRAKE_INPUT:
        #     BRAKE = 0
        # if BRAKE > 1:
        #     BRAKE = 1

        # braking_map = int(round((BRAKE-MIN_BRAKE_INPUT)*(MAX_BRAKE_MESSAGE-MIN_BRAKE_MESSAGE)/(MAX_BRAKE_INPUT-MIN_BRAKE_INPUT)+MIN_BRAKE_MESSAGE))
        # self.braking_data[3] = int(braking_map >> 8 & MASKER)
        # self.braking_data[4] = int(braking_map & MASKER)  

    def prop_control(self, desired_propulsion):
        """Function to assemble the hex data for the propulsion message"""
        #####################
        # Propulsion Logic ##
        #####################
        prop_input = desired_propulsion
        # 250 RPM
        MAX_PROP_MESSAGE = 0x00FA
        MIN_PROP_MESSAGE = 0x0000

        MAX_PROP_INPUT = 100
        MIN_PROP_INPUT = 0
        
        if prop_input < MIN_PROP_INPUT:
            prop_input = MIN_PROP_INPUT
        if prop_input > MAX_PROP_INPUT:
            prop_input = MAX_PROP_INPUT

        if (prop_input >= MIN_PROP_INPUT) and (prop_input <= MAX_PROP_INPUT):
            propulsion_map = int(round((prop_input-MIN_PROP_INPUT)*(MAX_PROP_MESSAGE-MIN_PROP_MESSAGE)/(MAX_PROP_INPUT-MIN_PROP_INPUT)+MIN_PROP_MESSAGE))

            self.prop_data[1] = int(propulsion_map >> 8 & self.MASKER)
            self.prop_data[0] = int(propulsion_map & self.MASKER)     
        else:
            self.prop_data[0] = 0x00
            self.prop_data[1] = 0x00

    def steering_control(self, desired_steering):
        """Function to assemble the hex data for the steering message"""
        ####################
        ## Steering Logic ##
        ####################
        steering_input = desired_steering

        # positive full lock bytes
        POS_FULL_LOCK = 0x00180000
        # zero full lock bytes
        ZERO_FULL_LOCK = 0x00000000

        # steering limits determined experimentally
        # maximum number of radians (positive)
        MAX_ANGLE = 1.4833248751
        # 0 REVOLUTIONS
        ZERO_ANGLE = 0
        # minimum number of radians (negative)
        NEG_ANGLE = -1.2074071982

        # establishing the limits of the joy node (from -0.33 to 0.33)
        if steering_input > MAX_ANGLE:
            steering_input = MAX_ANGLE
        if steering_input < NEG_ANGLE:
            steering_input = NEG_ANGLE

        if (steering_input <= MAX_ANGLE) and (steering_input >= NEG_ANGLE):
            steering_map = int(round(((-1)*steering_input-ZERO_ANGLE)*(POS_FULL_LOCK-ZERO_FULL_LOCK)/(MAX_ANGLE-ZERO_ANGLE)+ZERO_FULL_LOCK))
            self.steering_data[5] = int(steering_map >> 24 & self.MASKER)    
            self.steering_data[4] = int(steering_map >> 16 & self.MASKER)    
            self.steering_data[3]= int(steering_map >> 8 & self.MASKER)
            self.steering_data[2] = int(steering_map & self.MASKER)
        else:
            self.steering_data[5] = 0x00
            self.steering_data[4] = 0x00
            self.steering_data[3]= 0x00
            self.steering_data[2] = 0x00

    def can_message_assembly(self):
        self.canInterfaceMsg.steering_can_data = self.steering_data
        self.canInterfaceMsg.propulsion_can_data = self.prop_data
        self.canMsgPublisher.publish(self.canInterfaceMsg)

    def high_lvl_control_converter(self):
        """Take high level control steering and propulsion and convert to Can_Interface Msg"""
        # subscriber to the high level control
        rospy.Subscriber('/control/controlcmd', Controlcmd, self.high_lvl_callback, queue_size = 100)
        rospy.spin()

def main():
    rospy.init_node("can_ardu_interface_node", anonymous=False)
    canConverter = CanDriver()

    try:
        canConverter.high_lvl_control_converter()
    except rospy.ROSInterruptException:
        pass

if __name__ == "__main__":
    main()
