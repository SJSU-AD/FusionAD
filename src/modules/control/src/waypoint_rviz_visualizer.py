#!/usr/bin/env python

"""
NOTE: Generates two circles in rviz to represent the donut waypoint selector in the control stack.
      ---------
      Topic: /virtual_donut_visualization
        Msg: geometry_msgs/Polygon
"""

import rospy
import math
from geometry_msgs.msg import PolygonStamped, Point32

class VirtualDonut(object):
    """Publishes a donut in rviz from parameters in the control launch file"""

    def __init__(self):
        """Initializing MarkerArray message publisher"""
        self.innerDonutPublisher = rospy.Publisher("/inner_donut_visualization", PolygonStamped, queue_size=1)
        self.outerDonutPublisher = rospy.Publisher("/outer_donut_visualization", PolygonStamped, queue_size=1)

        self.innerDonutMsg = PolygonStamped()
        self.outerDonutMsg = PolygonStamped()
        
        self.point_initialization_state = True
    
    def vdonut_callback(self, event):
        """Timer callback for the polygon, creation @ 20 hz"""
        self.create_virtual_donut()

    def create_virtual_donut(self):
        """Compose and publish PolygonStamped message in the base_link frame"""
        # inner_donut_bound = rospy.get_param('/control_core/waypoint_lookahead_range')
        # outer_donut_bound = rospy.get_param('/control_core/waypoint_proximity_range')
        # point_density = rospy.get_param('/virtual_donut_node/point_density')
        
        inner_donut_bound = 1
        outer_donut_bound = 3
        point_density = 100

        if self.point_initialization_state:
            # calculate the placement of each point
            for i in range(0, point_density):
                point_density_increment = 360 / point_density

                x_inner_donut = inner_donut_bound * math.cos(point_density_increment*i)
                y_inner_donut = inner_donut_bound * math.sin(point_density_increment*i)

                x_outer_donut = outer_donut_bound * math.cos(point_density_increment*i)
                y_outer_donut = outer_donut_bound * math.sin(point_density_increment*i)

                self.innerDonutMsg.polygon.points.append(Point32(x_inner_donut, y_inner_donut, 0))
                self.outerDonutMsg.polygon.points.append(Point32(x_outer_donut, y_outer_donut, 0))
            
            self.point_initialization_state = False

        self.innerDonutMsg.header.frame_id = "base_link"
        self.outerDonutMsg.header.frame_id = "base_link"
        
        self.innerDonutMsg.header.stamp = rospy.Time.now()
        self.outerDonutMsg.header.stamp = rospy.Time.now()

        self.innerDonutPublisher.publish(self.innerDonutMsg)
        self.outerDonutPublisher.publish(self.outerDonutMsg)
        
    def virtual_donut_creation(self):
        """Create a polygon message and publish to rviz for visualization"""
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
    