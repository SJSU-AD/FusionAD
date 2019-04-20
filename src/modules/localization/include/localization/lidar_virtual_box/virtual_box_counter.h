#ifndef VIRTUAL_BOX_COUNTER_H
#define VIRTUAL_BOX_COUNTER_H

/*
This node listens to the lidar callback and then segments the point cloud data into
individual clusters with the use of the pcl ros library. A virtual rectangular prism is
created in 3-D space and the program publishes a bool when there is an object within the
virtual rectangular prism.

An additional feature is segmentation along with centroid and bounding box calculation of 
the segmented clusters.

Segmented clusters are published and colored in the /perception/segmented_cloud topic

Subscriber
-----------
Topic: /velodyne_points
            Msg: sensor_msgs::PointCloud2

Publisher
---------
Topic: /perception/point_count_detection
            Msg: std_msgs::Bool
       
Topic: /perception/segmented_cloud
            Msg: sensor_msgs::PointCloud2

Topic: /perception/cluster_locations
            Msg: interface::Cluster_bound_list
*/

#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/PointCloud.h"
#include "sensor_msgs/point_cloud_conversion.h"
#include "std_msgs/Bool.h"
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/point_types.h>
#include <pcl/conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/common/centroid.h>
#include <interface/Cluster_bound.h>
#include <interface/Cluster_bound_list.h>
#include <pcl/common/common.h>
#include <vector>
#include "Eigen/Dense"

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
        ros::Publisher object_detection_pub;
        ros::Publisher segment_pub;
        ros::Publisher cluster_bounds_pub;

        // subscriber to velodyne pointcloud publisher
        ros::Subscriber lidar_sub;

        bool points_threshold_met = false;

        // callback for lidar 
        void lidarCallback(const sensor_msgs::PointCloud2& lidar_msg);

        // other functions
        sensor_msgs::PointCloud count_points_in_box(sensor_msgs::PointCloud2& input_msg);
        void segmentation_and_coloration(sensor_msgs::PointCloud& points_in_box);
        interface::Cluster_bound cluster_bounds_calc(pcl::PointCloud<pcl::PointXYZI> input_seg_cloud);
        bool cluster_size_filter(interface::Cluster_bound input_cluster_bound);

}; // PcProcessingNode
}  // pc_processing_node
}  // localization
}  // fusionad

#endif
