#!/usr/bin/env python

"""Parser for input GPS coordinates to obtain latitude and longitude values in decimal"""

from __future__ import print_function
from __future__ import division

class Error(Exception):
    """Base error class for other exceptions"""
    pass

class GPSFormatError(Error):
    """Raised when file is not the correct '.txt' format as from http://www.gpsvisualizer.com/draw/"""
    pass

class GPSFileFormatError(Error):
    """Raised when file does not end in '.txt' extension"""
    pass

class XYZFileFormatError(Error):
    """Raised when file does not end in '.csv' extension"""
    pass

def read_file_coarse_points_XYZ(fileName):
    """Read XYZ coordinates from '.csv' file and output as lists."""

    try:
        if not fileName.endswith(".txt"):
            raise XYZFileFormatError
    except XYZFileFormatError:
        print("Wrong file extension. Expected '.csv' format for XYZ file read")

    inputXPoints = []
    inputYPoints = []
    inputZPoints = []

    with open(fileName, "r") as file:
        for line in file:
            currentLine = line.split(",")
            
            number_of_coordinates = 3
            if len(currentLine) != number_of_coordinates:
                print("Detected line that does not have exactly {} coordinates".format(number_of_coordinates))
            else:
                inputXPoints.append(float(currentLine[0]))
                inputYPoints.append(float(currentLine[1]))
                inputZPoints.append(float(currentLine[2]))

    return inputXPoints, inputYPoints, inputZPoints

def read_file_coarse_points_LatLon(fileName, chosenHeight, oneLineOnly=False):
    """Reads GPS coordinates from text file and returns latitude and longitude values in decimal
    
    Data taken from: http://www.gpsvisualizer.com/draw/
    """
        
    try:
        if not fileName.endswith(".txt"):
            raise GPSFileFormatError
    except GPSFileFormatError:
        print("Wrong file extension. Expected '.txt' format for lat/lon conversion")

    inputLatitudes = []
    inputLongitudes = []
    inputHeights = []

    try:
        with open(fileName, "r") as file:
            firstLine = file.readline().split()
            if firstLine[0] != "type":
                raise GPSFormatError
            
            for line in file:
                if line[0] == "W":
                    currentLine = line.split()
                    inputLatitudes.append(float(currentLine[1]))
                    inputLongitudes.append(float(currentLine[2]))
                    inputHeights.append(chosenHeight)
                if oneLineOnly == True:
                    return currentLine[1], currentLine[2], chosenHeight
    except GPSFormatError:
        print("Problem with file format. Make sure to use '.txt' version of file from http://www.gpsvisualizer.com/draw/")
    
    return inputLatitudes, inputLongitudes, inputHeights
