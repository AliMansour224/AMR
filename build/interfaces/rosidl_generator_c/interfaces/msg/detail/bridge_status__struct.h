// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/BridgeStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/bridge_status.h"


#ifndef INTERFACES__MSG__DETAIL__BRIDGE_STATUS__STRUCT_H_
#define INTERFACES__MSG__DETAIL__BRIDGE_STATUS__STRUCT_H_

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
// Member 'state'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BridgeStatus in the package interfaces.
typedef struct interfaces__msg__BridgeStatus
{
  std_msgs__msg__Header header;
  bool connected;
  bool command_stream_active;
  uint32_t tx_count;
  uint32_t rx_count;
  uint32_t crc_error_count;
  uint32_t timeout_count;
  rosidl_runtime_c__String state;
} interfaces__msg__BridgeStatus;

// Struct for a sequence of interfaces__msg__BridgeStatus.
typedef struct interfaces__msg__BridgeStatus__Sequence
{
  interfaces__msg__BridgeStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__BridgeStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__BRIDGE_STATUS__STRUCT_H_
