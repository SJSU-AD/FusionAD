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

import gps_parser

PKG = "geodesy"
NAME = "test_gps_parser"

class TestGpsParser(unittest.TestCase):
    """Validate File I/O and operations from gps_parser.py"""

    def setup(self):
        unittest.TestCase.setUp(self)

    def tearDown(self):
        unittest.TestCase.tearDown(self)
    
    def test_gps_file_format_error_good_file(self):
        pass

    def test_gps_file_format_error_bad_file(self):
        pass
    
    def test_gps_format_error_good_file(self):
        pass

    def test_gps_format_error_bad_file(self):
        pass

    def test_valid_return_lists(self):
        pass

    def test_one_line_only(self):
        pass
    
def main():
    import rostest
    rostest.run(PKG, NAME, TestGpsParser)

if __name__ == '__main__':
    main()

