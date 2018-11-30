#include <PID_v1.h> // PID LIBRARY 

#define R_EN 12 // ENABLE PIN
#define L_EN 13 

#define RPWM 6 // inward motion
#define LPWM 5 // outward motion

double left_setpoint = 0; // declare ALL the variables
double right_setpoint = 0;
double setpoint = 183;
double input = 0;
double right_output = 0;
double left_output = 0;
double incoming = 183;
double incoming_input = 0;
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
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);

  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  left.SetMode(AUTOMATIC);
  right.SetMode(AUTOMATIC);

  digitalWrite(R_EN, HIGH); // leave these as high to allow motor control operation
  digitalWrite(L_EN, HIGH);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    //incoming = Serial.read(); // allow user to test points
    incoming = Serial.parseInt();
    delay(10);
  }
  Serial.println(incoming);
  operation(incoming);
}

void operation(int incoming_input)
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

void right_operation(int right_side_setpoint)
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
    Serial.println(input);
    Serial.println("right stopped");
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
    Serial.println(input);
    Serial.println("right");
    Serial.println("Stuck");
    
    if (input >= right_side_setpoint)
      {
        input = analogRead(0);
        right_setpoint = right_side_setpoint;
        left.SetMode(MANUAL);
        right.SetMode(MANUAL);
        analogWrite(LPWM, 0);
        analogWrite(RPWM, 0);
        Serial.println(input);
        Serial.println("right stopped");
      }
  }
}

void left_operation(int left_side_setpoint)
{
  if (input <= left_side_setpoint)
  {
    input = analogRead(0);
    left_setpoint = left_side_setpoint;
    right.SetMode(MANUAL);
    left.SetMode(MANUAL);
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    Serial.println(input);
    Serial.println("left");
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
    Serial.println(input);
    Serial.println("left");

    if (input <= left_side_setpoint)
    {
      input = analogRead(0);
      left_setpoint = left_side_setpoint;
      right.SetMode(MANUAL);
      left.SetMode(MANUAL);
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);
      Serial.println(input);
      Serial.println("left");
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
  Serial.println(input);
  Serial.println("Straight");
}
