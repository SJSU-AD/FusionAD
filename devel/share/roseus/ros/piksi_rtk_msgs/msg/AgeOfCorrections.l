;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::AgeOfCorrections)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'AgeOfCorrections (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::AGEOFCORRECTIONS")
  (make-package "PIKSI_RTK_MSGS::AGEOFCORRECTIONS"))

(in-package "ROS")
;;//! \htmlinclude AgeOfCorrections.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::AgeOfCorrections
  :super ros::object
  :slots (_header _tow _age ))

(defmethod piksi_rtk_msgs::AgeOfCorrections
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:tow __tow) 0)
    ((:age __age) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _tow (round __tow))
   (setq _age (round __age))
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
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _tow
    4
    ;; uint16 _age
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
     ;; uint16 _age
       (write-word _age s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _tow
     (setq _tow (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint16 _age
     (setq _age (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::AgeOfCorrections :md5sum-) "94c5e09b6a4cc653e4fede2c22a046bf")
(setf (get piksi_rtk_msgs::AgeOfCorrections :datatype-) "piksi_rtk_msgs/AgeOfCorrections")
(setf (get piksi_rtk_msgs::AgeOfCorrections :definition-)
      "# Age of the corrections used for the current Differential solution.

Header header

uint32 tow      # GPS Time of Week [ms].
uint16 age      # Age of the corrections (0xFFFF indicates invalid) [deciseconds].

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



(provide :piksi_rtk_msgs/AgeOfCorrections "94c5e09b6a4cc653e4fede2c22a046bf")


