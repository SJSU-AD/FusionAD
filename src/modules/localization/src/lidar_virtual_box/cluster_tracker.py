#!/usr/bin/env python
"""
NOTE: Tracks the cluster centroid velocities and locations over time. Velocities are calculated 
      by backward differencing. 

         Subscribes
         ----------
         Topic: /perception/cluster_locations
            Msg: interface/Cluster_bound_list
"""

import rospy
from interface.msg import Cluster_bound_list, Cluster_bound

class ClusterTracking(object):
    """Class that tracks the movement of clusters"""
    def __init__(self):
        pass

    def cluster_callback(self, cluster_msgs):
        """Callback for the clusters"""
        
    def cluster_tracker(self):
        """Track the position and velocity of the clusters over time"""
        rospy.Subscriber("/perception/cluster_locations", Cluster_bound_list, self.cluster_callback, queue_size=1)
        rospy.spin()

def main():
    rospy.init_node("cluster_tracking_node", anonymous=False)
    clusterTracking = ClusterTracking()

    try:
        clusterTracking.cluster_tracker()
    except rospy.ROSInterruptException:
        pass

if __name__ == "__main__":
    main()
