#!/usr/bin/env python

"""Converts geodetic coordinate system to and from ECEF"""

from __future__ import print_function
from __future__ import division

import math

from geodesy import Geodesy

class GeodesyConverterECEF(Geodesy):
    
    def __init__(self, latitudesData, longitudesData, heightsData):
        self.latitudesData  = latitudesData
        self.longitudesData = longitudesData
        self.heightsData    = heightsData

    def geodetic_to_ECEF_point(self, lat, lng, h):
        """Convert a point in geodetic latitude/longitude/height format to ECEF X/Y/Z format"""

        N = Geodesy.a / math.sqrt(1-(Geodesy.e**2) * (math.sin(lat*math.pi/180)**2))        # prime vertical radius of curvature
        x = (N+h) * math.cos(lat*math.pi/180) * math.cos(lng*math.pi/180) 
        y = (N+h) * math.cos(lat*math.pi/180) * math.sin(lng*math.pi/180)
        z = ((Geodesy.b**2) / (Geodesy.a**2) * N+h) * math.sin(lat * math.pi/180)

        return x, y, z

    def geodetic_data_to_ECEF_data(self):
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

        for i in range(min(len(self.latitudesData), len(self.longitudesData), len(self.heightsData))):
            x, y, z = self.geodetic_to_ECEF_point(self.latitudesData[i], self.longitudesData[i], self.heightsData[i])
            xPosition.append(x)
            yPosition.append(y)
            zPosition.append(z)
        
        return xPosition, yPosition, zPosition

    def global_to_relative_ECEF(self, xPosition, yPosition, zPosition):
        """Convert global ECEF coordinates to relative coordinates at a given index"""
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
