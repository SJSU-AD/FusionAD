/***************************************************************************//**
* \file swiftnav_ros_driver.h
*
* \brief ROS Implementation of the C Driver (header)
* \author Josh Kretzmer
* \date June 23, 2017
*
* Adapted from original Swift-Nav Piksi driver authored by:
* Scott K Logan
* Caleb Jamison
*
* API for the ROS driver
*
* \section license License (BSD-3)
* Copyright (c) 2013, Scott K Logan\n
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
* - Neither the name of Willow Garage, Inc. nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#ifndef _swiftnav_ros_driver_hpp
#define _swiftnav_ros_driver_hpp

#include "swiftnav_ros/sbp_device.h"

#include <libsbp/sbp.h>

#include <ros/ros.h>
#include <ros/rate.h>
#include <tf/tf.h>
#include <diagnostic_updater/diagnostic_updater.h>
#include <diagnostic_updater/publisher.h>
#include <diagnostic_updater/update_functions.h>
#include <nav_msgs/Odometry.h>

#include <boost/thread.hpp>

namespace swiftnav_ros
{
	void heartbeat_callback(u16 sender_id, u8 len, u8 msg[], void *context);
	void time_callback(u16 sender_id, u8 len, u8 msg[], void *context);
	void pos_llh_callback(u16 sender_id, u8 len, u8 msg[], void *context);
	void dops_callback(u16 sender_id, u8 len, u8 msg[], void *context);
	void baseline_ned_callback(u16 sender_id, u8 len, u8 msg[], void *context);
	void vel_ned_callback(u16 sender_id, u8 len, u8 msg[], void *context);

	class PIKSI
	{
	public:
		PIKSI( const ros::NodeHandle &_nh = ros::NodeHandle( ),
			const ros::NodeHandle &_nh_priv = ros::NodeHandle( "~" ),
			const std::string _port = "/dev/ttyUSB0" );
		~PIKSI( );
		bool PIKSIOpen( );
		void PIKSIClose( );
	private:
		bool PIKSIOpenNoLock( );
		void PIKSICloseNoLock( );
		void spin( );
		void spinOnce( );
		/*!
		 * \brief Diagnostic update callback
		 *
		 * \author Scott K Logan
		 *
		 * Whenever the diagnostic_updater deems it necessary to update the values
		 * therein, this callback is called to fetch the values from the device.
		 *
		 * \param[out] stat Structure in which to store the values for
		 * diagnostic_updater to report
		 */
		void DiagCB( diagnostic_updater::DiagnosticStatusWrapper &stat );

		ros::NodeHandle nh;
		ros::NodeHandle nh_priv;
		std::string port;
		std::string frame_id;
		int8_t piksid;
		boost::mutex cmd_lock;

		sbp_state_t state;
		sbp_msg_callbacks_node_t heartbeat_callback_node;
		sbp_msg_callbacks_node_t time_callback_node;
//		sbp_msg_callbacks_node_t pos_ecef_callback_node;
		sbp_msg_callbacks_node_t pos_llh_callback_node;
		sbp_msg_callbacks_node_t dops_callback_node;
//		sbp_msg_callbacks_node_t baseline_ecef_callback_node;
		sbp_msg_callbacks_node_t baseline_ned_callback_node;
//		sbp_msg_callbacks_node_t vel_ecef_callback_node;
		sbp_msg_callbacks_node_t vel_ned_callback_node;

		/*
		 * Diagnostic updater
		 */
		diagnostic_updater::Updater heartbeat_diag;
		diagnostic_updater::Updater llh_diag;
		diagnostic_updater::Updater rtk_diag;
		/*
		 * Normal acceptable update rates for LLH, RTK, Heartbeat
		 */
		double min_llh_rate;
		double max_llh_rate;
        double min_rtk_rate;
        double max_rtk_rate;
        double min_heartbeat_rate;
        double max_heartbeat_rate;

		/*!
		 * \brief Diagnostic rate for gps/rtk publication
		 */
		diagnostic_updater::FrequencyStatus llh_pub_freq;
		diagnostic_updater::FrequencyStatus rtk_pub_freq;
		diagnostic_updater::FrequencyStatus heartbeat_pub_freq;

		ros::Publisher llh_pub;
		ros::Publisher rtk_pub;
		ros::Publisher time_pub;

        // Diagnostic Data
		unsigned int io_failure_count;
		unsigned int last_io_failure_count;
		unsigned int open_failure_count;
		unsigned int last_open_failure_count;
        unsigned int heartbeat_flags;       //!< Flags from heartbeat msg
        unsigned int sbp_protocol_version;
        unsigned int num_llh_satellites;   //!< Number of satellites used in llh soln
        unsigned int llh_status;           //!< Flags from POS_LLH message - bit 0: rtk
        double llh_lat;
        double llh_lon;
        double llh_height;
        double llh_h_accuracy;
        double llh_v_accuracy;
        double hdop;

        unsigned int num_rtk_satellites;   //!< Number of satellites used in rtk soln
        unsigned int rtk_status;           //!< Flags from BASELINE_NED message
        double rtk_north;
        double rtk_east;
        double rtk_height;
        double rtk_h_accuracy;
        double rtk_v_accuracy;
        double rtk_vel_north;
        double rtk_vel_east;
        double rtk_vel_down;
        double rtk_vel_v_covariance;
        double rtk_vel_h_covariance;

		ros::Rate spin_rate;
		boost::thread spin_thread;

		friend void heartbeat_callback(u16 sender_id, u8 len, u8 msg[], void *context);
		friend void time_callback(u16 sender_id, u8 len, u8 msg[], void *context);
		friend void pos_llh_callback(u16 sender_id, u8 len, u8 msg[], void *context);
		friend void baseline_ned_callback(u16 sender_id, u8 len, u8 msg[], void *context);
		friend void vel_ned_callback(u16 sender_id, u8 len, u8 msg[], void *context);
	};
}

#endif /* _piksi_driver_hpp */
