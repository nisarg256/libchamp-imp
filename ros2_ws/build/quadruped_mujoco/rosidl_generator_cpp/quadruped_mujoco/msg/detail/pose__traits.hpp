// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from quadruped_mujoco:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__POSE__TRAITS_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "quadruped_mujoco/msg/detail/pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"

namespace quadruped_mujoco
{

namespace msg
{

inline void to_flow_style_yaml(
  const Pose & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: orientation
  {
    out << "orientation: ";
    to_flow_style_yaml(msg.orientation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation:\n";
    to_block_style_yaml(msg.orientation, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pose & msg, bool use_flow_style = false)
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
  const quadruped_mujoco::msg::Pose & msg,
  std::ostream & out, size_t indentation = 0)
{
  quadruped_mujoco::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use quadruped_mujoco::msg::to_yaml() instead")]]
inline std::string to_yaml(const quadruped_mujoco::msg::Pose & msg)
{
  return quadruped_mujoco::msg::to_yaml(msg);
}

template<>
inline const char * data_type<quadruped_mujoco::msg::Pose>()
{
  return "quadruped_mujoco::msg::Pose";
}

template<>
inline const char * name<quadruped_mujoco::msg::Pose>()
{
  return "quadruped_mujoco/msg/Pose";
}

template<>
struct has_fixed_size<quadruped_mujoco::msg::Pose>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Quaternion>::value> {};

template<>
struct has_bounded_size<quadruped_mujoco::msg::Pose>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Quaternion>::value> {};

template<>
struct is_message<quadruped_mujoco::msg::Pose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__POSE__TRAITS_HPP_
