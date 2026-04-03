// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/BridgeStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/bridge_status.hpp"


#ifndef INTERFACES__MSG__DETAIL__BRIDGE_STATUS__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__BRIDGE_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/bridge_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BridgeStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: connected
  {
    out << "connected: ";
    rosidl_generator_traits::value_to_yaml(msg.connected, out);
    out << ", ";
  }

  // member: command_stream_active
  {
    out << "command_stream_active: ";
    rosidl_generator_traits::value_to_yaml(msg.command_stream_active, out);
    out << ", ";
  }

  // member: tx_count
  {
    out << "tx_count: ";
    rosidl_generator_traits::value_to_yaml(msg.tx_count, out);
    out << ", ";
  }

  // member: rx_count
  {
    out << "rx_count: ";
    rosidl_generator_traits::value_to_yaml(msg.rx_count, out);
    out << ", ";
  }

  // member: crc_error_count
  {
    out << "crc_error_count: ";
    rosidl_generator_traits::value_to_yaml(msg.crc_error_count, out);
    out << ", ";
  }

  // member: timeout_count
  {
    out << "timeout_count: ";
    rosidl_generator_traits::value_to_yaml(msg.timeout_count, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BridgeStatus & msg,
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

  // member: connected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "connected: ";
    rosidl_generator_traits::value_to_yaml(msg.connected, out);
    out << "\n";
  }

  // member: command_stream_active
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command_stream_active: ";
    rosidl_generator_traits::value_to_yaml(msg.command_stream_active, out);
    out << "\n";
  }

  // member: tx_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tx_count: ";
    rosidl_generator_traits::value_to_yaml(msg.tx_count, out);
    out << "\n";
  }

  // member: rx_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rx_count: ";
    rosidl_generator_traits::value_to_yaml(msg.rx_count, out);
    out << "\n";
  }

  // member: crc_error_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "crc_error_count: ";
    rosidl_generator_traits::value_to_yaml(msg.crc_error_count, out);
    out << "\n";
  }

  // member: timeout_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timeout_count: ";
    rosidl_generator_traits::value_to_yaml(msg.timeout_count, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BridgeStatus & msg, bool use_flow_style = false)
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
  const interfaces::msg::BridgeStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::BridgeStatus & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::BridgeStatus>()
{
  return "interfaces::msg::BridgeStatus";
}

template<>
inline const char * name<interfaces::msg::BridgeStatus>()
{
  return "interfaces/msg/BridgeStatus";
}

template<>
struct has_fixed_size<interfaces::msg::BridgeStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::msg::BridgeStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::msg::BridgeStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__BRIDGE_STATUS__TRAITS_HPP_
