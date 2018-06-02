; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude DopsMulti.msg.html

(cl:defclass <DopsMulti> (roslisp-msg-protocol:ros-message)
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
   (gdop
    :reader gdop
    :initarg :gdop
    :type cl:fixnum
    :initform 0)
   (pdop
    :reader pdop
    :initarg :pdop
    :type cl:fixnum
    :initform 0)
   (tdop
    :reader tdop
    :initarg :tdop
    :type cl:fixnum
    :initform 0)
   (hdop
    :reader hdop
    :initarg :hdop
    :type cl:fixnum
    :initform 0)
   (vdop
    :reader vdop
    :initarg :vdop
    :type cl:fixnum
    :initform 0)
   (flags
    :reader flags
    :initarg :flags
    :type cl:fixnum
    :initform 0))
)

(cl:defclass DopsMulti (<DopsMulti>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DopsMulti>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DopsMulti)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<DopsMulti> is deprecated: use piksi_rtk_msgs-msg:DopsMulti instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <DopsMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'tow-val :lambda-list '(m))
(cl:defmethod tow-val ((m <DopsMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow-val is deprecated.  Use piksi_rtk_msgs-msg:tow instead.")
  (tow m))

(cl:ensure-generic-function 'gdop-val :lambda-list '(m))
(cl:defmethod gdop-val ((m <DopsMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:gdop-val is deprecated.  Use piksi_rtk_msgs-msg:gdop instead.")
  (gdop m))

(cl:ensure-generic-function 'pdop-val :lambda-list '(m))
(cl:defmethod pdop-val ((m <DopsMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:pdop-val is deprecated.  Use piksi_rtk_msgs-msg:pdop instead.")
  (pdop m))

(cl:ensure-generic-function 'tdop-val :lambda-list '(m))
(cl:defmethod tdop-val ((m <DopsMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tdop-val is deprecated.  Use piksi_rtk_msgs-msg:tdop instead.")
  (tdop m))

(cl:ensure-generic-function 'hdop-val :lambda-list '(m))
(cl:defmethod hdop-val ((m <DopsMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:hdop-val is deprecated.  Use piksi_rtk_msgs-msg:hdop instead.")
  (hdop m))

(cl:ensure-generic-function 'vdop-val :lambda-list '(m))
(cl:defmethod vdop-val ((m <DopsMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:vdop-val is deprecated.  Use piksi_rtk_msgs-msg:vdop instead.")
  (vdop m))

(cl:ensure-generic-function 'flags-val :lambda-list '(m))
(cl:defmethod flags-val ((m <DopsMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:flags-val is deprecated.  Use piksi_rtk_msgs-msg:flags instead.")
  (flags m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DopsMulti>) ostream)
  "Serializes a message object of type '<DopsMulti>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'gdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'hdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'vdop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DopsMulti>) istream)
  "Deserializes a message object of type '<DopsMulti>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'gdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'hdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'vdop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DopsMulti>)))
  "Returns string type for a message object of type '<DopsMulti>"
  "piksi_rtk_msgs/DopsMulti")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DopsMulti)))
  "Returns string type for a message object of type 'DopsMulti"
  "piksi_rtk_msgs/DopsMulti")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DopsMulti>)))
  "Returns md5sum for a message object of type '<DopsMulti>"
  "c8ec518c5a95442b85a41a69915d3477")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DopsMulti)))
  "Returns md5sum for a message object of type 'DopsMulti"
  "c8ec518c5a95442b85a41a69915d3477")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DopsMulti>)))
  "Returns full string definition for message of type '<DopsMulti>"
  (cl:format cl:nil "# This dilution of precision (DOP) message describes the effect of navigation satellite geometry on positional~%# measurement precision.~%~%Header header~%~%uint32 tow  # GPS Time of Week [ms].~%uint16 gdop # Geometric Dilution of Precision.~%uint16 pdop # Position Dilution of Precision.~%uint16 tdop # Time Dilution of Precision.~%uint16 hdop # Horizontal Dilution of Precision.~%uint16 vdop # Vertical Dilution of Precision.~%uint8 flags # Indicates the position solution with which the DOPS message corresponds.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DopsMulti)))
  "Returns full string definition for message of type 'DopsMulti"
  (cl:format cl:nil "# This dilution of precision (DOP) message describes the effect of navigation satellite geometry on positional~%# measurement precision.~%~%Header header~%~%uint32 tow  # GPS Time of Week [ms].~%uint16 gdop # Geometric Dilution of Precision.~%uint16 pdop # Position Dilution of Precision.~%uint16 tdop # Time Dilution of Precision.~%uint16 hdop # Horizontal Dilution of Precision.~%uint16 vdop # Vertical Dilution of Precision.~%uint8 flags # Indicates the position solution with which the DOPS message corresponds.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DopsMulti>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     2
     2
     2
     2
     2
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DopsMulti>))
  "Converts a ROS message object to a list"
  (cl:list 'DopsMulti
    (cl:cons ':header (header msg))
    (cl:cons ':tow (tow msg))
    (cl:cons ':gdop (gdop msg))
    (cl:cons ':pdop (pdop msg))
    (cl:cons ':tdop (tdop msg))
    (cl:cons ':hdop (hdop msg))
    (cl:cons ':vdop (vdop msg))
    (cl:cons ':flags (flags msg))
))
