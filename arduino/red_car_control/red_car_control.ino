/* HOW TO USE 
 *  
 * The Arduino is subscribed to ardu_adapter and receives steering + driving values from ardu_adapter
 * These values have already been translated to analog inputs that are applicable to steering and driving
 * To run this code, use the following command
 * $rosrun rosserial_python serial_node.py /dev/ttyACM0
 * Check the USB port and correct for these        ^^^^ if needed
 * 
 * Before use, let the Arduino sit for a minute to balance the Serial Bus buffer. 
 */

 
#include <ros.h>
//#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
//#include <std_msgs/Int32.h>
#include <std_msgs/Int16.h>
ros::NodeHandle nh;

std_msgs::Int16 feedback;
std_msgs::Int16 driving_feedback;
std_msgs::Int16 steering_error_feedback;

// std_msgs::Float64 feedback;
// std_msgs::Float64 driving_feedback;
// std_msgs::Float64 steering_error_feedback;
//std_msgs::Float64 rosinfolog;
////std_msgs::String roswarning;
//std_msgs::Int32 roswarning;

ros::Publisher steering_response("/control/steering_response", &feedback); // publish error instead
ros::Publisher driving_response("/control/driving_response", &driving_feedback);
ros::Publisher steering_error_response("/control/steering_error", &steering_error_feedback);
//ros::Publisher steering_log_response("/control/rosinfo", &rosinfolog);
//ros::Publisher steering_warning_response("/control/warning", &roswarning);

#include <PID_v1.h> // PID LIBRARY 

#define R_EN 12 // ENABLE PIN steering
#define L_EN 13

#define RPWM 6 // inward motion steering
#define LPWM 5 // outward motion steering

#define Motor_R_EN 3 // ENABLE PIN DRIVE
#define Motor_L_EN 4 

#define Motor_RPWM 9 //
#define Motor_LPWM 10

double left_setpoint = 0; // declare ALL the variables
double right_setpoint = 0;
double setpoint = 319;
double input = 0;
double right_output = 0;
double left_output = 0;
double error = 0; 
//double upper_steering_limit = 462;
double upper_steering_limit = 470;
//double lower_steering_limit = 182;
//double lower_steering_limit = 174;
double lower_steering_limit = 82;
double driving_limit = 100;


/* POTENTIOMETER VALUES!!!
   BOUNDS ARE 462 FULL LOCK RIGHT
              319 STRAIGHT
              182  FULL LOCK LEFT
*/

unsigned int Kp = 120; // proportional gain
unsigned int Ki = 1;    // integral gain
unsigned int Kd = 1;  // derivative gain

PID left(&input, &left_output, &left_setpoint, Kp, Ki, Kd, REVERSE); // Turning left is more negative
PID right(&input, &right_output, &right_setpoint, Kp, Ki, Kd, DIRECT); // Turning right is more positive (referencing the pot)

float steering_value = 319;
float driving_value = 0;

unsigned long steering_timestamp = 0;
unsigned long loop_timestamp = 0;
unsigned long time_out = 200;


void drivingcallback(const std_msgs::Int16& driving_msg)
{
  driving_operation(driving_value);
  driving_value = driving_msg.data;
}

void steeringcallback(const std_msgs::Int16& steering_msg)
{
  /*
  nh.loginfo("message received");
  char log_msg[30];
  char steering_msg_string[8];
  dtostrf(steering_msg.data, 6, 2, steering_msg_string);
  sprintf(log_msg, "steering_msg is %s", steering_msg_string);
  nh.loginfo(log_msg);
  */
    // rosinfolog.data = steering_msg.data;
    // steering_log_response.publish(&rosinfolog);
    steering_timestamp = millis();
  
    if (steering_msg.data > upper_steering_limit)
    {
      steering_value = upper_steering_limit;
    }
    else if (steering_msg.data < lower_steering_limit)
    {
      steering_value = lower_steering_limit;
    }
    else
    {
      steering_value = steering_msg.data;
      operation(steering_value);
      unsigned int steering_tolerance = 5;
      
      if(abs(steering_value-(analogRead(0))) < steering_tolerance) // need to rethink requirements of low lvl control on test platform
      {
        // problem could be here?
        no_operation();
      }
      else
      {
        operation(steering_value);
      }
      
    }

    feedback.data = analogRead(0); // feedback.data is equal to the input of the linear actuator
    steering_error_feedback.data = steering_value-feedback.data;
    driving_feedback.data = driving_value; // driving feedback is equal to the driving value (until we have motor feedback)
    driving_response.publish(&driving_feedback); 
    steering_response.publish(&feedback);
    steering_error_response.publish(&steering_error_feedback);    
}

ros::Subscriber<std_msgs::Int16> steering_sub("/control/steering_channel", &steeringcallback); //subscriber initialization
ros::Subscriber<std_msgs::Int16> driving_sub("/control/driving_channel", &drivingcallback); 

