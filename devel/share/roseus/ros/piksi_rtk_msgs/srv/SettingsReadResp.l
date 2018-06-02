;; Auto-generated. Do not edit!


(when (boundp 'piksi_rtk_msgs::SettingsReadResp)
  (if (not (find-package "PIKSI_RTK_MSGS"))
    (make-package "PIKSI_RTK_MSGS"))
  (shadow 'SettingsReadResp (find-package "PIKSI_RTK_MSGS")))
(unless (find-package "PIKSI_RTK_MSGS::SETTINGSREADRESP")
  (make-package "PIKSI_RTK_MSGS::SETTINGSREADRESP"))
(unless (find-package "PIKSI_RTK_MSGS::SETTINGSREADRESPREQUEST")
  (make-package "PIKSI_RTK_MSGS::SETTINGSREADRESPREQUEST"))
(unless (find-package "PIKSI_RTK_MSGS::SETTINGSREADRESPRESPONSE")
  (make-package "PIKSI_RTK_MSGS::SETTINGSREADRESPRESPONSE"))

(in-package "ROS")





(defclass piksi_rtk_msgs::SettingsReadRespRequest
  :super ros::object
  :slots ())

(defmethod piksi_rtk_msgs::SettingsReadRespRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass piksi_rtk_msgs::SettingsReadRespResponse
  :super ros::object
  :slots (_success _message _section_setting _setting _value ))

(defmethod piksi_rtk_msgs::SettingsReadRespResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:message __message) "")
    ((:section_setting __section_setting) "")
    ((:setting __setting) "")
    ((:value __value) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _message (string __message))
   (setq _section_setting (string __section_setting))
   (setq _setting (string __setting))
   (setq _value (string __value))
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
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
    ;; bool _success
    1
    ;; string _message
    4 (length _message)
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
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
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
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _section_setting
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _section_setting (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _setting
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _setting (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _value
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _value (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass piksi_rtk_msgs::SettingsReadResp
  :super ros::object
  :slots ())

(setf (get piksi_rtk_msgs::SettingsReadResp :md5sum-) "c7380bc20753c3393be149ee20d6b7a4")
(setf (get piksi_rtk_msgs::SettingsReadResp :datatype-) "piksi_rtk_msgs/SettingsReadResp")
(setf (get piksi_rtk_msgs::SettingsReadResp :request) piksi_rtk_msgs::SettingsReadRespRequest)
(setf (get piksi_rtk_msgs::SettingsReadResp :response) piksi_rtk_msgs::SettingsReadRespResponse)

(defmethod piksi_rtk_msgs::SettingsReadRespRequest
  (:response () (instance piksi_rtk_msgs::SettingsReadRespResponse :init)))

(setf (get piksi_rtk_msgs::SettingsReadRespRequest :md5sum-) "c7380bc20753c3393be149ee20d6b7a4")
(setf (get piksi_rtk_msgs::SettingsReadRespRequest :datatype-) "piksi_rtk_msgs/SettingsReadRespRequest")
(setf (get piksi_rtk_msgs::SettingsReadRespRequest :definition-)
      "

---
bool success
string message
string section_setting
string setting
string value

")

(setf (get piksi_rtk_msgs::SettingsReadRespResponse :md5sum-) "c7380bc20753c3393be149ee20d6b7a4")
(setf (get piksi_rtk_msgs::SettingsReadRespResponse :datatype-) "piksi_rtk_msgs/SettingsReadRespResponse")
(setf (get piksi_rtk_msgs::SettingsReadRespResponse :definition-)
      "

---
bool success
string message
string section_setting
string setting
string value

")



(provide :piksi_rtk_msgs/SettingsReadResp "c7380bc20753c3393be149ee20d6b7a4")


