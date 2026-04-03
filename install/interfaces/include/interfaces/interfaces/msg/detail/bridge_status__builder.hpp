// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/BridgeStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/bridge_status.hpp"


#ifndef INTERFACES__MSG__DETAIL__BRIDGE_STATUS__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__BRIDGE_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/bridge_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_BridgeStatus_state
{
public:
  explicit Init_BridgeStatus_state(::interfaces::msg::BridgeStatus & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::BridgeStatus state(::interfaces::msg::BridgeStatus::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::BridgeStatus msg_;
};

class Init_BridgeStatus_timeout_count
{
public:
  explicit Init_BridgeStatus_timeout_count(::interfaces::msg::BridgeStatus & msg)
  : msg_(msg)
  {}
  Init_BridgeStatus_state timeout_count(::interfaces::msg::BridgeStatus::_timeout_count_type arg)
  {
    msg_.timeout_count = std::move(arg);
    return Init_BridgeStatus_state(msg_);
  }

private:
  ::interfaces::msg::BridgeStatus msg_;
};

class Init_BridgeStatus_crc_error_count
{
public:
  explicit Init_BridgeStatus_crc_error_count(::interfaces::msg::BridgeStatus & msg)
  : msg_(msg)
  {}
  Init_BridgeStatus_timeout_count crc_error_count(::interfaces::msg::BridgeStatus::_crc_error_count_type arg)
  {
    msg_.crc_error_count = std::move(arg);
    return Init_BridgeStatus_timeout_count(msg_);
  }

private:
  ::interfaces::msg::BridgeStatus msg_;
};

class Init_BridgeStatus_rx_count
{
public:
  explicit Init_BridgeStatus_rx_count(::interfaces::msg::BridgeStatus & msg)
  : msg_(msg)
  {}
  Init_BridgeStatus_crc_error_count rx_count(::interfaces::msg::BridgeStatus::_rx_count_type arg)
  {
    msg_.rx_count = std::move(arg);
    return Init_BridgeStatus_crc_error_count(msg_);
  }

private:
  ::interfaces::msg::BridgeStatus msg_;
};

class Init_BridgeStatus_tx_count
{
public:
  explicit Init_BridgeStatus_tx_count(::interfaces::msg::BridgeStatus & msg)
  : msg_(msg)
  {}
  Init_BridgeStatus_rx_count tx_count(::interfaces::msg::BridgeStatus::_tx_count_type arg)
  {
    msg_.tx_count = std::move(arg);
    return Init_BridgeStatus_rx_count(msg_);
  }

private:
  ::interfaces::msg::BridgeStatus msg_;
};

class Init_BridgeStatus_command_stream_active
{
public:
  explicit Init_BridgeStatus_command_stream_active(::interfaces::msg::BridgeStatus & msg)
  : msg_(msg)
  {}
  Init_BridgeStatus_tx_count command_stream_active(::interfaces::msg::BridgeStatus::_command_stream_active_type arg)
  {
    msg_.command_stream_active = std::move(arg);
    return Init_BridgeStatus_tx_count(msg_);
  }

private:
  ::interfaces::msg::BridgeStatus msg_;
};

class Init_BridgeStatus_connected
{
public:
  explicit Init_BridgeStatus_connected(::interfaces::msg::BridgeStatus & msg)
  : msg_(msg)
  {}
  Init_BridgeStatus_command_stream_active connected(::interfaces::msg::BridgeStatus::_connected_type arg)
  {
    msg_.connected = std::move(arg);
    return Init_BridgeStatus_command_stream_active(msg_);
  }

private:
  ::interfaces::msg::BridgeStatus msg_;
};

class Init_BridgeStatus_header
{
public:
  Init_BridgeStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BridgeStatus_connected header(::interfaces::msg::BridgeStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BridgeStatus_connected(msg_);
  }

private:
  ::interfaces::msg::BridgeStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::BridgeStatus>()
{
  return interfaces::msg::builder::Init_BridgeStatus_header();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__BRIDGE_STATUS__BUILDER_HPP_
