#!/usr/bin/env python

"""For all geodesy calculations and conversions"""

from __future__ import print_function
from __future__ import division

import math
import utm

a = 6378137         # equatorial radius of earth
b = 6356753         # polar radius of earth
e = 0.08181788116   # eccentricity of the earth

def euclidian_distance_3d(x1, y1, z1, x2, y2, z2):
    """3-D euclidian distance between two points. Intended use in meters"""
    return math.sqrt( ((x1-x2)**2) + ((y1-y2)**2) + ((z1-z2)**2) )

def euclidian_distance_2d(x1, y1, x2, y2):
    """2-D euclidian distance between two points. Intended use in meters"""
    return math.sqrt( ((x1-x2)**2) + ((y1-y2)**2) )

#################################
"""Geodetic to ECEF conversion"""
#################################

def geodetic_to_ECEF_point(lat, lng, h):
    """Convert a point in geodetic latitude/longitude/height format to ECEF X/Y/Z format"""

    N = a / math.sqrt(1-(e**2) * (math.sin(lat*math.pi/180)**2))        # prime vertical radius of curvature
    x = (N+h) * math.cos(lat*math.pi/180) * math.cos(lng*math.pi/180) 
    y = (N+h) * math.cos(lat*math.pi/180) * math.sin(lng*math.pi/180)
    z = ((b**2) / (a**2) * N+h) * math.sin(lat * math.pi/180)

    return x, y, z

def geodetic_data_to_ECEF_data(latitudesData, longitudesData, heightsData):
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
    xPosition: array_like
        X position of coordinates in ECEF coordinates
    yPosition: array_like
        Y position of coordinates in ECEF coordinates
    zPosition: array_like
        Z position of coordinates in ECEF coordinates
    """

    xPosition = []
    yPosition = []
    zPosition = []

    for i in range(min(len(latitudesData), len(longitudesData), len(heightsData))):
        x, y, z = geodetic_to_ECEF_point(latitudesData[i], longitudesData[i], heightsData[i])
        xPosition.append(x)
        yPosition.append(y)
        zPosition.append(z)
    
    return xPosition, yPosition, zPosition

def global_to_relative_ECEF(xPosition, yPosition, zPosition):
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

#################################
"""Geodetic to UTM conversion"""
#################################
"""Reference: https://en.wikipedia.org/wiki/Universal_Transverse_Mercator_coordinate_system#From_latitude,_longitude_(%CF%86,_%CE%BB)_to_UTM_coordinates_(E,_N)

NOTE: Lengths are in kilometers 
"""

# Flattening coefficient
flatteningCoeff = 1 / 298.257223563
N_0             = 0.0 # for Northern Hemisphere, in kilometers
k_0             = 0.9996
E_0             = 500 

def geodetic_to_UTM(lat, lng):
    """Converts input geodetic latitude/longitude to UTM"""
    # # Calculate preliminary values
    # n = flatteningCoeff / (2-flatteningCoeff)

    # A       = ( a / (1 + n) ) * (1 + ((n**2)/4) + ((n**4)/64)) )
    # alpha1  = (1/2)*n - (2/3)*(n**2) + (5/16)*(n**3)
    # alpha2  = (13/48)*(n**2) - (3/5)*(n**3)
    # alpha3  = (61/240)*(n**3)
    # alpha1  = (1/2)*n - (2/3)*(n**2) + (37/96)*(n**3)
    # alpha2  = (1/48)*(n**2) + (1/15)*(n**3)
    # alpha3  = (61/240)*(n**3)
    return

def geodetic_data_to_UTM_data(latitudesData, longitudesData, heightsData):

    eastings    = []
    northings   = []
    zoneNumbers = []
    zoneLetters = []

    for i in range(len(latitudesData)):
        print("latitudesData[i] is:", latitudesData[i])
        easting, northing, zoneNumber, zoneLetter = utm.from_latlon(latitudesData[i], longitudesData[i])
        # easting, northing, zoneNumber, zoneLetter = utm.from_latlon(37,123)
        eastings.append(easting)
        northings.append(northing)
        zoneLetters.append(zoneNumber)
        zoneLetters.append(zoneLetter)


    return eastings, northings, zoneNumbers, zoneLetters

def global_to_relative_UTM(eastings, northings):
    """Convert global coordinates to relative coordinates at a given index"""
    globalEastingInitial  = eastings[0]
    globalNorthingInitial = northings[0]
    
    relativeEasting  = []
    relativeNorthing = []

    for i in range(len(eastings)):
        relativeEasting.append(eastings[i] - globalEastingInitial)
        relativeNorthing.append(northings[i] - globalNorthingInitial)
    
    return relativeEasting, relativeNorthing 
