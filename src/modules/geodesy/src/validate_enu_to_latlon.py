#!/usr/bin/env python

"""Convert ENU data to latitude/longitude GPSVisualizer data

Accepts path to bagfile to parse. Converts ENU coordinates from path
and GPS data from bag into latitude/longitude in '.csv' lat/lon format
and '.txt' GPSVisualizer format.

Data from the '.txt' file can then be plotted at http://www.gpsvisualizer.com/draw/

Output files can be found in the /geodesy/geodesy_data/data_validation directory

USAGE:
    python validate_enu_to_latlon.py INITIAL_LATITUDE INITIAL_LONGITUDE INITIAL_HEIGHT
- where INITIAL_LATITUDE, INITIAL_LONGITUDE, and INITIAL_HEIGHT must be supplied for
valid ENU conversions. This supplies the 'radar' point reference.
"""

from __future__ import print_function
from __future__ import division

from Tkinter import Tk
from tkFileDialog import askopenfilename
import argparse
import math
import sys

import rosbag

from geodesy_conversion_ENU import GeodesyConverterENU

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
    """Get commmand line inputs for conversion"""
    
    parser = argparse.ArgumentParser(description="Tool to convert ENU bag data to lat/lon GPSVisualizer data")

    # positional args
    parser.add_argument("initialLatitude", 
                        help="Initial latitude (radar location) from planned path",
                        type=float)
    parser.add_argument("initialLongitude", 
                        help="Initial longitude (radar location) from planned path",
                        type=float)
    parser.add_argument("initialAltitude", 
                        help="Chosen fixed altitude of lat/lon data",
                        type=float,)

    default_bag_filepath = None
    default_filter_freq = 100
    default_path_filename = "enuToLatLon_path_fromBag.txt"
    default_gps_filename = "enuToLatLon_gpsData_fromBag.txt"
    default_path_topic = "/planning/trajectory"
    default_gps_topic = "/localization/state"
    
    # optional args
    parser.add_argument("-b", "--bag-file-path", 
                        help="Path to input bag file"\
                            + " Default={}".format(default_bag_filepath),
                        default=default_bag_filepath,
                        type=str,
                        dest="bagFilePath")
    parser.add_argument("-f", "--frequency", 
                        help="How many points to skip before saving a point in the input data."\
                            + " Default={}".format(default_filter_freq),
                        default=default_filter_freq,
                        type=int,
                        dest="filteringFreq")
    parser.add_argument("-o", "--path-output-file", 
                        help="File name to output file storing converted lat/lon values in GPSVisualizer format"\
                           + " Default={}".format(default_path_filename),
                        default=default_path_filename,
                        type=str,
                        dest="pathFileName")
    parser.add_argument("-s", "--gps-output-file", 
                        help="File name to output file storing converted lat/lon values in GPSVisualizer format"\
                            + " Default={}".format(default_gps_filename),
                        default=default_gps_filename,
                        type=str,
                        dest="gpsFileName")
    parser.add_argument("-p", "--path-topic", 
                        help="Name of topic publishing path"\
                            + " Default={}".format(default_path_topic),
                        default=default_path_topic,
                        type=str,
                        dest="pathTopic")
    parser.add_argument("-g", "--gps-topic", 
                        help="Name of topic GPS ENU data"\
                            + " Default={}".format(default_gps_topic),
                        default=default_gps_topic,
                        type=str,
                        dest="gpsTopic")

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

def print_input_args(optional_args):
    config_properties_label = "=====Configuration Properties====="
    print(len(config_properties_label) * "=" 
        + "\n{}\n".format(config_properties_label)
        + len(config_properties_label) * "=")
    
    for arg, val in optional_args.iteritems():
        print("{} = {}".format(arg, val))
    
    print()

def generate_latlon_files(properties):
    """Parses bag file for ENU data and writes recorded data as lat/lon
    
    Path data and GPS data are written to '.txt' files 
    - both are compatible with GPSVisualizer format
    
    NOTE: First point in path will be used as 'radar' point for ENU calculations
    """

    bagFilePath = properties["bagFilePath"]

    eData, nData, uData = parse_path_enu_data(properties, bagFilePath, properties["pathTopic"])
    latData, lonData = enu_to_latlon(properties, eData, nData, uData)
    # write '.txt' for path data
    with open(properties["pathFileName"], "wb") as pathFile:
        write_latlon_data(latData, lonData, pathFile)
        

    eData, nData, uData = parse_path_enu_data(properties, bagFilePath, properties["gpsTopic"])
    latData, lonData = enu_to_latlon(properties, eData, nData, uData)
    # write '.txt' for gps data
    with open(properties["gpsFileName"], "wb") as pathFile:
        write_latlon_data(latData, lonData, pathFile)

def parse_path_enu_data(properties, bagFilePath, chosenTopic):
    """Collects ENU data from bag"""

    bag = rosbag.Bag(bagFilePath)

    frequency = properties["filteringFreq"]

    eData = []
    nData = []
    uData = []

    for topic, msg, t in bag.read_messages(topics=[chosenTopic]):
        if frequency == None:
            for seq in range(len(msg.poses) - 1):
                eData.append(msg.poses[seq].pose.position.x)
                nData.append(msg.poses[seq].pose.position.y)
                uData.append(msg.poses[seq].pose.position.z)
        else:
            for seq in range(len(msg.poses) - 1):
                if seq % frequency == 0:
                    eData.append(msg.poses[seq].pose.position.x)
                    nData.append(msg.poses[seq].pose.position.x)
                    uData.append(msg.poses[seq].pose.position.z)

    bag.close()

    return eData, nData, uData
    
def enu_to_latlon(properties, eData, nData, uData):
    """Convert ENU data to lat/lon data"""

    latData = []
    lonData = []

    enuConverter = GeodesyConverterENU(eData, nData, uData)

    xData, yData, zData = enuConverter.ENU_data_to_ECEF_data(eData, nData, uData, 
                                                             lat0=properties["initialLatitude"],
                                                             lon0=properties["initialLongitude"],
                                                             h0=properties["initialAltitude"])

    latData, lonData = enuConverter.ECEF_data_to_geodetic_data(xData, yData, zData)

    return latData, lonData

def write_latlon_data(latData, lonData, pathFile):
    """Writes lat/lon data to GPSVisualizer '.txt' file"""

    pathFile.write("type	latitude	longitude	name")

    waypointCounter = 1
    for _ in latData:
        pathFile.write("W\t{}\t{}\t{}\n".format(latData[0], lonData[1].strip(), str(waypointCounter)))
        waypointCounter += 1
    
def main():
    optional_args = prompt_input()

    print_input_args(optional_args)

    generate_latlon_files(optional_args)

if __name__ == "__main__":
    main()
