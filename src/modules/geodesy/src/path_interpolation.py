#!/usr/bin/env python

"""Interpolates path from previously plotted points"""

import rospy

import gps_parser
from path_interpolator_ECEF import PathInterpolatorECEF
from path_interpolator_UTM  import PathInterpolatorUTM
from path_interpolator_ENU  import PathInterpolatorENU

def main():
    rospy.init_node('interpolation_node', anonymous = True)

    chosenHeight = -6.0

    # From https://www.maps.ie/coordinates.html at SJSU
    filePath = rospy.get_param("~file_path")
    inputLatitudes, inputLongitudes, inputHeights = gps_parser.read_file_coarse_points(filePath, chosenHeight)
    
    ##### ECEF #####
    # interpolatorECEF = PathInterpolatorECEF(inputLatitudes, inputLatitudes, inputHeights, chosenHeight)

    ##### ENU #####
    interpolatorENU = PathInterpolatorENU(inputLatitudes, inputLongitudes, inputHeights)

    ##### UTM #####
    # interpolatorUTM = PathInterpolatorUTM(inputLatitudes, inputLongitudes)
    
    try:
        # interpolatorECEF.interpolation_publish_ECEF()
        interpolatorENU.interpolation_publish_ENU()
        # interpolatorUTM.interpolation_publish_UTM()
    except rospy.ROSInterruptException:
        pass

if __name__ == '__main__':
    main()

