;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::SettingsReadReq)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'SettingsReadReq (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::SETTINGSREADREQ")
  (make-package "PIKSI_RTK_MSGS::SETTINGSREADREQ"))
(unless (find-package "PIKSI_RTK_MSGS::SETTINGSREADREQREQUEST")
  (make-package "PIKSI_RTK_MSGS::SETTINGSREADREQREQUEST"))
(unless (find-package "PIKSI_RTK_MSGS::SETTINGSREADREQRESPONSE")
  (make-package "PIKSI_RTK_MSGS::SETTINGSREADREQRESPONSE"))

(in-package "ROS")





(defclass piksi_rtk_msgs::SettingsReadReqRequest
  :super ros::object
  :slots (_section_setting _setting ))

(defmethod piksi_rtk_msgs::SettingsReadReqRequest
  (:init
   (&key
    ((:section_setting __section_setting) "")
    ((:setting __setting) "")
    )
   (send-super :init)
   (setq _section_setting (string __section_setting))
   (setq _setting (string __setting))
   self)
  (:section_setting
   (&optional __section_setting)
   (if __section_setting (setq _section_setting __section_setting)) _section_setting)
  (:setting
   (&optional __setting)
   (if __setting (setq _setting __setting)) _setting)
  (:serialization-length
   ()
   (+
    ;; string _section_setting
    4 (length _section_setting)
    ;; string _setting
    4 (length _setting)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _section_setting
       (write-long (length _section_setting) s) (princ _section_setting s)
     ;; string _setting
       (write-long (length _setting) s) (princ _setting s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _section_setting
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _section_setting (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _setting
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _setting (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass piksi_rtk_msgs::SettingsReadReqResponse
  :super ros::object
  :slots (_success _message ))

(defmethod piksi_rtk_msgs::SettingsReadReqResponse
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

(defclass piksi_rtk_msgs::SettingsReadReq
  :super ros::object
  :slots ())

(setf (get piksi_rtk_msgs::SettingsReadReq :md5sum-) "d894dfc3bc541068b4b4593028b123ee")
(setf (get piksi_rtk_msgs::SettingsReadReq :datatype-) "piksi_rtk_msgs/SettingsReadReq")
(setf (get piksi_rtk_msgs::SettingsReadReq :request) piksi_rtk_msgs::SettingsReadReqRequest)
(setf (get piksi_rtk_msgs::SettingsReadReq :response) piksi_rtk_msgs::SettingsReadReqResponse)

(defmethod piksi_rtk_msgs::SettingsReadReqRequest
  (:response () (instance piksi_rtk_msgs::SettingsReadReqResponse :init)))

(setf (get piksi_rtk_msgs::SettingsReadReqRequest :md5sum-) "d894dfc3bc541068b4b4593028b123ee")
(setf (get piksi_rtk_msgs::SettingsReadReqRequest :datatype-) "piksi_rtk_msgs/SettingsReadReqRequest")
(setf (get piksi_rtk_msgs::SettingsReadReqRequest :definition-)
      "


string section_setting
string setting
---
bool success
string message

")

(setf (get piksi_rtk_msgs::SettingsReadReqResponse :md5sum-) "d894dfc3bc541068b4b4593028b123ee")
(setf (get piksi_rtk_msgs::SettingsReadReqResponse :datatype-) "piksi_rtk_msgs/SettingsReadReqResponse")
(setf (get piksi_rtk_msgs::SettingsReadReqResponse :definition-)
      "


string section_setting
string setting
---
bool success
string message

")



(provide :piksi_rtk_msgs/SettingsReadReq "d894dfc3bc541068b4b4593028b123ee")


