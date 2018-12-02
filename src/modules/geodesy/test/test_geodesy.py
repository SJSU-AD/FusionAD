#!/usr/bin/env python

from __future__ import print_function
from __future__ import division
from __future__ import absolute_import

import rospkg

rospack = rospkg.RosPack()

import sys
import os
import unittest
sys.path.append(os.path.join(rospack.get_path('geodesy'), 'src/'))

from geodesy import Geodesy

PKG = "geodesy"

class TestGeodesy(unittest.TestCase):
    """Validate calculations from geodesy.py"""

    def test_euclidian_distance_2d(self):
        geodesyTester = Geodesy()
        self.assertAlmostEqual(geodesyTester.euclidian_distance_2d(0, 0, 3, 4), 5, places=7)
    
def main():
    import rostest
    rostest.run(PKG, 'test_geodesy', TestGeodesy)

if __name__ == '__main__':
    main()