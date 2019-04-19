#!/usr/bin/env python
"""
NOTE: Takes the Cluster_bound_list msg and then produces Marker cubes for visualization of 
      cluster centroid location as well as boundaries. 

      Subscribes
      ----------
      Topic: /perception/cluster_locations
        Msg: interface/Cluster_bound_list

      Publishes
      ---------
      Topic: /cluster_visualization
        Msg: visualization_msgs/MarkerArray
"""

import rospy
from visualization_msgs.msg import MarkerArray
from visualization_msgs.msg import Marker
from interface.msg import Cluster_bound_list
from interface.msg import Cluster_bound

class ClusterVisuals(object):
    """Class to facilitate visualization of the cluster locations and bounds"""
    def __init__(self):
        """Initializing MarkerArray publisher"""
        self.clusterVisPublisher = rospy.Publisher("/cluster_visualization", MarkerArray, queue_size=1)
        self.marker_array_initialization()

    def marker_array_initialization(self):
        """Function to set the RGBA values of each cube"""
        self.cube_r = rospy.get_param('/cluster_visualization_node/cube_r')
        self.cube_g = rospy.get_param('/cluster_visualization_node/cube_g')
        self.cube_b = rospy.get_param('/cluster_visualization_node/cube_b')
        self.cube_a = rospy.get_param('/cluster_visualization_node/cube_a')

    def cluster_callback(self, cluster_msgs):
        """Callback to the Cluster_bound_list msg"""
        clusterVisArray = MarkerArray()
        
        for i in range(cluster_msgs.num_clusters):
            # generate a new Marker msg and then append to the clusterVisArray
            clusterVis = Marker()

            clusterVis.header.frame_id = "/velodyne"
            clusterVis.header.stamp = rospy.Time.now()
            
            # create cubes
            clusterVis.type = 1

            # assign id to allow more than 1 marker to be shown
            clusterVis.id = i

            # add a new marker in this action
            clusterVis.action = 0

            nano_seconds = rospy.get_param('/cluster_visualization_node/cube_lifetime')
            # cube_lifetime = rospy.Duration(0, nano_seconds * 1000000000)
            clusterVis.lifetime = rospy.Duration(0, nano_seconds * 1000000000)
            # clusterVis.lifetime = cube_lifetime

            # set the color and opaqueness
            clusterVis.color.r = self.cube_r
            clusterVis.color.g = self.cube_g
            clusterVis.color.b = self.cube_b
            clusterVis.color.a = self.cube_a

            # set the position of the center of the cube
            clusterVis.pose.position.x = cluster_msgs.cluster_bounds[i].centroid_location.x
            clusterVis.pose.position.y = cluster_msgs.cluster_bounds[i].centroid_location.y
            clusterVis.pose.position.z = cluster_msgs.cluster_bounds[i].centroid_location.z
            
            # set the orientation of the cube
            clusterVis.pose.orientation.x = 0
            clusterVis.pose.orientation.y = 0
            clusterVis.pose.orientation.z = 0
            clusterVis.pose.orientation.w = 1

            # # set the boundaries of the cube
            clusterVis.scale.x = 0.1
            clusterVis.scale.y = 0.1
            clusterVis.scale.z = 0.1

            clusterVisArray.markers.append(clusterVis)
        
        self.clusterVisPublisher.publish(clusterVisArray)

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
