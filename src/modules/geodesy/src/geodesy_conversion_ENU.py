#!/usr/bin/env python

"""Converts geodetic or ECEF coordinate system to ENU"""

from __future__ import print_function
from __future__ import division

import math

from geodesy_conversion_ECEF import GeodesyConverterECEF

class GeodesyConverterENU(GeodesyConverterECEF):
    def __init__(self, latitudesData, longitudesData, heightsData, radarPoint=None):
        ## TODO: Make ECEF_to_ENU_point() a @staticmethod to reduce unnecessary object instantiation
        ##       OR make setters to get initial GPS position
        # if latitudesData  == None:
        #     latitudesData  = []
        # if longitudesData == None:
        #     longitudesData = []
        # if heightsData    == None:
        #     heightsData    = []

        super(GeodesyConverterENU, self).__init__(
            latitudesData, longitudesData, heightsData)
        
        if radarPoint != None:
            print("==========USING CUSTOM POINT!!!")
            self.radarLat = radarPoint[0]
            self.radarLon = radarPoint[1]
            self.radarHeight = radarPoint[2]
        else:
            self.radarLat = self.latitudesData[0]
            self.radarLon = self.longitudesData[0]
            self.radarHeight = self.heightsData[0]

    def geodetic_to_ENU_point(self, latitudeCoord, longitudeCoord, heightCoord, lat0=None, lon0=None, h0=None):
        """Convert relative ECEF coordinates to (East, North, Up) coordinates.

        NOTE: Uses initial geodetic point as reference for initial position if lat0, lon0, or h0 are not given
        
        Reference material: https://gist.github.com/    /41adb25532e658e41d541469f832c44a
            Converts the Earth-Centered Earth-Fixed (ECEF) coordinates (x, y, z) to 
            East-North-Up coordinates in a Local Tangent Plane that is centered at the 
            (WGS-84) Geodetic point (lat0, lon0, h0).
        """

        x, y, z = super(GeodesyConverterENU, self).geodetic_to_ECEF_point(
            latitudeCoord, longitudeCoord, heightCoord)

        if lat0 == None:
            lat0 = self.radarLat
        if lon0 == None:
            lon0 = self.radarLon
        if h0 == None:
            h0 = self.radarHeight

        lambdaValue = math.radians(lat0)
        phiValue = math.radians(lon0)
        sValue = math.sin(lambdaValue)
        nValue = self.a / math.sqrt(1 - self.eSquared * sValue * sValue)

        sinLambda = math.sin(lambdaValue)
        cosLambda = math.cos(lambdaValue)
        sinPhi = math.sin(phiValue)
        cosPhi = math.cos(phiValue)

        x0 = (h0 + nValue) * cosLambda * cosPhi
        y0 = (h0 + nValue) * cosLambda * sinPhi
        z0 = (h0 + (1 - self.eSquared) * nValue) * sinLambda

        xd = x - x0
        yd = y - y0
        zd = z - z0

        # From matrix multiplication
        east = -sinPhi * xd + cosPhi * yd
        north = -cosPhi * sinLambda * xd - sinLambda * sinPhi * yd + cosLambda + zd
        up = cosLambda * cosPhi * xd + cosLambda * sinPhi * yd + sinLambda * zd

        return east, north, up

    def geodetic_data_to_ENU_data(self):
        eData = []
        nData = []
        uData = []

        for i in range(min(len(self.latitudesData), len(self.longitudesData), len(self.heightsData))):
            e, n, u = self.geodetic_to_ENU_point(
                self.latitudesData[i], self.longitudesData[i], self.heightsData[i])
            eData.append(e)
            nData.append(n)
            uData.append(u)

        return eData, nData, uData

    def ECEF_to_ENU_point_from_wiki(self, i):
        """Convert geodetic point to ENU point

        Reference material: https://en.wikipedia.org/wiki/Geographic_coordinate_conversion#From_ECEF_to_ENU
        TODO: Cross reference this with https://gist.github.com/drofp/41adb25532e658e41d541469f832c44a
        """
        return

    def ENU_to_ECEF_point(self, east, north, up, lat0=None, lon0=None, h0=None):
        """Taken from: https://gist.github.com/govert/1b373696c9a27ff4c72a"""

        if lat0 == None:
            lat0 = self.latitudesData[0]
        if lon0 == None:
            lon0 = self.longitudesData[0]
        if h0 == None:
            h0 = self.heightsData[0]

        lambdaValue = math.radians(lat0)
        phiValue = math.radians(lon0)
        sValue = math.sin(lambdaValue)
        nValue = self.a / math.sqrt(1 - self.eSquared * sValue * sValue)

        sinLambda = math.sin(lambdaValue)
        cosLambda = math.cos(lambdaValue)
        sinPhi = math.sin(phiValue)
        cosPhi = math.cos(phiValue)

        x0 = (h0 + nValue) * cosLambda * cosPhi
        y0 = (h0 + nValue) * cosLambda * sinPhi
        z0 = (h0 + (1 - self.eSquared) * nValue) * sinLambda

        xd = -sinPhi * east - cosPhi * sinLambda * north + cosLambda * cosPhi * up
        yd = cosPhi * east - sinLambda * sinPhi * north + cosLambda * sinPhi * up
        zd = cosLambda * north + sinLambda * up

        x = xd + x0
        y = yd + y0
        z = zd + z0

        return x, y, z

    def ENU_data_to_ECEF_data(self, eData, nData, uData, lat0=None, lon0=None, h0=None):
        xData = []
        yData = []
        zData = []

        for i in range(min(len(eData), len(nData), len(uData))):
            x, y, z = self.ENU_to_ECEF_point(eData[i], nData[i], uData[i], lat0, lon0, h0)
            xData.append(x)
            yData.append(y)
            zData.append(z)

        return xData, yData, zData
