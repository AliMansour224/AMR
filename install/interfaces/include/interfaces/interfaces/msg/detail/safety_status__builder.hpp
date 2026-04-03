// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/safety_status.hpp"


#ifndef INTERFACES__MSG__DETAIL__SAFETY_STATUS__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__SAFETY_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/safety_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_SafetyStatus_reason
{
public:
  explicit Init_SafetyStatus_reason(::interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::SafetyStatus reason(::interfaces::msg::SafetyStatus::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_state
{
public:
  explicit Init_SafetyStatus_state(::interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  Init_SafetyStatus_reason state(::interfaces::msg::SafetyStatus::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_SafetyStatus_reason(msg_);
  }

private:
  ::interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_stale_vehicle_status
{
public:
  explicit Init_SafetyStatus_stale_vehicle_status(::interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  Init_SafetyStatus_state stale_vehicle_status(::interfaces::msg::SafetyStatus::_stale_vehicle_status_type arg)
  {
    msg_.stale_vehicle_status = std::move(arg);
    return Init_SafetyStatus_state(msg_);
  }

private:
  ::interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_stale_odom
{
public:
  explicit Init_SafetyStatus_stale_odom(::interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  Init_SafetyStatus_stale_vehicle_status stale_odom(::interfaces::msg::SafetyStatus::_stale_odom_type arg)
  {
    msg_.stale_odom = std::move(arg);
    return Init_SafetyStatus_stale_vehicle_status(msg_);
  }

private:
  ::interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_stale_scan
{
public:
  explicit Init_SafetyStatus_stale_scan(::interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  Init_SafetyStatus_stale_odom stale_scan(::interfaces::msg::SafetyStatus::_stale_scan_type arg)
  {
    msg_.stale_scan = std::move(arg);
    return Init_SafetyStatus_stale_odom(msg_);
  }

private:
  ::interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_estop_active
{
public:
  explicit Init_SafetyStatus_estop_active(::interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  Init_SafetyStatus_stale_scan estop_active(::interfaces::msg::SafetyStatus::_estop_active_type arg)
  {
    msg_.estop_active = std::move(arg);
    return Init_SafetyStatus_stale_scan(msg_);
  }

private:
  ::interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_safe_to_move
{
public:
  explicit Init_SafetyStatus_safe_to_move(::interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  Init_SafetyStatus_estop_active safe_to_move(::interfaces::msg::SafetyStatus::_safe_to_move_type arg)
  {
    msg_.safe_to_move = std::move(arg);
    return Init_SafetyStatus_estop_active(msg_);
  }

private:
  ::interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_header
{
public:
  Init_SafetyStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SafetyStatus_safe_to_move header(::interfaces::msg::SafetyStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SafetyStatus_safe_to_move(msg_);
  }

private:
  ::interfaces::msg::SafetyStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::SafetyStatus>()
{
  return interfaces::msg::builder::Init_SafetyStatus_header();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__SAFETY_STATUS__BUILDER_HPP_
