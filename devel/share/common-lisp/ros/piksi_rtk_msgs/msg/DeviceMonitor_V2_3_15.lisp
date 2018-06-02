; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude DeviceMonitor_V2_3_15.msg.html

(cl:defclass <DeviceMonitor_V2_3_15> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (dev_vin
    :reader dev_vin
    :initarg :dev_vin
    :type cl:fixnum
    :initform 0)
   (cpu_vint
    :reader cpu_vint
    :initarg :cpu_vint
    :type cl:fixnum
    :initform 0)
   (cpu_vaux
    :reader cpu_vaux
    :initarg :cpu_vaux
    :type cl:fixnum
    :initform 0)
   (cpu_temperature
    :reader cpu_temperature
    :initarg :cpu_temperature
    :type cl:fixnum
    :initform 0)
   (fe_temperature
    :reader fe_temperature
    :initarg :fe_temperature
    :type cl:fixnum
    :initform 0))
)

(cl:defclass DeviceMonitor_V2_3_15 (<DeviceMonitor_V2_3_15>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DeviceMonitor_V2_3_15>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DeviceMonitor_V2_3_15)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<DeviceMonitor_V2_3_15> is deprecated: use piksi_rtk_msgs-msg:DeviceMonitor_V2_3_15 instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <DeviceMonitor_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'dev_vin-val :lambda-list '(m))
(cl:defmethod dev_vin-val ((m <DeviceMonitor_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:dev_vin-val is deprecated.  Use piksi_rtk_msgs-msg:dev_vin instead.")
  (dev_vin m))

(cl:ensure-generic-function 'cpu_vint-val :lambda-list '(m))
(cl:defmethod cpu_vint-val ((m <DeviceMonitor_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:cpu_vint-val is deprecated.  Use piksi_rtk_msgs-msg:cpu_vint instead.")
  (cpu_vint m))

(cl:ensure-generic-function 'cpu_vaux-val :lambda-list '(m))
(cl:defmethod cpu_vaux-val ((m <DeviceMonitor_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:cpu_vaux-val is deprecated.  Use piksi_rtk_msgs-msg:cpu_vaux instead.")
  (cpu_vaux m))

(cl:ensure-generic-function 'cpu_temperature-val :lambda-list '(m))
(cl:defmethod cpu_temperature-val ((m <DeviceMonitor_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:cpu_temperature-val is deprecated.  Use piksi_rtk_msgs-msg:cpu_temperature instead.")
  (cpu_temperature m))

(cl:ensure-generic-function 'fe_temperature-val :lambda-list '(m))
(cl:defmethod fe_temperature-val ((m <DeviceMonitor_V2_3_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:fe_temperature-val is deprecated.  Use piksi_rtk_msgs-msg:fe_temperature instead.")
  (fe_temperature m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DeviceMonitor_V2_3_15>) ostream)
  "Serializes a message object of type '<DeviceMonitor_V2_3_15>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'dev_vin)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'cpu_vint)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'cpu_vaux)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'cpu_temperature)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'fe_temperature)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DeviceMonitor_V2_3_15>) istream)
  "Deserializes a message object of type '<DeviceMonitor_V2_3_15>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dev_vin) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cpu_vint) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cpu_vaux) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cpu_temperature) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'fe_temperature) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DeviceMonitor_V2_3_15>)))
  "Returns string type for a message object of type '<DeviceMonitor_V2_3_15>"
  "piksi_rtk_msgs/DeviceMonitor_V2_3_15")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DeviceMonitor_V2_3_15)))
  "Returns string type for a message object of type 'DeviceMonitor_V2_3_15"
  "piksi_rtk_msgs/DeviceMonitor_V2_3_15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DeviceMonitor_V2_3_15>)))
  "Returns md5sum for a message object of type '<DeviceMonitor_V2_3_15>"
  "54b454c5f7be4348e9710a8df0100d12")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DeviceMonitor_V2_3_15)))
  "Returns md5sum for a message object of type 'DeviceMonitor_V2_3_15"
  "54b454c5f7be4348e9710a8df0100d12")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DeviceMonitor_V2_3_15>)))
  "Returns full string definition for message of type '<DeviceMonitor_V2_3_15>"
  (cl:format cl:nil "# This message contains temperature and voltage level measurements from the processor’s monitoring~%# system and the RF frontend die temperature if available.~%~%# Message definition based on libsbp v2.2.15~%~%Header header~%~%int16 dev_vin               # Device V_in [V / 1000].~%int16 cpu_vint              # Processor V_int [V / 1000].~%int16 cpu_vaux              # Processor V_aux [V / 1000].~%int16 cpu_temperature       # Processor temperature [degrees C / 100].~%int16 fe_temperature        # Fronted temperature (if available) [degrees C / 100].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DeviceMonitor_V2_3_15)))
  "Returns full string definition for message of type 'DeviceMonitor_V2_3_15"
  (cl:format cl:nil "# This message contains temperature and voltage level measurements from the processor’s monitoring~%# system and the RF frontend die temperature if available.~%~%# Message definition based on libsbp v2.2.15~%~%Header header~%~%int16 dev_vin               # Device V_in [V / 1000].~%int16 cpu_vint              # Processor V_int [V / 1000].~%int16 cpu_vaux              # Processor V_aux [V / 1000].~%int16 cpu_temperature       # Processor temperature [degrees C / 100].~%int16 fe_temperature        # Fronted temperature (if available) [degrees C / 100].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DeviceMonitor_V2_3_15>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DeviceMonitor_V2_3_15>))
  "Converts a ROS message object to a list"
  (cl:list 'DeviceMonitor_V2_3_15
    (cl:cons ':header (header msg))
    (cl:cons ':dev_vin (dev_vin msg))
    (cl:cons ':cpu_vint (cpu_vint msg))
    (cl:cons ':cpu_vaux (cpu_vaux msg))
    (cl:cons ':cpu_temperature (cpu_temperature msg))
    (cl:cons ':fe_temperature (fe_temperature msg))
))
