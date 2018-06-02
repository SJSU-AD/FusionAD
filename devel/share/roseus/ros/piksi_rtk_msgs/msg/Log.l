;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::Log)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'Log (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::LOG")
  (make-package "PIKSI_RTK_MSGS::LOG"))

(in-package "ROS")
;;//! \htmlinclude Log.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::Log
  :super ros::object
  :slots (_header _level _text ))

(defmethod piksi_rtk_msgs::Log
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:level __level) 0)
    ((:text __text) "")
    )
   (send-super :init)
   (setq _header __header)
   (setq _level (round __level))
   (setq _text (string __text))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:level
   (&optional __level)
   (if __level (setq _level __level)) _level)
  (:text
   (&optional __text)
   (if __text (setq _text __text)) _text)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _level
    1
    ;; string _text
    4 (length _text)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _level
       (write-byte _level s)
     ;; string _text
       (write-long (length _text) s) (princ _text s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _level
     (setq _level (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _text
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _text (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::Log :md5sum-) "479c0d9a1959331b49466f8b39ceb6bb")
(setf (get piksi_rtk_msgs::Log :datatype-) "piksi_rtk_msgs/Log")
(setf (get piksi_rtk_msgs::Log :definition-)
      "# Logging and debugging messages from the device.

Header header

uint8 level # Emerg (0), Alert (1), Crit (2), Error (3), Warn (4), Notice (5), Info (6), Debug (7).
string text # Human-readable string.

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



(provide :piksi_rtk_msgs/Log "479c0d9a1959331b49466f8b39ceb6bb")


