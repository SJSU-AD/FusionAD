;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::UartState)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'UartState (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::UARTSTATE")
  (make-package "PIKSI_RTK_MSGS::UARTSTATE"))

(in-package "ROS")
;;//! \htmlinclude UartState.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::UartState
  :super ros::object
  :slots (_header _uart_a_tx_throughput _uart_a_rx_throughput _uart_a_crc_error_count _uart_a_io_error_count _uart_a_tx_buffer_level _uart_a_rx_buffer_level _uart_b_tx_throughput _uart_b_rx_throughput _uart_b_crc_error_count _uart_b_io_error_count _uart_b_tx_buffer_level _uart_b_rx_buffer_level _uart_ftdi_tx_throughput _uart_ftdi_rx_throughput _uart_ftdi_crc_error_count _uart_ftdi_io_error_count _uart_ftdi_tx_buffer_level _uart_ftdi_rx_buffer_level _latency_avg _latency_lmin _latency_lmax _latency_current _obs_period_avg _obs_period_pmin _obs_period_pmax _obs_period_current ))

(defmethod piksi_rtk_msgs::UartState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:uart_a_tx_throughput __uart_a_tx_throughput) 0.0)
    ((:uart_a_rx_throughput __uart_a_rx_throughput) 0.0)
    ((:uart_a_crc_error_count __uart_a_crc_error_count) 0)
    ((:uart_a_io_error_count __uart_a_io_error_count) 0)
    ((:uart_a_tx_buffer_level __uart_a_tx_buffer_level) 0)
    ((:uart_a_rx_buffer_level __uart_a_rx_buffer_level) 0)
    ((:uart_b_tx_throughput __uart_b_tx_throughput) 0.0)
    ((:uart_b_rx_throughput __uart_b_rx_throughput) 0.0)
    ((:uart_b_crc_error_count __uart_b_crc_error_count) 0)
    ((:uart_b_io_error_count __uart_b_io_error_count) 0)
    ((:uart_b_tx_buffer_level __uart_b_tx_buffer_level) 0)
    ((:uart_b_rx_buffer_level __uart_b_rx_buffer_level) 0)
    ((:uart_ftdi_tx_throughput __uart_ftdi_tx_throughput) 0.0)
    ((:uart_ftdi_rx_throughput __uart_ftdi_rx_throughput) 0.0)
    ((:uart_ftdi_crc_error_count __uart_ftdi_crc_error_count) 0)
    ((:uart_ftdi_io_error_count __uart_ftdi_io_error_count) 0)
    ((:uart_ftdi_tx_buffer_level __uart_ftdi_tx_buffer_level) 0)
    ((:uart_ftdi_rx_buffer_level __uart_ftdi_rx_buffer_level) 0)
    ((:latency_avg __latency_avg) 0)
    ((:latency_lmin __latency_lmin) 0)
    ((:latency_lmax __latency_lmax) 0)
    ((:latency_current __latency_current) 0)
    ((:obs_period_avg __obs_period_avg) 0)
    ((:obs_period_pmin __obs_period_pmin) 0)
    ((:obs_period_pmax __obs_period_pmax) 0)
    ((:obs_period_current __obs_period_current) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _uart_a_tx_throughput (float __uart_a_tx_throughput))
   (setq _uart_a_rx_throughput (float __uart_a_rx_throughput))
   (setq _uart_a_crc_error_count (round __uart_a_crc_error_count))
   (setq _uart_a_io_error_count (round __uart_a_io_error_count))
   (setq _uart_a_tx_buffer_level (round __uart_a_tx_buffer_level))
   (setq _uart_a_rx_buffer_level (round __uart_a_rx_buffer_level))
   (setq _uart_b_tx_throughput (float __uart_b_tx_throughput))
   (setq _uart_b_rx_throughput (float __uart_b_rx_throughput))
   (setq _uart_b_crc_error_count (round __uart_b_crc_error_count))
   (setq _uart_b_io_error_count (round __uart_b_io_error_count))
   (setq _uart_b_tx_buffer_level (round __uart_b_tx_buffer_level))
   (setq _uart_b_rx_buffer_level (round __uart_b_rx_buffer_level))
   (setq _uart_ftdi_tx_throughput (float __uart_ftdi_tx_throughput))
   (setq _uart_ftdi_rx_throughput (float __uart_ftdi_rx_throughput))
   (setq _uart_ftdi_crc_error_count (round __uart_ftdi_crc_error_count))
   (setq _uart_ftdi_io_error_count (round __uart_ftdi_io_error_count))
   (setq _uart_ftdi_tx_buffer_level (round __uart_ftdi_tx_buffer_level))
   (setq _uart_ftdi_rx_buffer_level (round __uart_ftdi_rx_buffer_level))
   (setq _latency_avg (round __latency_avg))
   (setq _latency_lmin (round __latency_lmin))
   (setq _latency_lmax (round __latency_lmax))
   (setq _latency_current (round __latency_current))
   (setq _obs_period_avg (round __obs_period_avg))
   (setq _obs_period_pmin (round __obs_period_pmin))
   (setq _obs_period_pmax (round __obs_period_pmax))
   (setq _obs_period_current (round __obs_period_current))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:uart_a_tx_throughput
   (&optional __uart_a_tx_throughput)
   (if __uart_a_tx_throughput (setq _uart_a_tx_throughput __uart_a_tx_throughput)) _uart_a_tx_throughput)
  (:uart_a_rx_throughput
   (&optional __uart_a_rx_throughput)
   (if __uart_a_rx_throughput (setq _uart_a_rx_throughput __uart_a_rx_throughput)) _uart_a_rx_throughput)
  (:uart_a_crc_error_count
   (&optional __uart_a_crc_error_count)
   (if __uart_a_crc_error_count (setq _uart_a_crc_error_count __uart_a_crc_error_count)) _uart_a_crc_error_count)
  (:uart_a_io_error_count
   (&optional __uart_a_io_error_count)
   (if __uart_a_io_error_count (setq _uart_a_io_error_count __uart_a_io_error_count)) _uart_a_io_error_count)
  (:uart_a_tx_buffer_level
   (&optional __uart_a_tx_buffer_level)
   (if __uart_a_tx_buffer_level (setq _uart_a_tx_buffer_level __uart_a_tx_buffer_level)) _uart_a_tx_buffer_level)
  (:uart_a_rx_buffer_level
   (&optional __uart_a_rx_buffer_level)
   (if __uart_a_rx_buffer_level (setq _uart_a_rx_buffer_level __uart_a_rx_buffer_level)) _uart_a_rx_buffer_level)
  (:uart_b_tx_throughput
   (&optional __uart_b_tx_throughput)
   (if __uart_b_tx_throughput (setq _uart_b_tx_throughput __uart_b_tx_throughput)) _uart_b_tx_throughput)
  (:uart_b_rx_throughput
   (&optional __uart_b_rx_throughput)
   (if __uart_b_rx_throughput (setq _uart_b_rx_throughput __uart_b_rx_throughput)) _uart_b_rx_throughput)
  (:uart_b_crc_error_count
   (&optional __uart_b_crc_error_count)
   (if __uart_b_crc_error_count (setq _uart_b_crc_error_count __uart_b_crc_error_count)) _uart_b_crc_error_count)
  (:uart_b_io_error_count
   (&optional __uart_b_io_error_count)
   (if __uart_b_io_error_count (setq _uart_b_io_error_count __uart_b_io_error_count)) _uart_b_io_error_count)
  (:uart_b_tx_buffer_level
   (&optional __uart_b_tx_buffer_level)
   (if __uart_b_tx_buffer_level (setq _uart_b_tx_buffer_level __uart_b_tx_buffer_level)) _uart_b_tx_buffer_level)
  (:uart_b_rx_buffer_level
   (&optional __uart_b_rx_buffer_level)
   (if __uart_b_rx_buffer_level (setq _uart_b_rx_buffer_level __uart_b_rx_buffer_level)) _uart_b_rx_buffer_level)
  (:uart_ftdi_tx_throughput
   (&optional __uart_ftdi_tx_throughput)
   (if __uart_ftdi_tx_throughput (setq _uart_ftdi_tx_throughput __uart_ftdi_tx_throughput)) _uart_ftdi_tx_throughput)
  (:uart_ftdi_rx_throughput
   (&optional __uart_ftdi_rx_throughput)
   (if __uart_ftdi_rx_throughput (setq _uart_ftdi_rx_throughput __uart_ftdi_rx_throughput)) _uart_ftdi_rx_throughput)
  (:uart_ftdi_crc_error_count
   (&optional __uart_ftdi_crc_error_count)
   (if __uart_ftdi_crc_error_count (setq _uart_ftdi_crc_error_count __uart_ftdi_crc_error_count)) _uart_ftdi_crc_error_count)
  (:uart_ftdi_io_error_count
   (&optional __uart_ftdi_io_error_count)
   (if __uart_ftdi_io_error_count (setq _uart_ftdi_io_error_count __uart_ftdi_io_error_count)) _uart_ftdi_io_error_count)
  (:uart_ftdi_tx_buffer_level
   (&optional __uart_ftdi_tx_buffer_level)
   (if __uart_ftdi_tx_buffer_level (setq _uart_ftdi_tx_buffer_level __uart_ftdi_tx_buffer_level)) _uart_ftdi_tx_buffer_level)
  (:uart_ftdi_rx_buffer_level
   (&optional __uart_ftdi_rx_buffer_level)
   (if __uart_ftdi_rx_buffer_level (setq _uart_ftdi_rx_buffer_level __uart_ftdi_rx_buffer_level)) _uart_ftdi_rx_buffer_level)
  (:latency_avg
   (&optional __latency_avg)
   (if __latency_avg (setq _latency_avg __latency_avg)) _latency_avg)
  (:latency_lmin
   (&optional __latency_lmin)
   (if __latency_lmin (setq _latency_lmin __latency_lmin)) _latency_lmin)
  (:latency_lmax
   (&optional __latency_lmax)
   (if __latency_lmax (setq _latency_lmax __latency_lmax)) _latency_lmax)
  (:latency_current
   (&optional __latency_current)
   (if __latency_current (setq _latency_current __latency_current)) _latency_current)
  (:obs_period_avg
   (&optional __obs_period_avg)
   (if __obs_period_avg (setq _obs_period_avg __obs_period_avg)) _obs_period_avg)
  (:obs_period_pmin
   (&optional __obs_period_pmin)
   (if __obs_period_pmin (setq _obs_period_pmin __obs_period_pmin)) _obs_period_pmin)
  (:obs_period_pmax
   (&optional __obs_period_pmax)
   (if __obs_period_pmax (setq _obs_period_pmax __obs_period_pmax)) _obs_period_pmax)
  (:obs_period_current
   (&optional __obs_period_current)
   (if __obs_period_current (setq _obs_period_current __obs_period_current)) _obs_period_current)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _uart_a_tx_throughput
    8
    ;; float64 _uart_a_rx_throughput
    8
    ;; uint16 _uart_a_crc_error_count
    2
    ;; uint16 _uart_a_io_error_count
    2
    ;; uint8 _uart_a_tx_buffer_level
    1
    ;; uint8 _uart_a_rx_buffer_level
    1
    ;; float64 _uart_b_tx_throughput
    8
    ;; float64 _uart_b_rx_throughput
    8
    ;; uint16 _uart_b_crc_error_count
    2
    ;; uint16 _uart_b_io_error_count
    2
    ;; uint8 _uart_b_tx_buffer_level
    1
    ;; uint8 _uart_b_rx_buffer_level
    1
    ;; float64 _uart_ftdi_tx_throughput
    8
    ;; float64 _uart_ftdi_rx_throughput
    8
    ;; uint16 _uart_ftdi_crc_error_count
    2
    ;; uint16 _uart_ftdi_io_error_count
    2
    ;; uint8 _uart_ftdi_tx_buffer_level
    1
    ;; uint8 _uart_ftdi_rx_buffer_level
    1
    ;; int32 _latency_avg
    4
    ;; int32 _latency_lmin
    4
    ;; int32 _latency_lmax
    4
    ;; int32 _latency_current
    4
    ;; int32 _obs_period_avg
    4
    ;; int32 _obs_period_pmin
    4
    ;; int32 _obs_period_pmax
    4
    ;; int32 _obs_period_current
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _uart_a_tx_throughput
       (sys::poke _uart_a_tx_throughput (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _uart_a_rx_throughput
       (sys::poke _uart_a_rx_throughput (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint16 _uart_a_crc_error_count
       (write-word _uart_a_crc_error_count s)
     ;; uint16 _uart_a_io_error_count
       (write-word _uart_a_io_error_count s)
     ;; uint8 _uart_a_tx_buffer_level
       (write-byte _uart_a_tx_buffer_level s)
     ;; uint8 _uart_a_rx_buffer_level
       (write-byte _uart_a_rx_buffer_level s)
     ;; float64 _uart_b_tx_throughput
       (sys::poke _uart_b_tx_throughput (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _uart_b_rx_throughput
       (sys::poke _uart_b_rx_throughput (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint16 _uart_b_crc_error_count
       (write-word _uart_b_crc_error_count s)
     ;; uint16 _uart_b_io_error_count
       (write-word _uart_b_io_error_count s)
     ;; uint8 _uart_b_tx_buffer_level
       (write-byte _uart_b_tx_buffer_level s)
     ;; uint8 _uart_b_rx_buffer_level
       (write-byte _uart_b_rx_buffer_level s)
     ;; float64 _uart_ftdi_tx_throughput
       (sys::poke _uart_ftdi_tx_throughput (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _uart_ftdi_rx_throughput
       (sys::poke _uart_ftdi_rx_throughput (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint16 _uart_ftdi_crc_error_count
       (write-word _uart_ftdi_crc_error_count s)
     ;; uint16 _uart_ftdi_io_error_count
       (write-word _uart_ftdi_io_error_count s)
     ;; uint8 _uart_ftdi_tx_buffer_level
       (write-byte _uart_ftdi_tx_buffer_level s)
     ;; uint8 _uart_ftdi_rx_buffer_level
       (write-byte _uart_ftdi_rx_buffer_level s)
     ;; int32 _latency_avg
       (write-long _latency_avg s)
     ;; int32 _latency_lmin
       (write-long _latency_lmin s)
     ;; int32 _latency_lmax
       (write-long _latency_lmax s)
     ;; int32 _latency_current
       (write-long _latency_current s)
     ;; int32 _obs_period_avg
       (write-long _obs_period_avg s)
     ;; int32 _obs_period_pmin
       (write-long _obs_period_pmin s)
     ;; int32 _obs_period_pmax
       (write-long _obs_period_pmax s)
     ;; int32 _obs_period_current
       (write-long _obs_period_current s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _uart_a_tx_throughput
     (setq _uart_a_tx_throughput (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _uart_a_rx_throughput
     (setq _uart_a_rx_throughput (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint16 _uart_a_crc_error_count
     (setq _uart_a_crc_error_count (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _uart_a_io_error_count
     (setq _uart_a_io_error_count (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _uart_a_tx_buffer_level
     (setq _uart_a_tx_buffer_level (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _uart_a_rx_buffer_level
     (setq _uart_a_rx_buffer_level (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _uart_b_tx_throughput
     (setq _uart_b_tx_throughput (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _uart_b_rx_throughput
     (setq _uart_b_rx_throughput (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint16 _uart_b_crc_error_count
     (setq _uart_b_crc_error_count (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _uart_b_io_error_count
     (setq _uart_b_io_error_count (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _uart_b_tx_buffer_level
     (setq _uart_b_tx_buffer_level (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _uart_b_rx_buffer_level
     (setq _uart_b_rx_buffer_level (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _uart_ftdi_tx_throughput
     (setq _uart_ftdi_tx_throughput (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _uart_ftdi_rx_throughput
     (setq _uart_ftdi_rx_throughput (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint16 _uart_ftdi_crc_error_count
     (setq _uart_ftdi_crc_error_count (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _uart_ftdi_io_error_count
     (setq _uart_ftdi_io_error_count (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _uart_ftdi_tx_buffer_level
     (setq _uart_ftdi_tx_buffer_level (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _uart_ftdi_rx_buffer_level
     (setq _uart_ftdi_rx_buffer_level (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int32 _latency_avg
     (setq _latency_avg (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _latency_lmin
     (setq _latency_lmin (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _latency_lmax
     (setq _latency_lmax (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _latency_current
     (setq _latency_current (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _obs_period_avg
     (setq _obs_period_avg (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _obs_period_pmin
     (setq _obs_period_pmin (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _obs_period_pmax
     (setq _obs_period_pmax (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _obs_period_current
     (setq _obs_period_current (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::UartState :md5sum-) "b8a9b74f69bcd0dbe0830dfb13841e63")
(setf (get piksi_rtk_msgs::UartState :datatype-) "piksi_rtk_msgs/UartState")
(setf (get piksi_rtk_msgs::UartState :definition-)
      "# The UART message reports data latency and throughput of the UART channels providing SBP I/O.
# On the default Piksi configuration, UARTs A and B are used for telemetry radios, but can also be host
# access ports for embedded hosts, or other interfaces in future. The reported percentage values must
# be normalized. Observations latency and period can be used to assess the health of the differential
# corrections link. Latency provides the timeliness of received base observations while the period indicates
# their likelihood of transmission.

Header header

float64 uart_a_tx_throughput      # UART transmit throughput [kB/s].
float64 uart_a_rx_throughput      # UART transmit throughput [kB/s].
uint16 uart_a_crc_error_count     # UART CRC error count.
uint16 uart_a_io_error_count      # UART IO error count.
uint8 uart_a_tx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).
uint8 uart_a_rx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).

float64 uart_b_tx_throughput      # UART transmit throughput [kB/s].
float64 uart_b_rx_throughput      # UART transmit throughput [kB/s].
uint16 uart_b_crc_error_count     # UART CRC error count.
uint16 uart_b_io_error_count      # UART IO error count.
uint8 uart_b_tx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).
uint8 uart_b_rx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).

float64 uart_ftdi_tx_throughput   # UART transmit throughput [kB/s].
float64 uart_ftdi_rx_throughput   # UART receive throughput [kB/s].
uint16 uart_ftdi_crc_error_count  # UART CRC error count.
uint16 uart_ftdi_io_error_count   # UART IO error count.
uint8 uart_ftdi_tx_buffer_level   # UART transmit buffer percentage utilization (ranges from 0 to 255).
uint8 uart_ftdi_rx_buffer_level   # UART receive buffer percentage utilization (ranges from 0 to 255).

int32 latency_avg                 # Average latency [ms].
int32 latency_lmin                # Minimum latency [ms].
int32 latency_lmax                # Maximum latency [ms].
int32 latency_current             # Smoothed estimate of the current latency [ms].

int32 obs_period_avg              # Average period [ms].
int32 obs_period_pmin             # Minimum period [ms].
int32 obs_period_pmax             # Maximum period [ms].
int32 obs_period_current          # Smoothed estimate of the current period [ms].

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :piksi_rtk_msgs/UartState "b8a9b74f69bcd0dbe0830dfb13841e63")


