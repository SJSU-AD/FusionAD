;; Auto-generated. Do not edit!


(when (boundp 'velodyne_puck_msgs::VelodynePuckPoint)
  (if (not (find-package "VELODYNE_PUCK_MSGS"))
    (make-package "VELODYNE_PUCK_MSGS"))
  (shadow 'VelodynePuckPoint (find-package "VELODYNE_PUCK_MSGS")))
(unless (find-package "VELODYNE_PUCK_MSGS::VELODYNEPUCKPOINT")
  (make-package "VELODYNE_PUCK_MSGS::VELODYNEPUCKPOINT"))

(in-package "ROS")
;;//! \htmlinclude VelodynePuckPoint.msg.html


(defclass velodyne_puck_msgs::VelodynePuckPoint
  :super ros::object
  :slots (_time _x _y _z _azimuth _distance _intensity ))

(defmethod velodyne_puck_msgs::VelodynePuckPoint
  (:init
   (&key
    ((:time __time) 0.0)
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:azimuth __azimuth) 0.0)
    ((:distance __distance) 0.0)
    ((:intensity __intensity) 0.0)
    )
   (send-super :init)
   (setq _time (float __time))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _azimuth (float __azimuth))
   (setq _distance (float __distance))
   (setq _intensity (float __intensity))
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:azimuth
   (&optional __azimuth)
   (if __azimuth (setq _azimuth __azimuth)) _azimuth)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:intensity
   (&optional __intensity)
   (if __intensity (setq _intensity __intensity)) _intensity)
  (:serialization-length
   ()
   (+
    ;; float32 _time
    4
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ;; float64 _azimuth
    8
    ;; float64 _distance
    8
    ;; float64 _intensity
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _time
       (sys::poke _time (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _azimuth
       (sys::poke _azimuth (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _intensity
       (sys::poke _intensity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _time
     (setq _time (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _azimuth
     (setq _azimuth (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _distance
     (setq _distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _intensity
     (setq _intensity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get velodyne_puck_msgs::VelodynePuckPoint :md5sum-) "4f9dbdcdc2cb5386e16b2ab1f416979d")
(setf (get velodyne_puck_msgs::VelodynePuckPoint :datatype-) "velodyne_puck_msgs/VelodynePuckPoint")
(setf (get velodyne_puck_msgs::VelodynePuckPoint :definition-)
      "# Time when the point is captured
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



(provide :velodyne_puck_msgs/VelodynePuckPoint "4f9dbdcdc2cb5386e16b2ab1f416979d")


