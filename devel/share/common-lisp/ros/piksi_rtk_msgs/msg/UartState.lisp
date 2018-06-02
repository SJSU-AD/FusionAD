; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude UartState.msg.html

(cl:defclass <UartState> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (uart_a_tx_throughput
    :reader uart_a_tx_throughput
    :initarg :uart_a_tx_throughput
    :type cl:float
    :initform 0.0)
   (uart_a_rx_throughput
    :reader uart_a_rx_throughput
    :initarg :uart_a_rx_throughput
    :type cl:float
    :initform 0.0)
   (uart_a_crc_error_count
    :reader uart_a_crc_error_count
    :initarg :uart_a_crc_error_count
    :type cl:fixnum
    :initform 0)
   (uart_a_io_error_count
    :reader uart_a_io_error_count
    :initarg :uart_a_io_error_count
    :type cl:fixnum
    :initform 0)
   (uart_a_tx_buffer_level
    :reader uart_a_tx_buffer_level
    :initarg :uart_a_tx_buffer_level
    :type cl:fixnum
    :initform 0)
   (uart_a_rx_buffer_level
    :reader uart_a_rx_buffer_level
    :initarg :uart_a_rx_buffer_level
    :type cl:fixnum
    :initform 0)
   (uart_b_tx_throughput
    :reader uart_b_tx_throughput
    :initarg :uart_b_tx_throughput
    :type cl:float
    :initform 0.0)
   (uart_b_rx_throughput
    :reader uart_b_rx_throughput
    :initarg :uart_b_rx_throughput
    :type cl:float
    :initform 0.0)
   (uart_b_crc_error_count
    :reader uart_b_crc_error_count
    :initarg :uart_b_crc_error_count
    :type cl:fixnum
    :initform 0)
   (uart_b_io_error_count
    :reader uart_b_io_error_count
    :initarg :uart_b_io_error_count
    :type cl:fixnum
    :initform 0)
   (uart_b_tx_buffer_level
    :reader uart_b_tx_buffer_level
    :initarg :uart_b_tx_buffer_level
    :type cl:fixnum
    :initform 0)
   (uart_b_rx_buffer_level
    :reader uart_b_rx_buffer_level
    :initarg :uart_b_rx_buffer_level
    :type cl:fixnum
    :initform 0)
   (uart_ftdi_tx_throughput
    :reader uart_ftdi_tx_throughput
    :initarg :uart_ftdi_tx_throughput
    :type cl:float
    :initform 0.0)
   (uart_ftdi_rx_throughput
    :reader uart_ftdi_rx_throughput
    :initarg :uart_ftdi_rx_throughput
    :type cl:float
    :initform 0.0)
   (uart_ftdi_crc_error_count
    :reader uart_ftdi_crc_error_count
    :initarg :uart_ftdi_crc_error_count
    :type cl:fixnum
    :initform 0)
   (uart_ftdi_io_error_count
    :reader uart_ftdi_io_error_count
    :initarg :uart_ftdi_io_error_count
    :type cl:fixnum
    :initform 0)
   (uart_ftdi_tx_buffer_level
    :reader uart_ftdi_tx_buffer_level
    :initarg :uart_ftdi_tx_buffer_level
    :type cl:fixnum
    :initform 0)
   (uart_ftdi_rx_buffer_level
    :reader uart_ftdi_rx_buffer_level
    :initarg :uart_ftdi_rx_buffer_level
    :type cl:fixnum
    :initform 0)
   (latency_avg
    :reader latency_avg
    :initarg :latency_avg
    :type cl:integer
    :initform 0)
   (latency_lmin
    :reader latency_lmin
    :initarg :latency_lmin
    :type cl:integer
    :initform 0)
   (latency_lmax
    :reader latency_lmax
    :initarg :latency_lmax
    :type cl:integer
    :initform 0)
   (latency_current
    :reader latency_current
    :initarg :latency_current
    :type cl:integer
    :initform 0)
   (obs_period_avg
    :reader obs_period_avg
    :initarg :obs_period_avg
    :type cl:integer
    :initform 0)
   (obs_period_pmin
    :reader obs_period_pmin
    :initarg :obs_period_pmin
    :type cl:integer
    :initform 0)
   (obs_period_pmax
    :reader obs_period_pmax
    :initarg :obs_period_pmax
    :type cl:integer
    :initform 0)
   (obs_period_current
    :reader obs_period_current
    :initarg :obs_period_current
    :type cl:integer
    :initform 0))
)

