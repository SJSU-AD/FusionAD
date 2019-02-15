# Define header of message
Header header

# 8 Byte Data field
uint8[8]  steering_can_data
uint8[8]  propulsion_can_data

# Steering Hold
bool hold_steering_position     # If this variable is true, the CAN gateway will not send a steering message
  