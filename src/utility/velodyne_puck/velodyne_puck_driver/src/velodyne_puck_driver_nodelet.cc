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

#include <string>
#include <boost/thread.hpp>

#include <ros/ros.h>
#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

#include <velodyne_puck_driver/velodyne_puck_driver_nodelet.h>


namespace velodyne_puck_driver
{

VelodynePuckDriverNodelet::VelodynePuckDriverNodelet():
  running(false) {
  return;
}

VelodynePuckDriverNodelet::~VelodynePuckDriverNodelet() {
  if (running) {
    NODELET_INFO("shutting down driver thread");
    running = false;
    device_thread->join();
    NODELET_INFO("driver thread stopped");
  }
  return;
}

void VelodynePuckDriverNodelet::onInit()
{
  // start the driver
  velodyne_puck_driver.reset(
      new VelodynePuckDriver(getNodeHandle(), getPrivateNodeHandle()));
  if (!velodyne_puck_driver->initialize()) {
    ROS_ERROR("Cannot initialize Velodyne driver...");
    return;
  }

  // spawn device poll thread
  running = true;
  device_thread = boost::shared_ptr< boost::thread >
    (new boost::thread(boost::bind(&VelodynePuckDriverNodelet::devicePoll, this)));
}

/** @brief Device poll thread main loop. */
void VelodynePuckDriverNodelet::devicePoll()
{
  while(ros::ok()) {
    // poll device until end of file
    running = velodyne_puck_driver->polling();
    if (!running)
      break;
  }
  running = false;
}

} // namespace velodyne_driver

// Register this plugin with pluginlib.  Names must match nodelet_velodyne.xml.
//
// parameters are: package, class name, class type, base class type
PLUGINLIB_DECLARE_CLASS(velodyne_puck_driver, VelodynePuckDriverNodelet,
                        velodyne_puck_driver::VelodynePuckDriverNodelet, nodelet::Nodelet);
