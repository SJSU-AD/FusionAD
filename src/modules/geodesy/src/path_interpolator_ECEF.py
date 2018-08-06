#!/usr/bin/env python
"""Publishes relative path ECEF poordinates from given geodetic coordinates

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

import gps_parser
from geodesy_conversion_ECEF import GeodesyConverterECEF
from geodesy_conversion_UTM  import GeodesyConverterUTM

class PathInterpolatorECEF(GeodesyConverterECEF):
    def __init__(self, latitudesData, longitudesData, heightsData, centimetersPerPoint=None):
        super(PathInterpolatorECEF, self).__init__(latitudesData, longitudesData, heightsData)
        self.heightsData = heightsData
        self.centimetersPerPoint = 25 if centimetersPerPoint==None else centimetersPerPoint

    def set_dist_between_points(self, centimetersPerPoint):
        """Set distance between points after interpolation"""
        self.centimetersPerPoint = centimetersPerPoint
    
    def get_point_density_ECEF(self, x1, y1, z1, x2, y2, z2, centimetersPerPoint):
        pointDensity = super(PathInterpolatorECEF, self).euclidian_distance_3d(x1, y1, z1, x2, y2, z2) / (centimetersPerPoint / 100.0)

        return int(pointDensity)

    # Instead of different functions for positive and negative
    def interpolate_ECEF(self, i, relativeXData, relativeYData, relativeZData, numberOfCoarsePoints):
        """Interpolate between two ECEF points, given index of one of the points."""

        finePointsX = []
        finePointsY = []
        finePointsZ = []

        # Vanilla case: for all points except final point
        if i < numberOfCoarsePoints-1:
            # Number of points between each interpolated point
            pointDensity = self.get_point_density_ECEF(relativeXData[i], relativeXData[i], relativeZData[i], 
                                                       relativeXData[i+1], relativeYData[i+1], relativeZData[i+1], self.centimetersPerPoint)

            # Declare the first and second positions for interpolation
            x0 = relativeXData[i]     
            x1 = relativeXData[i+1]
            y0 = relativeYData[i]     
            y1 = relativeYData[i+1]   
            z0 = relativeZData[i]     
            z1 = relativeZData[i+1]

            for n in range(pointDensity):
                finePointsX.append( x0 + (x1-x0)*(n/pointDensity) )
                finePointsY.append( y0 + (y1-y0)*(n/pointDensity) ) # was previously: finePointsY.append( ((y1-y0) / (x1-x0)) * (finePointsX[n]) + y0*((x1-x0) / (y1-y0)) )
                finePointsZ.append( z0 + (z1-z0)*(n/pointDensity) )

        # Corner case: for final point    
        if i == numberOfCoarsePoints-1:
            pointDensity = self.get_point_density_ECEF(relativeXData[i-1], relativeXData[i-1], relativeZData[i-1], 
                                                       relativeXData[i], relativeYData[i], relativeZData[i], 25)

            x0 = relativeXData[i-1]
            x1 = relativeXData[i]
            y0 = relativeYData[i-1]
            y1 = relativeYData[i]
            z0 = relativeZData[i-1]     
            z1 = relativeZData[i]

            for n in range(pointDensity):
                finePointsX.append( x0 + (x1-x0)*(n/pointDensity) )
                finePointsY.append( y0 + (y1-y0)*(n/pointDensity) )
                finePointsZ.append( z0 + (z1-z0)*(n/pointDensity) )

        # print("pointDensity used on iteration {} was {}".format(i, pointDensity))
        return finePointsX, finePointsY, finePointsZ

    def interpolation_publish_ECEF(self):
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

        xPositions, yPositions, zPositions = super(PathInterpolatorECEF, self).geodetic_data_to_ECEF_data()
        # print("\nxPosition =", xPosition, "\nyPosition =", yPosition, "\nzPosition =", zPosition)
        relativeXData, relativeYData, relativeZData = super(PathInterpolatorECEF, self).global_to_relative_ECEF(xPositions, yPositions, zPositions)
        # print("\nrelativeX =", relativeX, "\nrelativeY =", relativeY, "\nrelativeZ =", relativeZ, "\n")
        
        # Contains lists of fine points, including coarse points
        xInterpolatedPositions = []
        yInterpolatedPositions = []
        zInterpolatedPositions = []

        numberOfCoarsePoints = len(relativeXData)

        for i in range(numberOfCoarsePoints):
            finePointsX, finePointsY, finePointsZ = self.interpolate_ECEF(i, relativeXData, relativeYData, relativeZData, numberOfCoarsePoints)

            xInterpolatedPositions.extend(finePointsX)
            yInterpolatedPositions.extend(finePointsY)
            zInterpolatedPositions.extend(finePointsZ)
        
        while not rospy.is_shutdown():
            path = Path()
        
            for i in range(len(yInterpolatedPositions)):
                # # Attempting to add points directly in one line without creating point object first
                # path.poses.append(path.poses[i].pose.position.x = 0.0) # finePointsX[i]
                # path.poses[i].pose.position.y = 0.0 # finePointsY[i]
                # path.poses[i].pose.position.z = 0.0

                currentPoseStampMsg = PoseStamped()
                h = Header()

                h.stamp = rospy.Time.now()
                h.seq = i
                currentPoseStampMsg.header.seq = h.seq
                currentPoseStampMsg.header.stamp = h.stamp

                currentPoseStampMsg.pose.position.x = xInterpolatedPositions[i] 
                currentPoseStampMsg.pose.position.y = yInterpolatedPositions[i] 
                currentPoseStampMsg.pose.position.z = zInterpolatedPositions[i]

                path.poses.append(currentPoseStampMsg)
            
            path_publisher.publish(path)
            rospy.loginfo("Published Path with %d steps", i+1)
            rate.sleep()
