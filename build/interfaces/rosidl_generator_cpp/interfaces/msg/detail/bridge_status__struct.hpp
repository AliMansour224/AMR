// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/BridgeStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/msg/bridge_status.hpp"


#ifndef INTERFACES__MSG__DETAIL__BRIDGE_STATUS__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__BRIDGE_STATUS__STRUCT_HPP_

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
# define DEPRECATED__interfaces__msg__BridgeStatus __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__BridgeStatus __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BridgeStatus_
{
  using Type = BridgeStatus_<ContainerAllocator>;

  explicit BridgeStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connected = false;
      this->command_stream_active = false;
      this->tx_count = 0ul;
      this->rx_count = 0ul;
      this->crc_error_count = 0ul;
      this->timeout_count = 0ul;
      this->state = "";
    }
  }

  explicit BridgeStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    state(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connected = false;
      this->command_stream_active = false;
      this->tx_count = 0ul;
      this->rx_count = 0ul;
      this->crc_error_count = 0ul;
      this->timeout_count = 0ul;
      this->state = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _connected_type =
    bool;
  _connected_type connected;
  using _command_stream_active_type =
    bool;
  _command_stream_active_type command_stream_active;
  using _tx_count_type =
    uint32_t;
  _tx_count_type tx_count;
  using _rx_count_type =
    uint32_t;
  _rx_count_type rx_count;
  using _crc_error_count_type =
    uint32_t;
  _crc_error_count_type crc_error_count;
  using _timeout_count_type =
    uint32_t;
  _timeout_count_type timeout_count;
  using _state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _state_type state;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__connected(
    const bool & _arg)
  {
    this->connected = _arg;
    return *this;
  }
  Type & set__command_stream_active(
    const bool & _arg)
  {
    this->command_stream_active = _arg;
    return *this;
  }
  Type & set__tx_count(
    const uint32_t & _arg)
  {
    this->tx_count = _arg;
    return *this;
  }
  Type & set__rx_count(
    const uint32_t & _arg)
  {
    this->rx_count = _arg;
    return *this;
  }
  Type & set__crc_error_count(
    const uint32_t & _arg)
  {
    this->crc_error_count = _arg;
    return *this;
  }
  Type & set__timeout_count(
    const uint32_t & _arg)
  {
    this->timeout_count = _arg;
    return *this;
  }
  Type & set__state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::BridgeStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::BridgeStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::BridgeStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::BridgeStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::BridgeStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::BridgeStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::BridgeStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::BridgeStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::BridgeStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::BridgeStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__BridgeStatus
    std::shared_ptr<interfaces::msg::BridgeStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__BridgeStatus
    std::shared_ptr<interfaces::msg::BridgeStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BridgeStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->connected != other.connected) {
      return false;
    }
    if (this->command_stream_active != other.command_stream_active) {
      return false;
    }
    if (this->tx_count != other.tx_count) {
      return false;
    }
    if (this->rx_count != other.rx_count) {
      return false;
    }
    if (this->crc_error_count != other.crc_error_count) {
      return false;
    }
    if (this->timeout_count != other.timeout_count) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const BridgeStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BridgeStatus_

// alias to use template instance with default allocator
using BridgeStatus =
  interfaces::msg::BridgeStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__BRIDGE_STATUS__STRUCT_HPP_
