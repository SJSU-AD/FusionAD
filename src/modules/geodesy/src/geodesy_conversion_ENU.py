#!/usr/bin/env python

"""Converts geodetic or ECEF coordinate system to ENU"""

from __future__ import print_function
from __future__ import division

import math

from geodesy_conversion_ECEF import GeodesyConverterECEF

class GeodesyConverterENU(GeodesyConverterECEF):
    def __init__(self, latitudesData, longitudesData, heightsData):
        super(GeodesyConverterENU, self).__init__(latitudesData, longitudesData, heightsData)
    
    def ECEF_to_ENU_point(self, i):
        """Convert relative ECEF coordinates to (East, North, Up) coordinates.

        NOTE: Uses initial geodetic point as reference for initial position
        
        Reference material: https://gist.github.com/drofp/41adb25532e658e41d541469f832c44a
            Converts the Earth-Centered Earth-Fixed (ECEF) coordinates (x, y, z) to 
            East-North-Up coordinates in a Local Tangent Plane that is centered at the 
            (WGS-84) Geodetic point (lat0, lon0, h0).
        """

        x, y, z = super(GeodesyConverterENU, self).geodetic_to_ECEF_point(self.latitudesData[i], self.longitudesData[i], self.heightsData[i])
        
        lat0 = self.latitudesData[0]
        lon0 = self.longitudesData[0]
        h0   = self.heightsData[0]

        eSquared = self.f * (2 - self.f)      # square of eccentricity

        lambdaValue = math.radians(lat0)
        phiValue    = math.radians(lon0)
        sValue      = math.sin(lambdaValue)
        nValue      = self.a / math.sqrt(1 - eSquared * sValue * sValue)

        sinLambda = math.sin(lambdaValue)
        cosLambda = math.cos(lambdaValue)
        sinPhi    = math.sin(phiValue)
        cosPhi    = math.cos(phiValue)

        x0 = (h0 + nValue) * cosLambda * cosPhi
        y0 = (h0 + nValue) * cosLambda * sinPhi
        z0 = (h0 + (1- eSquared) * nValue) * sinLambda

        xd = x - x0
        yd = y - y0
        zd = z - z0

        # From matrix multiplication
        east  = -sinPhi * xd + cosPhi * yd
        north = -cosPhi * sinLambda * xd - sinLambda * sinPhi * yd + cosLambda + zd
        up    = cosLambda * cosPhi * xd + cosLambda * sinPhi * yd + sinLambda * zd

        return east, north, up

    def ECEF_data_to_ENU_data(self):
        eData = []
        nData = []
        uData = []

        for i in range(min(len(self.latitudesData), len(self.longitudesData), len(self.heightsData))):
            e, n, u = self.ECEF_to_ENU_point(i)
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