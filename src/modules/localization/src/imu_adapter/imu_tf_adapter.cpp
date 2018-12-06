#include "localization/imu_adapter/imu_tf_adapter.h"

namespace fusionad
{
namespace localization
{
namespace node
{
    ImuAdapterNode::ImuAdapterNode()
    {
    }

    ImuAdapterNode::~ImuAdapterNode()
    {
    }

    void ImuAdapterNode::initRosComm()
    {
        imu_pub = imuadapter_nh.advertise<sensor_msgs::Imu>("/localization/rotated_imu", 50);
        imu_yaw_pub = imuadapter_nh.advertise<std_msgs::Float32>("/localization/rotated_yaw", 50);
        //imu_original_pub = imuadapter_nh.advertise<std_msgs::Float64>("/originalImu", 50);
        imu_sub = imuadapter_nh.subscribe("/imu", 50, &ImuAdapterNode::imuCallback, this);
    }

    void ImuAdapterNode::imuCallback(const sensor_msgs::Imu& imuMsg)
    {
        // NOTE: rotates the yaw and the pitch such that the razor_9_dof_imu messages adheres to the ROS-105 standards
        //       where yaw = 0 when pointing east. 

        double roll = 0, pitch = 0, yaw = 0, vehicle_heading = 0;
        const float imu_residual_offset = -0.3567612546;
        const float yaw_offset = M_PI_2;

        adaptMsg = imuMsg;
        tf::Quaternion imu_quaternion(imuMsg.orientation.x,
                                      imuMsg.orientation.y,
                                      imuMsg.orientation.z,
                                      imuMsg.orientation.w);
        tf::Matrix3x3 temporary_rot_matrix(imu_quaternion);
        temporary_rot_matrix.getRPY(roll, pitch, yaw);

        float adjusted_yaw = yaw + yaw_offset + imu_residual_offset;
        //float adjusted_yaw = yaw + magnetic_declination_rad;

        if(adjusted_yaw > M_PI)
        {
            vehicle_heading = adjusted_yaw - 2*M_PI;
        }
        else if(adjusted_yaw < (-1)*M_PI)
        {
            vehicle_heading = (2*M_PI) + adjusted_yaw;
        }
        else
        {
            vehicle_heading = adjusted_yaw;
        }

        // pitch multiplied by (-1) to adhere to ROS-105 frame standards
        tf::Quaternion new_imu_quaternion = tf::createQuaternionFromRPY(roll, (-1)*pitch, vehicle_heading);

        adaptMsg.orientation.x = new_imu_quaternion[0];
        adaptMsg.orientation.y = new_imu_quaternion[1];
        adaptMsg.orientation.z = new_imu_quaternion[2];
        adaptMsg.orientation.w = new_imu_quaternion[3];
        
        std_msgs::Float32 odom_yaw_msg;
        odom_yaw_msg.data = vehicle_heading;
        
        imu_yaw_pub.publish(odom_yaw_msg);
        imu_pub.publish(adaptMsg);
    }
}// node
}// localization
}// fusionad

int main(int argc, char **argv)
{
    ros::init(argc, argv, "imuadapternode");
    fusionad::localization::node::ImuAdapterNode imuadapternode;
    
    imuadapternode.initRosComm();

    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}
