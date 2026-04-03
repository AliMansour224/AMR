// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/VehicleStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/vehicle_status.h"


#ifndef INTERFACES__MSG__DETAIL__VEHICLE_STATUS__STRUCT_H_
#define INTERFACES__MSG__DETAIL__VEHICLE_STATUS__STRUCT_H_

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
// Member 'mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/VehicleStatus in the package interfaces.
typedef struct interfaces__msg__VehicleStatus
{
  std_msgs__msg__Header header;
  bool enabled;
  bool estop_active;
  float speed_mps;
  float yaw_rate_rps;
  uint8_t fault_code;
  rosidl_runtime_c__String mode;
} interfaces__msg__VehicleStatus;

// Struct for a sequence of interfaces__msg__VehicleStatus.
typedef struct interfaces__msg__VehicleStatus__Sequence
{
  interfaces__msg__VehicleStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__VehicleStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__VEHICLE_STATUS__STRUCT_H_
