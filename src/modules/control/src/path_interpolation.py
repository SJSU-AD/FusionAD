#!/usr/bin/env python

"""Publishes ECEF Coordinates from given geodetic coordinates

Subscribes to:
    None

Publishes to:
    OLD -- /interpolation_x
    OLD -- /interpolation_y
    /planning/trajectory

Sends nav_msg/Path to "core_control" node (control_node.cpp)

NOTE: Requires hardcoded geodetic coordinates in decimal.

Convenience degrees-minute-second to decimal converter can be found here: https://repl.it/@DRmoto/DMStoDec
"""

from __future__ import print_function
from __future__ import division

import math
import rospy
from std_msgs.msg import Float64
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

######################################
######################################
######################################

point_density = 100 # how many points between each interpolated point

# Placeholders for output ECEF conversion
X_Position = []
Y_Position = []
Z_Position = []

vector_size = 0

# Initially converted from MATLAB rough equivalent: [None]*vector_size*point_density 
x_interpolated_position = []
y_interpolated_position = []

# Converted from MATLAB rough equivalent: #[None]*point_density
y_break = []
x_break = []

def interpolation_function():
    """Converts all input points from Geodetic to ECEF coordinates and publishes them.

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

    # x_publisher = rospy.Publisher('interpolation_x', Float64, queue_size = 10)
    # y_publisher = rospy.Publisher('interpolation_y', Float64, queue_size=10)
    path_publisher = rospy.Publisher('path_node', Path, queue_size=1000)
    rospy.init_node('interpolation_node', anonymous = True)
    rate = rospy.Rate(1)
    
    i = 0 # initialize global index for initial positions

    while not rospy.is_shutdown():
        print("Entered rospy")

        path = Path()

        while i < vector_size-2:
            
            print("Entered while")
            x_0 = X_Position[i]     # declaring the first x-position for interpolation
            x_1 = X_Position[i+1]   # declaring the second x-position for interpolation
            y_0 = Y_Position[i]     # declaring the first y-position for interpolation
            y_1 = Y_Position[i+1]   # declaring the second y-position for interpolation
                
            if y_1 < y_0: # when the slope is negative
                for a in range (0,point_density):
                    if a == 0:
                        y_break.append(y_0) # initial y_position
                        x_break.append(x_0) # initial x_position
                    elif a > 0:
                        y_break.append(y_0-(y_0-y_1)*a/point_density) # interpolate with the given point density
                        x_break.append(x_0-(x_0-x_1)*a/point_density)
            else: # when the slope is positive
                for a in range (0,point_density):
                    if a == 0:
                        y_break.append(y_0) # initial y_position
                        x_break.append(x_0) # initial x_position
                    elif a > 0:
                        y_break.append(y_0-(y_0-y_1)*a/point_density) # interpolate with the given point density
                        x_break.append(x_0-(x_0-x_1)*a/point_density)

            y_interpolated_position.append(y_break)
            x_interpolated_position.append(x_break)
	    i+=1
            
        for c in range (len(y_interpolated_position)):
            print("Entered outer for")
            
            # rospy.loginfo("Interpolated Y Position: %f", y_interpolated_position[c])
            # y_publisher.publish(y_interpolated_position[c])
            # x_publisher.publish(x_interpolated_position[c])
            # print(x_interpolated_position[c])

            for i in range(len(y_break)):
                currentPoseStampMsg = PoseStamped()

                currentPoseStampMsg.pose.position.x =  x_break[c] 
                currentPoseStampMsg.pose.position.y =  x_break[c] 
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
    
    for i in range(min(len(latitudesData), len(longitudesData), len(heightsData))):
        x, y, z = geodetic_to_ECEF_coordinates(latitudesCN2002[i], longitudesCN2002[i], heightsCN2002[i])
        X_Position.append(x)
        Y_Position.append(y)
        Z_Position.append(z)

def main():

    geodetic_data_to_ECEF_data(latitudesCN2002, longitudesCN2002, heightsCN2002)

    print("X_Position =", X_Position, "\nY_Position =", Y_Position, "\nZ_Position =", Z_Position)
    print("\n")

    # Find the length of the x_position list
    global vector_size 
    vector_size= len(X_Position) 

    try:
        interpolation_function()
    except rospy.ROSInterruptException:
        pass

if __name__ == '__main__':
    main()

