#!/usr/bin/env python

"""Publishes relative path UTM poordinates from given geodetic coordinates

Subscribes to:
    None

Publishes to:
    /planning/trajectory

Sends nav_msg/Path to "core_control" node (control_node.cpp)

Convenience degrees-minute-second to decimal converter can be found here: https://repl.it/@DRmoto/DMStoDec
"""

from __future__ import print_function
from __future__ import division

import rospy
from std_msgs.msg import Header
from geometry_msgs.msg import Point, Pose, PoseStamped
from nav_msgs.msg import Path

from geodesy_conversion_UTM import GeodesyConverterUTM

class PathInterpolatorUTM(GeodesyConverterUTM):
    def __init__(self, latitudesData, longitudesData, centimetersPerPoint=25):
        super(PathInterpolatorUTM, self).__init__(latitudesData, longitudesData, centimetersPerPoint)
        self.centimetersPerPoint = centimetersPerPoint

    def set_dist_between_points(self, centimetersPerPoint):
        """Set distance between points after interpolation"""
        self.centimetersPerPoint = centimetersPerPoint
    
    def get_point_density_UTM(self, relativeEasting1, relativeNorthing1, relativeEasting2, relativeNorthing2, centimetersPerPoint):
        pointDensity = super(PathInterpolatorUTM, self).euclidian_distance_2d(relativeEasting1, relativeEasting1, relativeEasting2, relativeNorthing2) / (centimetersPerPoint / 100.0)

        return int(pointDensity)

    def interpolate_UTM(self, i, relativeEastings, relativeNorthings, numberOfCoarsePoints):
        """Interpolate between two UTM points, given index of one of the points."""
        
        finePointsEasting = []
        finePointsNorthing = []

        # Vanilla case: for all points except final point
        if i < numberOfCoarsePoints-1:
            # Number of points between each interpolated point
            pointDensity = self.get_point_density_UTM(relativeEastings[i], relativeEastings[i], relativeEastings[i+1], relativeNorthings[i+1], 25)

            # Declare the first and second positions for interpolation
            x0 = relativeEastings[i]
            x1 = relativeEastings[i+1]
            y0 = relativeNorthings[i]     
            y1 = relativeNorthings[i+1]   

            for n in range(pointDensity):
                finePointsEasting.append( x0 + (x1-x0)*(n/pointDensity) )
                finePointsNorthing.append( y0 + (y1-y0)*(n/pointDensity) )

        # Corner case: for final point
        if i == numberOfCoarsePoints-1:
            pointDensity = self.get_point_density_UTM(relativeEastings[i-1], relativeEastings[i-1], relativeEastings[i], relativeNorthings[i], 25)

            x0 = relativeEastings[i-1]
            x1 = relativeEastings[i]
            y0 = relativeNorthings[i-1]
            y1 = relativeNorthings[i]

            for n in range(pointDensity):
                finePointsEasting.append( x0 + (x1-x0)*(n/pointDensity) )
                finePointsNorthing.append( y0 + (y1-y0)*(n/pointDensity) )

        return finePointsEasting, finePointsNorthing

    def interpolation_publish_UTM(self):
        """Interpolates between all ECEF coordinates and publishes them as a Path.

        Subscribes
        ----------
        None
        
        Publishes
        ---------
        Topic: /planning/trajectory
            Msg: Path
        """

        path_publisher = rospy.Publisher('/planning/trajectory', Path, queue_size=1000)
        rate = rospy.Rate(1)
        
        eastings, northings, zoneNumbers, zoneLetters = super(PathInterpolatorUTM, self).geodetic_data_to_UTM_data()
        relativeEastings, relativeNorthings = super(PathInterpolatorUTM, self).global_to_relative_UTM(eastings, northings)

        # Contains lists of fine points, including coarse points
        eastingInterpolatedPositions  = []
        northingInterpolatedPositions = []

        numberOfCoarsePoints = len(relativeEastings)

        for i in range(numberOfCoarsePoints):
            finePointsEasting, finePointsNorthing = self.interpolate_UTM(i, relativeEastings, relativeNorthings, numberOfCoarsePoints)

            eastingInterpolatedPositions.extend(finePointsEasting)
            northingInterpolatedPositions.extend(finePointsNorthing)

        while not rospy.is_shutdown():
            path = Path()

            for i in range(len(eastingInterpolatedPositions)):
                # # Attempting to add points directly in one line without creating point object first
                # path.poses.append(path.poses[i].pose.position.x = 0.0) # finePointsX[i]
                # path.poses[i].pose.position.y = 0.0 # finePointsY[i]

                currentPoseStampMsg = PoseStamped()
                h = Header()

                h.stamp = rospy.Time.now()
                h.seq = i
                currentPoseStampMsg.header.seq = h.seq
                currentPoseStampMsg.header.stamp = h.stamp

                currentPoseStampMsg.pose.position.x = eastingInterpolatedPositions[i] 
                currentPoseStampMsg.pose.position.y = northingInterpolatedPositions[i] 

                path.poses.append(currentPoseStampMsg)
            
            path_publisher.publish(path)
            rospy.loginfo("Published Path with %d steps", i+1)
            rate.sleep()
