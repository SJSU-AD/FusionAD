;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::ImuAuxMulti)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'ImuAuxMulti (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::IMUAUXMULTI")
  (make-package "PIKSI_RTK_MSGS::IMUAUXMULTI"))

(in-package "ROS")
;;//! \htmlinclude ImuAuxMulti.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::ImuAuxMulti
  :super ros::object
  :slots (_header _imu_type _temp _imu_conf ))

(defmethod piksi_rtk_msgs::ImuAuxMulti
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:imu_type __imu_type) 0)
    ((:temp __temp) 0)
    ((:imu_conf __imu_conf) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _imu_type (round __imu_type))
   (setq _temp (round __temp))
   (setq _imu_conf (round __imu_conf))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:imu_type
   (&optional __imu_type)
   (if __imu_type (setq _imu_type __imu_type)) _imu_type)
  (:temp
   (&optional __temp)
   (if __temp (setq _temp __temp)) _temp)
  (:imu_conf
   (&optional __imu_conf)
   (if __imu_conf (setq _imu_conf __imu_conf)) _imu_conf)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _imu_type
    1
    ;; int16 _temp
    2
    ;; uint8 _imu_conf
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _imu_type
       (write-byte _imu_type s)
     ;; int16 _temp
       (write-word _temp s)
     ;; uint8 _imu_conf
       (write-byte _imu_conf s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _imu_type
     (setq _imu_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _temp
     (setq _temp (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _imu_conf
     (setq _imu_conf (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::ImuAuxMulti :md5sum-) "1d0e477b2db08e26ff9772a2136dfba7")
(setf (get piksi_rtk_msgs::ImuAuxMulti :datatype-) "piksi_rtk_msgs/ImuAuxMulti")
(setf (get piksi_rtk_msgs::ImuAuxMulti :definition-)
      "# Auxiliary data specific to a particular IMU. The 'imu type' field will always be consistent but the rest of
# the payload is device specific and depends on the value of 'imu type'.

Header header

uint8 imu_type  # IMU type.
int16 temp      # Raw IMU temperature.
uint8 imu_conf  # IMU configuration.

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



(provide :piksi_rtk_msgs/ImuAuxMulti "1d0e477b2db08e26ff9772a2136dfba7")


