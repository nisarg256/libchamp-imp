# quadruped_mujoco/CMakeLists.txt
cmake_minimum_required(VERSION 3.8)
project(quadruped_mujoco)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Add cmake modules path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(mujoco REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Generate messages
set(MSG_FILES
  "msg/Contacts.msg"
  "msg/Joints.msg"
  "msg/Pose.msg"
  "msg/Velocities.msg"
  "msg/ContactsStamped.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${MSG_FILES}
  DEPENDENCIES std_msgs geometry_msgs
)

# Include directories
include_directories(
  include
  ${MUJOCO_INCLUDE_DIRS}
  ${OPENGL_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIRS}
)

# Create the mujoco interface node
add_executable(mujoco_interface_node 
  src/mujoco_interface.cpp
)

ament_target_dependencies(mujoco_interface_node
  rclcpp
  std_msgs
  geometry_msgs
  sensor_msgs
  tf2
  tf2_ros
)

target_link_libraries(mujoco_interface_node
  ${MUJOCO_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
)

# Install
install(
  DIRECTORY include/
  DESTINATION include
)

install(
  DIRECTORY config launch urdf models cmake
  DESTINATION share/${PROJECT_NAME}
)

install(TARGETS
  mujoco_interface_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()