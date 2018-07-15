#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""Logs detected lane info to screen.
Subscribed to:
    /lane_coeff_generation/coeffs

Publishes to:
    None
"""

from __future__ import division
from __future__ import print_function

import rospy
from perception.msg import video

#callback function
def MessageReceived(msg):
    #print the message
    rospy.loginfo(' slopel=' + str(msg.m1)
                  + ' slope2=' + str(msg.m2) + '  inter1=' + str(msg.c1)+ '  inter2=' + str(msg.c2))

def main():
    try:
	#initialize the node
        rospy.init_node('subscribe_to_coeff')
	
    #create subscriber object        
	rospy.Subscriber('/lane_coeff_generation/coeffs', video, MessageReceived, queue_size=1000)

	#wait for message to be published        
	rospy.spin()

    except rospy.ROSInterruptException:
		pass
        
if __name__ == '__main__':
    main()
