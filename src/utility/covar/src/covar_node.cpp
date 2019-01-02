#include <ros/ros.h>
#include "covar_ros.h"


/** Main node entry point. */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "covar");
    ros::NodeHandle nh;

    covar_ros covar_ros_obj;

    // specify topics
    std::string input_odom = "/integrated_to_init";
    std::string output_odom = "/loam_odom_with_covar";

    if (covar_ros_obj.setup(nh, input_odom, output_odom)) {
        // initialization successful
        ros::spin();
    }

    return 0;
}
