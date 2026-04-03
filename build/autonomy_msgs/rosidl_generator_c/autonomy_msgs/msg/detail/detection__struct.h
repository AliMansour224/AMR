// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autonomy_msgs:msg/Detection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "autonomy_msgs/msg/detection.h"


#ifndef AUTONOMY_MSGS__MSG__DETAIL__DETECTION__STRUCT_H_
#define AUTONOMY_MSGS__MSG__DETAIL__DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'label'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Detection in the package autonomy_msgs.
typedef struct autonomy_msgs__msg__Detection
{
  geometry_msgs__msg__Point position;
  float distance;
  float angle;
  float size_x;
  float size_y;
  rosidl_runtime_c__String label;
  float confidence;
} autonomy_msgs__msg__Detection;

// Struct for a sequence of autonomy_msgs__msg__Detection.
typedef struct autonomy_msgs__msg__Detection__Sequence
{
  autonomy_msgs__msg__Detection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autonomy_msgs__msg__Detection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTONOMY_MSGS__MSG__DETAIL__DETECTION__STRUCT_H_
