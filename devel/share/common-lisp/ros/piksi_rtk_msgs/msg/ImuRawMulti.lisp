; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude ImuRawMulti.msg.html

(cl:defclass <ImuRawMulti> (roslisp-msg-protocol:ros-message)
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
   (acc_x
    :reader acc_x
    :initarg :acc_x
    :type cl:fixnum
    :initform 0)
   (acc_y
    :reader acc_y
    :initarg :acc_y
    :type cl:fixnum
    :initform 0)
   (acc_z
    :reader acc_z
    :initarg :acc_z
    :type cl:fixnum
    :initform 0)
   (gyr_x
    :reader gyr_x
    :initarg :gyr_x
    :type cl:fixnum
    :initform 0)
   (gyr_y
    :reader gyr_y
    :initarg :gyr_y
    :type cl:fixnum
    :initform 0)
   (gyr_z
    :reader gyr_z
    :initarg :gyr_z
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ImuRawMulti (<ImuRawMulti>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ImuRawMulti>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ImuRawMulti)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<ImuRawMulti> is deprecated: use piksi_rtk_msgs-msg:ImuRawMulti instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ImuRawMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'tow-val :lambda-list '(m))
(cl:defmethod tow-val ((m <ImuRawMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow-val is deprecated.  Use piksi_rtk_msgs-msg:tow instead.")
  (tow m))

(cl:ensure-generic-function 'tow_f-val :lambda-list '(m))
(cl:defmethod tow_f-val ((m <ImuRawMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow_f-val is deprecated.  Use piksi_rtk_msgs-msg:tow_f instead.")
  (tow_f m))

(cl:ensure-generic-function 'acc_x-val :lambda-list '(m))
(cl:defmethod acc_x-val ((m <ImuRawMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:acc_x-val is deprecated.  Use piksi_rtk_msgs-msg:acc_x instead.")
  (acc_x m))

(cl:ensure-generic-function 'acc_y-val :lambda-list '(m))
(cl:defmethod acc_y-val ((m <ImuRawMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:acc_y-val is deprecated.  Use piksi_rtk_msgs-msg:acc_y instead.")
  (acc_y m))

(cl:ensure-generic-function 'acc_z-val :lambda-list '(m))
(cl:defmethod acc_z-val ((m <ImuRawMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:acc_z-val is deprecated.  Use piksi_rtk_msgs-msg:acc_z instead.")
  (acc_z m))

(cl:ensure-generic-function 'gyr_x-val :lambda-list '(m))
(cl:defmethod gyr_x-val ((m <ImuRawMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:gyr_x-val is deprecated.  Use piksi_rtk_msgs-msg:gyr_x instead.")
  (gyr_x m))

(cl:ensure-generic-function 'gyr_y-val :lambda-list '(m))
(cl:defmethod gyr_y-val ((m <ImuRawMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:gyr_y-val is deprecated.  Use piksi_rtk_msgs-msg:gyr_y instead.")
  (gyr_y m))

(cl:ensure-generic-function 'gyr_z-val :lambda-list '(m))
(cl:defmethod gyr_z-val ((m <ImuRawMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:gyr_z-val is deprecated.  Use piksi_rtk_msgs-msg:gyr_z instead.")
  (gyr_z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ImuRawMulti>) ostream)
  "Serializes a message object of type '<ImuRawMulti>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow_f)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'acc_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'acc_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'acc_z)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gyr_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gyr_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gyr_z)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ImuRawMulti>) istream)
  "Deserializes a message object of type '<ImuRawMulti>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow_f)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'acc_x) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'acc_y) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'acc_z) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gyr_x) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gyr_y) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gyr_z) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ImuRawMulti>)))
  "Returns string type for a message object of type '<ImuRawMulti>"
  "piksi_rtk_msgs/ImuRawMulti")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImuRawMulti)))
  "Returns string type for a message object of type 'ImuRawMulti"
  "piksi_rtk_msgs/ImuRawMulti")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ImuRawMulti>)))
  "Returns md5sum for a message object of type '<ImuRawMulti>"
  "e32f07f6279690082bb3d37f42a5fc90")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ImuRawMulti)))
  "Returns md5sum for a message object of type 'ImuRawMulti"
  "e32f07f6279690082bb3d37f42a5fc90")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ImuRawMulti>)))
  "Returns full string definition for message of type '<ImuRawMulti>"
  (cl:format cl:nil "# Raw data from the Inertial Measurement Unit, containing accelerometer and gyroscope readings.~%~%Header header~%~%uint32 tow    # Milliseconds since start of GPS week. If the high bit is set, the time is unknown or invalid.~%uint8 tow_f   # Milliseconds since start of GPS week, fractional part.~%int16 acc_x   # Acceleration in the body frame X axis.~%int16 acc_y   # Acceleration in the body frame Y axis.~%int16 acc_z   # Acceleration in the body frame Z axis.~%int16 gyr_x   # Angular rate around the body frame X axis.~%int16 gyr_y   # Angular rate around the body frame Y axis.~%int16 gyr_z   # Angular rate around the body frame Z axis.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ImuRawMulti)))
  "Returns full string definition for message of type 'ImuRawMulti"
  (cl:format cl:nil "# Raw data from the Inertial Measurement Unit, containing accelerometer and gyroscope readings.~%~%Header header~%~%uint32 tow    # Milliseconds since start of GPS week. If the high bit is set, the time is unknown or invalid.~%uint8 tow_f   # Milliseconds since start of GPS week, fractional part.~%int16 acc_x   # Acceleration in the body frame X axis.~%int16 acc_y   # Acceleration in the body frame Y axis.~%int16 acc_z   # Acceleration in the body frame Z axis.~%int16 gyr_x   # Angular rate around the body frame X axis.~%int16 gyr_y   # Angular rate around the body frame Y axis.~%int16 gyr_z   # Angular rate around the body frame Z axis.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ImuRawMulti>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     1
     2
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ImuRawMulti>))
  "Converts a ROS message object to a list"
  (cl:list 'ImuRawMulti
    (cl:cons ':header (header msg))
    (cl:cons ':tow (tow msg))
    (cl:cons ':tow_f (tow_f msg))
    (cl:cons ':acc_x (acc_x msg))
    (cl:cons ':acc_y (acc_y msg))
    (cl:cons ':acc_z (acc_z msg))
    (cl:cons ':gyr_x (gyr_x msg))
    (cl:cons ':gyr_y (gyr_y msg))
    (cl:cons ':gyr_z (gyr_z msg))
))
