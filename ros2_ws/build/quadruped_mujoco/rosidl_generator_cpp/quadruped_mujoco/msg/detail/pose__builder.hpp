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

class Init_Pose_orientation
{
public:
  explicit Init_Pose_orientation(::quadruped_mujoco::msg::Pose & msg)
  : msg_(msg)
  {}
  ::quadruped_mujoco::msg::Pose orientation(::quadruped_mujoco::msg::Pose::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadruped_mujoco::msg::Pose msg_;
};

class Init_Pose_position
{
public:
  Init_Pose_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pose_orientation position(::quadruped_mujoco::msg::Pose::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Pose_orientation(msg_);
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
  return quadruped_mujoco::msg::builder::Init_Pose_position();
}

}  // namespace quadruped_mujoco

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__POSE__BUILDER_HPP_
