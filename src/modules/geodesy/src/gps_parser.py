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

def read_file_coarse_points(fileName, chosenHeight, oneLineOnly=False):
    """Reads GPS coordinates from text file and returns latitude and longitude values in decimal
    
    Data taken from: http://www.gpsvisualizer.com/draw/
    """
        
    try:
        if not fileName.endswith(".txt"):
            raise GPSFileFormatError
    except GPSFileFormatError:
        print("Wrong file extension. Expected '.txt' format")

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

def main():
    pass
