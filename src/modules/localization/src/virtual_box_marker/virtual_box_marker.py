#!/usr/bin/env python

"""
NOTE: Generates a rectangular box in front of the vehicle in rviz that represents the lidar virtual box. This is purely
      for visualizing the lidar points that are in the virtual box. Uses the parameters in the virtual box launch file

      Publishes
      ---------
      Topic: /virtual_box_visualization
        Msg: geometry_msgs/Polygon
"""

import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PolygonStamped, Point32

class VirtualBox(object):
    """Publishes a box in rviz from parameters in the virtual box launch file"""

    def __init__(self):
        """Initializing MarkerArray message publisher"""
        self.virtualBoxFrontPublisher = rospy.Publisher("/virtual_box_front_visualization", PolygonStamped, queue_size=1)
        self.virtualBoxRearPublisher = rospy.Publisher("/virtual_box_rear_visualization", PolygonStamped, queue_size=1)
        self.virtualBoxRightPublisher = rospy.Publisher("/virtual_box_right_visualization", PolygonStamped, queue_size=1)
        self.virtualBoxLeftPublisher = rospy.Publisher("/virtual_box_left_visualization", PolygonStamped, queue_size=1)
    
    def vbox_callback(self, event):
        """Timer callback for the polygon, creation @ 20 hz"""
        self.create_virtual_box_base_link()

    def create_virtual_box_base_link(self):
        """Compose and publish PolygonStamped message in the base_link frame"""
        polygonFrontMsg = PolygonStamped()
        polygonRearMsg = PolygonStamped()
        polygonRightMsg = PolygonStamped()
        polygonLeftMsg = PolygonStamped()

        # vbox_x_lower_bound = rospy.get_param('/virtual_box_counter/x_lower_bound')
        # vbox_x_upper_bound = rospy.get_param('/virtual_box_counter/x_upper_bound')
        
        # vbox_y_lower_bound = rospy.get_param('/virtual_box_counter/y_lower_bound')
        # vbox_y_upper_bound = rospy.get_param('/virtual_box_counter/y_upper_bound')

        # vbox_z_lower_bound = rospy.get_param('/virtual_box_counter/z_lower_bound')
        # vbox_z_upper_bound = rospy.get_param('/virtual_box_counter/z_upper_bound')

        vbox_x_lower_bound = 0
        vbox_x_upper_bound = 1

        vbox_y_lower_bound = -0.5
        vbox_y_upper_bound = 0.5

        vbox_z_lower_bound = 0
        vbox_z_upper_bound = 1

        polygonFrontMsg.polygon.points = [Point32(vbox_x_lower_bound, vbox_y_lower_bound, vbox_z_lower_bound),
                                          Point32(vbox_x_lower_bound, vbox_y_lower_bound, vbox_z_upper_bound),
                                          Point32(vbox_x_lower_bound, vbox_y_upper_bound, vbox_z_upper_bound),
                                          Point32(vbox_x_lower_bound, vbox_y_upper_bound, vbox_z_lower_bound)]
        
        polygonRearMsg.polygon.points = [Point32(vbox_x_upper_bound, vbox_y_lower_bound, vbox_z_lower_bound),
                                         Point32(vbox_x_upper_bound, vbox_y_lower_bound, vbox_z_upper_bound),
                                         Point32(vbox_x_upper_bound, vbox_y_upper_bound, vbox_z_upper_bound),
                                         Point32(vbox_x_upper_bound, vbox_y_upper_bound, vbox_z_lower_bound)]

        polygonRightMsg.polygon.points = [Point32(vbox_x_lower_bound, vbox_y_upper_bound, vbox_z_upper_bound),
                                          Point32(vbox_x_lower_bound, vbox_y_upper_bound, vbox_z_lower_bound),
                                          Point32(vbox_x_upper_bound, vbox_y_upper_bound, vbox_z_lower_bound),
                                          Point32(vbox_x_upper_bound, vbox_y_upper_bound, vbox_z_upper_bound)]
        
        polygonLeftMsg.polygon.points = [Point32(vbox_x_lower_bound, vbox_y_lower_bound, vbox_z_lower_bound),
                                         Point32(vbox_x_lower_bound, vbox_y_lower_bound, vbox_z_upper_bound),
                                         Point32(vbox_x_upper_bound, vbox_y_lower_bound, vbox_z_upper_bound),
                                         Point32(vbox_x_upper_bound, vbox_y_lower_bound, vbox_z_lower_bound)]

        polygonFrontMsg.header.frame_id = "base_link"
        polygonRearMsg.header.frame_id = "base_link"
        polygonRightMsg.header.frame_id = "base_link"
        polygonLeftMsg.header.frame_id = "base_link"

        polygonFrontMsg.header.stamp = rospy.Time.now()
        polygonRearMsg.header.stamp = rospy.Time.now()
        polygonRightMsg.header.stamp = rospy.Time.now()
        polygonLeftMsg.header.stamp = rospy.Time.now()

        self.virtualBoxFrontPublisher.publish(polygonFrontMsg)
        self.virtualBoxRearPublisher.publish(polygonRearMsg)
        self.virtualBoxRightPublisher.publish(polygonRightMsg)
        self.virtualBoxLeftPublisher.publish(polygonLeftMsg)

    def virtual_box_creation(self):
        """Create a polygon message and publish to rviz for visualization"""
        rospy.Timer(rospy.Duration(0.05), self.vbox_callback)
        rospy.spin()

def main():
    rospy.init_node("virtual_box_poly_node", anonymous=False)
    virtualBoxCreator = VirtualBox()

    try:
        virtualBoxCreator.virtual_box_creation()
    except rospy.ROSInterruptException:
        pass

if __name__ == "__main__":
    main()
