#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
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

  ros::Rate loop_rate(5);

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
  int n_lpr = 20;
  int n_segs = 3;
  double seed_thresh = 0.4; //meters
  double dist_thresh = 0.2; //meters

  double th_run = 0.6;
  double th_merge = 1.3;
  int x_max = 30;
  int y_max = 100;
  int n_scanlines = 16;

  std::vector<Vec3> input_cloud;

  std::vector<pcl::PointIndices::Ptr> scan_indices;
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI> ());
  cloud->height = 1;

  pcl::PointIndices predicted_ground;
  std::vector<Vec3> predicted_not_ground;
  std::vector<Vec3> predicted_clusters;

  PointCloudSegmenter segmenter(x_max, y_max, n_iters, n_lpr, n_segs, seed_thresh, dist_thresh, n_scanlines, th_run, th_merge);

  parseInput(cloud, scan_indices, msg);

  //std::cout << "Input size: " << input_cloud.size() << std::endl;

  segmenter.GroundPlaneFitting(cloud);

  predicted_ground = segmenter.GetGroundPoints();
  /*predicted_not_ground = segmenter.GetNonGroundPoints();

  predicted_clusters = segmenter.ScanLineRun(segmenter.p_all);

  generateOutput(predicted_clusters);*/

  generateOutput(predicted_ground, cloud);
}


void segmenter::parseInput(pcl::PointCloud<pcl::PointXYZI>::Ptr& out_cloud, 
                            std::vector<pcl::PointIndices::Ptr>& scan_indices, 
                            const velodyne_puck_msgs::VelodynePuckSweep::ConstPtr& in_cloud)
{
  std::ofstream file;
  int cur_index = 0;

  file.open ("test_output.txt");  

  for (int i = 15; i >= 0; i--)
  {
    pcl::PointXYZI point;
    velodyne_puck_msgs::VelodynePuckPoint vlp_point;
    pcl::PointIndices::Ptr cur_scan (new pcl::PointIndices ());

    for (int j = 0; j < in_cloud->scans[i].points.size(); j++) 
    {
      vlp_point = in_cloud->scans[i].points[j];
      point.x = vlp_point.x; //(vlp_point.x * std::cos(theta)) + (vlp_point.z * std::sin(theta));
      point.y = vlp_point.y;
      point.z = vlp_point.z; //(vlp_point.x * std::sin(theta)) + (vlp_point.z * std::cos(theta));
      point.intensity = vlp_point.intensity;
      //point.azimuth = vlp_point.azimuth;
      //point.label = -1; //TODO!!
      //point.scanline = i;

      if (point.x > -30 || point.x < 30) 
      {
        cur_scan->indices.push_back(cur_index);
        out_cloud->points.push_back(point);
        ++out_cloud->width;
        ++cur_index;

        file << point.x << " " << point.y << " " << point.z << " " << point.intensity << "\n";
      }
    } 

    scan_indices.push_back(cur_scan);
  }

  //std::cout << "Out Size: " << cur_index << std::endl;
  file.close();
}


void segmenter::generateOutput(pcl::PointIndices& pts, pcl::PointCloud<pcl::PointXYZI>::Ptr& in_cloud)
{
  pcl::PointCloud<pcl::PointXYZI>::Ptr point_cloud(new pcl::PointCloud<pcl::PointXYZI>());
  point_cloud->height = 1;

  /*pcl::ExtractIndices<pcl::PointXYZI> extract;
  extract.setInputCloud(in_cloud);
  extract.setIndices(pts);
  extract.filter(*point_cloud);*/

  std::vector<int>::iterator it;

  for (it = pts.indices.begin(); it != pts.indices.end(); it++) {
    pcl::PointXYZI point = in_cloud->points.at(*it);
    //point.intensity = it->label;
    point_cloud->points.push_back(point);
    ++point_cloud->width;
  }

  point_cloud->header.frame_id = "/velodyne";
  std::cout << "Out Size: " << pts.indices.size() << std::endl;

  segmenter_pub.publish(point_cloud);
}
