// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from quadruped_mujoco:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__POSE__BUILDER_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "quadruped_mujoco/msg/detail/pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace quadruped_mujoco
{

namespace msg
{

namespace builder
{

class Init_Pose_yaw
{
public:
  explicit Init_Pose_yaw(::quadruped_mujoco::msg::Pose & msg)
  : msg_(msg)
  {}
  ::quadruped_mujoco::msg::Pose yaw(::quadruped_mujoco::msg::Pose::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadruped_mujoco::msg::Pose msg_;
};

class Init_Pose_pitch
{
public:
  explicit Init_Pose_pitch(::quadruped_mujoco::msg::Pose & msg)
  : msg_(msg)
  {}
  Init_Pose_yaw pitch(::quadruped_mujoco::msg::Pose::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Pose_yaw(msg_);
  }

private:
  ::quadruped_mujoco::msg::Pose msg_;
};

class Init_Pose_roll
{
public:
  explicit Init_Pose_roll(::quadruped_mujoco::msg::Pose & msg)
  : msg_(msg)
  {}
  Init_Pose_pitch roll(::quadruped_mujoco::msg::Pose::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Pose_pitch(msg_);
  }

private:
  ::quadruped_mujoco::msg::Pose msg_;
};

class Init_Pose_z
{
public:
  explicit Init_Pose_z(::quadruped_mujoco::msg::Pose & msg)
  : msg_(msg)
  {}
  Init_Pose_roll z(::quadruped_mujoco::msg::Pose::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Pose_roll(msg_);
  }

private:
  ::quadruped_mujoco::msg::Pose msg_;
};

class Init_Pose_y
{
public:
  explicit Init_Pose_y(::quadruped_mujoco::msg::Pose & msg)
  : msg_(msg)
  {}
  Init_Pose_z y(::quadruped_mujoco::msg::Pose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Pose_z(msg_);
  }

private:
  ::quadruped_mujoco::msg::Pose msg_;
};

class Init_Pose_x
{
public:
  Init_Pose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pose_y x(::quadruped_mujoco::msg::Pose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Pose_y(msg_);
  }

private:
  ::quadruped_mujoco::msg::Pose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadruped_mujoco::msg::Pose>()
{
  return quadruped_mujoco::msg::builder::Init_Pose_x();
}

}  // namespace quadruped_mujoco

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__POSE__BUILDER_HPP_
