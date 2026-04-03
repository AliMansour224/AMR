// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from autonomy_msgs:msg/Detection.idl
// generated code does not contain a copyright notice
#ifndef AUTONOMY_MSGS__MSG__DETAIL__DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define AUTONOMY_MSGS__MSG__DETAIL__DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "autonomy_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "autonomy_msgs/msg/detail/detection__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autonomy_msgs
bool cdr_serialize_autonomy_msgs__msg__Detection(
  const autonomy_msgs__msg__Detection * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autonomy_msgs
bool cdr_deserialize_autonomy_msgs__msg__Detection(
  eprosima::fastcdr::Cdr &,
  autonomy_msgs__msg__Detection * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autonomy_msgs
size_t get_serialized_size_autonomy_msgs__msg__Detection(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autonomy_msgs
size_t max_serialized_size_autonomy_msgs__msg__Detection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autonomy_msgs
bool cdr_serialize_key_autonomy_msgs__msg__Detection(
  const autonomy_msgs__msg__Detection * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autonomy_msgs
size_t get_serialized_size_key_autonomy_msgs__msg__Detection(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autonomy_msgs
size_t max_serialized_size_key_autonomy_msgs__msg__Detection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autonomy_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, autonomy_msgs, msg, Detection)();

#ifdef __cplusplus
}
#endif

#endif  // AUTONOMY_MSGS__MSG__DETAIL__DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
