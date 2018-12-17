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
    FrameCalibrationNode::FrameCalibrationNode(){}

    FrameCalibrationNode::~FrameCalibrationNode(){}

    void FrameCalibrationNode::initRosComm()
    {
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

    void FrameCalibrationNode::yawCallback(const std_msgs::Float32& yaw_msg)
    {
        // Perform while yaw is not calibrated
        if(!yaw_is_calibrated){
            
            ROS_INFO_ONCE("Collecting Yaw Samples");

            // Accumulate samples
            yaw_accumulation += yaw_msg.data;

            // Increment sample counter
            yaw_samples_counter++;

            // Calculate average of samples once threshold is hit
            if(yaw_samples_counter >= MSG_THRESHOLD){

                // Store and calculate calibrated data
                std_msgs::Float32 calibrated_yaw;
                calibrated_yaw.data = yaw_accumulation / yaw_samples_counter;

                // Publish data to /localization/calibrated_yaw
                calibrated_yaw_pub.publish(calibrated_yaw);

                // Yaw is now callibrated
                ROS_INFO("Yaw Calibration Completed");
                yaw_is_calibrated = true;
            }
        }
    }

    void FrameCalibrationNode::geodesyCallback(const nav_msgs::Odometry& geodesy_msg)
    {
        // Perform while geodesy is not calibrated
        if(!geodesy_is_calibrated){
            ROS_INFO_ONCE("Collecting Geodesy Samples");

            // Collect x sample and add to previous samples
            geodesy_x_accumulation += geodesy_msg.pose.pose.position.x;

            // Collect y sample and add to previous samples
            geodesy_y_accumulation += geodesy_msg.pose.pose.position.y;

            // Increment geodesy samples counter
            geodesy_samples_counter++;

            // Calculate average of samples once threshold is hit
            if(geodesy_samples_counter >= MSG_THRESHOLD){
                
                // Declare floats to store averaged data
                std_msgs::Float32 geodesy_calibrated_x;
                std_msgs::Float32 geodesy_calibrated_y;

                // Take average of x and y position samples
                geodesy_calibrated_x.data = geodesy_x_accumulation / geodesy_samples_counter;
                geodesy_calibrated_y.data = geodesy_y_accumulation / geodesy_samples_counter;

                // Publish averaged samples
                calibrated_x_pose_pub.publish(geodesy_calibrated_x);
                calibrated_y_pose_pub.publish(geodesy_calibrated_y);

                // Calibration is complete
                ROS_INFO("Geodesy Position Calibration Completed");
                geodesy_is_calibrated = true;
            }
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