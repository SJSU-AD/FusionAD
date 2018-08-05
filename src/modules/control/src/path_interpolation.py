#!/usr/bin/env python

"""Publishes relative path ECEF poordinates from given geodetic coordinates

Subscribes to:
    None

Publishes to:
    /planning/trajectory

Sends nav_msg/Path to "core_control" node (control_node.cpp)

NOTE: Requires hardcoded geodetic coordinates in decimal.

Convenience degrees-minute-second to decimal converter can be found here: https://repl.it/@DRmoto/DMStoDec
"""

from __future__ import print_function
from __future__ import division

import math
import rospy
from std_msgs.msg import Header
from geometry_msgs.msg import Point, Pose, PoseStamped
from nav_msgs.msg import Path

######################################
##### Input geodetic coordinates #####
######################################

# Data from sfpublicworks
# https://sfpublicworks.org/ccsf-geodetic-network
# "HPN Densification (HPND) Published Coordinates (doc)  UPDATED 07.06.18"
latitudesSF   = [37.73342686666667, 37.74874958888889, 37.78162528055555, 37.78120765833334, 37.782006519444444]
longitudesSF  = [122.49695338611112, 122.39902696666667, 122.424035375, 122.42713217777778, 122.427296125]
heightsFtSF   = [-29.73, 90.68, 0.1, -1.5, 16.6]
heigthsMSF    = [height * 0.3048 for height in heightsFtSF]

# Data from Antenna Reference Point(ARP): SLAC_BARD_CN2002 CORS ARP
# ftp://www.ngs.noaa.gov/cors/coord/coord_08/slac_08.coord.txt
latitudesCN2002  = [37.41651668611111, 37.416513997222225, 37.41651668888889, 37.416514]
longitudesCN2002 = [-122.20426206944444, -122.20424886666666, -122.20426205833333, -122.20424885555556]
heightsCN2002    = [63.685, 64.218, 63.774, 64.308]

# Custom hardcoded test data
latitudesCustom  = [0.0, 1.0, 2.0, 3.0, 4.0]
longitudesCustom = [0.0, 1.0, 2.0, 3.0, 4.0]
heightsCustom    = [4.0, 4.0, 4.0, 4.0, 4.0]

######################################
######################################
######################################

# Instead of different functions for positive and negative
def interpolate(i, relativeX, relativeY, relativeZ, finePointsX, finePointsY, numberOfCoarsePoints):
    """Interpolate between two points, given index of one of the points."""

    # Number of points between each interpolated point
    pointDensity = 10

    # Vanilla case: for all points except final point
    if i < numberOfCoarsePoints-1:
        x0 = relativeX[i]     # declare the first x-position for interpolation
        x1 = relativeX[i+1]   # declare the second x-position for interpolation
        y0 = relativeY[i]     # declare the first y-position for interpolation
        y1 = relativeY[i+1]   # declare the second y-position for interpolation  

        for n in range(pointDensity):
            finePointsX.append( x0 + (x1-x0)*(n/pointDensity) )
            finePointsY.append( ((y1-y0) / (x1-x0)) )# * (finePointsX[i]) + y1*((x1-x0) / (y1-y0)) )

    # Corner case: for final point    
    if i == numberOfCoarsePoints-1:
        x0 = relativeX[i-1]     
        x1 = relativeX[i]
        y0 = relativeY[i-1]
        y1 = relativeY[i]
    
        for n in range(pointDensity):
            finePointsX.append( x0 + (x1-x0)*(n/pointDensity) )
            finePointsY.append( ((y1-y0) / (x1-x0)) * (finePointsX[i]) + y1*((x1-x0) / (y1-y0)) )    

def interpolation_publish(relativeX, relativeY, relativeZ):
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
            interpolate(i, relativeX, relativeY, relativeZ, finePointsX, finePointsY,numberOfCoarsePoints)

            y_interpolated_positions.append(finePointsY)
            x_interpolated_positions.append(finePointsX)
            
        ################################
        ##### Publish Path message #####
        ################################
        print("number of total points:", len(finePointsY))
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
                currentPoseStampMsg.pose.position.z = 0.0

                path.poses.append(currentPoseStampMsg)
        
        path_publisher.publish(path)
        rate.sleep()

