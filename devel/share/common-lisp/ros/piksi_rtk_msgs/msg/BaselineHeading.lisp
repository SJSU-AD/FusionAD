; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude BaselineHeading.msg.html

(cl:defclass <BaselineHeading> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (tow
    :reader tow
    :initarg :tow
    :type cl:integer
    :initform 0)
   (heading
    :reader heading
    :initarg :heading
    :type cl:integer
    :initform 0)
   (n_sats
    :reader n_sats
    :initarg :n_sats
    :type cl:fixnum
    :initform 0)
   (flags
    :reader flags
    :initarg :flags
    :type cl:fixnum
    :initform 0))
)

(cl:defclass BaselineHeading (<BaselineHeading>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BaselineHeading>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BaselineHeading)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<BaselineHeading> is deprecated: use piksi_rtk_msgs-msg:BaselineHeading instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <BaselineHeading>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'tow-val :lambda-list '(m))
(cl:defmethod tow-val ((m <BaselineHeading>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow-val is deprecated.  Use piksi_rtk_msgs-msg:tow instead.")
  (tow m))

(cl:ensure-generic-function 'heading-val :lambda-list '(m))
(cl:defmethod heading-val ((m <BaselineHeading>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:heading-val is deprecated.  Use piksi_rtk_msgs-msg:heading instead.")
  (heading m))

(cl:ensure-generic-function 'n_sats-val :lambda-list '(m))
(cl:defmethod n_sats-val ((m <BaselineHeading>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:n_sats-val is deprecated.  Use piksi_rtk_msgs-msg:n_sats instead.")
  (n_sats m))

(cl:ensure-generic-function 'flags-val :lambda-list '(m))
(cl:defmethod flags-val ((m <BaselineHeading>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:flags-val is deprecated.  Use piksi_rtk_msgs-msg:flags instead.")
  (flags m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BaselineHeading>) ostream)
  "Serializes a message object of type '<BaselineHeading>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'heading)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'heading)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'heading)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'heading)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n_sats)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BaselineHeading>) istream)
  "Deserializes a message object of type '<BaselineHeading>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'heading)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'heading)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'heading)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'heading)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n_sats)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BaselineHeading>)))
  "Returns string type for a message object of type '<BaselineHeading>"
  "piksi_rtk_msgs/BaselineHeading")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BaselineHeading)))
  "Returns string type for a message object of type 'BaselineHeading"
  "piksi_rtk_msgs/BaselineHeading")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BaselineHeading>)))
  "Returns md5sum for a message object of type '<BaselineHeading>"
  "2898fbd48c60846b0ee32eacef99afae")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BaselineHeading)))
  "Returns md5sum for a message object of type 'BaselineHeading"
  "2898fbd48c60846b0ee32eacef99afae")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BaselineHeading>)))
  "Returns full string definition for message of type '<BaselineHeading>"
  (cl:format cl:nil "# This message reports the baseline heading pointing from the base station to the rover relative to True~%# North. The full GPS time is given by the preceding MSG GPS TIME with the matching time-of-week~%# (tow). It is intended that time-matched RTK mode is used when the base station is moving.~%~%Header header~%~%uint32 tow          # GPS Time of Week [ms].~%uint32 heading      # Heading [mdeg].~%uint8  n_sats       # Number of satellites used in solution~%uint8  flags        # Status flag.~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BaselineHeading)))
  "Returns full string definition for message of type 'BaselineHeading"
  (cl:format cl:nil "# This message reports the baseline heading pointing from the base station to the rover relative to True~%# North. The full GPS time is given by the preceding MSG GPS TIME with the matching time-of-week~%# (tow). It is intended that time-matched RTK mode is used when the base station is moving.~%~%Header header~%~%uint32 tow          # GPS Time of Week [ms].~%uint32 heading      # Heading [mdeg].~%uint8  n_sats       # Number of satellites used in solution~%uint8  flags        # Status flag.~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BaselineHeading>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BaselineHeading>))
  "Converts a ROS message object to a list"
  (cl:list 'BaselineHeading
    (cl:cons ':header (header msg))
    (cl:cons ':tow (tow msg))
    (cl:cons ':heading (heading msg))
    (cl:cons ':n_sats (n_sats msg))
    (cl:cons ':flags (flags msg))
))
