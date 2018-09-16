// /*
//     Subscribes to raw video images and calculates distance of a face from the center of a screen with the given image.
//     Publishes the distance that was calculated

//     Subscribes to:
//         /raw_USBcamera_images
//     Publishes to:
//         /faceCenter
// */

#include <iostream>
#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "std_msgs/Float32.h"

using namespace cv;
using namespace std;

//Setup for cascade classifier
CascadeClassifier face_cascade;
String frontalFace_cascade = "haarcascade_frontalface_alt.xml"; 

class Subscribe_And_Publish
{
	private:
		ros::Publisher pub;
		image_transport::Subscriber sub;
		std_msgs::Float32 distanceOfFaceFromCenter;

	public:
		Subscribe_And_Publish()
		{
			// Create publisher
			ros::NodeHandle nh;
			pub = nh.advertise<std_msgs::Float32>("/faceCenter", 1000);

			// Subscribes to raw camera images and sends subscribed data to 'getImageAndCalcDistance'
			image_transport::ImageTransport image_trans(nh);
			sub = image_trans.subscribe("/raw_USBcamera_images", 1, &Subscribe_And_Publish::getImageAndCalcDistance, this);
		}

		~Subscribe_And_Publish(){ }

		//Function Declaration
		void getImageAndCalcDistance(const sensor_msgs::ImageConstPtr& msg){
			try
			{
				vector<Rect> faces;
				Mat grayFrame;		
				Mat frame = cv_bridge::toCvShare(msg, "bgr8")->image;
				cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
				face_cascade.detectMultiScale(grayFrame, faces, 1.1, 5, 0|CV_HAAR_SCALE_IMAGE, Size(30,30));

				//Finds x location of center of face with respect to center of image
				for(size_t i = 0; i < faces.size(); i++)
				{
					float locationOfFace = faces[i].x + faces[i].width/2;
					float centerOfScreen = frame.cols/2;

					//Store and publish distance
					distanceOfFaceFromCenter.data = locationOfFace - centerOfScreen;
					ROS_INFO("Data: %f", distanceOfFaceFromCenter.data);
					pub.publish(distanceOfFaceFromCenter);
					rectangle(frame, faces[i], Scalar(255,0,0), 1, 8, 0); 
				}

				imshow("frame", frame);
				waitKey(30);
				
			}
			catch(cv_bridge::Exception &e)
			{
				ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
			}
		}
};

int main(int argc, char **argv){
	
	//Load the cascade. Exit if cascade failed to load
	if(!face_cascade.load(frontalFace_cascade)){
		ROS_ERROR("Failed to load cascade");
		ROS_ERROR("Possibly check path to xml file");
		return -1;
	}

	ros::init(argc, argv, "node_image_interpreter");
	ROS_INFO("node_image_interpreter initialized"); 
	Subscribe_And_Publish interpreter;
	ros::spin();

}
