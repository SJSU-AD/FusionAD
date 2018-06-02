; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-srv)


;//! \htmlinclude SettingsReadReq-request.msg.html

(cl:defclass <SettingsReadReq-request> (roslisp-msg-protocol:ros-message)
  ((section_setting
    :reader section_setting
    :initarg :section_setting
    :type cl:string
    :initform "")
   (setting
    :reader setting
    :initarg :setting
    :type cl:string
    :initform ""))
)

(cl:defclass SettingsReadReq-request (<SettingsReadReq-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SettingsReadReq-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SettingsReadReq-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-srv:<SettingsReadReq-request> is deprecated: use piksi_rtk_msgs-srv:SettingsReadReq-request instead.")))

(cl:ensure-generic-function 'section_setting-val :lambda-list '(m))
(cl:defmethod section_setting-val ((m <SettingsReadReq-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:section_setting-val is deprecated.  Use piksi_rtk_msgs-srv:section_setting instead.")
  (section_setting m))

(cl:ensure-generic-function 'setting-val :lambda-list '(m))
(cl:defmethod setting-val ((m <SettingsReadReq-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:setting-val is deprecated.  Use piksi_rtk_msgs-srv:setting instead.")
  (setting m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SettingsReadReq-request>) ostream)
  "Serializes a message object of type '<SettingsReadReq-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'section_setting))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'section_setting))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'setting))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'setting))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SettingsReadReq-request>) istream)
  "Deserializes a message object of type '<SettingsReadReq-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'section_setting) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'section_setting) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'setting) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'setting) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SettingsReadReq-request>)))
  "Returns string type for a service object of type '<SettingsReadReq-request>"
  "piksi_rtk_msgs/SettingsReadReqRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SettingsReadReq-request)))
  "Returns string type for a service object of type 'SettingsReadReq-request"
  "piksi_rtk_msgs/SettingsReadReqRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SettingsReadReq-request>)))
  "Returns md5sum for a message object of type '<SettingsReadReq-request>"
  "d894dfc3bc541068b4b4593028b123ee")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SettingsReadReq-request)))
  "Returns md5sum for a message object of type 'SettingsReadReq-request"
  "d894dfc3bc541068b4b4593028b123ee")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SettingsReadReq-request>)))
  "Returns full string definition for message of type '<SettingsReadReq-request>"
  (cl:format cl:nil "~%~%~%string section_setting~%string setting~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SettingsReadReq-request)))
  "Returns full string definition for message of type 'SettingsReadReq-request"
  (cl:format cl:nil "~%~%~%string section_setting~%string setting~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SettingsReadReq-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'section_setting))
     4 (cl:length (cl:slot-value msg 'setting))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SettingsReadReq-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SettingsReadReq-request
    (cl:cons ':section_setting (section_setting msg))
    (cl:cons ':setting (setting msg))
))
;//! \htmlinclude SettingsReadReq-response.msg.html

(cl:defclass <SettingsReadReq-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass SettingsReadReq-response (<SettingsReadReq-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SettingsReadReq-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SettingsReadReq-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-srv:<SettingsReadReq-response> is deprecated: use piksi_rtk_msgs-srv:SettingsReadReq-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SettingsReadReq-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:success-val is deprecated.  Use piksi_rtk_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <SettingsReadReq-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:message-val is deprecated.  Use piksi_rtk_msgs-srv:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SettingsReadReq-response>) ostream)
  "Serializes a message object of type '<SettingsReadReq-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SettingsReadReq-response>) istream)
  "Deserializes a message object of type '<SettingsReadReq-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SettingsReadReq-response>)))
  "Returns string type for a service object of type '<SettingsReadReq-response>"
  "piksi_rtk_msgs/SettingsReadReqResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SettingsReadReq-response)))
  "Returns string type for a service object of type 'SettingsReadReq-response"
  "piksi_rtk_msgs/SettingsReadReqResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SettingsReadReq-response>)))
  "Returns md5sum for a message object of type '<SettingsReadReq-response>"
  "d894dfc3bc541068b4b4593028b123ee")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SettingsReadReq-response)))
  "Returns md5sum for a message object of type 'SettingsReadReq-response"
  "d894dfc3bc541068b4b4593028b123ee")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SettingsReadReq-response>)))
  "Returns full string definition for message of type '<SettingsReadReq-response>"
  (cl:format cl:nil "bool success~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SettingsReadReq-response)))
  "Returns full string definition for message of type 'SettingsReadReq-response"
  (cl:format cl:nil "bool success~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SettingsReadReq-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SettingsReadReq-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SettingsReadReq-response
    (cl:cons ':success (success msg))
    (cl:cons ':message (message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SettingsReadReq)))
  'SettingsReadReq-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SettingsReadReq)))
  'SettingsReadReq-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SettingsReadReq)))
  "Returns string type for a service object of type '<SettingsReadReq>"
  "piksi_rtk_msgs/SettingsReadReq")