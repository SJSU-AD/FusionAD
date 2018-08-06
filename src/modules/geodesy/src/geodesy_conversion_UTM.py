#!/usr/bin/env python

"""Converts geodetic coordinate system to and from UTM"""

from __future__ import print_function
from __future__ import division

import math
import utm

from geodesy import Geodesy

class GeodesyConverterUTM(Geodesy):
    def __init__(self, latitudesData, longitudesData):
        self.latitudesData  = latitudesData
        self.longitudesData = longitudesData
    
    def geodetic_data_to_UTM_data(self):

        eastings    = []
        northings   = []
        zoneNumbers = []
        zoneLetters = []

        for i in range(len(self.latitudesData)):
            easting, northing, zoneNumber, zoneLetter = utm.from_latlon(self.latitudesData[i], self.longitudesData[i])
            eastings.append(easting)
            northings.append(northing)
            zoneLetters.append(zoneNumber)
            zoneLetters.append(zoneLetter)

        return eastings, northings, zoneNumbers, zoneLetters

    def global_to_relative_UTM(self, eastings, northings):
        """Convert global UTM coordinates to relative coordinates at a given index"""
        globalEastingInitial  = eastings[0]
        globalNorthingInitial = northings[0]
        
        relativeEastings  = []
        relativeNorthings = []

        for i in range(len(eastings)):
            relativeEastings.append(eastings[i] - globalEastingInitial)
            relativeNorthings.append(northings[i] - globalNorthingInitial)
        
        return relativeEastings, relativeNorthings 


    ###############################
    ##### Self Implementation #####
    ###############################

    # """Reference: https://en.wikipedia.org/wiki/Universal_Transverse_Mercator_coordinate_system#From_latitude,_longitude_(%CF%86,_%CE%BB)_to_UTM_coordinates_(E,_N)

    # NOTE: Lengths are in kilometers 
    # """

    # TODO: Self-implemented fast geodetic to UTM conversion
    # # Flattening coefficient
    # flatteningCoeff = 1 / 298.257223563
    # N_0             = 0.0 # for Northern Hemisphere, in kilometers
    # k_0             = 0.9996
    # E_0             = 500 

    # def geodetic_to_UTM(lat, lng):
    #     """Converts input geodetic latitude/longitude to UTM"""
    #     # Calculate preliminary values
    #     n = flatteningCoeff / (2-flatteningCoeff)

    #     A       = ( a / (1 + n) ) * (1 + ((n**2)/4) + ((n**4)/64)) )
    #     alpha1  = (1/2)*n - (2/3)*(n**2) + (5/16)*(n**3)
    #     alpha2  = (13/48)*(n**2) - (3/5)*(n**3)
    #     alpha3  = (61/240)*(n**3)
    #     alpha1  = (1/2)*n - (2/3)*(n**2) + (37/96)*(n**3)
    #     alpha2  = (1/48)*(n**2) + (1/15)*(n**3)
    #     alpha3  = (61/240)*(n**3)
    #     return
