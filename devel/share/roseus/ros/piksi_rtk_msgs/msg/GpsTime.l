;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::GpsTime)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'GpsTime (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::GPSTIME")
  (make-package "PIKSI_RTK_MSGS::GPSTIME"))

(in-package "ROS")
;;//! \htmlinclude GpsTime.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::GpsTime
  :super ros::object
  :slots (_header _wn _tow _ns _flags ))

(defmethod piksi_rtk_msgs::GpsTime
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:wn __wn) 0)
    ((:tow __tow) 0)
    ((:ns __ns) 0)
    ((:flags __flags) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _wn (round __wn))
   (setq _tow (round __tow))
   (setq _ns (round __ns))
   (setq _flags (round __flags))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:wn
   (&optional __wn)
   (if __wn (setq _wn __wn)) _wn)
  (:tow
   (&optional __tow)
   (if __tow (setq _tow __tow)) _tow)
  (:ns
   (&optional __ns)
   (if __ns (setq _ns __ns)) _ns)
  (:flags
   (&optional __flags)
   (if __flags (setq _flags __flags)) _flags)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _wn
    4
    ;; uint32 _tow
    4
    ;; int32 _ns
    4
    ;; uint8 _flags
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _wn
       (write-long _wn s)
     ;; uint32 _tow
       (write-long _tow s)
     ;; int32 _ns
       (write-long _ns s)
     ;; uint8 _flags
       (write-byte _flags s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _wn
     (setq _wn (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _tow
     (setq _tow (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _ns
     (setq _ns (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _flags
     (setq _flags (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::GpsTime :md5sum-) "d960bffb66122e272126ef7f2b6ef072")
(setf (get piksi_rtk_msgs::GpsTime :datatype-) "piksi_rtk_msgs/GpsTime")
(setf (get piksi_rtk_msgs::GpsTime :definition-)
      "# This message reports the GPS time, representing the time since the GPS epoch began on midnight
# January 6, 1980 UTC. GPS time counts the weeks and seconds of the week. The weeks begin at the
# Saturday/Sunday transition. GPS week 0 began at the beginning of the GPS time scale.
# Within each week number, the GPS time of the week is between between 0 and 604800 seconds
# (=60*60*24*7). Note that GPS time does not accumulate leap seconds, and as of now, has a small offset
# from UTC. In a message stream, this message precedes a set of other navigation messages referenced
# to the same time (but lacking the ns field) and indicates a more precise time of these messages.

Header header

uint32 wn   # GPS week number.
uint32 tow  # GPS time of week rounded to the nearest millisecond [ms].
int32 ns    # Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000) [ns].
uint8 flags # Status flags (reserved).

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



(provide :piksi_rtk_msgs/GpsTime "d960bffb66122e272126ef7f2b6ef072")


