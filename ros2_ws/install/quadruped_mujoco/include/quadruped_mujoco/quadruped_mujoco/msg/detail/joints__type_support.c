// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from quadruped_mujoco:msg/Joints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "quadruped_mujoco/msg/detail/joints__rosidl_typesupport_introspection_c.h"
#include "quadruped_mujoco/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "quadruped_mujoco/msg/detail/joints__functions.h"
#include "quadruped_mujoco/msg/detail/joints__struct.h"


// Include directives for member types
// Member `position`
// Member `velocity`
// Member `effort`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  quadruped_mujoco__msg__Joints__init(message_memory);
}

void quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_fini_function(void * message_memory)
{
  quadruped_mujoco__msg__Joints__fini(message_memory);
}

size_t quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__size_function__Joints__position(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_const_function__Joints__position(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_function__Joints__position(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__fetch_function__Joints__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_const_function__Joints__position(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__assign_function__Joints__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_function__Joints__position(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__resize_function__Joints__position(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__size_function__Joints__velocity(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_const_function__Joints__velocity(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_function__Joints__velocity(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__fetch_function__Joints__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_const_function__Joints__velocity(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__assign_function__Joints__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_function__Joints__velocity(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__resize_function__Joints__velocity(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__size_function__Joints__effort(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_const_function__Joints__effort(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_function__Joints__effort(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__fetch_function__Joints__effort(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_const_function__Joints__effort(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__assign_function__Joints__effort(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_function__Joints__effort(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__resize_function__Joints__effort(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_message_member_array[3] = {
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(quadruped_mujoco__msg__Joints, position),  // bytes offset in struct
    NULL,  // default value
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__size_function__Joints__position,  // size() function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_const_function__Joints__position,  // get_const(index) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_function__Joints__position,  // get(index) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__fetch_function__Joints__position,  // fetch(index, &value) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__assign_function__Joints__position,  // assign(index, value) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__resize_function__Joints__position  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(quadruped_mujoco__msg__Joints, velocity),  // bytes offset in struct
    NULL,  // default value
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__size_function__Joints__velocity,  // size() function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_const_function__Joints__velocity,  // get_const(index) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_function__Joints__velocity,  // get(index) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__fetch_function__Joints__velocity,  // fetch(index, &value) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__assign_function__Joints__velocity,  // assign(index, value) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__resize_function__Joints__velocity  // resize(index) function pointer
  },
  {
    "effort",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(quadruped_mujoco__msg__Joints, effort),  // bytes offset in struct
    NULL,  // default value
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__size_function__Joints__effort,  // size() function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_const_function__Joints__effort,  // get_const(index) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__get_function__Joints__effort,  // get(index) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__fetch_function__Joints__effort,  // fetch(index, &value) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__assign_function__Joints__effort,  // assign(index, value) function pointer
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__resize_function__Joints__effort  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_message_members = {
  "quadruped_mujoco__msg",  // message namespace
  "Joints",  // message name
  3,  // number of fields
  sizeof(quadruped_mujoco__msg__Joints),
  quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_message_member_array,  // message members
  quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_init_function,  // function to initialize message memory (memory has to be allocated)
  quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_message_type_support_handle = {
  0,
  &quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_quadruped_mujoco
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, quadruped_mujoco, msg, Joints)() {
  if (!quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_message_type_support_handle.typesupport_identifier) {
    quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &quadruped_mujoco__msg__Joints__rosidl_typesupport_introspection_c__Joints_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
