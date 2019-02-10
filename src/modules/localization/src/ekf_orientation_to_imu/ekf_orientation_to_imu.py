#!/usr/bin/env python

"""Takes vehicle heading data from the EKF odometry message as well as orientation, twist, and accel data from the IMU and publishes as an imu message.

NOTE: The EKF assumes a 2-D world so the roll, pitch, roll rate, pitch rate, and linear acceleration must come from the IMU

Subscribes
----------
Topic: /odometry/filtered
    Msg: nav_msgs/Odometry

Topic: /localization/rotated_imu
    Msg: sensor_msgs/Imu

Publishes
---------
Topic: /localization/ekf_orientation
    Msg: sensor_msgs/Imu

"""

import rospy
from tf.transformations import euler_from_quaternion, quaternion_from_euler
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Quaternion

class imuMsgConverter(object):
    """Takes orientation data from the EKF and republishes as an IMU message"""

    def __init__(self):
        self.imuMsgPublisher = rospy.Publisher("/localization/ekf_orientation", Imu, queue_size = 100)

        # Initialize a sensor_msgs/Imu message and assign to the imuMsgConverter object
        self.receivedImuMsg = Imu()

        # Initialize a geometry/Quaternion message and assign to the imuMsgConverter object
        self.receivedImuQuat = Quaternion()

    def imu_callback(self, imuMsg):
        """Callback subscribed to the IMU output"""
        self.receivedImuMsg = imuMsg
        self.receivedImuQuat = imuMsg.orientation

    def ekf_callback(self, ekfMsg):
        """Callback subscribed to the EKF output"""
        updatedImuMsg = self.create_imu_msg(ekfMsg.pose.pose.orientation.x, ekfMsg.pose.pose.orientation.y,
                                            ekfMsg.pose.pose.orientation.z, ekfMsg.pose.pose.orientation.w,
                                            self.receivedImuQuat.x, self.receivedImuQuat.y,
                                            self.receivedImuQuat.z, self.receivedImuQuat.w)
        
        self.imuMsgPublisher.publish(updatedImuMsg)

    def create_imu_msg(self, ekf_quat_x, ekf_quat_y, ekf_quat_z, ekf_quat_w, imu_quat_x, imu_quat_y, imu_quat_z, imu_quat_w):
        """Compose the Imu message"""
        updatedImuMsg = self.receivedImuMsg

        # Take the roll, pitch, and yaw from the ekf message
        (ekf_roll, ekf_pitch, ekf_yaw) = euler_from_quaternion([ekf_quat_x, ekf_quat_y, ekf_quat_z, ekf_quat_w])

        # Take the roll, pitch, and yaw from the imu message
        (imu_roll, imu_pitch, imu_yaw) = euler_from_quaternion([imu_quat_x, imu_quat_y, imu_quat_z, imu_quat_w])
        
        # Place the roll and pitch from the imu and the yaw from the ekf into the updated Imu message
        (new_quat_x, new_quat_y, new_quat_z, new_quat_w) = quaternion_from_euler(imu_roll, imu_pitch, ekf_yaw)
        
        updatedImuMsg.orientation.x = new_quat_x
        updatedImuMsg.orientation.y = new_quat_y
        updatedImuMsg.orientation.z = new_quat_z
        updatedImuMsg.orientation.w = new_quat_w

        return updatedImuMsg
    
    def imu_data_converter(self):
        """Take the EKF orientation data and IMU data, convert to new IMU message, republish"""
        rospy.Subscriber("/odometry/filtered", Odometry, self.ekf_callback, queue_size = 100)
        rospy.Subscriber("/localization/rotated_imu", Imu, self.imu_callback, queue_size = 100)
        rospy.spin()

def main():
    rospy.init_node("imu_converter_node", anonymous=False)
    imuConverter = imuMsgConverter()

    try:
        imuConverter.imu_data_converter()
    except rospy.ROSInterruptException:
        pass

if __name__ == "__main__":
    main()
        