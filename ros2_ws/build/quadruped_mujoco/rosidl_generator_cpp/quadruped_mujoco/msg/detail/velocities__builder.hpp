// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from quadruped_mujoco:msg/Velocities.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__BUILDER_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "quadruped_mujoco/msg/detail/velocities__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace quadruped_mujoco
{

namespace msg
{

namespace builder
{

class Init_Velocities_angular
{
public:
  explicit Init_Velocities_angular(::quadruped_mujoco::msg::Velocities & msg)
  : msg_(msg)
  {}
  ::quadruped_mujoco::msg::Velocities angular(::quadruped_mujoco::msg::Velocities::_angular_type arg)
  {
    msg_.angular = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadruped_mujoco::msg::Velocities msg_;
};

class Init_Velocities_linear
{
public:
  Init_Velocities_linear()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Velocities_angular linear(::quadruped_mujoco::msg::Velocities::_linear_type arg)
  {
    msg_.linear = std::move(arg);
    return Init_Velocities_angular(msg_);
  }

private:
  ::quadruped_mujoco::msg::Velocities msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadruped_mujoco::msg::Velocities>()
{
  return quadruped_mujoco::msg::builder::Init_Velocities_linear();
}

}  // namespace quadruped_mujoco

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__BUILDER_HPP_
