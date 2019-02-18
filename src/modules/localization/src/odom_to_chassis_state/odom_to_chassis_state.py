#!/usr/bin/env python

"""Takes odometry data from robot_localization and publishes as a chassis_state message.
   Currently using the velocity estimates from wheel odometry because the EKF velocity estimates are incorrect as discussed 
   in ISS-160.

NOTE: Uses interface/chassis_state.msg

Subscribes
----------
Topic: /odometry/filtered
    Msg: nav_msgs/Odometry

Publishes
---------
Topic: /localization/state
    Msg: Chassis_state.msg
    
"""

import rospy
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu
from interface.msg import Chassis_state

class MsgConverter(object):
    """Takes odometry data from robot_localization and wheel odom data and publishes as a chassis_state message"""

    def __init__(self):
        """Initializing Chassis_state message publisher"""
        self.chassisStatePublisher = rospy.Publisher("/localization/state", Chassis_state, queue_size=1000)

        # Initialize a nav_msgs/Odometry message and assign to MsgConverter object
        self.newWheelMsg = Odometry()

    def wheel_odom_callback(self, wheelMsg):
        """Callback subscribed to the wheel odometry topic"""
        self.newWheelMsg = wheelMsg

    def ekf_odom_callback(self, odomMsg):
        """Callback subscribed to EKF odometry topic"""
        currentChassisState = self.create_chassis_state_msg(odomMsg.header.stamp, 
                                                            odomMsg.pose.pose.position.x, odomMsg.pose.pose.position.y,
                                                            self.newWheelMsg.twist.twist.linear.x, self.newWheelMsg.twist.twist.linear.y,
                                                            odomMsg.pose.pose.orientation.x, odomMsg.pose.pose.orientation.y, 
                                                            odomMsg.pose.pose.orientation.z, odomMsg.pose.pose.orientation.w)

        self.chassisStatePublisher.publish(currentChassisState)

    def create_chassis_state_msg(self, headerStamp, x, y, xVel, yVel, quatX, quatY, quatZ, quatW):
        """Compose Chassis_state message"""
        currentChassisState = Chassis_state()
        currentChassisState.header.stamp = headerStamp

        # Set position in publish message
        currentChassisState.Position.pose.position.x = x
        currentChassisState.Position.pose.position.y = y

        # Set velocity in publish message
        currentChassisState.Speed.twist.linear.x = xVel
        currentChassisState.Speed.twist.linear.y = yVel

        # Set orientation in publish message
        currentChassisState.Position.pose.orientation.x = quatX
        currentChassisState.Position.pose.orientation.y = quatY
        currentChassisState.Position.pose.orientation.z = quatZ
        currentChassisState.Position.pose.orientation.w = quatW

        return currentChassisState
    
    def odom_data_converter(self):
        """Take EKF odom data, convert to chassis_state, republish"""
        rospy.Subscriber("/odometry/filtered", Odometry, self.ekf_odom_callback, queue_size=1000)
        rospy.Subscriber("/localization/wheel_odom", Odometry, self.wheel_odom_callback, queue_size=1000)
        rospy.spin()

def main():
    rospy.init_node("odom_converter_node", anonymous=False)
    odomConverter = MsgConverter()

    try:
        odomConverter.odom_data_converter()
    except rospy.ROSInterruptException:
        pass

if __name__ == "__main__":
    main()
        