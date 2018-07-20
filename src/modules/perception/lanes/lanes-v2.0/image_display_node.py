import cv2
import rospy
import numpy as numpy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

def interpretImage(msg):
    # Create bridge object to convert image message to cv2 image
    bridge= CvBridge()
    # 'imgmsg_to_cv2' converts the input (msg), which is of type 'sensor_msgs.msg._Image.Image',
    # converts it to a numpy array'
    frameRecieved= bridge.imgmsg_to_cv2(msg, "bgr8")
    # Displays image
    cv2.imshow('Camera Input', frameRecieved)
    cv2.waitKey(1)
    
def main():
    # Initialize node
    rospy.init_node('image_display')
    print 'Image display initialized'
    # Create subscriber and subscribe to raw image data
    image_subscribe = rospy.Subscriber('/raw_USBcamera_images', Image, interpretImage)
    rospy.spin()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass