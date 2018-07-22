#!/usr/bin/env python

"""
Publishes the lane offset from raw image input as a data type Float32

Subscribes to:
    /imtalker/image_raw
Publishes to:
    /lane_offset

"""
import rospy
import cv2
from std_msgs.msg import Float32
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from get_offset import get_offset

def main():
    # Initialize node
    rospy.init_node('offset_pub')
    rospy.loginfo("Offset Publisher Node Initialized")
    
    # Subscribe to recieved raw camera input
    image_subscribe = rospy.Subscriber('/raw_USBcamera_images', Image, interpretImage)

def interpretImage(msg):
    # Initialize publisher
    offset_publisher= rospy.Publisher('/lane_offset', Float32, queue_size=1)
    
    # Open bridge to convert image message to a matrix (Mat)
    cvBridge= CvBridge()
    
    # Get frame recieved
    frameRecieved= cvBridge.imgmsg_to_cv2(msg)  
    
    # With given frame publish information about the offset
    # Only publish if image is not empty
    if frameRecieved is not None:
        lane_offset= get_offset(frameRecieved)  
        offset_publisher.publish(lane_offset)
        rospy.loginfo("Lane offset: %f",lane_offset)

if __name__ == '__main__':
    try:
        main()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
