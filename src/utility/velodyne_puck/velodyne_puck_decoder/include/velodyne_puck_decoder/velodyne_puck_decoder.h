/*
 * This file is part of velodyne_puck driver.
 *
 * The driver is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The driver is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the driver.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef VELODYNE_PUCK_DECODER_H
#define VELODYNE_PUCK_DECODER_H

#define DEG_TO_RAD 0.017453292
#define RAD_TO_DEG 57.29577951

#include <cmath>
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>

#include <velodyne_puck_msgs/VelodynePuckPacket.h>
#include <velodyne_puck_msgs/VelodynePuckPoint.h>
#include <velodyne_puck_msgs/VelodynePuckScan.h>
#include <velodyne_puck_msgs/VelodynePuckSweep.h>


namespace velodyne_puck_decoder {

// Raw Velodyne packet constants and structures.
static const int SIZE_BLOCK      = 100;
static const int RAW_SCAN_SIZE   = 3;
static const int SCANS_PER_BLOCK = 32;
static const int BLOCK_DATA_SIZE =
  (SCANS_PER_BLOCK * RAW_SCAN_SIZE);

// According to Bruce Hall DISTANCE_MAX is 65.0, but we noticed
// valid packets with readings up to 130.0.
static const double DISTANCE_MAX        = 130.0;        /**< meters */
static const double DISTANCE_RESOLUTION = 0.002; /**< meters */
static const double DISTANCE_MAX_UNITS  =
  (DISTANCE_MAX / DISTANCE_RESOLUTION + 1.0);

/** @todo make this work for both big and little-endian machines */
static const uint16_t UPPER_BANK = 0xeeff;
static const uint16_t LOWER_BANK = 0xddff;

/** Special Defines for VLP16 support **/
static const int     FIRINGS_PER_BLOCK = 2;
static const int     SCANS_PER_FIRING  = 16;
static const double  BLOCK_TDURATION   = 110.592; // [µs]
static const double  DSR_TOFFSET       = 2.304;   // [µs]
static const double  FIRING_TOFFSET    = 55.296;  // [µs]

static const int PACKET_SIZE        = 1206;
static const int BLOCKS_PER_PACKET  = 12;
static const int PACKET_STATUS_SIZE = 4;
static const int SCANS_PER_PACKET =
  (SCANS_PER_BLOCK * BLOCKS_PER_PACKET);
static const int FIRINGS_PER_PACKET =
  FIRINGS_PER_BLOCK * BLOCKS_PER_PACKET;

// Pre-compute the sine and cosine for the altitude angles.
static const double scan_altitude[16] = {
  -0.2617993877991494,   0.017453292519943295,
  -0.22689280275926285,  0.05235987755982989,
  -0.19198621771937624,  0.08726646259971647,
  -0.15707963267948966,  0.12217304763960307,
  -0.12217304763960307,  0.15707963267948966,
  -0.08726646259971647,  0.19198621771937624,
  -0.05235987755982989,  0.22689280275926285,
  -0.017453292519943295, 0.2617993877991494
};

static const double cos_scan_altitude[16] = {
  std::cos(scan_altitude[ 0]), std::cos(scan_altitude[ 1]),
  std::cos(scan_altitude[ 2]), std::cos(scan_altitude[ 3]),
  std::cos(scan_altitude[ 4]), std::cos(scan_altitude[ 5]),
  std::cos(scan_altitude[ 6]), std::cos(scan_altitude[ 7]),
  std::cos(scan_altitude[ 8]), std::cos(scan_altitude[ 9]),
  std::cos(scan_altitude[10]), std::cos(scan_altitude[11]),
  std::cos(scan_altitude[12]), std::cos(scan_altitude[13]),
  std::cos(scan_altitude[14]), std::cos(scan_altitude[15]),
};

