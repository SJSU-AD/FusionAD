#!/usr/bin/env python

"""Publishes ECEF Coordinates from given geodetic coordinates

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
from std_msgs.msg import Float64, UInt32, Header
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

# Set variables for storing input coarse GNSS geodetic coordinates
latitudes = []
longitudes = []
heights = []

# how many points between each interpolated point
point_density = 10 

# Placeholders for output global ECEF conversion
X_Position = []
Y_Position = []
Z_Position = []

# Placeholders for output relative ECEF conversion
relativeX = []
relativeY = []
relativeZ = []

numberOfCoarsePoints = 0

# Contains lists of points between input coarse points, including coarse points
# Initially converted from MATLAB rough equivalent: [None]*numberOfCoarsePoints*point_density
x_interpolated_positions = []
y_interpolated_positions = []

# Converted from MATLAB rough equivalent: #[None]*point_density
y_n = []
x_n = []

# Instead of different functions for positive and negative
def interpolate(i):
    """Interpolate between two points, given index of one of the points."""
    print("i is currently:", i)

    # Vanilla case: for all points except final point
    if i < numberOfCoarsePoints-1:
        x_0 = relativeX[i]     # declare the first x-position for interpolation
        x_1 = relativeX[i+1]   # declare the second x-position for interpolation
        y_0 = relativeY[i]     # declare the first y-position for interpolation
        y_1 = relativeY[i+1]   # declare the second y-position for interpolation        

        for n in range(point_density):
            x_n.append( x_0 + (x_1-x_0)*(n/point_density) )
            y_n.append( ((y_1-y_0) / (x_1-x_0)) * (x_n[i]) + y_1*((x_1-x_0) / (y_1-y_0)) )

    # Corner case: for final point    
    if i == numberOfCoarsePoints-1:
        x_0 = relativeX[i-1]     
        x_1 = relativeX[i]
        y_0 = relativeY[i-1]
        y_1 = relativeY[i]
    
        for n in range(point_density):
            x_n.append( x_0 + (x_1-x_0)*(n/point_density) )
            y_n.append( ((y_1-y_0) / (x_1-x_0)) * (x_n[i]) + y_1*((x_1-x_0) / (y_1-y_0)) )    

def interpolation_publish():
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
    
    i = 0 # initialize global index for initial positions

    while not rospy.is_shutdown():
        path = Path()

        print("numberOfCoarsePoints is:", numberOfCoarsePoints)
        while i < numberOfCoarsePoints:
            interpolate(i)

            y_interpolated_positions.append(y_n)
            x_interpolated_positions.append(x_n)
            
            i += 1
            
        ################################
        ##### Publish Path message #####
        ################################
        for _ in range(len(y_interpolated_positions)+1):

            print("length of y_n:", len(y_n))
            seq = 0
            for i in range(len(y_n)):

                # # Attempting to add points directly in one line without creating point object first
                # path.poses.append(path.poses[i].pose.position.x = 0.0) # x_n[i]
                # path.poses[i].pose.position.y = 0.0 # y_n[i]
                # path.poses[i].pose.position.z = 0.0

                currentPoseStampMsg = PoseStamped()

                h = Header()
                h.stamp = rospy.Time.now()
                currentPoseStampMsg.header.seq = seq
                currentPoseStampMsg.header.stamp = h.stamp
                seq += 1

                currentPoseStampMsg.pose.position.x =  x_n[i] 
                currentPoseStampMsg.pose.position.y =  y_n[i] 
                currentPoseStampMsg.pose.position.z = 0.0

                path.poses.append(currentPoseStampMsg)
        
        path_publisher.publish(path)
        rate.sleep()


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
    """Convert list of geodetic data to list of ECEF data"""
    for i in range(min(len(latitudesData), len(longitudesData), len(heightsData))):
        x, y, z = geodetic_to_ECEF_coordinates(latitudesData[i], longitudesData[i], heightsData[i])
        X_Position.append(x)
        Y_Position.append(y)
        Z_Position.append(z)

def global_to_relative():
    """Convert global coordinates to relative coordinates at a given index"""
    globalXInitial = X_Position[0]
    globalYInitial = Y_Position[0]
    globalZInitial = Z_Position[0]
    
    
    for i in range(len(X_Position)):
        relativeX.append(X_Position[i] - globalXInitial)
        relativeY.append(Y_Position[i] - globalYInitial)
        relativeZ.append(Z_Position[i] - globalZInitial)

def read_file_coarse_points(fileName):
    """Reads GPS coordinates from text file and saves to latitude and longitude variables"""
    latitudes = longitudes = heights = []

    # TODO: Check for file format and catch appropriate exception
    with open(fileName, "r") as file:

        for line in file:
            if file.index(line) != 1:
                splitLine = line.split()
                latitudes.append(splitLine[1])
                longitudes.append(splitLine[2])
                heights.append(60.0) # Hardcoded

def main():

    # Set chosen dataset
    latitudes  = latitudesCN2002
    longitudes = longitudesCN2002
    heights    = heightsCN2002

    # read_file_coarse_points("testCoordinates1.txt")
    geodetic_data_to_ECEF_data(latitudes, longitudes, heights)
    global_to_relative()

    print("relativeX =", relativeX, "\nrelativeY =", relativeY, "\nrelativeZ =", relativeZ)
    print("\n")

    # Find the length of the relativeX list
    global numberOfCoarsePoints 
    numberOfCoarsePoints= len(relativeX) 

    try:
        interpolation_publish()
    except rospy.ROSInterruptException:
        pass

if __name__ == '__main__':
    main()

