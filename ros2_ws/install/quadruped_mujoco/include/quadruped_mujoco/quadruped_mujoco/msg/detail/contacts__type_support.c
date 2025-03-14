// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from quadruped_mujoco:msg/Contacts.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "quadruped_mujoco/msg/detail/contacts__rosidl_typesupport_introspection_c.h"
#include "quadruped_mujoco/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "quadruped_mujoco/msg/detail/contacts__functions.h"
#include "quadruped_mujoco/msg/detail/contacts__struct.h"


// Include directives for member types
// Member `contacts`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  quadruped_mujoco__msg__Contacts__init(message_memory);
}

void quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_fini_function(void * message_memory)
{
  quadruped_mujoco__msg__Contacts__fini(message_memory);
}

size_t quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__size_function__Contacts__contacts(
  const void * untyped_member)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return member->size;
}

const void * quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__get_const_function__Contacts__contacts(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void * quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__get_function__Contacts__contacts(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__fetch_function__Contacts__contacts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__get_const_function__Contacts__contacts(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__assign_function__Contacts__contacts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__get_function__Contacts__contacts(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

bool quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__resize_function__Contacts__contacts(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  rosidl_runtime_c__boolean__Sequence__fini(member);
  return rosidl_runtime_c__boolean__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_message_member_array[1] = {
  {
    "contacts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(quadruped_mujoco__msg__Contacts, contacts),  // bytes offset in struct
    NULL,  // default value
    quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__size_function__Contacts__contacts,  // size() function pointer
    quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__get_const_function__Contacts__contacts,  // get_const(index) function pointer
    quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__get_function__Contacts__contacts,  // get(index) function pointer
    quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__fetch_function__Contacts__contacts,  // fetch(index, &value) function pointer
    quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__assign_function__Contacts__contacts,  // assign(index, value) function pointer
    quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__resize_function__Contacts__contacts  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_message_members = {
  "quadruped_mujoco__msg",  // message namespace
  "Contacts",  // message name
  1,  // number of fields
  sizeof(quadruped_mujoco__msg__Contacts),
  quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_message_member_array,  // message members
  quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_init_function,  // function to initialize message memory (memory has to be allocated)
  quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_message_type_support_handle = {
  0,
  &quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_quadruped_mujoco
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, quadruped_mujoco, msg, Contacts)() {
  if (!quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_message_type_support_handle.typesupport_identifier) {
    quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &quadruped_mujoco__msg__Contacts__rosidl_typesupport_introspection_c__Contacts_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
