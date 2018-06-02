;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::PosEcef)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'PosEcef (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::POSECEF")
  (make-package "PIKSI_RTK_MSGS::POSECEF"))

(in-package "ROS")
;;//! \htmlinclude PosEcef.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::PosEcef
  :super ros::object
  :slots (_header _tow _x _y _z _accuracy _n_sats _flags ))

(defmethod piksi_rtk_msgs::PosEcef
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:tow __tow) 0)
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:accuracy __accuracy) 0)
    ((:n_sats __n_sats) 0)
    ((:flags __flags) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _tow (round __tow))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _accuracy (round __accuracy))
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
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:accuracy
   (&optional __accuracy)
   (if __accuracy (setq _accuracy __accuracy)) _accuracy)
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
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ;; uint16 _accuracy
    2
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
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint16 _accuracy
       (write-word _accuracy s)
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
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint16 _accuracy
     (setq _accuracy (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _n_sats
     (setq _n_sats (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _flags
     (setq _flags (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::PosEcef :md5sum-) "c591e4d37e8157d9695581e98d021231")
(setf (get piksi_rtk_msgs::PosEcef :datatype-) "piksi_rtk_msgs/PosEcef")
(setf (get piksi_rtk_msgs::PosEcef :definition-)
      "# The position solution message reports absolute Earth Centered Earth Fixed (ECEF) coordinates and the
# status (single point vs pseudo-absolute RTK) of the position solution. If the rover receiver knows the
# surveyed position of the base station and has an RTK solution, this reports a pseudo-absolute position
# solution using the base station position and the rover's RTK baseline vector. The full GPS time is given
# by the preceding MSG GPS TIME with the matching time-of-week (tow).

Header header

uint32 tow          # GPS Time of Week [ms].
float64 x           # ECEF X coordinate [m].
float64 y           # ECEF Y coordinate [m].
float64 z           # ECEF Z coordinate [m].
uint16 accuracy     # Position accuracy estimate (not implemented in hardware version V2).
uint8 n_sats        # Number of satellites used in solution.
uint8 flags         # Status flags, see MSG_POS_ECEF message description in SBP documentation.

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



(provide :piksi_rtk_msgs/PosEcef "c591e4d37e8157d9695581e98d021231")


