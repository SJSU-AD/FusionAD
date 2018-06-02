;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::ReceiverState_V2_2_15)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'ReceiverState_V2_2_15 (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15")
  (make-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))

(in-package "ROS")
;;//! \htmlinclude ReceiverState_V2_2_15.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*CODE_GPS_L1CA*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*CODE_GPS_L1CA* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*CODE_GPS_L1CA* 0)
(intern "*CODE_GPS_L2CM*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*CODE_GPS_L2CM* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*CODE_GPS_L2CM* 1)
(intern "*CODE_SBAS_L1CA*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*CODE_SBAS_L1CA* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*CODE_SBAS_L1CA* 2)
(intern "*CODE_GLO_L1CA*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*CODE_GLO_L1CA* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*CODE_GLO_L1CA* 3)
(intern "*CODE_GLO_L2CA*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*CODE_GLO_L2CA* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*CODE_GLO_L2CA* 4)
(intern "*CODE_GPS_L1P*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*CODE_GPS_L1P* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*CODE_GPS_L1P* 5)
(intern "*CODE_GPS_L2P*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*CODE_GPS_L2P* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*CODE_GPS_L2P* 6)
(intern "*STR_FIX_MODE_INVALID*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*STR_FIX_MODE_INVALID* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*STR_FIX_MODE_INVALID* "Invalid")
(intern "*STR_FIX_MODE_SPP*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*STR_FIX_MODE_SPP* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*STR_FIX_MODE_SPP* "SPP")
(intern "*STR_FIX_MODE_DGNSS*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*STR_FIX_MODE_DGNSS* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*STR_FIX_MODE_DGNSS* "DGNSS")
(intern "*STR_FIX_MODE_FLOAT_RTK*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*STR_FIX_MODE_FLOAT_RTK* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*STR_FIX_MODE_FLOAT_RTK* "FLOAT_RTK")
(intern "*STR_FIX_MODE_FIXED_RTK*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*STR_FIX_MODE_FIXED_RTK* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*STR_FIX_MODE_FIXED_RTK* "FIXED_RTK")
(intern "*STR_FIX_MODE_UNKNOWN*" (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(shadow '*STR_FIX_MODE_UNKNOWN* (find-package "PIKSI_RTK_MSGS::RECEIVERSTATE_V2_2_15"))
(defconstant piksi_rtk_msgs::ReceiverState_V2_2_15::*STR_FIX_MODE_UNKNOWN* "Unknown")
(defclass piksi_rtk_msgs::ReceiverState_V2_2_15
  :super ros::object
  :slots (_header _num_sat _rtk_mode_fix _sat _cn0 _system_error _io_error _swift_nap_error _external_antenna_present _num_gps_sat _cn0_gps _num_sbas_sat _cn0_sbas _num_glonass_sat _cn0_glonass _fix_mode ))

(defmethod piksi_rtk_msgs::ReceiverState_V2_2_15
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:num_sat __num_sat) 0)
    ((:rtk_mode_fix __rtk_mode_fix) nil)
    ((:sat __sat) (make-array 0 :initial-element 0 :element-type :char))
    ((:cn0 __cn0) (make-array 0 :initial-element 0 :element-type :char))
    ((:system_error __system_error) 0)
    ((:io_error __io_error) 0)
    ((:swift_nap_error __swift_nap_error) 0)
    ((:external_antenna_present __external_antenna_present) 0)
    ((:num_gps_sat __num_gps_sat) 0)
    ((:cn0_gps __cn0_gps) (make-array 0 :initial-element 0 :element-type :char))
    ((:num_sbas_sat __num_sbas_sat) 0)
    ((:cn0_sbas __cn0_sbas) (make-array 0 :initial-element 0 :element-type :char))
    ((:num_glonass_sat __num_glonass_sat) 0)
    ((:cn0_glonass __cn0_glonass) (make-array 0 :initial-element 0 :element-type :char))
    ((:fix_mode __fix_mode) "")
    )
   (send-super :init)
   (setq _header __header)
   (setq _num_sat (round __num_sat))
   (setq _rtk_mode_fix __rtk_mode_fix)
   (setq _sat __sat)
   (setq _cn0 __cn0)
   (setq _system_error (round __system_error))
   (setq _io_error (round __io_error))
   (setq _swift_nap_error (round __swift_nap_error))
   (setq _external_antenna_present (round __external_antenna_present))
   (setq _num_gps_sat (round __num_gps_sat))
   (setq _cn0_gps __cn0_gps)
   (setq _num_sbas_sat (round __num_sbas_sat))
   (setq _cn0_sbas __cn0_sbas)
   (setq _num_glonass_sat (round __num_glonass_sat))
   (setq _cn0_glonass __cn0_glonass)
   (setq _fix_mode (string __fix_mode))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:num_sat
   (&optional __num_sat)
   (if __num_sat (setq _num_sat __num_sat)) _num_sat)
  (:rtk_mode_fix
   (&optional __rtk_mode_fix)
   (if __rtk_mode_fix (setq _rtk_mode_fix __rtk_mode_fix)) _rtk_mode_fix)
  (:sat
   (&optional __sat)
   (if __sat (setq _sat __sat)) _sat)
  (:cn0
   (&optional __cn0)
   (if __cn0 (setq _cn0 __cn0)) _cn0)
  (:system_error
   (&optional __system_error)
   (if __system_error (setq _system_error __system_error)) _system_error)
  (:io_error
   (&optional __io_error)
   (if __io_error (setq _io_error __io_error)) _io_error)
  (:swift_nap_error
   (&optional __swift_nap_error)
   (if __swift_nap_error (setq _swift_nap_error __swift_nap_error)) _swift_nap_error)
  (:external_antenna_present
   (&optional __external_antenna_present)
   (if __external_antenna_present (setq _external_antenna_present __external_antenna_present)) _external_antenna_present)
  (:num_gps_sat
   (&optional __num_gps_sat)
   (if __num_gps_sat (setq _num_gps_sat __num_gps_sat)) _num_gps_sat)
  (:cn0_gps
   (&optional __cn0_gps)
   (if __cn0_gps (setq _cn0_gps __cn0_gps)) _cn0_gps)
  (:num_sbas_sat
   (&optional __num_sbas_sat)
   (if __num_sbas_sat (setq _num_sbas_sat __num_sbas_sat)) _num_sbas_sat)
  (:cn0_sbas
   (&optional __cn0_sbas)
   (if __cn0_sbas (setq _cn0_sbas __cn0_sbas)) _cn0_sbas)
  (:num_glonass_sat
   (&optional __num_glonass_sat)
   (if __num_glonass_sat (setq _num_glonass_sat __num_glonass_sat)) _num_glonass_sat)
  (:cn0_glonass
   (&optional __cn0_glonass)
   (if __cn0_glonass (setq _cn0_glonass __cn0_glonass)) _cn0_glonass)
  (:fix_mode
   (&optional __fix_mode)
   (if __fix_mode (setq _fix_mode __fix_mode)) _fix_mode)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _num_sat
    1
    ;; bool _rtk_mode_fix
    1
    ;; uint8[] _sat
    (* 1    (length _sat)) 4
    ;; uint8[] _cn0
    (* 1    (length _cn0)) 4
    ;; uint8 _system_error
    1
    ;; uint8 _io_error
    1
    ;; uint8 _swift_nap_error
    1
    ;; uint8 _external_antenna_present
    1
    ;; uint8 _num_gps_sat
    1
    ;; uint8[] _cn0_gps
    (* 1    (length _cn0_gps)) 4
    ;; uint8 _num_sbas_sat
    1
    ;; uint8[] _cn0_sbas
    (* 1    (length _cn0_sbas)) 4
    ;; uint8 _num_glonass_sat
    1
    ;; uint8[] _cn0_glonass
    (* 1    (length _cn0_glonass)) 4
    ;; string _fix_mode
    4 (length _fix_mode)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _num_sat
       (write-byte _num_sat s)
     ;; bool _rtk_mode_fix
       (if _rtk_mode_fix (write-byte -1 s) (write-byte 0 s))
     ;; uint8[] _sat
     (write-long (length _sat) s)
     (princ _sat s)
     ;; uint8[] _cn0
     (write-long (length _cn0) s)
     (princ _cn0 s)
     ;; uint8 _system_error
       (write-byte _system_error s)
     ;; uint8 _io_error
       (write-byte _io_error s)
     ;; uint8 _swift_nap_error
       (write-byte _swift_nap_error s)
     ;; uint8 _external_antenna_present
       (write-byte _external_antenna_present s)
     ;; uint8 _num_gps_sat
       (write-byte _num_gps_sat s)
     ;; uint8[] _cn0_gps
     (write-long (length _cn0_gps) s)
     (princ _cn0_gps s)
     ;; uint8 _num_sbas_sat
       (write-byte _num_sbas_sat s)
     ;; uint8[] _cn0_sbas
     (write-long (length _cn0_sbas) s)
     (princ _cn0_sbas s)
     ;; uint8 _num_glonass_sat
       (write-byte _num_glonass_sat s)
     ;; uint8[] _cn0_glonass
     (write-long (length _cn0_glonass) s)
     (princ _cn0_glonass s)
     ;; string _fix_mode
       (write-long (length _fix_mode) s) (princ _fix_mode s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _num_sat
     (setq _num_sat (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _rtk_mode_fix
     (setq _rtk_mode_fix (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8[] _sat
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _sat (make-array n :element-type :char))
     (replace _sat buf :start2 ptr-) (incf ptr- n))
   ;; uint8[] _cn0
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _cn0 (make-array n :element-type :char))
     (replace _cn0 buf :start2 ptr-) (incf ptr- n))
   ;; uint8 _system_error
     (setq _system_error (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _io_error
     (setq _io_error (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _swift_nap_error
     (setq _swift_nap_error (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _external_antenna_present
     (setq _external_antenna_present (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _num_gps_sat
     (setq _num_gps_sat (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8[] _cn0_gps
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _cn0_gps (make-array n :element-type :char))
     (replace _cn0_gps buf :start2 ptr-) (incf ptr- n))
   ;; uint8 _num_sbas_sat
     (setq _num_sbas_sat (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8[] _cn0_sbas
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _cn0_sbas (make-array n :element-type :char))
     (replace _cn0_sbas buf :start2 ptr-) (incf ptr- n))
   ;; uint8 _num_glonass_sat
     (setq _num_glonass_sat (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8[] _cn0_glonass
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _cn0_glonass (make-array n :element-type :char))
     (replace _cn0_glonass buf :start2 ptr-) (incf ptr- n))
   ;; string _fix_mode
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _fix_mode (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get piksi_rtk_msgs::ReceiverState_V2_2_15 :md5sum-) "0b24eec3eea4c8a5bf60087436d79950")
(setf (get piksi_rtk_msgs::ReceiverState_V2_2_15 :datatype-) "piksi_rtk_msgs/ReceiverState_V2_2_15")
(setf (get piksi_rtk_msgs::ReceiverState_V2_2_15 :definition-)
      "# Miscellaneous information form different SBP messages

# Message definition based on libsbp v2.2.15


Header header

uint8 num_sat                   # Number of satellites.
bool rtk_mode_fix 	            # 1 = Fixed, 0 = Float.
uint8[] sat                     # Constellation-specific satellite identifier.
uint8[] cn0                     # Carrier-to-Noise density. Zero implies invalid cn0 [dB Hz / 4].
uint8 system_error              # System Error Flag.
uint8 io_error                  # IO Error Flag.
uint8 swift_nap_error           # SwiftNAP Error Flag.
uint8 external_antenna_present  # External Antenna Present Flag.
uint8 num_gps_sat               # Number of GPS satellites.
uint8[] cn0_gps                 # Carrier-to-Noise density of GPS satellites. Zero implies invalid cn0 [dB Hz / 4].
uint8 num_sbas_sat              # Number of SBAS satellites.
uint8[] cn0_sbas                # Carrier-to-Noise density of SBAS satellites. Zero implies invalid cn0 [dB Hz / 4].
uint8 num_glonass_sat           # Number of GLONASS satellites.
uint8[] cn0_glonass             # Carrier-to-Noise density of GLONASS satellites. Zero implies invalid cn0 [dB Hz / 4].
string fix_mode                 # Invalid, Single Point Position (SPP), Differential GNSS (DGNSS), Float RTK, Fixed RTK.


uint8 CODE_GPS_L1CA     = 0
uint8 CODE_GPS_L2CM     = 1
uint8 CODE_SBAS_L1CA    = 2
uint8 CODE_GLO_L1CA     = 3
uint8 CODE_GLO_L2CA     = 4
uint8 CODE_GPS_L1P      = 5
uint8 CODE_GPS_L2P      = 6

string STR_FIX_MODE_INVALID   = Invalid
string STR_FIX_MODE_SPP       = SPP
string STR_FIX_MODE_DGNSS     = DGNSS
string STR_FIX_MODE_FLOAT_RTK = FLOAT_RTK
string STR_FIX_MODE_FIXED_RTK = FIXED_RTK
string STR_FIX_MODE_UNKNOWN   = Unknown

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :piksi_rtk_msgs/ReceiverState_V2_2_15 "0b24eec3eea4c8a5bf60087436d79950")


