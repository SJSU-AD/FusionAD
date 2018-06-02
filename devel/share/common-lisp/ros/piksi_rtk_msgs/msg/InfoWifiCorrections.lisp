; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude InfoWifiCorrections.msg.html

(cl:defclass <InfoWifiCorrections> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (received_corrections
    :reader received_corrections
    :initarg :received_corrections
    :type cl:integer
    :initform 0)
   (latency
    :reader latency
    :initarg :latency
    :type cl:float
    :initform 0.0))
)

(cl:defclass InfoWifiCorrections (<InfoWifiCorrections>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <InfoWifiCorrections>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'InfoWifiCorrections)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<InfoWifiCorrections> is deprecated: use piksi_rtk_msgs-msg:InfoWifiCorrections instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <InfoWifiCorrections>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'received_corrections-val :lambda-list '(m))
(cl:defmethod received_corrections-val ((m <InfoWifiCorrections>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:received_corrections-val is deprecated.  Use piksi_rtk_msgs-msg:received_corrections instead.")
  (received_corrections m))

(cl:ensure-generic-function 'latency-val :lambda-list '(m))
(cl:defmethod latency-val ((m <InfoWifiCorrections>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:latency-val is deprecated.  Use piksi_rtk_msgs-msg:latency instead.")
  (latency m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <InfoWifiCorrections>) ostream)
  "Serializes a message object of type '<InfoWifiCorrections>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'received_corrections)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'received_corrections)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'received_corrections)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'received_corrections)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'latency))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <InfoWifiCorrections>) istream)
  "Deserializes a message object of type '<InfoWifiCorrections>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'received_corrections)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'received_corrections)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'received_corrections)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'received_corrections)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'latency) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<InfoWifiCorrections>)))
  "Returns string type for a message object of type '<InfoWifiCorrections>"
  "piksi_rtk_msgs/InfoWifiCorrections")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'InfoWifiCorrections)))
  "Returns string type for a message object of type 'InfoWifiCorrections"
  "piksi_rtk_msgs/InfoWifiCorrections")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<InfoWifiCorrections>)))
  "Returns md5sum for a message object of type '<InfoWifiCorrections>"
  "925248c7afa695eb59c83cfd29d8c57c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'InfoWifiCorrections)))
  "Returns md5sum for a message object of type 'InfoWifiCorrections"
  "925248c7afa695eb59c83cfd29d8c57c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<InfoWifiCorrections>)))
  "Returns full string definition for message of type '<InfoWifiCorrections>"
  (cl:format cl:nil "# Information about Corrections received over WiFi.~%~%Header header~%~%uint32 received_corrections # number of correction received from start up~%float32 latency # latency from base station, -1 if not sampled [ms].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'InfoWifiCorrections)))
  "Returns full string definition for message of type 'InfoWifiCorrections"
  (cl:format cl:nil "# Information about Corrections received over WiFi.~%~%Header header~%~%uint32 received_corrections # number of correction received from start up~%float32 latency # latency from base station, -1 if not sampled [ms].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <InfoWifiCorrections>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <InfoWifiCorrections>))
  "Converts a ROS message object to a list"
  (cl:list 'InfoWifiCorrections
    (cl:cons ':header (header msg))
    (cl:cons ':received_corrections (received_corrections msg))
    (cl:cons ':latency (latency msg))
))
