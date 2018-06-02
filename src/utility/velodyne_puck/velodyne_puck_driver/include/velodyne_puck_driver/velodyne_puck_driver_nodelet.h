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

#include <velodyne_puck_driver/velodyne_puck_driver.h>

namespace velodyne_puck_driver
{

class VelodynePuckDriverNodelet: public nodelet::Nodelet
{
public:

  VelodynePuckDriverNodelet();
  ~VelodynePuckDriverNodelet();

private:

  virtual void onInit(void);
  virtual void devicePoll(void);

  volatile bool running;               ///< device thread is running
  boost::shared_ptr<boost::thread> device_thread;

  VelodynePuckDriverPtr velodyne_puck_driver; ///< driver implementation class
};

} // namespace velodyne_driver
