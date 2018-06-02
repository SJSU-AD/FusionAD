;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::Observation)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'Observation (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::OBSERVATION")
  (make-package "PIKSI_RTK_MSGS::OBSERVATION"))

(in-package "ROS")
;;//! \htmlinclude Observation.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass piksi_rtk_msgs::Observation
  :super ros::object
  :slots (_header _tow _ns_residual _wn _n_obs _P _L_i _L_f _D_i _D_f _cn0 _lock _flags _sid_sat _sid_code ))

(defmethod piksi_rtk_msgs::Observation
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:tow __tow) 0)
    ((:ns_residual __ns_residual) 0)
    ((:wn __wn) 0)
    ((:n_obs __n_obs) 0)
    ((:P __P) (make-array 0 :initial-element 0 :element-type :integer))
    ((:L_i __L_i) (make-array 0 :initial-element 0 :element-type :integer))
    ((:L_f __L_f) (make-array 0 :initial-element 0 :element-type :char))
    ((:D_i __D_i) (make-array 0 :initial-element 0 :element-type :integer))
    ((:D_f __D_f) (make-array 0 :initial-element 0 :element-type :char))
    ((:cn0 __cn0) (make-array 0 :initial-element 0 :element-type :char))
    ((:lock __lock) (make-array 0 :initial-element 0 :element-type :char))
    ((:flags __flags) (make-array 0 :initial-element 0 :element-type :char))
    ((:sid_sat __sid_sat) (make-array 0 :initial-element 0 :element-type :char))
    ((:sid_code __sid_code) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _header __header)
   (setq _tow (round __tow))
   (setq _ns_residual (round __ns_residual))
   (setq _wn (round __wn))
   (setq _n_obs (round __n_obs))
   (setq _P __P)
   (setq _L_i __L_i)
   (setq _L_f __L_f)
   (setq _D_i __D_i)
   (setq _D_f __D_f)
   (setq _cn0 __cn0)
   (setq _lock __lock)
   (setq _flags __flags)
   (setq _sid_sat __sid_sat)
   (setq _sid_code __sid_code)
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
  (:ns_residual
   (&optional __ns_residual)
   (if __ns_residual (setq _ns_residual __ns_residual)) _ns_residual)
  (:wn
   (&optional __wn)
   (if __wn (setq _wn __wn)) _wn)
  (:n_obs
   (&optional __n_obs)
   (if __n_obs (setq _n_obs __n_obs)) _n_obs)
  (:P
   (&optional __P)
   (if __P (setq _P __P)) _P)
  (:L_i
   (&optional __L_i)
   (if __L_i (setq _L_i __L_i)) _L_i)
  (:L_f
   (&optional __L_f)
   (if __L_f (setq _L_f __L_f)) _L_f)
  (:D_i
   (&optional __D_i)
   (if __D_i (setq _D_i __D_i)) _D_i)
  (:D_f
   (&optional __D_f)
   (if __D_f (setq _D_f __D_f)) _D_f)
  (:cn0
   (&optional __cn0)
   (if __cn0 (setq _cn0 __cn0)) _cn0)
  (:lock
   (&optional __lock)
   (if __lock (setq _lock __lock)) _lock)
  (:flags
   (&optional __flags)
   (if __flags (setq _flags __flags)) _flags)
  (:sid_sat
   (&optional __sid_sat)
   (if __sid_sat (setq _sid_sat __sid_sat)) _sid_sat)
  (:sid_code
   (&optional __sid_code)
   (if __sid_code (setq _sid_code __sid_code)) _sid_code)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _tow
    4
    ;; int32 _ns_residual
    4
    ;; uint16 _wn
    2
    ;; uint8 _n_obs
    1
    ;; uint32[] _P
    (* 4    (length _P)) 4
    ;; int32[] _L_i
    (* 4    (length _L_i)) 4
    ;; uint8[] _L_f
    (* 1    (length _L_f)) 4
    ;; int16[] _D_i
    (* 2    (length _D_i)) 4
    ;; uint8[] _D_f
    (* 1    (length _D_f)) 4
    ;; uint8[] _cn0
    (* 1    (length _cn0)) 4
    ;; uint8[] _lock
    (* 1    (length _lock)) 4
    ;; uint8[] _flags
    (* 1    (length _flags)) 4
    ;; uint8[] _sid_sat
    (* 1    (length _sid_sat)) 4
    ;; uint8[] _sid_code
    (* 1    (length _sid_code)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _tow
       (write-long _tow s)
     ;; int32 _ns_residual
       (write-long _ns_residual s)
     ;; uint16 _wn
       (write-word _wn s)
     ;; uint8 _n_obs
       (write-byte _n_obs s)
     ;; uint32[] _P
     (write-long (length _P) s)
     (dotimes (i (length _P))
       (write-long (elt _P i) s)
       )
     ;; int32[] _L_i
     (write-long (length _L_i) s)
     (dotimes (i (length _L_i))
       (write-long (elt _L_i i) s)
       )
     ;; uint8[] _L_f
     (write-long (length _L_f) s)
     (princ _L_f s)
     ;; int16[] _D_i
     (write-long (length _D_i) s)
     (dotimes (i (length _D_i))
       (write-word (elt _D_i i) s)
       )
     ;; uint8[] _D_f
     (write-long (length _D_f) s)
     (princ _D_f s)
     ;; uint8[] _cn0
     (write-long (length _cn0) s)
     (princ _cn0 s)
     ;; uint8[] _lock
     (write-long (length _lock) s)
     (princ _lock s)
     ;; uint8[] _flags
     (write-long (length _flags) s)
     (princ _flags s)
     ;; uint8[] _sid_sat
     (write-long (length _sid_sat) s)
     (princ _sid_sat s)
     ;; uint8[] _sid_code
     (write-long (length _sid_code) s)
     (princ _sid_code s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _tow
     (setq _tow (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _ns_residual
     (setq _ns_residual (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint16 _wn
     (setq _wn (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _n_obs
     (setq _n_obs (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32[] _P
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _P (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _P i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32[] _L_i
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _L_i (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _L_i i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; uint8[] _L_f
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _L_f (make-array n :element-type :char))
     (replace _L_f buf :start2 ptr-) (incf ptr- n))
   ;; int16[] _D_i
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _D_i (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _D_i i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; uint8[] _D_f
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _D_f (make-array n :element-type :char))
     (replace _D_f buf :start2 ptr-) (incf ptr- n))
   ;; uint8[] _cn0
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _cn0 (make-array n :element-type :char))
     (replace _cn0 buf :start2 ptr-) (incf ptr- n))
   ;; uint8[] _lock
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _lock (make-array n :element-type :char))
     (replace _lock buf :start2 ptr-) (incf ptr- n))
   ;; uint8[] _flags
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _flags (make-array n :element-type :char))
     (replace _flags buf :start2 ptr-) (incf ptr- n))
   ;; uint8[] _sid_sat
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _sid_sat (make-array n :element-type :char))
     (replace _sid_sat buf :start2 ptr-) (incf ptr- n))
   ;; uint8[] _sid_code
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _sid_code (make-array n :element-type :char))
     (replace _sid_code buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::Observation :md5sum-) "9fb93688b90e872c3a77668a53e5ecc9")
(setf (get piksi_rtk_msgs::Observation :datatype-) "piksi_rtk_msgs/Observation")
(setf (get piksi_rtk_msgs::Observation :definition-)
      "# Satellite observation messages from the device.

Header header

uint32 tow                  # Milliseconds since start of GPS week.
int32  ns_residual          # Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000).
uint16 wn                   # GPS week number.
uint8  n_obs                # Total number of observations.
                            # First nibble is the size of the sequence (n), second nibble is the zero-indexed counter (ith packet of n).

uint32[] P                  # Pseudorange observation.
int32[]  L_i                # Carrier phase whole cycles.
uint8[]  L_f                # Carrier phase fractional part.
int16[]  D_i                # Doppler whole Hz.
uint8[]  D_f                # Doppler fractional part.
uint8[]  cn0                # Carrier-to-Noise density. Zero implies invalid cn0.

uint8[]  lock               # Lock timer.
uint8[]  flags              # Measurement status flags.
uint8[]  sid_sat            # Constellation-specific satellite identifier.
uint8[]  sid_code           # Signal constellation, band and code.
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



(provide :piksi_rtk_msgs/Observation "9fb93688b90e872c3a77668a53e5ecc9")


