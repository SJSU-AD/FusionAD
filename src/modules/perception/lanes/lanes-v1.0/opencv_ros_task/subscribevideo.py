#!/usr/bin/python
import rospy
from rospy.numpy_msg import numpy_msg
from beginner_tutorials.msg import video
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
import numpy as np
import cv2
x3=0
y3=0
x4=0
y4=0
x5=0
y5=0
x6=0
y6=0
mleft=0
mright=0
pub=rospy.Publisher('coeffs',video,queue_size=1000)
msg=video()
def poseMessageReceived(pic):
    global x3,y3,x4,y4,x5,y5,x6,y6,mleft,mright
    converter=CvBridge()
    img=converter.imgmsg_to_cv2(pic,"bgr8")
    img_gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    #converting to hsv to extract yellow
    img_hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
    img_gray=cv2.equalizeHist(img_gray)
    #bitwise_and to extract white
    a=cv2.bitwise_and(img[:,:,0],img[:,:,1])
    c=cv2.bitwise_and(a,img[:,:,2])
    c_hsv=cv2.cvtColor(c,cv2.COLOR_GRAY2BGR)
    c_hsv=cv2.cvtColor(c_hsv,cv2.COLOR_BGR2HSV)
    #thresholds for yellow and white
    lower_yellow = np.array([20, 40, 10], dtype = "uint8")
    upper_yellow = np.array([30, 255, 255], dtype="uint8")
    kernel = np.ones((6,6),np.uint8)
    kernel2 = np.ones((3,3),np.uint8)
    lower_white = np.array([0, 0,190], dtype = "uint8")
    upper_white = np.array([0, 0, 255], dtype="uint8")
    #creating the masks
    mask_yellow = cv2.inRange(img_hsv, lower_yellow, upper_yellow)
    mask_yellow=cv2.morphologyEx(mask_yellow,cv2.MORPH_OPEN,kernel)
    mask_yellow=cv2.morphologyEx(mask_yellow,cv2.MORPH_OPEN,kernel)
    mask_white = cv2.inRange(c_hsv, lower_white, upper_white)
    mask_white=cv2.morphologyEx(mask_white,cv2.MORPH_OPEN,kernel2)
    #making mask to extract ROI
    mask_trap=np.zeros_like(img_gray)
    points = np.array([[int(img.shape[1]/3),int(img.shape[0])-int(img.shape[0]/3)],[img.shape[1]-int(img.shape[1]/3),int(img.shape[0])-int(img.shape[0]/3)], [img.shape[1]-int(img.shape[1]/10),int(img.shape[0])-int(img.shape[0]/15)],[int(img.shape[1]/10),int(img.shape[0])-int(img.shape[0]/15)] ], np.int32)
    cv2.fillPoly(mask_trap,[points],255)
    #lane computation for left lane
    """
    So we fistly us the masks and use canny edges
    We find contours in the canny edges image
    Using the contour points we make lines using polylines
    Than use HoughLinesP to ony take the most prominant line which will mostly be our lane
    We do this seperately for left and right lanes assumng left lane is yellow and right lane is white
    """
    blur=cv2.bitwise_and(mask_yellow,mask_trap)
    blur=cv2.GaussianBlur(blur,(5,5),0)
    blur=cv2.inRange(blur,200,250)
    edges=cv2.Canny(blur,800,900)
    _,contours, hierarchy = cv2.findContours(edges,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    left_contours=np.zeros((1,2))
    for i in range(len(contours)):
        if contours[i][0][0][0]<img.shape[1]/2-img.shape[1]/20:
            for j in range(len(contours[i])):
                left_contours = np.vstack((left_contours,np.array(contours[i][j][0]).reshape((1,2))))
    left_contours=left_contours[1:,:] 
    cv2.polylines(edges,np.int32([left_contours]),False,255,thickness=5)
    lines = cv2.HoughLinesP(edges[:,0:int(img.shape[1]/3)],1,np.pi/180,100,40,1)
    rospy.loginfo("here1")
    lines2 = cv2.HoughLinesP(edges[:,int(img.shape[1]-img.shape[1]/3):],1,np.pi/180,100,40,1)
    if lines is not None:
	rospy.loginfo("here2")
        for x1,y1,x2,y2 in lines[0]:
            x5=x1
            y5=y1
            x6=x2
            y6=y2
            cv2.line(img,(x1,y1),(x2,y2),(0,255,0),5)
    #lane computation for right lane
    blur=cv2.bitwise_and(mask_white,mask_trap)
    blur=cv2.GaussianBlur(blur,(5,5),0)
    blur=cv2.inRange(blur,200,250)
    edges=cv2.Canny(blur,800,900)
    _,contours, hierarchy = cv2.findContours(edges,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    right_contours=np.zeros((1,2))
    for i in range(len(contours)):
        if contours[i][0][0][0]>img.shape[1]/2+img.shape[1]/20:
            for j in range(len(contours[i])):
                right_contours = np.vstack((right_contours,np.array(contours[i][j][0]).reshape((1,2))))
    right_contours=right_contours[1:,:]
    cv2.polylines(edges,np.int32([right_contours]),False,255,thickness=5)
    lines2 = cv2.HoughLinesP(edges[:,int(img.shape[1]-img.shape[1]/3):],1,np.pi/180,100,0,1)
    rospy.loginfo("here3")
    if lines2 is not None:
	rospy.loginfo("here4")
        for x1,y1,x2,y2 in lines2[0]:
            x3=x1
            y3=y1
            x4=x2
            y4=y2
            cv2.line(img[:,int(img.shape[1]-img.shape[1]/3):],(x1,y1),(x2,y2),(0,255,0),5)
    #slope and intercept calculations
    if(x3-x4!=0):
    	mleft=float((y3-y4)/(x3-x4))
	cleft=float((-(x4*(y4-y3))/(x4-x3))+y4)
    if(x5-x6!=0):
    	mright=float((y5-y6)/(x5-x6))
	cright=float((-(x6*(y6-y5))/(x6-x5))+y6)
    msg.m1=mleft
    msg.m2=mright
    msg.c1=cleft
    msg.c2=cright
    #publish the slope and intercets in a new topic
    pub.publish(msg)

if __name__ == '__main__':
    try:
        #initialize node
        rospy.init_node('subscribevideo')
        #create subscriber object
        rospy.Subscriber('chatter', Image, poseMessageReceived,
                         queue_size=1000)
        #wait for message to be published so callback can be called
        rospy.spin()
    except rospy.ROSInterruptException:
	pass
