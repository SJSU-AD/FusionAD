;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::UartState_V2_3_15)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'UartState_V2_3_15 (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::UARTSTATE_V2_3_15")
  (make-package "PIKSI_RTK_MSGS::UARTSTATE_V2_3_15"))

(in-package "ROS")
;;//! \htmlinclude UartState_V2_3_15.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::UartState_V2_3_15
  :super ros::object
  :slots (_header _latency_avg _latency_lmin _latency_lmax _latency_current _obs_period_avg _obs_period_pmin _obs_period_pmax _obs_period_current ))

(defmethod piksi_rtk_msgs::UartState_V2_3_15
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
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

(setf (get piksi_rtk_msgs::UartState_V2_3_15 :md5sum-) "eab7c26cb7da9615284c0c7450fdcec3")
(setf (get piksi_rtk_msgs::UartState_V2_3_15 :datatype-) "piksi_rtk_msgs/UartState_V2_3_15")
(setf (get piksi_rtk_msgs::UartState_V2_3_15 :definition-)
      "# The UART message reports data latency and throughput of the UART channels providing SBP I/O.

# Message definition based on libsbp v2.3.15, only some field were selected for the original SBP message (same ones
# used in piksi_tools/console/system_monitor_view.py, function \"uart_state_callback\").

Header header

int32 latency_avg               # Average latency [ms].
int32 latency_lmin              # Minimum latency [ms].
int32 latency_lmax              # Maximum latency [ms].
int32 latency_current           # Smoothed estimate of the current latency [ms].
int32 obs_period_avg            # Average period [ms].
int32 obs_period_pmin           # Minimum period [ms].
int32 obs_period_pmax           # Maximum period [ms].
int32 obs_period_current        # Smoothed estimate of the current preiod [ms].

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



(provide :piksi_rtk_msgs/UartState_V2_3_15 "eab7c26cb7da9615284c0c7450fdcec3")


