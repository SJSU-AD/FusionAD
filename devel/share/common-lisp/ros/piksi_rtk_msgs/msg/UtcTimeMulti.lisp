; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude UtcTimeMulti.msg.html

(cl:defclass <UtcTimeMulti> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (flags
    :reader flags
    :initarg :flags
    :type cl:fixnum
    :initform 0)
   (tow
    :reader tow
    :initarg :tow
    :type cl:integer
    :initform 0)
   (year
    :reader year
    :initarg :year
    :type cl:fixnum
    :initform 0)
   (month
    :reader month
    :initarg :month
    :type cl:fixnum
    :initform 0)
   (day
    :reader day
    :initarg :day
    :type cl:fixnum
    :initform 0)
   (hours
    :reader hours
    :initarg :hours
    :type cl:fixnum
    :initform 0)
   (minutes
    :reader minutes
    :initarg :minutes
    :type cl:fixnum
    :initform 0)
   (seconds
    :reader seconds
    :initarg :seconds
    :type cl:fixnum
    :initform 0)
   (ns
    :reader ns
    :initarg :ns
    :type cl:integer
    :initform 0))
)

(cl:defclass UtcTimeMulti (<UtcTimeMulti>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UtcTimeMulti>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UtcTimeMulti)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<UtcTimeMulti> is deprecated: use piksi_rtk_msgs-msg:UtcTimeMulti instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'flags-val :lambda-list '(m))
(cl:defmethod flags-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:flags-val is deprecated.  Use piksi_rtk_msgs-msg:flags instead.")
  (flags m))

(cl:ensure-generic-function 'tow-val :lambda-list '(m))
(cl:defmethod tow-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow-val is deprecated.  Use piksi_rtk_msgs-msg:tow instead.")
  (tow m))

(cl:ensure-generic-function 'year-val :lambda-list '(m))
(cl:defmethod year-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:year-val is deprecated.  Use piksi_rtk_msgs-msg:year instead.")
  (year m))

(cl:ensure-generic-function 'month-val :lambda-list '(m))
(cl:defmethod month-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:month-val is deprecated.  Use piksi_rtk_msgs-msg:month instead.")
  (month m))

(cl:ensure-generic-function 'day-val :lambda-list '(m))
(cl:defmethod day-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:day-val is deprecated.  Use piksi_rtk_msgs-msg:day instead.")
  (day m))

(cl:ensure-generic-function 'hours-val :lambda-list '(m))
(cl:defmethod hours-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:hours-val is deprecated.  Use piksi_rtk_msgs-msg:hours instead.")
  (hours m))

(cl:ensure-generic-function 'minutes-val :lambda-list '(m))
(cl:defmethod minutes-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:minutes-val is deprecated.  Use piksi_rtk_msgs-msg:minutes instead.")
  (minutes m))

(cl:ensure-generic-function 'seconds-val :lambda-list '(m))
(cl:defmethod seconds-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:seconds-val is deprecated.  Use piksi_rtk_msgs-msg:seconds instead.")
  (seconds m))

(cl:ensure-generic-function 'ns-val :lambda-list '(m))
(cl:defmethod ns-val ((m <UtcTimeMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:ns-val is deprecated.  Use piksi_rtk_msgs-msg:ns instead.")
  (ns m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UtcTimeMulti>) ostream)
  "Serializes a message object of type '<UtcTimeMulti>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'year)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'year)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'month)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'day)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hours)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'minutes)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'seconds)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ns)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ns)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ns)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ns)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UtcTimeMulti>) istream)
  "Deserializes a message object of type '<UtcTimeMulti>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'year)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'year)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'month)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'day)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hours)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'minutes)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'seconds)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ns)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ns)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ns)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ns)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UtcTimeMulti>)))
  "Returns string type for a message object of type '<UtcTimeMulti>"
  "piksi_rtk_msgs/UtcTimeMulti")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UtcTimeMulti)))
  "Returns string type for a message object of type 'UtcTimeMulti"
  "piksi_rtk_msgs/UtcTimeMulti")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UtcTimeMulti>)))
  "Returns md5sum for a message object of type '<UtcTimeMulti>"
  "305f41bf5fdb87de324a10b06c47c614")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UtcTimeMulti)))
  "Returns md5sum for a message object of type 'UtcTimeMulti"
  "305f41bf5fdb87de324a10b06c47c614")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UtcTimeMulti>)))
  "Returns full string definition for message of type '<UtcTimeMulti>"
  (cl:format cl:nil "# This message reports the Universal Coordinated Time (UTC). Note the flags which~%# indicate the source of the UTC offset value and source of the time fix.~%~%Header header~%~%uint8 flags   # Indicates source and time validity~%uint32 tow    # GPS time of week rounded to the nearest millisecond~%uint16 year   # Year~%uint8 month   # Month (range 1 .. 12)~%uint8 day     # days in the month (range 1-31)~%uint8 hours   # hours of day (range 0-23)~%uint8 minutes # minutes of hour (range 0-59)~%uint8 seconds # seconds of minute (range 0-60) rounded down~%uint32 ns     # nanoseconds of second (range 0-999999999)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UtcTimeMulti)))
  "Returns full string definition for message of type 'UtcTimeMulti"
  (cl:format cl:nil "# This message reports the Universal Coordinated Time (UTC). Note the flags which~%# indicate the source of the UTC offset value and source of the time fix.~%~%Header header~%~%uint8 flags   # Indicates source and time validity~%uint32 tow    # GPS time of week rounded to the nearest millisecond~%uint16 year   # Year~%uint8 month   # Month (range 1 .. 12)~%uint8 day     # days in the month (range 1-31)~%uint8 hours   # hours of day (range 0-23)~%uint8 minutes # minutes of hour (range 0-59)~%uint8 seconds # seconds of minute (range 0-60) rounded down~%uint32 ns     # nanoseconds of second (range 0-999999999)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UtcTimeMulti>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4
     2
     1
     1
     1
     1
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UtcTimeMulti>))
  "Converts a ROS message object to a list"
  (cl:list 'UtcTimeMulti
    (cl:cons ':header (header msg))
    (cl:cons ':flags (flags msg))
    (cl:cons ':tow (tow msg))
    (cl:cons ':year (year msg))
    (cl:cons ':month (month msg))
    (cl:cons ':day (day msg))
    (cl:cons ':hours (hours msg))
    (cl:cons ':minutes (minutes msg))
    (cl:cons ':seconds (seconds msg))
    (cl:cons ':ns (ns msg))
))
