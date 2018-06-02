;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::BaselineHeading)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'BaselineHeading (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::BASELINEHEADING")
  (make-package "PIKSI_RTK_MSGS::BASELINEHEADING"))

(in-package "ROS")
;;//! \htmlinclude BaselineHeading.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::BaselineHeading
  :super ros::object
  :slots (_header _tow _heading _n_sats _flags ))

(defmethod piksi_rtk_msgs::BaselineHeading
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:tow __tow) 0)
    ((:heading __heading) 0)
    ((:n_sats __n_sats) 0)
    ((:flags __flags) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _tow (round __tow))
   (setq _heading (round __heading))
   (setq _n_sats (round __n_sats))
   (setq _flags (round __flags))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:tow
   (&optional __tow)
   (if __tow (setq _tow __tow)) _tow)
  (:heading
   (&optional __heading)
   (if __heading (setq _heading __heading)) _heading)
  (:n_sats
   (&optional __n_sats)
   (if __n_sats (setq _n_sats __n_sats)) _n_sats)
  (:flags
   (&optional __flags)
   (if __flags (setq _flags __flags)) _flags)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _tow
    4
    ;; uint32 _heading
    4
    ;; uint8 _n_sats
    1
    ;; uint8 _flags
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _tow
       (write-long _tow s)
     ;; uint32 _heading
       (write-long _heading s)
     ;; uint8 _n_sats
       (write-byte _n_sats s)
     ;; uint8 _flags
       (write-byte _flags s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _tow
     (setq _tow (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _heading
     (setq _heading (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _n_sats
     (setq _n_sats (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _flags
     (setq _flags (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::BaselineHeading :md5sum-) "2898fbd48c60846b0ee32eacef99afae")
(setf (get piksi_rtk_msgs::BaselineHeading :datatype-) "piksi_rtk_msgs/BaselineHeading")
(setf (get piksi_rtk_msgs::BaselineHeading :definition-)
      "# This message reports the baseline heading pointing from the base station to the rover relative to True
# North. The full GPS time is given by the preceding MSG GPS TIME with the matching time-of-week
# (tow). It is intended that time-matched RTK mode is used when the base station is moving.

Header header

uint32 tow          # GPS Time of Week [ms].
uint32 heading      # Heading [mdeg].
uint8  n_sats       # Number of satellites used in solution
uint8  flags        # Status flag.


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



(provide :piksi_rtk_msgs/BaselineHeading "2898fbd48c60846b0ee32eacef99afae")


