// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/VehicleStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/vehicle_status.hpp"


#ifndef INTERFACES__MSG__DETAIL__VEHICLE_STATUS__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__VEHICLE_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interfaces__msg__VehicleStatus __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__VehicleStatus __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleStatus_
{
  using Type = VehicleStatus_<ContainerAllocator>;

  explicit VehicleStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enabled = false;
      this->estop_active = false;
      this->speed_mps = 0.0f;
      this->yaw_rate_rps = 0.0f;
      this->fault_code = 0;
      this->mode = "";
    }
  }

  explicit VehicleStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enabled = false;
      this->estop_active = false;
      this->speed_mps = 0.0f;
      this->yaw_rate_rps = 0.0f;
      this->fault_code = 0;
      this->mode = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _enabled_type =
    bool;
  _enabled_type enabled;
  using _estop_active_type =
    bool;
  _estop_active_type estop_active;
  using _speed_mps_type =
    float;
  _speed_mps_type speed_mps;
  using _yaw_rate_rps_type =
    float;
  _yaw_rate_rps_type yaw_rate_rps;
  using _fault_code_type =
    uint8_t;
  _fault_code_type fault_code;
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__enabled(
    const bool & _arg)
  {
    this->enabled = _arg;
    return *this;
  }
  Type & set__estop_active(
    const bool & _arg)
  {
    this->estop_active = _arg;
    return *this;
  }
  Type & set__speed_mps(
    const float & _arg)
  {
    this->speed_mps = _arg;
    return *this;
  }
  Type & set__yaw_rate_rps(
    const float & _arg)
  {
    this->yaw_rate_rps = _arg;
    return *this;
  }
  Type & set__fault_code(
    const uint8_t & _arg)
  {
    this->fault_code = _arg;
    return *this;
  }
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::VehicleStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::VehicleStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::VehicleStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::VehicleStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::VehicleStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::VehicleStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::VehicleStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::VehicleStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::VehicleStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::VehicleStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__VehicleStatus
    std::shared_ptr<interfaces::msg::VehicleStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__VehicleStatus
    std::shared_ptr<interfaces::msg::VehicleStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->enabled != other.enabled) {
      return false;
    }
    if (this->estop_active != other.estop_active) {
      return false;
    }
    if (this->speed_mps != other.speed_mps) {
      return false;
    }
    if (this->yaw_rate_rps != other.yaw_rate_rps) {
      return false;
    }
    if (this->fault_code != other.fault_code) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleStatus_

// alias to use template instance with default allocator
using VehicleStatus =
  interfaces::msg::VehicleStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__VEHICLE_STATUS__STRUCT_HPP_
