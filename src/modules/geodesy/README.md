# Geodesy
Module for geographic coordinate system conversions and reference frame transformations.

**INPUT:** Coarse GPS coordinates in latitude/longitude

**OUTPUT:** A linearly interpolated path between the input points, in order of the points input. Coordinate system of choice shown in "[Choose coordinate output system](#choose-coordinate-output-system)"

## Usage Preparation
### Collect coarse input path data
Input path in /geodesy_data/gps_coarse_points in the following ".csv" format:

```
type	latitude	longitude	name
W	37.3371389	-121.8799411	1
W	37.3371178	-121.8799050	2
W	37.3370886	-121.8798571	3
W	37.3370421	-121.8797874	4
```

This format can be generated from the [GPS Visualizer](http://www.gpsvisualizer.com/draw/), using the "wpt" tool to add markers to the map and export as ".csv" format.

### Choose coordinate output system
Choices available are:
* ECEF (Earth-Centered, Earth-Fixed)
* ENU (East, North, Up)
* UTM (Universal Transverse Mercator)

Future choices may include (TODO):
* NED (North, East, Down)

## Usage for online or rosbag validation
Uncomment the line in `path_interpolation.py` corresponding to the desired output coordinate system. This will instantiate the appropriate object for performing conversions on the input path.

```python
    ##### ECEF #####
    # interpolatorECEF = PathInterpolatorECEF(inputLatitudes, inputLatitudes, inputHeights, chosenHeight)

    ##### ENU #####
    interpolatorENU = PathInterpolatorENU(inputLatitudes, inputLongitudes, inputHeights)

    ##### UTM #####
    # interpolatorUTM = PathInterpolatorUTM(inputLatitudes, inputLongitudes)
    
    try:
        # interpolatorECEF.interpolation_publish_ECEF()
        interpolatorENU.interpolation_publish_ENU()
        # interpolatorUTM.interpolation_publish_UTM()
    except rospy.ROSInterruptException:
        pass
```

**NOTE:** *BOTH* the selected interpolator object *AND* the method call line in the 'try' block must be uncommented and correspond appropriately to one another.

### Select the path of choice in the main launch file
Launch file location: /launch/geodesy.launch

Modify the "value" argument in the "param" tags to point to the path of choice, as generated instnsructions in "[Collect coarse input path data](#collect-coarse-input-path-data)" section. The file chosen for the example below is `student_union_straight.txt`.
```xml
  <node type="path_interpolation.py" pkg="geodesy" name="path_interpolator" output="screen">
    <param name="~file_path" value="$(find geodesy)/geodesy_data/gps_coarse_points/student_union_straight.txt" />
    <!-- <param name="~file_path" value="$(find geodesy)/geodesy_data/gps_coarse_points/path_1.txt" /> -->
  </node>

  <node type="gps_pose.py" pkg="geodesy" name="gps_pose_converter" output="screen">
    <param name="~file_path" value="$(find geodesy)/geodesy_data/gps_coarse_points/student_union_straight.txt" />
    <!-- <param name="~file_path" value="$(find geodesy)/geodesy_data/gps_coarse_points/path_1.txt" /> -->
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

A path will publish at the rate noted in the output path publishing method (called in the try block from [Usage: Online or rosbag Validation](Usage-for-online-or-vrosbag-validation)). The default rate is 1 Hz. It is highly reccomended to keep this value as is.
*Example:* The publishing method for ENU conversion is "interpolation_publish_ENU()"

**NOTE:** If the launch file does not run, double check that the repo is built with 
```
catkin_make
```
...and the proper environment has been sourced using 
```
source devel/setup.bash
```
from the root of the workspace.

## Usage for Offline Validation


