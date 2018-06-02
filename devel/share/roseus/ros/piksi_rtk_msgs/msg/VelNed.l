;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::VelNed)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'VelNed (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::VELNED")
  (make-package "PIKSI_RTK_MSGS::VELNED"))

(in-package "ROS")
;;//! \htmlinclude VelNed.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::VelNed
  :super ros::object
  :slots (_header _tow _n _e _d _h_accuracy _v_accuracy _n_sats _flags ))

(defmethod piksi_rtk_msgs::VelNed
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:tow __tow) 0)
    ((:n __n) 0)
    ((:e __e) 0)
    ((:d __d) 0)
    ((:h_accuracy __h_accuracy) 0)
    ((:v_accuracy __v_accuracy) 0)
    ((:n_sats __n_sats) 0)
    ((:flags __flags) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _tow (round __tow))
   (setq _n (round __n))
   (setq _e (round __e))
   (setq _d (round __d))
   (setq _h_accuracy (round __h_accuracy))
   (setq _v_accuracy (round __v_accuracy))
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
  (:n
   (&optional __n)
   (if __n (setq _n __n)) _n)
  (:e
   (&optional __e)
   (if __e (setq _e __e)) _e)
  (:d
   (&optional __d)
   (if __d (setq _d __d)) _d)
  (:h_accuracy
   (&optional __h_accuracy)
   (if __h_accuracy (setq _h_accuracy __h_accuracy)) _h_accuracy)
  (:v_accuracy
   (&optional __v_accuracy)
   (if __v_accuracy (setq _v_accuracy __v_accuracy)) _v_accuracy)
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
    ;; int32 _n
    4
    ;; int32 _e
    4
    ;; int32 _d
    4
    ;; uint16 _h_accuracy
    2
    ;; uint16 _v_accuracy
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
     ;; int32 _n
       (write-long _n s)
     ;; int32 _e
       (write-long _e s)
     ;; int32 _d
       (write-long _d s)
     ;; uint16 _h_accuracy
       (write-word _h_accuracy s)
     ;; uint16 _v_accuracy
       (write-word _v_accuracy s)
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
   ;; int32 _n
     (setq _n (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _e
     (setq _e (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _d
     (setq _d (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint16 _h_accuracy
     (setq _h_accuracy (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _v_accuracy
     (setq _v_accuracy (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _n_sats
     (setq _n_sats (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _flags
     (setq _flags (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::VelNed :md5sum-) "d181eb2c9a6abff7c97c58dc9f4c0a7f")
(setf (get piksi_rtk_msgs::VelNed :datatype-) "piksi_rtk_msgs/VelNed")
(setf (get piksi_rtk_msgs::VelNed :definition-)
      "# This message reports the velocity in local North East Down (NED) coordinates. The NED coordinate
# system is defined as the local WGS84 tangent plane centered at the current position. The full GPS time
# is given by the preceding MSG GPS TIME with the matching time-of-week (tow).

Header header

uint32 tow          # GPS Time of Week.
int32 n             # Velocity North coordinate [mm/s].
int32 e             # Velocity East coordinate [mm/s].
int32 d             # Velocity Down coordinate [mm/s].
uint16 h_accuracy   # Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
uint16 v_accuracy   # Vertical velocity accuracy estimate (not implemented). Defaults to 0.
uint8 n_sats        # Number of satellites used in solution.
uint8 flags         # Status flags (reserved), see MSG_VEL_ECEF message description in SBP documentation.

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



(provide :piksi_rtk_msgs/VelNed "d181eb2c9a6abff7c97c58dc9f4c0a7f")


