#ifndef COVAR_ROS_H_
#define COVAR_ROS_H_

#include "covar_lol.h"

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>

#include <covar/gen_pose_covar_srv.h>
#include "covar/gen_twist_covar_srv.h"
#include "covar/gen_both_covar_srv.h"

/* Continuing from covar.h, what we want to do here is
 * 1) Instantiate a covar object for each part of the odometry topic
 *    (http://docs.ros.org/melodic/api/nav_msgs/html/msg/Odometry.html)
 *    a) Pose
 *    b) Twist
 * 2) Service a ROS service request for
 *    a) Setting a Pose Covariance 
 *    b) Setting a Twist Covariance
 * 3) Indicate whether the covariance is set, which means we need flags
 *    a) Pose
 *    b) Twist
 * 4) Subscribe to an odometry topic
 * 5) Publish an odometry topic, appending the covariance matrix
 */

class covar_ros
{
    private:
        covar_lol pose_covar;
        covar_lol twist_covar;
        // ntwong0 - instead of rolling with our own double arrays, we'll
        //           use the arrays provided in nav_msgs::Odometry instead
        // double pose_covar_mat[36];
        // double twist_covar_mat[36];

        // \TODO: refactor *_data_points_count and *_data_points_limit
        //        to *_samples_count and *_samples_limit
        uint8_t pose_data_points_count;
        uint8_t twist_data_points_count;
        uint8_t pose_data_points_limit;
        uint8_t twist_data_points_limit;
        bool pose_covar_available;
        bool twist_covar_available;

        nav_msgs::Odometry output_odom_msg;

        ros::Subscriber sub_odom;
        ros::Publisher pub_odom;
        ros::ServiceServer gen_pose_covar;
        ros::ServiceServer gen_twist_covar;
        ros::ServiceServer gen_both_covar;
    
    public:
        covar_ros()
        {
            for (int i = 0; i < 36; i++)
            {
                // pose_covar_mat[i] = 0;
                // twist_covar_mat[i] = 0;
                output_odom_msg.pose.covariance[i] = 0;
                output_odom_msg.twist.covariance[i] = 0;
            }
            pose_data_points_count  = 0;
            twist_data_points_count = 0;
            pose_data_points_limit  = 0;
            twist_data_points_limit = 0;
            pose_covar_available    = false;
            twist_covar_available   = false;
        }

        void input_odom_handler(
                        const nav_msgs::Odometry::ConstPtr& input_odom_msg)
        {
            if(pose_data_points_count++ < pose_data_points_limit)
            {
                double roll, pitch, yaw;
                geometry_msgs::Quaternion tempQuat = 
                    input_odom_msg->pose.pose.orientation;
                tf::Matrix3x3(tf::Quaternion(
                    tempQuat.z, 
                    -tempQuat.x, 
                    -tempQuat.y, 
                    tempQuat.w)).getRPY(roll, pitch, yaw);

                double * pose_data_point = new double[6];
                pose_data_point[0] = input_odom_msg->pose.pose.position.x;
                pose_data_point[1] = input_odom_msg->pose.pose.position.y;
                pose_data_point[2] = input_odom_msg->pose.pose.position.z;
                pose_data_point[3] = roll;
                pose_data_point[4] = pitch;
                pose_data_point[5] = yaw;
                
                pose_covar.insert(pose_data_point);
            }

            if(pose_data_points_count > pose_data_points_limit 
                && pose_data_points_limit > 0)
            {
                pose_data_points_count = 0;
                pose_data_points_limit = 0;
                pose_covar.generate_covar();
                // pose_covar.get_mat(pose_covar_mat);
                pose_covar.get_mat(&(output_odom_msg.pose.covariance));
                pose_covar_available = true;
            }

            if(twist_data_points_count++ < twist_data_points_limit)
            {
                double * twist_data_point = new double[6];
                twist_data_point[0] = input_odom_msg->twist.twist.linear.x;
                twist_data_point[1] = input_odom_msg->twist.twist.linear.y;
                twist_data_point[2] = input_odom_msg->twist.twist.linear.z;
                twist_data_point[3] = 
                                input_odom_msg->twist.twist.angular.x;
                twist_data_point[4] = 
                                input_odom_msg->twist.twist.angular.y;
                twist_data_point[5] = 
                                input_odom_msg->twist.twist.angular.z;
                
                twist_covar.insert(twist_data_point);
            }

            if(twist_data_points_count > twist_data_points_limit 
                && twist_data_points_limit > 0)
            {
                twist_data_points_count = 0;
                twist_data_points_limit = 0;
                twist_covar.generate_covar();
                // twist_covar.get_mat(twist_covar_mat);
                twist_covar.get_mat(&(output_odom_msg.twist.covariance));
                twist_covar_available = true;
            }

            output_odom_msg.header.seq++;
            output_odom_msg.header.stamp = input_odom_msg->header.stamp;
            output_odom_msg.header.frame_id = input_odom_msg->header.frame_id;
            output_odom_msg.child_frame_id = input_odom_msg->child_frame_id;
            output_odom_msg.pose.pose.position.x = input_odom_msg->pose.pose.position.x;
            output_odom_msg.pose.pose.position.y = input_odom_msg->pose.pose.position.y;
            output_odom_msg.pose.pose.position.z = input_odom_msg->pose.pose.position.z;
            output_odom_msg.pose.pose.orientation.x = input_odom_msg->pose.pose.orientation.x;
            output_odom_msg.pose.pose.orientation.y = input_odom_msg->pose.pose.orientation.y;
            output_odom_msg.pose.pose.orientation.z = input_odom_msg->pose.pose.orientation.z;
            output_odom_msg.pose.pose.orientation.w = input_odom_msg->pose.pose.orientation.w;
            output_odom_msg.twist.twist.linear.x = input_odom_msg->twist.twist.linear.x;
            output_odom_msg.twist.twist.linear.y = input_odom_msg->twist.twist.linear.y;
            output_odom_msg.twist.twist.linear.z = input_odom_msg->twist.twist.linear.z;
            output_odom_msg.twist.twist.angular.x = input_odom_msg->twist.twist.angular.x;
            output_odom_msg.twist.twist.angular.y = input_odom_msg->twist.twist.angular.y;
            output_odom_msg.twist.twist.angular.z = input_odom_msg->twist.twist.angular.z;
            
            pub_odom.publish(output_odom_msg);
        }

