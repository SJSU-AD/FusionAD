cmake_minimum_required(VERSION 2.8.3)
project(velodyne_puck_driver)

add_definitions(-std=c++0x)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  diagnostic_updater
  nodelet

  velodyne_puck_msgs
)

find_package(Boost REQUIRED)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES velodyne_puck_driver
  CATKIN_DEPENDS
    roscpp diagnostic_updater nodelet
    velodyne_puck_msgs
  DEPENDS
    boost
)

include_directories(
  include
  ${Boost_INCLUDE_DIR}
  ${catkin_INCLUDE_DIRS}
)

link_directories(
  ${catkin_LIBRARY_DIRS}
)

# Velodyne Puck driver
add_library(velodyne_puck_driver
  src/velodyne_puck_driver.cc
)
target_link_libraries(velodyne_puck_driver
  ${catkin_LIBRARIES}
)
add_dependencies(velodyne_puck_driver
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

# Velodyne Puck nodelet
add_library(velodyne_puck_driver_nodelet
  src/velodyne_puck_driver_nodelet.cc
)
target_link_libraries(velodyne_puck_driver_nodelet
  velodyne_puck_driver
  ${catkin_LIBRARIES}
)
add_dependencies(velodyne_puck_driver_nodelet
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

# Velodyne Puck node
#add_executable(velodyne_puck_driver_node
#  src/velodyne_puck_driver_node.cc
#)
#target_link_libraries(velodyne_puck_driver_node
#  velodyne_puck_driver
#  ${catkin_LIBRARIES}
#)
#add_dependencies(velodyne_puck_driver_node
#  ${${PROJECT_NAME}_EXPORTED_TARGETS}
#  ${catkin_EXPORTED_TARGETS}
#)
