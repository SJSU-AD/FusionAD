; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude Heartbeat.msg.html

(cl:defclass <Heartbeat> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (system_error
    :reader system_error
    :initarg :system_error
    :type cl:fixnum
    :initform 0)
   (io_error
    :reader io_error
    :initarg :io_error
    :type cl:fixnum
    :initform 0)
   (swift_nap_error
    :reader swift_nap_error
    :initarg :swift_nap_error
    :type cl:fixnum
    :initform 0)
   (sbp_minor_version
    :reader sbp_minor_version
    :initarg :sbp_minor_version
    :type cl:fixnum
    :initform 0)
   (sbp_major_version
    :reader sbp_major_version
    :initarg :sbp_major_version
    :type cl:fixnum
    :initform 0)
   (external_antenna_present
    :reader external_antenna_present
    :initarg :external_antenna_present
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Heartbeat (<Heartbeat>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Heartbeat>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Heartbeat)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<Heartbeat> is deprecated: use piksi_rtk_msgs-msg:Heartbeat instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Heartbeat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'system_error-val :lambda-list '(m))
(cl:defmethod system_error-val ((m <Heartbeat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:system_error-val is deprecated.  Use piksi_rtk_msgs-msg:system_error instead.")
  (system_error m))

(cl:ensure-generic-function 'io_error-val :lambda-list '(m))
(cl:defmethod io_error-val ((m <Heartbeat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:io_error-val is deprecated.  Use piksi_rtk_msgs-msg:io_error instead.")
  (io_error m))

(cl:ensure-generic-function 'swift_nap_error-val :lambda-list '(m))
(cl:defmethod swift_nap_error-val ((m <Heartbeat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:swift_nap_error-val is deprecated.  Use piksi_rtk_msgs-msg:swift_nap_error instead.")
  (swift_nap_error m))

(cl:ensure-generic-function 'sbp_minor_version-val :lambda-list '(m))
(cl:defmethod sbp_minor_version-val ((m <Heartbeat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:sbp_minor_version-val is deprecated.  Use piksi_rtk_msgs-msg:sbp_minor_version instead.")
  (sbp_minor_version m))

(cl:ensure-generic-function 'sbp_major_version-val :lambda-list '(m))
(cl:defmethod sbp_major_version-val ((m <Heartbeat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:sbp_major_version-val is deprecated.  Use piksi_rtk_msgs-msg:sbp_major_version instead.")
  (sbp_major_version m))

(cl:ensure-generic-function 'external_antenna_present-val :lambda-list '(m))
(cl:defmethod external_antenna_present-val ((m <Heartbeat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:external_antenna_present-val is deprecated.  Use piksi_rtk_msgs-msg:external_antenna_present instead.")
  (external_antenna_present m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Heartbeat>) ostream)
  "Serializes a message object of type '<Heartbeat>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_error)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'io_error)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'swift_nap_error)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sbp_minor_version)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sbp_major_version)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'external_antenna_present)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Heartbeat>) istream)
  "Deserializes a message object of type '<Heartbeat>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_error)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'io_error)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'swift_nap_error)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sbp_minor_version)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sbp_major_version)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'external_antenna_present)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Heartbeat>)))
  "Returns string type for a message object of type '<Heartbeat>"
  "piksi_rtk_msgs/Heartbeat")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Heartbeat)))
  "Returns string type for a message object of type 'Heartbeat"
  "piksi_rtk_msgs/Heartbeat")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Heartbeat>)))
  "Returns md5sum for a message object of type '<Heartbeat>"
  "f302769a534aa6ff5a3f6b1f1c11f4bc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Heartbeat)))
  "Returns md5sum for a message object of type 'Heartbeat"
  "f302769a534aa6ff5a3f6b1f1c11f4bc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Heartbeat>)))
  "Returns full string definition for message of type '<Heartbeat>"
  (cl:format cl:nil "# The heartbeat message is sent periodically to inform the host or other attached devices that the system~%# is running. It is used to monitor system malfunctions. It also contains status flags that indicate to the~%# host the status of the system and whether it is operating correctly. Currently, the expected heartbeat~%# interval is 1 sec.~%# The system error flag is used to indicate that an error has occurred in the system. To determine the~%# source of the error, the remaining error flags should be inspected.~%~%Header header~%~%uint8 system_error              # System Error Flag.~%uint8 io_error                  # IO Error Flag.~%uint8 swift_nap_error           # SwiftNAP Error Flag.~%uint8 sbp_minor_version         # SBP Minor Protocol Version Number.~%uint8 sbp_major_version         # SBP Major Protocol Version Number.~%uint8 external_antenna_present  # External Antenna Present Flag.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Heartbeat)))
  "Returns full string definition for message of type 'Heartbeat"
  (cl:format cl:nil "# The heartbeat message is sent periodically to inform the host or other attached devices that the system~%# is running. It is used to monitor system malfunctions. It also contains status flags that indicate to the~%# host the status of the system and whether it is operating correctly. Currently, the expected heartbeat~%# interval is 1 sec.~%# The system error flag is used to indicate that an error has occurred in the system. To determine the~%# source of the error, the remaining error flags should be inspected.~%~%Header header~%~%uint8 system_error              # System Error Flag.~%uint8 io_error                  # IO Error Flag.~%uint8 swift_nap_error           # SwiftNAP Error Flag.~%uint8 sbp_minor_version         # SBP Minor Protocol Version Number.~%uint8 sbp_major_version         # SBP Major Protocol Version Number.~%uint8 external_antenna_present  # External Antenna Present Flag.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Heartbeat>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Heartbeat>))
  "Converts a ROS message object to a list"
  (cl:list 'Heartbeat
    (cl:cons ':header (header msg))
    (cl:cons ':system_error (system_error msg))
    (cl:cons ':io_error (io_error msg))
    (cl:cons ':swift_nap_error (swift_nap_error msg))
    (cl:cons ':sbp_minor_version (sbp_minor_version msg))
    (cl:cons ':sbp_major_version (sbp_major_version msg))
    (cl:cons ':external_antenna_present (external_antenna_present msg))
))
