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

# TODO: Modularize parser to test exceptions (bad IO and formatting)
# per issue # 
class TestGpsParser(unittest.TestCase):
    """Validate File I/O and operations from gps_parser.py"""

    def setup(self):
        unittest.TestCase.setUp(self)

    def tearDown(self):
        unittest.TestCase.tearDown(self)
    
    def test_gps_file_format_error_good_file(self):
        """Check file with correct '.txt' extension.
        """
        pass

    def test_gps_file_format_error_bad_file(self):
        """Check if exception is thrown on input file without '.txt' extension
        """
        pass
    
    def test_gps_format_error_good_file(self):
        """Check file with correct format"""
        pass

    def test_gps_format_error_bad_file(self):
        """Check if exception is thrown on input file that is not formatted properly
        """
        pass

    def test_valid_return_lists(self):
        """Check parser returns lists
        """
        latitudes, longitudes, heights = gps_parser.read_file_coarse_points("test_gps_parser_file1.txt", 0)
        self.assertIsInstance(latitudes, list)
        self.assertIsInstance(longitudes, list)
        self.assertIsInstance(heights, list)
        

    def test_one_line_only(self):
        """Test one line mode functionality."""
        pass
    
# def main():
#     """NOTE: Does not work with rosunit or rostest yet
#     MUST run `python -m unittest test_gps_parser` to run these tests
#     """
#     import rosunit
#     rosunit.rosrun(PKG, NAME, TestGpsParser)

# if __name__ == '__main__':
#     main()

