// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadruped_mujoco:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__POSE__STRUCT_H_
#define QUADRUPED_MUJOCO__MSG__DETAIL__POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

/// Struct defined in msg/Pose in the package quadruped_mujoco.
/**
  * quadruped_mujoco/msg/Pose.msg
 */
typedef struct quadruped_mujoco__msg__Pose
{
  geometry_msgs__msg__Point position;
  geometry_msgs__msg__Quaternion orientation;
} quadruped_mujoco__msg__Pose;

// Struct for a sequence of quadruped_mujoco__msg__Pose.
typedef struct quadruped_mujoco__msg__Pose__Sequence
{
  quadruped_mujoco__msg__Pose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadruped_mujoco__msg__Pose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__POSE__STRUCT_H_
