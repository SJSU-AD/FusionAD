#!/usr/bin/env python

"""
NOTE: Generates a rectangular box in front of the vehicle in rviz that represents the lidar virtual box. This is purely
      for visualizing the lidar points that are in the virtual box. The code subscribes to the EKF output to get the 
      current position of the vehicle and then generates a box based off of the parameters set by the user in the 
      state_estimation.launch launch file. 

      Subscribes
      ----------
      Topic: /odometry/filtered
        Msg: nav_msgs/Odometry

      Publishes
      ---------
      Topic: /virtual_box_visualization
        Msg: geometry_msgs/Polygon
"""

import rospy
from nav_msgs import Odometry
from geometry_msgs import PolygonStamped, Point32

class VirtualBox(object):
    """Takes the odometry data from robot localization and publishes a virtual box"""

    def __init__(self):
        """Initializing MarkerArray message publisher"""
        self.virtualBoxPublisher = rospy.Publisher("/virtual_box_visualization", Polygon, queue_size = 0)

    def odom_callback(self, odomMsg):
        """Callback subscribed to the odometry message"""
        # generate and publish the virtual box
        create_virtual_box_poly(odomMsg.pose.pose.position.x, odomMsg.pose.pose.position.y)

    def create_virtual_box_poly(self, x, y):
        """Compose and publish PolygonStamped message"""
        # retrieve parameters from the launch file
        vbox_x_lower_bound = rospy.get_param('/virtual_box_counter/x_lower_bound')
        vbox_x_upper_bound = rospy.get_param('/virtual_box_counter/x_upper_bound')
        
        vbox_y_lower_bound = rospy.get_param('/virtual_box_counter/y_lower_bound')
        vbox_y_upper_bound = rospy.get_param('/virtual_box_counter/y_upper_bound')

        vbox_z_lower_bound = rospy.get_param('/virtual_box_counter/z_lower_bound')
        vbox_z_upper_bound = rospy.get_param('/virtual_box_counter/z_upper_bound')

        # assemble the polygon message 
        polygonMsg = PolygonStamped()

        # generating the points for the rectangular prism is separated into two rectangles
        # starting from the first rectangle closer to the vehicle at the bottom left corner and going clockwise
        polygonMsg.polygon.points = [Point32(vbox_x_lower_bound + x, vbox_y_lower_bound + y, z_lower_bound),
                                     Point32(vbox_x_lower_bound + x, vbox_y_lower_bound + y, z_upper_bound),
                                     Point32(vbox_x_lower_bound + x, vbox_y_upper_bound + y, z_upper_bound),
                                     Point32(vbox_x_lower_bound + x, vbox_y_upper_bound + y, z_lower_bound),
                                     Point32(vbox_x_upper_bound + x, vbox_y_lower_bound + y, z_lower_bound),
                                     Point32(vbox_x_upper_bound + x, vbox_y_lower_bound + y, z_upper_bound),
                                     Point32(vbox_x_upper_bound + x, vbox_y_upper_bound + y, z_upper_bound),
                                     Point32(vbox_x_upper_bound + x, vbox_y_upper_bound + y, z_lower_bound)]
        
        polygonMsg.frame_id = "odom"
        polygonMsg.stamp = rospy.Time.now()

        self.virtualBoxPublisher.publish(polygonMsg)

    def virtual_box_creation(self):
        """Take the EKF odom data, create a polygon message and publish to rviz for visualization"""
        rospy.Subscriber("/odometry/filtered", Odometry, self.odom_callback, queue_size=0)
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
