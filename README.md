![SJSUxSJSU_AD](https://i.imgur.com/4hXBYbz.png)  

# Welcome to FusionAD

FusionAD is an autonomous driving software stack developed by the SJSU Autonomous Driving Team at San Jose State University (SJSU), San Jose, CA.   
    
Our challenge is to create a fully functional autonomous driving vehicle within the **1 Year** timeline of a Mechanical Engineering Senior Project at SJSU.

# See KPIX Bay Area's coverage on SJSU autonomous driving on Youtube
[![](http://img.youtube.com/vi/WfKbCQZTQx8/0.jpg)](http://www.youtube.com/watch?v=WfKbCQZTQx8 "San Jose State Engineering Students Build Self-Driving Vehicle on Shoestring Budget")

## FusionAD's Software Architecture
![FusionAD Architecture](https://i.imgur.com/e7NYAYK.png)
  
This repository mainly capture the software application layer within FusionAD's architecture.  

### Application Modules
Currently, all the modules are under work in progress and they are located under ```FusionAD/src/modules```  
Current capabilities of the software modules:  
* **Perception**
    * Integration done with Yolo V3 image detector
* **Localization**
    * EKF through ```robot_localization``` package
    * Dead reckoning vehicle kinematic model
    * Initial Calibration routine
    * Transforms between sensors and tracking frames
* **Planning**
    * "Virtual rail" planner - Basic route planner
* **Control**
    * High-level motion controller
    * Low-level actuator controller
    * Tele-op interface
    * CAN Bus interface
* **Simulation**
    * [OSV Sim](https://github.com/SJSU-AD/osv_sim)
        * A full fledge vehicle simulator on the Gazebo Simulation Platform
    * [Control SIL](https://github.com/SJSU-AD/FusionAD/wiki/High-Level-Controller-Software-In-the-Loop-(SIL)-Testing)
        * A Real-time, Software In the Loop testing environment for high-level controller vaidation.  
          
### Operating Systems and Requirements
* FusionAD is developed on **ROS KINETICS** and **UBUNTU 16.04 LTS**. We do not support other version of ROS or Ubuntu at the moment.

## Hardware
### Sensor Stack
One of the goals at SJSU Autonomous Driving is to make autonomy development more accessible and cheaper.    
Therefore, our sensor stack consisted of mainly low-cost and easily attainable sensors.
* GPS
    * [SwiftNav Piksi Multi RTK](https://www.swiftnav.com/piksi-multi)
* IMU
    * [Sparkfun Razor 9Dof IMU](https://www.sparkfun.com/products/14001)
* Wheel Encoders
    * [Generic Incremental Encoder](https://www.amazon.com/Signswise-Incremental-Encoder-Dc5-24v-Voltage/dp/B00UTIFCVA/ref=sr_1_5?ie=UTF8&qid=1548354220&sr=8-5&keywords=rotary+encoders)
* Cameras
    * [Pi Camera](https://www.amazon.com/Keyestudio-Camera-Module-Raspberry-Model/dp/B073RCXGQS/ref=sr_1_8?ie=UTF8&qid=1548354282&sr=8-8&keywords=pi+camera) + [Raspberry Pi](https://www.amazon.com/ELEMENT-Element14-Raspberry-Pi-Motherboard/dp/B07BDR5PDW/ref=sr_1_2?ie=UTF8&qid=1548354319&sr=8-2&keywords=rpi) together forms a camera node
* Lidar
    * [Velodyne VLP-16](https://velodynelidar.com/vlp-16.html)

### Computation
Current computation architecture mimics a distributed system for distributing tasks and loads between the two resource-heavy modules, perception and map-based localization.
* Main Computer
    * Spec:  i7-7700HQ  +  GTX 1050  +  16 Gb Ram
    * Handles most localization + planning + control computations
* 2x Nvidia Jetson TX2
    * Dedicated to perform image detection computations 

## How to build FusionAD:
1. **Run: ```sudo ext_package_build.sh``` at the root directory to ensure all the prerequisites of the external ROS packages used in this stack are met and installed**
2. Run: ```catkin_make``` at the root directory

## Development
### Branches
* **master**
    * Most stable branch
    * FusionAD do not recommend performing development from this branch
* **develop**
    * Contains __tested__ features
    * **__FusionAD recommends performing development on this branch__**
* **test_deployment**
    * Contains features that are pending to be tested on the vehicle
    * FusionAD do not recommend performing development from this branch
* **slave_tx2**
    * Contains software for the Jetson TX2 modules
    * Not Open for main FusionAD development except for software related to the TX2 board
* **release_branches**
    * Sealed branch for storing past releases
    * Not Open for development

## Maintainers
### The Core FusionAD team
![SeniorProjectTeam](https://i.imgur.com/6nWVhY2.png)
    
FusionAD also appreciate the help of other passionate SJSU students!  
We would like to acknowledge the following FusionADers:
* John Phung
    * FusionAD Program and Community Manager
* [Nelson Wong](https://github.com/ntwong0)
    * SJSU Autonomous Driving Perception and Localization Engineer
* [Francisco Ibrarra](https://github.com/Francisco-Ibarra07)
    * SJSU Autonomous Driving Perception Engineer
