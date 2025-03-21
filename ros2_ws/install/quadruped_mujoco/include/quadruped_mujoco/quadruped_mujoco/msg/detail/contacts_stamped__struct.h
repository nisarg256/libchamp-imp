// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadruped_mujoco:msg/ContactsStamped.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__STRUCT_H_
#define QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'contacts'
#include "quadruped_mujoco/msg/detail/contacts__struct.h"

/// Struct defined in msg/ContactsStamped in the package quadruped_mujoco.
typedef struct quadruped_mujoco__msg__ContactsStamped
{
  std_msgs__msg__Header header;
  quadruped_mujoco__msg__Contacts contacts;
} quadruped_mujoco__msg__ContactsStamped;

// Struct for a sequence of quadruped_mujoco__msg__ContactsStamped.
typedef struct quadruped_mujoco__msg__ContactsStamped__Sequence
{
  quadruped_mujoco__msg__ContactsStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadruped_mujoco__msg__ContactsStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__STRUCT_H_
