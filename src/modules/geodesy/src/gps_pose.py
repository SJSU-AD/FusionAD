#!/usr/bin/env python

"""Takes GPS values and converts and publishes X/Y ENU coordinates

NOTE: Uses interface/chassis_state.msg
"""

from __future__ import print_function
from __future__ import division

import math

import rospy
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import Point, Pose, PoseStamped
from std_msgs.msg import Header

import gps_parser
from interface.msg import Chassis_state
from geodesy_conversion_ENU import GeodesyConverterENU

class GPSDataConverter(object):
    """Reads GPS data and converts and publishes it in ENU coordinates

    Subscribes
    ----------
    Topic: /gps/fix
        Msg: sensor_msgs/NavSatFix

    Publishes
    ---------
    Topic: /localization/state
        Msg: Chassis_state.msg
    """
    
    def __init__(self):
        self.statePublisher = rospy.Publisher("/localization/state", Chassis_state, queue_size=1000)
        rospy.loginfo("Instantiated publisher")
        # self.rate = rospy.Rate(1)
        self.seq = 0

        self.latitude  = 0.0
        self.longitude = 0.0
        self.altitude  = 0.0

        # For velocity caluclation
        self.foundFirstCoord = False
        self.prevE           = 0.0
        self.prevN           = 0.0
        self.prevU           = 0.0
        self.prevTime        = 0.0

        filePath = rospy.get_param("~file_path")
        self.lat0, self.lon0, self.h0 = map(float, gps_parser.read_file_coarse_points(filePath, -6.0, oneLineOnly=True))
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
        rospy.logdebug("Received latitude: %f, longitude: %f, altitude: %f", self.latitude, self.longitude, self.altitude)

        e, n, u = self.toENUConverter.geodetic_to_ENU_point(self.latitude, self.longitude, self.altitude, lat0=self.lat0, lon0=self.lon0, h0=self.h0)
        rospy.logdebug("Converted values: east = %f, north = %f, up = %f", e, n, u)

        currentChassisState = Chassis_state()

        h = Header()
        h.stamp     = rospy.Time.now()
        currentTime = rospy.get_time()

        currentChassisState.header.seq = self.seq
        currentChassisState.header.stamp = h.stamp

        # Set position in publish message
        currentChassisState.Position.pose.position.x = e
        currentChassisState.Position.pose.position.y = n
        currentChassisState.Position.pose.position.z = u

        # Set velocity in publish message
        if not self.foundFirstCoord:
            self.prevE = e
            self.prevN = n
            self.prevU = u
            self.prevTime = float("nan")
            self.foundFirstCoord = True
        
        timeDelta = currentTime - self.prevTime

        rospy.logdebug("Current E = %f, previous E = %f", e, self.prevE)
        rospy.logdebug("Current N = %f, previous N = %f", n, self.prevN)
        rospy.logdebug("Current U = %f, previous U = %f", u, self.prevU)
        rospy.logdebug("Time delta = %f", timeDelta)

        currentChassisState.Speed.twist.linear.x = (e - self.prevE) / timeDelta
        currentChassisState.Speed.twist.linear.y = (n - self.prevN) / timeDelta
        currentChassisState.Speed.twist.linear.z = (u - self.prevU) / timeDelta

        self.prevE = e
        self.prevN = n
        self.prevU = u
        self.prevTime = currentTime

        self.statePublisher.publish(currentChassisState)

        rospy.loginfo("Published Chassis state message")
        self.seq += 1

        # TODO: Overwrite latitudesData[0], longitudesData[0], heightsData[0] with actual initial position?
    
    def GPS_data_converter(self):
        """Take GPS data, convert to ENU, and republish"""
        rospy.Subscriber("/gps/fix", NavSatFix, self.GPS_to_ENU_callback, queue_size=1000)

        rospy.spin()

def main():
    rospy.init_node("gps_pose_converter_node", anonymous=False)
    
    convertGPSData = GPSDataConverter()

    try:
        convertGPSData.GPS_data_converter()
    except rospy.ROSInterruptException:
        pass

if __name__ == "__main__":
    main()