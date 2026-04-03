// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/safety_status.hpp"


#ifndef INTERFACES__MSG__DETAIL__SAFETY_STATUS__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__SAFETY_STATUS__STRUCT_HPP_

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
# define DEPRECATED__interfaces__msg__SafetyStatus __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__SafetyStatus __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SafetyStatus_
{
  using Type = SafetyStatus_<ContainerAllocator>;

  explicit SafetyStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->safe_to_move = false;
      this->estop_active = false;
      this->stale_scan = false;
      this->stale_odom = false;
      this->stale_vehicle_status = false;
      this->state = "";
      this->reason = "";
    }
  }

  explicit SafetyStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    state(_alloc),
    reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->safe_to_move = false;
      this->estop_active = false;
      this->stale_scan = false;
      this->stale_odom = false;
      this->stale_vehicle_status = false;
      this->state = "";
      this->reason = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _safe_to_move_type =
    bool;
  _safe_to_move_type safe_to_move;
  using _estop_active_type =
    bool;
  _estop_active_type estop_active;
  using _stale_scan_type =
    bool;
  _stale_scan_type stale_scan;
  using _stale_odom_type =
    bool;
  _stale_odom_type stale_odom;
  using _stale_vehicle_status_type =
    bool;
  _stale_vehicle_status_type stale_vehicle_status;
  using _state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _state_type state;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__safe_to_move(
    const bool & _arg)
  {
    this->safe_to_move = _arg;
    return *this;
  }
  Type & set__estop_active(
    const bool & _arg)
  {
    this->estop_active = _arg;
    return *this;
  }
  Type & set__stale_scan(
    const bool & _arg)
  {
    this->stale_scan = _arg;
    return *this;
  }
  Type & set__stale_odom(
    const bool & _arg)
  {
    this->stale_odom = _arg;
    return *this;
  }
  Type & set__stale_vehicle_status(
    const bool & _arg)
  {
    this->stale_vehicle_status = _arg;
    return *this;
  }
  Type & set__state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::SafetyStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::SafetyStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::SafetyStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::SafetyStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::SafetyStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::SafetyStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::SafetyStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::SafetyStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::SafetyStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::SafetyStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__SafetyStatus
    std::shared_ptr<interfaces::msg::SafetyStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__SafetyStatus
    std::shared_ptr<interfaces::msg::SafetyStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SafetyStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->safe_to_move != other.safe_to_move) {
      return false;
    }
    if (this->estop_active != other.estop_active) {
      return false;
    }
    if (this->stale_scan != other.stale_scan) {
      return false;
    }
    if (this->stale_odom != other.stale_odom) {
      return false;
    }
    if (this->stale_vehicle_status != other.stale_vehicle_status) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    return true;
  }
  bool operator!=(const SafetyStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SafetyStatus_

// alias to use template instance with default allocator
using SafetyStatus =
  interfaces::msg::SafetyStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__SAFETY_STATUS__STRUCT_HPP_
