;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::DeviceMonitor_V2_3_15)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'DeviceMonitor_V2_3_15 (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::DEVICEMONITOR_V2_3_15")
  (make-package "PIKSI_RTK_MSGS::DEVICEMONITOR_V2_3_15"))

(in-package "ROS")
;;//! \htmlinclude DeviceMonitor_V2_3_15.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::DeviceMonitor_V2_3_15
  :super ros::object
  :slots (_header _dev_vin _cpu_vint _cpu_vaux _cpu_temperature _fe_temperature ))

(defmethod piksi_rtk_msgs::DeviceMonitor_V2_3_15
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:dev_vin __dev_vin) 0)
    ((:cpu_vint __cpu_vint) 0)
    ((:cpu_vaux __cpu_vaux) 0)
    ((:cpu_temperature __cpu_temperature) 0)
    ((:fe_temperature __fe_temperature) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _dev_vin (round __dev_vin))
   (setq _cpu_vint (round __cpu_vint))
   (setq _cpu_vaux (round __cpu_vaux))
   (setq _cpu_temperature (round __cpu_temperature))
   (setq _fe_temperature (round __fe_temperature))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:dev_vin
   (&optional __dev_vin)
   (if __dev_vin (setq _dev_vin __dev_vin)) _dev_vin)
  (:cpu_vint
   (&optional __cpu_vint)
   (if __cpu_vint (setq _cpu_vint __cpu_vint)) _cpu_vint)
  (:cpu_vaux
   (&optional __cpu_vaux)
   (if __cpu_vaux (setq _cpu_vaux __cpu_vaux)) _cpu_vaux)
  (:cpu_temperature
   (&optional __cpu_temperature)
   (if __cpu_temperature (setq _cpu_temperature __cpu_temperature)) _cpu_temperature)
  (:fe_temperature
   (&optional __fe_temperature)
   (if __fe_temperature (setq _fe_temperature __fe_temperature)) _fe_temperature)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int16 _dev_vin
    2
    ;; int16 _cpu_vint
    2
    ;; int16 _cpu_vaux
    2
    ;; int16 _cpu_temperature
    2
    ;; int16 _fe_temperature
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int16 _dev_vin
       (write-word _dev_vin s)
     ;; int16 _cpu_vint
       (write-word _cpu_vint s)
     ;; int16 _cpu_vaux
       (write-word _cpu_vaux s)
     ;; int16 _cpu_temperature
       (write-word _cpu_temperature s)
     ;; int16 _fe_temperature
       (write-word _fe_temperature s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int16 _dev_vin
     (setq _dev_vin (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _cpu_vint
     (setq _cpu_vint (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _cpu_vaux
     (setq _cpu_vaux (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _cpu_temperature
     (setq _cpu_temperature (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _fe_temperature
     (setq _fe_temperature (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::DeviceMonitor_V2_3_15 :md5sum-) "54b454c5f7be4348e9710a8df0100d12")
(setf (get piksi_rtk_msgs::DeviceMonitor_V2_3_15 :datatype-) "piksi_rtk_msgs/DeviceMonitor_V2_3_15")
(setf (get piksi_rtk_msgs::DeviceMonitor_V2_3_15 :definition-)
      "# This message contains temperature and voltage level measurements from the processor’s monitoring
# system and the RF frontend die temperature if available.

# Message definition based on libsbp v2.2.15

Header header

int16 dev_vin               # Device V_in [V / 1000].
int16 cpu_vint              # Processor V_int [V / 1000].
int16 cpu_vaux              # Processor V_aux [V / 1000].
int16 cpu_temperature       # Processor temperature [degrees C / 100].
int16 fe_temperature        # Fronted temperature (if available) [degrees C / 100].

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



(provide :piksi_rtk_msgs/DeviceMonitor_V2_3_15 "54b454c5f7be4348e9710a8df0100d12")


