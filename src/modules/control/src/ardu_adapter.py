#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64

global steering_callback
global driving_callback
global high_lvl_driving_callback
global high_lvl_steering_callback

high_lvl_steering_callback = 0
steering_callback = 207
high_lvl_driving_callback = 1
driving_callback = 1
pi = 3.1415926535

def callback_steer(low_steering_msg):
    ''' 
    Converts analog input from potentiometer to steering angle in radians
    '''
    steering_callback = ((low_steering_msg.data*.1721)-36.15)*pi/180

def callback_drive(low_driving_msg):
    '''
    PWM Value from the arduino
    '''
    driving_callback = low_driving_msg.data
    #print driving_callback

def driving_high_lvl_callback(high_driving_msg):
    '''
    Desired PWM Value from the high lvl control
    '''
    high_lvl_driving_callback = high_driving_msg.data
    #print high_lvl_driving_callback

def steering_high_lvl_callback(high_steering_msg):
    '''
    Converts steering angle required from high lvl control to analog input for the linear actuator
    '''
    high_lvl_steering_callback = (high_steering_msg.data*180/pi + 36.15)/.1721)

def Control_Adapter_Arduino_node():
    '''
    Node to facilitate the publisher and subscriber relationship between the high lvl and low lvl control
    '''
    rospy.init_node('Control_Adapter', anonymous = True)

    steering_low_lvl_node_publisher = rospy.Publisher('/control/steering_channel', Float64, queue_size=10)
    steering_publisher_to_high_lvl = rospy.Publisher('/control/steering_feedback', Float64, queue_size=10)
    driving_low_lvl_node_publisher = rospy.Publisher('/control/driving_channel', Float64, queue_size=10)
    driving_publisher_to_high_lvl = rospy.Publisher('/control/driving_feedback', Float64, queue_size=10)

    rate = rospy.Rate(50)

    while not rospy.is_shutdown():
        high_lvl_steering_subscriber = rospy.Subscriber("/control/steering_desired", Float64, steering_high_lvl_callback)
        low_lvl_steering_subscriber = rospy.Subscriber("/control/steering_response", Float64, callback_steer)
        low_lvl_driving_subscriber = rospy.Subscriber("/control/driving_response", Float64, callback_drive)
        high_lvl_driving_subscriber = rospy.Subscriber("/control/driving_desired", Float64, driving_high_lvl_callback)
        steering_low_lvl_node_publisher.publish(high_lvl_steering_callback)
        steering_publisher_to_high_lvl.publish(steering_callback)
        driving_low_lvl_node_publisher.publish(high_lvl_driving_callback)
        driving_publisher_to_high_lvl.publish(driving_callback)
        rate.sleep()
        #rospy.spin()

if __name__ == '__main__':
    try:
        Control_Adapter_Arduino_node()
    except rospy.ROSInterruptException:
        pass


    