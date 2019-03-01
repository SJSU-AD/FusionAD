#!/usr/bin/env python

"""Interpolates path from previously plotted points"""

import rospy

import gps_parser
from path_interpolator_ECEF import PathInterpolatorECEF
from path_interpolator_UTM  import PathInterpolatorUTM
from path_interpolator_ENU  import PathInterpolatorENU

def main():
    rospy.init_node('interpolation_node', anonymous = True)

    # radar points for ENU conversion
    radarLat = rospy.get_param("~radar_lat")
    radarLon = rospy.get_param("~radar_lon")
    chosenHeight = rospy.get_param("~fixed_height")

    radarPnt = None
    if radarLat != "None" and radarLon != "None":
        radarPnt = (radarLat, radarLon, chosenHeight)

    # From https://www.maps.ie/coordinates.html at SJSU
    filePath = rospy.get_param("~file_path")
    conversionType = rospy.get_param("~conversion_type")
    
    if filePath[-3:] not in ["txt", "csv"]:
        raise ValueError("Expected '.txt' or '.csv' file for input path")

    if conversionType not in ["ECEF", "ENU", "UTM"]:
        raise NameError("'{}' is not a valid conversion. Please provide valid conversion in launch file\n".format(conversionType))
    
    # Placeholder for converters
    inputLatitudes = [0]
    inputLongitudes = [0]
    inputHeights = [0]
    inputXPoints = [0]
    inputYPoints = [0]
    inputZPoints = [0]
    inputPath = None

    if filePath.endswith("txt"):
        inputLatitudes, inputLongitudes, inputHeights = gps_parser.read_file_coarse_points_LatLon(filePath, chosenHeight)

    if filePath.endswith("csv"):
        inputXPoints, inputYPoints, inputZPoints = gps_parser.read_file_coarse_points_XYZ(filePath)
        inputPath = (inputXPoints, inputYPoints, inputZPoints)

    if conversionType == "ECEF":
        interpolatorECEF = PathInterpolatorECEF(inputLatitudes, inputLatitudes, inputHeights)

        try:
            rospy.loginfo("ECEF Conversion publishing...")
            interpolatorECEF.interpolation_publish_ECEF()
        except rospy.ROSInterruptException:
            pass
    elif conversionType == "ENU":
        interpolatorENU = PathInterpolatorENU(inputLatitudes, inputLongitudes, inputHeights, centimetersPerPoint=10, radarPoint=radarPnt, ENUInputPath=inputPath)
        
        try:
            rospy.loginfo("ENU Conversion publishing...")
            interpolatorENU.interpolation_publish_ENU()
        except rospy.ROSInterruptException:
            pass
    elif conversionType == "UTM":
        rospy.loginfo("UTM instantiation...")
        interpolatorUTM = PathInterpolatorUTM(inputLatitudes, inputLongitudes)
        
        try:
            rospy.loginfo("UTM Conversion publishing...")
            interpolatorUTM.interpolation_publish_UTM()
        except rospy.ROSInterruptException:
            pass

if __name__ == '__main__':
    main()

