#!/usr/bin/env python

"""
NOTE: Generates two circles in rviz to represent the donut waypoint selector in the control stack.
      ---------
      Topic: /virtual_donut_visualization
        Msg: visualization_msgs/Marker
"""

import rospy
import math
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point

class VirtualDonut(object):
    """Publishes a donut in rviz from parameters in the control launch file"""

    def __init__(self):
        """Initializing MarkerArray message publisher"""
        self.innerDonutPublisher = rospy.Publisher("/inner_donut_visualization", Marker, queue_size=1)
        self.outerDonutPublisher = rospy.Publisher("/outer_donut_visualization", Marker, queue_size=1)
        
        self.point_initialization_state = True

        self.marker_initialization()
    
    def vdonut_callback(self, event):
        """Timer callback for the polygon, creation @ 40 hz"""
        self.create_virtual_donut()

    def marker_initialization(self):
        """Create the Marker() messages for donut creation"""
        self.innerDonutMsg = Marker()
        self.outerDonutMsg = Marker()

        inner_donut_bound = rospy.get_param('/control_core/waypoint_lookahead_range')
        outer_donut_bound = rospy.get_param('/control_core/waypoint_proximity_range')
        
        point_density = rospy.get_param('/virtual_donut_node/point_density')

        msg_scale = rospy.get_param('/virtual_donut_node/msg_scale')
        
        inner_donut_r = rospy.get_param('/virtual_donut_node/inner_donut_r')
        inner_donut_g = rospy.get_param('/virtual_donut_node/inner_donut_g')
        inner_donut_b = rospy.get_param('/virtual_donut_node/inner_donut_b')
        inner_donut_a = rospy.get_param('/virtual_donut_node/inner_donut_a')

        outer_donut_r = rospy.get_param('/virtual_donut_node/outer_donut_r')
        outer_donut_g = rospy.get_param('/virtual_donut_node/outer_donut_g')
        outer_donut_b = rospy.get_param('/virtual_donut_node/outer_donut_b')
        outer_donut_a = rospy.get_param('/virtual_donut_node/outer_donut_a')

        self.innerDonutMsg.scale.x = msg_scale
        self.innerDonutMsg.scale.y = msg_scale
        self.innerDonutMsg.scale.z = msg_scale

        self.outerDonutMsg.scale.x = msg_scale
        self.outerDonutMsg.scale.y = msg_scale
        self.outerDonutMsg.scale.z = msg_scale

        self.innerDonutMsg.type = 8
        self.outerDonutMsg.type = 8

        self.innerDonutMsg.color.a = inner_donut_a
        self.innerDonutMsg.color.r = inner_donut_r
        self.innerDonutMsg.color.g = inner_donut_g
        self.innerDonutMsg.color.b = inner_donut_b
        
        self.outerDonutMsg.color.a = outer_donut_a
        self.outerDonutMsg.color.r = outer_donut_r
        self.outerDonutMsg.color.g = outer_donut_g
        self.outerDonutMsg.color.b = outer_donut_b

        if self.point_initialization_state:
            # calculate the placement of each point in polar coordinates
            for i in range(0, point_density):
                point_density_increment = 360 / point_density

                x_inner_donut = inner_donut_bound * math.cos(point_density_increment*i)
                y_inner_donut = inner_donut_bound * math.sin(point_density_increment*i)

                x_outer_donut = outer_donut_bound * math.cos(point_density_increment*i)
                y_outer_donut = outer_donut_bound * math.sin(point_density_increment*i)

                self.innerDonutMsg.points.append(Point(x_inner_donut, y_inner_donut, 0))
                self.outerDonutMsg.points.append(Point(x_outer_donut, y_outer_donut, 0))
            
            self.point_initialization_state = False

        self.innerDonutMsg.header.frame_id = "base_link"
        self.outerDonutMsg.header.frame_id = "base_link"

    def create_virtual_donut(self):
        """Publish marker messages in the base_link frame"""
        self.innerDonutMsg.header.stamp = rospy.Time.now()
        self.outerDonutMsg.header.stamp = rospy.Time.now()

        self.innerDonutPublisher.publish(self.innerDonutMsg)
        self.outerDonutPublisher.publish(self.outerDonutMsg)
        
    def virtual_donut_creation(self):
        """Create marker messages and publish to rviz for visualization"""
        rospy.Timer(rospy.Duration(0.025), self.vdonut_callback)
        rospy.spin()

def main():
    rospy.init_node("virtual_donut_node", anonymous=False)
    virtualDonutCreator = VirtualDonut()

    try:
        virtualDonutCreator.virtual_donut_creation()
    except rospy.ROSInterruptException:
        pass

if __name__ == "__main__":
    main()
    