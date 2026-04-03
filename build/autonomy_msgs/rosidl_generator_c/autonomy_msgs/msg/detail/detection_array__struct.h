// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autonomy_msgs:msg/DetectionArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "autonomy_msgs/msg/detection_array.h"


#ifndef AUTONOMY_MSGS__MSG__DETAIL__DETECTION_ARRAY__STRUCT_H_
#define AUTONOMY_MSGS__MSG__DETAIL__DETECTION_ARRAY__STRUCT_H_

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
// Member 'detections'
#include "autonomy_msgs/msg/detail/detection__struct.h"

/// Struct defined in msg/DetectionArray in the package autonomy_msgs.
typedef struct autonomy_msgs__msg__DetectionArray
{
  std_msgs__msg__Header header;
  autonomy_msgs__msg__Detection__Sequence detections;
} autonomy_msgs__msg__DetectionArray;

// Struct for a sequence of autonomy_msgs__msg__DetectionArray.
typedef struct autonomy_msgs__msg__DetectionArray__Sequence
{
  autonomy_msgs__msg__DetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autonomy_msgs__msg__DetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTONOMY_MSGS__MSG__DETAIL__DETECTION_ARRAY__STRUCT_H_
