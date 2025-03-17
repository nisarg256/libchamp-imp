# quadruped_mujoco/CMakeLists.txt
cmake_minimum_required(VERSION 3.8)
project(quadruped_mujoco)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Add cmake modules path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
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

# Create the library
add_library(${PROJECT_NAME}_lib SHARED
  src/controllers/quadruped_controller.cpp
  # Add other source files here
)

target_include_directories(${PROJECT_NAME}_lib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(${PROJECT_NAME}_lib
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  nav_msgs
  tf2
  tf2_ros
)

rosidl_get_typesupport_target(cpp_typesupport_target "${PROJECT_NAME}" "rosidl_typesupport_cpp")
target_link_libraries(${PROJECT_NAME}_lib "${cpp_typesupport_target}")

# Include directories
include_directories(
  include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${MUJOCO_INCLUDE_DIRS}
  ${OPENGL_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIRS}
)

# Create executables
add_executable(mujoco_interface_node src/mujoco_interface.cpp)
add_executable(quadruped_controller_node src/nodes/quadruped_controller_node.cpp)
add_executable(trot_node src/nodes/trot_node.cpp)
add_executable(turn_node src/nodes/turn_node.cpp)
add_executable(waypoint_nav_node src/nodes/waypoint_nav_node.cpp)
add_executable(mujoco_sim_node src/nodes/mujoco_sim_node.cpp)

# Link executables with library
foreach(target 
    quadruped_controller_node 
    trot_node 
    turn_node 
    waypoint_nav_node)
  target_link_libraries(${target} ${PROJECT_NAME}_lib)
  ament_target_dependencies(${target}
    rclcpp
    std_msgs
    geometry_msgs
    sensor_msgs
    nav_msgs
    tf2
    tf2_ros
  )
endforeach()

# Link mujoco interface
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

# Link MuJoCo simulation node
ament_target_dependencies(mujoco_sim_node
  rclcpp
  sensor_msgs
)

target_link_libraries(mujoco_sim_node
  ${PROJECT_NAME}_lib
  ${MUJOCO_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
)

# Install
install(TARGETS ${PROJECT_NAME}_lib
  EXPORT ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(TARGETS 
  trot_node
  turn_node
  waypoint_nav_node
  quadruped_controller_node
  mujoco_sim_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME}_lib)
ament_export_targets(${PROJECT_NAME})

ament_package()