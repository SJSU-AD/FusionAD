
(cl:in-package :asdf)

(defsystem "piksi_rtk_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SettingsReadReq" :depends-on ("_package_SettingsReadReq"))
    (:file "_package_SettingsReadReq" :depends-on ("_package"))
    (:file "SettingsReadResp" :depends-on ("_package_SettingsReadResp"))
    (:file "_package_SettingsReadResp" :depends-on ("_package"))
    (:file "SettingsWrite" :depends-on ("_package_SettingsWrite"))
    (:file "_package_SettingsWrite" :depends-on ("_package"))
  ))