;; Auto-generated. Do not edit!


(when (boundp 'velodyne_puck_msgs::VelodynePuckScan)
  (if (not (find-package "VELODYNE_PUCK_MSGS"))
    (make-package "VELODYNE_PUCK_MSGS"))
  (shadow 'VelodynePuckScan (find-package "VELODYNE_PUCK_MSGS")))
(unless (find-package "VELODYNE_PUCK_MSGS::VELODYNEPUCKSCAN")
  (make-package "VELODYNE_PUCK_MSGS::VELODYNEPUCKSCAN"))

(in-package "ROS")
;;//! \htmlinclude VelodynePuckScan.msg.html


(defclass velodyne_puck_msgs::VelodynePuckScan
  :super ros::object
  :slots (_altitude _points ))

(defmethod velodyne_puck_msgs::VelodynePuckScan
  (:init
   (&key
    ((:altitude __altitude) 0.0)
    ((:points __points) (let (r) (dotimes (i 0) (push (instance velodyne_puck_msgs::VelodynePuckPoint :init) r)) r))
    )
   (send-super :init)
   (setq _altitude (float __altitude))
   (setq _points __points)
   self)
  (:altitude
   (&optional __altitude)
   (if __altitude (setq _altitude __altitude)) _altitude)
  (:points
   (&rest __points)
   (if (keywordp (car __points))
       (send* _points __points)
     (progn
       (if __points (setq _points (car __points)))
       _points)))
  (:serialization-length
   ()
   (+
    ;; float64 _altitude
    8
    ;; velodyne_puck_msgs/VelodynePuckPoint[] _points
    (apply #'+ (send-all _points :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _altitude
       (sys::poke _altitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; velodyne_puck_msgs/VelodynePuckPoint[] _points
     (write-long (length _points) s)
     (dolist (elem _points)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _altitude
     (setq _altitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; velodyne_puck_msgs/VelodynePuckPoint[] _points
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _points (let (r) (dotimes (i n) (push (instance velodyne_puck_msgs::VelodynePuckPoint :init) r)) r))
     (dolist (elem- _points)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get velodyne_puck_msgs::VelodynePuckScan :md5sum-) "bcd29f667509c681a7820aacabe51d58")
(setf (get velodyne_puck_msgs::VelodynePuckScan :datatype-) "velodyne_puck_msgs/VelodynePuckScan")
(setf (get velodyne_puck_msgs::VelodynePuckScan :definition-)
      "# Altitude of all the points within this scan
float64 altitude

# The valid points in this scan sorted by azimuth
# from 0 to 359.99
VelodynePuckPoint[] points

================================================================================
MSG: velodyne_puck_msgs/VelodynePuckPoint
# Time when the point is captured
float32 time

# Converted distance in the sensor frame
float64 x
float64 y
float64 z

# Raw measurement from velodyne puck
float64 azimuth
float64 distance
float64 intensity

")



(provide :velodyne_puck_msgs/VelodynePuckScan "bcd29f667509c681a7820aacabe51d58")


