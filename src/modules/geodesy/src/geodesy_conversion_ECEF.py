#!/usr/bin/env python

"""Converts geodetic coordinate system to ECEF"""

from __future__ import print_function
from __future__ import division

import math

from geodesy import Geodesy

class GeodesyConverterECEF(Geodesy):

    def __init__(self, latitudesData, longitudesData, heightsData):
        super(GeodesyConverterECEF, self).__init__()
        self.latitudesData = latitudesData
        self.longitudesData = longitudesData
        self.heightsData = heightsData

    def geodetic_to_ECEF_point(self, lat, lng, h):
        """Convert a point in geodetic latitude/longitude/height format to ECEF X/Y/Z format"""

        # prime vertical radius of curvature
        N = self.a / math.sqrt(1-(self.e**2) *
                                  (math.sin(lat*math.pi/180)**2))
        x = (N+h) * math.cos(lat*math.pi/180) * math.cos(lng*math.pi/180)
        y = (N+h) * math.cos(lat*math.pi/180) * math.sin(lng*math.pi/180)
        z = ((self.b**2) / (self.a**2) * N+h) * \
            math.sin(lat * math.pi/180)

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

        xPositions = []
        yPositions = []
        zPositions = []

        for i in range(min(len(self.latitudesData), len(self.longitudesData), len(self.heightsData))):
            x, y, z = self.geodetic_to_ECEF_point(
                self.latitudesData[i], self.longitudesData[i], self.heightsData[i])
            xPositions.append(x)
            yPositions.append(y)
            zPositions.append(z)

        return xPositions, yPositions, zPositions

    def global_to_relative_ECEF(self, xPositions, yPositions, zPositions):
        """Convert global ECEF coordinates to relative coordinates at a given index"""
        globalXInitial = xPositions[0]
        globalYInitial = yPositions[0]
        globalZInitial = zPositions[0]

        relativeXData = []
        relativeYData = []
        relativeZData = []

        for i in range(len(xPositions)):
            relativeXData.append(xPositions[i] - globalXInitial)
            relativeYData.append(yPositions[i] - globalYInitial)
            relativeZData.append(zPositions[i] - globalZInitial)

        return relativeXData, relativeYData, relativeZData

    def ECEF_to_geodetic_point(self, x, y, z):
        """From https://gist.github.com/govert/1b373696c9a27ff4c72a"""

        eps = self.eSquared / (1.0 - self.eSquared)
        p = math.sqrt(x * x + y * y)
        q = math.atan2((z * self.a), (p * self.b))
        sinQ = math.sin(q)
        cosQ = math.cos(q)
        sinQ3 = sinQ * sinQ * sinQ
        cosQ3 = cosQ * cosQ * cosQ
        phi = math.atan2((z + eps * self.b * sinQ3),
                         (p - self.eSquared * self.a * cosQ3))
        lambdaValue = math.atan2(y, x)
        v = self.a / math.sqrt(1.0 - self.eSquared *
                               math.sin(phi) * math.sin(phi))
        h = (p / math.cos(phi)) - v

        lat = math.degrees(phi)
        lon = math.degrees(lambdaValue)

        return lat, lon

    def ECEF_data_to_geodetic_data(self, xData, yData, zData):
        latitudesData = []
        longitudesData = []
        heightsData = []

        for i in range(min(len(xData), len(yData), len(zData))):
            lat, lon = self.ECEF_to_geodetic_point(
                xData[i], yData[i], zData[i])
            latitudesData.append(lat)
            longitudesData.append(lon)

        return latitudesData, longitudesData
