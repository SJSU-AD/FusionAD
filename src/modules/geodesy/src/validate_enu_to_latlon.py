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
import math
import sys

import rosbag

import validate_geodesy_conversion as gct

# TODO: Input ENU data is mandatory
# TODO: Output file names, freq are optional

def prompt_input():
    """Prompt user for necessary filenames and parameters"""
    bagFilePath = get_bag_location()
    print("Chosen bag location is: ", bagFilePath)

    optional_args = get_cmd_input()

    return bagFilePath, optional_args

def get_bag_location():
    Tk().withdraw()
    bagFilePath = askopenfilename()

    return bagFilePath

def get_cmd_input():
    """Get optional commmand line inputs for conversion
    
    Returns
    -------
    str
        Path to input bagfile
    int
        Filtering rate (on ENU data)
    str
        Name of output lat/lon path file
    str
        Name of output lat/lon GPS data file
    str
        Name of path topic
    str
        Name of GPS ENU data output topic
    float
        Chosen fixed altitude of lat/lon data
    """
    
    parser = argparse.ArgumentParser(description="Get file names")
    parser.add_argument("-f", "--frequency", 
                        help="Filtering frequency",
                        default=100,
                        type=int,
                        dest="filteringRate")
    parser.add_argument("-t", "--path-output-file", 
                        help="File name to output file storing converted lat/lon values in '.csv' format",
                        default="enuToLatLon_fromBag.txt",
                        type=str,
                        dest="pathFileName")
    parser.add_argument("-m", "--gps-output-file", 
                        help="File name to output file storing converted lat/lon values in GPS visualizer format",
                        default="enuToLatLon_fromBag.txt",
                        type=str,
                        dest="gpsFileName")
    parser.add_argument("-p", "--path-topic", 
                        help="Name of topic publishing path",
                        default="/planning/trajectory",
                        type=str,
                        dest="pathTopic")
    parser.add_argument("-g", "--gps-topic", 
                        help="Name of topic GPS ENU data",
                        default="/localization/state",
                        type=str,
                        dest="gpsTopic")
    parser.add_argument("-a", "--altitude", 
                        help="Chosen fixed altitude of lat/lon data",
                        default=-6.0,
                        type=float,
                        dest="chosenAltitude")

    optional_args = vars(parser.parse_args())

    ##### Validate a valid value for filtering rate is chosen #####
    while optional_args["filteringRate"] < 1 and optional_args["filteringRate"] != None:
        try:
            print("Please enter a frequency value of 'None' (to specify no filtering)" +
                   "or an integer value greater than 0: ", end="")
            new_filtering_rate = unicode(sys.stdin.readline().strip(), "utf-8")
            print("Input value is: ", new_filtering_rate)
            if new_filtering_rate == "None":
                optional_args["filteringRate"] = None
            elif new_filtering_rate.isnumeric():
                optional_args["filteringRate"] = int(math.floor(float(new_filtering_rate)))
        except KeyboardInterrupt:
            print("\nNow exitting the ENU-to-latlon validator...")
            sys.exit()

    return optional_args

def generate_latlon_files(bagFilePath, properties):
    """Parses bag file for ENU data and writes recorded data as lat/lon
    
    Path data is written to '.csv' file, GPS data written to '.txt' file"""
    

    # write '.txt' for path data
    with open(properties["pathFileName"], "wb") as pathFile:
        eData, nData = parse_path_enu_data(bagFilePath, properties["frequency"])
        

    # for topic, msg, t in bag.read_messages(topic=["/localization/state"]):
    #     for seq in range(len(msg))

    # write '.txt' for GPS data
    with open(properties["gpsFileName"], "wb") as gpsFile:
        parse_gps_data(bagFilePath, [eData[0], nData[0]])

def parse_path_enu_data(bagFilePath, frequency):
    """Writes ENU data from path to bag
    
    NOTE: First point in path will be used as 'radar' point for ENU calculations"""

    bag = rosbag.Bag(bagFilePath)

    eData = []
    nData = []

    for topic, msg, t in bag.read_messages(topics=["/planning/trajectory"]):

        if frequency == None:
            for seq in range(len(msg.poses) - 1):
                eData.append(msg.poses[seq].pose.position.x)
                nData.append(msg.poses[seq].pose.position.x)    
        else:
            for seq in range(len(msg.poses) - 1):
                if seq % frequency == 0:
                    eData.append(msg.poses[seq].pose.position.x)
                    nData.append(msg.poses[seq].pose.position.x)
    
    bag.close()

    return eData, nData
    
def parse_gps_data(bagFilePath, radarPoint):
    """Writes ENU data from path to bag
    
    NOTE: First point in path will be used as 'radar' point for ENU calculations"""
    pass

def main():
    bagFilePath, optional_args = prompt_input()

    config_properties_label = "=====Configuration Properties====="
    print(config_properties_label)

    print("\n" + len(config_properties_label) * "=")
    print("Bag File Location:\n{}".format(bagFilePath))

    print("\n" + len(config_properties_label) * "=")
    print()
    
    for arg, val in optional_args.iteritems():
        print("{} = {}".format(arg, val))

    # generate_latlon_files(bagFilePath, optional_args)

if __name__ == "__main__":
    main()

