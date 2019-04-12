#!/usr/bin/env python

"""
NOTE: Generates two circles in rviz to represent the donut waypoint selector in the control stack.
      Shades in an area in the donut to represent the waypoint heading error range.

      Publisher
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
        self.headingShadePublisher = rospy.Publisher("/heading_donut_visualization", Marker, queue_size=1)

        self.point_initialization_state = True

        self.callback_interval = rospy.get_param('/virtual_donut_node/callback_interval')

        self.marker_initialization()

    def marker_initialization(self):
        """Create the Marker() messages for donut creation"""
        self.innerDonutMsg = Marker()
        self.outerDonutMsg = Marker()
        self.headingShadeMsg = Marker()

        inner_donut_bound = rospy.get_param('/control_core/waypoint_lookahead_range')
        outer_donut_bound = rospy.get_param('/control_core/waypoint_proximity_range')
        heading_error_range = rospy.get_param('/control_core/waypoint_heading_error_range')

        heading_shade_density = rospy.get_param('/virtual_donut_node/heading_shade_density')
        radius_shade_density = rospy.get_param('/virtual_donut_node/radius_shade_density')
        point_density = rospy.get_param('/virtual_donut_node/point_density')

        heading_msg_scale = rospy.get_param('/virtual_donut_node/heading_msg_scale')
        msg_scale = rospy.get_param('/virtual_donut_node/msg_scale')
        
        inner_donut_r = rospy.get_param('/virtual_donut_node/inner_donut_r')
        inner_donut_g = rospy.get_param('/virtual_donut_node/inner_donut_g')
        inner_donut_b = rospy.get_param('/virtual_donut_node/inner_donut_b')
        inner_donut_a = rospy.get_param('/virtual_donut_node/inner_donut_a')

        outer_donut_r = rospy.get_param('/virtual_donut_node/outer_donut_r')
        outer_donut_g = rospy.get_param('/virtual_donut_node/outer_donut_g')
        outer_donut_b = rospy.get_param('/virtual_donut_node/outer_donut_b')
        outer_donut_a = rospy.get_param('/virtual_donut_node/outer_donut_a')

        heading_shade_r = rospy.get_param('/virtual_donut_node/heading_shade_r')
        heading_shade_g = rospy.get_param('/virtual_donut_node/heading_shade_g')
        heading_shade_b = rospy.get_param('/virtual_donut_node/heading_shade_b')
        heading_shade_a = rospy.get_param('/virtual_donut_node/heading_shade_a')

        self.innerDonutMsg.scale.x = msg_scale
        self.innerDonutMsg.scale.y = msg_scale
        self.innerDonutMsg.scale.z = msg_scale

        self.outerDonutMsg.scale.x = msg_scale
        self.outerDonutMsg.scale.y = msg_scale
        self.outerDonutMsg.scale.z = msg_scale

        self.headingShadeMsg.scale.x = heading_msg_scale
        self.headingShadeMsg.scale.y = heading_msg_scale
        self.headingShadeMsg.scale.z = heading_msg_scale

        self.innerDonutMsg.type = 8
        self.outerDonutMsg.type = 8
        self.headingShadeMsg.type = 8

        self.innerDonutMsg.color.a = inner_donut_a
        self.innerDonutMsg.color.r = inner_donut_r
        self.innerDonutMsg.color.g = inner_donut_g
        self.innerDonutMsg.color.b = inner_donut_b
        
        self.outerDonutMsg.color.a = outer_donut_a
        self.outerDonutMsg.color.r = outer_donut_r
        self.outerDonutMsg.color.g = outer_donut_g
        self.outerDonutMsg.color.b = outer_donut_b

        self.headingShadeMsg.color.a = heading_shade_a
        self.headingShadeMsg.color.r = heading_shade_r
        self.headingShadeMsg.color.g = heading_shade_g
        self.headingShadeMsg.color.b = heading_shade_b

        if self.point_initialization_state:
            # calculate the placement of each point in polar coordinates
            for i in range(point_density):
                point_density_increment = (2*math.pi) / point_density

                x_inner_donut = inner_donut_bound * math.cos(point_density_increment*i)
                y_inner_donut = inner_donut_bound * math.sin(point_density_increment*i)

                x_outer_donut = outer_donut_bound * math.cos(point_density_increment*i)
                y_outer_donut = outer_donut_bound * math.sin(point_density_increment*i)

                self.innerDonutMsg.points.append(Point(x_inner_donut, y_inner_donut, 0))
                self.outerDonutMsg.points.append(Point(x_outer_donut, y_outer_donut, 0))
            
            # calculate the placement of each point in polar coordinates for heading shade
            for i in range(heading_shade_density):
                # angle for the sweep inside the donut
                angle_shade_density_increment = (heading_error_range) / heading_shade_density

                for j in range(radius_shade_density):
                    # outward radius for the sweep inside the donut
                    radius_shade_density_increment = (outer_donut_bound - inner_donut_bound) / radius_shade_density

                    x_shade_pos = (radius_shade_density_increment*j + inner_donut_bound) * (math.cos(angle_shade_density_increment*i - heading_error_range/2))
                    y_shade_pos = (radius_shade_density_increment*j + inner_donut_bound) * (math.sin(angle_shade_density_increment*i - heading_error_range/2))

                    self.headingShadeMsg.points.append(Point(x_shade_pos, y_shade_pos, 0))
                

            self.point_initialization_state = False

        self.innerDonutMsg.header.frame_id = "base_link"
        self.outerDonutMsg.header.frame_id = "base_link"
        self.headingShadeMsg.header.frame_id = "base_link"

    def create_virtual_donut(self, event):
        """Publish marker messages in the base_link frame @ rate given in launch file param"""
        self.innerDonutMsg.header.stamp = rospy.Time.now()
        self.outerDonutMsg.header.stamp = rospy.Time.now()
        self.headingShadeMsg.header.stamp = rospy.Time.now()

        self.innerDonutPublisher.publish(self.innerDonutMsg)
        self.outerDonutPublisher.publish(self.outerDonutMsg)
        self.headingShadePublisher.publish(self.headingShadeMsg)
        
    def virtual_donut_creation(self):
        """Create marker messages and publish to rviz for visualization"""
        rospy.Timer(rospy.Duration(self.callback_interval), self.create_virtual_donut)
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
    