void setup() {
  // put your setup code here, to run once:
  // set the baud rate at 115200 baud
  nh.getHardware()->setBaud(115200);
  
  nh.initNode(); // initialize ROS node
  nh.subscribe(steering_sub); // subscriber to ardu_adapter for steering
  nh.subscribe(driving_sub); // subscriber to ardu_adapter for driving
  nh.advertise(steering_response); // publisher to ardu_adapter for steering
  nh.advertise(driving_response); // publisher to ardu_adapter for driving
  nh.advertise(steering_error_response); // publisher for error for PID tuning
  //nh.advertise(steering_log_response);
//  nh.advertise(steering_warning_response);
  pinMode(R_EN, OUTPUT); // initializing enable pins on linear actuator
  pinMode(L_EN, OUTPUT);

  pinMode(RPWM, OUTPUT); // initializing PWM pins on linear actuator
  pinMode(LPWM, OUTPUT);

  pinMode(Motor_R_EN, OUTPUT); // initializing enable pins on motor
  pinMode(Motor_L_EN, OUTPUT);

  pinMode(Motor_RPWM, OUTPUT); // initializing PWM pins on motor
  pinMode(Motor_LPWM, OUTPUT); 

  left.SetMode(AUTOMATIC); // turning on the PID control
  right.SetMode(AUTOMATIC);

  digitalWrite(R_EN, HIGH); // leave these as high to allow steering control operation
  digitalWrite(L_EN, HIGH);

  digitalWrite(Motor_R_EN, HIGH); // leave these as high to allow the motor control operation
  digitalWrite(Motor_L_EN, HIGH);

  nh.loginfo("Startup Complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
  
  loop_timestamp = millis();

  if (abs(loop_timestamp-steering_timestamp)>time_out)
  {
    no_operation();
  }
  
  //delay(1);
}

void operation(double incoming_input)
{
  input = analogRead(0);
  setpoint = incoming_input;
  error = setpoint - input;

  if (error > 0)
  {
    right_operation(setpoint); // turn right
    steering_limits(input);
  }
  else if (error < 0)
  {
    left_operation(setpoint); // turn left
    steering_limits(input);
  }
  else if (error == 0)
  {
    no_operation(); // go straight
  }
}

void right_operation(double right_side_setpoint)
{
  right_setpoint = right_side_setpoint;
  input = analogRead(0);
  steering_limits(input);

  if (input >= right_side_setpoint)
  {
    input = analogRead(0);
    right_setpoint = right_side_setpoint;
    left.SetMode(MANUAL);
    right.SetMode(MANUAL);
    analogWrite(LPWM, 0);
    analogWrite(RPWM, 0);
  }
  else if (input < right_side_setpoint)
  {
    input = analogRead(0);
    right_setpoint = right_side_setpoint;
    left.SetMode(MANUAL);
    right.SetMode(AUTOMATIC);
    right.Compute();
    analogWrite(LPWM, 0);
    analogWrite(RPWM, right_output);

    if (input >= right_side_setpoint)
    {
      input = analogRead(0);
      right_setpoint = right_side_setpoint;
      left.SetMode(MANUAL);
      right.SetMode(MANUAL);
      analogWrite(LPWM, 0);
      analogWrite(RPWM, 0);
    }
  }
}

void left_operation(double left_side_setpoint)
{
  steering_limits(input);
  
  if (input <= left_side_setpoint)
  {
    input = analogRead(0);
    left_setpoint = left_side_setpoint;
    right.SetMode(MANUAL);
    left.SetMode(MANUAL);
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
  }
  else if (input > left_side_setpoint)
  {
    input = analogRead(0);
    left_setpoint = left_side_setpoint;
    right.SetMode(MANUAL);
    left.SetMode(AUTOMATIC);
    left.Compute();
    analogWrite(RPWM, 0);
    analogWrite(LPWM, left_output);

    if (input <= left_side_setpoint)
    {
      input = analogRead(0);
      left_setpoint = left_side_setpoint;
      right.SetMode(MANUAL);
      left.SetMode(MANUAL);
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);
    }
  }
}

void no_operation()
{
  input = analogRead(0);
  right.SetMode(MANUAL);
  left.SetMode(MANUAL);
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
//  //roswarning.data = "no_operation";
//  roswarning.data += 1;
//  steering_warning_response.publish(&roswarning);
}

void driving_operation(double incoming_driving_input)
{
  if (incoming_driving_input > 0)
  {
    forward_drive(incoming_driving_input);
  }
  else if (incoming_driving_input < 0)
  {
    reverse_drive(incoming_driving_input);
  }
  else if (incoming_driving_input == 0)
  {
    braking();
  }
}

void forward_drive(double driving_pwm)
{
  if (driving_pwm <= driving_limit)
  {
    digitalWrite(Motor_R_EN, HIGH);
    digitalWrite(Motor_L_EN, HIGH);
    analogWrite(Motor_LPWM, 0);
    analogWrite(Motor_RPWM, driving_pwm);
  }
  else if (driving_pwm>driving_limit)
  {
    digitalWrite(Motor_R_EN, HIGH);
    digitalWrite(Motor_L_EN, HIGH);
    analogWrite(Motor_LPWM, 0);
    analogWrite(Motor_RPWM, 100);
  }
}

void reverse_drive(double driving_pwm)
{
  if (abs(driving_pwm) <= driving_limit)
  {
    digitalWrite(Motor_R_EN, HIGH);
    digitalWrite(Motor_L_EN, HIGH);
    analogWrite(Motor_LPWM, abs(driving_pwm));
    analogWrite(Motor_RPWM, 0);
  }
  else if (abs(driving_pwm)>driving_limit)
  {
    digitalWrite(Motor_R_EN, HIGH);
    digitalWrite(Motor_L_EN, HIGH);
    analogWrite(Motor_LPWM, 100);
    analogWrite(Motor_RPWM, 0);
  }
}
void braking()
{
  digitalWrite(Motor_R_EN, LOW);
  digitalWrite(Motor_L_EN, LOW);
  analogWrite(Motor_RPWM, 0);
  analogWrite(Motor_LPWM, 0);
}

void steering_limits(double steering_input_limit)
{
  
  if (steering_input_limit >= upper_steering_limit)
  {
    no_operation();
  }
  else if (steering_input_limit <= lower_steering_limit)
  {
    no_operation();
  }
  
}
