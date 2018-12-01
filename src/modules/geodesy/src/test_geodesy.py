#!/usr/bin/env python

from __future__ import print_function
from __future__ import division

PKG = "geodesy"

import unittest
from geodesy import Geodesy

class TestGeodesy(unittest.TestCase):
    """Validate calculations from geodesy.py"""

    def test_euclidian_distance_2d(self):
        geodesyTester = Geodesy()
        self.assertAlmostEqual(geodesyTester.euclidian_distance_2d(0, 0, 3, 4), 5, places=7)

    

def main():
    import rosunit
    rosunit.unitrun(PKG, 'test_geodesy', TestGeodesy)

if __name__ == '__main__':
    main()