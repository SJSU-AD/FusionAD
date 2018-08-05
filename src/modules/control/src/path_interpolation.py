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

import math
import rospy
from std_msgs.msg import Header
from geometry_msgs.msg import Point, Pose, PoseStamped
from nav_msgs.msg import Path

import gps_parser
import geodesy

def get_point_density(x1, y1, z1, x2, y2, z2, centimetersPerPoint):
    pointDensity = geodesy.euclidian_distance_3d(x1, y1, z1, x2, y2, z2) / (centimetersPerPoint / 100.0)

    return pointDensity

# Instead of different functions for positive and negative
def interpolate(i, relativeX, relativeY, relativeZ, finePointsX, finePointsY, numberOfCoarsePoints):
    """Interpolate between two points, given index of one of the points."""
    # pointDensity = 10
    # Vanilla case: for all points except final point
    if i < numberOfCoarsePoints-1:
        # Number of points between each interpolated point
        pointDensity = get_point_density(relativeX[i], relativeX[i], relativeZ[i], relativeX[i+1], relativeY[i+1], relativeZ[i+1], 25)

        x0 = relativeX[i]     # declare the first x-position for interpolation
        x1 = relativeX[i+1]   # declare the second x-position for interpolation
        y0 = relativeY[i]     # declare the first y-position for interpolation
        y1 = relativeY[i+1]   # declare the second y-position for interpolation

        for n in range(int(pointDensity)):
            finePointsX.append( x0 + (x1-x0)*(n/pointDensity) )
            finePointsY.append( ((y1-y0) / (x1-x0)) )# * (finePointsX[i]) + y1*((x1-x0) / (y1-y0)) )

    # Corner case: for final point    
    if i == numberOfCoarsePoints-1:
        pointDensity = get_point_density(relativeX[i-1], relativeX[i-1], relativeZ[i-1], relativeX[i], relativeY[i], relativeZ[i], 25)

        x0 = relativeX[i-1]
        x1 = relativeX[i]
        y0 = relativeY[i-1]
        y1 = relativeY[i]
    
        for n in range(int(pointDensity)):
            finePointsX.append( x0 + (x1-x0)*(n/pointDensity) )
            finePointsY.append( ((y1-y0) / (x1-x0)) * (finePointsX[i]) + y1*((x1-x0) / (y1-y0)) )    

def interpolation_publish(relativeX, relativeY, relativeZ, chosenHeight):
    """Interpolates between all ECEF coordinates and publishes them as a Path.

    Subscribes
    ----------
    None
    
    Publishes
    ---------
    std_msgs/Float64
        /interpolation_x -- List of interpolated points in the x direction in ECEF coordinates
    
    std_msgs/Float64
        /interpolation_x -- List of interpolated points in the x direction in ECEF coordinates
    """

    path_publisher = rospy.Publisher('path_node', Path, queue_size=1000)
    rospy.init_node('interpolation_node', anonymous = True)
    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        path = Path()

        # Placeholder for all points after interpolation between two given points
        finePointsY = []
        finePointsX = []

        # Contains lists of fine points, including coarse points
        x_interpolated_positions = []
        y_interpolated_positions = []

        numberOfCoarsePoints = len(relativeX)

        print("numberOfCoarsePoints is:", len(relativeX))
        for i in range(numberOfCoarsePoints):
            interpolate(i, relativeX, relativeY, relativeZ, finePointsX, finePointsY, numberOfCoarsePoints)
            
            print("number of total points:", len(finePointsY))
            
            y_interpolated_positions.append(finePointsY)
            x_interpolated_positions.append(finePointsX)
            
        ################################
        ##### Publish Path message #####
        ################################
        for _ in range(len(y_interpolated_positions)+1):
            seq = 0
            for i in range(len(finePointsY)):

                # # Attempting to add points directly in one line without creating point object first
                # path.poses.append(path.poses[i].pose.position.x = 0.0) # finePointsX[i]
                # path.poses[i].pose.position.y = 0.0 # finePointsY[i]
                # path.poses[i].pose.position.z = 0.0

                currentPoseStampMsg = PoseStamped()

                h = Header()
                h.stamp = rospy.Time.now()
                currentPoseStampMsg.header.seq = seq
                currentPoseStampMsg.header.stamp = h.stamp
                seq += 1

                currentPoseStampMsg.pose.position.x =  finePointsX[i] 
                currentPoseStampMsg.pose.position.y =  finePointsY[i] 
                currentPoseStampMsg.pose.position.z = chosenHeight

                path.poses.append(currentPoseStampMsg)
        
        path_publisher.publish(path)
        rate.sleep()

def main():

    # From https://www.maps.ie/coordinates.html at SJSU
    chosenHeight = 60.0

    inputLatitudes, inputLongitudes, inputHeights = gps_parser.read_file_coarse_points("gps_coarse_points/testCoordinates1.txt", chosenHeight)
    print("inputLatitudes: {}\ninputLongitudes: {}\ninputHeights: {}".format(inputLatitudes, inputLongitudes, inputHeights))
    
    xPosition, yPosition, zPosition = geodesy.geodetic_data_to_ECEF_data(inputLatitudes, inputLongitudes, inputHeights)
    print("xPosition =", xPosition, "\nyPosition =", yPosition, "\nzPosition =", zPosition)

    relativeX, relativeY, relativeZ = geodesy.global_to_relative(xPosition, yPosition, zPosition)
    print("relativeX =", relativeX, "\nrelativeY =", relativeY, "\nrelativeZ =", relativeZ)
    
    print("\n")

    try:
        interpolation_publish(relativeX, relativeY, relativeZ, chosenHeight)
    except rospy.ROSInterruptException:
        pass

if __name__ == '__main__':
    main()

