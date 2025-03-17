// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from quadruped_mujoco:msg/Joints.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__JOINTS__BUILDER_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__JOINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "quadruped_mujoco/msg/detail/joints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace quadruped_mujoco
{

namespace msg
{

namespace builder
{

class Init_Joints_effort
{
public:
  explicit Init_Joints_effort(::quadruped_mujoco::msg::Joints & msg)
  : msg_(msg)
  {}
  ::quadruped_mujoco::msg::Joints effort(::quadruped_mujoco::msg::Joints::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadruped_mujoco::msg::Joints msg_;
};

class Init_Joints_velocity
{
public:
  explicit Init_Joints_velocity(::quadruped_mujoco::msg::Joints & msg)
  : msg_(msg)
  {}
  Init_Joints_effort velocity(::quadruped_mujoco::msg::Joints::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_Joints_effort(msg_);
  }

private:
  ::quadruped_mujoco::msg::Joints msg_;
};

class Init_Joints_position
{
public:
  Init_Joints_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Joints_velocity position(::quadruped_mujoco::msg::Joints::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Joints_velocity(msg_);
  }

private:
  ::quadruped_mujoco::msg::Joints msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadruped_mujoco::msg::Joints>()
{
  return quadruped_mujoco::msg::builder::Init_Joints_position();
}

}  // namespace quadruped_mujoco

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__JOINTS__BUILDER_HPP_
