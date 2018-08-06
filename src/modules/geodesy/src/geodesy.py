#!/usr/bin/env python

"""For all geodesy calculations and conversions"""

from __future__ import print_function
from __future__ import division

import math
import utm

class Geodesy(object):
    a = 6378137         # equatorial radius of earth
    b = 6356753         # polar radius of earth
    e = 0.08181788116   # eccentricity of the earth

    def __init__(self):
            pass

    def euclidian_distance_3d(self, x1, y1, z1, x2, y2, z2):
        """3-D euclidian distance between two points. Intended use in meters"""
        return math.sqrt( ((x1-x2)**2) + ((y1-y2)**2) + ((z1-z2)**2) )

    def euclidian_distance_2d(self, x1, y1, x2, y2):
        """2-D euclidian distance between two points. Intended use in meters"""
        return math.sqrt( ((x1-x2)**2) + ((y1-y2)**2) )
