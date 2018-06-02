;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::VelEcef)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'VelEcef (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::VELECEF")
  (make-package "PIKSI_RTK_MSGS::VELECEF"))

(in-package "ROS")
;;//! \htmlinclude VelEcef.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::VelEcef
  :super ros::object
  :slots (_header _tow _x _y _z _accuracy _n_sats _flags ))

(defmethod piksi_rtk_msgs::VelEcef
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:tow __tow) 0)
    ((:x __x) 0)
    ((:y __y) 0)
    ((:z __z) 0)
    ((:accuracy __accuracy) 0)
    ((:n_sats __n_sats) 0)
    ((:flags __flags) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _tow (round __tow))
   (setq _x (round __x))
   (setq _y (round __y))
   (setq _z (round __z))
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
    ;; int32 _x
    4
    ;; int32 _y
    4
    ;; int32 _z
    4
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
     ;; int32 _x
       (write-long _x s)
     ;; int32 _y
       (write-long _y s)
     ;; int32 _z
       (write-long _z s)
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
   ;; int32 _x
     (setq _x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _y
     (setq _y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _z
     (setq _z (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint16 _accuracy
     (setq _accuracy (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _n_sats
     (setq _n_sats (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _flags
     (setq _flags (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::VelEcef :md5sum-) "b632ba03d94241cc519a3a3e4885b973")
(setf (get piksi_rtk_msgs::VelEcef :datatype-) "piksi_rtk_msgs/VelEcef")
(setf (get piksi_rtk_msgs::VelEcef :definition-)
      "# This message reports the velocity in Earth Centered Earth Fixed (ECEF) coordinates. The full GPS time
# is given by the preceding MSG GPS TIME with the matching time-of-week (tow).

Header header

uint32 tow      # GPS Time of Week.
int32 x         # Velocity ECEF X coordinate [mm/s].
int32 y         # Velocity ECEF Y coordinate [mm/s].
int32 z         # Velocity ECEF Z coordinate [mm/s].
uint16 accuracy # Velocity accuracy estimate (not implemented). Defaults to 0.
uint8 n_sats    # Number of satellites used in solution.
uint8 flags     # Status flags (reserved), see MSG_VEL_ECEF message description in SBP documentation.

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



(provide :piksi_rtk_msgs/VelEcef "b632ba03d94241cc519a3a3e4885b973")


