#!/usr/bin/env python

"""For all geodesy calculations and conversions"""

from __future__ import print_function
from __future__ import division

import math
import utm

class Geodesy(object):
    """All Geodesy related calculations
    
    TODO: Add class docstrings, __str__, and __repr__ methods
    TODO: Consider moving set_dist_between_points() method and centimetersPerPoint variable to this class
    """

    def __init__(self):
        self._a = 6378137.0         # equatorial radius of earth. Also the WGS-84 Earth semimajor axis in meters
        self._b = 6356752.314245    # polar radius of earth. Also the derived Earth semiminor axis in meters
        self._e = 0.08181788116     # eccentricity of the earth
        self._f = (self.a - self.b) / self.a       # flattening coefficient. Also (1 / 298.257223563)
        self._eSquared = self.f * (2 - self.f)      # square of eccentricity

    @property
    def a(self):
        return self._a

    @property
    def b(self):
        return self._b
    
    @property
    def e(self):
        return self._e

    @property
    def f(self):
        return self._f

    @property
    def eSquared(self):
        return self._eSquared

    def euclidian_distance_3d(self, x1, y1, z1, x2, y2, z2):
        """3-D euclidian distance between two points. Intended use in meters"""
        return math.sqrt(((x1-x2)**2) + ((y1-y2)**2) + ((z1-z2)**2))

    def euclidian_distance_2d(self, x1, y1, x2, y2):
        """2-D euclidian distance between two points. Intended use in meters"""
        return math.sqrt(((x1-x2)**2) + ((y1-y2)**2))
