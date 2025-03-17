// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadruped_mujoco:msg/Joints.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__JOINTS__STRUCT_H_
#define QUADRUPED_MUJOCO__MSG__DETAIL__JOINTS__STRUCT_H_

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
// Member 'velocity'
// Member 'effort'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Joints in the package quadruped_mujoco.
/**
  * quadruped_mujoco/msg/Joints.msg
 */
typedef struct quadruped_mujoco__msg__Joints
{
  rosidl_runtime_c__float__Sequence position;
  rosidl_runtime_c__float__Sequence velocity;
  rosidl_runtime_c__float__Sequence effort;
} quadruped_mujoco__msg__Joints;

// Struct for a sequence of quadruped_mujoco__msg__Joints.
typedef struct quadruped_mujoco__msg__Joints__Sequence
{
  quadruped_mujoco__msg__Joints * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadruped_mujoco__msg__Joints__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__JOINTS__STRUCT_H_
