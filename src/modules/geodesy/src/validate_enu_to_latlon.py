#!/usr/bin/env python

"""Convert ENU data to latitude/longitude GPSVisualizer data"""

from __future__ import print_function
from __future__ import division

from Tkinter import Tk
from tkFileDialog import askopenfilename
import argparse

import validate_geodesy_conversion as gct

# TODO: Input ENU data is mandatory
# TODO: Output file names, freq are optional

def prompt_input():
    """Get necessary inputs for conversion
    
    Returns
    -------
    str
        Path to input bagfile
    str
        Name of output lat/lon conversion file
    str
        Name of output lat/lon GPSVisualizer file
    """

    Tk().withdraw()
    fileName = askopenfilename()
    
    parser = argparse.ArgumentParser(description="Get file names")
    parser.add_argument("-f", "--frequency", 
                        help="Filtering frequency",
                        default=100,
                        type=int,
                        dest="filteringRate")
    parser.add_argument("-c", "--conversion-to-lat-long-file", 
                        help="File name to output file storing converted lat/lon values in '.csv' format",
                        default="",
                        type=str,
                        dest="conversionFileName")
    parser.add_argument("-g", "--gpsvisualizer-format-file", 
                        help="File name to output file storing converted lat/lon values in GPS visualizer format",
                        default="",
                        type=str,
                        dest="visualizerFileName")

    args = parser.parse_args()
    print("args are: ", args.filteringRate, args.conversionFileName, args.visualizerFileName)

    return fileName, args.filteringRate, args.conversionFileName, args.visualizerFileName

def main():
    fileName, filteringRate, latLonFileNameCsv, latLonFileNameTxt = prompt_input()

    print("fileName: ", fileName)
    print("args after are: ", filteringRate, latLonFileNameCsv, latLonFileNameTxt)

if __name__ == "__main__":
    main()

