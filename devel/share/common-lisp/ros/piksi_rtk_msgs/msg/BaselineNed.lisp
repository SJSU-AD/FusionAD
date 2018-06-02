; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude BaselineNed.msg.html

(cl:defclass <BaselineNed> (roslisp-msg-protocol:ros-message)
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
   (n
    :reader n
    :initarg :n
    :type cl:integer
    :initform 0)
   (e
    :reader e
    :initarg :e
    :type cl:integer
    :initform 0)
   (d
    :reader d
    :initarg :d
    :type cl:integer
    :initform 0)
   (h_accuracy
    :reader h_accuracy
    :initarg :h_accuracy
    :type cl:fixnum
    :initform 0)
   (v_accuracy
    :reader v_accuracy
    :initarg :v_accuracy
    :type cl:fixnum
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

(cl:defclass BaselineNed (<BaselineNed>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BaselineNed>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BaselineNed)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<BaselineNed> is deprecated: use piksi_rtk_msgs-msg:BaselineNed instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <BaselineNed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'tow-val :lambda-list '(m))
(cl:defmethod tow-val ((m <BaselineNed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow-val is deprecated.  Use piksi_rtk_msgs-msg:tow instead.")
  (tow m))

(cl:ensure-generic-function 'n-val :lambda-list '(m))
(cl:defmethod n-val ((m <BaselineNed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:n-val is deprecated.  Use piksi_rtk_msgs-msg:n instead.")
  (n m))

(cl:ensure-generic-function 'e-val :lambda-list '(m))
(cl:defmethod e-val ((m <BaselineNed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:e-val is deprecated.  Use piksi_rtk_msgs-msg:e instead.")
  (e m))

(cl:ensure-generic-function 'd-val :lambda-list '(m))
(cl:defmethod d-val ((m <BaselineNed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:d-val is deprecated.  Use piksi_rtk_msgs-msg:d instead.")
  (d m))

(cl:ensure-generic-function 'h_accuracy-val :lambda-list '(m))
(cl:defmethod h_accuracy-val ((m <BaselineNed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:h_accuracy-val is deprecated.  Use piksi_rtk_msgs-msg:h_accuracy instead.")
  (h_accuracy m))

(cl:ensure-generic-function 'v_accuracy-val :lambda-list '(m))
(cl:defmethod v_accuracy-val ((m <BaselineNed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:v_accuracy-val is deprecated.  Use piksi_rtk_msgs-msg:v_accuracy instead.")
  (v_accuracy m))

(cl:ensure-generic-function 'n_sats-val :lambda-list '(m))
(cl:defmethod n_sats-val ((m <BaselineNed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:n_sats-val is deprecated.  Use piksi_rtk_msgs-msg:n_sats instead.")
  (n_sats m))

(cl:ensure-generic-function 'flags-val :lambda-list '(m))
(cl:defmethod flags-val ((m <BaselineNed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:flags-val is deprecated.  Use piksi_rtk_msgs-msg:flags instead.")
  (flags m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BaselineNed>) ostream)
  "Serializes a message object of type '<BaselineNed>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'n)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'e)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'd)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'h_accuracy)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'h_accuracy)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'v_accuracy)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'v_accuracy)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n_sats)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BaselineNed>) istream)
  "Deserializes a message object of type '<BaselineNed>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'n) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'e) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'd) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'h_accuracy)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'h_accuracy)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'v_accuracy)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'v_accuracy)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n_sats)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BaselineNed>)))
  "Returns string type for a message object of type '<BaselineNed>"
  "piksi_rtk_msgs/BaselineNed")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BaselineNed)))
  "Returns string type for a message object of type 'BaselineNed"
  "piksi_rtk_msgs/BaselineNed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BaselineNed>)))
  "Returns md5sum for a message object of type '<BaselineNed>"
  "d181eb2c9a6abff7c97c58dc9f4c0a7f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BaselineNed)))
  "Returns md5sum for a message object of type 'BaselineNed"
  "d181eb2c9a6abff7c97c58dc9f4c0a7f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BaselineNed>)))
  "Returns full string definition for message of type '<BaselineNed>"
  (cl:format cl:nil "# This message reports the baseline solution in North East Down (NED) coordinates. This baseline is~%# the relative vector distance from the base station to the rover receiver, and NED coordinate system is~%# defined at the local WGS84 tangent plane centered at the base station position. The full GPS time is~%# given by the preceding MSG GPS TIME with the matching time-of-week (tow).~%~%Header header~%~%uint32 tow          # GPS Time of Week [ms].~%int32 n             # Baseline North coordinate [mm].~%int32 e             # Baseline East coordinate[mm].~%int32 d             # Baseline Down coordinate [mm].~%uint16 h_accuracy   # Horizontal position accuracy estimate (not implemented in hardware version V2).~%uint16 v_accuracy   # Vertical position accuracy estimate (not implemented in hardware version V2).~%uint8 n_sats        # Number of satellites used in solution~%uint8 flags         # Status flags, see MSG_BASELINE_NED message description in SBP documentation.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BaselineNed)))
  "Returns full string definition for message of type 'BaselineNed"
  (cl:format cl:nil "# This message reports the baseline solution in North East Down (NED) coordinates. This baseline is~%# the relative vector distance from the base station to the rover receiver, and NED coordinate system is~%# defined at the local WGS84 tangent plane centered at the base station position. The full GPS time is~%# given by the preceding MSG GPS TIME with the matching time-of-week (tow).~%~%Header header~%~%uint32 tow          # GPS Time of Week [ms].~%int32 n             # Baseline North coordinate [mm].~%int32 e             # Baseline East coordinate[mm].~%int32 d             # Baseline Down coordinate [mm].~%uint16 h_accuracy   # Horizontal position accuracy estimate (not implemented in hardware version V2).~%uint16 v_accuracy   # Vertical position accuracy estimate (not implemented in hardware version V2).~%uint8 n_sats        # Number of satellites used in solution~%uint8 flags         # Status flags, see MSG_BASELINE_NED message description in SBP documentation.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BaselineNed>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     2
     2
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BaselineNed>))
  "Converts a ROS message object to a list"
  (cl:list 'BaselineNed
    (cl:cons ':header (header msg))
    (cl:cons ':tow (tow msg))
    (cl:cons ':n (n msg))
    (cl:cons ':e (e msg))
    (cl:cons ':d (d msg))
    (cl:cons ':h_accuracy (h_accuracy msg))
    (cl:cons ':v_accuracy (v_accuracy msg))
    (cl:cons ':n_sats (n_sats msg))
    (cl:cons ':flags (flags msg))
))
