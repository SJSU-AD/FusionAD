;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::ReceiverState)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'ReceiverState (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE")
  (make-package "PIKSI_RTK_MSGS::RECEIVERSTATE"))

(in-package "ROS")
;;//! \htmlinclude ReceiverState.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::ReceiverState
  :super ros::object
  :slots (_header _num_sat _rtk_mode_fix _sat _cn0 _tracking_running _system_error _io_error _swift_nap_error _external_antenna_present ))

(defmethod piksi_rtk_msgs::ReceiverState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:num_sat __num_sat) 0)
    ((:rtk_mode_fix __rtk_mode_fix) nil)
    ((:sat __sat) (make-array 0 :initial-element 0 :element-type :integer))
    ((:cn0 __cn0) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:tracking_running __tracking_running) (make-array 0 :initial-element 0 :element-type :char))
    ((:system_error __system_error) 0)
    ((:io_error __io_error) 0)
    ((:swift_nap_error __swift_nap_error) 0)
    ((:external_antenna_present __external_antenna_present) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _num_sat (round __num_sat))
   (setq _rtk_mode_fix __rtk_mode_fix)
   (setq _sat __sat)
   (setq _cn0 __cn0)
   (setq _tracking_running __tracking_running)
   (setq _system_error (round __system_error))
   (setq _io_error (round __io_error))
   (setq _swift_nap_error (round __swift_nap_error))
   (setq _external_antenna_present (round __external_antenna_present))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:num_sat
   (&optional __num_sat)
   (if __num_sat (setq _num_sat __num_sat)) _num_sat)
  (:rtk_mode_fix
   (&optional __rtk_mode_fix)
   (if __rtk_mode_fix (setq _rtk_mode_fix __rtk_mode_fix)) _rtk_mode_fix)
  (:sat
   (&optional __sat)
   (if __sat (setq _sat __sat)) _sat)
  (:cn0
   (&optional __cn0)
   (if __cn0 (setq _cn0 __cn0)) _cn0)
  (:tracking_running
   (&optional __tracking_running)
   (if __tracking_running (setq _tracking_running __tracking_running)) _tracking_running)
  (:system_error
   (&optional __system_error)
   (if __system_error (setq _system_error __system_error)) _system_error)
  (:io_error
   (&optional __io_error)
   (if __io_error (setq _io_error __io_error)) _io_error)
  (:swift_nap_error
   (&optional __swift_nap_error)
   (if __swift_nap_error (setq _swift_nap_error __swift_nap_error)) _swift_nap_error)
  (:external_antenna_present
   (&optional __external_antenna_present)
   (if __external_antenna_present (setq _external_antenna_present __external_antenna_present)) _external_antenna_present)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _num_sat
    1
    ;; bool _rtk_mode_fix
    1
    ;; uint16[] _sat
    (* 2    (length _sat)) 4
    ;; float32[] _cn0
    (* 4    (length _cn0)) 4
    ;; uint8[] _tracking_running
    (* 1    (length _tracking_running)) 4
    ;; uint8 _system_error
    1
    ;; uint8 _io_error
    1
    ;; uint8 _swift_nap_error
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
     ;; uint8 _num_sat
       (write-byte _num_sat s)
     ;; bool _rtk_mode_fix
       (if _rtk_mode_fix (write-byte -1 s) (write-byte 0 s))
     ;; uint16[] _sat
     (write-long (length _sat) s)
     (dotimes (i (length _sat))
       (write-word (elt _sat i) s)
       )
     ;; float32[] _cn0
     (write-long (length _cn0) s)
     (dotimes (i (length _cn0))
       (sys::poke (elt _cn0 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; uint8[] _tracking_running
     (write-long (length _tracking_running) s)
     (princ _tracking_running s)
     ;; uint8 _system_error
       (write-byte _system_error s)
     ;; uint8 _io_error
       (write-byte _io_error s)
     ;; uint8 _swift_nap_error
       (write-byte _swift_nap_error s)
     ;; uint8 _external_antenna_present
       (write-byte _external_antenna_present s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _num_sat
     (setq _num_sat (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _rtk_mode_fix
     (setq _rtk_mode_fix (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint16[] _sat
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _sat (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _sat i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; float32[] _cn0
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _cn0 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _cn0 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; uint8[] _tracking_running
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _tracking_running (make-array n :element-type :char))
     (replace _tracking_running buf :start2 ptr-) (incf ptr- n))
   ;; uint8 _system_error
     (setq _system_error (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _io_error
     (setq _io_error (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _swift_nap_error
     (setq _swift_nap_error (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _external_antenna_present
     (setq _external_antenna_present (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::ReceiverState :md5sum-) "3bca929a4e134714778225bff42f183c")
(setf (get piksi_rtk_msgs::ReceiverState :datatype-) "piksi_rtk_msgs/ReceiverState")
(setf (get piksi_rtk_msgs::ReceiverState :definition-)
      "# Miscellaneous information form different SBP messages

Header header

uint8 num_sat                   # Number of satellites.
bool rtk_mode_fix 	            # 1 = Fixed, 0 = Float.
uint16[] sat                    # Constellation-specific satellite identifier.
float32[] cn0                   # Carrier-to-noise density.
uint8[] tracking_running        # Status of tracking channel.
uint8 system_error              # System Error Flag.
uint8 io_error                  # IO Error Flag.
uint8 swift_nap_error           # SwiftNAP Error Flag.
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



(provide :piksi_rtk_msgs/ReceiverState "3bca929a4e134714778225bff42f183c")


