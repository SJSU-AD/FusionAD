#!/usr/bin/env python

"""Convert ENU Data from CSV to geodesy-runnable lat/lon data.

- Uses fixed height for "u" value
"""

from geodesy_conversion_ENU import GeodesyConverterENU

def enu_to_latlon(eData, nData, uData, radarPnt):
    """Convert ENU data to lat/lon data
    
    Also used in `validate_enu_to_latlon.py
    TODO: merge files to single converter
    """

    print("Now converting ENU data to lat/lon data")

    latData = []
    lonData = []

    enuConverter = GeodesyConverterENU(eData, nData, uData, radarPoint=radarPnt)

    xData, yData, zData = enuConverter.ENU_data_to_ECEF_data(eData, nData, uData)

    latData, lonData = enuConverter.ECEF_data_to_geodetic_data(xData, yData, zData)

    return latData, lonData

def write_latlon_data(latData, lonData, pathFile, outputFileLocation):
    """Writes lat/lon data to GPSVisualizer '.txt' file"""

    print("Now writing GPSVisualizer output at location '{}'\n".format(outputFileLocation))

    pathFile.write("type	latitude	longitude	name\n")

    waypointCounter = 1
    for latPoint, lonPoint in zip(latData, lonData):
        pathFile.write("W\t{}\t{}\t{}\n".format(latPoint, lonPoint, str(waypointCounter)))
        waypointCounter += 1

def main():
    # Extract ENU data from CSV file
    fileName = 'atm_cv2_gym_commaDelimited.csv'
    eData = []
    nData = []
    uData = []
    with open(fileName, 'r') as enuFile:
        for line in enuFile:
            currentLine = line.split(',')
            eData.append(float(currentLine[0]))
            nData.append(float(currentLine[1]))
            uData.append(0.5)

    # in lat/lon/heigh
    enuRadarPnt = (37.335292, -121.881295, -6.0)

    latData, lonData = enu_to_latlon(eData, nData, uData, enuRadarPnt)

    outputLatLonPathFile = 'atm_cv2_path.txt'
    with open(outputLatLonPathFile, "wb") as pathFile:
        write_latlon_data(latData, lonData, pathFile, outputLatLonPathFile)

if __name__ == "__main__":
    main()


