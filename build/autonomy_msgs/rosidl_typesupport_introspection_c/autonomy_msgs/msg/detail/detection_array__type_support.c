// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from autonomy_msgs:msg/DetectionArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "autonomy_msgs/msg/detail/detection_array__rosidl_typesupport_introspection_c.h"
#include "autonomy_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "autonomy_msgs/msg/detail/detection_array__functions.h"
#include "autonomy_msgs/msg/detail/detection_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `detections`
#include "autonomy_msgs/msg/detection.h"
// Member `detections`
#include "autonomy_msgs/msg/detail/detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  autonomy_msgs__msg__DetectionArray__init(message_memory);
}

void autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_fini_function(void * message_memory)
{
  autonomy_msgs__msg__DetectionArray__fini(message_memory);
}

size_t autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__size_function__DetectionArray__detections(
  const void * untyped_member)
{
  const autonomy_msgs__msg__Detection__Sequence * member =
    (const autonomy_msgs__msg__Detection__Sequence *)(untyped_member);
  return member->size;
}

const void * autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__get_const_function__DetectionArray__detections(
  const void * untyped_member, size_t index)
{
  const autonomy_msgs__msg__Detection__Sequence * member =
    (const autonomy_msgs__msg__Detection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__get_function__DetectionArray__detections(
  void * untyped_member, size_t index)
{
  autonomy_msgs__msg__Detection__Sequence * member =
    (autonomy_msgs__msg__Detection__Sequence *)(untyped_member);
  return &member->data[index];
}

void autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__fetch_function__DetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const autonomy_msgs__msg__Detection * item =
    ((const autonomy_msgs__msg__Detection *)
    autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__get_const_function__DetectionArray__detections(untyped_member, index));
  autonomy_msgs__msg__Detection * value =
    (autonomy_msgs__msg__Detection *)(untyped_value);
  *value = *item;
}

void autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__assign_function__DetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  autonomy_msgs__msg__Detection * item =
    ((autonomy_msgs__msg__Detection *)
    autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__get_function__DetectionArray__detections(untyped_member, index));
  const autonomy_msgs__msg__Detection * value =
    (const autonomy_msgs__msg__Detection *)(untyped_value);
  *item = *value;
}

bool autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__resize_function__DetectionArray__detections(
  void * untyped_member, size_t size)
{
  autonomy_msgs__msg__Detection__Sequence * member =
    (autonomy_msgs__msg__Detection__Sequence *)(untyped_member);
  autonomy_msgs__msg__Detection__Sequence__fini(member);
  return autonomy_msgs__msg__Detection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autonomy_msgs__msg__DetectionArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autonomy_msgs__msg__DetectionArray, detections),  // bytes offset in struct
    NULL,  // default value
    autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__size_function__DetectionArray__detections,  // size() function pointer
    autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__get_const_function__DetectionArray__detections,  // get_const(index) function pointer
    autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__get_function__DetectionArray__detections,  // get(index) function pointer
    autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__fetch_function__DetectionArray__detections,  // fetch(index, &value) function pointer
    autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__assign_function__DetectionArray__detections,  // assign(index, value) function pointer
    autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__resize_function__DetectionArray__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_members = {
  "autonomy_msgs__msg",  // message namespace
  "DetectionArray",  // message name
  2,  // number of fields
  sizeof(autonomy_msgs__msg__DetectionArray),
  false,  // has_any_key_member_
  autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_member_array,  // message members
  autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_type_support_handle = {
  0,
  &autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_members,
  get_message_typesupport_handle_function,
  &autonomy_msgs__msg__DetectionArray__get_type_hash,
  &autonomy_msgs__msg__DetectionArray__get_type_description,
  &autonomy_msgs__msg__DetectionArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_autonomy_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, autonomy_msgs, msg, DetectionArray)() {
  autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, autonomy_msgs, msg, Detection)();
  if (!autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_type_support_handle.typesupport_identifier) {
    autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &autonomy_msgs__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
