; Auto-generated. Do not edit!


(cl:in-package velodyne_puck_msgs-msg)


;//! \htmlinclude VelodynePuckPacket.msg.html

(cl:defclass <VelodynePuckPacket> (roslisp-msg-protocol:ros-message)
  ((stamp
    :reader stamp
    :initarg :stamp
    :type cl:real
    :initform 0)
   (data
    :reader data
    :initarg :data
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 1206 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass VelodynePuckPacket (<VelodynePuckPacket>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <VelodynePuckPacket>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'VelodynePuckPacket)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name velodyne_puck_msgs-msg:<VelodynePuckPacket> is deprecated: use velodyne_puck_msgs-msg:VelodynePuckPacket instead.")))

(cl:ensure-generic-function 'stamp-val :lambda-list '(m))
(cl:defmethod stamp-val ((m <VelodynePuckPacket>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader velodyne_puck_msgs-msg:stamp-val is deprecated.  Use velodyne_puck_msgs-msg:stamp instead.")
  (stamp m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <VelodynePuckPacket>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader velodyne_puck_msgs-msg:data-val is deprecated.  Use velodyne_puck_msgs-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <VelodynePuckPacket>) ostream)
  "Serializes a message object of type '<VelodynePuckPacket>"
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'stamp)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'stamp) (cl:floor (cl:slot-value msg 'stamp)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <VelodynePuckPacket>) istream)
  "Deserializes a message object of type '<VelodynePuckPacket>"
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stamp) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  (cl:setf (cl:slot-value msg 'data) (cl:make-array 1206))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i 1206)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<VelodynePuckPacket>)))
  "Returns string type for a message object of type '<VelodynePuckPacket>"
  "velodyne_puck_msgs/VelodynePuckPacket")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'VelodynePuckPacket)))
  "Returns string type for a message object of type 'VelodynePuckPacket"
  "velodyne_puck_msgs/VelodynePuckPacket")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<VelodynePuckPacket>)))
  "Returns md5sum for a message object of type '<VelodynePuckPacket>"
  "ae4f90a23256f44e82baa08dd45c3456")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'VelodynePuckPacket)))
  "Returns md5sum for a message object of type 'VelodynePuckPacket"
  "ae4f90a23256f44e82baa08dd45c3456")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<VelodynePuckPacket>)))
  "Returns full string definition for message of type '<VelodynePuckPacket>"
  (cl:format cl:nil "# Raw Velodyne LIDAR packet.~%~%time stamp              # packet timestamp~%uint8[1206] data        # packet contents~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'VelodynePuckPacket)))
  "Returns full string definition for message of type 'VelodynePuckPacket"
  (cl:format cl:nil "# Raw Velodyne LIDAR packet.~%~%time stamp              # packet timestamp~%uint8[1206] data        # packet contents~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <VelodynePuckPacket>))
  (cl:+ 0
     8
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <VelodynePuckPacket>))
  "Converts a ROS message object to a list"
  (cl:list 'VelodynePuckPacket
    (cl:cons ':stamp (stamp msg))
    (cl:cons ':data (data msg))
))
