// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from quadruped_mujoco:msg/ContactsStamped.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__TRAITS_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "quadruped_mujoco/msg/detail/contacts_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace quadruped_mujoco
{

namespace msg
{

inline void to_flow_style_yaml(
  const ContactsStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: contacts
  {
    if (msg.contacts.size() == 0) {
      out << "contacts: []";
    } else {
      out << "contacts: [";
      size_t pending_items = msg.contacts.size();
      for (auto item : msg.contacts) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ContactsStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: contacts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.contacts.size() == 0) {
      out << "contacts: []\n";
    } else {
      out << "contacts:\n";
      for (auto item : msg.contacts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ContactsStamped & msg, bool use_flow_style = false)
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
  const quadruped_mujoco::msg::ContactsStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  quadruped_mujoco::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use quadruped_mujoco::msg::to_yaml() instead")]]
inline std::string to_yaml(const quadruped_mujoco::msg::ContactsStamped & msg)
{
  return quadruped_mujoco::msg::to_yaml(msg);
}

template<>
inline const char * data_type<quadruped_mujoco::msg::ContactsStamped>()
{
  return "quadruped_mujoco::msg::ContactsStamped";
}

template<>
inline const char * name<quadruped_mujoco::msg::ContactsStamped>()
{
  return "quadruped_mujoco/msg/ContactsStamped";
}

template<>
struct has_fixed_size<quadruped_mujoco::msg::ContactsStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<quadruped_mujoco::msg::ContactsStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<quadruped_mujoco::msg::ContactsStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__TRAITS_HPP_
