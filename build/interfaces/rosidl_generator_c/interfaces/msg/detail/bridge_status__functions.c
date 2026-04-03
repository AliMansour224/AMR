// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/BridgeStatus.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/bridge_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `state`
#include "rosidl_runtime_c/string_functions.h"

bool
interfaces__msg__BridgeStatus__init(interfaces__msg__BridgeStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    interfaces__msg__BridgeStatus__fini(msg);
    return false;
  }
  // connected
  // command_stream_active
  // tx_count
  // rx_count
  // crc_error_count
  // timeout_count
  // state
  if (!rosidl_runtime_c__String__init(&msg->state)) {
    interfaces__msg__BridgeStatus__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__msg__BridgeStatus__fini(interfaces__msg__BridgeStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // connected
  // command_stream_active
  // tx_count
  // rx_count
  // crc_error_count
  // timeout_count
  // state
  rosidl_runtime_c__String__fini(&msg->state);
}

bool
interfaces__msg__BridgeStatus__are_equal(const interfaces__msg__BridgeStatus * lhs, const interfaces__msg__BridgeStatus * rhs)
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
  // connected
  if (lhs->connected != rhs->connected) {
    return false;
  }
  // command_stream_active
  if (lhs->command_stream_active != rhs->command_stream_active) {
    return false;
  }
  // tx_count
  if (lhs->tx_count != rhs->tx_count) {
    return false;
  }
  // rx_count
  if (lhs->rx_count != rhs->rx_count) {
    return false;
  }
  // crc_error_count
  if (lhs->crc_error_count != rhs->crc_error_count) {
    return false;
  }
  // timeout_count
  if (lhs->timeout_count != rhs->timeout_count) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  return true;
}

bool
interfaces__msg__BridgeStatus__copy(
  const interfaces__msg__BridgeStatus * input,
  interfaces__msg__BridgeStatus * output)
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
  // connected
  output->connected = input->connected;
  // command_stream_active
  output->command_stream_active = input->command_stream_active;
  // tx_count
  output->tx_count = input->tx_count;
  // rx_count
  output->rx_count = input->rx_count;
  // crc_error_count
  output->crc_error_count = input->crc_error_count;
  // timeout_count
  output->timeout_count = input->timeout_count;
  // state
  if (!rosidl_runtime_c__String__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  return true;
}

interfaces__msg__BridgeStatus *
interfaces__msg__BridgeStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__BridgeStatus * msg = (interfaces__msg__BridgeStatus *)allocator.allocate(sizeof(interfaces__msg__BridgeStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__BridgeStatus));
  bool success = interfaces__msg__BridgeStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__BridgeStatus__destroy(interfaces__msg__BridgeStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__msg__BridgeStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__msg__BridgeStatus__Sequence__init(interfaces__msg__BridgeStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__BridgeStatus * data = NULL;

  if (size) {
    data = (interfaces__msg__BridgeStatus *)allocator.zero_allocate(size, sizeof(interfaces__msg__BridgeStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__BridgeStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__BridgeStatus__fini(&data[i - 1]);
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
interfaces__msg__BridgeStatus__Sequence__fini(interfaces__msg__BridgeStatus__Sequence * array)
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
      interfaces__msg__BridgeStatus__fini(&array->data[i]);
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

interfaces__msg__BridgeStatus__Sequence *
interfaces__msg__BridgeStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__BridgeStatus__Sequence * array = (interfaces__msg__BridgeStatus__Sequence *)allocator.allocate(sizeof(interfaces__msg__BridgeStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__BridgeStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__msg__BridgeStatus__Sequence__destroy(interfaces__msg__BridgeStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__msg__BridgeStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__msg__BridgeStatus__Sequence__are_equal(const interfaces__msg__BridgeStatus__Sequence * lhs, const interfaces__msg__BridgeStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__BridgeStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__BridgeStatus__Sequence__copy(
  const interfaces__msg__BridgeStatus__Sequence * input,
  interfaces__msg__BridgeStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__BridgeStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__msg__BridgeStatus * data =
      (interfaces__msg__BridgeStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__BridgeStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__msg__BridgeStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__msg__BridgeStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
