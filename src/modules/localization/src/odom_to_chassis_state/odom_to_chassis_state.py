#!/usr/bin/env python

"""Takes odometry data from robot_localization and publishes as a chassis_state message

NOTE: Uses interface/chassis_state.msg
"""

import rospy
from nav_msgs.msg import Odometry
from interface.msg import Chassis_state

class MsgConverter(object):
    """Takes odometry data from robot_localization and publishes as a chassis_state message

    Subscribes
    ----------
    Topic: /odometry/filtered
        Msg: nav_msgs/Odometry

    Publishes: /localization/state
        Msg: Chassis_state.msg
    """

    def __init__(self):
        """initializing Chassis_state message publisher"""
        self.chassisStatePublisher = rospy.Publisher("/localization/state", Chassis_state, queue_size=1000)
    
    def ekf_odom_callback(self, odomMsg):
        """Callback subscribed to EKF odometry topic"""
        currentChassisState = self.create_chassis_state_msg(odomMsg.header.stamp, 
                                                            odomMsg.pose.pose.position.x, odomMsg.pose.pose.position.y,
                                                            odomMsg.twist.twist.linear.x, odomMsg.twist.twist.linear.y)

        self.chassisStatePublisher.publish(currentChassisState)

    def create_chassis_state_msg(self, headerStamp, x, y, xVel, yVel):
        """Compose Chassis_state message"""
        currentChassisState = Chassis_state()
        currentChassisState.header.stamp = headerStamp

        # Set position in publish message
        currentChassisState.Position.pose.position.x = x
        currentChassisState.Position.pose.position.y = y

        # Set velocity in publish message
        currentChassisState.Speed.twist.linear.x = xVel
        currentChassisState.Speed.twist.linear.y = yVel

        return currentChassisState
    
    def odom_data_converter(self):
        """Take EKF odom data, convert to chassis_state, republish"""
        rospy.Subscriber("/odometry/filtered", Odometry, self.ekf_odom_callback, queue_size=1000)

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
        