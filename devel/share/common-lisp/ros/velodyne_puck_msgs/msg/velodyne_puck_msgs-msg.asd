
(cl:in-package :asdf)

(defsystem "velodyne_puck_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "VelodynePuckPacket" :depends-on ("_package_VelodynePuckPacket"))
    (:file "_package_VelodynePuckPacket" :depends-on ("_package"))
    (:file "VelodynePuckPoint" :depends-on ("_package_VelodynePuckPoint"))
    (:file "_package_VelodynePuckPoint" :depends-on ("_package"))
    (:file "VelodynePuckScan" :depends-on ("_package_VelodynePuckScan"))
    (:file "_package_VelodynePuckScan" :depends-on ("_package"))
    (:file "VelodynePuckSweep" :depends-on ("_package_VelodynePuckSweep"))
    (:file "_package_VelodynePuckSweep" :depends-on ("_package"))
  ))