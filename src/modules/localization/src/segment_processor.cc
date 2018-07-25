#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>        /* atan2 */
#include "segmenter/segment_processor.h"

#define PI 3.14159265

void SegmentProcessor::ExtractIndices(std::vector<Vec3>& pts)
{
    std::map<int, size_t> label_index_map;
    int cur_point_index = 0;
    size_t cluster_count = 0;

    std::vector<Vec3>::iterator v_it;

    for (v_it = pts.begin(); v_it != pts.end(); v_it++) 
    {
        pcl::PointXYZI point;
        point.x = v_it->x;
        point.y = v_it->y;
        point.z = v_it->z;
        point.intensity = v_it->intensity;

        point_cloud.points.push_back(point);
        ++point_cloud.width;

        std::map<int, size_t>::iterator m_it = label_index_map.find(v_it->label);
        if (m_it != label_index_map.end())
        {
            cluster_indices[(*m_it).second].indices.push_back(cur_point_index);
        } else 
        {
            cluster_indices.resize(cluster_count + 1);
            cluster_indices[cluster_count].indices.push_back(cur_point_index);

            std::pair<int, size_t> label_index_pair;
            label_index_pair.first = v_it->label;
            label_index_pair.second = cluster_count;

            label_index_map.insert(label_index_pair);
            ++cluster_count;
        }
        ++cur_point_index;
    }
}


void SegmentProcessor::FilterPoints(int min_pts)
{
    int init_clusters = cluster_indices.indices.size();
    std::vector<pcl::PointIndices>::iterator c_it;
    for (c_it = cluster_indices.begin(); c_it != cluster_indices.end(); c_it++)
    {
        if (c_it->indices.size() < min_pts)
        {
            cluster_indices.erase(c_it);
            --c_it;
        }
    }
    int final_clusters = cluster_indices.indices.size();
    std::cout << "Removed " << init_clusters - final_clusters << " clusters, " << final_clusters << " remaining." << std::endl;
}


bool SegmentProcessor::FindObstacles()
{
    pcl::PointXYZI origin;
    origin.x, origin.y, origin.z = 0;
    bool obstacle_detected = false;

    double theta_range = 10; // +/- {theta_range} degrees
    double distance_threshold = 2; // meters
    
    for (size_t i = 0; i < cluster_indices.size(); i++)
    {
        pcl::PointXYZI centroid = CalculateCentroid(i);
        double theta = CalculateTheta(centroid, origin);
        double dist = sqrt(centroid.x * centroid.x + centroid.y * centroid.y + centroid.z * centroid.z);

        if(theta > 360 - theta_range || theta < theta_range)
        {
            if (dist < distance_threshold)
            {
                obstacle_detected = true;
            }
        }
    }
    return obstacle_detected;
}

pcl::PointCloud<pcl::PointXYZI>::Ptr SegmentProcessor::GenerateColoredPointCloud()
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr colored_point_cloud(new pcl::PointCloud<pcl::PointXYZI>());
    colored_point_cloud.header.frame_id = "/velodyne";
    colored_point_cloud.height = 1;

    srand (time(NULL));

    std::vector<pcl::PointIndices>::iterator c_it;
    std::vector<int>::iterator i_it;

    for (c_it = cluster_indices.begin(); c_it != cluster_indices.end(); c_it++)
    {
        int new_label = rand() % 256;
        for (i_it = c_it->indices.begin(); i_it != c_it->indices.end(); i_it++)
        {
            pcl::PointXYZI pt = point_cloud.points[*i_it];
            pt.intensity = new_label;
            colored_point_cloud->points.push_back(pt);
            ++colored_point_cloud->width;
        }
    }

    return colored_point_cloud;
}


pcl::PointXYZI SegmentProcessor::CalculateCentroid(size_t cluster_index)
{
    std::vector<int>::iterator it;
    std::vector<int> & cur_cluster = cluster_indices[cluter_index].indices;

    pcl::PointXYZI centroid();

    for(it = cur_cluster.begin(); it != cur_cluster.end(); it++) 
    {
        pcl::PointXYZI cur_pt = point_cloud.points[*it];
        centroid.x += cur_pt.x;
        centroid.y += cur_pt.y;
        centroid.x += cur_pt.z;
        centroid.intensity += cur_pt.intensity;
    }

    int n_points = cur_cluster.size();
    centroid.x /= n_points;
    centroid.y /= n_pointw;
    centroid.x /= n_points;
    centroid.intensity /= n_points;

    return centroid;
}


double SegmentProcessor::CalculateTheta(const pcl::PointXYZI &p1, const pcl::PointXYZI &p2)
{
    return atan2(p2.y - p1.y, p2.x - p1.x) * (180 / PI);
}

void SegmentProcessor::CalculateBoundingBox()
{
    
}
