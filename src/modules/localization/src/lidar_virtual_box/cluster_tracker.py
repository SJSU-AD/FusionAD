#!/usr/bin/env python
from __future__ import print_function
from __future__ import division

"""
NOTE: Tracks the cluster centroid velocities and locations over time by transforming to odom frame.
      Velocities are calculated by backward differencing. Produces a MarkerArray arrow for visualization of cluster velocity.

         Subscribes
         ----------
         Topic: /perception/cluster_locations
            Msg: interface/Cluster_bound_list
         
         Topic: /odometry/filtered
            Msg: nav_msgs/Odometry

         Publishes
         ---------
         Topic: /visualization/cluster_velocity
            Msg: visualization_msgs/MarkerArray

         Topic: /perception/obstacle_collision_prediction
            Msg: std_msgs/Bool

TODO: Take the size of the bounding box and the vehicle boundaries into account for impact calculation
TODO: Test code in front of car
"""

import rospy
from interface.msg import Cluster_bound_list, Cluster_bound
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Point32
import math
from visualization_msgs.msg import MarkerArray, Marker

class ClusterTracking(object):
    """Class that tracks the movement of clusters"""
    def __init__(self):
        """Initialize messages and get parameters"""
        self.clusterVelVisPublisher = rospy.Publisher('/cluster_velocity_visualization', MarkerArray, queue_size = 1)

        # keep track of the odometry msgs from the pose callback
        self.vehiclePos = Odometry()

        self.cluster_callback_time = 0
        self.prev_time = 0

        self.first_set_calculated = False
        
        # parameter for tolerance to determine whether the current measurement is of a centroid in a past frame
        self.movement_tolerance = rospy.get_param('cluster_tracking_node/movement_tolerance')
        
        # parameter for amount of time before warning the operator that an impact will occur with a cluster
        self.impact_time_const = rospy.get_param('cluster_tracking_node/impact_time_const')
        
        # parameter for the minimum velocity for publishing
        self.min_velocity_threshold = rospy.get_param('cluster_tracking_node/min_velocity_threshold')

        # need to keep track of the previous cluster positions
        self.previous_cluster_list = []

        self.vel_vector_vis_initialization()

        self.marker_index = 0

    def pose_callback(self, odomMsg):
        """Callback for the current position of the vehicle in odom frame"""
        self.vehiclePos = odomMsg

    def cluster_callback(self, clusterMsg):
        """Callback for the clusters"""
        # keep track of the time from each cluster msg
        self.cluster_callback_time = rospy.get_time()
        
        # keep track of the current cluster centroid positions
        cluster_tracking_list = []

        self.velocityVectorVisArray = MarkerArray()

        for i in range(clusterMsg.num_clusters):
            curr_x_centroid_pos = clusterMsg.cluster_bounds[i].centroid_location.x + self.vehiclePos.pose.pose.position.x
            curr_y_centroid_pos = clusterMsg.cluster_bounds[i].centroid_location.y + self.vehiclePos.pose.pose.position.y    
            
            cluster_tracking_list.append([curr_x_centroid_pos, curr_y_centroid_pos])
            
            # return a list containing information as to whether the cluster was from the previous frame
            """
            cluster_logistics[0] is True or False depending on whether the cluster was from the previous frame
            cluster_logistics[1] contains information from the x_position of the cluster from the previous frame
            cluster_logistics[2] contains information from the y_position of the cluster from the previous frame
            """
            cluster_logistics = self.cluster_from_previous(curr_x_centroid_pos, curr_y_centroid_pos)
            
            # if the current cluster was in the previous cluster list
            if(cluster_logistics[0]):
                self.velocity_calc(clusterMsg.cluster_bounds[i], cluster_logistics[1], cluster_logistics[2])
            
            self.marker_index = i

        self.previous_cluster_list = cluster_tracking_list

        if(len(self.velocityVectorVisArray.markers) > 0):
            self.clusterVelVisPublisher.publish(self.velocityVectorVisArray)


    def cluster_from_previous(self, input_x_pos, input_y_pos):
        """Function to check whether the input cluster's centroid was from a previous frame"""
        cluster_is_from_previous = False
        previous_cluster_x = 0
        previous_cluster_y = 0
        
        for i in range(len(self.previous_cluster_list)):
            # check whether the x and y conditions meet the tolerance for cluster centroid movement
            if((abs(input_x_pos - self.previous_cluster_list[i][0]) <= self.movement_tolerance) and (abs(input_y_pos - self.previous_cluster_list[i][1]) <= self.movement_tolerance)):
                cluster_is_from_previous = True
                previous_cluster_x = self.previous_cluster_list[i][0]
                previous_cluster_y = self.previous_cluster_list[i][1]
        
        return [cluster_is_from_previous, previous_cluster_x, previous_cluster_y]

    def velocity_calc(self, input_cluster, previous_x_pos, previous_y_pos):
        """Calculate the velocity of the input cluster"""
        # position of cluster with respect to odom frame in x and y
        cluster_x_pos = input_cluster.centroid_location.x + self.vehiclePos.pose.pose.position.x
        cluster_y_pos = input_cluster.centroid_location.y + self.vehiclePos.pose.pose.position.y
        
        # time_difference is set at 0.1 to prevent divide by 0 error
        time_difference = 0.1

        if(self.first_set_calculated):
            time_difference = self.cluster_callback_time - self.prev_time

        cluster_x_vel = (cluster_x_pos - previous_x_pos) / (time_difference)
        cluster_y_vel = (cluster_y_pos - previous_y_pos) / (time_difference)
        cluster_mag_vel = math.sqrt(cluster_x_vel**2 + cluster_y_vel**2)
        
        vehicle_impact_status = self.impact_check(cluster_x_pos, cluster_y_pos, cluster_x_vel, cluster_y_vel, cluster_mag_vel)
        
        if(vehicle_impact_status):
            print(vehicle_impact_status)

        if(cluster_mag_vel >= self.min_velocity_threshold):
            self.velocityVectorVisArray.markers.append(self.velocity_visualization(input_cluster.centroid_location.x, input_cluster.centroid_location.y, input_cluster.centroid_location.z, cluster_x_vel, cluster_y_vel))
        
        # store the previous time of the cluster
        self.prev_time = time_difference
        self.first_set_calculated = True
    
    def impact_check(self, x_pos, y_pos, x_vel, y_vel, vel_mag):
        """Check whether the car will hit the cluster in a configurable amount of time"""
        vehicle_impact_status = False

        if(vel_mag >= self.min_velocity_threshold):
            x_pos_impact_time = (self.vehiclePos.pose.pose.position.x - x_pos) / (self.vehiclePos.twist.twist.linear.x - x_vel)
            y_pos_impact_time = (self.vehiclePos.pose.pose.position.y - y_pos) / (self.vehiclePos.twist.twist.linear.y - y_vel)

            if((x_pos_impact_time <= self.impact_time_const) and (y_pos_impact_time <= self.impact_time_const) and (x_pos_impact_time > 0) and (y_pos_impact_time > 0)):
                vehicle_impact_status = True
        
        return vehicle_impact_status
            

    def velocity_visualization(self, cluster_x_pos, cluster_y_pos, cluster_z_pos, cluster_x_vel, cluster_y_vel):
        """Display an arrow in rviz that represents the velocity vector of the cluster"""
        velVectorMarker = Marker()
        
        velVectorMarker.header.frame_id = "/velodyne"
        velVectorMarker.header.stamp = rospy.Time.now()

        # create arrow 
        velVectorMarker.type = 0

        # each marker must have a unique ID
        velVectorMarker.id = self.marker_index

        # add a new marker 
        velVectorMarker.action = 0

        # RGBA values
        velVectorMarker.color.r = self.vel_vec_r
        velVectorMarker.color.g = self.vel_vec_g
        velVectorMarker.color.b = self.vel_vec_b
        velVectorMarker.color.a = self.vel_vec_a

        # scale of the vectors, assigned according to the configurable params
        velVectorMarker.scale.x = self.vel_vec_scale_x
        velVectorMarker.scale.y = self.vel_vec_scale_y
        velVectorMarker.scale.z = self.vel_vec_scale_z

        velVectorMarker.lifetime = rospy.Duration(0, self.vel_vec_nano_seconds*1000000000)

        predicted_x_pos = cluster_x_pos + cluster_x_vel*(self.cluster_callback_time - self.prev_time)
        predicted_y_pos = cluster_y_pos + cluster_y_vel*(self.cluster_callback_time - self.prev_time)

        velVectorMarker.points = [Point32(cluster_x_pos, cluster_y_pos, cluster_z_pos),
                                  Point32(predicted_x_pos, predicted_y_pos, cluster_z_pos)]
        
        return velVectorMarker


    def vel_vector_vis_initialization(self):
        """Initialize the parameter reads for the marker array arrow to visualize velocity vectors"""
        self.vel_vec_r = rospy.get_param('cluster_tracking_node/vel_vec_r')
        self.vel_vec_g = rospy.get_param('cluster_tracking_node/vel_vec_g')
        self.vel_vec_b = rospy.get_param('cluster_tracking_node/vel_vec_b')
        self.vel_vec_a = rospy.get_param('cluster_tracking_node/vel_vec_a')

        self.vel_vec_scale_x = rospy.get_param('cluster_tracking_node/shaft_diameter')
        self.vel_vec_scale_y = rospy.get_param('cluster_tracking_node/head_diameter')
        self.vel_vec_scale_z = rospy.get_param('cluster_tracking_node/head_length')

        self.vel_vec_nano_seconds = rospy.get_param('/cluster_tracking_node/arrow_lifetime')

    def cluster_tracker(self):
        """Track the position and velocity of the clusters over time"""
        rospy.Subscriber("/perception/cluster_locations", Cluster_bound_list, self.cluster_callback, queue_size = 1)
        rospy.Subscriber("/odometry/filtered", Odometry, self.pose_callback, queue_size = 1)
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
