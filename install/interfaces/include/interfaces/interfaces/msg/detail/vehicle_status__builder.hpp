// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/VehicleStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/vehicle_status.hpp"


#ifndef INTERFACES__MSG__DETAIL__VEHICLE_STATUS__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__VEHICLE_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/vehicle_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_VehicleStatus_mode
{
public:
  explicit Init_VehicleStatus_mode(::interfaces::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::VehicleStatus mode(::interfaces::msg::VehicleStatus::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_fault_code
{
public:
  explicit Init_VehicleStatus_fault_code(::interfaces::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_mode fault_code(::interfaces::msg::VehicleStatus::_fault_code_type arg)
  {
    msg_.fault_code = std::move(arg);
    return Init_VehicleStatus_mode(msg_);
  }

private:
  ::interfaces::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_yaw_rate_rps
{
public:
  explicit Init_VehicleStatus_yaw_rate_rps(::interfaces::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_fault_code yaw_rate_rps(::interfaces::msg::VehicleStatus::_yaw_rate_rps_type arg)
  {
    msg_.yaw_rate_rps = std::move(arg);
    return Init_VehicleStatus_fault_code(msg_);
  }

private:
  ::interfaces::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_speed_mps
{
public:
  explicit Init_VehicleStatus_speed_mps(::interfaces::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_yaw_rate_rps speed_mps(::interfaces::msg::VehicleStatus::_speed_mps_type arg)
  {
    msg_.speed_mps = std::move(arg);
    return Init_VehicleStatus_yaw_rate_rps(msg_);
  }

private:
  ::interfaces::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_estop_active
{
public:
  explicit Init_VehicleStatus_estop_active(::interfaces::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_speed_mps estop_active(::interfaces::msg::VehicleStatus::_estop_active_type arg)
  {
    msg_.estop_active = std::move(arg);
    return Init_VehicleStatus_speed_mps(msg_);
  }

private:
  ::interfaces::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_enabled
{
public:
  explicit Init_VehicleStatus_enabled(::interfaces::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_estop_active enabled(::interfaces::msg::VehicleStatus::_enabled_type arg)
  {
    msg_.enabled = std::move(arg);
    return Init_VehicleStatus_estop_active(msg_);
  }

private:
  ::interfaces::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_header
{
public:
  Init_VehicleStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleStatus_enabled header(::interfaces::msg::VehicleStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleStatus_enabled(msg_);
  }

private:
  ::interfaces::msg::VehicleStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::VehicleStatus>()
{
  return interfaces::msg::builder::Init_VehicleStatus_header();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__VEHICLE_STATUS__BUILDER_HPP_
