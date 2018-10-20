# Geodesy
Module for geographic coordinate system conversions and reference frame transformations.

**INPUT:** A set of GPS coordinates to be followed as a path. Check "[Collect coarse input path data](#collect-coarse-input-path-data)" for correct input format.

**OUTPUT:** A linearly interpolated path between the input points, in order of the points input. Coordinate system of choice shown in "[Choose coordinate output system](#choose-coordinate-output-system)"

**OUTPUT:** The current pose in chosen coordinate system.

**NOTE:** This vehicle's coordinate system standard is in ENU

## Usage - Preparation
### Collect coarse input path data
Input path in /geodesy_data/gps_coarse_points in the following ".csv" format:

```
type	latitude	longitude	name
W	37.3371389	-121.8799411	1
W	37.3371178	-121.8799050	2
W	37.3370886	-121.8798571	3
W	37.3370421	-121.8797874	4
```

This format can be generated from the [GPS Visualizer](http://www.gpsvisualizer.com/draw/), using the "wpt" tool to add markers to the map and export as ".csv" format (this is marked as ".txt" format on the gps visualizer website).

## Usage - Online/rosbag Validation
Run in this mode to publish linearly interpolated path from input GPS coordinates and pose.

### Select the path of choice in the main launch file
Launch file location: /launch/geodesy.launch

Modify the "value" argument in the "~file_path" param tags to point to the path of choice, as generated instnsructions in "[Collect coarse input path data](#collect-coarse-input-path-data)" section. The file chosen for the example below is `student_union_straight.txt`. The option to chose conversion method is available here, but it is recommended to keep this setting at "ENU" to retain a single standard across all modules.
```xml
  <node type="path_interpolation.py" pkg="geodesy" name="path_interpolator" output="screen">
    <param name="~file_path" value="$(find geodesy)/geodesy_data/gps_coarse_points/student_union_straight.txt" />
    <param name="~conversion_type" value="ENU" />
  </node>

  <node type="gps_pose.py" pkg="geodesy" name="gps_pose_converter" output="screen">
    <param name="~file_path" value="$(find geodesy)/geodesy_data/gps_coarse_points/student_union_straight.txt" />
  </node>
```

### Launch the launch file
Using the following command:
`roslaunch geodesy geodesy.launch`

Expected output should be similar to that shown below, if no GPS device is connected or there is no rosbag running with GPS

```
$ roslaunch geodesy geodesy.launch
... logging to /home/drp/.ros/log/7179fbcc-cc09-11e8-8fff-9cb6d0f930e9/roslaunch-drp-XPS-15-9560-4638.log
Checking log directory for disk usage. This may take awhile.
Press Ctrl-C to interrupt
WARNING: disk usage in log directory [/home/drp/.ros/log] is over 1GB.
It's recommended that you use the 'rosclean' command.

started roslaunch server http://drp-XPS-15-9560:42517/

SUMMARY
========

PARAMETERS
 * /diagnostic_aggregator/analyzers/GPS/contains: ['piksi_']
 * /diagnostic_aggregator/analyzers/GPS/path: GPS
 * /diagnostic_aggregator/analyzers/GPS/timeout: 5.0
 * /diagnostic_aggregator/analyzers/GPS/type: diagnostic_aggreg...
 * /diagnostic_aggregator/pub_rate: 1.0
 * /gps_pose_converter/file_path: /home/drp/Documen...
 * /path_interpolator/file_path: /home/drp/Documen...
 * /rosdistro: kinetic
 * /rosversion: 1.12.14
 * /swiftnav_ros_node/port: /dev/ttyUSB0

NODES
  /
    diagnostic_aggregator (diagnostic_aggregator/aggregator_node)
    gps_pose_converter (geodesy/gps_pose.py)
    path_interpolator (geodesy/path_interpolation.py)
    swiftnav_ros_node (swiftnav_ros/swiftnav_ros_node)

auto-starting new master
process[master]: started with pid [4648]
ROS_MASTER_URI=http://localhost:11311

setting /run_id to 7179fbcc-cc09-11e8-8fff-9cb6d0f930e9
process[rosout-1]: started with pid [4661]
started core service [/rosout]
running rosparam delete /diagnostic_aggregator
ERROR: parameter [/diagnostic_aggregator] is not set
process[swiftnav_ros_node-2]: started with pid [4683]
process[diagnostic_aggregator-3]: started with pid [4684]
[ERROR] [1539120157.342279391]: Failed to open SBP device on /dev/ttyUSB0
process[path_interpolator-4]: started with pid [4698]
process[gps_pose_converter-5]: started with pid [4715]
[INFO] [1539120157.614564]: Published Path with 50 steps
[INFO] [1539120157.616735]: Instantiated publisher
[INFO] [1539120157.620114]: Found and initialized intial lat/lon/altitude values
[INFO] [1539120157.620865]: Initial latitude: 37.337139
[INFO] [1539120157.621431]: Initial latitude: -121.879941
[INFO] [1539120157.621965]: Initial latitude: -6.000000
[INFO] [1539120158.615313]: Published Path with 50 steps
[INFO] [1539120159.615279]: Published Path with 50 steps
[INFO] [1539120160.615277]: Published Path with 50 steps
[INFO] [1539120161.615256]: Published Path with 50 steps
```

A path will publish at the rate noted in the output path publishing method (called in the try block from [Usage - Online/rosbag Validation](#usage---onlinerosbag-validation)). The default rate is 1 Hz. It is highly reccomended to keep this value as is.
*Example:* The publishing method for ENU conversion is `interpolation_publish_ENU()`

**NOTE:** If the launch file does not run, double check that the repo is built with 
```
catkin_make
```
...and the proper environment has been sourced using 
```
source devel/setup.bash
```
from the root of the workspace.

## Usage - Online IMU Validation
Launch the appropriate launch file:
```
roslaunch geodesy tf_launch.launch
```

## Usage - Offline Validation
Here are the steps for validating conversion points by reading from a ".csv" file and writing the converted values to another ".csv" file, so the conversion data can be validated manually.

Run the `geodesy_converter_tester.py` script to validate input GPS data in the following format, where the first coordinate in each line is latitude, and the second coordinate in each line is latitude.
```
37.3371440781,-121.879934136
37.3371442522,-121.879934655
37.3371442441,-121.879934437
37.3371443401,-121.879934479
37.3371440806,-121.879933884
```

Input the relative path to the input and output into the `verify_gps_csv_data_enu()` function to validate the lat/lon data to ENU conversion data. The output file should roughly match the input file. An equivalent function, `verify_gps_point_enu()` is available for validating a single point, where only the first point in the input file will be validated

## Available coordinate output systems
Choices available are:
* ECEF (Earth-Centered, Earth-Fixed)
* ENU (East, North, Up)
* UTM (Universal Transverse Mercator)

Future choices may include (TODO):
* NED (North, East, Down)

**WARNING:** Changes in coordinate system should be done with care. The default across all modules is ENU, and this should be used for all live operating purposes.

## Notes
Coordinate systems follow format specified by [REP 103](http://www.ros.org/reps/rep-0103.html).

For ENU, this specification is as follows:
```
x = east
y = north
z = up
```
