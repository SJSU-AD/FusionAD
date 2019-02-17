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
    def __init__(self, latitudesData, longitudesData, heightsData, centimetersPerPoint=25, radarPoint=None):
        super(PathInterpolatorENU, self).__init__(latitudesData, longitudesData, heightsData, radarPoint=radarPoint)
        self.heightsData = heightsData
        self.centimetersPerPoint = centimetersPerPoint

    def set_dist_between_points(self, centimetersPerPoint):
        """Set distance between points after interpolation"""
        self.centimetersPerPoint = centimetersPerPoint
    
    def get_point_density_ENU(self, e1, n1, u1, e2, n2, u2):
        
        pointDensity = super(PathInterpolatorENU, self).euclidian_distance_2d(e1, n1, e2, n2) / (self.centimetersPerPoint / 100.0)
        
        return pointDensity

    # Instead of different functions for positive and negative
    def interpolate_ENU(self, i, eData, nData, uData, numberOfCoarsePoints):
        """Interpolate between two ENU points, given index of one of the points."""

        finePointsE = []
        finePointsN = []
        finePointsU = []

        # OPTION 1: Fixed point density option
        # pointDensity = 10

        # Vanilla case: for all points except final point
        if i <= numberOfCoarsePoints - 1:
            
            print("radar point:", self.radarLat, self.radarLon, self.radarHeight)
            print("eData[i]: {}, nData[i]: {}, uData[i]: {}, eData[i+1]: {}, nData[i+1]: {}, uData[i+1]: {}".format(eData[i], nData[i], uData[i], eData[i+1], nData[i+1], uData[i+1]))
            print("ECEF start:", self.ENU_to_ECEF_point(eData[i], nData[i], uData[i]))
            print("ECEF end:", self.ENU_to_ECEF_point(eData[i+1], nData[i+1], uData[i+1]))
            # OPTION 2: Fixed distance option (variable point density)
            # Number of points between each interpolated point
            pointDensity = self.get_point_density_ENU(eData[i], nData[i], uData[i], 
                                                       eData[i+1], nData[i+1], uData[i+1])
            ##### pointDensity is type float right now #####
            print("========pointDensity:", pointDensity)
            
            # Declare the first and second positions for interpolation
            e0 = eData[i]     
            e1 = eData[i+1]
            n0 = nData[i]     
            n1 = nData[i+1]   
            u0 = uData[i]     
            u1 = uData[i+1]

            for n in range(int(pointDensity)):
                finePointsE.append( e0 + (e1-e0)*(n/pointDensity) )
                finePointsN.append( n0 + (n1-n0)*(n/pointDensity) )
                finePointsU.append( u0 + (u1-u0)*(n/pointDensity) )

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

        eData, nData, uData = super(PathInterpolatorENU, self).geodetic_data_to_ENU_data()
        
        # Contains lists of fine points, including coarse points
        eInterpolatedPositions = []
        nInterpolatedPositions = []
        uInterpolatedPositions = []

        if len(eData) != len(nData) or len(eData) != len(uData) or len(nData) != len(uData):
            raise ValueError("Number of E, N, and U coordinates are not equal")

        numberOfCoarsePoints = len(eData)
    
        totalPoints = 0

        for i in range(numberOfCoarsePoints - 1):
            finePointsE, finePointsN, finePointsU = self.interpolate_ENU(i, eData, nData, uData, numberOfCoarsePoints)

            eInterpolatedPositions.extend(finePointsE)
            nInterpolatedPositions.extend(finePointsN)
            uInterpolatedPositions.extend(finePointsU)

            totalPoints += len(finePointsE)

        eInterpolatedPositions.append(eData[-1])
        nInterpolatedPositions.append(nData[-1])
        uInterpolatedPositions.append(uData[-1])

        while not rospy.is_shutdown():
            path = Path()
            path.header.frame_id = "map"

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
