; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude TrackingState_V2_3_15.msg.html

(cl:defclass <TrackingState_V2_3_15> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (sat
    :reader sat
    :initarg :sat
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (code
    :reader code
    :initarg :code
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (fcn
    :reader fcn
    :initarg :fcn
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (cn0
    :reader cn0
    :initarg :cn0
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass TrackingState_V2_3_15 (<TrackingState_V2_3_15>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TrackingState_V2_3_15>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TrackingState_V2_3_15)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<TrackingState_V2_3_15> is deprecated: use piksi_rtk_msgs-msg:TrackingState_V2_3_15 instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <TrackingState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'sat-val :lambda-list '(m))
(cl:defmethod sat-val ((m <TrackingState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:sat-val is deprecated.  Use piksi_rtk_msgs-msg:sat instead.")
  (sat m))

(cl:ensure-generic-function 'code-val :lambda-list '(m))
(cl:defmethod code-val ((m <TrackingState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:code-val is deprecated.  Use piksi_rtk_msgs-msg:code instead.")
  (code m))

(cl:ensure-generic-function 'fcn-val :lambda-list '(m))
(cl:defmethod fcn-val ((m <TrackingState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:fcn-val is deprecated.  Use piksi_rtk_msgs-msg:fcn instead.")
  (fcn m))

(cl:ensure-generic-function 'cn0-val :lambda-list '(m))
(cl:defmethod cn0-val ((m <TrackingState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:cn0-val is deprecated.  Use piksi_rtk_msgs-msg:cn0 instead.")
  (cn0 m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<TrackingState_V2_3_15>)))
    "Constants for message type '<TrackingState_V2_3_15>"
  '((:CODE_GPS_L1CA . 0)
    (:CODE_GPS_L2CM . 1)
    (:CODE_SBAS_L1CA . 2)
    (:CODE_GLO_L1CA . 3)
    (:CODE_GLO_L2CA . 4)
    (:CODE_GPS_L1P . 5)
    (:CODE_GPS_L2P . 6))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'TrackingState_V2_3_15)))
    "Constants for message type 'TrackingState_V2_3_15"
  '((:CODE_GPS_L1CA . 0)
    (:CODE_GPS_L2CM . 1)
    (:CODE_SBAS_L1CA . 2)
    (:CODE_GLO_L1CA . 3)
    (:CODE_GLO_L2CA . 4)
    (:CODE_GPS_L1P . 5)
    (:CODE_GPS_L2P . 6))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TrackingState_V2_3_15>) ostream)
  "Serializes a message object of type '<TrackingState_V2_3_15>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'sat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'sat))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'code))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'code))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'fcn))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'fcn))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'cn0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'cn0))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TrackingState_V2_3_15>) istream)
  "Deserializes a message object of type '<TrackingState_V2_3_15>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'sat) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'sat)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'code) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'code)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'fcn) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'fcn)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'cn0) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'cn0)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TrackingState_V2_3_15>)))
  "Returns string type for a message object of type '<TrackingState_V2_3_15>"
  "piksi_rtk_msgs/TrackingState_V2_3_15")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TrackingState_V2_3_15)))
  "Returns string type for a message object of type 'TrackingState_V2_3_15"
  "piksi_rtk_msgs/TrackingState_V2_3_15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TrackingState_V2_3_15>)))
  "Returns md5sum for a message object of type '<TrackingState_V2_3_15>"
  "0a051c9934e022ee2abf2e31fc142ed2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TrackingState_V2_3_15)))
  "Returns md5sum for a message object of type 'TrackingState_V2_3_15"
  "0a051c9934e022ee2abf2e31fc142ed2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TrackingState_V2_3_15>)))
  "Returns full string definition for message of type '<TrackingState_V2_3_15>"
  (cl:format cl:nil "# The tracking message returns a variable-length array of tracking channel states. It reports status and~%# carrier-to-noise density measurements for all tracked satellites.~%~%# Message definition based on libsbp v2.3.15~%~%Header header~%~%uint8[] sat     # Constellation-specific satellite identifier.~%uint8[] code    # Signal constellation, band and code.~%uint8[] fcn     # Frequency channel number (GLONASS only).~%uint8[] cn0     # Carrier-to-Noise density. Zero implies invalid cn0 [dB Hz / 4].~%~%~%uint8 CODE_GPS_L1CA     = 0~%uint8 CODE_GPS_L2CM     = 1~%uint8 CODE_SBAS_L1CA    = 2~%uint8 CODE_GLO_L1CA     = 3~%uint8 CODE_GLO_L2CA     = 4~%uint8 CODE_GPS_L1P      = 5~%uint8 CODE_GPS_L2P      = 6~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TrackingState_V2_3_15)))
  "Returns full string definition for message of type 'TrackingState_V2_3_15"
  (cl:format cl:nil "# The tracking message returns a variable-length array of tracking channel states. It reports status and~%# carrier-to-noise density measurements for all tracked satellites.~%~%# Message definition based on libsbp v2.3.15~%~%Header header~%~%uint8[] sat     # Constellation-specific satellite identifier.~%uint8[] code    # Signal constellation, band and code.~%uint8[] fcn     # Frequency channel number (GLONASS only).~%uint8[] cn0     # Carrier-to-Noise density. Zero implies invalid cn0 [dB Hz / 4].~%~%~%uint8 CODE_GPS_L1CA     = 0~%uint8 CODE_GPS_L2CM     = 1~%uint8 CODE_SBAS_L1CA    = 2~%uint8 CODE_GLO_L1CA     = 3~%uint8 CODE_GLO_L2CA     = 4~%uint8 CODE_GPS_L1P      = 5~%uint8 CODE_GPS_L2P      = 6~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TrackingState_V2_3_15>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'sat) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'code) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'fcn) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'cn0) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TrackingState_V2_3_15>))
  "Converts a ROS message object to a list"
  (cl:list 'TrackingState_V2_3_15
    (cl:cons ':header (header msg))
    (cl:cons ':sat (sat msg))
    (cl:cons ':code (code msg))
    (cl:cons ':fcn (fcn msg))
    (cl:cons ':cn0 (cn0 msg))
))
