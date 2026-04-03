// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autonomy_msgs:msg/Detection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "autonomy_msgs/msg/detection.hpp"


#ifndef AUTONOMY_MSGS__MSG__DETAIL__DETECTION__BUILDER_HPP_
#define AUTONOMY_MSGS__MSG__DETAIL__DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autonomy_msgs/msg/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autonomy_msgs
{

namespace msg
{

namespace builder
{

class Init_Detection_confidence
{
public:
  explicit Init_Detection_confidence(::autonomy_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  ::autonomy_msgs::msg::Detection confidence(::autonomy_msgs::msg::Detection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autonomy_msgs::msg::Detection msg_;
};

class Init_Detection_label
{
public:
  explicit Init_Detection_label(::autonomy_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_confidence label(::autonomy_msgs::msg::Detection::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Detection_confidence(msg_);
  }

private:
  ::autonomy_msgs::msg::Detection msg_;
};

class Init_Detection_size_y
{
public:
  explicit Init_Detection_size_y(::autonomy_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_label size_y(::autonomy_msgs::msg::Detection::_size_y_type arg)
  {
    msg_.size_y = std::move(arg);
    return Init_Detection_label(msg_);
  }

private:
  ::autonomy_msgs::msg::Detection msg_;
};

class Init_Detection_size_x
{
public:
  explicit Init_Detection_size_x(::autonomy_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_size_y size_x(::autonomy_msgs::msg::Detection::_size_x_type arg)
  {
    msg_.size_x = std::move(arg);
    return Init_Detection_size_y(msg_);
  }

private:
  ::autonomy_msgs::msg::Detection msg_;
};

class Init_Detection_angle
{
public:
  explicit Init_Detection_angle(::autonomy_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_size_x angle(::autonomy_msgs::msg::Detection::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_Detection_size_x(msg_);
  }

private:
  ::autonomy_msgs::msg::Detection msg_;
};

class Init_Detection_distance
{
public:
  explicit Init_Detection_distance(::autonomy_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_angle distance(::autonomy_msgs::msg::Detection::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_Detection_angle(msg_);
  }

private:
  ::autonomy_msgs::msg::Detection msg_;
};

class Init_Detection_position
{
public:
  Init_Detection_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_distance position(::autonomy_msgs::msg::Detection::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Detection_distance(msg_);
  }

private:
  ::autonomy_msgs::msg::Detection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::autonomy_msgs::msg::Detection>()
{
  return autonomy_msgs::msg::builder::Init_Detection_position();
}

}  // namespace autonomy_msgs

#endif  // AUTONOMY_MSGS__MSG__DETAIL__DETECTION__BUILDER_HPP_
