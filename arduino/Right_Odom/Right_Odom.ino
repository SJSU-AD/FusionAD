#include <ros.h>
#include <std_msgs/Int32.h>
ros::NodeHandle nh;
std_msgs::Int32 right_odometry_feedback;

// library for high performance reads and writes by jrraines
// see http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1267553811/0
// and http://code.google.com/p/digitalwritefast/

#include <digitalWriteFast.h>
ros::Publisher right_odometry_publisher("/localization/right_encoder_reading", &right_odometry_feedback);

// right encoder
// Red - 5V
// Black - GND
const int encoder_a = 2; // Green - pin 2 - Digital
const int encoder_b = 3; // White - pin 3 - Digital
long encoder = 0;
void setup()
{
  nh.initNode();
  nh.advertise(right_odometry_publisher);
  // Quadrature encoders
  // right encoder
  pinMode(encoder_a, INPUT_PULLUP);
  pinMode(encoder_b, INPUT_PULLUP);

  attachInterrupt(0, encoderPinChangeA, CHANGE);
  attachInterrupt(1, encoderPinChangeB, CHANGE);

}

void loop()
{
  nh.spinOnce();

  right_odometry_feedback.data = encoder;
  right_odometry_publisher.publish(&right_odometry_feedback);

  delay(20);
}

// Interrupt service routines for the right motor's quadrature encoder
void encoderPinChangeA()
{
  encoder += digitalReadFast(encoder_a) == digitalReadFast(encoder_b) ? -1 : 1;
}

void encoderPinChangeB()
{
  encoder += digitalReadFast(encoder_a) != digitalReadFast(encoder_b) ? -1 : 1;
}


