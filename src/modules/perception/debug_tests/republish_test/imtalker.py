#!/usr/bin/env python

"""
Publishes images from camera and publishes them as ROS message.

Taken from page 12 of: https://www.cvl.isy.liu.se/education/graduate/opencv/Lecture14_ROSPython.pdf
- modified with code from "simpub_img_cap.py"

Subscribes to:
    None

Publishes to:
    /imtalker/image_raw

NOTE: Original code used "capture.retrieve()" instead of "capture.read()". 
This returned an image where all pixels were set to [0, 154, 0] (neon green color)
"""

from __future__ import division
from __future__ import print_function
import rospy

from rospy.numpy_msg import numpy_msg
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

import numpy as np
import cv2
import os

def imtalker():
    rospy.init_node('imtalker', anonymous=True)
    
    pub = rospy.Publisher('imtalker/image_raw', Image, queue_size=1000)
    rate = rospy.Rate(2) # 2hz

    br = CvBridge()

    capture = cv2.VideoCapture(0)

    # print("status of rospy.is_shutdown: {}".format(rospy.is_shutodwn()))
    while not rospy.is_shutdown():
        if (capture.isOpened()):
            # read next frame
            status,img = capture.read()
            
            if status==False:
				rospy.loginfo("False")
				os.system('rosnode kill --all')

            msg = br.cv2_to_imgmsg(img, "bgr8")

            # publish the message
            pub.publish(msg)

            # print("Status is: {}".format(status))
            # rospy.loginfo('published image')

            # print image numpy representation in terminal
            rospy.loginfo(img)
            # rate.sleep()
        else:
			rospy.loginfo("cap is not opened")
			os.system('rosnode kill --all')

def main():
    try:
        imtalker()
    except rospy.ROSInterruptException: 
        pass

if __name__ == '__main__':
    main()