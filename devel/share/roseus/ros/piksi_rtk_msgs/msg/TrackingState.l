;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::TrackingState)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'TrackingState (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::TRACKINGSTATE")
  (make-package "PIKSI_RTK_MSGS::TRACKINGSTATE"))

(in-package "ROS")
;;//! \htmlinclude TrackingState.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::TrackingState
  :super ros::object
  :slots (_header _state _sat _code _cn0 ))

(defmethod piksi_rtk_msgs::TrackingState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:state __state) (make-array 0 :initial-element 0 :element-type :char))
    ((:sat __sat) (make-array 0 :initial-element 0 :element-type :integer))
    ((:code __code) (make-array 0 :initial-element 0 :element-type :char))
    ((:cn0 __cn0) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _state __state)
   (setq _sat __sat)
   (setq _code __code)
   (setq _cn0 __cn0)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:sat
   (&optional __sat)
   (if __sat (setq _sat __sat)) _sat)
  (:code
   (&optional __code)
   (if __code (setq _code __code)) _code)
  (:cn0
   (&optional __cn0)
   (if __cn0 (setq _cn0 __cn0)) _cn0)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8[] _state
    (* 1    (length _state)) 4
    ;; uint16[] _sat
    (* 2    (length _sat)) 4
    ;; uint8[] _code
    (* 1    (length _code)) 4
    ;; float32[] _cn0
    (* 4    (length _cn0)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8[] _state
     (write-long (length _state) s)
     (princ _state s)
     ;; uint16[] _sat
     (write-long (length _sat) s)
     (dotimes (i (length _sat))
       (write-word (elt _sat i) s)
       )
     ;; uint8[] _code
     (write-long (length _code) s)
     (princ _code s)
     ;; float32[] _cn0
     (write-long (length _cn0) s)
     (dotimes (i (length _cn0))
       (sys::poke (elt _cn0 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8[] _state
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _state (make-array n :element-type :char))
     (replace _state buf :start2 ptr-) (incf ptr- n))
   ;; uint16[] _sat
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _sat (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _sat i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; uint8[] _code
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _code (make-array n :element-type :char))
     (replace _code buf :start2 ptr-) (incf ptr- n))
   ;; float32[] _cn0
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _cn0 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _cn0 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::TrackingState :md5sum-) "e7984ffda35159a5c451b134b22b20b1")
(setf (get piksi_rtk_msgs::TrackingState :datatype-) "piksi_rtk_msgs/TrackingState")
(setf (get piksi_rtk_msgs::TrackingState :definition-)
      "# The tracking message returns a variable-length array of tracking channel states. It reports status and
# carrier-to-noise density measurements for all tracked satellites.

Header header

uint8[] state   # Status of tracking channel.
uint16[] sat    # Constellation-specific satellite identifier.
uint8[] code    # Signal constellation, band and code.
float32[] cn0   # Carrier-to-noise density.

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



(provide :piksi_rtk_msgs/TrackingState "e7984ffda35159a5c451b134b22b20b1")


