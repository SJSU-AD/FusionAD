# CAN-Arduino-ROS (CAR) Gateway
The CAN-Arduino-ROS (CAR) Gateway is an Arduino CAN to ROS gateway for the OSV vehicle. It serves as an interface between the OSV Drive-By-Wire System CAN Bus and the ROS network on the master computer. 

## Development Environment
The CAR Gateway project uses ```platform.io```, a cros-platform IDE Extension on Visual Studio Code.
* Installation:
    1. Please download and install [Visual Studio Code](https://code.visualstudio.com/) (VSCode)
    2. Install the [PlatformIO IDE Extension](https://platformio.org/install/ide?install=vscode) in the VSCode Extensions store (Click on hyperlink for instruction)
* Develop/Build the CAR Firmware on an Arduino Mega:
    1. Open the CAR Gateway project from the PlatformIO home menu in your VSCode editor.
        * Open the PlatformIO home menu by clicking on the PlatformIO Icon on your VSCode Activity Bar (On the left side of the VSCode window)
    2. Open ```can_gateway/platformio.ini```
        * Change the upload port settings to point to the right serial port for uploading the firmware
    3. Navigate to the ```can_gateway/src``` directory
    4. Open ```main.cpp```. This is the CAR Gateway's main firmware.
    5. Build or Upload the firmware to the Arduino
        * You may use keyboard bindings or the PlatformIO GUI to build or upload the code:
            * __Keybindings:__
                * BUILD: ```ctrl+alt+b``` or ```ctrl+shift+b``` or ```cmd-shift-b```
                * UPLOAD: ```ctrl+alt+u```
                * OPEN SERIAL MONITOR: ```ctrl+alt+s```
            * __GUI (PlatformIO Toolbar)__
![](https://docs.platformio.org/en/latest/_images/platformio-ide-vscode-build-project.png) ![](https://i.imgur.com/QSJ5W9w.png)

## CAR Gateway Firmware
### Dependency
The PlatformIO development allows local storage of all the depended header libraries, which eliminates the concern of installing depended libraries on a new machine. You may see all the used libraries under ```can_gateway/lib```.   
  
  Currently, the CAR Gateway contains the following dependency:
  * ```ros_lib``` 
      * With custom message definition (```interface``` messages) from FusionAD
  * ```Timer```
      * A timer library with callback features from Simon Monks and other contributers
  * ```CAN_BUS_SHIELD```
      * A CAN bus library that provides APIs for the CAN Controller and Transceiver access on the Seeed Studio V1.2 CAN Shield (MCP2551 + MCP2515).

### ROS-Gateway Interface
#### Input and Output topics
* Input Topics:
    - ```/can_gateway/send``` 
        - Message Type: ```interface::Can_Interface```
        - Brief: This message should be sent from the master computer to the gateway. The message contains two byte arrays of size 8 and a boolean value for holding steering angle. Each of the byte arrays represents the steering or the propulsion control CAN data frame. The boolean value is used for preventing continuous identical steering control messages being sent, when this value is true, the gateway will stop sending steering control messages.
    - ```/can_gateway/mode```
        - Message Type: ```std_msgs::Bool```
        - Brief: This message should be sent from the master computer to the gateway. This message contains the boolean value for controlling the operating mode of the CAR Gateway. Currently, there are two modes:
            - ```ON``` (True)
            - ```OFF``` (False)
* Output Topics:
    - ```/can_gateway/debug```
        - Message Type: ```interface::Can_Interface_Debug```
        - Brief: This message should be sent from the gateway to the master computer. This message contains operating conditions of the gateway and various initialization paramters.


#### Initialization:
The gateway is designed to handle all the initialization of the CAN Bus network. Therefore, the role of an external initializer is to kick off the initialization of the DBW system.
  
  #### __*DO NOT SEND ANY MESSAGES to ```/can_gateway/send``` BEFORE THE DBW SYSTEM IS INITIALIZED*__

##### *Launching the CAR Gateway in ROS*
  Launching the CAR Gateway:
  ``` roslaunch interface can_gateway.launch```
##### *Initializing the DBW System*
  Initializing the DBW system:
  1. Send a __true__ value to ```/can_gateway/mode``` to switch on the gateway.
  2. Wait 5 Seconds for the gateway to initialize all the DBW CAN bus requirements
  OR
  You may also check the debug topic. You may send control messages to the gateway once the ```${debug_msg}.isGatewayInitialized``` field becomes __true__. 
  3. Once ```${debug_msg}.isGatewayInitialized``` becomes __true__, you may start sending DBW control data frames to ```/can_gateway/send```

#### Operation
The CAR gateway's role is a message delivery gateway. The input topic is designed to simplify the process of writing CAN control data frame to the OSV CAN bus without the worries of maintaining heartbeat CAN messages for the DBW system and other timing issues that may arise in a full fledge operating system.
 
 __Steering Control Command__:
* Send a size of 8, byte type array to ```${control_msg}.steering_can_data```

__Propulsion Control Command__:
* Send a size of 8, byte type array to ```${control_msg}.propulsion_can_data```

__How to Stuff the array__:  
C++
```
char steering_can_frame[8] = {0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
char propulsion_can_frame[8] = {0x00, 0x00, 0xFF, 0x7F, 0x00, 0x0D, 0x00, 0x00};

// Initialize the control message
interface::Can_Interface test_control_msgs;

// Using a for loop to stuff the message arrays
for(char i = 0; i < 8 ; i++)
{
  test_control_msgs.steering_can_data[i] = steering_can_frame[i];
  test_control_msgs.propulsion_can_data[i] = propulsion_can_frame[i];
}
```
Python 2 or 3 (This method has not been validated yet, as far as I know, the ros page says constant length array is represented as a tuple(1) in Python 2 or 3)
```
from interface.msg import Can_Interface

# Create instance of the can interface message
test_control_msgs = Can_Interface()

# Create tuples containing the outgoing steering and propulsion control can frame
steering_can_frame = (0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00)
propulsion_can_frame = (0x00, 0x00, 0xFF, 0x7F, 0x00, 0x0D, 0x00, 0x00)

# Store the tuples into the message
test_control_msgs.steering_can_data = steering_can_frame
test_control_msgs.propulsion_can_data = propulsion_can_frame
```
#### ROS Spin Speed
*Currently, the ROS spin frequency is set at 100 Hz, or at a 10 ms interval.*
  
   



## Extra
### Creating custom rosserial_arduino messages
Please use the following command to generate custom message header file for the CAR Gateway firmware:
```
rosrun rosserial_client make_libraries ${Location of ros_lib} ${ROS pkg contatining the message}
```
Example: 
```rosrun rosserial_client make_libraries ~/Arduino/libraries interface```  
  
__PLEASE NOTE THAT THE INTERFACE MESSAGE LIBRARY IS NAMED ```interface_msgs``` UNDER ```lib```, NOT ```interface/```.__  


### Changing rosserial_arduino baud rate
* The current serial baudrate of the CAR Gateway is ```500000``` (500 KPBS).
* You may change the serial baudrate by changing the value of ```ROSSERIAL_BAUD``` in ```can_gateway/include/osv_can_gateway_main.h```
