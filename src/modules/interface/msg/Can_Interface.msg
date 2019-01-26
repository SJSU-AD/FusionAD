# Define header of message
Header header

# Boolean on whether CAN bus is initialized
bool isCanBusInitialized

# Can message id (Declared as 32 bit but only 29 bits are used)
uint32 can_id        

# Extended message Boolean
bool extended_message

# 8 Byte Data field
byte[8]  can_data
