// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadruped_mujoco:msg/Contacts.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS__STRUCT_H_
#define QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'contacts'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Contacts in the package quadruped_mujoco.
/**
  * quadruped_mujoco/msg/Contacts.msg
 */
typedef struct quadruped_mujoco__msg__Contacts
{
  rosidl_runtime_c__boolean__Sequence contacts;
} quadruped_mujoco__msg__Contacts;

// Struct for a sequence of quadruped_mujoco__msg__Contacts.
typedef struct quadruped_mujoco__msg__Contacts__Sequence
{
  quadruped_mujoco__msg__Contacts * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadruped_mujoco__msg__Contacts__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS__STRUCT_H_
