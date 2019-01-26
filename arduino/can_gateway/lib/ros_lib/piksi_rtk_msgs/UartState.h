#ifndef _ROS_piksi_rtk_msgs_UartState_h
#define _ROS_piksi_rtk_msgs_UartState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class UartState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _uart_a_tx_throughput_type;
      _uart_a_tx_throughput_type uart_a_tx_throughput;
      typedef double _uart_a_rx_throughput_type;
      _uart_a_rx_throughput_type uart_a_rx_throughput;
      typedef uint16_t _uart_a_crc_error_count_type;
      _uart_a_crc_error_count_type uart_a_crc_error_count;
      typedef uint16_t _uart_a_io_error_count_type;
      _uart_a_io_error_count_type uart_a_io_error_count;
      typedef uint8_t _uart_a_tx_buffer_level_type;
      _uart_a_tx_buffer_level_type uart_a_tx_buffer_level;
      typedef uint8_t _uart_a_rx_buffer_level_type;
      _uart_a_rx_buffer_level_type uart_a_rx_buffer_level;
      typedef double _uart_b_tx_throughput_type;
      _uart_b_tx_throughput_type uart_b_tx_throughput;
      typedef double _uart_b_rx_throughput_type;
      _uart_b_rx_throughput_type uart_b_rx_throughput;
      typedef uint16_t _uart_b_crc_error_count_type;
      _uart_b_crc_error_count_type uart_b_crc_error_count;
      typedef uint16_t _uart_b_io_error_count_type;
      _uart_b_io_error_count_type uart_b_io_error_count;
      typedef uint8_t _uart_b_tx_buffer_level_type;
      _uart_b_tx_buffer_level_type uart_b_tx_buffer_level;
      typedef uint8_t _uart_b_rx_buffer_level_type;
      _uart_b_rx_buffer_level_type uart_b_rx_buffer_level;
      typedef double _uart_ftdi_tx_throughput_type;
      _uart_ftdi_tx_throughput_type uart_ftdi_tx_throughput;
      typedef double _uart_ftdi_rx_throughput_type;
      _uart_ftdi_rx_throughput_type uart_ftdi_rx_throughput;
      typedef uint16_t _uart_ftdi_crc_error_count_type;
      _uart_ftdi_crc_error_count_type uart_ftdi_crc_error_count;
      typedef uint16_t _uart_ftdi_io_error_count_type;
      _uart_ftdi_io_error_count_type uart_ftdi_io_error_count;
      typedef uint8_t _uart_ftdi_tx_buffer_level_type;
      _uart_ftdi_tx_buffer_level_type uart_ftdi_tx_buffer_level;
      typedef uint8_t _uart_ftdi_rx_buffer_level_type;
      _uart_ftdi_rx_buffer_level_type uart_ftdi_rx_buffer_level;
      typedef int32_t _latency_avg_type;
      _latency_avg_type latency_avg;
      typedef int32_t _latency_lmin_type;
      _latency_lmin_type latency_lmin;
      typedef int32_t _latency_lmax_type;
      _latency_lmax_type latency_lmax;
      typedef int32_t _latency_current_type;
      _latency_current_type latency_current;
      typedef int32_t _obs_period_avg_type;
      _obs_period_avg_type obs_period_avg;
      typedef int32_t _obs_period_pmin_type;
      _obs_period_pmin_type obs_period_pmin;
      typedef int32_t _obs_period_pmax_type;
      _obs_period_pmax_type obs_period_pmax;
      typedef int32_t _obs_period_current_type;
      _obs_period_current_type obs_period_current;

    UartState():
      header(),
      uart_a_tx_throughput(0),
      uart_a_rx_throughput(0),
      uart_a_crc_error_count(0),
      uart_a_io_error_count(0),
      uart_a_tx_buffer_level(0),
      uart_a_rx_buffer_level(0),
      uart_b_tx_throughput(0),
      uart_b_rx_throughput(0),
      uart_b_crc_error_count(0),
      uart_b_io_error_count(0),
      uart_b_tx_buffer_level(0),
      uart_b_rx_buffer_level(0),
      uart_ftdi_tx_throughput(0),
      uart_ftdi_rx_throughput(0),
      uart_ftdi_crc_error_count(0),
      uart_ftdi_io_error_count(0),
      uart_ftdi_tx_buffer_level(0),
      uart_ftdi_rx_buffer_level(0),
      latency_avg(0),
      latency_lmin(0),
      latency_lmax(0),
      latency_current(0),
      obs_period_avg(0),
      obs_period_pmin(0),
      obs_period_pmax(0),
      obs_period_current(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_uart_a_tx_throughput;
      u_uart_a_tx_throughput.real = this->uart_a_tx_throughput;
      *(outbuffer + offset + 0) = (u_uart_a_tx_throughput.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uart_a_tx_throughput.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uart_a_tx_throughput.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uart_a_tx_throughput.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_uart_a_tx_throughput.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_uart_a_tx_throughput.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_uart_a_tx_throughput.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_uart_a_tx_throughput.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->uart_a_tx_throughput);
      union {
        double real;
        uint64_t base;
      } u_uart_a_rx_throughput;
      u_uart_a_rx_throughput.real = this->uart_a_rx_throughput;
      *(outbuffer + offset + 0) = (u_uart_a_rx_throughput.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uart_a_rx_throughput.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uart_a_rx_throughput.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uart_a_rx_throughput.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_uart_a_rx_throughput.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_uart_a_rx_throughput.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_uart_a_rx_throughput.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_uart_a_rx_throughput.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->uart_a_rx_throughput);
      *(outbuffer + offset + 0) = (this->uart_a_crc_error_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uart_a_crc_error_count >> (8 * 1)) & 0xFF;
      offset += sizeof(this->uart_a_crc_error_count);
      *(outbuffer + offset + 0) = (this->uart_a_io_error_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uart_a_io_error_count >> (8 * 1)) & 0xFF;
      offset += sizeof(this->uart_a_io_error_count);
      *(outbuffer + offset + 0) = (this->uart_a_tx_buffer_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->uart_a_tx_buffer_level);
      *(outbuffer + offset + 0) = (this->uart_a_rx_buffer_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->uart_a_rx_buffer_level);
      union {
        double real;
        uint64_t base;
      } u_uart_b_tx_throughput;
      u_uart_b_tx_throughput.real = this->uart_b_tx_throughput;
      *(outbuffer + offset + 0) = (u_uart_b_tx_throughput.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uart_b_tx_throughput.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uart_b_tx_throughput.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uart_b_tx_throughput.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_uart_b_tx_throughput.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_uart_b_tx_throughput.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_uart_b_tx_throughput.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_uart_b_tx_throughput.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->uart_b_tx_throughput);
      union {
        double real;
        uint64_t base;
      } u_uart_b_rx_throughput;
      u_uart_b_rx_throughput.real = this->uart_b_rx_throughput;
      *(outbuffer + offset + 0) = (u_uart_b_rx_throughput.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uart_b_rx_throughput.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uart_b_rx_throughput.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uart_b_rx_throughput.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_uart_b_rx_throughput.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_uart_b_rx_throughput.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_uart_b_rx_throughput.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_uart_b_rx_throughput.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->uart_b_rx_throughput);
      *(outbuffer + offset + 0) = (this->uart_b_crc_error_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uart_b_crc_error_count >> (8 * 1)) & 0xFF;
      offset += sizeof(this->uart_b_crc_error_count);
      *(outbuffer + offset + 0) = (this->uart_b_io_error_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uart_b_io_error_count >> (8 * 1)) & 0xFF;
      offset += sizeof(this->uart_b_io_error_count);
      *(outbuffer + offset + 0) = (this->uart_b_tx_buffer_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->uart_b_tx_buffer_level);
      *(outbuffer + offset + 0) = (this->uart_b_rx_buffer_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->uart_b_rx_buffer_level);
      union {
        double real;
        uint64_t base;
      } u_uart_ftdi_tx_throughput;
      u_uart_ftdi_tx_throughput.real = this->uart_ftdi_tx_throughput;
      *(outbuffer + offset + 0) = (u_uart_ftdi_tx_throughput.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uart_ftdi_tx_throughput.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uart_ftdi_tx_throughput.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uart_ftdi_tx_throughput.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_uart_ftdi_tx_throughput.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_uart_ftdi_tx_throughput.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_uart_ftdi_tx_throughput.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_uart_ftdi_tx_throughput.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->uart_ftdi_tx_throughput);
      union {
        double real;
        uint64_t base;
      } u_uart_ftdi_rx_throughput;
      u_uart_ftdi_rx_throughput.real = this->uart_ftdi_rx_throughput;
      *(outbuffer + offset + 0) = (u_uart_ftdi_rx_throughput.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uart_ftdi_rx_throughput.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uart_ftdi_rx_throughput.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uart_ftdi_rx_throughput.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_uart_ftdi_rx_throughput.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_uart_ftdi_rx_throughput.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_uart_ftdi_rx_throughput.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_uart_ftdi_rx_throughput.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->uart_ftdi_rx_throughput);
      *(outbuffer + offset + 0) = (this->uart_ftdi_crc_error_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uart_ftdi_crc_error_count >> (8 * 1)) & 0xFF;
      offset += sizeof(this->uart_ftdi_crc_error_count);
      *(outbuffer + offset + 0) = (this->uart_ftdi_io_error_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uart_ftdi_io_error_count >> (8 * 1)) & 0xFF;
      offset += sizeof(this->uart_ftdi_io_error_count);
      *(outbuffer + offset + 0) = (this->uart_ftdi_tx_buffer_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->uart_ftdi_tx_buffer_level);
      *(outbuffer + offset + 0) = (this->uart_ftdi_rx_buffer_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->uart_ftdi_rx_buffer_level);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_avg;
      u_latency_avg.real = this->latency_avg;
      *(outbuffer + offset + 0) = (u_latency_avg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency_avg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency_avg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency_avg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency_avg);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_lmin;
      u_latency_lmin.real = this->latency_lmin;
      *(outbuffer + offset + 0) = (u_latency_lmin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency_lmin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency_lmin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency_lmin.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency_lmin);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_lmax;
      u_latency_lmax.real = this->latency_lmax;
      *(outbuffer + offset + 0) = (u_latency_lmax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency_lmax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency_lmax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency_lmax.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency_lmax);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_current;
      u_latency_current.real = this->latency_current;
      *(outbuffer + offset + 0) = (u_latency_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency_current);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_avg;
      u_obs_period_avg.real = this->obs_period_avg;
      *(outbuffer + offset + 0) = (u_obs_period_avg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_period_avg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_period_avg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_period_avg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_period_avg);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_pmin;
      u_obs_period_pmin.real = this->obs_period_pmin;
      *(outbuffer + offset + 0) = (u_obs_period_pmin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_period_pmin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_period_pmin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_period_pmin.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_period_pmin);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_pmax;
      u_obs_period_pmax.real = this->obs_period_pmax;
      *(outbuffer + offset + 0) = (u_obs_period_pmax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_period_pmax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_period_pmax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_period_pmax.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_period_pmax);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_current;
      u_obs_period_current.real = this->obs_period_current;
      *(outbuffer + offset + 0) = (u_obs_period_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_period_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_period_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_period_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_period_current);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_uart_a_tx_throughput;
      u_uart_a_tx_throughput.base = 0;
      u_uart_a_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uart_a_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uart_a_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uart_a_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_uart_a_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_uart_a_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_uart_a_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_uart_a_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->uart_a_tx_throughput = u_uart_a_tx_throughput.real;
      offset += sizeof(this->uart_a_tx_throughput);
      union {
        double real;
        uint64_t base;
      } u_uart_a_rx_throughput;
      u_uart_a_rx_throughput.base = 0;
      u_uart_a_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uart_a_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uart_a_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uart_a_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_uart_a_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_uart_a_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_uart_a_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_uart_a_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->uart_a_rx_throughput = u_uart_a_rx_throughput.real;
      offset += sizeof(this->uart_a_rx_throughput);
      this->uart_a_crc_error_count =  ((uint16_t) (*(inbuffer + offset)));
      this->uart_a_crc_error_count |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->uart_a_crc_error_count);
      this->uart_a_io_error_count =  ((uint16_t) (*(inbuffer + offset)));
      this->uart_a_io_error_count |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->uart_a_io_error_count);
      this->uart_a_tx_buffer_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->uart_a_tx_buffer_level);
      this->uart_a_rx_buffer_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->uart_a_rx_buffer_level);
      union {
        double real;
        uint64_t base;
      } u_uart_b_tx_throughput;
      u_uart_b_tx_throughput.base = 0;
      u_uart_b_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uart_b_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uart_b_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uart_b_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_uart_b_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_uart_b_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_uart_b_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_uart_b_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->uart_b_tx_throughput = u_uart_b_tx_throughput.real;
      offset += sizeof(this->uart_b_tx_throughput);
      union {
        double real;
        uint64_t base;
      } u_uart_b_rx_throughput;
      u_uart_b_rx_throughput.base = 0;
      u_uart_b_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uart_b_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uart_b_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uart_b_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_uart_b_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_uart_b_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_uart_b_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_uart_b_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->uart_b_rx_throughput = u_uart_b_rx_throughput.real;
      offset += sizeof(this->uart_b_rx_throughput);
      this->uart_b_crc_error_count =  ((uint16_t) (*(inbuffer + offset)));
      this->uart_b_crc_error_count |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->uart_b_crc_error_count);
      this->uart_b_io_error_count =  ((uint16_t) (*(inbuffer + offset)));
      this->uart_b_io_error_count |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->uart_b_io_error_count);
      this->uart_b_tx_buffer_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->uart_b_tx_buffer_level);
      this->uart_b_rx_buffer_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->uart_b_rx_buffer_level);
      union {
        double real;
        uint64_t base;
      } u_uart_ftdi_tx_throughput;
      u_uart_ftdi_tx_throughput.base = 0;
      u_uart_ftdi_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uart_ftdi_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uart_ftdi_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uart_ftdi_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_uart_ftdi_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_uart_ftdi_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_uart_ftdi_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_uart_ftdi_tx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->uart_ftdi_tx_throughput = u_uart_ftdi_tx_throughput.real;
      offset += sizeof(this->uart_ftdi_tx_throughput);
      union {
        double real;
        uint64_t base;
      } u_uart_ftdi_rx_throughput;
      u_uart_ftdi_rx_throughput.base = 0;
      u_uart_ftdi_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uart_ftdi_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uart_ftdi_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uart_ftdi_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_uart_ftdi_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_uart_ftdi_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_uart_ftdi_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_uart_ftdi_rx_throughput.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->uart_ftdi_rx_throughput = u_uart_ftdi_rx_throughput.real;
      offset += sizeof(this->uart_ftdi_rx_throughput);
      this->uart_ftdi_crc_error_count =  ((uint16_t) (*(inbuffer + offset)));
      this->uart_ftdi_crc_error_count |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->uart_ftdi_crc_error_count);
      this->uart_ftdi_io_error_count =  ((uint16_t) (*(inbuffer + offset)));
      this->uart_ftdi_io_error_count |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->uart_ftdi_io_error_count);
      this->uart_ftdi_tx_buffer_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->uart_ftdi_tx_buffer_level);
      this->uart_ftdi_rx_buffer_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->uart_ftdi_rx_buffer_level);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_avg;
      u_latency_avg.base = 0;
      u_latency_avg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency_avg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency_avg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency_avg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency_avg = u_latency_avg.real;
      offset += sizeof(this->latency_avg);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_lmin;
      u_latency_lmin.base = 0;
      u_latency_lmin.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency_lmin.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency_lmin.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency_lmin.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency_lmin = u_latency_lmin.real;
      offset += sizeof(this->latency_lmin);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_lmax;
      u_latency_lmax.base = 0;
      u_latency_lmax.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency_lmax.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency_lmax.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency_lmax.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency_lmax = u_latency_lmax.real;
      offset += sizeof(this->latency_lmax);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_current;
      u_latency_current.base = 0;
      u_latency_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency_current = u_latency_current.real;
      offset += sizeof(this->latency_current);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_avg;
      u_obs_period_avg.base = 0;
      u_obs_period_avg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_period_avg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_period_avg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_period_avg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_period_avg = u_obs_period_avg.real;
      offset += sizeof(this->obs_period_avg);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_pmin;
      u_obs_period_pmin.base = 0;
      u_obs_period_pmin.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_period_pmin.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_period_pmin.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_period_pmin.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_period_pmin = u_obs_period_pmin.real;
      offset += sizeof(this->obs_period_pmin);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_pmax;
      u_obs_period_pmax.base = 0;
      u_obs_period_pmax.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_period_pmax.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_period_pmax.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_period_pmax.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_period_pmax = u_obs_period_pmax.real;
      offset += sizeof(this->obs_period_pmax);
      union {
        int32_t real;
        uint32_t base;
      } u_obs_period_current;
      u_obs_period_current.base = 0;
      u_obs_period_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_period_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_period_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_period_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_period_current = u_obs_period_current.real;
      offset += sizeof(this->obs_period_current);
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/UartState"; };
    const char * getMD5(){ return "b8a9b74f69bcd0dbe0830dfb13841e63"; };

  };

}
#endif