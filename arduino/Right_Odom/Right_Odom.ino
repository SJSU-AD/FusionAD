#include <ros.h>
#include <std_msgs/Int32.h>
ros::NodeHandle nh;
std_msgs::Int32 right_odometry_feedback;
// library for high performance reads and writes by jrraines
// see http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1267553811/0
// and http://code.google.com/p/digitalwritefast/

#include <digitalWriteFast.h>
ros::Publisher right_odometry_publisher("/localization/right_encoder_reading", &right_odometry_feedback);

// right right_encoder
// Red - 5V
// Black - GND
const int right_encoder_a = 2; // Green - pin 2 - Digital
const int right_encoder_b = 3; // White - pin 3 - Digital
long right_encoder = 0;
void setup()
{
  // set the baud rate at 115200 baud
  nh.getHardware()->setBaud(115200);
  // initialize the ros node
  nh.initNode();
  
  nh.advertise(right_odometry_publisher);
  // Quadrature right_encoders
  // right right_encoder
  pinMode(right_encoder_a, INPUT_PULLUP);
  pinMode(right_encoder_b, INPUT_PULLUP);

  attachInterrupt(0, right_encoderPinChangeA, RISING);
  attachInterrupt(1, right_encoderPinChangeB, RISING);

}

void loop()
{
  nh.spinOnce();

  right_odometry_feedback.data = right_encoder;
  right_odometry_publisher.publish(&right_odometry_feedback);

  delay(20);
}

// Interrupt service routines for the right motor's quadrature right_encoder
void right_encoderPinChangeA()
{
  //right_encoder += digitalReadFast(right_encoder_a) == digitalReadFast(right_encoder_b) ? -1 : 1;
  right_encoder += digitalReadFast(right_encoder_a) != digitalReadFast(right_encoder_b) ? -1 : 1;
}

void right_encoderPinChangeB()
{
  //right_encoder += digitalReadFast(right_encoder_a) != digitalReadFast(right_encoder_b) ? -1 : 1;
  right_encoder += digitalReadFast(right_encoder_a) == digitalReadFast(right_encoder_b) ? -1 : 1;
}


