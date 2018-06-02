cmake_minimum_required(VERSION 2.8.3)
project(velodyne_puck_decoder)

add_definitions(-std=c++0x)

find_package(catkin REQUIRED COMPONENTS
  nodelet
  roscpp
  pluginlib
  sensor_msgs
  pcl_ros
  pcl_conversions
  velodyne_puck_msgs
)
find_package(Boost REQUIRED)


catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES velodyne_puck_decoder
  CATKIN_DEPENDS
    roscpp nodelet sensor_msgs pluginlib
    pcl_ros pcl_conversions
    velodyne_puck_msgs
  DEPENDS
    Boost
)

include_directories(
  include
  ${Boost_INCLUDE_DIR}
  ${catkin_INCLUDE_DIRS}
)

link_directories(
  ${catkin_LIBRARY_DIRS}
)

# Velodyne Puck Decoder
add_library(velodyne_puck_decoder
  src/velodyne_puck_decoder.cpp
)
target_link_libraries(velodyne_puck_decoder
  ${catkin_LIBRARIES}
)
add_dependencies(velodyne_puck_decoder
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

# Velodyne Puck Decoder nodelet
add_library(velodyne_puck_decoder_nodelet
  src/velodyne_puck_decoder_nodelet.cpp
)
target_link_libraries(velodyne_puck_decoder_nodelet
  velodyne_puck_decoder
  ${catkin_LIBRARIES}
)
add_dependencies(velodyne_puck_decoder_nodelet
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

# Velodyne Puck Decoder node
#add_executable(velodyne_puck_decoder_node
#  src/velodyne_puck_decoder_node.cpp
#)
#target_link_libraries(velodyne_puck_decoder_node
#  velodyne_puck_decoder
#  profiler
#  ${catkin_LIBRARIES}
#)
#add_dependencies(velodyne_puck_decoder_node
#  ${${PROJECT_NAME}_EXPORTED_TARGETS}
#  ${catkin_EXPORTED_TARGETS}
#)
