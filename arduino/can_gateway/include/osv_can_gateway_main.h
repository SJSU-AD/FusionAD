/** osv_can_gateway_main.h
 * @author Menson Li
 * 
 * @email menson168@gmail.com
 * 
 * @desc The header file for the CAN-Arduino-ROS gateway.
 * 
 */
#ifndef OSV_CAN_GATEWAY_MAIN_H_
#define OSV_CAN_GATEWAY_MAIN_H_

// Include all arduino headers
#include <Arduino.h>
#include <mcp_can.h>
#include <Timer.h>
#include <SPI.h>

// Include all ros headers
#include <ros.h>
#include <interface_msgs/Can_Interface.h>
#include <std_msgs/Bool.h>
#include <interface_msgs/Can_Interface_Debug.h>

// Declare all constants or preprocessors

// Status preprocessors
// Gateway Mode
#define ON 1
#define OFF 0
// CAN Frame Parameters
#define EXT_FRAME 1
#define STD_FRAME 0
// Communication Params
#define ROSSERIAL_BAUD 115200
#define SPI_CS_PIN 9
// CAN ID
#define STEERING_ARB_ID 0x18FF00F9
//#define PROPULSION_POWER_ID 0x204
//#define PROPULSION_CONTROL_ID 0x304
#define STEERING_FEEDBACK_ARB_ID 0x18FF0113

// CAN Message Frames for Init
const uint8_t Steering_Set_Zero_Data[8] = {0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t Steering_Set_Center_Data[8] = {0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66};
//const uint8_t Propulsion_Power_Data[8] = {0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// Define all function prototype

// ROS Callbacks
void ROSGatewaySendCallback(const interface::Can_Interface &can_outgoing_msg);
void ROSGatewayModeCallback(const std_msgs::Bool &can_mode_msg);

// Initialize functions
bool InitializeCommunication();
bool InitializeDBWSystem();
void SendDebugMessages();

// Timer Callbacks
void TimerPropulsionPowerCallback();
void TimerRosSpinCallback();

// Check if incoming message received
void CheckIncomingMessage();

#endif //OSV_CAN_GATEWAY_MAIN_H_