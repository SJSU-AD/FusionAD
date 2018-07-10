#!/usr/bin/python

"""This is the file used to publish the frames of the video 

Subscribes to:
    None

Publishes to:
    /simpub_img_cap/image_raw
"""

import numpy as np
import rospy
from rospy.numpy_msg import numpy_msg
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
import random
import os
import cv2

def simpub():
        #initiate the node
	rospy.init_node('simpub')
        #create the cap object
	cap=cv2.VideoCapture(1)
	#create the publisher object	
	pub=rospy.Publisher('/simpub_img_cap/image_raw',Image,queue_size=1000)
	#create the converter for the image into a transmittable message	
	converter=CvBridge()
        #check if node has been killed or not
	while not rospy.is_shutdown():
		if (cap.isOpened()):                
			#read the next frame
			ret,img=cap.read()
			if ret==False:
				rospy.loginfo("False")
				os.system('rosnode kill --all')

			#convert from a numpy array to ros image		
			msg=converter.cv2_to_imgmsg(img,"bgr8")
		        
			#publish the message
			pub.publish(msg)
		        
			#print in terminal
			rospy.loginfo(img)

			# view image
			# cv2.imshow('raw input video', img)
		else:
			rospy.loginfo("cap is not opened")
			os.system('rosnode kill --all')
	

if __name__ == '__main__':
	try:
		simpub()
	except rospy.ROSInterruptException:
		pass
