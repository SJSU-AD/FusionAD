;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::Heartbeat)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'Heartbeat (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::HEARTBEAT")
  (make-package "PIKSI_RTK_MSGS::HEARTBEAT"))

(in-package "ROS")
;;//! \htmlinclude Heartbeat.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::Heartbeat
  :super ros::object
  :slots (_header _system_error _io_error _swift_nap_error _sbp_minor_version _sbp_major_version _external_antenna_present ))

(defmethod piksi_rtk_msgs::Heartbeat
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:system_error __system_error) 0)
    ((:io_error __io_error) 0)
    ((:swift_nap_error __swift_nap_error) 0)
    ((:sbp_minor_version __sbp_minor_version) 0)
    ((:sbp_major_version __sbp_major_version) 0)
    ((:external_antenna_present __external_antenna_present) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _system_error (round __system_error))
   (setq _io_error (round __io_error))
   (setq _swift_nap_error (round __swift_nap_error))
   (setq _sbp_minor_version (round __sbp_minor_version))
   (setq _sbp_major_version (round __sbp_major_version))
   (setq _external_antenna_present (round __external_antenna_present))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:system_error
   (&optional __system_error)
   (if __system_error (setq _system_error __system_error)) _system_error)
  (:io_error
   (&optional __io_error)
   (if __io_error (setq _io_error __io_error)) _io_error)
  (:swift_nap_error
   (&optional __swift_nap_error)
   (if __swift_nap_error (setq _swift_nap_error __swift_nap_error)) _swift_nap_error)
  (:sbp_minor_version
   (&optional __sbp_minor_version)
   (if __sbp_minor_version (setq _sbp_minor_version __sbp_minor_version)) _sbp_minor_version)
  (:sbp_major_version
   (&optional __sbp_major_version)
   (if __sbp_major_version (setq _sbp_major_version __sbp_major_version)) _sbp_major_version)
  (:external_antenna_present
   (&optional __external_antenna_present)
   (if __external_antenna_present (setq _external_antenna_present __external_antenna_present)) _external_antenna_present)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _system_error
    1
    ;; uint8 _io_error
    1
    ;; uint8 _swift_nap_error
    1
    ;; uint8 _sbp_minor_version
    1
    ;; uint8 _sbp_major_version
    1
    ;; uint8 _external_antenna_present
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _system_error
       (write-byte _system_error s)
     ;; uint8 _io_error
       (write-byte _io_error s)
     ;; uint8 _swift_nap_error
       (write-byte _swift_nap_error s)
     ;; uint8 _sbp_minor_version
       (write-byte _sbp_minor_version s)
     ;; uint8 _sbp_major_version
       (write-byte _sbp_major_version s)
     ;; uint8 _external_antenna_present
       (write-byte _external_antenna_present s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _system_error
     (setq _system_error (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _io_error
     (setq _io_error (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _swift_nap_error
     (setq _swift_nap_error (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _sbp_minor_version
     (setq _sbp_minor_version (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _sbp_major_version
     (setq _sbp_major_version (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _external_antenna_present
     (setq _external_antenna_present (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::Heartbeat :md5sum-) "f302769a534aa6ff5a3f6b1f1c11f4bc")
(setf (get piksi_rtk_msgs::Heartbeat :datatype-) "piksi_rtk_msgs/Heartbeat")
(setf (get piksi_rtk_msgs::Heartbeat :definition-)
      "# The heartbeat message is sent periodically to inform the host or other attached devices that the system
# is running. It is used to monitor system malfunctions. It also contains status flags that indicate to the
# host the status of the system and whether it is operating correctly. Currently, the expected heartbeat
# interval is 1 sec.
# The system error flag is used to indicate that an error has occurred in the system. To determine the
# source of the error, the remaining error flags should be inspected.

Header header

uint8 system_error              # System Error Flag.
uint8 io_error                  # IO Error Flag.
uint8 swift_nap_error           # SwiftNAP Error Flag.
uint8 sbp_minor_version         # SBP Minor Protocol Version Number.
uint8 sbp_major_version         # SBP Major Protocol Version Number.
uint8 external_antenna_present  # External Antenna Present Flag.

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



(provide :piksi_rtk_msgs/Heartbeat "f302769a534aa6ff5a3f6b1f1c11f4bc")


