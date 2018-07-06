# Lane_Detection_Opencv_ROS

CREDIT TO: https://github.com/naruarjun/Lane_Detection_Opencv_ROS

The project publishes frames of a video on the topic chatter, detects lanes using basic image processing and than the coefficients of the lines depicting the lanes are published on a topic called "coeffs"

simpub.py - This is the file used to publish the frames of the video on the topic "chatter"

subscribevideo.py - This is the file used to subscribe to the topic chatter and then calculate the coefficients and then publish them on coeffs

video.msg - Custom message for coefficient publish
