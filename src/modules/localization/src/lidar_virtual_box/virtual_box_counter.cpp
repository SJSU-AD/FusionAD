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

        segment_pub = pcProcessingNode_nh.advertise<sensor_msgs::PointCloud2>("/perception/segmented_cloud", 10);

        // subscriber to the lidar
        lidar_sub = pcProcessingNode_nh.subscribe("/velodyne_points", 10, &PcProcessingNode::lidarCallback, this);
    }

    void PcProcessingNode::lidarCallback(const sensor_msgs::PointCloud2& lidar_msg)
    {
        // pointcloud msg to parse xyz position of points
        sensor_msgs::PointCloud out_cloud;
        sensor_msgs::convertPointCloud2ToPointCloud(lidar_msg, out_cloud);

        sensor_msgs::PointCloud pc_in_box;
        // sensor_msgs::ChannelFloat32 pc_in_box_channel;
        // geometry_msgs::Point32 pc_in_box_points;
        
        pc_in_box.header = out_cloud.header;

        // get virtual box parameters from launch file
        float x_lower_bound, x_upper_bound, y_lower_bound, y_upper_bound, z_lower_bound, z_upper_bound;

        pcProcessingNode_nh.getParam("/virtual_box_counter/x_lower_bound", x_lower_bound);
        pcProcessingNode_nh.getParam("/virtual_box_counter/x_upper_bound", x_upper_bound);

        pcProcessingNode_nh.getParam("/virtual_box_counter/y_lower_bound", y_lower_bound);
        pcProcessingNode_nh.getParam("/virtual_box_counter/y_upper_bound", y_upper_bound);

        pcProcessingNode_nh.getParam("/virtual_box_counter/z_lower_bound", z_lower_bound);
        pcProcessingNode_nh.getParam("/virtual_box_counter/z_upper_bound", z_upper_bound);

        int points_in_box = 0;

        for(int i = 0; i < out_cloud.points.size(); i++)
        {
            // check for the # of points within the virtual box
            if((out_cloud.points[i].x >= x_lower_bound) && (out_cloud.points[i].x <= x_upper_bound) && 
               (out_cloud.points[i].y >= y_lower_bound) && (out_cloud.points[i].y <= y_upper_bound) && 
               (out_cloud.points[i].z >= z_lower_bound) && (out_cloud.points[i].z <= z_upper_bound))
               {
                    // put the points into a new pointcloud message
                    pc_in_box.points.push_back(out_cloud.points[i]);
                    
                    points_in_box++;                    
               }
        }
        // if the points in box threshold has been met
        int points_in_box_threshold;
        pcProcessingNode_nh.getParam("/virtual_box_counter/points_in_box_threshold", points_in_box_threshold);

        if(points_in_box >= points_in_box_threshold)
        {
            sensor_msgs::PointCloud2 pc2_in_box;
            sensor_msgs::convertPointCloudToPointCloud2(pc_in_box, pc2_in_box);        
            
            pcl::PointCloud<pcl::PointXYZI>::Ptr filtered_cloud (new pcl::PointCloud<pcl::PointXYZI>);

            // convert the pc2 inside the box into usable format for pcl library
            pcl::PCLPointCloud2 pcl_pc2;
            pcl_conversions::toPCL(pc2_in_box, pcl_pc2);
            pcl::fromPCLPointCloud2(pcl_pc2, *filtered_cloud);
    
            // creating the KdTree object for the search method of the extraction
            pcl::search::KdTree<pcl::PointXYZI>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZI>);
            tree->setInputCloud(filtered_cloud);

            std::vector<pcl::PointIndices> cluster_indices;
            pcl::EuclideanClusterExtraction<pcl::PointXYZI> ec;

            float cluster_tolerance;
            pcProcessingNode_nh.getParam("/virtual_box_counter/cluster_tolerance", cluster_tolerance);

            float min_cluster_size;
            pcProcessingNode_nh.getParam("/virtual_box_counter/min_cluster_size", min_cluster_size);

            float max_cluster_size;
            pcProcessingNode_nh.getParam("/virtual_box_counter/max_cluster_size", max_cluster_size);

            ec.setClusterTolerance(cluster_tolerance);
            ec.setMinClusterSize(min_cluster_size);
            ec.setMaxClusterSize(max_cluster_size);
            ec.setSearchMethod(tree);
            ec.setInputCloud(filtered_cloud);
            ec.extract(cluster_indices);

            pcl::PointCloud<pcl::PointXYZI>::Ptr colored_point_cloud(new pcl::PointCloud<pcl::PointXYZI>);
            colored_point_cloud->header.frame_id = "velodyne";
            colored_point_cloud->height = 1;

            // variable to change the color of the segmented clusters
            int j = 0;

            // insert each point from the segmented data into a pcl object
            for(std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin(); it != cluster_indices.end(); ++it)
            {
                j++;

                pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_cluster (new pcl::PointCloud<pcl::PointXYZI>);
                
                for(std::vector<int>::const_iterator pit = it->indices.begin(); pit != it->indices.end(); ++pit)
                {
                    cloud_cluster->points.push_back(filtered_cloud->points[*pit]);
                    
                    pcl::PointXYZI pt = filtered_cloud->points[*pit];
                    pt.intensity = j;
                    colored_point_cloud->points.push_back(pt);
                    ++colored_point_cloud->width;
                }

                cloud_cluster->width = cloud_cluster->points.size();
                cloud_cluster->height = 1;
                cloud_cluster->is_dense = true;
            }
            
            // sensor_msgs::PointCloud2 colored_segmented_pc2;
            // pcl::toROSMsg(*colored_point_cloud, colored_segmented_pc2);
            
            // colored_segmented_pc2.header.stamp = ros::Time::now();
            // segment_pub.publish(colored_segmented_pc2);
            
            pcl::PointCloud<pcl::PointXYZI>::Ptr final_pc;
            final_pc = colored_point_cloud;
            segment_pub.publish(final_pc);

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
