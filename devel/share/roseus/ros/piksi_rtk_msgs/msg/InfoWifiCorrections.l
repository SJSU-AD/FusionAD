;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::InfoWifiCorrections)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'InfoWifiCorrections (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::INFOWIFICORRECTIONS")
  (make-package "PIKSI_RTK_MSGS::INFOWIFICORRECTIONS"))

(in-package "ROS")
;;//! \htmlinclude InfoWifiCorrections.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::InfoWifiCorrections
  :super ros::object
  :slots (_header _received_corrections _latency ))

(defmethod piksi_rtk_msgs::InfoWifiCorrections
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:received_corrections __received_corrections) 0)
    ((:latency __latency) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _received_corrections (round __received_corrections))
   (setq _latency (float __latency))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:received_corrections
   (&optional __received_corrections)
   (if __received_corrections (setq _received_corrections __received_corrections)) _received_corrections)
  (:latency
   (&optional __latency)
   (if __latency (setq _latency __latency)) _latency)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _received_corrections
    4
    ;; float32 _latency
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _received_corrections
       (write-long _received_corrections s)
     ;; float32 _latency
       (sys::poke _latency (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _received_corrections
     (setq _received_corrections (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _latency
     (setq _latency (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::InfoWifiCorrections :md5sum-) "925248c7afa695eb59c83cfd29d8c57c")
(setf (get piksi_rtk_msgs::InfoWifiCorrections :datatype-) "piksi_rtk_msgs/InfoWifiCorrections")
(setf (get piksi_rtk_msgs::InfoWifiCorrections :definition-)
      "# Information about Corrections received over WiFi.

Header header

uint32 received_corrections # number of correction received from start up
float32 latency # latency from base station, -1 if not sampled [ms].

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



(provide :piksi_rtk_msgs/InfoWifiCorrections "925248c7afa695eb59c83cfd29d8c57c")