(cl:defclass UartState (<UartState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UartState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UartState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<UartState> is deprecated: use piksi_rtk_msgs-msg:UartState instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'uart_a_tx_throughput-val :lambda-list '(m))
(cl:defmethod uart_a_tx_throughput-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_a_tx_throughput-val is deprecated.  Use piksi_rtk_msgs-msg:uart_a_tx_throughput instead.")
  (uart_a_tx_throughput m))

(cl:ensure-generic-function 'uart_a_rx_throughput-val :lambda-list '(m))
(cl:defmethod uart_a_rx_throughput-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_a_rx_throughput-val is deprecated.  Use piksi_rtk_msgs-msg:uart_a_rx_throughput instead.")
  (uart_a_rx_throughput m))

(cl:ensure-generic-function 'uart_a_crc_error_count-val :lambda-list '(m))
(cl:defmethod uart_a_crc_error_count-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_a_crc_error_count-val is deprecated.  Use piksi_rtk_msgs-msg:uart_a_crc_error_count instead.")
  (uart_a_crc_error_count m))

(cl:ensure-generic-function 'uart_a_io_error_count-val :lambda-list '(m))
(cl:defmethod uart_a_io_error_count-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_a_io_error_count-val is deprecated.  Use piksi_rtk_msgs-msg:uart_a_io_error_count instead.")
  (uart_a_io_error_count m))

(cl:ensure-generic-function 'uart_a_tx_buffer_level-val :lambda-list '(m))
(cl:defmethod uart_a_tx_buffer_level-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_a_tx_buffer_level-val is deprecated.  Use piksi_rtk_msgs-msg:uart_a_tx_buffer_level instead.")
  (uart_a_tx_buffer_level m))

(cl:ensure-generic-function 'uart_a_rx_buffer_level-val :lambda-list '(m))
(cl:defmethod uart_a_rx_buffer_level-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_a_rx_buffer_level-val is deprecated.  Use piksi_rtk_msgs-msg:uart_a_rx_buffer_level instead.")
  (uart_a_rx_buffer_level m))

(cl:ensure-generic-function 'uart_b_tx_throughput-val :lambda-list '(m))
(cl:defmethod uart_b_tx_throughput-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_b_tx_throughput-val is deprecated.  Use piksi_rtk_msgs-msg:uart_b_tx_throughput instead.")
  (uart_b_tx_throughput m))

(cl:ensure-generic-function 'uart_b_rx_throughput-val :lambda-list '(m))
(cl:defmethod uart_b_rx_throughput-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_b_rx_throughput-val is deprecated.  Use piksi_rtk_msgs-msg:uart_b_rx_throughput instead.")
  (uart_b_rx_throughput m))

(cl:ensure-generic-function 'uart_b_crc_error_count-val :lambda-list '(m))
(cl:defmethod uart_b_crc_error_count-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_b_crc_error_count-val is deprecated.  Use piksi_rtk_msgs-msg:uart_b_crc_error_count instead.")
  (uart_b_crc_error_count m))

(cl:ensure-generic-function 'uart_b_io_error_count-val :lambda-list '(m))
(cl:defmethod uart_b_io_error_count-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_b_io_error_count-val is deprecated.  Use piksi_rtk_msgs-msg:uart_b_io_error_count instead.")
  (uart_b_io_error_count m))

(cl:ensure-generic-function 'uart_b_tx_buffer_level-val :lambda-list '(m))
(cl:defmethod uart_b_tx_buffer_level-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_b_tx_buffer_level-val is deprecated.  Use piksi_rtk_msgs-msg:uart_b_tx_buffer_level instead.")
  (uart_b_tx_buffer_level m))

(cl:ensure-generic-function 'uart_b_rx_buffer_level-val :lambda-list '(m))
(cl:defmethod uart_b_rx_buffer_level-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_b_rx_buffer_level-val is deprecated.  Use piksi_rtk_msgs-msg:uart_b_rx_buffer_level instead.")
  (uart_b_rx_buffer_level m))

(cl:ensure-generic-function 'uart_ftdi_tx_throughput-val :lambda-list '(m))
(cl:defmethod uart_ftdi_tx_throughput-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_ftdi_tx_throughput-val is deprecated.  Use piksi_rtk_msgs-msg:uart_ftdi_tx_throughput instead.")
  (uart_ftdi_tx_throughput m))

(cl:ensure-generic-function 'uart_ftdi_rx_throughput-val :lambda-list '(m))
(cl:defmethod uart_ftdi_rx_throughput-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_ftdi_rx_throughput-val is deprecated.  Use piksi_rtk_msgs-msg:uart_ftdi_rx_throughput instead.")
  (uart_ftdi_rx_throughput m))

(cl:ensure-generic-function 'uart_ftdi_crc_error_count-val :lambda-list '(m))
(cl:defmethod uart_ftdi_crc_error_count-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_ftdi_crc_error_count-val is deprecated.  Use piksi_rtk_msgs-msg:uart_ftdi_crc_error_count instead.")
  (uart_ftdi_crc_error_count m))

(cl:ensure-generic-function 'uart_ftdi_io_error_count-val :lambda-list '(m))
(cl:defmethod uart_ftdi_io_error_count-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_ftdi_io_error_count-val is deprecated.  Use piksi_rtk_msgs-msg:uart_ftdi_io_error_count instead.")
  (uart_ftdi_io_error_count m))

(cl:ensure-generic-function 'uart_ftdi_tx_buffer_level-val :lambda-list '(m))
(cl:defmethod uart_ftdi_tx_buffer_level-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_ftdi_tx_buffer_level-val is deprecated.  Use piksi_rtk_msgs-msg:uart_ftdi_tx_buffer_level instead.")
  (uart_ftdi_tx_buffer_level m))

(cl:ensure-generic-function 'uart_ftdi_rx_buffer_level-val :lambda-list '(m))
(cl:defmethod uart_ftdi_rx_buffer_level-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:uart_ftdi_rx_buffer_level-val is deprecated.  Use piksi_rtk_msgs-msg:uart_ftdi_rx_buffer_level instead.")
  (uart_ftdi_rx_buffer_level m))

(cl:ensure-generic-function 'latency_avg-val :lambda-list '(m))
(cl:defmethod latency_avg-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:latency_avg-val is deprecated.  Use piksi_rtk_msgs-msg:latency_avg instead.")
  (latency_avg m))

(cl:ensure-generic-function 'latency_lmin-val :lambda-list '(m))
(cl:defmethod latency_lmin-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:latency_lmin-val is deprecated.  Use piksi_rtk_msgs-msg:latency_lmin instead.")
  (latency_lmin m))

(cl:ensure-generic-function 'latency_lmax-val :lambda-list '(m))
(cl:defmethod latency_lmax-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:latency_lmax-val is deprecated.  Use piksi_rtk_msgs-msg:latency_lmax instead.")
  (latency_lmax m))

(cl:ensure-generic-function 'latency_current-val :lambda-list '(m))
(cl:defmethod latency_current-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:latency_current-val is deprecated.  Use piksi_rtk_msgs-msg:latency_current instead.")
  (latency_current m))

(cl:ensure-generic-function 'obs_period_avg-val :lambda-list '(m))
(cl:defmethod obs_period_avg-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:obs_period_avg-val is deprecated.  Use piksi_rtk_msgs-msg:obs_period_avg instead.")
  (obs_period_avg m))

(cl:ensure-generic-function 'obs_period_pmin-val :lambda-list '(m))
(cl:defmethod obs_period_pmin-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:obs_period_pmin-val is deprecated.  Use piksi_rtk_msgs-msg:obs_period_pmin instead.")
  (obs_period_pmin m))

(cl:ensure-generic-function 'obs_period_pmax-val :lambda-list '(m))
(cl:defmethod obs_period_pmax-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:obs_period_pmax-val is deprecated.  Use piksi_rtk_msgs-msg:obs_period_pmax instead.")
  (obs_period_pmax m))

(cl:ensure-generic-function 'obs_period_current-val :lambda-list '(m))
(cl:defmethod obs_period_current-val ((m <UartState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:obs_period_current-val is deprecated.  Use piksi_rtk_msgs-msg:obs_period_current instead.")
  (obs_period_current m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UartState>) ostream)
  "Serializes a message object of type '<UartState>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'uart_a_tx_throughput))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'uart_a_rx_throughput))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_a_crc_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_a_crc_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_a_io_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_a_io_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_a_tx_buffer_level)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_a_rx_buffer_level)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'uart_b_tx_throughput))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'uart_b_rx_throughput))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_b_crc_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_b_crc_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_b_io_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_b_io_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_b_tx_buffer_level)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_b_rx_buffer_level)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'uart_ftdi_tx_throughput))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'uart_ftdi_rx_throughput))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_ftdi_crc_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_ftdi_crc_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_ftdi_io_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_ftdi_io_error_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_ftdi_tx_buffer_level)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_ftdi_rx_buffer_level)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'latency_avg)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'latency_lmin)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'latency_lmax)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'latency_current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_period_avg)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_period_pmin)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_period_pmax)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_period_current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UartState>) istream)
  "Deserializes a message object of type '<UartState>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'uart_a_tx_throughput) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'uart_a_rx_throughput) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_a_crc_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_a_crc_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_a_io_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_a_io_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_a_tx_buffer_level)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_a_rx_buffer_level)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'uart_b_tx_throughput) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'uart_b_rx_throughput) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_b_crc_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_b_crc_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_b_io_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_b_io_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_b_tx_buffer_level)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_b_rx_buffer_level)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'uart_ftdi_tx_throughput) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'uart_ftdi_rx_throughput) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_ftdi_crc_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_ftdi_crc_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_ftdi_io_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uart_ftdi_io_error_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_ftdi_tx_buffer_level)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uart_ftdi_rx_buffer_level)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'latency_avg) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'latency_lmin) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'latency_lmax) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'latency_current) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_period_avg) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_period_pmin) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_period_pmax) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_period_current) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UartState>)))
  "Returns string type for a message object of type '<UartState>"
  "piksi_rtk_msgs/UartState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UartState)))
  "Returns string type for a message object of type 'UartState"
  "piksi_rtk_msgs/UartState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UartState>)))
  "Returns md5sum for a message object of type '<UartState>"
  "b8a9b74f69bcd0dbe0830dfb13841e63")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UartState)))
  "Returns md5sum for a message object of type 'UartState"
  "b8a9b74f69bcd0dbe0830dfb13841e63")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UartState>)))
  "Returns full string definition for message of type '<UartState>"
  (cl:format cl:nil "# The UART message reports data latency and throughput of the UART channels providing SBP I/O.~%# On the default Piksi configuration, UARTs A and B are used for telemetry radios, but can also be host~%# access ports for embedded hosts, or other interfaces in future. The reported percentage values must~%# be normalized. Observations latency and period can be used to assess the health of the differential~%# corrections link. Latency provides the timeliness of received base observations while the period indicates~%# their likelihood of transmission.~%~%Header header~%~%float64 uart_a_tx_throughput      # UART transmit throughput [kB/s].~%float64 uart_a_rx_throughput      # UART transmit throughput [kB/s].~%uint16 uart_a_crc_error_count     # UART CRC error count.~%uint16 uart_a_io_error_count      # UART IO error count.~%uint8 uart_a_tx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).~%uint8 uart_a_rx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).~%~%float64 uart_b_tx_throughput      # UART transmit throughput [kB/s].~%float64 uart_b_rx_throughput      # UART transmit throughput [kB/s].~%uint16 uart_b_crc_error_count     # UART CRC error count.~%uint16 uart_b_io_error_count      # UART IO error count.~%uint8 uart_b_tx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).~%uint8 uart_b_rx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).~%~%float64 uart_ftdi_tx_throughput   # UART transmit throughput [kB/s].~%float64 uart_ftdi_rx_throughput   # UART receive throughput [kB/s].~%uint16 uart_ftdi_crc_error_count  # UART CRC error count.~%uint16 uart_ftdi_io_error_count   # UART IO error count.~%uint8 uart_ftdi_tx_buffer_level   # UART transmit buffer percentage utilization (ranges from 0 to 255).~%uint8 uart_ftdi_rx_buffer_level   # UART receive buffer percentage utilization (ranges from 0 to 255).~%~%int32 latency_avg                 # Average latency [ms].~%int32 latency_lmin                # Minimum latency [ms].~%int32 latency_lmax                # Maximum latency [ms].~%int32 latency_current             # Smoothed estimate of the current latency [ms].~%~%int32 obs_period_avg              # Average period [ms].~%int32 obs_period_pmin             # Minimum period [ms].~%int32 obs_period_pmax             # Maximum period [ms].~%int32 obs_period_current          # Smoothed estimate of the current period [ms].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UartState)))
  "Returns full string definition for message of type 'UartState"
  (cl:format cl:nil "# The UART message reports data latency and throughput of the UART channels providing SBP I/O.~%# On the default Piksi configuration, UARTs A and B are used for telemetry radios, but can also be host~%# access ports for embedded hosts, or other interfaces in future. The reported percentage values must~%# be normalized. Observations latency and period can be used to assess the health of the differential~%# corrections link. Latency provides the timeliness of received base observations while the period indicates~%# their likelihood of transmission.~%~%Header header~%~%float64 uart_a_tx_throughput      # UART transmit throughput [kB/s].~%float64 uart_a_rx_throughput      # UART transmit throughput [kB/s].~%uint16 uart_a_crc_error_count     # UART CRC error count.~%uint16 uart_a_io_error_count      # UART IO error count.~%uint8 uart_a_tx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).~%uint8 uart_a_rx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).~%~%float64 uart_b_tx_throughput      # UART transmit throughput [kB/s].~%float64 uart_b_rx_throughput      # UART transmit throughput [kB/s].~%uint16 uart_b_crc_error_count     # UART CRC error count.~%uint16 uart_b_io_error_count      # UART IO error count.~%uint8 uart_b_tx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).~%uint8 uart_b_rx_buffer_level      # UART transmit buffer percentage utilization (ranges from 0 to 255).~%~%float64 uart_ftdi_tx_throughput   # UART transmit throughput [kB/s].~%float64 uart_ftdi_rx_throughput   # UART receive throughput [kB/s].~%uint16 uart_ftdi_crc_error_count  # UART CRC error count.~%uint16 uart_ftdi_io_error_count   # UART IO error count.~%uint8 uart_ftdi_tx_buffer_level   # UART transmit buffer percentage utilization (ranges from 0 to 255).~%uint8 uart_ftdi_rx_buffer_level   # UART receive buffer percentage utilization (ranges from 0 to 255).~%~%int32 latency_avg                 # Average latency [ms].~%int32 latency_lmin                # Minimum latency [ms].~%int32 latency_lmax                # Maximum latency [ms].~%int32 latency_current             # Smoothed estimate of the current latency [ms].~%~%int32 obs_period_avg              # Average period [ms].~%int32 obs_period_pmin             # Minimum period [ms].~%int32 obs_period_pmax             # Maximum period [ms].~%int32 obs_period_current          # Smoothed estimate of the current period [ms].~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UartState>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
     2
     2
     1
     1
     8
     8
     2
     2
     1
     1
     8
     8
     2
     2
     1
     1
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UartState>))
  "Converts a ROS message object to a list"
  (cl:list 'UartState
    (cl:cons ':header (header msg))
    (cl:cons ':uart_a_tx_throughput (uart_a_tx_throughput msg))
    (cl:cons ':uart_a_rx_throughput (uart_a_rx_throughput msg))
    (cl:cons ':uart_a_crc_error_count (uart_a_crc_error_count msg))
    (cl:cons ':uart_a_io_error_count (uart_a_io_error_count msg))
    (cl:cons ':uart_a_tx_buffer_level (uart_a_tx_buffer_level msg))
    (cl:cons ':uart_a_rx_buffer_level (uart_a_rx_buffer_level msg))
    (cl:cons ':uart_b_tx_throughput (uart_b_tx_throughput msg))
    (cl:cons ':uart_b_rx_throughput (uart_b_rx_throughput msg))
    (cl:cons ':uart_b_crc_error_count (uart_b_crc_error_count msg))
    (cl:cons ':uart_b_io_error_count (uart_b_io_error_count msg))
    (cl:cons ':uart_b_tx_buffer_level (uart_b_tx_buffer_level msg))
    (cl:cons ':uart_b_rx_buffer_level (uart_b_rx_buffer_level msg))
    (cl:cons ':uart_ftdi_tx_throughput (uart_ftdi_tx_throughput msg))
    (cl:cons ':uart_ftdi_rx_throughput (uart_ftdi_rx_throughput msg))
    (cl:cons ':uart_ftdi_crc_error_count (uart_ftdi_crc_error_count msg))
    (cl:cons ':uart_ftdi_io_error_count (uart_ftdi_io_error_count msg))
    (cl:cons ':uart_ftdi_tx_buffer_level (uart_ftdi_tx_buffer_level msg))
    (cl:cons ':uart_ftdi_rx_buffer_level (uart_ftdi_rx_buffer_level msg))
    (cl:cons ':latency_avg (latency_avg msg))
    (cl:cons ':latency_lmin (latency_lmin msg))
    (cl:cons ':latency_lmax (latency_lmax msg))
    (cl:cons ':latency_current (latency_current msg))
    (cl:cons ':obs_period_avg (obs_period_avg msg))
    (cl:cons ':obs_period_pmin (obs_period_pmin msg))
    (cl:cons ':obs_period_pmax (obs_period_pmax msg))
    (cl:cons ':obs_period_current (obs_period_current msg))
))
