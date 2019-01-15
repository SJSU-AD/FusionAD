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
* You can either run the tests for each control feature individually or run all of them at the same time.  
* To build and run all the control tests:  
    * ```catkin_make run_tests_control``` 
    * The tests will be built and the result will be shown in the terminal window.
* To build and run the tests individually:  
    * ```catkin_make tests```
        * For running the control lateral test:  
            * ```roscore && rosrun control lateral_control_test```     
        * For running the control waypoint selector test:
            * ```roscore && rosrun control control_path_test```    
        * Press Ctrl + C to kill the node, the test result will appear after the node is killed   

