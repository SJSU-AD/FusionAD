#!/usr/bin/env python
import rospy
#from std_msgs.msg import Float64
from std_msgs.msg import Int16
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
'''
TODO: Need to prevent steering oscillation due to slower subscriber rate than 50 Hz
'''
# declaring publishers for propulsion and steering
steering_low_lvl_node_publisher = rospy.Publisher('/control/steering_channel', Int16, queue_size=10)
driving_low_lvl_node_publisher = rospy.Publisher('/control/driving_channel', Int16, queue_size=10)

# declaring constants
desired_steering = 319
steering_msg = 0
desired_throttle = 0
driving_msg = 0

steering_limit_radians = 0.33
steering_analog_slope = 424.2424
steering_analog_intercept = 322

min_driving_input = 0
max_driving_input = 100
min_driving_output = 0
max_driving_output = 255

def high_lvl_callback(high_lvl_control_msg):
    '''High lvl control message for both desired driving and steering input
    /control/controlcmd is the topic name
    '''
    global steering_msg
    steering_msg = high_lvl_control_msg.steeringAngle
    global driving_msg
    driving_msg = high_lvl_control_msg.throttle
    
    global desired_throttle
    if driving_msg >= 0:
        desired_throttle = (driving_msg-min_driving_input)*(max_driving_output-min_driving_output)/(max_driving_input-min_driving_input)+min_driving_output
    else:
        desired_throttle = (-1)*(abs(driving_msg)-min_driving_input)*(max_driving_output-min_driving_output)/(max_driving_input-min_driving_input)+min_driving_output
    steering_angle = 0

    if(abs(steering_msg) > steering_limit_radians): # establishing limits in radians for steering
        steering_angle = steering_limit_radians*(abs(steering_msg)/steering_msg)
    else:
        steering_angle = steering_msg 

    global desired_steering
    desired_steering = ((-1)*steering_angle*steering_analog_slope+steering_analog_intercept)
    steering_low_lvl_node_publisher.publish(desired_steering)
    driving_low_lvl_node_publisher.publish(desired_throttle)
    
    
# def timer_callback(event):
#     '''Handles the conversion between steering in radians from the high level control and analog value for the low level control
#     '''
#     global desired_throttle
#     if driving_msg >= 0:
#         desired_throttle = (driving_msg-min_driving_input)*(max_driving_output-min_driving_output)/(max_driving_input-min_driving_input)+min_driving_output
#     else:
#         desired_throttle = (-1)*(abs(driving_msg)-min_driving_input)*(max_driving_output-min_driving_output)/(max_driving_input-min_driving_input)+min_driving_output
#     steering_angle = 0

#     if(abs(steering_msg) > steering_limit_radians): # establishing limits in radians for steering
#         steering_angle = steering_limit_radians*(abs(steering_msg)/steering_msg)
#     else:
#         steering_angle = steering_msg 

#     global desired_steering
#     desired_steering = ((-1)*steering_angle*steering_analog_slope+steering_analog_intercept)
#     steering_low_lvl_node_publisher.publish(desired_steering)
#     driving_low_lvl_node_publisher.publish(desired_throttle)

def Control_Adapter_Arduino_Node():
    '''Node to facilitate the publisher and subscriber relationship between the high lvl and low lvl control
    '''
    rospy.init_node('Control_Adapter', anonymous = True)

    rospy.Subscriber("/control/controlcmd", Controlcmd, high_lvl_callback)
    # timer = rospy.Timer(rospy.Duration(0.02), timer_callback)

    # rospy.spin()
    # timer.shutdown()
    # '''
    #rate = rospy.Rate(50)
    rate = rospy.Rate(25)

    while not rospy.is_shutdown():
        steering_low_lvl_node_publisher.publish(desired_steering)
        driving_low_lvl_node_publisher.publish(desired_throttle)
        rate.sleep()
    
    

if __name__ == '__main__':
    try:
        Control_Adapter_Arduino_Node()
    except rospy.ROSInterruptException:
        pass
