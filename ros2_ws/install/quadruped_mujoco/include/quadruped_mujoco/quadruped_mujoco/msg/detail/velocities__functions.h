// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from quadruped_mujoco:msg/Velocities.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__FUNCTIONS_H_
#define QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "quadruped_mujoco/msg/rosidl_generator_c__visibility_control.h"

#include "quadruped_mujoco/msg/detail/velocities__struct.h"

/// Initialize msg/Velocities message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * quadruped_mujoco__msg__Velocities
 * )) before or use
 * quadruped_mujoco__msg__Velocities__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__Velocities__init(quadruped_mujoco__msg__Velocities * msg);

/// Finalize msg/Velocities message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
void
quadruped_mujoco__msg__Velocities__fini(quadruped_mujoco__msg__Velocities * msg);

/// Create msg/Velocities message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * quadruped_mujoco__msg__Velocities__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
quadruped_mujoco__msg__Velocities *
quadruped_mujoco__msg__Velocities__create();

/// Destroy msg/Velocities message.
/**
 * It calls
 * quadruped_mujoco__msg__Velocities__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
void
quadruped_mujoco__msg__Velocities__destroy(quadruped_mujoco__msg__Velocities * msg);

/// Check for msg/Velocities message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__Velocities__are_equal(const quadruped_mujoco__msg__Velocities * lhs, const quadruped_mujoco__msg__Velocities * rhs);

/// Copy a msg/Velocities message.
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
quadruped_mujoco__msg__Velocities__copy(
  const quadruped_mujoco__msg__Velocities * input,
  quadruped_mujoco__msg__Velocities * output);

/// Initialize array of msg/Velocities messages.
/**
 * It allocates the memory for the number of elements and calls
 * quadruped_mujoco__msg__Velocities__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__Velocities__Sequence__init(quadruped_mujoco__msg__Velocities__Sequence * array, size_t size);

/// Finalize array of msg/Velocities messages.
/**
 * It calls
 * quadruped_mujoco__msg__Velocities__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
void
quadruped_mujoco__msg__Velocities__Sequence__fini(quadruped_mujoco__msg__Velocities__Sequence * array);

/// Create array of msg/Velocities messages.
/**
 * It allocates the memory for the array and calls
 * quadruped_mujoco__msg__Velocities__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
quadruped_mujoco__msg__Velocities__Sequence *
quadruped_mujoco__msg__Velocities__Sequence__create(size_t size);

/// Destroy array of msg/Velocities messages.
/**
 * It calls
 * quadruped_mujoco__msg__Velocities__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
void
quadruped_mujoco__msg__Velocities__Sequence__destroy(quadruped_mujoco__msg__Velocities__Sequence * array);

/// Check for msg/Velocities message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadruped_mujoco
bool
quadruped_mujoco__msg__Velocities__Sequence__are_equal(const quadruped_mujoco__msg__Velocities__Sequence * lhs, const quadruped_mujoco__msg__Velocities__Sequence * rhs);

/// Copy an array of msg/Velocities messages.
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
quadruped_mujoco__msg__Velocities__Sequence__copy(
  const quadruped_mujoco__msg__Velocities__Sequence * input,
  quadruped_mujoco__msg__Velocities__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__FUNCTIONS_H_
