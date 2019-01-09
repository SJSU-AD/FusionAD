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

def east_north_csv_reader(readFile):
    rawEData = []
    rawNData = []
    rawUData = []

    with open(readFile, "r") as readFile:
        # Eastings in first column and Northings in second column
        for line in readFile:
            currentLine = line.split(",")
            
            rawEData.append(float(currentLine[0]))
            rawNData.append(float(currentLine[1]))
            rawUData.append(0)
    
    return rawEData, rawNData, rawUData

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
    
def verify_enu_to_latlon(readFile, outFile):
    """Convert ENU coordinates from readFile to Lat/Lon to outFile
    
    Read ENU from readFile,
    converts ENU coordinates to ECEF,
    converts ECEF coordinates to lat/lon,
    writes lat/lon to CSV outFile"""
    rawEData, rawNData, rawUData = east_north_csv_reader(readFile)
    
    geodesyENUConv = GeodesyConverterENU(rawEData, rawNData, rawUData)

    # Convert latitudes/longitudes to ENU
    # eData, nData, uData = geodesyENUConv.geodetic_data_to_ENU_data()
    # print("===eData===\n {}, nData: {}, uData: {}\n".format(eData, nData, uData))
    
    # TODO: Remove hardcoded initial conditions for lat0, lon0, and h0
    # Convert ENU back to ECEF
    xData, yData, zData =  geodesyENUConv.ENU_data_to_ECEF_data(rawEData, rawNData, rawUData, 
                                lat0=37.3371389, lon0=-121.8799411, h0=-6.0)
    # print("===xData===\nxData: {}, \nyData: {}, \nzData: {}\n".format(xData, yData, zData))
    
    # Convert ECEF back to latitude/longitude
    latitudes, longitudes = geodesyENUConv.ECEF_data_to_geodetic_data(xData, yData, zData)
    # print("===latitudesBack===\nlatitudes: {}, \nlongitudes: {}\n".format(
    #     latitudes, longitudes))
    
    with open(outFile, "wb") as verificationWriteFile:
        csvWriter = csv.writer(verificationWriteFile, delimiter=",")
        
        latsAndLongs = zip(latitudes, longitudes)
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

def latlon_to_gpsVisualizer(readFile, gpsVisualizerFile, filterFrequency=None):
    """Convert lat,lon '.csv' to GPSVisualizer '.txt' format"""

    print("Converting from lat,lon '.csv' to GPSVisualizer '.txt", end="")

    print(", where filtering frequency is {}".format(filterFrequency)) if filterFrequency != None else print(", unfiltered")

    acceptPoint = 0
    rawLatLonValues = []

    with open(readFile, "r") as f:
        for line in f:
            currentCoordinate = line.split(",")
            
            if acceptPoint == 0:
                rawLatLonValues.append(currentCoordinate)
            
            if filterFrequency != None:
                acceptPoint += 1
                if acceptPoint == filterFrequency:
                    acceptPoint = 0
    
    waypointCounter = 1
    with open(gpsVisualizerFile, "wb") as f:
        for coordinate in rawLatLonValues:
            line = "W\t{}\t{}\t{}\n".format(coordinate[0], coordinate[1].strip(), str(waypointCounter))
            
            f.write(line)
            waypointCounter += 1
    
def main():
    # print("=====Converting CSV Points=====")
    # verify_gps_csv_data_enu("../geodesy_data/data_validation/gps.csv", "../geodesy_data/data_validation/back_from_enu.csv")
    # print()

    # print("=====Converting Single Lat/Lon Point=====")
    # latitudePointBack, longitudePointBack = verify_gps_point_enu("../geodesy_data/data_validation/gps.csv")
    # print()
    # print("latitude converted back: {}\nlongitude converted back: {}".format(latitudePointBack, longitudePointBack))

    print("=====Validating ENU Points=====")
    verify_enu_to_latlon("../geodesy_data/data_validation/uTurn_joy_campus_raw_e_n2.csv", \
                         "../geodesy_data/data_validation/uTurn_joy_campus_from_raw_enu_to_latlon.csv")
    latlon_to_gpsVisualizer("../geodesy_data/data_validation/uTurn_joy_campus_from_raw_enu_to_latlon.csv", \
                            "../geodesy_data/data_validation/filtered_visualizer_data.txt", \
                            filterFrequency=100)

if __name__ == "__main__":
    main()
