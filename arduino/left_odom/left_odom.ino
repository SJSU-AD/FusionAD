#include <ros.h>
#include <std_msgs/Int32.h>
ros::NodeHandle nh;
std_msgs::Int32 left_odometry_feedback;

// library for high performance reads and writes by jrraines
// see http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1267553811/0
// and http://code.google.com/p/digitalwritefast/

#include <digitalWriteFast.h>
ros::Publisher left_odometry_publisher("/localization/left_encoder_reading", &left_odometry_feedback);

// Left encoder
// Red - 5V
// Black - GND
const int left_encoder_a = 2; // Green - pin 2 - Digital
const int left_encoder_b = 3; // White - pin 3 - Digital
long left_encoder = 0;
void setup()
{
  // set the baud rate at 115200 baud
  nh.getHardware()->setBaud(115200);
  
  // initialize the ros node
  nh.initNode();
  nh.advertise(left_odometry_publisher);
  // Quadrature left_encoders
  // Left left_encoder
  pinMode(left_encoder_a, INPUT_PULLUP);
  pinMode(left_encoder_b, INPUT_PULLUP);

  attachInterrupt(0, left_encoderPinChangeA, RISING);
  attachInterrupt(1, left_encoderPinChangeB, RISING);

}

void loop()
{
  nh.spinOnce();

  left_odometry_feedback.data = left_encoder;
  left_odometry_publisher.publish(&left_odometry_feedback);

  delay(20);
}

// Interrupt service routines for the left motor's quadrature left_encoder
void left_encoderPinChangeA()
{
  left_encoder += digitalReadFast(left_encoder_a) == digitalReadFast(left_encoder_b) ? -1 : 1;
}

void left_encoderPinChangeB()
{
  left_encoder += digitalReadFast(left_encoder_a) != digitalReadFast(left_encoder_b) ? -1 : 1;
}