static const double sin_scan_altitude[16] = {
  std::sin(scan_altitude[ 0]), std::sin(scan_altitude[ 1]),
  std::sin(scan_altitude[ 2]), std::sin(scan_altitude[ 3]),
  std::sin(scan_altitude[ 4]), std::sin(scan_altitude[ 5]),
  std::sin(scan_altitude[ 6]), std::sin(scan_altitude[ 7]),
  std::sin(scan_altitude[ 8]), std::sin(scan_altitude[ 9]),
  std::sin(scan_altitude[10]), std::sin(scan_altitude[11]),
  std::sin(scan_altitude[12]), std::sin(scan_altitude[13]),
  std::sin(scan_altitude[14]), std::sin(scan_altitude[15]),
};

class VelodynePuckDecoder {
public:

  VelodynePuckDecoder(ros::NodeHandle& n, ros::NodeHandle& pn);
  VelodynePuckDecoder(const VelodynePuckDecoder&) = delete;
  VelodynePuckDecoder operator=(const VelodynePuckDecoder&) = delete;
  ~VelodynePuckDecoder() {return;}

  bool initialize();

  typedef boost::shared_ptr<VelodynePuckDecoder> VelodynePuckDecoderPtr;
  typedef boost::shared_ptr<const VelodynePuckDecoder> VelodynePuckDecoderConstPtr;

private:

  union TwoBytes {
    uint16_t distance;
    uint8_t  bytes[2];
  };

  struct RawBlock {
    uint16_t header;        ///< UPPER_BANK or LOWER_BANK
    uint16_t rotation;      ///< 0-35999, divide by 100 to get degrees
    uint8_t  data[BLOCK_DATA_SIZE];
  };

  struct RawPacket {
    RawBlock blocks[BLOCKS_PER_PACKET];
    uint32_t time_stamp;
    uint8_t factory[2];
    //uint16_t revolution;
    //uint8_t status[PACKET_STATUS_SIZE];
  };

  struct Firing {
    // Azimuth associated with the first shot within this firing.
    double firing_azimuth;
    double azimuth[SCANS_PER_FIRING];
    double distance[SCANS_PER_FIRING];
    double intensity[SCANS_PER_FIRING];
  };

  // Intialization sequence
  bool loadParameters();
  bool createRosIO();


  // Callback function for a single velodyne packet.
  bool checkPacketValidity(const RawPacket* packet);
  void decodePacket(const RawPacket* packet);
  void packetCallback(const velodyne_puck_msgs::VelodynePuckPacketConstPtr& msg);

  // Publish data
  void publishPointCloud();

  // Check if a point is in the required range.
  bool isPointInRange(const double& distance) {
    return (distance >= min_range && distance <= max_range);
  }

  double rawAzimuthToDouble(const uint16_t& raw_azimuth) {
    // According to the user manual,
    // azimuth = raw_azimuth / 100.0;
    return static_cast<double>(raw_azimuth) / 100.0 * DEG_TO_RAD;
  }

  // Configuration parameters
  double min_range;
  double max_range;
  double frequency;
  bool publish_point_cloud;

  double cos_azimuth_table[6300];
  double sin_azimuth_table[6300];

  bool is_first_sweep;
  double last_azimuth;
  double sweep_start_time;
  double packet_start_time;
  Firing firings[FIRINGS_PER_PACKET];

  // ROS related parameters
  ros::NodeHandle nh;
  ros::NodeHandle pnh;

  std::string fixed_frame_id;
  std::string child_frame_id;

  velodyne_puck_msgs::VelodynePuckSweepPtr sweep_data;
  sensor_msgs::PointCloud2 point_cloud_data;

  ros::Subscriber packet_sub;
  ros::Publisher sweep_pub;
  ros::Publisher point_cloud_pub;

};

typedef VelodynePuckDecoder::VelodynePuckDecoderPtr VelodynePuckDecoderPtr;
typedef VelodynePuckDecoder::VelodynePuckDecoderConstPtr VelodynePuckDecoderConstPtr;

} // end namespace velodyne_puck_decoder

#endif
