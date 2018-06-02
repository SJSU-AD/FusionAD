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

#include <velodyne_puck_decoder/velodyne_puck_decoder.h>

using namespace std;

namespace velodyne_puck_decoder {
VelodynePuckDecoder::VelodynePuckDecoder(
    ros::NodeHandle& n, ros::NodeHandle& pn):
  nh(n),
  pnh(pn),
  publish_point_cloud(true),
  is_first_sweep(true),
  last_azimuth(0.0),
  sweep_start_time(0.0),
  packet_start_time(0.0),
  sweep_data(new velodyne_puck_msgs::VelodynePuckSweep()){
  return;
}

bool VelodynePuckDecoder::loadParameters() {
  pnh.param<double>("min_range", min_range, 0.5);
  pnh.param<double>("max_range", max_range, 100.0);
  pnh.param<double>("frequency", frequency, 20.0);
  pnh.param<bool>("publish_point_cloud", publish_point_cloud, true);

  pnh.param<string>("fixed_frame_id", fixed_frame_id, "map");
  pnh.param<string>("child_frame_id", child_frame_id, "velodyne");
  return true;
}

bool VelodynePuckDecoder::createRosIO() {
  packet_sub = nh.subscribe<velodyne_puck_msgs::VelodynePuckPacket>(
      "velodyne_packet", 100, &VelodynePuckDecoder::packetCallback, this);
  sweep_pub = nh.advertise<velodyne_puck_msgs::VelodynePuckSweep>(
      "velodyne_sweep", 10);
  point_cloud_pub = nh.advertise<sensor_msgs::PointCloud2>(
      "velodyne_point_cloud", 10);
  return true;
}

bool VelodynePuckDecoder::initialize() {
  if (!loadParameters()) {
    ROS_ERROR("Cannot load all required parameters...");
    return false;
  }

  if (!createRosIO()) {
    ROS_ERROR("Cannot create ROS I/O...");
    return false;
  }

  // Fill in the altitude for each scan.
  for (size_t scan_idx = 0; scan_idx < 16; ++scan_idx) {
    size_t remapped_scan_idx = scan_idx%2 == 0 ? scan_idx/2 : scan_idx/2+8;
    sweep_data->scans[remapped_scan_idx].altitude = scan_altitude[scan_idx];
  }

  // Create the sin and cos table for different azimuth values.
  for (size_t i = 0; i < 6300; ++i) {
    double angle = static_cast<double>(i) / 1000.0;
    cos_azimuth_table[i] = cos(angle);
    sin_azimuth_table[i] = sin(angle);
  }

  return true;
}

bool VelodynePuckDecoder::checkPacketValidity(const RawPacket* packet) {
  for (size_t blk_idx = 0; blk_idx < BLOCKS_PER_PACKET; ++blk_idx) {
    if (packet->blocks[blk_idx].header != UPPER_BANK) {
      ROS_WARN("Skip invalid VLP-16 packet: block %lu header is %x",
          blk_idx, packet->blocks[blk_idx].header);
      return false;
    }
  }
  return true;
}

void VelodynePuckDecoder::publishPointCloud() {
  pcl::PointCloud<pcl::PointXYZI>::Ptr point_cloud(
      new pcl::PointCloud<pcl::PointXYZI>());
  point_cloud->header.stamp =
    pcl_conversions::toPCL(sweep_data->header).stamp;
  point_cloud->header.frame_id = child_frame_id;
  point_cloud->height = 1;

  for (size_t i = 0; i < 16; ++i) {
    const velodyne_puck_msgs::VelodynePuckScan& scan = sweep_data->scans[i];
    // The first and last point in each scan is ignored, which
    // seems to be corrupted based on the received data.
    // TODO: The two end points should be removed directly
    //    in the scans.
    if (scan.points.size() == 0) continue;
    for (size_t j = 1; j < scan.points.size()-1; ++j) {
      pcl::PointXYZI point;
      point.x = scan.points[j].x;
      point.y = scan.points[j].y;
      point.z = scan.points[j].z;
      point.intensity = scan.points[j].intensity;
      point_cloud->points.push_back(point);
      ++point_cloud->width;
    }
  }

  point_cloud_pub.publish(point_cloud);
  //sweep_pub.publish(sweep_data);

  return;
}

void VelodynePuckDecoder::decodePacket(const RawPacket* packet) {

  // Compute the azimuth angle for each firing.
  for (size_t fir_idx = 0; fir_idx < FIRINGS_PER_PACKET; fir_idx+=2) {
    size_t blk_idx = fir_idx / 2;
    firings[fir_idx].firing_azimuth = rawAzimuthToDouble(
        packet->blocks[blk_idx].rotation);
  }

  // Interpolate the azimuth values
  for (size_t fir_idx = 1; fir_idx < FIRINGS_PER_PACKET; fir_idx+=2) {
    size_t lfir_idx = fir_idx - 1;
    size_t rfir_idx = fir_idx + 1;

    if (fir_idx == FIRINGS_PER_PACKET - 1) {
      lfir_idx = fir_idx - 3;
      rfir_idx = fir_idx - 1;
    }

    double azimuth_diff = firings[rfir_idx].firing_azimuth -
      firings[lfir_idx].firing_azimuth;
    azimuth_diff = azimuth_diff < 0 ? azimuth_diff + 2*M_PI : azimuth_diff;

    firings[fir_idx].firing_azimuth =
      firings[fir_idx-1].firing_azimuth + azimuth_diff/2.0;
    firings[fir_idx].firing_azimuth  =
      firings[fir_idx].firing_azimuth > 2*M_PI ?
      firings[fir_idx].firing_azimuth-2*M_PI : firings[fir_idx].firing_azimuth;
  }

  // Fill in the distance and intensity for each firing.
  for (size_t blk_idx = 0; blk_idx < BLOCKS_PER_PACKET; ++blk_idx) {
    const RawBlock& raw_block = packet->blocks[blk_idx];

    for (size_t blk_fir_idx = 0; blk_fir_idx < FIRINGS_PER_BLOCK; ++blk_fir_idx){
      size_t fir_idx = blk_idx*FIRINGS_PER_BLOCK + blk_fir_idx;

      double azimuth_diff = 0.0;
      if (fir_idx < FIRINGS_PER_PACKET - 1)
        azimuth_diff = firings[fir_idx+1].firing_azimuth -
          firings[fir_idx].firing_azimuth;
      else
        azimuth_diff = firings[fir_idx].firing_azimuth -
          firings[fir_idx-1].firing_azimuth;

      for (size_t scan_fir_idx = 0; scan_fir_idx < SCANS_PER_FIRING; ++scan_fir_idx){
        size_t byte_idx = RAW_SCAN_SIZE * (
            SCANS_PER_FIRING*blk_fir_idx + scan_fir_idx);

        // Azimuth
        firings[fir_idx].azimuth[scan_fir_idx] = firings[fir_idx].firing_azimuth +
          (scan_fir_idx*DSR_TOFFSET/FIRING_TOFFSET) * azimuth_diff;

        // Distance
        TwoBytes raw_distance;
        raw_distance.bytes[0] = raw_block.data[byte_idx];
        raw_distance.bytes[1] = raw_block.data[byte_idx+1];
        firings[fir_idx].distance[scan_fir_idx] = static_cast<double>(
            raw_distance.distance) * DISTANCE_RESOLUTION;

        // Intensity
        firings[fir_idx].intensity[scan_fir_idx] = static_cast<double>(
            raw_block.data[byte_idx+2]);
      }
    }
  }
  return;
}

void VelodynePuckDecoder::packetCallback(
    const velodyne_puck_msgs::VelodynePuckPacketConstPtr& msg) {

  // Convert the msg to the raw packet type.
  const RawPacket* raw_packet = (const RawPacket*) (&(msg->data[0]));

  // Check if the packet is valid
  if (!checkPacketValidity(raw_packet)) return;

  // Decode the packet
  decodePacket(raw_packet);

  // Find the start of a new revolution
  //    If there is one, new_sweep_start will be the index of the start firing,
  //    otherwise, new_sweep_start will be FIRINGS_PER_PACKET.
  size_t new_sweep_start = 0;
  do {
    if (firings[new_sweep_start].firing_azimuth < last_azimuth) break;
    else {
      last_azimuth = firings[new_sweep_start].firing_azimuth;
      ++new_sweep_start;
    }
  } while (new_sweep_start < FIRINGS_PER_PACKET);

  // The first sweep may not be complete. So, the firings with
  // the first sweep will be discarded. We will wait for the
  // second sweep in order to find the 0 azimuth angle.
  size_t start_fir_idx = 0;
  size_t end_fir_idx = new_sweep_start;
  if (is_first_sweep &&
      new_sweep_start == FIRINGS_PER_PACKET) {
    // The first sweep has not ended yet.
    return;
  } else {
    if (is_first_sweep) {
      is_first_sweep = false;
      start_fir_idx = new_sweep_start;
      end_fir_idx = FIRINGS_PER_PACKET;
      sweep_start_time = msg->stamp.toSec() +
        FIRING_TOFFSET * (end_fir_idx-start_fir_idx) * 1e-6;
    }
  }

  for (size_t fir_idx = start_fir_idx; fir_idx < end_fir_idx; ++fir_idx) {
    for (size_t scan_idx = 0; scan_idx < SCANS_PER_FIRING; ++scan_idx) {
      // Check if the point is valid.
      if (!isPointInRange(firings[fir_idx].distance[scan_idx])) continue;

      // Convert the point to xyz coordinate
      size_t table_idx = floor(firings[fir_idx].azimuth[scan_idx]*1000.0+0.5);
      //cout << table_idx << endl;
      double cos_azimuth = cos_azimuth_table[table_idx];
      double sin_azimuth = sin_azimuth_table[table_idx];

      //double x = firings[fir_idx].distance[scan_idx] *
      //  cos_scan_altitude[scan_idx] * sin(firings[fir_idx].azimuth[scan_idx]);
      //double y = firings[fir_idx].distance[scan_idx] *
      //  cos_scan_altitude[scan_idx] * cos(firings[fir_idx].azimuth[scan_idx]);
      //double z = firings[fir_idx].distance[scan_idx] *
      //  sin_scan_altitude[scan_idx];

      double x = firings[fir_idx].distance[scan_idx] *
        cos_scan_altitude[scan_idx] * sin_azimuth;
      double y = firings[fir_idx].distance[scan_idx] *
        cos_scan_altitude[scan_idx] * cos_azimuth;
      double z = firings[fir_idx].distance[scan_idx] *
        sin_scan_altitude[scan_idx];

      double x_coord = y;
      double y_coord = -x;
      double z_coord = z;

      // Compute the time of the point
      double time = packet_start_time +
        FIRING_TOFFSET*fir_idx + DSR_TOFFSET*scan_idx;

      // Remap the index of the scan
      int remapped_scan_idx = scan_idx%2 == 0 ? scan_idx/2 : scan_idx/2+8;
      sweep_data->scans[remapped_scan_idx].points.push_back(
          velodyne_puck_msgs::VelodynePuckPoint());
      velodyne_puck_msgs::VelodynePuckPoint& new_point =
        sweep_data->scans[remapped_scan_idx].points[
        sweep_data->scans[remapped_scan_idx].points.size()-1];

      // Pack the data into point msg
      new_point.time = time;
      new_point.x = x_coord;
      new_point.y = y_coord;
      new_point.z = z_coord;
      new_point.azimuth = firings[fir_idx].azimuth[scan_idx];
      new_point.distance = firings[fir_idx].distance[scan_idx];
      new_point.intensity = firings[fir_idx].intensity[scan_idx];
    }
  }

  packet_start_time += FIRING_TOFFSET * (end_fir_idx-start_fir_idx);

  // A new sweep begins
  if (end_fir_idx != FIRINGS_PER_PACKET) {
    // Publish the last revolution
    sweep_data->header.stamp = ros::Time(sweep_start_time);
    sweep_pub.publish(sweep_data);
    if (publish_point_cloud) publishPointCloud();
    sweep_data = velodyne_puck_msgs::VelodynePuckSweepPtr(
        new velodyne_puck_msgs::VelodynePuckSweep());

    // Prepare the next revolution
    sweep_start_time = msg->stamp.toSec() +
      FIRING_TOFFSET * (end_fir_idx-start_fir_idx) * 1e-6;
    packet_start_time = 0.0;
    last_azimuth = firings[FIRINGS_PER_PACKET-1].firing_azimuth;

    start_fir_idx = end_fir_idx;
    end_fir_idx = FIRINGS_PER_PACKET;

    for (size_t fir_idx = start_fir_idx; fir_idx < end_fir_idx; ++fir_idx) {
      for (size_t scan_idx = 0; scan_idx < SCANS_PER_FIRING; ++scan_idx) {
        // Check if the point is valid.
        if (!isPointInRange(firings[fir_idx].distance[scan_idx])) continue;

        // Convert the point to xyz coordinate
        size_t table_idx = floor(firings[fir_idx].azimuth[scan_idx]*1000.0+0.5);
        //cout << table_idx << endl;
        double cos_azimuth = cos_azimuth_table[table_idx];
        double sin_azimuth = sin_azimuth_table[table_idx];

        //double x = firings[fir_idx].distance[scan_idx] *
        //  cos_scan_altitude[scan_idx] * sin(firings[fir_idx].azimuth[scan_idx]);
        //double y = firings[fir_idx].distance[scan_idx] *
        //  cos_scan_altitude[scan_idx] * cos(firings[fir_idx].azimuth[scan_idx]);
        //double z = firings[fir_idx].distance[scan_idx] *
        //  sin_scan_altitude[scan_idx];

        double x = firings[fir_idx].distance[scan_idx] *
          cos_scan_altitude[scan_idx] * sin_azimuth;
        double y = firings[fir_idx].distance[scan_idx] *
          cos_scan_altitude[scan_idx] * cos_azimuth;
        double z = firings[fir_idx].distance[scan_idx] *
          sin_scan_altitude[scan_idx];

        double x_coord = y;
        double y_coord = -x;
        double z_coord = z;

        // Compute the time of the point
        double time = packet_start_time +
          FIRING_TOFFSET*(fir_idx-start_fir_idx) + DSR_TOFFSET*scan_idx;

        // Remap the index of the scan
        int remapped_scan_idx = scan_idx%2 == 0 ? scan_idx/2 : scan_idx/2+8;
        sweep_data->scans[remapped_scan_idx].points.push_back(
            velodyne_puck_msgs::VelodynePuckPoint());
        velodyne_puck_msgs::VelodynePuckPoint& new_point =
          sweep_data->scans[remapped_scan_idx].points[
          sweep_data->scans[remapped_scan_idx].points.size()-1];

        // Pack the data into point msg
        new_point.time = time;
        new_point.x = x_coord;
        new_point.y = y_coord;
        new_point.z = z_coord;
        new_point.azimuth = firings[fir_idx].azimuth[scan_idx];
        new_point.distance = firings[fir_idx].distance[scan_idx];
        new_point.intensity = firings[fir_idx].intensity[scan_idx];
      }
    }

    packet_start_time += FIRING_TOFFSET * (end_fir_idx-start_fir_idx);
  }

  return;
}

} // end namespace velodyne_puck_decoder

