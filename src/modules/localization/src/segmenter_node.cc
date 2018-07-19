#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <ctime>
#include "segmenter/point_cloud_segmenter.h"
#include "segmenter/segmenter_node.h"

segmenter::segmenter()
{

}

segmenter::~segmenter()
{

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "segmenter_node");
  segmenter segmenter_object;
  segmenter_object.initRosComm();

  ros::Rate loop_rate(6);

  while(ros::ok())
  {
    ros::spinOnce();

    loop_rate.sleep();
  }
}

void segmenter::initRosComm()
{
  segmenter_pub = segmenter_nh.advertise<sensor_msgs::PointCloud2>("clusters", 10);
  segmenter_sub = segmenter_nh.subscribe("velodyne_sweep", 100, &segmenter::messageCallback, this);
  ROS_INFO("Subscriber has been set");
}

void segmenter::publishSegments()
{
  
}

void segmenter::messageCallback(const velodyne_puck_msgs::VelodynePuckSweep::ConstPtr& msg)
{
  ROS_INFO("Message Recieved");
  int n_iters = 3;
  int n_lpr = 15;
  int n_segs = 2;
  double seed_thresh = 0.2; //meters
  double dist_thresh = 0.1; //meters

  double th_run = 0.6;
  double th_merge = 1.3;
  int x_max = 40;
  int y_max = 40;
  int n_scanlines = 16;

  std::vector<Vec3> input_cloud;
  std::vector<Vec3> predicted_ground;
  std::vector<Vec3> predicted_not_ground;
  std::vector<Vec3> predicted_clusters;

  PointCloudSegmenter segmenter(x_max, y_max, n_iters, n_lpr, n_segs, seed_thresh, dist_thresh, n_scanlines, th_run, th_merge);

  //int time1 = clock();
  parseInput(input_cloud, segmenter, msg);
  //std::cout << "Input size: " << input_cloud.size() << std::endl;

  segmenter.GroundPlaneFitting(input_cloud);

  predicted_ground = segmenter.GetGroundPoints();
  predicted_not_ground = segmenter.GetNonGroundPoints();

  predicted_clusters = segmenter.ScanLineRun(predicted_not_ground);

  generateOutput(predicted_clusters);
  //int time2 = clock();
  //std::cout << "Segmentation runtime: " << (time2 - time1) / double(CLOCKS_PER_SEC) * 1000 << " ms\n" << std::endl;
}


void segmenter::parseInput(std::vector<Vec3>& in, PointCloudSegmenter& seg,  
     			   const velodyne_puck_msgs::VelodynePuckSweep::ConstPtr& cloud)
{
  for (int i = 0; i < 15; i++)
  {
    Vec3 point;
    velodyne_puck_msgs::VelodynePuckPoint vlp_point;

    for (int j = 0; j < cloud->scans[i].points.size(); j++) 
    {
      vlp_point = cloud->scans[i].points[j];
      point.x = vlp_point.x; //(vlp_point.x * std::cos(theta)) + (vlp_point.z * std::sin(theta));
      point.y = vlp_point.y;
      point.z = vlp_point.z + 1; //(vlp_point.x * std::sin(theta)) + (vlp_point.z * std::cos(theta));
      //point.r = vlp_point.distance;
      point.intensity = vlp_point.intensity;
      //point.azimuth = vlp_point.azimuth;
      point.label = -1; //TODO!!
      point.scanline = i;

      //if (point.r > 0) 
      //{
        if (point.x < seg.max_x && point.x > -seg.max_x && point.y < seg.max_y && point.y > -seg.max_y) {
          in.push_back(point); 
        }
      //}
    } 
  }
  
}


void segmenter::generateOutput(std::vector<Vec3>& pts)
{
  std::ofstream file;
  file.open ("test_output.txt"); 
 
  pcl::PointCloud<pcl::PointXYZI>::Ptr point_cloud(
    new pcl::PointCloud<pcl::PointXYZI>());
  point_cloud->header.frame_id = "/velodyne";
  point_cloud->height = 1;

  std::vector<Vec3>::iterator it;

  for (it = pts.begin(); it != pts.end(); it++) {
    pcl::PointXYZI point;
    point.x = it->x;
    point.y = it->y;
    point.z = it->z;
    point.intensity = it->label;
    point_cloud->points.push_back(point);
    ++point_cloud->width;
    file << point.x << " " << point.y << " " << point.z << " " << point.intensity << "\n";
  }

  std::cout << "Out Size: " << point_cloud->width << std::endl;

  segmenter_pub.publish(point_cloud);
  file.close();
}
