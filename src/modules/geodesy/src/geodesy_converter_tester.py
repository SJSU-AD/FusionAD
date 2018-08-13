#!/usr/bin/env python

"""Test Geodesy conversions back and forth, with http://vmddtech.com/ssp/latlong.html

Reads latitudes/longitudes from CSV file,
converts to ECEF, converts to ENU,
converts back to ECEF, converts back to latitudes/longitudes
writes new latitudes/longitudes to CSV file
"""

from __future__ import print_function
from __future__ import division

import math
import csv

import gps_parser
from geodesy_conversion_ENU import GeodesyConverterENU
from geodesy_conversion_ECEF import GeodesyConverterECEF

def main():
    
    """Test Geodetic to ENU conversion"""
    rawLatitude  = []
    rawLongitude = []
    rawHeights   = []

    with open("gps.csv", "r") as readFile:
        # Latitudes in first column and Longitudes in second column
        for line in readFile:
            currentLine = line.split(",")
            rawLatitude.append(float(currentLine[0]))
            rawLongitude.append(float(currentLine[1]))
            rawHeights.append(0)
    
    geodesyENUConv   = GeodesyConverterENU(rawLatitude, rawLongitude, rawHeights)
    
    # Convert latitudes/longitudes to ENU
    eData, nData, uData = geodesyENUConv.geodetic_data_to_ENU_data()
    # print(eData)
    
    # Convert ENU back to ECEF
    xData, yData, zData =  geodesyENUConv.ENU_data_to_ECEF_data(eData, nData, uData)
    # print(xData)
    
    # Convert ECEF back to latitude/longitude
    latitudesBack, longitudesBack = geodesyENUConv.ECEF_data_to_geodetic_data(xData, yData, zData)

    # print(latitudesBack)
    
    with open("back_from_enu.csv", "wb") as enuWriteFile:
        csvWriter = csv.writer(enuWriteFile, delimiter=",")
        
        latsAndLongs = zip(latitudesBack, longitudesBack)
        csvWriter.writerows(latsAndLongs)

if __name__ == "__main__":
    main()