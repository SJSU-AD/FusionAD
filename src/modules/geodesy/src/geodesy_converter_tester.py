#!/usr/bin/env python

"""Test Geodesy conversions back and forth, with http://vmddtech.com/ssp/latlong.html"""

from __future__ import print_function
from __future__ import division

import math
import csv

import gps_parser
from geodesy_conversion_ENU import GeodesyConverterENU
from geodesy_conversion_ECEF import GeodesyConverterECEF

def lat_lon_csv_reader(readFile):

    rawLatitude = []
    rawLongitude = []
    rawHeights = []

    with open(readFile, "r") as readFile:
        # Latitudes in first column and Longitudes in second column
        for line in readFile:
            currentLine = line.split(",")
            rawLatitude.append(float(currentLine[0]))
            rawLongitude.append(float(currentLine[1]))
            rawHeights.append(0)
    
    return rawLatitude, rawLongitude, rawHeights

def verify_gps_csv_data_enu(readFile, outFile):
    """Convert latitude/longitude data to ENU and back from many data points
    
    Reads latitudes/longitudes from CSV file,
    converts to ECEF, converts to ENU,
    converts back to ECEF, converts back to latitudes/longitudes,
    writes new latitudes/longitudes to CSV file"""

    rawLatitude, rawLongitude, rawHeights = lat_lon_csv_reader(readFile)
    
    geodesyENUConv = GeodesyConverterENU(rawLatitude, rawLongitude, rawHeights)
    
    # Convert latitudes/longitudes to ENU
    eData, nData, uData = geodesyENUConv.geodetic_data_to_ENU_data()
    print("===eData===\n {}, nData: {}, uData: {}\n".format(eData, nData, uData))
    
    # Convert ENU back to ECEF
    xData, yData, zData =  geodesyENUConv.ENU_data_to_ECEF_data(eData, nData, uData)
    print("===xData===\n {}, uData: {}, zData: {}\n".format(xData, yData, zData))
    
    # Convert ECEF back to latitude/longitude
    latitudesBack, longitudesBack = geodesyENUConv.ECEF_data_to_geodetic_data(xData, yData, zData)
    print("===latitudesBack===\n {}, longitudesBack: {}\n".format(
        latitudesBack, longitudesBack))
    
    with open(outFile, "wb") as enuWriteFile:
        csvWriter = csv.writer(enuWriteFile, delimiter=",")
        
        latsAndLongs = zip(latitudesBack, longitudesBack)
        csvWriter.writerows(latsAndLongs)

def verify_gps_point_enu(readFile):
    """Converts input lat/long point to ENU and back"""
    rawLatitude, rawLongitude, rawHeights = lat_lon_csv_reader(readFile)

    pointENUConv = GeodesyConverterENU(rawLatitude, rawLongitude, rawHeights)

    print("raw latitude: {}\nraw longitude: {}\n".format(rawLatitude[0], rawLongitude[0]))

    ePoint, nPoint, uPoint = pointENUConv.geodetic_to_ENU_point(rawLatitude[0], rawLongitude[0], rawHeights[0])
    print("ePoint: {:.16e}, nPoint: {:.16f}, uPoint: {:.16f}".format(ePoint, nPoint, uPoint))

    xPoint, yPoint, zPoint = pointENUConv.ENU_to_ECEF_point(ePoint, nPoint, uPoint)
    print("xPoint: {:.10f}, yPoint: {:.10f}, zPoint: {:.10f}".format(xPoint, yPoint, zPoint))

    latitudePointBack, longitudePointBack = pointENUConv.ECEF_to_geodetic_point(xPoint, yPoint, zPoint)
    print("latitudePointBack: {:.14f}, longitudePointBack: {:.14f}".format(
        latitudePointBack, longitudePointBack))

    return latitudePointBack, longitudePointBack

def main():
    print("=====Converting CSV Points=====")
    verify_gps_csv_data_enu("../geodesy_data/data_validation/gps.csv", "../geodesy_data/data_validation/back_from_enu.csv")
    print()

    print("=====Converting Single Lat/Lon Point=====")
    latitudePointBack, longitudePointBack = verify_gps_point_enu("../geodesy_data/data_validation/gps.csv")
    print()

    print("latitude converted back: {}\nlongitude converted back: {}".format(latitudePointBack, longitudePointBack))


if __name__ == "__main__":
    main()
