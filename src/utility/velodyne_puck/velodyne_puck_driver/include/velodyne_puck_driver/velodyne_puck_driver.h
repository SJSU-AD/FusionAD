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

#ifndef VELODYNE_PUCK_DRIVER_H
#define VELODYNE_PUCK_DRIVER_H

#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string>

#include <boost/shared_ptr.hpp>

#include <ros/ros.h>
#include <diagnostic_updater/diagnostic_updater.h>
#include <diagnostic_updater/publisher.h>

#include <velodyne_puck_msgs/VelodynePuckPacket.h>

namespace velodyne_puck_driver {

static uint16_t UDP_PORT_NUMBER = 2368;
static uint16_t PACKET_SIZE = 1206;

class VelodynePuckDriver {
public:

  VelodynePuckDriver(ros::NodeHandle& n, ros::NodeHandle& pn);
  ~VelodynePuckDriver();

  bool initialize();
  bool polling();

  typedef boost::shared_ptr<VelodynePuckDriver> VelodynePuckDriverPtr;
  typedef boost::shared_ptr<const VelodynePuckDriver> VelodynePuckDriverConstPtr;

private:

  bool loadParameters();
  bool createRosIO();
  bool openUDPPort();
  int getPacket(velodyne_puck_msgs::VelodynePuckPacketPtr& msg);

  // Ethernet relate variables
  std::string device_ip_string;
  in_addr device_ip;
  int socket_id;

  // ROS related variables
  ros::NodeHandle nh;
  ros::NodeHandle pnh;

  std::string frame_id;
  ros::Publisher packet_pub;

  // Diagnostics updater
  diagnostic_updater::Updater diagnostics;
  boost::shared_ptr<diagnostic_updater::TopicDiagnostic> diag_topic;
  double diag_min_freq;
  double diag_max_freq;
};

typedef VelodynePuckDriver::VelodynePuckDriverPtr VelodynePuckDriverPtr;
typedef VelodynePuckDriver::VelodynePuckDriverConstPtr VelodynePuckDriverConstPtr;

} // namespace velodyne_driver

#endif // _VELODYNE_DRIVER_H_
