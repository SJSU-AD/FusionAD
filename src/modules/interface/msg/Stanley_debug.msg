Header header

# Vehicle State
geometry_msgs/Point vehicle_Position
float64 vehicle_heading
float64 vehicle_speed

# Controller Parameter
float64 stanleyGain_p
float64 stanleyGain_d
float64 control_loop_period

# Control Calculation
float64 CrosstrackError                          # CrossTrack Error
float64 headingError 
float64 pathHeading                              # Fitted Path heading
float64 steeringAngle                            # Computed Steering Angle 
float64 CrosstrackError_dot

# Path Information
int32 pathSize
float64 distance_to_wp
int32 currentWPIndex

# Calculation Error Flags
bool crossTrackErrorCalcInvalid
bool headingErrorCalcInvalid
bool steeringAngleCalcInvalid