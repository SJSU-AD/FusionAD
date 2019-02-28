#ifndef PC2_TO_XYZ_H
#define PC2_TO_XYZ_H

/*
This node listens to the lidar callback and then segments the point cloud data into
individual clusters with the use of the pcl ros library. A virtual rectangular prism is
created in 3-D space and the program publishes a bool when there is an object within the
virtual rectangular prism.

Subscriber
-----------
Topic: /velodyne_points
            Msg: sensor_msgs::PointCloud2

Publisher
---------
Topic: /perception/point_count_detection
            Msg: std_msgs::Bool
*/

#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/PointCloud.h"
#include "sensor_msgs/point_cloud_conversion.h"
#include "std_msgs/Bool.h"

namespace fusionad
{
namespace localization
{
namespace pc_processing_node
{
class PcProcessingNode
{
    public:
        PcProcessingNode();
        ~PcProcessingNode();
        void initRosComm();
    
    private:
        // initialize nodehandle
        ros::NodeHandle pcProcessingNode_nh;

        // publisher to perception when cluster is identified within virtual box
        ros::Publisher cluster_pub;

        // subscriber to velodyne pointcloud publisher
        ros::Subscriber lidar_sub;

        // callback for lidar 
        void lidarCallback(const sensor_msgs::PointCloud2& lidar_msg);
};
}
}
}

#endif
