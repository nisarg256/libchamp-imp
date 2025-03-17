// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from quadruped_mujoco:msg/Velocities.idl
// generated code does not contain a copyright notice
#include "quadruped_mujoco/msg/detail/velocities__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `linear`
// Member `angular`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
quadruped_mujoco__msg__Velocities__init(quadruped_mujoco__msg__Velocities * msg)
{
  if (!msg) {
    return false;
  }
  // linear
  if (!geometry_msgs__msg__Vector3__init(&msg->linear)) {
    quadruped_mujoco__msg__Velocities__fini(msg);
    return false;
  }
  // angular
  if (!geometry_msgs__msg__Vector3__init(&msg->angular)) {
    quadruped_mujoco__msg__Velocities__fini(msg);
    return false;
  }
  return true;
}

void
quadruped_mujoco__msg__Velocities__fini(quadruped_mujoco__msg__Velocities * msg)
{
  if (!msg) {
    return;
  }
  // linear
  geometry_msgs__msg__Vector3__fini(&msg->linear);
  // angular
  geometry_msgs__msg__Vector3__fini(&msg->angular);
}

bool
quadruped_mujoco__msg__Velocities__are_equal(const quadruped_mujoco__msg__Velocities * lhs, const quadruped_mujoco__msg__Velocities * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // linear
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->linear), &(rhs->linear)))
  {
    return false;
  }
  // angular
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->angular), &(rhs->angular)))
  {
    return false;
  }
  return true;
}

bool
quadruped_mujoco__msg__Velocities__copy(
  const quadruped_mujoco__msg__Velocities * input,
  quadruped_mujoco__msg__Velocities * output)
{
  if (!input || !output) {
    return false;
  }
  // linear
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->linear), &(output->linear)))
  {
    return false;
  }
  // angular
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->angular), &(output->angular)))
  {
    return false;
  }
  return true;
}

quadruped_mujoco__msg__Velocities *
quadruped_mujoco__msg__Velocities__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadruped_mujoco__msg__Velocities * msg = (quadruped_mujoco__msg__Velocities *)allocator.allocate(sizeof(quadruped_mujoco__msg__Velocities), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(quadruped_mujoco__msg__Velocities));
  bool success = quadruped_mujoco__msg__Velocities__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
quadruped_mujoco__msg__Velocities__destroy(quadruped_mujoco__msg__Velocities * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    quadruped_mujoco__msg__Velocities__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
quadruped_mujoco__msg__Velocities__Sequence__init(quadruped_mujoco__msg__Velocities__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadruped_mujoco__msg__Velocities * data = NULL;

  if (size) {
    data = (quadruped_mujoco__msg__Velocities *)allocator.zero_allocate(size, sizeof(quadruped_mujoco__msg__Velocities), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = quadruped_mujoco__msg__Velocities__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        quadruped_mujoco__msg__Velocities__fini(&data[i - 1]);
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
quadruped_mujoco__msg__Velocities__Sequence__fini(quadruped_mujoco__msg__Velocities__Sequence * array)
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
      quadruped_mujoco__msg__Velocities__fini(&array->data[i]);
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

quadruped_mujoco__msg__Velocities__Sequence *
quadruped_mujoco__msg__Velocities__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadruped_mujoco__msg__Velocities__Sequence * array = (quadruped_mujoco__msg__Velocities__Sequence *)allocator.allocate(sizeof(quadruped_mujoco__msg__Velocities__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = quadruped_mujoco__msg__Velocities__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
quadruped_mujoco__msg__Velocities__Sequence__destroy(quadruped_mujoco__msg__Velocities__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    quadruped_mujoco__msg__Velocities__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
quadruped_mujoco__msg__Velocities__Sequence__are_equal(const quadruped_mujoco__msg__Velocities__Sequence * lhs, const quadruped_mujoco__msg__Velocities__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!quadruped_mujoco__msg__Velocities__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
quadruped_mujoco__msg__Velocities__Sequence__copy(
  const quadruped_mujoco__msg__Velocities__Sequence * input,
  quadruped_mujoco__msg__Velocities__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(quadruped_mujoco__msg__Velocities);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    quadruped_mujoco__msg__Velocities * data =
      (quadruped_mujoco__msg__Velocities *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!quadruped_mujoco__msg__Velocities__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          quadruped_mujoco__msg__Velocities__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!quadruped_mujoco__msg__Velocities__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
