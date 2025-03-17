// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from quadruped_mujoco:msg/Velocities.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__TRAITS_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "quadruped_mujoco/msg/detail/velocities__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'linear'
// Member 'angular'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace quadruped_mujoco
{

namespace msg
{

inline void to_flow_style_yaml(
  const Velocities & msg,
  std::ostream & out)
{
  out << "{";
  // member: linear
  {
    out << "linear: ";
    to_flow_style_yaml(msg.linear, out);
    out << ", ";
  }

  // member: angular
  {
    out << "angular: ";
    to_flow_style_yaml(msg.angular, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Velocities & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear:\n";
    to_block_style_yaml(msg.linear, out, indentation + 2);
  }

  // member: angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular:\n";
    to_block_style_yaml(msg.angular, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Velocities & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace quadruped_mujoco

namespace rosidl_generator_traits
{

[[deprecated("use quadruped_mujoco::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const quadruped_mujoco::msg::Velocities & msg,
  std::ostream & out, size_t indentation = 0)
{
  quadruped_mujoco::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use quadruped_mujoco::msg::to_yaml() instead")]]
inline std::string to_yaml(const quadruped_mujoco::msg::Velocities & msg)
{
  return quadruped_mujoco::msg::to_yaml(msg);
}

template<>
inline const char * data_type<quadruped_mujoco::msg::Velocities>()
{
  return "quadruped_mujoco::msg::Velocities";
}

template<>
inline const char * name<quadruped_mujoco::msg::Velocities>()
{
  return "quadruped_mujoco/msg/Velocities";
}

template<>
struct has_fixed_size<quadruped_mujoco::msg::Velocities>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<quadruped_mujoco::msg::Velocities>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<quadruped_mujoco::msg::Velocities>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__TRAITS_HPP_
