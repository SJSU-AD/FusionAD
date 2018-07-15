#!/usr/bin/env python

"""
Listens to images from "imlistener" topic and shows the image on the screen

Taken from page 14 of: https://www.cvl.isy.liu.se/education/graduate/opencv/Lecture14_ROSPython.pdf

Subscribes to: 
    /simpub_img_cap/image_raw

Publishes to: 
    /lane_coeff_generation/coeffs
"""

from __future__ import division
from __future__ import print_function
import rospy

from sensor_msgs.msg import Image
from cv_bridge import CvBridge

import cv2

def callback(data):
    br = CvBridge()
    rospy.loginfo('receiving image')
    cv2.imshow("camera", br.imgmsg_to_cv2(data, "bgr8"))
    cv2.waitKey(1)

def imlistener():
    rospy.init_node('imlistener', anonymous=True)
    rospy.Subscriber('/imtalker/image_raw', Image, callback, queue_size=1000)
    rospy.spin()
    cv2.destroyAllWindows()

def main():
    imlistener()

if __name__ == '__main__':
    main()