; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude UartState_V2_3_15.msg.html

(cl:defclass <UartState_V2_3_15> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (latency_avg
    :reader latency_avg
    :initarg :latency_avg
    :type cl:integer
    :initform 0)
   (latency_lmin
    :reader latency_lmin
    :initarg :latency_lmin
    :type cl:integer
    :initform 0)
   (latency_lmax
    :reader latency_lmax
    :initarg :latency_lmax
    :type cl:integer
    :initform 0)
   (latency_current
    :reader latency_current
    :initarg :latency_current
    :type cl:integer
    :initform 0)
   (obs_period_avg
    :reader obs_period_avg
    :initarg :obs_period_avg
    :type cl:integer
    :initform 0)
   (obs_period_pmin
    :reader obs_period_pmin
    :initarg :obs_period_pmin
    :type cl:integer
    :initform 0)
   (obs_period_pmax
    :reader obs_period_pmax
    :initarg :obs_period_pmax
    :type cl:integer
    :initform 0)
   (obs_period_current
    :reader obs_period_current
    :initarg :obs_period_current
    :type cl:integer
    :initform 0))
)

(cl:defclass UartState_V2_3_15 (<UartState_V2_3_15>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UartState_V2_3_15>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UartState_V2_3_15)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<UartState_V2_3_15> is deprecated: use piksi_rtk_msgs-msg:UartState_V2_3_15 instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <UartState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'latency_avg-val :lambda-list '(m))
(cl:defmethod latency_avg-val ((m <UartState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:latency_avg-val is deprecated.  Use piksi_rtk_msgs-msg:latency_avg instead.")
  (latency_avg m))

(cl:ensure-generic-function 'latency_lmin-val :lambda-list '(m))
(cl:defmethod latency_lmin-val ((m <UartState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:latency_lmin-val is deprecated.  Use piksi_rtk_msgs-msg:latency_lmin instead.")
  (latency_lmin m))

(cl:ensure-generic-function 'latency_lmax-val :lambda-list '(m))
(cl:defmethod latency_lmax-val ((m <UartState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:latency_lmax-val is deprecated.  Use piksi_rtk_msgs-msg:latency_lmax instead.")
  (latency_lmax m))

(cl:ensure-generic-function 'latency_current-val :lambda-list '(m))
(cl:defmethod latency_current-val ((m <UartState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:latency_current-val is deprecated.  Use piksi_rtk_msgs-msg:latency_current instead.")
  (latency_current m))

(cl:ensure-generic-function 'obs_period_avg-val :lambda-list '(m))
(cl:defmethod obs_period_avg-val ((m <UartState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:obs_period_avg-val is deprecated.  Use piksi_rtk_msgs-msg:obs_period_avg instead.")
  (obs_period_avg m))

(cl:ensure-generic-function 'obs_period_pmin-val :lambda-list '(m))
(cl:defmethod obs_period_pmin-val ((m <UartState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:obs_period_pmin-val is deprecated.  Use piksi_rtk_msgs-msg:obs_period_pmin instead.")
  (obs_period_pmin m))

(cl:ensure-generic-function 'obs_period_pmax-val :lambda-list '(m))
(cl:defmethod obs_period_pmax-val ((m <UartState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:obs_period_pmax-val is deprecated.  Use piksi_rtk_msgs-msg:obs_period_pmax instead.")
  (obs_period_pmax m))

(cl:ensure-generic-function 'obs_period_current-val :lambda-list '(m))
(cl:defmethod obs_period_current-val ((m <UartState_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:obs_period_current-val is deprecated.  Use piksi_rtk_msgs-msg:obs_period_current instead.")
  (obs_period_current m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UartState_V2_3_15>) ostream)
  "Serializes a message object of type '<UartState_V2_3_15>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'latency_avg)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'latency_lmin)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'latency_lmax)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'latency_current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_period_avg)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_period_pmin)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_period_pmax)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_period_current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UartState_V2_3_15>) istream)
  "Deserializes a message object of type '<UartState_V2_3_15>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'latency_avg) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'latency_lmin) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'latency_lmax) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'latency_current) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_period_avg) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_period_pmin) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_period_pmax) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_period_current) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UartState_V2_3_15>)))
  "Returns string type for a message object of type '<UartState_V2_3_15>"
  "piksi_rtk_msgs/UartState_V2_3_15")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UartState_V2_3_15)))
  "Returns string type for a message object of type 'UartState_V2_3_15"
  "piksi_rtk_msgs/UartState_V2_3_15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UartState_V2_3_15>)))
  "Returns md5sum for a message object of type '<UartState_V2_3_15>"
  "eab7c26cb7da9615284c0c7450fdcec3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UartState_V2_3_15)))
  "Returns md5sum for a message object of type 'UartState_V2_3_15"
  "eab7c26cb7da9615284c0c7450fdcec3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UartState_V2_3_15>)))
  "Returns full string definition for message of type '<UartState_V2_3_15>"
  (cl:format cl:nil "# The UART message reports data latency and throughput of the UART channels providing SBP I/O.~%~%# Message definition based on libsbp v2.3.15, only some field were selected for the original SBP message (same ones~%# used in piksi_tools/console/system_monitor_view.py, function \"uart_state_callback\").~%~%Header header~%~%int32 latency_avg               # Average latency [ms].~%int32 latency_lmin              # Minimum latency [ms].~%int32 latency_lmax              # Maximum latency [ms].~%int32 latency_current           # Smoothed estimate of the current latency [ms].~%int32 obs_period_avg            # Average period [ms].~%int32 obs_period_pmin           # Minimum period [ms].~%int32 obs_period_pmax           # Maximum period [ms].~%int32 obs_period_current        # Smoothed estimate of the current preiod [ms].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UartState_V2_3_15)))
  "Returns full string definition for message of type 'UartState_V2_3_15"
  (cl:format cl:nil "# The UART message reports data latency and throughput of the UART channels providing SBP I/O.~%~%# Message definition based on libsbp v2.3.15, only some field were selected for the original SBP message (same ones~%# used in piksi_tools/console/system_monitor_view.py, function \"uart_state_callback\").~%~%Header header~%~%int32 latency_avg               # Average latency [ms].~%int32 latency_lmin              # Minimum latency [ms].~%int32 latency_lmax              # Maximum latency [ms].~%int32 latency_current           # Smoothed estimate of the current latency [ms].~%int32 obs_period_avg            # Average period [ms].~%int32 obs_period_pmin           # Minimum period [ms].~%int32 obs_period_pmax           # Maximum period [ms].~%int32 obs_period_current        # Smoothed estimate of the current preiod [ms].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UartState_V2_3_15>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UartState_V2_3_15>))
  "Converts a ROS message object to a list"
  (cl:list 'UartState_V2_3_15
    (cl:cons ':header (header msg))
    (cl:cons ':latency_avg (latency_avg msg))
    (cl:cons ':latency_lmin (latency_lmin msg))
    (cl:cons ':latency_lmax (latency_lmax msg))
    (cl:cons ':latency_current (latency_current msg))
    (cl:cons ':obs_period_avg (obs_period_avg msg))
    (cl:cons ':obs_period_pmin (obs_period_pmin msg))
    (cl:cons ':obs_period_pmax (obs_period_pmax msg))
    (cl:cons ':obs_period_current (obs_period_current msg))
))
