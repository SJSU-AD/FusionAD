#include "vec3.h"
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>

class SegmentProcessor
{
    private:
        pcl::PointCloud<pcl::PointXYZI> point_cloud;
        std::vector<pcl::PointIndices> cluster_indices;

        void CalculateBoundingBox(); //TODO

        pcl::PointXYZI CalculateCentroid(size_t cluster_index);

        double CalculateTheta(const pcl::PointXYZI &p1, const pcl::PointXYZI &p2);

    public:
        struct SegmentedClusters {
            pcl::PointCloud<pcl::PointXYZI>
        };

        SegmentProcessor() {
            point_cloud.header.frame_id = "/velodyne";
            point_cloud.height = 1;
        }

        ~SegmentProcessor();

        std::vector<pcl::PointIndices> GetClusterIndices() 
        {
            return cluster_indices;
        }

        pcl::PointCloud<pcl::PointXYZI> GetPointCloud()
        {
            return point_cloud;
        }

        pcl::PointCloud<pcl::PointXYZI>::Ptr GenerateColoredPointCloud();

        void ExtractIndices(std::vector<Vec3>& clusters);

        void FilterPoints(int min_pts);
        
        bool FindObstacles();

};