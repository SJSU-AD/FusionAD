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
    int init_clusters = cluster_indices.size();
    std::vector<pcl::PointIndices>::iterator c_it;
    for (c_it = cluster_indices.begin(); c_it != cluster_indices.end(); c_it++)
    {
        if (c_it->indices.size() < min_pts)
        {
            cluster_indices.erase(c_it);
            --c_it;
        }
    }
    int final_clusters = cluster_indices.size();
}


bool SegmentProcessor::FindObstacles()
{
    pcl::PointXYZI origin;
    origin.x = 0;
    origin.y = 0;

    bool obstacle_detected = false;
    float x_max = 2.5;
    float y_max = 0.7;

    for (size_t i = 0; i < cluster_indices.size(); i++)
    {
        //pcl::PointXYZI centroid = CalculateCentroi(i);
        //double theta = CalculateTheta(centroid, origin);
        int points_in_range = PointsInRange(i, x_max, y_max);
       // double dist = sqrt(centroid.x * centroid.x + centroid.y * centroid.y)

        if(points_in_range > 100)
        {
            obstacle_detected = true;
            std::cout << "Obstacle detected with " << points_in_range << " points" << std::endl;
            return obstacle_detected;
        }
    }
    return obstacle_detected;
}

pcl::PointCloud<pcl::PointXYZI>::Ptr SegmentProcessor::GenerateColoredPointCloud()
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr colored_point_cloud(new pcl::PointCloud<pcl::PointXYZI>());
    colored_point_cloud->header.frame_id = "/velodyne";
    colored_point_cloud->height = 1;

    std::vector<pcl::PointIndices>::iterator c_it;
    std::vector<int>::iterator i_it;
    int i = 0;

    for (c_it = cluster_indices.begin(); c_it != cluster_indices.end(); c_it++, i++)
    {
        //int new_label = rand() % 256;
        for (i_it = c_it->indices.begin(); i_it != c_it->indices.end(); i_it++)
        {
            pcl::PointXYZI pt = point_cloud.points[*i_it];
            pt.intensity = i;
            colored_point_cloud->points.push_back(pt);
            ++colored_point_cloud->width;
        }
    }

    return colored_point_cloud;
}

int SegmentProcessor::PointsInRange(size_t cluster_index, float x, float y) 
{
    std::vector<int>::iterator it;
    std::vector<int> & cur_cluster = cluster_indices[cluster_index].indices;

    int n_pts = 0;

    for(it = cur_cluster.begin(); it != cur_cluster.end(); it++) 
    {
        pcl::PointXYZI cur_pt = point_cloud.points[*it];
        if (cur_pt.x < x && cur_pt.x > 0 && cur_pt.y < y && cur_pt.y > -y && cur_pt.z < 2.0 && cur_pt.z > -0.5 )
        {
            n_pts++;
        }
        //centroid.intensity += cur_pt.intensity;
    }

    return n_pts;
}


pcl::PointXYZI SegmentProcessor::CalculateCentroid(int cluster_index)
{
    std::vector<int>::iterator it;
    std::vector<int> & cur_cluster = cluster_indices[cluster_index].indices;

    pcl::PointXYZI centroid;
    centroid.x = 0;
    centroid.y = 0;
    centroid.x = 0;

    for(it = cur_cluster.begin(); it != cur_cluster.end(); it++) 
    {
        pcl::PointXYZI cur_pt = point_cloud.points[*it];
        centroid.x += cur_pt.x;
        centroid.y += cur_pt.y;
        centroid.x += cur_pt.z;
        //centroid.intensity += cur_pt.intensity;
    }

    int n_points = cur_cluster.size();
    centroid.x /= n_points;
    centroid.y /= n_points;
    centroid.x /= n_points;
    // centroid.intensity /= n_points;

    return centroid;
}


double SegmentProcessor::CalculateTheta(const pcl::PointXYZI &p1, const pcl::PointXYZI &p2)
{
    return (atan2(p1.y - p2.y, p1.x - p2.x) * (180 / PI));
}

void SegmentProcessor::CalculateBoundingBox()
{
    
}
