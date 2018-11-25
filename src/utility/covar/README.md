# test_gsl AKA covar
## 0. First things
Ensure that gsl is installed:
`sudo apt-get install libgsl2 libgsl-dev libgsl-dbg gsl-bin`

## 1. Getting the package
Do the following to add to the src of your ROS workspace (i.e. catkin_ws if you kept the dirname from ROS tutorial), *almost* as you would any other package - we're going to give this repo's dirname "covar" instead of "test_gsl".
* `cd path/to/catkin_ws/src; git clone https://github.com/ntwong0/test_gsl.git -b ROSify covar`

## 2. Installation
catkin_make as usual:
* `cd path/to/catkin_ws; catkin_make`

**You already have the loam_velodyne package installed, right?**

## 3. Running
No launch file has yet been prepared, so use rosrun instead, and don't forget to source the setup.bash file:
* `cd path/to/catkin_ws; source devel/setup.bash`
* `rosrun covar covar_node`

## 4. Service calls - this is why you "bought" it 
Generate the covariance matrix with the following:
* For pose only, 100 samples
    * `rosservice call /gen_pose_covar 100`
* For twist only, 100 samples
    * `rosservice call /gen_twist_covar 100`
* For pose and twist, 100 samples pose and 200 samples twist
    * `rosservice call /gen_both_covar 100 200`

## 999. Dummy compilation note:
To compile, do the following:
<!-- gcc <filename> -lgsl -lgslcblas -->
g++ -std=c++11 src/file.cpp -lgsl -lgslcblas -Iinclude

Header files of the gsl library are located at /usr/include/gsl
