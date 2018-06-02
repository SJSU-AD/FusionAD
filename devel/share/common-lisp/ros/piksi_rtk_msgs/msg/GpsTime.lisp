; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude GpsTime.msg.html

(cl:defclass <GpsTime> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (wn
    :reader wn
    :initarg :wn
    :type cl:integer
    :initform 0)
   (tow
    :reader tow
    :initarg :tow
    :type cl:integer
    :initform 0)
   (ns
    :reader ns
    :initarg :ns
    :type cl:integer
    :initform 0)
   (flags
    :reader flags
    :initarg :flags
    :type cl:fixnum
    :initform 0))
)

(cl:defclass GpsTime (<GpsTime>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GpsTime>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GpsTime)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<GpsTime> is deprecated: use piksi_rtk_msgs-msg:GpsTime instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <GpsTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'wn-val :lambda-list '(m))
(cl:defmethod wn-val ((m <GpsTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:wn-val is deprecated.  Use piksi_rtk_msgs-msg:wn instead.")
  (wn m))

(cl:ensure-generic-function 'tow-val :lambda-list '(m))
(cl:defmethod tow-val ((m <GpsTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow-val is deprecated.  Use piksi_rtk_msgs-msg:tow instead.")
  (tow m))

(cl:ensure-generic-function 'ns-val :lambda-list '(m))
(cl:defmethod ns-val ((m <GpsTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:ns-val is deprecated.  Use piksi_rtk_msgs-msg:ns instead.")
  (ns m))

(cl:ensure-generic-function 'flags-val :lambda-list '(m))
(cl:defmethod flags-val ((m <GpsTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:flags-val is deprecated.  Use piksi_rtk_msgs-msg:flags instead.")
  (flags m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GpsTime>) ostream)
  "Serializes a message object of type '<GpsTime>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wn)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'wn)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'wn)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'wn)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'ns)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GpsTime>) istream)
  "Deserializes a message object of type '<GpsTime>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wn)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'wn)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'wn)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'wn)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ns) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GpsTime>)))
  "Returns string type for a message object of type '<GpsTime>"
  "piksi_rtk_msgs/GpsTime")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GpsTime)))
  "Returns string type for a message object of type 'GpsTime"
  "piksi_rtk_msgs/GpsTime")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GpsTime>)))
  "Returns md5sum for a message object of type '<GpsTime>"
  "d960bffb66122e272126ef7f2b6ef072")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GpsTime)))
  "Returns md5sum for a message object of type 'GpsTime"
  "d960bffb66122e272126ef7f2b6ef072")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GpsTime>)))
  "Returns full string definition for message of type '<GpsTime>"
  (cl:format cl:nil "# This message reports the GPS time, representing the time since the GPS epoch began on midnight~%# January 6, 1980 UTC. GPS time counts the weeks and seconds of the week. The weeks begin at the~%# Saturday/Sunday transition. GPS week 0 began at the beginning of the GPS time scale.~%# Within each week number, the GPS time of the week is between between 0 and 604800 seconds~%# (=60*60*24*7). Note that GPS time does not accumulate leap seconds, and as of now, has a small offset~%# from UTC. In a message stream, this message precedes a set of other navigation messages referenced~%# to the same time (but lacking the ns field) and indicates a more precise time of these messages.~%~%Header header~%~%uint32 wn   # GPS week number.~%uint32 tow  # GPS time of week rounded to the nearest millisecond [ms].~%int32 ns    # Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000) [ns].~%uint8 flags # Status flags (reserved).~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GpsTime)))
  "Returns full string definition for message of type 'GpsTime"
  (cl:format cl:nil "# This message reports the GPS time, representing the time since the GPS epoch began on midnight~%# January 6, 1980 UTC. GPS time counts the weeks and seconds of the week. The weeks begin at the~%# Saturday/Sunday transition. GPS week 0 began at the beginning of the GPS time scale.~%# Within each week number, the GPS time of the week is between between 0 and 604800 seconds~%# (=60*60*24*7). Note that GPS time does not accumulate leap seconds, and as of now, has a small offset~%# from UTC. In a message stream, this message precedes a set of other navigation messages referenced~%# to the same time (but lacking the ns field) and indicates a more precise time of these messages.~%~%Header header~%~%uint32 wn   # GPS week number.~%uint32 tow  # GPS time of week rounded to the nearest millisecond [ms].~%int32 ns    # Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000) [ns].~%uint8 flags # Status flags (reserved).~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GpsTime>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GpsTime>))
  "Converts a ROS message object to a list"
  (cl:list 'GpsTime
    (cl:cons ':header (header msg))
    (cl:cons ':wn (wn msg))
    (cl:cons ':tow (tow msg))
    (cl:cons ':ns (ns msg))
    (cl:cons ':flags (flags msg))
))
