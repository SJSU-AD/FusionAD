#include "localization/frame_tf_calibrate/frame_calibration.h"
/*
TODO: Need to test the current logic
      Create static transform node (separate from this one) to broadcast transforms
*/

/*
INPUTS: /gps/geodesy   <-- NOTE: will change later, just works with current bags
        /localization/rotated_yaw

OUTPUTS: /localization/calibrated_x_pose
         /localization/calibrated_y_pose
         /localization/calibrated_yaw
*/

namespace fusionad
{
namespace localization
{
namespace frame_calibration_node
{
    FrameCalibrationNode::FrameCalibrationNode()
    {
    }

    FrameCalibrationNode::~FrameCalibrationNode()
    {
    }

    void FrameCalibrationNode::initRosComm()
    {
        // create timer at 10 Hz
        calibration_timer = frameCalibrationNode_nh.createTimer(ros::Duration(0.1), &FrameCalibrationNode::timerCallback, this);
        
        // publisher for gps position calibration
        calibrated_x_pose_pub = frameCalibrationNode_nh.advertise<std_msgs::Float32>("/localization/calibrated_x_pose", 10);
        calibrated_y_pose_pub = frameCalibrationNode_nh.advertise<std_msgs::Float32>("/localization/calibrated_y_pose", 10);
        
        // publisher for orientation calibration (yaw)
        calibrated_yaw_pub = frameCalibrationNode_nh.advertise<std_msgs::Float32>("/localization/calibrated_yaw", 10);

        // subscriber for gps position calibration
        geodesy_sub = frameCalibrationNode_nh.subscribe("/gps/geodesy", 10, &FrameCalibrationNode::geodesyCallback, this);
        // subscriber for orientation calibration (yaw)
        yaw_sub = frameCalibrationNode_nh.subscribe("/localization/rotated_yaw", 50, &FrameCalibrationNode::yawCallback, this);
    }

    float FrameCalibrationNode::message_calibration(unsigned int& msg_count, float msg_storage[99])
    {
        // if there has been 100 messages collected
        // subtract by 1 because array indexes at zero
        if (msg_count == (MSG_THRESHOLD-1))
        {
            // declare a variable for getting the sum of the values in the array
            float msg_sum = 0;
            // for loop to add each element within the array
            for (int n = 0; n < MSG_THRESHOLD; n++)
            {
                msg_sum += msg_storage[n];
            }
            
            ROS_INFO("Calibration Completed");
            // taking the average of the measurements
            float calibration_value = msg_sum/(MSG_THRESHOLD-1);
            // return the average of the measurements
            return calibration_value;
        }
    }

    void FrameCalibrationNode::yawCallback(const std_msgs::Float32& yaw_msg)
    {
        // if enough samples have been collected
        if (yaw_msg_count < MSG_THRESHOLD)
        {
            ROS_INFO("Collecting Yaw Samples");
            // store the yaw messages into an array
            yaw_msg_storage[yaw_msg_count] = yaw_msg.data;
            // increase the count by 1
            yaw_msg_count += 1;

            //ROS_INFO("Calibrated Yaw = %f", calibrated_yaw);
            // when there has been 100 messages allocated, make bool true for timercallback logic 
            // subtract by 1 because the array indexes at 0
            if (yaw_msg_count == (MSG_THRESHOLD-1))
            {
                // calibrate the messages if the 100 messages have been allocated
                ROS_INFO("Performing Yaw Calibration");
                calibrated_yaw = message_calibration(yaw_msg_count, yaw_msg_storage);
                
                ROS_INFO("Yaw Calibration Completed");
                yaw_msg_calibration_status = true;
            }
        }
    }

    void FrameCalibrationNode::geodesyCallback(const nav_msgs::Odometry& geodesy_msg)
    {
        // if enough samples have been collected
        if (geodesy_msg_count < MSG_THRESHOLD)
        {
            ROS_INFO("Collecting Geodesy Samples");

            // take the x-values from the geodesy_msg
            geodesy_x_msg_storage[geodesy_msg_count] = geodesy_msg.pose.pose.position.x;
            // NOTE: The correct values are being stored

            // take the y-values from the geodesy_msg
            geodesy_y_msg_storage[geodesy_msg_count] = geodesy_msg.pose.pose.position.y;
            
            // increase the count by 1
            geodesy_msg_count += 1;

            // when there has been 100 messages allocated, make bool true for timercallback logic
            // subtract by 1 because array indexes at 0
            if (geodesy_msg_count == (MSG_THRESHOLD-1))
            {
                // calibrating the y-position from geodesy
                ROS_INFO("Performing Y-Position Calibration");
                calibrated_y_pos = message_calibration(geodesy_msg_count, geodesy_y_msg_storage);
                
                // calibrating the x-position from geodesy
                ROS_INFO("Performing X-Position Calibration");
                calibrated_x_pos = message_calibration(geodesy_msg_count, geodesy_x_msg_storage);

                ROS_INFO("Geodesy Position Calibration Completed");
                geodesy_msg_calibration_status = true;
            }
        }
    }

    void FrameCalibrationNode::timerCallback(const ros::TimerEvent& event)
    {
        // if the position and orientation have been calibrated, then publish the values
        if ((geodesy_msg_calibration_status == true) && (yaw_msg_calibration_status == true))
        {
            std_msgs::Float32 calibrated_x_pos_msg; 
            calibrated_x_pos_msg.data = calibrated_x_pos;

            std_msgs::Float32 calibrated_y_pos_msg;
            calibrated_y_pos_msg.data = calibrated_y_pos;

            std_msgs::Float32 calibrated_yaw_msg;
            calibrated_yaw_msg.data = calibrated_yaw;

            calibrated_x_pose_pub.publish(calibrated_x_pos_msg);
            calibrated_y_pose_pub.publish(calibrated_y_pos_msg);
            calibrated_yaw_pub.publish(calibrated_yaw_msg);
        }
    }
}// frame_calibration_node
}// localization
}// fusionad

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Frame_Calibration");
    fusionad::localization::frame_calibration_node::FrameCalibrationNode Frame_Calibration;

    Frame_Calibration.initRosComm();

    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}