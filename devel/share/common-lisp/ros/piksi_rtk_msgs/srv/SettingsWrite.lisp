; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-srv)


;//! \htmlinclude SettingsWrite-request.msg.html

(cl:defclass <SettingsWrite-request> (roslisp-msg-protocol:ros-message)
  ((section_setting
    :reader section_setting
    :initarg :section_setting
    :type cl:string
    :initform "")
   (setting
    :reader setting
    :initarg :setting
    :type cl:string
    :initform "")
   (value
    :reader value
    :initarg :value
    :type cl:string
    :initform ""))
)

(cl:defclass SettingsWrite-request (<SettingsWrite-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SettingsWrite-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SettingsWrite-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-srv:<SettingsWrite-request> is deprecated: use piksi_rtk_msgs-srv:SettingsWrite-request instead.")))

(cl:ensure-generic-function 'section_setting-val :lambda-list '(m))
(cl:defmethod section_setting-val ((m <SettingsWrite-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:section_setting-val is deprecated.  Use piksi_rtk_msgs-srv:section_setting instead.")
  (section_setting m))

(cl:ensure-generic-function 'setting-val :lambda-list '(m))
(cl:defmethod setting-val ((m <SettingsWrite-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:setting-val is deprecated.  Use piksi_rtk_msgs-srv:setting instead.")
  (setting m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <SettingsWrite-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:value-val is deprecated.  Use piksi_rtk_msgs-srv:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SettingsWrite-request>) ostream)
  "Serializes a message object of type '<SettingsWrite-request>"
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
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'value))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SettingsWrite-request>) istream)
  "Deserializes a message object of type '<SettingsWrite-request>"
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
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'value) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'value) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SettingsWrite-request>)))
  "Returns string type for a service object of type '<SettingsWrite-request>"
  "piksi_rtk_msgs/SettingsWriteRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SettingsWrite-request)))
  "Returns string type for a service object of type 'SettingsWrite-request"
  "piksi_rtk_msgs/SettingsWriteRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SettingsWrite-request>)))
  "Returns md5sum for a message object of type '<SettingsWrite-request>"
  "213f9437df3a9ccdceeabec724b32fdc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SettingsWrite-request)))
  "Returns md5sum for a message object of type 'SettingsWrite-request"
  "213f9437df3a9ccdceeabec724b32fdc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SettingsWrite-request>)))
  "Returns full string definition for message of type '<SettingsWrite-request>"
  (cl:format cl:nil "~%~%~%string section_setting~%string setting~%string value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SettingsWrite-request)))
  "Returns full string definition for message of type 'SettingsWrite-request"
  (cl:format cl:nil "~%~%~%string section_setting~%string setting~%string value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SettingsWrite-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'section_setting))
     4 (cl:length (cl:slot-value msg 'setting))
     4 (cl:length (cl:slot-value msg 'value))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SettingsWrite-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SettingsWrite-request
    (cl:cons ':section_setting (section_setting msg))
    (cl:cons ':setting (setting msg))
    (cl:cons ':value (value msg))
))
;//! \htmlinclude SettingsWrite-response.msg.html

(cl:defclass <SettingsWrite-response> (roslisp-msg-protocol:ros-message)
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

(cl:defclass SettingsWrite-response (<SettingsWrite-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SettingsWrite-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SettingsWrite-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-srv:<SettingsWrite-response> is deprecated: use piksi_rtk_msgs-srv:SettingsWrite-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SettingsWrite-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:success-val is deprecated.  Use piksi_rtk_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <SettingsWrite-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:message-val is deprecated.  Use piksi_rtk_msgs-srv:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SettingsWrite-response>) ostream)
  "Serializes a message object of type '<SettingsWrite-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SettingsWrite-response>) istream)
  "Deserializes a message object of type '<SettingsWrite-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SettingsWrite-response>)))
  "Returns string type for a service object of type '<SettingsWrite-response>"
  "piksi_rtk_msgs/SettingsWriteResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SettingsWrite-response)))
  "Returns string type for a service object of type 'SettingsWrite-response"
  "piksi_rtk_msgs/SettingsWriteResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SettingsWrite-response>)))
  "Returns md5sum for a message object of type '<SettingsWrite-response>"
  "213f9437df3a9ccdceeabec724b32fdc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SettingsWrite-response)))
  "Returns md5sum for a message object of type 'SettingsWrite-response"
  "213f9437df3a9ccdceeabec724b32fdc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SettingsWrite-response>)))
  "Returns full string definition for message of type '<SettingsWrite-response>"
  (cl:format cl:nil "bool success~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SettingsWrite-response)))
  "Returns full string definition for message of type 'SettingsWrite-response"
  (cl:format cl:nil "bool success~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SettingsWrite-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SettingsWrite-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SettingsWrite-response
    (cl:cons ':success (success msg))
    (cl:cons ':message (message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SettingsWrite)))
  'SettingsWrite-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SettingsWrite)))
  'SettingsWrite-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SettingsWrite)))
  "Returns string type for a service object of type '<SettingsWrite>"
  "piksi_rtk_msgs/SettingsWrite")