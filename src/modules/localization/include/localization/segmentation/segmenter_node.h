#ifndef SEGMENTER_NODE_H
#define SEGMENTER_NODE_H

#include <vector>
#include <sstream>
#include <iostream>
#include <math.h>
#include <ctime>
#include "ros/ros.h"
#include <velodyne_puck_msgs/VelodynePuckPoint.h>
#include <velodyne_puck_msgs/VelodynePuckScan.h>
#include <velodyne_puck_msgs/VelodynePuckSweep.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>

class segmenter
{
  public:
    segmenter(){};
    ~segmenter(){};
    void InitRosComm();

  private:
    ros::NodeHandle segmenter_nh;
    ros::Publisher segmenter_pub;
    ros::Publisher point_cloud_pub;
    ros::Subscriber segmenter_sub;
    void MessageCallback(const velodyne_puck_msgs::VelodynePuckSweep::ConstPtr& msg);
    void ParseInput(std::vector<Vec3>& in, PointCloudSegmenter& seg, 
                    const velodyne_puck_msgs::VelodynePuckSweep::ConstPtr& cloud);
    std::vector<pcl::PointIndices> GenerateOutput(std::vector<Vec3>& pts);
};

#endif