        // Pulled from ROS Service Tutorial
        //   http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29
        // bool add(beginner_tutorials::AddTwoInts::Request  &req,
        //          beginner_tutorials::AddTwoInts::Response &res)
        // {
        //   res.sum = req.a + req.b;
        //   ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
        //   ROS_INFO("sending back response: [%ld]", (long int)res.sum);
        //   return true;
        // }

        bool gen_pose_covar_cb(
                                covar::gen_pose_covar_srv::Request &req,
                                covar::gen_pose_covar_srv::Response &res)
        {
            pose_data_points_limit = req.pose_sample_limit;
            pose_data_points_count = 0; // likely redundant
            res.ack = 1;
            return true;
        }

        bool gen_twist_covar_cb(
                                covar::gen_twist_covar_srv::Request &req,
                                covar::gen_twist_covar_srv::Response &res)
        {
            twist_data_points_limit = req.twist_sample_limit;
            twist_data_points_count = 0; // likely redundant
            res.ack = 1;
            return true;
        }

        bool gen_both_covar_cb(
                                covar::gen_both_covar_srv::Request &req,
                                covar::gen_both_covar_srv::Response &res)
        {
            pose_data_points_limit = req.pose_sample_limit;
            twist_data_points_limit = req.twist_sample_limit;
            pose_data_points_count = 0;  // likely redundant
            twist_data_points_count = 0; // likely redundant
            res.ack = 1;
            return true;
        }

        // lol http://wiki.ros.org/roscpp_tutorials/Tutorials/UsingClassMethodsAsCallbacks
        bool setup(ros::NodeHandle& nh, std::string& input_odom, 
                    std::string& output_odom)
        {
            pub_odom = nh.advertise<nav_msgs::Odometry>(output_odom, 5);
            
            sub_odom = nh.subscribe<nav_msgs::Odometry>(input_odom, 5, 
                            &covar_ros::input_odom_handler, 
                            this);

            gen_pose_covar  = nh.advertiseService("gen_pose_covar", 
                                    &covar_ros::gen_pose_covar_cb,
                                    this);
            gen_twist_covar = nh.advertiseService("gen_twist_covar", 
                                    &covar_ros::gen_twist_covar_cb,
                                    this);
            gen_both_covar  = nh.advertiseService("gen_both_covar", 
                                    &covar_ros::gen_both_covar_cb,
                                    this);

            return true;
        }

};

#endif // COVAR_ROS_H_
