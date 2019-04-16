#include "localization/lidar_virtual_box/virtual_box_counter.h"

namespace fusionad
{
namespace localization
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
        lidar_sub = pcProcessingNode_nh.subscribe("/velodyne_points", 10, &PcProcessingNode::lidarCallback, this);
    }

    void PcProcessingNode::lidarCallback(const sensor_msgs::PointCloud2& lidar_msg)
    {
        // pointcloud msg to parse xyz position of points
        sensor_msgs::PointCloud out_cloud;
        sensor_msgs::convertPointCloud2ToPointCloud(lidar_msg, out_cloud);

        sensor_msgs::PointCloud pc_in_box;
        pc_in_box.header = out_cloud.header;

        // get virtual box parameters from launch file
        float x_lower_bound, x_upper_bound, y_lower_bound, y_upper_bound, z_lower_bound, z_upper_bound;

        pcProcessingNode_nh.getParam("/virtual_box_counter/x_lower_bound", x_lower_bound);
        pcProcessingNode_nh.getParam("/virtual_box_counter/x_upper_bound", x_upper_bound);

        pcProcessingNode_nh.getParam("/virtual_box_counter/y_lower_bound", y_lower_bound);
        pcProcessingNode_nh.getParam("/virtual_box_counter/y_upper_bound", y_upper_bound);

        pcProcessingNode_nh.getParam("/virtual_box_counter/z_lower_bound", z_lower_bound);
        pcProcessingNode_nh.getParam("/virtual_box_counter/z_upper_bound", z_upper_bound);

        unsigned int points_in_box = 0;
        
        pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud (new pcl::PointCloud<pcl::PointXYZ>);

        for(int i = 0; i < out_cloud.points.size(); i++)
        {
            // check for the # of points within the virtual box
            if((out_cloud.points[i].x >= x_lower_bound) && (out_cloud.points[i].x <= x_upper_bound) && 
               (out_cloud.points[i].y >= y_lower_bound) && (out_cloud.points[i].y <= y_upper_bound) && 
               (out_cloud.points[i].z >= z_lower_bound) && (out_cloud.points[i].z <= z_upper_bound))
               {
                    // put the points into a new pointcloud message
                    pc_in_box.points[points_in_box] = out_cloud.points[i];
                    pc_in_box.channels[points_in_box] = out_cloud.channels[i];
                    points_in_box++;                    
               }
        }

        sensor_msgs::PointCloud2 pc2_in_box;
        sensor_msgs::convertPointCloudToPointCloud2(pc_in_box, pc2_in_box);        

        // convert the pc2 inside the box into usable format for pcl library
        pcl::PCLPointCloud2 pcl_pc2;
        pcl_conversions::toPCL(pc2_in_box, pcl_pc2);
        pcl::fromPCLPointCloud2(pcl_pc2,*filtered_cloud);

        // if the points in box threshold has been met
        int points_in_box_threshold;
        pcProcessingNode_nh.getParam("/virtual_box_counter/points_in_box_threshold", points_in_box_threshold);

        if(points_in_box >= points_in_box_threshold)
        {
            std_msgs::Bool points_exceeded_threshold;
            points_exceeded_threshold.data = true;
            cluster_pub.publish(points_exceeded_threshold);
        }
    }
}// pc_processing_node
}// localization
}// fusionad

int main(int argc, char** argv)
{
    ros::init(argc, argv, "virtual_box_counter");
    fusionad::localization::pc_processing_node::PcProcessingNode virtual_box_counter;

    virtual_box_counter.initRosComm();

    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}
