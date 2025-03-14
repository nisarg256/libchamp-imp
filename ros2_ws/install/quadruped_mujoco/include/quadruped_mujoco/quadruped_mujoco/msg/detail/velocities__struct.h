// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadruped_mujoco:msg/Velocities.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__STRUCT_H_
#define QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Velocities in the package quadruped_mujoco.
/**
  * quadruped_mujoco/msg/Velocities.msg
 */
typedef struct quadruped_mujoco__msg__Velocities
{
  float linear_x;
  float linear_y;
  float angular_z;
} quadruped_mujoco__msg__Velocities;

// Struct for a sequence of quadruped_mujoco__msg__Velocities.
typedef struct quadruped_mujoco__msg__Velocities__Sequence
{
  quadruped_mujoco__msg__Velocities * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadruped_mujoco__msg__Velocities__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__STRUCT_H_