def read_file_coarse_points(fileName):
    """Reads GPS coordinates from text file and returns latitude and longitude values in decimal
    
    Data taken from: http://www.gpsvisualizer.com/draw/
    """
    inputLatitudes = []
    inputLongitudes = []
    inputHeights = []

    # TODO: Check for file format and catch appropriate exception
    with open(fileName, "r") as file:
        for line in file:
            if line[0] == "W":
                currentLine = line.split()
                inputLatitudes.append(float(currentLine[1]))
                inputLongitudes.append(float(currentLine[2]))
                inputHeights.append(60.0) # Hardcoded estimated height of SJSU
    
    return inputLatitudes, inputLongitudes, inputHeights

def geodetic_to_ECEF_coordinates(lat, lng, h):
    """Converts a list of geodetic coordinates to a list of ECEF coordinates.
    
    Reference Material: 
    https://en.wikipedia.org/wiki/Geographic_coordinate_conversion
    http://clynchg3c.com/Technote/geodesy/coordcvt.pdf

    NOTE: 'h' is also known as 'ellipsoidal height' or 'altitude'. DO NOT use orthogonal height. 

    Parameters
    ----------
    param1: array_like
        Latitude coordinates in order in decimal (float).
    param2: array_like
        Longitude coordinates in order in decimal (float).
    param3: array_like
        Height coordinates in order in decimal (float).

    Returns
    -------
    x: array_like
        X position of coordinates in ECEF coordinates
    y: array_like
        Y position of coordinates in ECEF coordinates
    z: array_like
        Z position of coordinates in ECEF coordinates
    """
    a = 6378137         # equatorial radius of earth
    b = 6356753         # polar radius of earth
    e = 0.08181788116   # eccentricity of the earth

    N = a / math.sqrt(1-(e**2) * (math.sin(lat*math.pi/180)**2))        # prime vertical radius of curvature
    x = (N+h) * math.cos(lat*math.pi/180) * math.cos(lng*math.pi/180) 
    y = (N+h) * math.cos(lat*math.pi/180) * math.sin(lng*math.pi/180)
    z = ((b**2) / (a**2) * N+h) * math.sin(lat * math.pi/180)

    return x, y, z

def geodetic_data_to_ECEF_data(latitudesData, longitudesData, heightsData):
    """Convert lists of geodetic latitude/longitude/height data to list of ECEF X/Y/Z data"""

    xPosition = []
    yPosition = []
    zPosition = []

    for i in range(min(len(latitudesData), len(longitudesData), len(heightsData))):
        x, y, z = geodetic_to_ECEF_coordinates(latitudesData[i], longitudesData[i], heightsData[i])
        xPosition.append(x)
        yPosition.append(y)
        zPosition.append(z)
    
    return xPosition, yPosition, zPosition

def global_to_relative(xPosition, yPosition, zPosition):
    """Convert global coordinates to relative coordinates at a given index"""
    globalXInitial = xPosition[0]
    globalYInitial = yPosition[0]
    globalZInitial = zPosition[0]
    
    relativeX = []
    relativeY = []
    relativeZ = []

    for i in range(len(zPosition)):
        relativeX.append(xPosition[i] - globalXInitial)
        relativeY.append(yPosition[i] - globalYInitial)
        relativeZ.append(zPosition[i] - globalZInitial)
    
    return relativeX, relativeY, relativeZ

def main():

    # Set chosen dataset
    # latitudes  = latitudesCN2002
    # longitudes = longitudesCN2002
    # heights    = heightsCN2002

    inputLatitudes, inputLongitudes, inputHeights = read_file_coarse_points("testCoordinates1.txt")
    print("inputLatitudes: {}\ninputLongitudes: {}\ninputHeights: {}".format(inputLatitudes, inputLongitudes, inputHeights))
    xPosition, yPosition, zPosition = geodetic_data_to_ECEF_data(inputLatitudes, inputLongitudes, inputHeights)
    relativeX, relativeY, relativeZ = global_to_relative(xPosition, yPosition, zPosition)

    print("relativeX =", relativeX, "\nrelativeY =", relativeY, "\nrelativeZ =", relativeZ)
    print("\n")


    try:
        interpolation_publish(relativeX, relativeY, relativeZ)
    except rospy.ROSInterruptException:
        pass

if __name__ == '__main__':
    main()

