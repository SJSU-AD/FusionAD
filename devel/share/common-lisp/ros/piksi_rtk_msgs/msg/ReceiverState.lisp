; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude ReceiverState.msg.html

(cl:defclass <ReceiverState> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (num_sat
    :reader num_sat
    :initarg :num_sat
    :type cl:fixnum
    :initform 0)
   (rtk_mode_fix
    :reader rtk_mode_fix
    :initarg :rtk_mode_fix
    :type cl:boolean
    :initform cl:nil)
   (sat
    :reader sat
    :initarg :sat
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (cn0
    :reader cn0
    :initarg :cn0
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (tracking_running
    :reader tracking_running
    :initarg :tracking_running
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (system_error
    :reader system_error
    :initarg :system_error
    :type cl:fixnum
    :initform 0)
   (io_error
    :reader io_error
    :initarg :io_error
    :type cl:fixnum
    :initform 0)
   (swift_nap_error
    :reader swift_nap_error
    :initarg :swift_nap_error
    :type cl:fixnum
    :initform 0)
   (external_antenna_present
    :reader external_antenna_present
    :initarg :external_antenna_present
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ReceiverState (<ReceiverState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReceiverState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReceiverState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<ReceiverState> is deprecated: use piksi_rtk_msgs-msg:ReceiverState instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'num_sat-val :lambda-list '(m))
(cl:defmethod num_sat-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:num_sat-val is deprecated.  Use piksi_rtk_msgs-msg:num_sat instead.")
  (num_sat m))

(cl:ensure-generic-function 'rtk_mode_fix-val :lambda-list '(m))
(cl:defmethod rtk_mode_fix-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:rtk_mode_fix-val is deprecated.  Use piksi_rtk_msgs-msg:rtk_mode_fix instead.")
  (rtk_mode_fix m))

(cl:ensure-generic-function 'sat-val :lambda-list '(m))
(cl:defmethod sat-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:sat-val is deprecated.  Use piksi_rtk_msgs-msg:sat instead.")
  (sat m))

(cl:ensure-generic-function 'cn0-val :lambda-list '(m))
(cl:defmethod cn0-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:cn0-val is deprecated.  Use piksi_rtk_msgs-msg:cn0 instead.")
  (cn0 m))

(cl:ensure-generic-function 'tracking_running-val :lambda-list '(m))
(cl:defmethod tracking_running-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tracking_running-val is deprecated.  Use piksi_rtk_msgs-msg:tracking_running instead.")
  (tracking_running m))

(cl:ensure-generic-function 'system_error-val :lambda-list '(m))
(cl:defmethod system_error-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:system_error-val is deprecated.  Use piksi_rtk_msgs-msg:system_error instead.")
  (system_error m))

(cl:ensure-generic-function 'io_error-val :lambda-list '(m))
(cl:defmethod io_error-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:io_error-val is deprecated.  Use piksi_rtk_msgs-msg:io_error instead.")
  (io_error m))

(cl:ensure-generic-function 'swift_nap_error-val :lambda-list '(m))
(cl:defmethod swift_nap_error-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:swift_nap_error-val is deprecated.  Use piksi_rtk_msgs-msg:swift_nap_error instead.")
  (swift_nap_error m))

(cl:ensure-generic-function 'external_antenna_present-val :lambda-list '(m))
(cl:defmethod external_antenna_present-val ((m <ReceiverState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:external_antenna_present-val is deprecated.  Use piksi_rtk_msgs-msg:external_antenna_present instead.")
  (external_antenna_present m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReceiverState>) ostream)
  "Serializes a message object of type '<ReceiverState>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_sat)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'rtk_mode_fix) 1 0)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'sat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'sat))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'cn0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'cn0))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'tracking_running))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'tracking_running))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_error)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'io_error)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'swift_nap_error)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'external_antenna_present)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReceiverState>) istream)
  "Deserializes a message object of type '<ReceiverState>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_sat)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rtk_mode_fix) (cl:not (cl:zerop (cl:read-byte istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'sat) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'sat)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'cn0) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'cn0)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'tracking_running) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'tracking_running)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_error)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'io_error)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'swift_nap_error)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'external_antenna_present)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReceiverState>)))
  "Returns string type for a message object of type '<ReceiverState>"
  "piksi_rtk_msgs/ReceiverState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReceiverState)))
  "Returns string type for a message object of type 'ReceiverState"
  "piksi_rtk_msgs/ReceiverState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReceiverState>)))
  "Returns md5sum for a message object of type '<ReceiverState>"
  "3bca929a4e134714778225bff42f183c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReceiverState)))
  "Returns md5sum for a message object of type 'ReceiverState"
  "3bca929a4e134714778225bff42f183c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReceiverState>)))
  "Returns full string definition for message of type '<ReceiverState>"
  (cl:format cl:nil "# Miscellaneous information form different SBP messages~%~%Header header~%~%uint8 num_sat                   # Number of satellites.~%bool rtk_mode_fix 	            # 1 = Fixed, 0 = Float.~%uint16[] sat                    # Constellation-specific satellite identifier.~%float32[] cn0                   # Carrier-to-noise density.~%uint8[] tracking_running        # Status of tracking channel.~%uint8 system_error              # System Error Flag.~%uint8 io_error                  # IO Error Flag.~%uint8 swift_nap_error           # SwiftNAP Error Flag.~%uint8 external_antenna_present  # External Antenna Present Flag.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReceiverState)))
  "Returns full string definition for message of type 'ReceiverState"
  (cl:format cl:nil "# Miscellaneous information form different SBP messages~%~%Header header~%~%uint8 num_sat                   # Number of satellites.~%bool rtk_mode_fix 	            # 1 = Fixed, 0 = Float.~%uint16[] sat                    # Constellation-specific satellite identifier.~%float32[] cn0                   # Carrier-to-noise density.~%uint8[] tracking_running        # Status of tracking channel.~%uint8 system_error              # System Error Flag.~%uint8 io_error                  # IO Error Flag.~%uint8 swift_nap_error           # SwiftNAP Error Flag.~%uint8 external_antenna_present  # External Antenna Present Flag.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReceiverState>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'sat) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'cn0) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'tracking_running) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReceiverState>))
  "Converts a ROS message object to a list"
  (cl:list 'ReceiverState
    (cl:cons ':header (header msg))
    (cl:cons ':num_sat (num_sat msg))
    (cl:cons ':rtk_mode_fix (rtk_mode_fix msg))
    (cl:cons ':sat (sat msg))
    (cl:cons ':cn0 (cn0 msg))
    (cl:cons ':tracking_running (tracking_running msg))
    (cl:cons ':system_error (system_error msg))
    (cl:cons ':io_error (io_error msg))
    (cl:cons ':swift_nap_error (swift_nap_error msg))
    (cl:cons ':external_antenna_present (external_antenna_present msg))
))
