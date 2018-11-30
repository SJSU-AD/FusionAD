# CONTROL TESTING README  

## Testing  
The unittest in control package is written with gtest, Google's C++ unittest framework.    

### Pre-requisite for building the test:  
* Installing Gtest:  
  * ```
    sudo apt-get install libgtest-dev  
    cd /usr/src/gtest  
    sudo cmake CMakeLists.txt  
    sudo make  

    sudo cp *.a /usr/lib  
    ```


### To Build and Run the test:  
* ```catkin_make tests```
* ```roscore && rosrun control control_test```   
* Press Ctrl + C to kill the node, the test result will appear after the node is killed   

### References  
[ysonggit's tutorial on ROS-gtest](http://ysonggit.github.io/coding/2014/12/19/use-gtest-in-ros-program.html)
