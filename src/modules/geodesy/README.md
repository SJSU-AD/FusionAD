# Geodesy
Module for geographic coordinate system conversions and reference frame transformations.

**INPUT:** Coarse GPS coordinates in latitude/longitude

**OUTPUT:** A linearly interpolated path between the input points, in order of the points input. Coordinate system of choice shown in ["Choose coordinate output system"](#choose-coordinate-output-system)

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

This format can be generated from the [GPS Visualizer](http://www.gpsvisualizer.com/draw/), using the "wpt" tool to add markers to the map and export as ".csv" format.

### Choose coordinate output system
Choices available are:
* ECEF (Earth-Centered, Earth-Fixed)
* ENU (East, North, Up)
* UTM (Universal Transverse Mercator)

Future choices may include:
* NED (North, East, Down)

### Select the path of choice in the main launch file
Launch file location: /launch/geodesy.launch

Modify the "value" argument in the "param" tag to point to the path of choice, as generated from ["Collect coarse input path data"](#collect-coarse-input-path-data)
```xml
  <node type="path_interpolation.py" pkg="geodesy" name="path_interpolator" output="screen">
    <param name="~file_path" value="$(find geodesy)/geodesy_data/gps_coarse_points/student_union_straight.txt" />
    <!-- <param name="~file_path" value="$(find geodesy)/geodesy_data/gps_coarse_points/path_1.txt" /> -->
  </node>
```

## Usage - Online Validation


## Usage - Offline Validation
