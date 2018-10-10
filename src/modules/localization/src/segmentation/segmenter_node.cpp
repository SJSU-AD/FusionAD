#include "std_msgs/Bool.h"
#include "localization/segmentation/point_cloud_segmenter.h"
#include "localization/segmentation/segment_processor.h"
#include "localization/segmentation/segmenter_node.h"

int main(int argc, char** argv) {
  ros::init(argc, argv, "segmenter_node");
  segmenter segmenter_object;
  segmenter_object.InitRosComm();
  ros::Rate loop_rate(2);

  while(ros::ok()) {
    ros::spinOnce();
    loop_rate.sleep();
  }
}

void segmenter::InitRosComm() {
  segmenter_pub = segmenter_nh.advertise<std_msgs::Bool>("/localization/obstacle", 2);
  point_cloud_pub = segmenter_nh.advertise<sensor_msgs::PointCloud2>("/localization/clusters", 2);
  segmenter_sub = segmenter_nh.subscribe("velodyne_sweep", 1, &segmenter::MessageCallback, this);
  ROS_INFO("Subscriber has been set");
}

void segmenter::MessageCallback(const velodyne_puck_msgs::VelodynePuckSweep::ConstPtr& msg) {
  ROS_INFO("Point Cloud Recieved");
  int n_iters = 0;
  int n_lpr = 40;
  int n_segs = 2;
  float seed_thresh = 0.65;
  float dist_thresh = 0.4;

  float th_run = 0.5;
  float th_merge = 1.0;
  int x_max = 35;
  int y_max = 25;
  int z_min = -2;
  int n_scanlines = 16;

  pcl::PointCloud<pcl::PointXYZI>::Ptr final_point_cloud;
  std::vector<pcl::PointIndices> clusters;

  std::vector<Vec3> input_cloud;
  std::vector<Vec3> predicted_clusters;

  PointCloudSegmenter segmenter(x_max, y_max, z_min, n_iters, n_lpr, n_segs, seed_thresh, dist_thresh, n_scanlines, th_run, th_merge);

  //Perform GPF and SLR
  ParseInput(input_cloud, segmenter, msg);
  segmenter.GroundPlaneFitting(input_cloud);
  predicted_clusters = segmenter.ScanLineRun(segmenter.p_all);

  //Filter out clusters with low number of points
  SegmentProcessor seg_processor;
  seg_processor.ExtractIndices(predicted_clusters);
  seg_processor.FilterPoints(20);

  //Naive Obstacle Detection
  std_msgs::Bool obstacle_detected;
  obstacle_detected.data = seg_processor.FindObstacles();
  segmenter_pub.publish(obstacle_detected); 

  //Publish Data
  final_point_cloud = seg_processor.GenerateColoredPointCloud();
  point_cloud_pub.publish(final_point_cloud);
}


void segmenter::ParseInput(std::vector<Vec3>& in, PointCloudSegmenter& seg,  
     			   const velodyne_puck_msgs::VelodynePuckSweep::ConstPtr& cloud) {
  for (int i = 15; i >= 0; i--) {
    Vec3 point;
    velodyne_puck_msgs::VelodynePuckPoint vlp_point;

    for (int j = 0; j < cloud->scans[i].points.size(); j++) {
      vlp_point = cloud->scans[i].points[j];

      if (vlp_point.x < seg.max_x && vlp_point.x > -seg.max_x && vlp_point.y < seg.max_y && vlp_point.y > -seg.max_y && vlp_point.z > seg.min_z) {
        point.x = vlp_point.x;
        point.y = vlp_point.y;
        point.z = vlp_point.z + 3;
        point.intensity = vlp_point.intensity;
        point.theta = vlp_point.azimuth;
        point.label = -1;
        point.scanline = i;

        in.push_back(point);
      }
    } 
  }
}
