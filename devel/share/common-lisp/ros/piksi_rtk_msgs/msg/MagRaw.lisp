; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude MagRaw.msg.html

(cl:defclass <MagRaw> (roslisp-msg-protocol:ros-message)
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
   (tow_f
    :reader tow_f
    :initarg :tow_f
    :type cl:fixnum
    :initform 0)
   (mag_x
    :reader mag_x
    :initarg :mag_x
    :type cl:fixnum
    :initform 0)
   (mag_y
    :reader mag_y
    :initarg :mag_y
    :type cl:fixnum
    :initform 0)
   (mag_z
    :reader mag_z
    :initarg :mag_z
    :type cl:fixnum
    :initform 0))
)

(cl:defclass MagRaw (<MagRaw>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MagRaw>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MagRaw)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<MagRaw> is deprecated: use piksi_rtk_msgs-msg:MagRaw instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MagRaw>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'tow-val :lambda-list '(m))
(cl:defmethod tow-val ((m <MagRaw>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow-val is deprecated.  Use piksi_rtk_msgs-msg:tow instead.")
  (tow m))

(cl:ensure-generic-function 'tow_f-val :lambda-list '(m))
(cl:defmethod tow_f-val ((m <MagRaw>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow_f-val is deprecated.  Use piksi_rtk_msgs-msg:tow_f instead.")
  (tow_f m))

(cl:ensure-generic-function 'mag_x-val :lambda-list '(m))
(cl:defmethod mag_x-val ((m <MagRaw>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:mag_x-val is deprecated.  Use piksi_rtk_msgs-msg:mag_x instead.")
  (mag_x m))

(cl:ensure-generic-function 'mag_y-val :lambda-list '(m))
(cl:defmethod mag_y-val ((m <MagRaw>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:mag_y-val is deprecated.  Use piksi_rtk_msgs-msg:mag_y instead.")
  (mag_y m))

(cl:ensure-generic-function 'mag_z-val :lambda-list '(m))
(cl:defmethod mag_z-val ((m <MagRaw>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:mag_z-val is deprecated.  Use piksi_rtk_msgs-msg:mag_z instead.")
  (mag_z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MagRaw>) ostream)
  "Serializes a message object of type '<MagRaw>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow_f)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'mag_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mag_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mag_z)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MagRaw>) istream)
  "Deserializes a message object of type '<MagRaw>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow_f)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mag_x) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mag_y) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mag_z) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MagRaw>)))
  "Returns string type for a message object of type '<MagRaw>"
  "piksi_rtk_msgs/MagRaw")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MagRaw)))
  "Returns string type for a message object of type 'MagRaw"
  "piksi_rtk_msgs/MagRaw")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MagRaw>)))
  "Returns md5sum for a message object of type '<MagRaw>"
  "79dfa3690a8019ef8383e9c5637520d8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MagRaw)))
  "Returns md5sum for a message object of type 'MagRaw"
  "79dfa3690a8019ef8383e9c5637520d8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MagRaw>)))
  "Returns full string definition for message of type '<MagRaw>"
  (cl:format cl:nil "# Raw data from the Magnetometer.~%~%Header header~%~%uint32 tow    # Milliseconds since start of GPS week. If the high bit is set, the time is unknown or invalid.~%uint8 tow_f   # Milliseconds since start of GPS week, fractional part.~%int16 mag_x   # Magnetometer value in the body frame X axis.~%int16 mag_y   # Magnetometer value in the body frame Y axis.~%int16 mag_z   # Magnetometer value in the body frame Z axis.~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MagRaw)))
  "Returns full string definition for message of type 'MagRaw"
  (cl:format cl:nil "# Raw data from the Magnetometer.~%~%Header header~%~%uint32 tow    # Milliseconds since start of GPS week. If the high bit is set, the time is unknown or invalid.~%uint8 tow_f   # Milliseconds since start of GPS week, fractional part.~%int16 mag_x   # Magnetometer value in the body frame X axis.~%int16 mag_y   # Magnetometer value in the body frame Y axis.~%int16 mag_z   # Magnetometer value in the body frame Z axis.~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MagRaw>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     1
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MagRaw>))
  "Converts a ROS message object to a list"
  (cl:list 'MagRaw
    (cl:cons ':header (header msg))
    (cl:cons ':tow (tow msg))
    (cl:cons ':tow_f (tow_f msg))
    (cl:cons ':mag_x (mag_x msg))
    (cl:cons ':mag_y (mag_y msg))
    (cl:cons ':mag_z (mag_z msg))
))
