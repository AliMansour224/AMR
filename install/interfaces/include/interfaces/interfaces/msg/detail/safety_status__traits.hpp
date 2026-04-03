// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/safety_status.hpp"


#ifndef INTERFACES__MSG__DETAIL__SAFETY_STATUS__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__SAFETY_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/safety_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SafetyStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: safe_to_move
  {
    out << "safe_to_move: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_to_move, out);
    out << ", ";
  }

  // member: estop_active
  {
    out << "estop_active: ";
    rosidl_generator_traits::value_to_yaml(msg.estop_active, out);
    out << ", ";
  }

  // member: stale_scan
  {
    out << "stale_scan: ";
    rosidl_generator_traits::value_to_yaml(msg.stale_scan, out);
    out << ", ";
  }

  // member: stale_odom
  {
    out << "stale_odom: ";
    rosidl_generator_traits::value_to_yaml(msg.stale_odom, out);
    out << ", ";
  }

  // member: stale_vehicle_status
  {
    out << "stale_vehicle_status: ";
    rosidl_generator_traits::value_to_yaml(msg.stale_vehicle_status, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SafetyStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: safe_to_move
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safe_to_move: ";
    rosidl_generator_traits::value_to_yaml(msg.safe_to_move, out);
    out << "\n";
  }

  // member: estop_active
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estop_active: ";
    rosidl_generator_traits::value_to_yaml(msg.estop_active, out);
    out << "\n";
  }

  // member: stale_scan
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stale_scan: ";
    rosidl_generator_traits::value_to_yaml(msg.stale_scan, out);
    out << "\n";
  }

  // member: stale_odom
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stale_odom: ";
    rosidl_generator_traits::value_to_yaml(msg.stale_odom, out);
    out << "\n";
  }

  // member: stale_vehicle_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stale_vehicle_status: ";
    rosidl_generator_traits::value_to_yaml(msg.stale_vehicle_status, out);
    out << "\n";
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SafetyStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::msg::SafetyStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::SafetyStatus & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::SafetyStatus>()
{
  return "interfaces::msg::SafetyStatus";
}

template<>
inline const char * name<interfaces::msg::SafetyStatus>()
{
  return "interfaces/msg/SafetyStatus";
}

template<>
struct has_fixed_size<interfaces::msg::SafetyStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::msg::SafetyStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::msg::SafetyStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__SAFETY_STATUS__TRAITS_HPP_
