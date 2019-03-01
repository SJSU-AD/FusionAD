#include "perception/pc2_to_xyz/pc2_to_xyz.h"

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
        
    }
}
}
}