#include "perception/lidar_virtual_box/virtual_box_counter.h"

namespace fusionad
{
namespace perception
{
namespace pc_processing_node
{

    PcProcessingNode::PcProcessingNode(){}

    PcProcessingNode::~PcProcessingNode(){}

    void PcProcessingNode::initRosComm()
    {
        // publisher for object detected within virtual box
        cluster_pub = pcProcessingNode_nh.advertise<std_msgs::Bool>("/perception/point_cloud_detection", 10);

        // subscriber to the lidar
        lidar_sub = pcProcessingNode_nh.subscribe<sensor_msgs::PointCloud2>("/velodyne_points", 10, &PcProcessingNode::lidarCallback, this);
    }

    void PcProcessingNode::lidarCallback(const sensor_msgs::PointCloud2& lidar_msg)
    {
        // pointcloud msg to parse xyz position of points
        sensor_msgs::PointCloud out_cloud;
        sensor_msgs::convertPointCloud2ToPointCloud(lidar_msg, out_cloud);
        
        // get virtual box parameters from launch file
        float x_lower_bound, x_upper_bound, y_lower_bound, y_upper_bound, z_lower_bound, z_upper_bound;

        pcProcessingNode_nh.getParam("/virtual_box_counter", x_lower_bound);
        pcProcessingNode_nh.getParam("/virtual_box_counter", x_upper_bound);

        pcProcessingNode_nh.getParam("/virtual_box_counter", y_lower_bound);
        pcProcessingNode_nh.getParam("/virtual_box_counter", y_upper_bound);

        pcProcessingNode_nh.getParam("/virtual_box_counter", z_lower_bound);
        pcProcessingNode_nh.getParam("/virtual_box_counter", z_upper_bound);

        unsigned int points_in_box = 0;

        for(int i = 0; out_cloud.points.size(), ++i)
        {
            // check for the # of points within the virtual box
            if(out_cloud.points[i].x >= x_lower_bound && out_cloud.points[i].x <= x_upper_bound && 
               out_cloud.points[i].y >= y_lower_bound && out_cloud.points[i].y <= y_upper_bound && 
               out_cloud.points[i].z >= z_lower_bound && out_cloud.points[i].z <= z_upper_bound)
               {
                   points_in_box++;
               }
        }

        // if the points in box threshold has been met
        unsigned int points_in_box_threshold;
        pcProcessingNode_nh.getParam("/virtual_box_counter", points_in_box_threshold);

        if(points_in_box >= points_in_box_threshold)
        {
            std_msgs::Bool points_exceeded_threshold = true;
            cluster_pub.publish(points_exceeded_threshold)
        }
    }
}// pc_processing_node
}// perception
}// fusionad

int main(int argc, char** argv)
{
    ros::init(argc, argv, "virtual_box_counter");
    fusionad::perception::pc_processing_node::PcProcessingNode virtual_box_counter;

    virtual_box_counter.initRosComm();

    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}
