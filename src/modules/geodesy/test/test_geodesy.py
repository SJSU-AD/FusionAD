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
NAME = "test_geodesy"

class TestGeodesy(unittest.TestCase):
    """Validate calculations from geodesy.py"""

    def setUp(self):
        unittest.TestCase.setUp(self)

        self.geodesyTester = Geodesy()
    
    def tearDown(self):
        unittest.TestCase.tearDown(self)
    
    # TODO: Implement type safety in accordance to issue #133
    #############################
    ##### Read/Write Access #####
    #############################
    def test_read_access_a(self):
        pass

    def test_read_access_b(self):
        pass

    def test_read_access_e(self):
        pass

    def test_read_access_f(self):
        pass

    def test_read_access_eSquared(self):
        pass
    
    def test_write_access_a(self):
        pass

    def test_write_access_b(self):
        pass

    def test_write_access_e(self):
        pass

    def test_write_access_f(self):
        pass

    def test_write_access_eSquared(self):
        pass
    
    #######################################################
    ##### euclidian_distance_2d(self, x1, y1, x2, y2) #####
    #######################################################
    def test_euclidian_distance_2d_zeros(self):
        self.assertEqual(self.geodesyTester.euclidian_distance_2d(0, 0, 0, 0), 0)

    def test_euclidian_distance_2d_perfect_square(self):
        self.assertAlmostEqual(self.geodesyTester.euclidian_distance_2d(0, 0, 3, 4), 5, places=7)

    def test_euclidian_distance_2d_large_value(self):
        self.assertAlmostEqual(self.geodesyTester.euclidian_distance_2d(0, 0, 9999999999, 9999999999), 14142135622.316736, places=7)
    
    ###############################################################
    ##### euclidian_distance_2d(self, x1, y1, z1, x2, y2, z2) #####
    ###############################################################
    def test_euclidian_distance_3d_zeros(self):
        self.assertEqual(self.geodesyTester.euclidian_distance_3d(0, 0, 0, 0, 0, 0), 0)
    
    def test_euclidian_distance_3d_large_value(self):
        """One order of magnitude greater than diameter of Earth, in meters"""
        self.assertAlmostEqual(self.geodesyTester.euclidian_distance_3d(0, 0, 0, 99999999, 99999999, 99999999), 173205079.02484, places=5)
    
def main():
    import rostest
    rostest.run(PKG, NAME, TestGeodesy)

if __name__ == '__main__':
    main()