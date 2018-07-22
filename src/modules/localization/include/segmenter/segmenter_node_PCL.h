#ifndef SEGMENTER_NODE_H
#define SEGMENTER_NODE_H

#include <vector>
#include <sstream>

#include "ros/ros.h"
#include <velodyne_puck_msgs/VelodynePuckPoint.h>
#include <velodyne_puck_msgs/VelodynePuckScan.h>
#include <velodyne_puck_msgs/VelodynePuckSweep.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>


class segmenter
{
  public:
    segmenter();
    ~segmenter();
    void initRosComm();
    void publishSegments();

  private:
    ros::NodeHandle segmenter_nh;
    ros::Publisher segmenter_pub;
    ros::Subscriber segmenter_sub;
    void messageCallback(const velodyne_puck_msgs::VelodynePuckSweep::ConstPtr& msg);
    void parseInput(pcl::PointCloud<pcl::PointXYZI>::Ptr& out_cloud, 
                           std::vector<pcl::PointIndices::Ptr>& scan_indices, 
                           const velodyne_puck_msgs::VelodynePuckSweep::ConstPtr& in_cloud);
    void generateOutput(pcl::PointIndices& pts, pcl::PointCloud<pcl::PointXYZI>::Ptr& in_cloud);
};

#endif
