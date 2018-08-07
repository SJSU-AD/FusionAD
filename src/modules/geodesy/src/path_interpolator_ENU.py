#!/usr/bin/env python

"""Publishes relative path ENU poordinates from given geodetic coordinates

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
from geodesy_conversion_ENU import GeodesyConverterENU

class PathInterpolatorENU(GeodesyConverterENU):
    def __init__(self, latitudesData, longitudesData, heightsData, centimetersPerPoint=None):
        super(PathInterpolatorENU, self).__init__(latitudesData, longitudesData, heightsData)
        self.heightsData = heightsData
        self.centimetersPerPoint = 25 if centimetersPerPoint==None else centimetersPerPoint

    def set_dist_between_points(self, centimetersPerPoint):
        """Set distance between points after interpolation"""
        self.centimetersPerPoint = centimetersPerPoint
    
    def get_point_density_ENU(self, e1, n1, u1, e2, n2, u2, centimetersPerPoint):
        pointDensity = super(PathInterpolatorENU, self).euclidian_distance_3d(e1, n1, u1, e2, n2, u2) / (centimetersPerPoint / 100.0)

        return int(pointDensity)

    # Instead of different functions for positive and negative
    def interpolate_ENU(self, i, eData, nData, uData, numberOfCoarsePoints):
        """Interpolate between two ENU points, given index of one of the points."""

        finePointsE = []
        finePointsN = []
        finePointsU = []

        pointDensity = 10
        # Vanilla case: for all points except final point
        if i < numberOfCoarsePoints-1:
            # Number of points between each interpolated point
            # pointDensity = self.get_point_density_ENU(eData[i], eData[i], uData[i], 
                                                    #    eData[i+1], nData[i+1], uData[i+1], self.centimetersPerPoint)

            # Declare the first and second positions for interpolation
            e0 = eData[i]     
            e1 = eData[i+1]
            n0 = nData[i]     
            n1 = nData[i+1]   
            u0 = uData[i]     
            u1 = uData[i+1]

            for n in range(pointDensity):
                finePointsE.append( e0 + (e1-e0)*(n/pointDensity) )
                finePointsN.append( n0 + (n1-n0)*(n/pointDensity) )
                finePointsU.append( u0 + (u1-u0)*(n/pointDensity) )

        # Corner case: for final point    
        if i == numberOfCoarsePoints-1:
            # pointDensity = self.get_point_density_ENU(eData[i-1], eData[i-1], uData[i-1], 
            #                                            eData[i], nData[i], uData[i], self.centimetersPerPoint)

            x0 = eData[i-1]
            x1 = eData[i]
            y0 = nData[i-1]
            y1 = nData[i]
            z0 = uData[i-1]     
            z1 = uData[i]

            for n in range(pointDensity):
                finePointsE.append( x0 + (x1-x0)*(n/pointDensity) )
                finePointsN.append( y0 + (y1-y0)*(n/pointDensity) )
                finePointsU.append( z0 + (z1-z0)*(n/pointDensity) )

        return finePointsE, finePointsN, finePointsU

    def interpolation_publish_ENU(self):
        """Interpolates between all ENU coordinates and publishes them as a Path.

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

        eData, nData, uData = super(PathInterpolatorENU, self).ECEF_data_to_ENU_data()
        
        # Contains lists of fine points, including coarse points
        eInterpolatedPositions = []
        nInterpolatedPositions = []
        uInterpolatedPositions = []

        numberOfCoarsePoints = len(eData)

        for i in range(numberOfCoarsePoints):
            finePointsE, finePointsN, finePointsU = self.interpolate_ENU(i, eData, nData, uData, numberOfCoarsePoints)

            eInterpolatedPositions.extend(finePointsE)
            nInterpolatedPositions.extend(finePointsN)
            uInterpolatedPositions.extend(finePointsU)
        
        while not rospy.is_shutdown():
            path = Path()
        
            for i in range(len(nInterpolatedPositions)):
                # # Attempting to add points directly in one line without creating point object first
                # path.poses.append(path.poses[i].pose.position.x = 0.0) # finePointsE[i]
                # path.poses[i].pose.position.y = 0.0 # finePointsN[i]
                # path.poses[i].pose.position.z = 0.0

                currentPoseStampMsg = PoseStamped()
                h = Header()

                h.stamp = rospy.Time.now()
                h.seq = i
                currentPoseStampMsg.header.seq = h.seq
                currentPoseStampMsg.header.stamp = h.stamp

                currentPoseStampMsg.pose.position.x = eInterpolatedPositions[i] 
                currentPoseStampMsg.pose.position.y = nInterpolatedPositions[i] 
                currentPoseStampMsg.pose.position.z = uInterpolatedPositions[i]

                path.poses.append(currentPoseStampMsg)
            
            path_publisher.publish(path)
            rospy.loginfo("Published Path with %d steps", i+1)
            rate.sleep()
