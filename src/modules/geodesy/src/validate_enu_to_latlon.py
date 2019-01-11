#!/usr/bin/env python

"""Convert ENU data to latitude/longitude GPSVisualizer data

Accepts path to bagfile to parse. Converts ENU coordinates from path
and GPS data from bag into latitude/longitude in '.csv' lat/lon format
and '.txt' GPSVisualizer format.

Data from the '.txt' file can then be plotted at http://www.gpsvisualizer.com/draw/

Output files can be found in the /geodesy/geodesy_data/data_validation directory
"""

from __future__ import print_function
from __future__ import division

from Tkinter import Tk
from tkFileDialog import askopenfilename
import argparse

import rosbag

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
    bagFilePath = askopenfilename()
    
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

    return bagFilePath, args.filteringRate, args.conversionFileName, args.visualizerFileName

def parse_bag(bagFilePath):
    """Parses bag file for ENU data and writes to '.csv'"""

    bag = rosbag.Bag(bagFilePath)
    eData = []
    nData = []

    for topic, msg, t in bag.read_messages(topics=["/planning/trajectory"]):
        for seq in range(len(msg.poses) - 1):
            eData.append(msg.poses[seq].pose.position.x)
            nData.append(msg.poses[seq].pose.position.x)
    
    # for topic, msg, t in bag.read_messages(topic=["/localization/state"]):
    #     for seq in range(len(msg))
    
    bag.close()

def main():
    bagFilePath, filteringRate, latLonFileNameCsv, latLonFileNameTxt = prompt_input()

    print("fileName: ", bagFilePath)
    print("args after are: ", filteringRate, latLonFileNameCsv, latLonFileNameTxt)

if __name__ == "__main__":
    main()

