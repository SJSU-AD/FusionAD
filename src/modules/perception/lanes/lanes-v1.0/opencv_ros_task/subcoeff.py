#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from beginner_tutorials.msg import video

#callback function
def MessageReceived(msg):
    #print the message
    rospy.loginfo(' slopel=' + str(msg.m1)
                  + ' slope2=' + str(msg.m2) + '  inter1=' + str(msg.c1)+ '  inter2=' + str(msg.c2))


if __name__ == '__main__':
    try:
	#initialize the node
        rospy.init_node('subscribe_to_coeff')
	#create subscriber object        
	rospy.Subscriber('coeffs', video, MessageReceived,
                         queue_size=1000)

	#wait for message to be published        
	rospy.spin()
    except rospy.ROSInterruptException:
		pass
