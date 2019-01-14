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
    optional_args = get_cmd_input()
    if optional_args["bagFilePath"] == None:
        optional_args["bagFilePath"] = get_bag_location()

    return optional_args

def get_bag_location():
    Tk().withdraw()
    bagFilePath = askopenfilename(initialdir="~", title="Chose bag file location", filetypes=(("Bag files", "*.bag"), ("All files", "*.*")))

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

    default_path_filename = "enuToLatLon_path_fromBag.txt"
    default_gps_filename = "enuToLatLon_gpsData_fromBag.txt"
    default_chosen_altitude = -6.0 # meters
    
    parser = argparse.ArgumentParser(description="Tool to convert ENU bag data to lat/lon GPSVisualizer data")
    parser.add_argument("-b", "--bag-file-path", 
                        help="Path to input bag file",
                        default=None,
                        type=str,
                        dest="bagFilePath")
    parser.add_argument("-f", "--frequency", 
                        help="How many points to skip before saving a point in the input data",
                        default=100,
                        type=int,
                        dest="filteringFreq")
    parser.add_argument("-t", "--path-output-file", 
                        help="File name to output file storing converted lat/lon values in GPSVisualizer format",
                        default=default_path_filename,
                        type=str,
                        dest="pathFileName")
    parser.add_argument("-m", "--gps-output-file", 
                        help="File name to output file storing converted lat/lon values in GPSVisualizer format",
                        default=default_gps_filename,
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
                        default=default_chosen_altitude,
                        type=float,
                        dest="chosenAltitude")

    optional_args = vars(parser.parse_args())

    _validate_bag_location(optional_args)
    _validate_filtering_rate(optional_args)
    _validate_ouput_visualizer_filename(optional_args, "pathFileName", default_path_filename)
    _validate_ouput_visualizer_filename(optional_args, "gpsFileName", default_gps_filename)

    return optional_args

def _validate_bag_location(optional_args):
    """Validate a valid path to bag file is chosen"""
    if optional_args["bagFilePath"] == None:
        optional_args["bagFilePath"] = ""

    while optional_args["bagFilePath"] != None and optional_args["bagFilePath"][-4:] != ".bag":
        try:
            print("Please enter the path (or 'None' to select in file choser window) to the desired bag file to parse"
                + " (complete path is preferred): ", end="")
            optional_args["bagFilePath"] = sys.stdin.readline().strip()

            if optional_args["bagFilePath"].lower() == "none":
                optional_args["bagFilePath"] = None
            
            print("Chosen bag location is: {}\n".format(optional_args["bagFilePath"]))
        except KeyboardInterrupt:
            print("\nNow exitting the ENU-to-latlon validator...")
            sys.exit()

def _validate_filtering_rate(optional_args):
    """Validate a valid value for filtering rate is chosen"""
    
    while optional_args["filteringFreq"] != None and optional_args["filteringFreq"] < 1:
        try:
            print("Please enter an integer frequency value greater than 0"
                + " (or 'None' to specify no filtering) : ", end="")
            optional_args["filteringFreq"] = unicode(sys.stdin.readline().strip(), "utf-8")
            print("Chosen filtering rate is: {}\n".format(optional_args["filteringFreq"]))

            if optional_args["filteringFreq"].lower() == "none":
                optional_args["filteringFreq"] = None
            elif optional_args["filteringFreq"].isnumeric():
                optional_args["filteringFreq"] = int(math.floor(float(optional_args["filteringFreq"])))
        except KeyboardInterrupt:
            print("\nNow exitting the ENU-to-latlon validator...")
            sys.exit()

def _validate_ouput_visualizer_filename(optional_args, arg, default_filename):
    """Validate a valid name for an output file is chosen"""

    while optional_args[arg][-4:] != ".txt":
        try:
            print("Please enter the name (or 'None' for default filename) for the output '.txt' ({}) file".format(arg)
                + " for the GPSVisualizer: ", end="")
            new_output_filename = sys.stdin.readline().strip()
            print("Chosen output GPSVisualizer file ({}) name is: {}\n".format(arg, optional_args[arg]))

            if new_output_filename.lower() == "none":
                optional_args[arg] = default_filename
        except KeyboardInterrupt:
            print("\nNow exitting the ENU-to-latlon validator...")
            sys.exit()

def _validate_chosen_alitude(optional_args):
    """Validate a value for chosen fixed altitude"""

    while optional_args["chosenAltitude"] != None and optional_args["chosenAltitude"] < 1:
        try:
            print("Please enter a chosen altitude value of 'None' (to specify no filtering)" +
                   "or a floating point value: ", end="")
            optional_args["chosenAltitude"] = unicode(sys.stdin.readline().strip(), "utf-8")
            print("Chosen filtering rate is: {}\n".format(optional_args["chosenAltitude"]))

            if optional_args["chosenAltitude"].lower() == "none":
                optional_args["chosenAltitude"] = None
            elif optional_args["chosenAltitude"].isnumeric():
                optional_args["chosenAltitude"] = float(optional_args["chosenAltitude"])
        except KeyboardInterrupt:
            print("\nNow exitting the ENU-to-latlon validator...")
            sys.exit()

def print_input_args(optional_args):
    config_properties_label = "=====Configuration Properties====="
    print(len(config_properties_label) * "=" 
        + "\n{}\n".format(config_properties_label)
        + len(config_properties_label) * "=")
    
    for arg, val in optional_args.iteritems():
        print("{} = {}".format(arg, val))
    
    print()

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
    optional_args = prompt_input()

    print_input_args(optional_args)

    # generate_latlon_files(bagFilePath, optional_args)

if __name__ == "__main__":
    main()

