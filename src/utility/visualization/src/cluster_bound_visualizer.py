#!/usr/bin/env python
"""
NOTE: Takes the Cluster_bound_list msg and then produces Marker cubes for visualization of 
      cluster centroid location. Line points are used for bounding box visualization.

      Subscribes
      ----------
      Topic: /perception/cluster_locations
        Msg: interface/Cluster_bound_list

      Publishes
      ---------
      Topic: /cluster_centroid_visualization
        Msg: visualization_msgs/MarkerArray

      Topic: /cluster_bounding_box_visualization
        Msg: visualization_msgs/MarkerArray
"""

import rospy
from visualization_msgs.msg import MarkerArray, Marker
from interface.msg import Cluster_bound_list, Cluster_bound
from geometry_msgs.msg import Point32

class ClusterVisuals(object):
    """Class to facilitate visualization of the cluster locations and bounds"""
    def __init__(self):
        """Initializing MarkerArray publisher"""
        self.clusterCentroidVisPublisher = rospy.Publisher("/cluster_centroid_visualization", MarkerArray, queue_size=1)
        self.clusterBoundingBoxVisPublisher = rospy.Publisher("/cluster_bounding_box_visualization", MarkerArray, queue_size=1)

        self.marker_array_initialization()

    def marker_array_initialization(self):
        """Function to set the RGBA and scale values of each cube and line strip"""
        # centroid location rgba and xyz scale
        self.cube_r = rospy.get_param('/cluster_visualization_node/cube_r')
        self.cube_g = rospy.get_param('/cluster_visualization_node/cube_g')
        self.cube_b = rospy.get_param('/cluster_visualization_node/cube_b')
        self.cube_a = rospy.get_param('/cluster_visualization_node/cube_a')

        self.scale_x = rospy.get_param('/cluster_visualization_node/scale_x')
        self.scale_y = rospy.get_param('/cluster_visualization_node/scale_y')
        self.scale_z = rospy.get_param('/cluster_visualization_node/scale_z')

        # centroid cube and line strip lifetime in rviz
        self.nano_seconds = rospy.get_param('/cluster_visualization_node/cube_lifetime')

        # line strip width
        self.line_strip_width = rospy.get_param('/cluster_visualization_node/line_strip_width')

    def cluster_callback(self, cluster_msgs):
        """Callback to the Cluster_bound_list msg"""
        clusterCentroidVisArray = MarkerArray()

        clusterBoundingBoxVisArray = MarkerArray()
        
        for i in range(cluster_msgs.num_clusters):
            # generate a new Marker msg and then append to the clusterCentroidVisArray
            clusterCentroidVis = Marker()
            clusterBoundingBoxVis = Marker()

            # stuff the centroid visualization info into the Marker() msg
            clusterCentroidVis = self.centroid_visualization(cluster_msgs.cluster_bounds[i], i)

            # stuff the bounding box visualization info into the Marker() msg
            clusterBoundingBoxVis = self.bounding_box_visualization(cluster_msgs.cluster_bounds[i], i)

            clusterCentroidVisArray.markers.append(clusterCentroidVis)
            clusterBoundingBoxVisArray.markers.append(clusterBoundingBoxVis)
        
        self.clusterCentroidVisPublisher.publish(clusterCentroidVisArray)
        self.clusterBoundingBoxVisPublisher.publish(clusterBoundingBoxVisArray)
    
    def bounding_box_visualization(self, in_cluster_msg, index):
        """Generate the Marker message for bounding box visualization"""
        outClusterBoundsVis = Marker()

        outClusterBoundsVis.header.frame_id = "/velodyne"
        outClusterBoundsVis.header.stamp = rospy.Time.now()

        # generate a line strip
        outClusterBoundsVis.type = 4

        # assign id to allow more than 1 marker to be shown
        outClusterBoundsVis.id = index

        # add a new marker in this action
        outClusterBoundsVis.action = 0

        # nano_seconds*1000000000 nanoseconds to seconds conversion
        outClusterBoundsVis.lifetime = rospy.Duration(0, self.nano_seconds * 1000000000)
        
        # set the color and opaqueness
        outClusterBoundsVis.color.r = self.cube_r
        outClusterBoundsVis.color.g = self.cube_g
        outClusterBoundsVis.color.b = self.cube_b
        outClusterBoundsVis.color.a = self.cube_a

        # set the width of the line strip
        outClusterBoundsVis.scale.x = self.line_strip_width

        # set the origin to be at the lidar
        outClusterBoundsVis.pose.position.x = 0
        outClusterBoundsVis.pose.position.y = 0
        outClusterBoundsVis.pose.position.z = 0

        outClusterBoundsVis.pose.orientation.x = 0
        outClusterBoundsVis.pose.orientation.y = 0
        outClusterBoundsVis.pose.orientation.z = 0
        outClusterBoundsVis.pose.orientation.w = 1
        
        # define the bounds of the box
        x_min = in_cluster_msg.min_bound.x
        y_min = in_cluster_msg.min_bound.y
        z_min = in_cluster_msg.min_bound.z  

        x_max = in_cluster_msg.max_bound.x
        y_max = in_cluster_msg.max_bound.y
        z_max = in_cluster_msg.max_bound.z

        outClusterBoundsVis.points = [Point32(x_min, y_min, z_min),
                                      Point32(x_min, y_min, z_max),
                                      Point32(x_min, y_max, z_max),
                                      Point32(x_min, y_max, z_min),
                                      Point32(x_min, y_min, z_min),
                                      Point32(x_max, y_min, z_min),
                                      Point32(x_max, y_min, z_max),
                                      Point32(x_max, y_max, z_max),
                                      Point32(x_max, y_max, z_min),
                                      Point32(x_min, y_max, z_min),
                                      Point32(x_min, y_max, z_max),
                                      Point32(x_max, y_max, z_max),
                                      Point32(x_max, y_min, z_max),
                                      Point32(x_min, y_min, z_max),
                                      Point32(x_min, y_min, z_min),
                                      Point32(x_max, y_min, z_min),
                                      Point32(x_max, y_max, z_min)]

        return outClusterBoundsVis

    def centroid_visualization(self, in_cluster_msg, index):
        """Generate the Marker message for centroid visualization"""
        outClusterCentroidVis = Marker()

        outClusterCentroidVis.header.frame_id = "/velodyne"
        outClusterCentroidVis.header.stamp = rospy.Time.now()
        
        # create cubes
        outClusterCentroidVis.type = 1

        # assign id to allow more than 1 marker to be shown
        outClusterCentroidVis.id = index

        # add a new marker in this action
        outClusterCentroidVis.action = 0

        # nano_seconds*1000000000 nanoseconds to seconds conversion
        outClusterCentroidVis.lifetime = rospy.Duration(0, self.nano_seconds * 1000000000)

        # set the color and opaqueness
        outClusterCentroidVis.color.r = self.cube_r
        outClusterCentroidVis.color.g = self.cube_g
        outClusterCentroidVis.color.b = self.cube_b
        outClusterCentroidVis.color.a = self.cube_a

        # set the position of the center of the cube
        outClusterCentroidVis.pose.position.x = in_cluster_msg.centroid_location.x
        outClusterCentroidVis.pose.position.y = in_cluster_msg.centroid_location.y
        outClusterCentroidVis.pose.position.z = in_cluster_msg.centroid_location.z
        
        # set the orientation of the cube
        outClusterCentroidVis.pose.orientation.x = 0
        outClusterCentroidVis.pose.orientation.y = 0
        outClusterCentroidVis.pose.orientation.z = 0
        outClusterCentroidVis.pose.orientation.w = 1

        # set the boundaries of the cube
        outClusterCentroidVis.scale.x = self.scale_x
        outClusterCentroidVis.scale.y = self.scale_y
        outClusterCentroidVis.scale.z = self.scale_z

        return outClusterCentroidVis

    def marker_creation(self):
        """Create marker array messages and publish to rviz for cluster visualization"""
        rospy.Subscriber("/perception/cluster_locations", Cluster_bound_list, self.cluster_callback, queue_size=1)
        rospy.spin()

def main():
    rospy.init_node("cluster_visualization_node", anonymous=False)
    clusterCreation = ClusterVisuals()

    try:
        clusterCreation.marker_creation()
    except rospy.ROSInterruptException:
        pass

if __name__ == "__main__":
    main()
