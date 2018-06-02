; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-srv)


;//! \htmlinclude SettingsReadResp-request.msg.html

(cl:defclass <SettingsReadResp-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass SettingsReadResp-request (<SettingsReadResp-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SettingsReadResp-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SettingsReadResp-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-srv:<SettingsReadResp-request> is deprecated: use piksi_rtk_msgs-srv:SettingsReadResp-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SettingsReadResp-request>) ostream)
  "Serializes a message object of type '<SettingsReadResp-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SettingsReadResp-request>) istream)
  "Deserializes a message object of type '<SettingsReadResp-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SettingsReadResp-request>)))
  "Returns string type for a service object of type '<SettingsReadResp-request>"
  "piksi_rtk_msgs/SettingsReadRespRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SettingsReadResp-request)))
  "Returns string type for a service object of type 'SettingsReadResp-request"
  "piksi_rtk_msgs/SettingsReadRespRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SettingsReadResp-request>)))
  "Returns md5sum for a message object of type '<SettingsReadResp-request>"
  "c7380bc20753c3393be149ee20d6b7a4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SettingsReadResp-request)))
  "Returns md5sum for a message object of type 'SettingsReadResp-request"
  "c7380bc20753c3393be149ee20d6b7a4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SettingsReadResp-request>)))
  "Returns full string definition for message of type '<SettingsReadResp-request>"
  (cl:format cl:nil "~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SettingsReadResp-request)))
  "Returns full string definition for message of type 'SettingsReadResp-request"
  (cl:format cl:nil "~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SettingsReadResp-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SettingsReadResp-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SettingsReadResp-request
))
;//! \htmlinclude SettingsReadResp-response.msg.html

(cl:defclass <SettingsReadResp-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform "")
   (section_setting
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

(cl:defclass SettingsReadResp-response (<SettingsReadResp-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SettingsReadResp-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SettingsReadResp-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-srv:<SettingsReadResp-response> is deprecated: use piksi_rtk_msgs-srv:SettingsReadResp-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SettingsReadResp-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:success-val is deprecated.  Use piksi_rtk_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <SettingsReadResp-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:message-val is deprecated.  Use piksi_rtk_msgs-srv:message instead.")
  (message m))

(cl:ensure-generic-function 'section_setting-val :lambda-list '(m))
(cl:defmethod section_setting-val ((m <SettingsReadResp-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:section_setting-val is deprecated.  Use piksi_rtk_msgs-srv:section_setting instead.")
  (section_setting m))

(cl:ensure-generic-function 'setting-val :lambda-list '(m))
(cl:defmethod setting-val ((m <SettingsReadResp-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:setting-val is deprecated.  Use piksi_rtk_msgs-srv:setting instead.")
  (setting m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <SettingsReadResp-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-srv:value-val is deprecated.  Use piksi_rtk_msgs-srv:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SettingsReadResp-response>) ostream)
  "Serializes a message object of type '<SettingsReadResp-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SettingsReadResp-response>) istream)
  "Deserializes a message object of type '<SettingsReadResp-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SettingsReadResp-response>)))
  "Returns string type for a service object of type '<SettingsReadResp-response>"
  "piksi_rtk_msgs/SettingsReadRespResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SettingsReadResp-response)))
  "Returns string type for a service object of type 'SettingsReadResp-response"
  "piksi_rtk_msgs/SettingsReadRespResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SettingsReadResp-response>)))
  "Returns md5sum for a message object of type '<SettingsReadResp-response>"
  "c7380bc20753c3393be149ee20d6b7a4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SettingsReadResp-response)))
  "Returns md5sum for a message object of type 'SettingsReadResp-response"
  "c7380bc20753c3393be149ee20d6b7a4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SettingsReadResp-response>)))
  "Returns full string definition for message of type '<SettingsReadResp-response>"
  (cl:format cl:nil "bool success~%string message~%string section_setting~%string setting~%string value~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SettingsReadResp-response)))
  "Returns full string definition for message of type 'SettingsReadResp-response"
  (cl:format cl:nil "bool success~%string message~%string section_setting~%string setting~%string value~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SettingsReadResp-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
     4 (cl:length (cl:slot-value msg 'section_setting))
     4 (cl:length (cl:slot-value msg 'setting))
     4 (cl:length (cl:slot-value msg 'value))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SettingsReadResp-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SettingsReadResp-response
    (cl:cons ':success (success msg))
    (cl:cons ':message (message msg))
    (cl:cons ':section_setting (section_setting msg))
    (cl:cons ':setting (setting msg))
    (cl:cons ':value (value msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SettingsReadResp)))
  'SettingsReadResp-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SettingsReadResp)))
  'SettingsReadResp-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SettingsReadResp)))
  "Returns string type for a service object of type '<SettingsReadResp>"
  "piksi_rtk_msgs/SettingsReadResp")