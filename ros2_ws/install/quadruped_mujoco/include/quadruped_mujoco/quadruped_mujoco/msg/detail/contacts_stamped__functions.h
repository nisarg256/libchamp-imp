// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from quadruped_mujoco:msg/ContactsStamped.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__FUNCTIONS_H_
#define QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "quadruped_mujoco/msg/rosidl_generator_c__visibility_control.h"

#include "quadruped_mujoco/msg/detail/contacts_stamped__struct.h"

/// Initialize msg/ContactsStamped message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * quadruped_mujoco__msg__ContactsStamped
 * )) before or use
 * quadruped_mujoco__msg__ContactsStamped__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__ContactsStamped__init(quadruped_mujoco__msg__ContactsStamped * msg);

/// Finalize msg/ContactsStamped message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
void
quadruped_mujoco__msg__ContactsStamped__fini(quadruped_mujoco__msg__ContactsStamped * msg);

/// Create msg/ContactsStamped message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * quadruped_mujoco__msg__ContactsStamped__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
quadruped_mujoco__msg__ContactsStamped *
quadruped_mujoco__msg__ContactsStamped__create();

/// Destroy msg/ContactsStamped message.
/**
 * It calls
 * quadruped_mujoco__msg__ContactsStamped__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
void
quadruped_mujoco__msg__ContactsStamped__destroy(quadruped_mujoco__msg__ContactsStamped * msg);

/// Check for msg/ContactsStamped message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__ContactsStamped__are_equal(const quadruped_mujoco__msg__ContactsStamped * lhs, const quadruped_mujoco__msg__ContactsStamped * rhs);

/// Copy a msg/ContactsStamped message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__ContactsStamped__copy(
  const quadruped_mujoco__msg__ContactsStamped * input,
  quadruped_mujoco__msg__ContactsStamped * output);

/// Initialize array of msg/ContactsStamped messages.
/**
 * It allocates the memory for the number of elements and calls
 * quadruped_mujoco__msg__ContactsStamped__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__ContactsStamped__Sequence__init(quadruped_mujoco__msg__ContactsStamped__Sequence * array, size_t size);

/// Finalize array of msg/ContactsStamped messages.
/**
 * It calls
 * quadruped_mujoco__msg__ContactsStamped__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
void
quadruped_mujoco__msg__ContactsStamped__Sequence__fini(quadruped_mujoco__msg__ContactsStamped__Sequence * array);

/// Create array of msg/ContactsStamped messages.
/**
 * It allocates the memory for the array and calls
 * quadruped_mujoco__msg__ContactsStamped__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
quadruped_mujoco__msg__ContactsStamped__Sequence *
quadruped_mujoco__msg__ContactsStamped__Sequence__create(size_t size);

/// Destroy array of msg/ContactsStamped messages.
/**
 * It calls
 * quadruped_mujoco__msg__ContactsStamped__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
void
quadruped_mujoco__msg__ContactsStamped__Sequence__destroy(quadruped_mujoco__msg__ContactsStamped__Sequence * array);

/// Check for msg/ContactsStamped message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__ContactsStamped__Sequence__are_equal(const quadruped_mujoco__msg__ContactsStamped__Sequence * lhs, const quadruped_mujoco__msg__ContactsStamped__Sequence * rhs);

/// Copy an array of msg/ContactsStamped messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__ContactsStamped__Sequence__copy(
  const quadruped_mujoco__msg__ContactsStamped__Sequence * input,
  quadruped_mujoco__msg__ContactsStamped__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__FUNCTIONS_H_
