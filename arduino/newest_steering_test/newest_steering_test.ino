#include <ros.h>
#include <std_msgs/Float64.h>
ros::NodeHandle nh;

float steering_value = 207;
float driving_value = 1;

void drivingcallback(const std_msgs::Float64& driving_msg)
{
  driving_operation(driving_value);
  driving_value = driving_msg.data;
}

void steeringcallback(const std_msgs::Float64& steering_msg)
{
  operation(steering_value);
  steering_value = steering_msg.data;
}

std_msgs::Float64 feedback;
std_msgs::Float64 driving_feedback;

ros::Subscriber<std_msgs::Float64> steering_sub("/control/steering_channel", &steeringcallback); //subscriber initialization
ros::Subscriber<std_msgs::Float64> driving_sub("/control/driving_channel", &drivingcallback); 
ros::Publisher steering_response("/control/steering_response", &feedback); // publish error instead
ros::Publisher driving_response("/control/driving_response", &driving_feedback);

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
double setpoint = 207;
double input = 0;
double right_output = 0;
double left_output = 0;
double wheel_angle = 0;
double error = 0;

/* POTENTIOMETER VALUES!!!
   BOUNDS ARE 350 FULL LOCK LEFT
              207 STRAIGHT
              70  FULL LOCK RIGHT
*/

unsigned int Kp = 6000; // proportional gain
unsigned int Ki = 6;    // integral gain
unsigned int Kd = 200;  // derivative gain

PID left(&input, &left_output, &left_setpoint, Kp, Ki, Kd, REVERSE); // Turning left is more positive
PID right(&input, &right_output, &right_setpoint, Kp, Ki, Kd, DIRECT); // Turning right is more negative (referencing the pot)

void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.subscribe(steering_sub);
  nh.subscribe(driving_sub);
  nh.advertise(steering_response);
  nh.advertise(driving_response);
  
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);

  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  pinMode(Motor_R_EN, OUTPUT);
  pinMode(Motor_L_EN, OUTPUT);

  pinMode(Motor_RPWM, OUTPUT);
  pinMode(Motor_LPWM, OUTPUT);

  left.SetMode(AUTOMATIC);
  right.SetMode(AUTOMATIC);

  digitalWrite(R_EN, HIGH); // leave these as high to allow motor control operation
  digitalWrite(L_EN, HIGH);

  digitalWrite(Motor_R_EN, HIGH);
  digitalWrite(Motor_L_EN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  feedback.data = input;
  driving_feedback.data = driving_value;
  driving_response.publish(&driving_feedback);
  steering_response.publish(&feedback);
  nh.spinOnce();
  delay(20);
}

void operation(double incoming_input)
{
  input = analogRead(0);
  //setpoint = (wheel_angle + 36.15)/.1721; // need to input a desired wheel_angle
  setpoint = incoming_input;
  error = setpoint - input;

  if (error > 0)
  {
    right_operation(setpoint); // turn right
  }

  else if (error < 0)
  {
    left_operation(setpoint); // turn left
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

  if (input >= right_side_setpoint)
  {
    input = analogRead(0);
    right_setpoint = right_side_setpoint;
    left.SetMode(MANUAL);
    right.SetMode(MANUAL);
    analogWrite(LPWM, 0);
    analogWrite(RPWM, 0);
    //Serial.println(input);
    //Serial.println("right stopped");
  }

  //while (input < right_side_setpoint)
  else if (input < right_side_setpoint)
  {
    input = analogRead(0);
    right_setpoint = right_side_setpoint;
    left.SetMode(MANUAL);
    right.SetMode(AUTOMATIC);
    right.Compute();
    analogWrite(LPWM, 0);
    analogWrite(RPWM, right_output);
    //Serial.println(input);
    //Serial.println("right");
    //Serial.println("Stuck");

    if (input >= right_side_setpoint)
    {
      input = analogRead(0);
      right_setpoint = right_side_setpoint;
      left.SetMode(MANUAL);
      right.SetMode(MANUAL);
      analogWrite(LPWM, 0);
      analogWrite(RPWM, 0);
      //Serial.println(input);
      //Serial.println("right stopped");
    }
  }
}

void left_operation(double left_side_setpoint)
{
  if (input <= left_side_setpoint)
  {
    input = analogRead(0);
    left_setpoint = left_side_setpoint;
    right.SetMode(MANUAL);
    left.SetMode(MANUAL);
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    //Serial.println(input);
    //Serial.println("left");
  }

  //while (input > left_side_setpoint)
  else if (input > left_side_setpoint)
  {
    input = analogRead(0);
    left_setpoint = left_side_setpoint;
    right.SetMode(MANUAL);
    left.SetMode(AUTOMATIC);
    left.Compute();
    analogWrite(RPWM, 0);
    analogWrite(LPWM, left_output);
    //Serial.println(input);
    //Serial.println("left");

    if (input <= left_side_setpoint)
    {
      input = analogRead(0);
      left_setpoint = left_side_setpoint;
      right.SetMode(MANUAL);
      left.SetMode(MANUAL);
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);
      // Serial.println(input);
      //Serial.println("left");
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
  //Serial.println(input);
  //Serial.println("Straight");
}

void driving_operation(double incoming_driving_input)
{
  if (incoming_driving_input == 1)
  {
    forward_drive();
  }

  else if (incoming_driving_input == 2)
  {
    reverse_drive();
  }

  else if (incoming_driving_input == 0)
  {
    braking();
  }
}

void forward_drive()
{
  digitalWrite(Motor_R_EN, HIGH);
  digitalWrite(Motor_L_EN, HIGH);
  analogWrite(Motor_LPWM, 100);
  analogWrite(Motor_RPWM, 0);
}

void reverse_drive()
{
  digitalWrite(Motor_R_EN, HIGH);
  digitalWrite(Motor_L_EN, HIGH);
  analogWrite(Motor_LPWM, 0);
  analogWrite(Motor_RPWM, 100);
}
void braking()
{
  digitalWrite(Motor_R_EN, LOW);
  digitalWrite(Motor_L_EN, LOW);
  analogWrite(Motor_RPWM, 0);
  analogWrite(Motor_LPWM, 0);
}

