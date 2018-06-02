# velodyne\_puck

[![Build Status](https://travis-ci.org/KumarRobotics/velodyne_puck.svg?branch=master)](https://travis-ci.org/KumarRobotics/velodyne_puck)

![Picture of Velodyne Puck](http://velodynelidar.com/images/products/vlp-16/puck.png)

The `velodyne_puck` package is a linux ROS driver for velodyne puck only of [VELODYNE LIDAR](http://velodynelidar.com/). The user manual for the device can be found [here](http://velodynelidar.com/vlp-16.html) or the LTE version [here](http://velodynelidar.com/vlp-16-lite.html).

The major difference between this driver and the [ROS velodyne driver](http://wiki.ros.org/velodyne_driver) is that the start of each revolution is detected using azimuth.

The package is tested on Ubuntu 14.04 with ROS indigo.

## License
This driver is developed based on [ROS velodyne driver](http://wiki.ros.org/velodyne_driver), which originally has the BSD license. The COPYING file is kept in this package. However, the changed files have the GNU General Public License V3.0.

## Compling
This is a Catkin package. Make sure the package is on `ROS_PACKAGE_PATH` after cloning the package to your workspace. And the normal procedure for compling a catkin package will work.

```
cd your_work_space
catkin_make --pkg velodyne_puck_driver velodyne_puck_decoder --cmake-args -DCMAKE_BUILD_TYPE=Release
```

## Example Usage

### velodyne_puck_driver

**Parameters**

`device_ip` (`string`, `default: 192.168.1.201`)

By default, the IP address of the device is 192.168.1.201.

`frame_id` (`string`, `default: velodyne`)

The frame ID entry for the sent messages.

**Published Topics**

`velodyne_packets` (`velodyne_puck_msgs/VelodynePuckPacket`)

Each message corresponds to a velodyne packet sent by the device through the Ethernet. For more details on the definition of the packet, please refer to the [user manual](http://velodynelidar.com/docs/manuals/63-9243%20Rev%20B%20User%20Manual%20and%20Programming%20Guide,VLP-16.pdf).

### velodyne_puck_decoder

**Parameters**

`min_range` (`double`, `0.3`)

`max_range` (`double`, `100.0`)

Points outside this range will be removed.

`frequency` (`frequency`, `20.0`)

Note that the driver does not change the frequency of the sensor. If needed, the RPM of the sensor should be set through the brower (see [user manual](http://velodynelidar.com/docs/manuals/63-9243%20Rev%20B%20User%20Manual%20and%20Programming%20Guide,VLP-16.pdf) for more details). And the `frequency` parameter in the launch file should be set accordingly.

`publish_point_cloud` (`bool`, `false`)

If set to true, the decoder will additionally send out a local point cloud consisting of the points in each revolution.

**Published Topics**

`velodyne_sweep` (`velodyne_puck_msgs/VelodynePuckSweep`)

The message arranges the points within each sweep based on its scan index and azimuth.

`velodyne_point_cloud` (`sensor_msgs/PointCloud2`)

This is only published when the `publish_point_cloud` is set to `true` in the launch file.

**Node**

```
roslauch velodyne_puck_decoder velodyne_puck_decoder_nodelet.launch
```

Note that this launch file launches both the driver and the decoder, which is the only launch file needed to be used.


## FAQ


## Bug Report

Prefer to open an issue. You can also send an E-mail to sunke.polyu@gmail.com.
