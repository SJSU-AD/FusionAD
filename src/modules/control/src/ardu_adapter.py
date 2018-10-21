#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64
from interface.msg import Controlcmd
'''
NOTE: Please be in ~/FusionAD to run this code with the following commands:
$ se
$ rosrun control ardu_adapter.py
This script is subscribed to both the high level control node and the Arduino
The high level control node gives the throttle and steering values with a custom message definition
    high_lvl_callback is the callback function for the high level control
The Arduino node gives the throttle and steering values with individual functions
    callback_steer and callback_drive
The high_lvl_callback takes the message from the high level control and converts it to useable (analog) values
The callbacks take the message from the low level control and convert them into radians and percentage for steering and driving respectively
Eventually this script will be used for low level control when we move away from PID
'''


high_lvl_steering_callback = 319
steering_callback = 0
high_lvl_driving_callback = 0
driving_callback = 0

pi = 3.1415926535

potentiometer_offset = 112
steering_analog_slope = .1721
steering_analog_intercept = 36.15
steering_limit_radians = 0.33

min_driving_input = 0
max_driving_input = 100
min_driving_output = 0
max_driving_output = 255

def callback_steer(low_steering_msg):
    ''' 
    Converts analog input from potentiometer to steering angle in radians
    /control/steering_response is the topic name
    '''
    global steering_callback
    steering_callback = (((low_steering_msg.data-potentiometer_offset)*steering_analog_slope)-steering_analog_intercept)*pi/180

def callback_drive(low_driving_msg):
    '''
    PWM Value from the arduino
    /control/driving_response is the topic name
    '''
    global driving_callback
    driving_callback = (low_driving_msg.data-min_driving_output)*(max_driving_input-max_driving_input)/(max_driving_output-min_driving_output)+min_driving_input

def high_lvl_callback(high_lvl_control_msg):
    '''
    High lvl control message for both desired driving and steering input
    /control/controlcmd is the topic name
    '''
    global high_lvl_driving_callback
    if high_lvl_control_msg.throttle>=0:
        high_lvl_driving_callback = (high_lvl_control_msg.throttle-min_driving_input)*(max_driving_output-min_driving_output)/(max_driving_input-min_driving_input)+min_driving_output
    else:
        high_lvl_driving_callback = (-1)*(abs(high_lvl_control_msg.throttle)-min_driving_input)*(max_driving_output-min_driving_output)/(max_driving_input-min_driving_input)+min_driving_output
    
    steering_angle = 0

    if(abs(high_lvl_control_msg.steeringAngle) > steering_limit_radians): # establishing limits in radians for steering
        steering_angle = steering_limit_radians*((-1)*abs(high_lvl_control_msg.steeringAngle)/high_lvl_control_msg.steeringAngle)
    else:
        steering_angle = high_lvl_control_msg.steeringAngle 

    global high_lvl_steering_callback
    high_lvl_steering_callback = ((-1)*steering_angle*180/pi+steering_analog_intercept)/steering_analog_slope+potentiometer_offset

'''
def driving_high_lvl_callback(high_driving_msg):
    
    #Desired PWM Value from the high lvl control
    
    high_lvl_driving_callback = (high_driving_msg.data-min_driving_input)*(max_driving_output-min_driving_output)/(max_driving_input-min_driving_input)+min_driving_output
def steering_high_lvl_callback(high_steering_msg):
    
    #Converts steering angle required from high lvl control to analog input for the linear actuator
    high_lvl_steering_callback = (high_steering_msg.data*180/pi + 36.15)/.1721
'''

def Control_Adapter_Arduino_node():
    '''
    Node to facilitate the publisher and subscriber relationship between the high lvl and low lvl control
    '''
    rospy.init_node('Control_Adapter', anonymous = True)

    steering_low_lvl_node_publisher = rospy.Publisher('/control/steering_channel', Float64, queue_size=10)
    driving_low_lvl_node_publisher = rospy.Publisher('/control/driving_channel', Float64, queue_size=10)
    high_lvl_subscriber = rospy.Subscriber("/control/controlcmd", Controlcmd, high_lvl_callback)
    low_lvl_steering_subscriber = rospy.Subscriber("/control/steering_response", Float64, callback_steer)
    low_lvl_driving_subscriber = rospy.Subscriber("/control/driving_response", Float64, callback_drive)

    rate = rospy.Rate(50)

    while not rospy.is_shutdown():
        steering_low_lvl_node_publisher.publish(high_lvl_steering_callback)
        driving_low_lvl_node_publisher.publish(high_lvl_driving_callback)
        rate.sleep()

if __name__ == '__main__':
    try:
        Control_Adapter_Arduino_node()
    except rospy.ROSInterruptException:
        pass