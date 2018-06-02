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

#ifndef VELODYNE_PUCK_DECODER_NODELET_H
#define VELODYNE_PUCK_DECODER_NODELET_H

#include <ros/ros.h>
#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

#include <velodyne_puck_decoder/velodyne_puck_decoder.h>

namespace velodyne_puck_decoder {
class VelodynePuckDecoderNodelet: public nodelet::Nodelet {
public:

  VelodynePuckDecoderNodelet() {}
  ~VelodynePuckDecoderNodelet() {}

private:

  virtual void onInit();
  VelodynePuckDecoderPtr decoder;
};

} // end namespace velodyne_puck_decoder


#endif
