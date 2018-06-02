;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::SettingsWrite)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'SettingsWrite (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::SETTINGSWRITE")
  (make-package "PIKSI_RTK_MSGS::SETTINGSWRITE"))
(unless (find-package "PIKSI_RTK_MSGS::SETTINGSWRITEREQUEST")
  (make-package "PIKSI_RTK_MSGS::SETTINGSWRITEREQUEST"))
(unless (find-package "PIKSI_RTK_MSGS::SETTINGSWRITERESPONSE")
  (make-package "PIKSI_RTK_MSGS::SETTINGSWRITERESPONSE"))

(in-package "ROS")





(defclass piksi_rtk_msgs::SettingsWriteRequest
  :super ros::object
  :slots (_section_setting _setting _value ))

(defmethod piksi_rtk_msgs::SettingsWriteRequest
  (:init
   (&key
    ((:section_setting __section_setting) "")
    ((:setting __setting) "")
    ((:value __value) "")
    )
   (send-super :init)
   (setq _section_setting (string __section_setting))
   (setq _setting (string __setting))
   (setq _value (string __value))
   self)
  (:section_setting
   (&optional __section_setting)
   (if __section_setting (setq _section_setting __section_setting)) _section_setting)
  (:setting
   (&optional __setting)
   (if __setting (setq _setting __setting)) _setting)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; string _section_setting
    4 (length _section_setting)
    ;; string _setting
    4 (length _setting)
    ;; string _value
    4 (length _value)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _section_setting
       (write-long (length _section_setting) s) (princ _section_setting s)
     ;; string _setting
       (write-long (length _setting) s) (princ _setting s)
     ;; string _value
       (write-long (length _value) s) (princ _value s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _section_setting
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _section_setting (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _setting
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _setting (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _value
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _value (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass piksi_rtk_msgs::SettingsWriteResponse
  :super ros::object
  :slots (_success _message ))

(defmethod piksi_rtk_msgs::SettingsWriteResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _message (string __message))
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass piksi_rtk_msgs::SettingsWrite
  :super ros::object
  :slots ())

(setf (get piksi_rtk_msgs::SettingsWrite :md5sum-) "213f9437df3a9ccdceeabec724b32fdc")
(setf (get piksi_rtk_msgs::SettingsWrite :datatype-) "piksi_rtk_msgs/SettingsWrite")
(setf (get piksi_rtk_msgs::SettingsWrite :request) piksi_rtk_msgs::SettingsWriteRequest)
(setf (get piksi_rtk_msgs::SettingsWrite :response) piksi_rtk_msgs::SettingsWriteResponse)

(defmethod piksi_rtk_msgs::SettingsWriteRequest
  (:response () (instance piksi_rtk_msgs::SettingsWriteResponse :init)))

(setf (get piksi_rtk_msgs::SettingsWriteRequest :md5sum-) "213f9437df3a9ccdceeabec724b32fdc")
(setf (get piksi_rtk_msgs::SettingsWriteRequest :datatype-) "piksi_rtk_msgs/SettingsWriteRequest")
(setf (get piksi_rtk_msgs::SettingsWriteRequest :definition-)
      "


string section_setting
string setting
string value
---
bool success
string message

")

(setf (get piksi_rtk_msgs::SettingsWriteResponse :md5sum-) "213f9437df3a9ccdceeabec724b32fdc")
(setf (get piksi_rtk_msgs::SettingsWriteResponse :datatype-) "piksi_rtk_msgs/SettingsWriteResponse")
(setf (get piksi_rtk_msgs::SettingsWriteResponse :definition-)
      "


string section_setting
string setting
string value
---
bool success
string message

")



(provide :piksi_rtk_msgs/SettingsWrite "213f9437df3a9ccdceeabec724b32fdc")


