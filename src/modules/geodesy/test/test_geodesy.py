#!/usr/bin/env python

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import rospkg

rospack = rospkg.RosPack()

import os
import sys
import unittest
sys.path.append(os.path.join(rospack.get_path('geodesy'), 'src/'))

from geodesy import Geodesy

PKG = "geodesy"
NAME = 'test_geodesy'

class TestGeodesy(unittest.TestCase):
    """Validate calculations from geodesy.py"""

    def setUp(self):
        unittest.TestCase.setUp(self)

        self.geodesyTester = Geodesy()
    
    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def test_euclidian_distance_2d_perfect_square(self):
            self.assertAlmostEqual(self.geodesyTester.euclidian_distance_2d(0, 0, 3, 4), 5, places=7)
    
    def test_euclidian_distance_2d_zeros(self):
        self.assertEqual(self.geodesyTester.euclidian_distance_2d(0, 0, 0, 0), 0)

    # def test_euclidian_distance_3d(self):
    #     self.assertEqual(1, 2)
    
def main():
    import rostest
    rostest.run(PKG, NAME, TestGeodesy)

if __name__ == '__main__':
    main()