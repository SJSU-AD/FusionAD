;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::UtcTimeMulti)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'UtcTimeMulti (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::UTCTIMEMULTI")
  (make-package "PIKSI_RTK_MSGS::UTCTIMEMULTI"))

(in-package "ROS")
;;//! \htmlinclude UtcTimeMulti.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::UtcTimeMulti
  :super ros::object
  :slots (_header _flags _tow _year _month _day _hours _minutes _seconds _ns ))

(defmethod piksi_rtk_msgs::UtcTimeMulti
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:flags __flags) 0)
    ((:tow __tow) 0)
    ((:year __year) 0)
    ((:month __month) 0)
    ((:day __day) 0)
    ((:hours __hours) 0)
    ((:minutes __minutes) 0)
    ((:seconds __seconds) 0)
    ((:ns __ns) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _flags (round __flags))
   (setq _tow (round __tow))
   (setq _year (round __year))
   (setq _month (round __month))
   (setq _day (round __day))
   (setq _hours (round __hours))
   (setq _minutes (round __minutes))
   (setq _seconds (round __seconds))
   (setq _ns (round __ns))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:flags
   (&optional __flags)
   (if __flags (setq _flags __flags)) _flags)
  (:tow
   (&optional __tow)
   (if __tow (setq _tow __tow)) _tow)
  (:year
   (&optional __year)
   (if __year (setq _year __year)) _year)
  (:month
   (&optional __month)
   (if __month (setq _month __month)) _month)
  (:day
   (&optional __day)
   (if __day (setq _day __day)) _day)
  (:hours
   (&optional __hours)
   (if __hours (setq _hours __hours)) _hours)
  (:minutes
   (&optional __minutes)
   (if __minutes (setq _minutes __minutes)) _minutes)
  (:seconds
   (&optional __seconds)
   (if __seconds (setq _seconds __seconds)) _seconds)
  (:ns
   (&optional __ns)
   (if __ns (setq _ns __ns)) _ns)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _flags
    1
    ;; uint32 _tow
    4
    ;; uint16 _year
    2
    ;; uint8 _month
    1
    ;; uint8 _day
    1
    ;; uint8 _hours
    1
    ;; uint8 _minutes
    1
    ;; uint8 _seconds
    1
    ;; uint32 _ns
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _flags
       (write-byte _flags s)
     ;; uint32 _tow
       (write-long _tow s)
     ;; uint16 _year
       (write-word _year s)
     ;; uint8 _month
       (write-byte _month s)
     ;; uint8 _day
       (write-byte _day s)
     ;; uint8 _hours
       (write-byte _hours s)
     ;; uint8 _minutes
       (write-byte _minutes s)
     ;; uint8 _seconds
       (write-byte _seconds s)
     ;; uint32 _ns
       (write-long _ns s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _flags
     (setq _flags (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _tow
     (setq _tow (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint16 _year
     (setq _year (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _month
     (setq _month (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _day
     (setq _day (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _hours
     (setq _hours (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _minutes
     (setq _minutes (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _seconds
     (setq _seconds (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _ns
     (setq _ns (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::UtcTimeMulti :md5sum-) "305f41bf5fdb87de324a10b06c47c614")
(setf (get piksi_rtk_msgs::UtcTimeMulti :datatype-) "piksi_rtk_msgs/UtcTimeMulti")
(setf (get piksi_rtk_msgs::UtcTimeMulti :definition-)
      "# This message reports the Universal Coordinated Time (UTC). Note the flags which
# indicate the source of the UTC offset value and source of the time fix.

Header header

uint8 flags   # Indicates source and time validity
uint32 tow    # GPS time of week rounded to the nearest millisecond
uint16 year   # Year
uint8 month   # Month (range 1 .. 12)
uint8 day     # days in the month (range 1-31)
uint8 hours   # hours of day (range 0-23)
uint8 minutes # minutes of hour (range 0-59)
uint8 seconds # seconds of minute (range 0-60) rounded down
uint32 ns     # nanoseconds of second (range 0-999999999)

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



(provide :piksi_rtk_msgs/UtcTimeMulti "305f41bf5fdb87de324a10b06c47c614")


