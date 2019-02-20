/** main.cpp
 * @author Menson Li
 * 
 * @email menson168@gmail.com
 * 
 * @desc The main firmware source code for the CAN-Arduino-ROS gateway.
 * 
 */

/** Note:
 *  - This Firmware and its library have set the ROS-Arduino Serial baudrate to be 500Kbps (500000 BPS).
 *    Double check the baudrate by following the instruction in the README file of this project.
 */

// Include main firmware header
#include <osv_can_gateway_main.h>

// Create CAN object
MCP_CAN OSV_CAN(SPI_CS_PIN);

// Declare can timer
Timer can_timer;

// Declare ros node handle
ros::NodeHandle can_ros_nh;

// Declare the outgoing message
interface::Can_Interface received_can_message;
interface::Can_Interface_Debug can_debug_message;

// Declare ros publisher and subscriber for relaying the CAN message
ros::Publisher can_relay_pub("/can_gateway/received", &received_can_message);
ros::Publisher can_relay_debug_pub("/can_gateway/debug", &can_debug_message);
ros::Subscriber<interface::Can_Interface> can_relay_sub("/can_gateway/send", &ROSGatewaySendCallback);
ros::Subscriber<std_msgs::Bool> can_relay_mode_sub("/can_gateway/mode", &ROSGatewayModeCallback);

// Declare global action flags
bool GatewayMode = OFF;
bool IsDBWInitialized = false;
bool IsPropulsionPowerMessageSent = false;
bool HoldSteeringValue = true;

// Declare Global timer value
//unsigned long int next_propulsion_control_event = 0;

// Declare Global timer event
//int propulsion_power_event;

// Declare Global CAN message frame
uint8_t steering_message_data[8] = {0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66};        // Data is set to set steering straight by default
//uint8_t propulsion_message_data[8] = {0x00, 0x00, 0xFF, 0x7F, 0x00, 0x0D, 0x00, 0x00};      // Data is set to set zero rpm by default

void setup() 
{
  InitializeCommunication();
  can_timer.every(10, TimerRosSpinCallback);
}

void loop() 
{
  // Checks to see if it is time to send the propulsion control message
  // if((millis() >= next_propulsion_control_event) && IsDBWInitialized && IsPropulsionPowerMessageSent)
  // {
  //   // Send propulsion control data
  //   OSV_CAN.sendMsgBuf(PROPULSION_CONTROL_ID, STD_FRAME, 8, propulsion_message_data);      
  //   IsPropulsionPowerMessageSent = false;
  // }
  // Check if hold steering position is false
  if(!HoldSteeringValue && IsDBWInitialized)
  {
    // Send steering control data if hold is false
    OSV_CAN.sendMsgBuf(STEERING_ARB_ID, EXT_FRAME, 8, steering_message_data);      
  }

  // Check receive and send to ROS
  if(IsDBWInitialized)
  {
    CheckIncomingMessage();
  }

  // Debug messages
  SendDebugMessages();     

  //Update Timer
  can_timer.update();
}

void ROSGatewaySendCallback(const interface::Can_Interface &can_outgoing_msg)
{
  for(uint8_t i = 0; i < 8; i++)
  {
    steering_message_data[i] = can_outgoing_msg.steering_can_data[i];
    //propulsion_message_data[i] = can_outgoing_msg.propulsion_can_data[i];
  }
  HoldSteeringValue = can_outgoing_msg.hold_steering_position;
}

void ROSGatewayModeCallback(const std_msgs::Bool &can_mode_msg)
{
  GatewayMode = can_mode_msg.data;
  if((!IsDBWInitialized) && (GatewayMode))
  {
    InitializeDBWSystem();
    IsDBWInitialized = true;  
    SendDebugMessages();
  }
}

bool InitializeCommunication()
{
  // Initialize ROS Communication
  can_ros_nh.getHardware()->setBaud(ROSSERIAL_BAUD);    // Set Rosserial baud to 500 kbps
  can_ros_nh.initNode();                                // init ros node  
  // Init Publisher
  can_ros_nh.advertise(can_relay_pub);   
  can_ros_nh.advertise(can_relay_debug_pub);                  
  // Init Subscriber
  can_ros_nh.subscribe(can_relay_sub);                  
  can_ros_nh.subscribe(can_relay_mode_sub);

  // Initialize CAN BUS
  while (CAN_OK != OSV_CAN.begin(CAN_250KBPS))          // init can bus : baudrate = 250KBPS
  {
    can_debug_message.isCanBusInitialized = false;   // Send out can bus failure message
    can_relay_debug_pub.publish(&can_debug_message);
    can_ros_nh.spinOnce();
    delay(100);
  }  
  can_debug_message.isCanBusInitialized = true;      // Send out can bus initialized message
  SendDebugMessages();
  can_ros_nh.spinOnce();  

  return true;
}

bool InitializeDBWSystem()
{
  // Perform Steering CAN BUS Initialization
  //OSV_CAN.sendMsgBuf(STEERING_ARB_ID, EXT_FRAME, 8, Steering_Set_Zero_Data);        // Set steering position to zero
  //OSV_CAN.sendMsgBuf(STEERING_ARB_ID, EXT_FRAME, 8, Steering_Set_Center_Data);      // Center steering wheel

  // Send 5 seconds long of power signals 
  //unsigned long propulsion_power_init_current_time = millis();
  //const unsigned long propulsion_power_init_end_time = propulsion_power_init_current_time + 5000;
  
  // Initialize timer event on propulsion power callback every 50 ms or at a freq of 20Hz
  //propulsion_power_event = can_timer.every(50, TimerPropulsionPowerCallback);
  // while(propulsion_power_init_current_time < propulsion_power_init_end_time)
  // {
  //   // Block the program during the 5 seconds init period for propulsion
  //   can_timer.update();
  //   propulsion_power_init_current_time = millis();
  // }
  return true;
}

// void TimerPropulsionPowerCallback()
// {
//   // Send Propulsion Power Data Frame
//   OSV_CAN.sendMsgBuf(PROPULSION_POWER_ID, STD_FRAME, 8, Propulsion_Power_Data);
//   next_propulsion_control_event = millis() + 25;
//   IsPropulsionPowerMessageSent = true;
// }

void SendDebugMessages()
{
  can_debug_message.isGatewayInitialized = IsDBWInitialized;
  can_debug_message.canMode = GatewayMode;
  can_relay_debug_pub.publish(&can_debug_message);
}

void TimerRosSpinCallback()
{
  can_ros_nh.spinOnce();  
}

void CheckIncomingMessage()
{
  uint8_t len = 0;
  uint8_t buf[8];

  if(CAN_MSGAVAIL == OSV_CAN.checkReceive())            // check if data coming
  {
    OSV_CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

    uint32_t canId = OSV_CAN.getCanId();

    if(canId == STEERING_FEEDBACK_ARB_ID)
    {
      for(int i = 0; i <len ; i++)
      {
        received_can_message.steering_can_data[i] = buf[i];
      }
      can_relay_pub.publish(&received_can_message);
    }
  }  
}