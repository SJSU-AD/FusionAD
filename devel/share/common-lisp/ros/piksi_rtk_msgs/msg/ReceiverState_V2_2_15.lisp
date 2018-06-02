; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude ReceiverState_V2_2_15.msg.html

(cl:defclass <ReceiverState_V2_2_15> (roslisp-msg-protocol:ros-message)
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
    :initform 0)
   (num_gps_sat
    :reader num_gps_sat
    :initarg :num_gps_sat
    :type cl:fixnum
    :initform 0)
   (cn0_gps
    :reader cn0_gps
    :initarg :cn0_gps
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (num_sbas_sat
    :reader num_sbas_sat
    :initarg :num_sbas_sat
    :type cl:fixnum
    :initform 0)
   (cn0_sbas
    :reader cn0_sbas
    :initarg :cn0_sbas
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (num_glonass_sat
    :reader num_glonass_sat
    :initarg :num_glonass_sat
    :type cl:fixnum
    :initform 0)
   (cn0_glonass
    :reader cn0_glonass
    :initarg :cn0_glonass
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (fix_mode
    :reader fix_mode
    :initarg :fix_mode
    :type cl:string
    :initform ""))
)

(cl:defclass ReceiverState_V2_2_15 (<ReceiverState_V2_2_15>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReceiverState_V2_2_15>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReceiverState_V2_2_15)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<ReceiverState_V2_2_15> is deprecated: use piksi_rtk_msgs-msg:ReceiverState_V2_2_15 instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'num_sat-val :lambda-list '(m))
(cl:defmethod num_sat-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:num_sat-val is deprecated.  Use piksi_rtk_msgs-msg:num_sat instead.")
  (num_sat m))

(cl:ensure-generic-function 'rtk_mode_fix-val :lambda-list '(m))
(cl:defmethod rtk_mode_fix-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:rtk_mode_fix-val is deprecated.  Use piksi_rtk_msgs-msg:rtk_mode_fix instead.")
  (rtk_mode_fix m))

(cl:ensure-generic-function 'sat-val :lambda-list '(m))
(cl:defmethod sat-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:sat-val is deprecated.  Use piksi_rtk_msgs-msg:sat instead.")
  (sat m))

(cl:ensure-generic-function 'cn0-val :lambda-list '(m))
(cl:defmethod cn0-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:cn0-val is deprecated.  Use piksi_rtk_msgs-msg:cn0 instead.")
  (cn0 m))

(cl:ensure-generic-function 'system_error-val :lambda-list '(m))
(cl:defmethod system_error-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:system_error-val is deprecated.  Use piksi_rtk_msgs-msg:system_error instead.")
  (system_error m))

(cl:ensure-generic-function 'io_error-val :lambda-list '(m))
(cl:defmethod io_error-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:io_error-val is deprecated.  Use piksi_rtk_msgs-msg:io_error instead.")
  (io_error m))

(cl:ensure-generic-function 'swift_nap_error-val :lambda-list '(m))
(cl:defmethod swift_nap_error-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:swift_nap_error-val is deprecated.  Use piksi_rtk_msgs-msg:swift_nap_error instead.")
  (swift_nap_error m))

(cl:ensure-generic-function 'external_antenna_present-val :lambda-list '(m))
(cl:defmethod external_antenna_present-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:external_antenna_present-val is deprecated.  Use piksi_rtk_msgs-msg:external_antenna_present instead.")
  (external_antenna_present m))

(cl:ensure-generic-function 'num_gps_sat-val :lambda-list '(m))
(cl:defmethod num_gps_sat-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:num_gps_sat-val is deprecated.  Use piksi_rtk_msgs-msg:num_gps_sat instead.")
  (num_gps_sat m))

(cl:ensure-generic-function 'cn0_gps-val :lambda-list '(m))
(cl:defmethod cn0_gps-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:cn0_gps-val is deprecated.  Use piksi_rtk_msgs-msg:cn0_gps instead.")
  (cn0_gps m))

(cl:ensure-generic-function 'num_sbas_sat-val :lambda-list '(m))
(cl:defmethod num_sbas_sat-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:num_sbas_sat-val is deprecated.  Use piksi_rtk_msgs-msg:num_sbas_sat instead.")
  (num_sbas_sat m))

(cl:ensure-generic-function 'cn0_sbas-val :lambda-list '(m))
(cl:defmethod cn0_sbas-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:cn0_sbas-val is deprecated.  Use piksi_rtk_msgs-msg:cn0_sbas instead.")
  (cn0_sbas m))

(cl:ensure-generic-function 'num_glonass_sat-val :lambda-list '(m))
(cl:defmethod num_glonass_sat-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:num_glonass_sat-val is deprecated.  Use piksi_rtk_msgs-msg:num_glonass_sat instead.")
  (num_glonass_sat m))

(cl:ensure-generic-function 'cn0_glonass-val :lambda-list '(m))
(cl:defmethod cn0_glonass-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:cn0_glonass-val is deprecated.  Use piksi_rtk_msgs-msg:cn0_glonass instead.")
  (cn0_glonass m))

(cl:ensure-generic-function 'fix_mode-val :lambda-list '(m))
(cl:defmethod fix_mode-val ((m <ReceiverState_V2_2_15>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:fix_mode-val is deprecated.  Use piksi_rtk_msgs-msg:fix_mode instead.")
  (fix_mode m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<ReceiverState_V2_2_15>)))
    "Constants for message type '<ReceiverState_V2_2_15>"
  '((:CODE_GPS_L1CA . 0)
    (:CODE_GPS_L2CM . 1)
    (:CODE_SBAS_L1CA . 2)
    (:CODE_GLO_L1CA . 3)
    (:CODE_GLO_L2CA . 4)
    (:CODE_GPS_L1P . 5)
    (:CODE_GPS_L2P . 6)
    (:STR_FIX_MODE_INVALID . Invalid)
    (:STR_FIX_MODE_SPP . SPP)
    (:STR_FIX_MODE_DGNSS . DGNSS)
    (:STR_FIX_MODE_FLOAT_RTK . FLOAT_RTK)
    (:STR_FIX_MODE_FIXED_RTK . FIXED_RTK)
    (:STR_FIX_MODE_UNKNOWN . Unknown))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'ReceiverState_V2_2_15)))
    "Constants for message type 'ReceiverState_V2_2_15"
  '((:CODE_GPS_L1CA . 0)
    (:CODE_GPS_L2CM . 1)
    (:CODE_SBAS_L1CA . 2)
    (:CODE_GLO_L1CA . 3)
    (:CODE_GLO_L2CA . 4)
    (:CODE_GPS_L1P . 5)
    (:CODE_GPS_L2P . 6)
    (:STR_FIX_MODE_INVALID . Invalid)
    (:STR_FIX_MODE_SPP . SPP)
    (:STR_FIX_MODE_DGNSS . DGNSS)
    (:STR_FIX_MODE_FLOAT_RTK . FLOAT_RTK)
    (:STR_FIX_MODE_FIXED_RTK . FIXED_RTK)
    (:STR_FIX_MODE_UNKNOWN . Unknown))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReceiverState_V2_2_15>) ostream)
  "Serializes a message object of type '<ReceiverState_V2_2_15>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_sat)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'rtk_mode_fix) 1 0)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'sat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'sat))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'cn0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'cn0))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_error)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'io_error)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'swift_nap_error)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'external_antenna_present)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_gps_sat)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'cn0_gps))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'cn0_gps))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_sbas_sat)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'cn0_sbas))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'cn0_sbas))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_glonass_sat)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'cn0_glonass))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'cn0_glonass))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'fix_mode))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'fix_mode))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReceiverState_V2_2_15>) istream)
  "Deserializes a message object of type '<ReceiverState_V2_2_15>"
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'cn0) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'cn0)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_error)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'io_error)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'swift_nap_error)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'external_antenna_present)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_gps_sat)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'cn0_gps) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'cn0_gps)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_sbas_sat)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'cn0_sbas) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'cn0_sbas)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_glonass_sat)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'cn0_glonass) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'cn0_glonass)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'fix_mode) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'fix_mode) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReceiverState_V2_2_15>)))
  "Returns string type for a message object of type '<ReceiverState_V2_2_15>"
  "piksi_rtk_msgs/ReceiverState_V2_2_15")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReceiverState_V2_2_15)))
  "Returns string type for a message object of type 'ReceiverState_V2_2_15"
  "piksi_rtk_msgs/ReceiverState_V2_2_15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReceiverState_V2_2_15>)))
  "Returns md5sum for a message object of type '<ReceiverState_V2_2_15>"
  "0b24eec3eea4c8a5bf60087436d79950")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReceiverState_V2_2_15)))
  "Returns md5sum for a message object of type 'ReceiverState_V2_2_15"
  "0b24eec3eea4c8a5bf60087436d79950")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReceiverState_V2_2_15>)))
  "Returns full string definition for message of type '<ReceiverState_V2_2_15>"
  (cl:format cl:nil "# Miscellaneous information form different SBP messages~%~%# Message definition based on libsbp v2.2.15~%~%~%Header header~%~%uint8 num_sat                   # Number of satellites.~%bool rtk_mode_fix 	            # 1 = Fixed, 0 = Float.~%uint8[] sat                     # Constellation-specific satellite identifier.~%uint8[] cn0                     # Carrier-to-Noise density. Zero implies invalid cn0 [dB Hz / 4].~%uint8 system_error              # System Error Flag.~%uint8 io_error                  # IO Error Flag.~%uint8 swift_nap_error           # SwiftNAP Error Flag.~%uint8 external_antenna_present  # External Antenna Present Flag.~%uint8 num_gps_sat               # Number of GPS satellites.~%uint8[] cn0_gps                 # Carrier-to-Noise density of GPS satellites. Zero implies invalid cn0 [dB Hz / 4].~%uint8 num_sbas_sat              # Number of SBAS satellites.~%uint8[] cn0_sbas                # Carrier-to-Noise density of SBAS satellites. Zero implies invalid cn0 [dB Hz / 4].~%uint8 num_glonass_sat           # Number of GLONASS satellites.~%uint8[] cn0_glonass             # Carrier-to-Noise density of GLONASS satellites. Zero implies invalid cn0 [dB Hz / 4].~%string fix_mode                 # Invalid, Single Point Position (SPP), Differential GNSS (DGNSS), Float RTK, Fixed RTK.~%~%~%uint8 CODE_GPS_L1CA     = 0~%uint8 CODE_GPS_L2CM     = 1~%uint8 CODE_SBAS_L1CA    = 2~%uint8 CODE_GLO_L1CA     = 3~%uint8 CODE_GLO_L2CA     = 4~%uint8 CODE_GPS_L1P      = 5~%uint8 CODE_GPS_L2P      = 6~%~%string STR_FIX_MODE_INVALID   = Invalid~%string STR_FIX_MODE_SPP       = SPP~%string STR_FIX_MODE_DGNSS     = DGNSS~%string STR_FIX_MODE_FLOAT_RTK = FLOAT_RTK~%string STR_FIX_MODE_FIXED_RTK = FIXED_RTK~%string STR_FIX_MODE_UNKNOWN   = Unknown~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReceiverState_V2_2_15)))
  "Returns full string definition for message of type 'ReceiverState_V2_2_15"
  (cl:format cl:nil "# Miscellaneous information form different SBP messages~%~%# Message definition based on libsbp v2.2.15~%~%~%Header header~%~%uint8 num_sat                   # Number of satellites.~%bool rtk_mode_fix 	            # 1 = Fixed, 0 = Float.~%uint8[] sat                     # Constellation-specific satellite identifier.~%uint8[] cn0                     # Carrier-to-Noise density. Zero implies invalid cn0 [dB Hz / 4].~%uint8 system_error              # System Error Flag.~%uint8 io_error                  # IO Error Flag.~%uint8 swift_nap_error           # SwiftNAP Error Flag.~%uint8 external_antenna_present  # External Antenna Present Flag.~%uint8 num_gps_sat               # Number of GPS satellites.~%uint8[] cn0_gps                 # Carrier-to-Noise density of GPS satellites. Zero implies invalid cn0 [dB Hz / 4].~%uint8 num_sbas_sat              # Number of SBAS satellites.~%uint8[] cn0_sbas                # Carrier-to-Noise density of SBAS satellites. Zero implies invalid cn0 [dB Hz / 4].~%uint8 num_glonass_sat           # Number of GLONASS satellites.~%uint8[] cn0_glonass             # Carrier-to-Noise density of GLONASS satellites. Zero implies invalid cn0 [dB Hz / 4].~%string fix_mode                 # Invalid, Single Point Position (SPP), Differential GNSS (DGNSS), Float RTK, Fixed RTK.~%~%~%uint8 CODE_GPS_L1CA     = 0~%uint8 CODE_GPS_L2CM     = 1~%uint8 CODE_SBAS_L1CA    = 2~%uint8 CODE_GLO_L1CA     = 3~%uint8 CODE_GLO_L2CA     = 4~%uint8 CODE_GPS_L1P      = 5~%uint8 CODE_GPS_L2P      = 6~%~%string STR_FIX_MODE_INVALID   = Invalid~%string STR_FIX_MODE_SPP       = SPP~%string STR_FIX_MODE_DGNSS     = DGNSS~%string STR_FIX_MODE_FLOAT_RTK = FLOAT_RTK~%string STR_FIX_MODE_FIXED_RTK = FIXED_RTK~%string STR_FIX_MODE_UNKNOWN   = Unknown~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReceiverState_V2_2_15>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'sat) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'cn0) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     1
     1
     1
     1
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'cn0_gps) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'cn0_sbas) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'cn0_glonass) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:length (cl:slot-value msg 'fix_mode))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReceiverState_V2_2_15>))
  "Converts a ROS message object to a list"
  (cl:list 'ReceiverState_V2_2_15
    (cl:cons ':header (header msg))
    (cl:cons ':num_sat (num_sat msg))
    (cl:cons ':rtk_mode_fix (rtk_mode_fix msg))
    (cl:cons ':sat (sat msg))
    (cl:cons ':cn0 (cn0 msg))
    (cl:cons ':system_error (system_error msg))
    (cl:cons ':io_error (io_error msg))
    (cl:cons ':swift_nap_error (swift_nap_error msg))
    (cl:cons ':external_antenna_present (external_antenna_present msg))
    (cl:cons ':num_gps_sat (num_gps_sat msg))
    (cl:cons ':cn0_gps (cn0_gps msg))
    (cl:cons ':num_sbas_sat (num_sbas_sat msg))
    (cl:cons ':cn0_sbas (cn0_sbas msg))
    (cl:cons ':num_glonass_sat (num_glonass_sat msg))
    (cl:cons ':cn0_glonass (cn0_glonass msg))
    (cl:cons ':fix_mode (fix_mode msg))
))
