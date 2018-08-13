#!/usr/bin/env python

"""Test Geodesy conversions back and forth, with http://vmddtech.com/ssp/latlong.html"""

from __future__ import print_function
from __future__ import division

import math
import csv

import gps_parser
from geodesy_conversion_ENU import GeodesyConverterENU
from geodesy_conversion_ECEF import GeodesyConverterECEF

def lat_lon_csv_reader(fileName):

    rawLatitude = []
    rawLongitude = []
    rawHeights = []

    with open(fileName, "r") as readFile:
        # Latitudes in first column and Longitudes in second column
        for line in readFile:
            currentLine = line.split(",")
            rawLatitude.append(float(currentLine[0]))
            rawLongitude.append(float(currentLine[1]))
            rawHeights.append(0)
    
    return rawLatitude, rawLongitude, rawHeights

def verify_gps_csv_data():
    """Convert latitude/longitude data to ENU and back from many data points
    
    Reads latitudes/longitudes from CSV file,
    converts to ECEF, converts to ENU,
    converts back to ECEF, converts back to latitudes/longitudes,
    writes new latitudes/longitudes to CSV file"""

    rawLatitude, rawLongitude, rawHeights = lat_lon_csv_reader("gps.csv")
    
    geodesyENUConv = GeodesyConverterENU(rawLatitude, rawLongitude, rawHeights)
    
    # Convert latitudes/longitudes to ENU
    eData, nData, uData = geodesyENUConv.geodetic_data_to_ENU_data()
    
    # Convert ENU back to ECEF
    xData, yData, zData =  geodesyENUConv.ENU_data_to_ECEF_data(eData, nData, uData)
    
    # Convert ECEF back to latitude/longitude
    latitudesBack, longitudesBack = geodesyENUConv.ECEF_data_to_geodetic_data(xData, yData, zData)
    
    with open("back_from_enu.csv", "wb") as enuWriteFile:
        csvWriter = csv.writer(enuWriteFile, delimiter=",")
        
        latsAndLongs = zip(latitudesBack, longitudesBack)
        csvWriter.writerows(latsAndLongs)

def verify_gps_point(latitudePoint, longitudePoint):
    """Converts input lat/long point to ENU and back"""
    rawLatitude, rawLongitude, rawHeights = lat_lon_csv_reader("gps.csv")

    pointENUConv = GeodesyConverterENU(rawLatitude, rawLongitude, rawHeights)

    ePoint, nPoint, uPoint = pointENUConv.geodetic_to_ENU_point(rawLatitude[0], rawLongitude[0], rawHeights[0])

    xPoint, yPoint, zPoint = pointENUConv.ENU_to_ECEF_point(ePoint, nPoint, uPoint)

    latitudePointBack, longitudePointBack = pointENUConv.ECEF_to_geodetic_point(xPoint, yPoint, zPoint)

    return latitudePointBack, longitudePointBack

def main():
    verify_gps_csv_data()
    latitudePointBack, longitudePointBack = verify_gps_point(
        37.3371440781, -121.879934136)

    print("latitude converted back:", latitudePointBack)
    print("longitude converted back:", longitudePointBack)


if __name__ == "__main__":
    main()
