// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from quadruped_mujoco:msg/Joints.idl
// generated code does not contain a copyright notice
#include "quadruped_mujoco/msg/detail/joints__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `position`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
quadruped_mujoco__msg__Joints__init(quadruped_mujoco__msg__Joints * msg)
{
  if (!msg) {
    return false;
  }
  // position
  if (!rosidl_runtime_c__float__Sequence__init(&msg->position, 0)) {
    quadruped_mujoco__msg__Joints__fini(msg);
    return false;
  }
  return true;
}

void
quadruped_mujoco__msg__Joints__fini(quadruped_mujoco__msg__Joints * msg)
{
  if (!msg) {
    return;
  }
  // position
  rosidl_runtime_c__float__Sequence__fini(&msg->position);
}

bool
quadruped_mujoco__msg__Joints__are_equal(const quadruped_mujoco__msg__Joints * lhs, const quadruped_mujoco__msg__Joints * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  return true;
}

bool
quadruped_mujoco__msg__Joints__copy(
  const quadruped_mujoco__msg__Joints * input,
  quadruped_mujoco__msg__Joints * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  return true;
}

quadruped_mujoco__msg__Joints *
quadruped_mujoco__msg__Joints__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadruped_mujoco__msg__Joints * msg = (quadruped_mujoco__msg__Joints *)allocator.allocate(sizeof(quadruped_mujoco__msg__Joints), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(quadruped_mujoco__msg__Joints));
  bool success = quadruped_mujoco__msg__Joints__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
quadruped_mujoco__msg__Joints__destroy(quadruped_mujoco__msg__Joints * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    quadruped_mujoco__msg__Joints__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
quadruped_mujoco__msg__Joints__Sequence__init(quadruped_mujoco__msg__Joints__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadruped_mujoco__msg__Joints * data = NULL;

  if (size) {
    data = (quadruped_mujoco__msg__Joints *)allocator.zero_allocate(size, sizeof(quadruped_mujoco__msg__Joints), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = quadruped_mujoco__msg__Joints__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        quadruped_mujoco__msg__Joints__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
quadruped_mujoco__msg__Joints__Sequence__fini(quadruped_mujoco__msg__Joints__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      quadruped_mujoco__msg__Joints__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

quadruped_mujoco__msg__Joints__Sequence *
quadruped_mujoco__msg__Joints__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadruped_mujoco__msg__Joints__Sequence * array = (quadruped_mujoco__msg__Joints__Sequence *)allocator.allocate(sizeof(quadruped_mujoco__msg__Joints__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = quadruped_mujoco__msg__Joints__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
quadruped_mujoco__msg__Joints__Sequence__destroy(quadruped_mujoco__msg__Joints__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    quadruped_mujoco__msg__Joints__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
quadruped_mujoco__msg__Joints__Sequence__are_equal(const quadruped_mujoco__msg__Joints__Sequence * lhs, const quadruped_mujoco__msg__Joints__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!quadruped_mujoco__msg__Joints__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
quadruped_mujoco__msg__Joints__Sequence__copy(
  const quadruped_mujoco__msg__Joints__Sequence * input,
  quadruped_mujoco__msg__Joints__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(quadruped_mujoco__msg__Joints);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    quadruped_mujoco__msg__Joints * data =
      (quadruped_mujoco__msg__Joints *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!quadruped_mujoco__msg__Joints__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          quadruped_mujoco__msg__Joints__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!quadruped_mujoco__msg__Joints__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
