Header header

bool debugContoller                  #Debug Boolean

float64 CTE                          #CrossTrack Error
float64 headingError 
float64 pathHeading
float64 est_pathHeading
float64 steeringAngle
float64 CTE_dot

float64 estimated_heading 
float64 imu_heading
float64 imu_transformed_heading

int32 pathSize
float64 distance_to_wp
int32 currentWPIndex

float64 stanleyGain_p
float64 stanleyGain_d

float64 control_loop_period

bool pathHeadingCalcInvalid
bool crossTrackErrorCalcInvalid
bool headingErrorCalcInvalid
bool steeringAngleCalcInvalid