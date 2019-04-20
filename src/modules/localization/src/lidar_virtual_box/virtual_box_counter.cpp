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
        object_detection_pub = pcProcessingNode_nh.advertise<std_msgs::Bool>("/perception/point_cloud_detection", 10);

        // publisher for segmented colored point cloud
        segment_pub = pcProcessingNode_nh.advertise<sensor_msgs::PointCloud2>("/perception/segmented_cloud", 10);

        // publisher for cluster boundaries and centroid for each segmented cloud
        cluster_bounds_pub = pcProcessingNode_nh.advertise<interface::Cluster_bound_list>("/perception/cluster_locations", 10);

        // subscriber to the lidar
        lidar_sub = pcProcessingNode_nh.subscribe("/velodyne_points", 10, &PcProcessingNode::lidarCallback, this);
    }

    void PcProcessingNode::lidarCallback(const sensor_msgs::PointCloud2& lidar_msg)
    {
        sensor_msgs::PointCloud2 input_pc2_msg = lidar_msg;
        sensor_msgs::PointCloud points_in_box = count_points_in_box(input_pc2_msg);
        if(points_threshold_met)
        {
            segmentation_and_coloration(points_in_box);
        }
    }

    sensor_msgs::PointCloud PcProcessingNode::count_points_in_box(sensor_msgs::PointCloud2& input_msg)
    {
        // pointcloud msg to parse xyz position of points
        sensor_msgs::PointCloud out_cloud;
        sensor_msgs::convertPointCloud2ToPointCloud(input_msg, out_cloud);

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
            points_threshold_met = true;
            std_msgs::Bool points_exceeded_threshold;
            points_exceeded_threshold.data = true;
            object_detection_pub.publish(points_exceeded_threshold);
        }
        else
        {
            points_threshold_met = false;
        }

        return pc_in_box;
    }

    interface::Cluster_bound PcProcessingNode::cluster_bounds_calc(pcl::PointCloud<pcl::PointXYZI> input_seg_cloud)
    {
        interface::Cluster_bound temp_cluster_boundaries;
        
        // calculate the centroid of the point cloud
        Eigen::Vector4f centroid_points;
        pcl::compute3DCentroid(input_seg_cloud, centroid_points);

        // calculate the min and max bounds of the point cloud pt
        pcl::PointXYZI min_3d_bound;
        pcl::PointXYZI max_3d_bound;

        pcl::getMinMax3D(input_seg_cloud, min_3d_bound, max_3d_bound);

        // stuff data into return msg
        temp_cluster_boundaries.centroid_location.x = centroid_points(0);
        temp_cluster_boundaries.centroid_location.y = centroid_points(1);
        temp_cluster_boundaries.centroid_location.z = centroid_points(2);

        temp_cluster_boundaries.min_bound.x = min_3d_bound.x;
        temp_cluster_boundaries.min_bound.y = min_3d_bound.y;
        temp_cluster_boundaries.min_bound.z = min_3d_bound.z;
        
        temp_cluster_boundaries.max_bound.x = max_3d_bound.x;
        temp_cluster_boundaries.max_bound.y = max_3d_bound.y;
        temp_cluster_boundaries.max_bound.z = max_3d_bound.z;

        temp_cluster_boundaries.header.frame_id = "velodyne";
        temp_cluster_boundaries.header.stamp = ros::Time::now();

        return temp_cluster_boundaries;
    }

    bool PcProcessingNode::cluster_size_filter(interface::Cluster_bound input_cluster_bound)
    {
        // check whether the cluster size is within the user defined bounds
        float x_size_lim, y_size_lim, z_size_lim, x_size_min, y_size_min, z_size_min;
    
        pcProcessingNode_nh.getParam("/virtual_box_counter/x_size_lim", x_size_lim);
        pcProcessingNode_nh.getParam("/virtual_box_counter/y_size_lim", y_size_lim);
        pcProcessingNode_nh.getParam("/virtual_box_counter/z_size_lim", z_size_lim);

        pcProcessingNode_nh.getParam("/virtual_box_counter/x_size_min", x_size_min);
        pcProcessingNode_nh.getParam("/virtual_box_counter/y_size_min", y_size_min);
        pcProcessingNode_nh.getParam("/virtual_box_counter/z_size_min", z_size_min);

        int bounds_passing_threshold;
        pcProcessingNode_nh.getParam("/virtual_box_counter/bounds_passing_threshold", bounds_passing_threshold);

        bool cluster_within_bounds;
        int bounds_passed = 0;

        float x_cluster_size = std::abs(input_cluster_bound.max_bound.x - input_cluster_bound.min_bound.x);
        float y_cluster_size = std::abs(input_cluster_bound.max_bound.y - input_cluster_bound.min_bound.y);
        float z_cluster_size = std::abs(input_cluster_bound.max_bound.z - input_cluster_bound.min_bound.z);

        // increase the bounds passed variable by 1 for each condition passed
        if((x_cluster_size >= x_size_min) && (x_cluster_size <= x_size_lim))
        {
            bounds_passed++;
        }
        if((y_cluster_size >= y_size_min) && (y_cluster_size <= y_size_lim))
        {
            bounds_passed++;
        }
        if((z_cluster_size >= z_size_min) && (z_cluster_size <= z_size_lim))
        {
            bounds_passed++;
        }

        if(bounds_passed >= bounds_passing_threshold)
        {
            cluster_within_bounds = true;
        }
        else
        {
            cluster_within_bounds = false;
        }

        return cluster_within_bounds;
    }

    void PcProcessingNode::segmentation_and_coloration(sensor_msgs::PointCloud& points_in_box)
    {
        sensor_msgs::PointCloud2 pc2_in_box;
        sensor_msgs::convertPointCloudToPointCloud2(points_in_box, pc2_in_box);        
        
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

        // Cluster_bounds to store centroid locations and bounding boxes of each point cloud
        interface::Cluster_bound_list cluster_bound_list;

        // variable to change the color of the segmented clusters
        int j = 0;
        
        // count the number of clusters
        int cluster_count = 0;

        // insert each point from the segmented data into a pcl object
        for(std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin(); it != cluster_indices.end(); ++it)
        {
            j++;

            // create message to alter the intensity of the point cloud points
            pcl::PointXYZI pt;

            pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_cluster (new pcl::PointCloud<pcl::PointXYZI>);
            for(std::vector<int>::const_iterator pit = it->indices.begin(); pit != it->indices.end(); ++pit)
            {
                cloud_cluster->points.push_back(filtered_cloud->points[*pit]);

                // add color to the new point cloud points by changing intensity
                pt = filtered_cloud->points[*pit];
                pt.intensity = j;

                colored_point_cloud->points.push_back(pt);
                ++colored_point_cloud->width;
            }

            // calculate the centroid of the point cloud and the boundaries
            interface::Cluster_bound cluster_boundaries = cluster_bounds_calc(*cloud_cluster);
            
            bool cluster_within_bounds = cluster_size_filter(cluster_boundaries);

            if(cluster_within_bounds)
            {
                cluster_bound_list.cluster_bounds.push_back(cluster_boundaries);
                
                // need to calculate cluster bounds out here and perform color calc out here!
                cluster_count++;
            }

            cloud_cluster->width = cloud_cluster->points.size();
            cloud_cluster->height = 1;
            cloud_cluster->is_dense = true;
        }
        
        segment_pub.publish(colored_point_cloud);

        cluster_bound_list.num_clusters = cluster_count;
        cluster_bounds_pub.publish(cluster_bound_list);
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
