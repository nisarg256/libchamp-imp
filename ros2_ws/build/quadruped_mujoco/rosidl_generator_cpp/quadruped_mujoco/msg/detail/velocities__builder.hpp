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

class Init_Velocities_angular_z
{
public:
  explicit Init_Velocities_angular_z(::quadruped_mujoco::msg::Velocities & msg)
  : msg_(msg)
  {}
  ::quadruped_mujoco::msg::Velocities angular_z(::quadruped_mujoco::msg::Velocities::_angular_z_type arg)
  {
    msg_.angular_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadruped_mujoco::msg::Velocities msg_;
};

class Init_Velocities_linear_y
{
public:
  explicit Init_Velocities_linear_y(::quadruped_mujoco::msg::Velocities & msg)
  : msg_(msg)
  {}
  Init_Velocities_angular_z linear_y(::quadruped_mujoco::msg::Velocities::_linear_y_type arg)
  {
    msg_.linear_y = std::move(arg);
    return Init_Velocities_angular_z(msg_);
  }

private:
  ::quadruped_mujoco::msg::Velocities msg_;
};

class Init_Velocities_linear_x
{
public:
  Init_Velocities_linear_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Velocities_linear_y linear_x(::quadruped_mujoco::msg::Velocities::_linear_x_type arg)
  {
    msg_.linear_x = std::move(arg);
    return Init_Velocities_linear_y(msg_);
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
  return quadruped_mujoco::msg::builder::Init_Velocities_linear_x();
}

}  // namespace quadruped_mujoco

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__BUILDER_HPP_
