;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::MagRaw)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'MagRaw (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::MAGRAW")
  (make-package "PIKSI_RTK_MSGS::MAGRAW"))

(in-package "ROS")
;;//! \htmlinclude MagRaw.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::MagRaw
  :super ros::object
  :slots (_header _tow _tow_f _mag_x _mag_y _mag_z ))

(defmethod piksi_rtk_msgs::MagRaw
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:tow __tow) 0)
    ((:tow_f __tow_f) 0)
    ((:mag_x __mag_x) 0)
    ((:mag_y __mag_y) 0)
    ((:mag_z __mag_z) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _tow (round __tow))
   (setq _tow_f (round __tow_f))
   (setq _mag_x (round __mag_x))
   (setq _mag_y (round __mag_y))
   (setq _mag_z (round __mag_z))
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
  (:tow_f
   (&optional __tow_f)
   (if __tow_f (setq _tow_f __tow_f)) _tow_f)
  (:mag_x
   (&optional __mag_x)
   (if __mag_x (setq _mag_x __mag_x)) _mag_x)
  (:mag_y
   (&optional __mag_y)
   (if __mag_y (setq _mag_y __mag_y)) _mag_y)
  (:mag_z
   (&optional __mag_z)
   (if __mag_z (setq _mag_z __mag_z)) _mag_z)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _tow
    4
    ;; uint8 _tow_f
    1
    ;; int16 _mag_x
    2
    ;; int16 _mag_y
    2
    ;; int16 _mag_z
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _tow
       (write-long _tow s)
     ;; uint8 _tow_f
       (write-byte _tow_f s)
     ;; int16 _mag_x
       (write-word _mag_x s)
     ;; int16 _mag_y
       (write-word _mag_y s)
     ;; int16 _mag_z
       (write-word _mag_z s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _tow
     (setq _tow (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _tow_f
     (setq _tow_f (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _mag_x
     (setq _mag_x (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mag_y
     (setq _mag_y (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mag_z
     (setq _mag_z (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::MagRaw :md5sum-) "79dfa3690a8019ef8383e9c5637520d8")
(setf (get piksi_rtk_msgs::MagRaw :datatype-) "piksi_rtk_msgs/MagRaw")
(setf (get piksi_rtk_msgs::MagRaw :definition-)
      "# Raw data from the Magnetometer.

Header header

uint32 tow    # Milliseconds since start of GPS week. If the high bit is set, the time is unknown or invalid.
uint8 tow_f   # Milliseconds since start of GPS week, fractional part.
int16 mag_x   # Magnetometer value in the body frame X axis.
int16 mag_y   # Magnetometer value in the body frame Y axis.
int16 mag_z   # Magnetometer value in the body frame Z axis.
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



(provide :piksi_rtk_msgs/MagRaw "79dfa3690a8019ef8383e9c5637520d8")


