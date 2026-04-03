// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/safety_status.h"


#ifndef INTERFACES__MSG__DETAIL__SAFETY_STATUS__FUNCTIONS_H_
#define INTERFACES__MSG__DETAIL__SAFETY_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "interfaces/msg/detail/safety_status__struct.h"

/// Initialize msg/SafetyStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaces__msg__SafetyStatus
 * )) before or use
 * interfaces__msg__SafetyStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__msg__SafetyStatus__init(interfaces__msg__SafetyStatus * msg);

/// Finalize msg/SafetyStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__msg__SafetyStatus__fini(interfaces__msg__SafetyStatus * msg);

/// Create msg/SafetyStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaces__msg__SafetyStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
interfaces__msg__SafetyStatus *
interfaces__msg__SafetyStatus__create(void);

/// Destroy msg/SafetyStatus message.
/**
 * It calls
 * interfaces__msg__SafetyStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__msg__SafetyStatus__destroy(interfaces__msg__SafetyStatus * msg);

/// Check for msg/SafetyStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__msg__SafetyStatus__are_equal(const interfaces__msg__SafetyStatus * lhs, const interfaces__msg__SafetyStatus * rhs);

/// Copy a msg/SafetyStatus message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__msg__SafetyStatus__copy(
  const interfaces__msg__SafetyStatus * input,
  interfaces__msg__SafetyStatus * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_interfaces
const rosidl_type_hash_t *
interfaces__msg__SafetyStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
interfaces__msg__SafetyStatus__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_interfaces
const rosidl_runtime_c__type_description__TypeSource *
interfaces__msg__SafetyStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
interfaces__msg__SafetyStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/SafetyStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaces__msg__SafetyStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__msg__SafetyStatus__Sequence__init(interfaces__msg__SafetyStatus__Sequence * array, size_t size);

/// Finalize array of msg/SafetyStatus messages.
/**
 * It calls
 * interfaces__msg__SafetyStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__msg__SafetyStatus__Sequence__fini(interfaces__msg__SafetyStatus__Sequence * array);

/// Create array of msg/SafetyStatus messages.
/**
 * It allocates the memory for the array and calls
 * interfaces__msg__SafetyStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
interfaces__msg__SafetyStatus__Sequence *
interfaces__msg__SafetyStatus__Sequence__create(size_t size);

/// Destroy array of msg/SafetyStatus messages.
/**
 * It calls
 * interfaces__msg__SafetyStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__msg__SafetyStatus__Sequence__destroy(interfaces__msg__SafetyStatus__Sequence * array);

/// Check for msg/SafetyStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__msg__SafetyStatus__Sequence__are_equal(const interfaces__msg__SafetyStatus__Sequence * lhs, const interfaces__msg__SafetyStatus__Sequence * rhs);

/// Copy an array of msg/SafetyStatus messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__msg__SafetyStatus__Sequence__copy(
  const interfaces__msg__SafetyStatus__Sequence * input,
  interfaces__msg__SafetyStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__SAFETY_STATUS__FUNCTIONS_H_
