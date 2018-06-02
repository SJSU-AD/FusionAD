; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude AgeOfCorrections.msg.html

(cl:defclass <AgeOfCorrections> (roslisp-msg-protocol:ros-message)
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
   (age
    :reader age
    :initarg :age
    :type cl:fixnum
    :initform 0))
)

(cl:defclass AgeOfCorrections (<AgeOfCorrections>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AgeOfCorrections>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AgeOfCorrections)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<AgeOfCorrections> is deprecated: use piksi_rtk_msgs-msg:AgeOfCorrections instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <AgeOfCorrections>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'tow-val :lambda-list '(m))
(cl:defmethod tow-val ((m <AgeOfCorrections>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow-val is deprecated.  Use piksi_rtk_msgs-msg:tow instead.")
  (tow m))

(cl:ensure-generic-function 'age-val :lambda-list '(m))
(cl:defmethod age-val ((m <AgeOfCorrections>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:age-val is deprecated.  Use piksi_rtk_msgs-msg:age instead.")
  (age m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AgeOfCorrections>) ostream)
  "Serializes a message object of type '<AgeOfCorrections>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'age)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'age)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AgeOfCorrections>) istream)
  "Deserializes a message object of type '<AgeOfCorrections>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'age)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'age)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AgeOfCorrections>)))
  "Returns string type for a message object of type '<AgeOfCorrections>"
  "piksi_rtk_msgs/AgeOfCorrections")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AgeOfCorrections)))
  "Returns string type for a message object of type 'AgeOfCorrections"
  "piksi_rtk_msgs/AgeOfCorrections")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AgeOfCorrections>)))
  "Returns md5sum for a message object of type '<AgeOfCorrections>"
  "94c5e09b6a4cc653e4fede2c22a046bf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AgeOfCorrections)))
  "Returns md5sum for a message object of type 'AgeOfCorrections"
  "94c5e09b6a4cc653e4fede2c22a046bf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AgeOfCorrections>)))
  "Returns full string definition for message of type '<AgeOfCorrections>"
  (cl:format cl:nil "# Age of the corrections used for the current Differential solution.~%~%Header header~%~%uint32 tow      # GPS Time of Week [ms].~%uint16 age      # Age of the corrections (0xFFFF indicates invalid) [deciseconds].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AgeOfCorrections)))
  "Returns full string definition for message of type 'AgeOfCorrections"
  (cl:format cl:nil "# Age of the corrections used for the current Differential solution.~%~%Header header~%~%uint32 tow      # GPS Time of Week [ms].~%uint16 age      # Age of the corrections (0xFFFF indicates invalid) [deciseconds].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AgeOfCorrections>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AgeOfCorrections>))
  "Converts a ROS message object to a list"
  (cl:list 'AgeOfCorrections
    (cl:cons ':header (header msg))
    (cl:cons ':tow (tow msg))
    (cl:cons ':age (age msg))
))
