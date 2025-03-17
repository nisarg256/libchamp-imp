// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from quadruped_mujoco:msg/ContactsStamped.idl
// generated code does not contain a copyright notice
#include "quadruped_mujoco/msg/detail/contacts_stamped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `contacts`
#include "quadruped_mujoco/msg/detail/contacts__functions.h"

bool
quadruped_mujoco__msg__ContactsStamped__init(quadruped_mujoco__msg__ContactsStamped * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    quadruped_mujoco__msg__ContactsStamped__fini(msg);
    return false;
  }
  // contacts
  if (!quadruped_mujoco__msg__Contacts__init(&msg->contacts)) {
    quadruped_mujoco__msg__ContactsStamped__fini(msg);
    return false;
  }
  return true;
}

void
quadruped_mujoco__msg__ContactsStamped__fini(quadruped_mujoco__msg__ContactsStamped * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // contacts
  quadruped_mujoco__msg__Contacts__fini(&msg->contacts);
}

bool
quadruped_mujoco__msg__ContactsStamped__are_equal(const quadruped_mujoco__msg__ContactsStamped * lhs, const quadruped_mujoco__msg__ContactsStamped * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // contacts
  if (!quadruped_mujoco__msg__Contacts__are_equal(
      &(lhs->contacts), &(rhs->contacts)))
  {
    return false;
  }
  return true;
}

bool
quadruped_mujoco__msg__ContactsStamped__copy(
  const quadruped_mujoco__msg__ContactsStamped * input,
  quadruped_mujoco__msg__ContactsStamped * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // contacts
  if (!quadruped_mujoco__msg__Contacts__copy(
      &(input->contacts), &(output->contacts)))
  {
    return false;
  }
  return true;
}

quadruped_mujoco__msg__ContactsStamped *
quadruped_mujoco__msg__ContactsStamped__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadruped_mujoco__msg__ContactsStamped * msg = (quadruped_mujoco__msg__ContactsStamped *)allocator.allocate(sizeof(quadruped_mujoco__msg__ContactsStamped), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(quadruped_mujoco__msg__ContactsStamped));
  bool success = quadruped_mujoco__msg__ContactsStamped__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
quadruped_mujoco__msg__ContactsStamped__destroy(quadruped_mujoco__msg__ContactsStamped * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    quadruped_mujoco__msg__ContactsStamped__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
quadruped_mujoco__msg__ContactsStamped__Sequence__init(quadruped_mujoco__msg__ContactsStamped__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadruped_mujoco__msg__ContactsStamped * data = NULL;

  if (size) {
    data = (quadruped_mujoco__msg__ContactsStamped *)allocator.zero_allocate(size, sizeof(quadruped_mujoco__msg__ContactsStamped), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = quadruped_mujoco__msg__ContactsStamped__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        quadruped_mujoco__msg__ContactsStamped__fini(&data[i - 1]);
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
quadruped_mujoco__msg__ContactsStamped__Sequence__fini(quadruped_mujoco__msg__ContactsStamped__Sequence * array)
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
      quadruped_mujoco__msg__ContactsStamped__fini(&array->data[i]);
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

quadruped_mujoco__msg__ContactsStamped__Sequence *
quadruped_mujoco__msg__ContactsStamped__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadruped_mujoco__msg__ContactsStamped__Sequence * array = (quadruped_mujoco__msg__ContactsStamped__Sequence *)allocator.allocate(sizeof(quadruped_mujoco__msg__ContactsStamped__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = quadruped_mujoco__msg__ContactsStamped__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
quadruped_mujoco__msg__ContactsStamped__Sequence__destroy(quadruped_mujoco__msg__ContactsStamped__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    quadruped_mujoco__msg__ContactsStamped__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
quadruped_mujoco__msg__ContactsStamped__Sequence__are_equal(const quadruped_mujoco__msg__ContactsStamped__Sequence * lhs, const quadruped_mujoco__msg__ContactsStamped__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!quadruped_mujoco__msg__ContactsStamped__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
quadruped_mujoco__msg__ContactsStamped__Sequence__copy(
  const quadruped_mujoco__msg__ContactsStamped__Sequence * input,
  quadruped_mujoco__msg__ContactsStamped__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(quadruped_mujoco__msg__ContactsStamped);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    quadruped_mujoco__msg__ContactsStamped * data =
      (quadruped_mujoco__msg__ContactsStamped *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!quadruped_mujoco__msg__ContactsStamped__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          quadruped_mujoco__msg__ContactsStamped__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!quadruped_mujoco__msg__ContactsStamped__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
