#!/usr/bin/env python

"""Takes GPS values and converts and publishes X/Y ENU coordinates"""

from __future__ import print_function
from __future__ import division

import math

import rospy
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import Point, Pose, PoseStamped
from std_msgs.msg import Header
from nav_msgs.msg import Odometry

import gps_parser
from geodesy_conversion_ENU import GeodesyConverterENU

class GPSDataConverter(object):
    """Reads GPS data and converts and publishes it in ENU coordinates

    Subscribes
    ----------
    Topic: /piksi/navsatfix_best_fix
        Msg: sensor_msgs/NavSatFix

    Publishes
    ---------
        Topic: /gps/geodesy_odom
        Msg: nav_msgs/Odometry.msg
    """
    
    def __init__(self, useCustomRadarPnt=True):
        self.odomPublisher = rospy.Publisher("/gps/geodesy_odom", Odometry, queue_size=1000)
        rospy.loginfo("Instantiated gps_pose publishers")
        # self.rate = rospy.Rate(1)

        self.latitude  = 0.0
        self.longitude = 0.0
        self.altitude  = 0.0
        self.gpsCovar = []

        # For velocity caluclation
        self.foundFirstCoord = False
        self.prevE           = 0.0
        self.prevN           = 0.0
        self.prevU           = 0.0
        self.prevTime        = 0.0

        filePath = rospy.get_param("~file_path")
        
        radarLat = rospy.get_param("~radar_lat")
        radarLon = rospy.get_param("~radar_lon")
        height = rospy.get_param("~fixed_height")
        # height = -6.0

        self.lat0, self.lon0, self.h0 = map(float, gps_parser.read_file_coarse_points(filePath, height, oneLineOnly=True))
        self.toENUConverter = GeodesyConverterENU(self.lat0, self.lon0, self.h0)
        rospy.loginfo("Found and initialized intial lat/lon/altitude values")
        rospy.loginfo("Initial latitude: %f", self.toENUConverter.latitudesData)
        rospy.loginfo("Initial latitude: %f", self.toENUConverter.longitudesData)
        rospy.loginfo("Initial latitude: %f", self.toENUConverter.heightsData)

    def GPS_to_ENU_callback(self, gpsMsg):
        """Callback for subscribing to GPS data"""
        self.latitude  = gpsMsg.latitude
        self.longitude = gpsMsg.longitude
        self.altitude  = gpsMsg.altitude
        self.gpsCovar = gpsMsg.position_covariance

        rospy.logdebug("Received latitude: %f, longitude: %f, altitude: %f", self.latitude, self.longitude, self.altitude)
        rospy.logdebug("Received GPS Covariance: [%s]", ", ".join([str(covar) for covar in self.gpsCovar]))

        e, n, u = self.toENUConverter.geodetic_to_ENU_point(self.latitude, self.longitude, self.altitude, lat0=self.lat0, lon0=self.lon0, h0=self.h0)
        rospy.logdebug("Converted values: east = %f, north = %f, up = %f", e, n, u)

        ############################
        ##### Message Creation #####
        ############################

        h = Header()
        h.stamp     = rospy.Time.now()
        currentTime = rospy.get_time()

        # Set velocity in publish message
        if not self.foundFirstCoord:
            self.prevE = e
            self.prevN = n
            self.prevU = u
            self.prevTime = float("nan")
            self.foundFirstCoord = True

        rospy.logdebug("Current time: %f, Previous time: %f", currentTime, self.prevTime)
        
        timeDelta = currentTime - self.prevTime
        self.prevTime = currentTime

        rospy.logdebug("Current E = %f, previous E = %f", e, self.prevE)
        rospy.logdebug("Current N = %f, previous N = %f", n, self.prevN)
        rospy.logdebug("Current U = %f, previous U = %f", u, self.prevU)
        rospy.logdebug("Time delta = %f", timeDelta)

        xVelocity = (e - self.prevE) / timeDelta
        yVelocity = (n - self.prevN) / timeDelta
        zVelocity = (u - self.prevU) / timeDelta

        self.prevE = e
        self.prevN = n
        self.prevU = u

        ###################################
        ##### Create Odometry Message #####
        ###################################
        currentOdomState = self.create_odom_msg(h.stamp, e, n, u, xVelocity, yVelocity, zVelocity, gpsMsg.position_covariance)
        
        self.odomPublisher.publish(currentOdomState)

        rospy.loginfo("Published Odom message")

        # TODO: Overwrite latitudesData[0], longitudesData[0], heightsData[0] with actual initial position?
        
    def create_odom_msg(self, headerStamp, x, y, z, xVel, yVel, zVel, gpsCovarMsg):
        """Create Odometry message"""
        currentOdomState = Odometry()

        currentOdomState.header.stamp = headerStamp

        currentOdomState.header.frame_id = "odom"

        # Set position in publish message
        currentOdomState.pose.pose.position.x = x
        currentOdomState.pose.pose.position.y = y
        currentOdomState.pose.pose.position.z = z

        currentOdomState.twist.twist.linear.x = xVel
        currentOdomState.twist.twist.linear.y = yVel
        currentOdomState.twist.twist.linear.z = zVel

        currentOdomState.pose.covariance[0] = gpsCovarMsg[0]
        currentOdomState.pose.covariance[7] = gpsCovarMsg[4]

        return currentOdomState

    def GPS_data_converter(self):
        """Take GPS data, convert to ENU, and republish"""
        rospy.Subscriber("/piksi/navsatfix_best_fix", NavSatFix, self.GPS_to_ENU_callback, queue_size=1000)

        rospy.spin()

def main():
    rospy.init_node("gps_pose_converter_node", anonymous=False, log_level=rospy.INFO)
    
    convertGPSData = GPSDataConverter()

    try:
        convertGPSData.GPS_data_converter()
    except rospy.ROSInterruptException:
        pass

if __name__ == "__main__":
    main()