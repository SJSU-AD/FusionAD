;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::DopsMulti)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'DopsMulti (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::DOPSMULTI")
  (make-package "PIKSI_RTK_MSGS::DOPSMULTI"))

(in-package "ROS")
;;//! \htmlinclude DopsMulti.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::DopsMulti
  :super ros::object
  :slots (_header _tow _gdop _pdop _tdop _hdop _vdop _flags ))

(defmethod piksi_rtk_msgs::DopsMulti
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:tow __tow) 0)
    ((:gdop __gdop) 0)
    ((:pdop __pdop) 0)
    ((:tdop __tdop) 0)
    ((:hdop __hdop) 0)
    ((:vdop __vdop) 0)
    ((:flags __flags) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _tow (round __tow))
   (setq _gdop (round __gdop))
   (setq _pdop (round __pdop))
   (setq _tdop (round __tdop))
   (setq _hdop (round __hdop))
   (setq _vdop (round __vdop))
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
  (:gdop
   (&optional __gdop)
   (if __gdop (setq _gdop __gdop)) _gdop)
  (:pdop
   (&optional __pdop)
   (if __pdop (setq _pdop __pdop)) _pdop)
  (:tdop
   (&optional __tdop)
   (if __tdop (setq _tdop __tdop)) _tdop)
  (:hdop
   (&optional __hdop)
   (if __hdop (setq _hdop __hdop)) _hdop)
  (:vdop
   (&optional __vdop)
   (if __vdop (setq _vdop __vdop)) _vdop)
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
    ;; uint16 _gdop
    2
    ;; uint16 _pdop
    2
    ;; uint16 _tdop
    2
    ;; uint16 _hdop
    2
    ;; uint16 _vdop
    2
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
     ;; uint16 _gdop
       (write-word _gdop s)
     ;; uint16 _pdop
       (write-word _pdop s)
     ;; uint16 _tdop
       (write-word _tdop s)
     ;; uint16 _hdop
       (write-word _hdop s)
     ;; uint16 _vdop
       (write-word _vdop s)
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
   ;; uint16 _gdop
     (setq _gdop (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _pdop
     (setq _pdop (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _tdop
     (setq _tdop (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _hdop
     (setq _hdop (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _vdop
     (setq _vdop (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _flags
     (setq _flags (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::DopsMulti :md5sum-) "c8ec518c5a95442b85a41a69915d3477")
(setf (get piksi_rtk_msgs::DopsMulti :datatype-) "piksi_rtk_msgs/DopsMulti")
(setf (get piksi_rtk_msgs::DopsMulti :definition-)
      "# This dilution of precision (DOP) message describes the effect of navigation satellite geometry on positional
# measurement precision.

Header header

uint32 tow  # GPS Time of Week [ms].
uint16 gdop # Geometric Dilution of Precision.
uint16 pdop # Position Dilution of Precision.
uint16 tdop # Time Dilution of Precision.
uint16 hdop # Horizontal Dilution of Precision.
uint16 vdop # Vertical Dilution of Precision.
uint8 flags # Indicates the position solution with which the DOPS message corresponds.

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



(provide :piksi_rtk_msgs/DopsMulti "c8ec518c5a95442b85a41a69915d3477")


