;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::ImuRawMulti)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'ImuRawMulti (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::IMURAWMULTI")
  (make-package "PIKSI_RTK_MSGS::IMURAWMULTI"))

(in-package "ROS")
;;//! \htmlinclude ImuRawMulti.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::ImuRawMulti
  :super ros::object
  :slots (_header _tow _tow_f _acc_x _acc_y _acc_z _gyr_x _gyr_y _gyr_z ))

(defmethod piksi_rtk_msgs::ImuRawMulti
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:tow __tow) 0)
    ((:tow_f __tow_f) 0)
    ((:acc_x __acc_x) 0)
    ((:acc_y __acc_y) 0)
    ((:acc_z __acc_z) 0)
    ((:gyr_x __gyr_x) 0)
    ((:gyr_y __gyr_y) 0)
    ((:gyr_z __gyr_z) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _tow (round __tow))
   (setq _tow_f (round __tow_f))
   (setq _acc_x (round __acc_x))
   (setq _acc_y (round __acc_y))
   (setq _acc_z (round __acc_z))
   (setq _gyr_x (round __gyr_x))
   (setq _gyr_y (round __gyr_y))
   (setq _gyr_z (round __gyr_z))
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
  (:acc_x
   (&optional __acc_x)
   (if __acc_x (setq _acc_x __acc_x)) _acc_x)
  (:acc_y
   (&optional __acc_y)
   (if __acc_y (setq _acc_y __acc_y)) _acc_y)
  (:acc_z
   (&optional __acc_z)
   (if __acc_z (setq _acc_z __acc_z)) _acc_z)
  (:gyr_x
   (&optional __gyr_x)
   (if __gyr_x (setq _gyr_x __gyr_x)) _gyr_x)
  (:gyr_y
   (&optional __gyr_y)
   (if __gyr_y (setq _gyr_y __gyr_y)) _gyr_y)
  (:gyr_z
   (&optional __gyr_z)
   (if __gyr_z (setq _gyr_z __gyr_z)) _gyr_z)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _tow
    4
    ;; uint8 _tow_f
    1
    ;; int16 _acc_x
    2
    ;; int16 _acc_y
    2
    ;; int16 _acc_z
    2
    ;; int16 _gyr_x
    2
    ;; int16 _gyr_y
    2
    ;; int16 _gyr_z
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
     ;; int16 _acc_x
       (write-word _acc_x s)
     ;; int16 _acc_y
       (write-word _acc_y s)
     ;; int16 _acc_z
       (write-word _acc_z s)
     ;; int16 _gyr_x
       (write-word _gyr_x s)
     ;; int16 _gyr_y
       (write-word _gyr_y s)
     ;; int16 _gyr_z
       (write-word _gyr_z s)
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
   ;; int16 _acc_x
     (setq _acc_x (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _acc_y
     (setq _acc_y (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _acc_z
     (setq _acc_z (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gyr_x
     (setq _gyr_x (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gyr_y
     (setq _gyr_y (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gyr_z
     (setq _gyr_z (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::ImuRawMulti :md5sum-) "e32f07f6279690082bb3d37f42a5fc90")
(setf (get piksi_rtk_msgs::ImuRawMulti :datatype-) "piksi_rtk_msgs/ImuRawMulti")
(setf (get piksi_rtk_msgs::ImuRawMulti :definition-)
      "# Raw data from the Inertial Measurement Unit, containing accelerometer and gyroscope readings.

Header header

uint32 tow    # Milliseconds since start of GPS week. If the high bit is set, the time is unknown or invalid.
uint8 tow_f   # Milliseconds since start of GPS week, fractional part.
int16 acc_x   # Acceleration in the body frame X axis.
int16 acc_y   # Acceleration in the body frame Y axis.
int16 acc_z   # Acceleration in the body frame Z axis.
int16 gyr_x   # Angular rate around the body frame X axis.
int16 gyr_y   # Angular rate around the body frame Y axis.
int16 gyr_z   # Angular rate around the body frame Z axis.

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



(provide :piksi_rtk_msgs/ImuRawMulti "e32f07f6279690082bb3d37f42a5fc90")


