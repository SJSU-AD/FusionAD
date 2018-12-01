#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import Float32

right_encoder_msg = 0
left_encoder_msg = 0

right_encoder_count = 0
previous_right_encoder_count = 0

left_encoder_count = 0
previous_left_encoder_count = 0

# left_angular_vel = 0
# right_angular_vel = 0
left_pos = 0
right_pos = 0
vel_magnitude = 0

PI = 3.14159
WHEEL_RADIUS = 0.1397
PULSES_PER_ROTATION = 1200
DT = 0.02

# initialize the publisher
velocity_estimate_publisher = rospy.Publisher('/localization/velocity_estimate', Float32, queue_size = 10)

def right_encoder_callback(right_encoder_msg):
    '''callback function for the right encoder
    '''
    global right_encoder_count
    right_encoder_count = (-1)*right_encoder_msg.data

def left_encoder_callback(left_encoder_msg):
    '''callback function for the left encoder
    '''
    global left_encoder_count
    left_encoder_count = left_encoder_msg.data

def vel_timer_callback(event):
    '''timer_callback function to perform the math required to estimate velocity of the car
    '''
    # declare the globals for this function
    global previous_right_encoder_count
    global previous_left_encoder_count
    # global left_angular_vel
    # global right_angular_vel
    global right_pos
    global left_pos
    global vel_magnitude
    # # left wheel angular velocity estimate
    # left_angular_vel = ((2*PI*(left_encoder_count-previous_left_encoder_count))/(PULSES_PER_ROTATION*DT))
    # # right wheel angular velocity estimate
    # right_angular_vel = ((2*PI*(right_encoder_count-previous_right_encoder_count))/(PULSES_PER_ROTATION*DT))
    # # updating previous encoder counts
    # previous_left_encoder_count = left_encoder_count
    # previous_right_encoder_count = right_encoder_count
    # # velocity estimate
    # vel_magnitude = (left_angular_vel+right_angular_vel)*WHEEL_RADIUS/2
    # velocity_estimate_publisher.publish(vel_magnitude)
    # left wheel angular velocity estimate
    
    left_pos = ((2*PI*(left_encoder_count-previous_left_encoder_count))/(PULSES_PER_ROTATION))
    # right wheel angular velocity estimate
    right_pos = ((2*PI*(right_encoder_count-previous_right_encoder_count))/(PULSES_PER_ROTATION))
    # updating previous encoder counts
    previous_left_encoder_count = left_encoder_count
    previous_right_encoder_count = right_encoder_count
    # velocity estimate
    vel_magnitude = (left_pos+right_pos)*WHEEL_RADIUS/DT/2
    velocity_estimate_publisher.publish(vel_magnitude)

def Velocity_Estimation_Node():
    '''Node to initialize the node and subscribers to the Arduino odometry nodes
    Establishes timer for consistent odometry readings at 50 Hz
    '''
    rospy.init_node('Velocity_Estimation', anonymous = True)

    rospy.Subscriber("localization/right_encoder_reading", Int32, right_encoder_callback)
    rospy.Subscriber("localization/left_encoder_reading", Int32, left_encoder_callback)

    timer = rospy.Timer(rospy.Duration(DT), vel_timer_callback)
    rospy.spin()
    timer.shutdown()

if __name__ == '__main__':
    try:
        Velocity_Estimation_Node()
    except rospy.ROSInterruptException:
        pass