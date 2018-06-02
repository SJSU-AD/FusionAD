; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude ImuAuxMulti.msg.html

(cl:defclass <ImuAuxMulti> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (imu_type
    :reader imu_type
    :initarg :imu_type
    :type cl:fixnum
    :initform 0)
   (temp
    :reader temp
    :initarg :temp
    :type cl:fixnum
    :initform 0)
   (imu_conf
    :reader imu_conf
    :initarg :imu_conf
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ImuAuxMulti (<ImuAuxMulti>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ImuAuxMulti>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ImuAuxMulti)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<ImuAuxMulti> is deprecated: use piksi_rtk_msgs-msg:ImuAuxMulti instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ImuAuxMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'imu_type-val :lambda-list '(m))
(cl:defmethod imu_type-val ((m <ImuAuxMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:imu_type-val is deprecated.  Use piksi_rtk_msgs-msg:imu_type instead.")
  (imu_type m))

(cl:ensure-generic-function 'temp-val :lambda-list '(m))
(cl:defmethod temp-val ((m <ImuAuxMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:temp-val is deprecated.  Use piksi_rtk_msgs-msg:temp instead.")
  (temp m))

(cl:ensure-generic-function 'imu_conf-val :lambda-list '(m))
(cl:defmethod imu_conf-val ((m <ImuAuxMulti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:imu_conf-val is deprecated.  Use piksi_rtk_msgs-msg:imu_conf instead.")
  (imu_conf m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ImuAuxMulti>) ostream)
  "Serializes a message object of type '<ImuAuxMulti>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'imu_type)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'temp)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'imu_conf)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ImuAuxMulti>) istream)
  "Deserializes a message object of type '<ImuAuxMulti>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'imu_type)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'temp) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'imu_conf)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ImuAuxMulti>)))
  "Returns string type for a message object of type '<ImuAuxMulti>"
  "piksi_rtk_msgs/ImuAuxMulti")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImuAuxMulti)))
  "Returns string type for a message object of type 'ImuAuxMulti"
  "piksi_rtk_msgs/ImuAuxMulti")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ImuAuxMulti>)))
  "Returns md5sum for a message object of type '<ImuAuxMulti>"
  "1d0e477b2db08e26ff9772a2136dfba7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ImuAuxMulti)))
  "Returns md5sum for a message object of type 'ImuAuxMulti"
  "1d0e477b2db08e26ff9772a2136dfba7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ImuAuxMulti>)))
  "Returns full string definition for message of type '<ImuAuxMulti>"
  (cl:format cl:nil "# Auxiliary data specific to a particular IMU. The 'imu type' field will always be consistent but the rest of~%# the payload is device specific and depends on the value of 'imu type'.~%~%Header header~%~%uint8 imu_type  # IMU type.~%int16 temp      # Raw IMU temperature.~%uint8 imu_conf  # IMU configuration.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ImuAuxMulti)))
  "Returns full string definition for message of type 'ImuAuxMulti"
  (cl:format cl:nil "# Auxiliary data specific to a particular IMU. The 'imu type' field will always be consistent but the rest of~%# the payload is device specific and depends on the value of 'imu type'.~%~%Header header~%~%uint8 imu_type  # IMU type.~%int16 temp      # Raw IMU temperature.~%uint8 imu_conf  # IMU configuration.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ImuAuxMulti>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     2
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ImuAuxMulti>))
  "Converts a ROS message object to a list"
  (cl:list 'ImuAuxMulti
    (cl:cons ':header (header msg))
    (cl:cons ':imu_type (imu_type msg))
    (cl:cons ':temp (temp msg))
    (cl:cons ':imu_conf (imu_conf msg))
))
