// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from quadruped_mujoco:msg/ContactsStamped.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__BUILDER_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "quadruped_mujoco/msg/detail/contacts_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace quadruped_mujoco
{

namespace msg
{

namespace builder
{

class Init_ContactsStamped_contacts
{
public:
  explicit Init_ContactsStamped_contacts(::quadruped_mujoco::msg::ContactsStamped & msg)
  : msg_(msg)
  {}
  ::quadruped_mujoco::msg::ContactsStamped contacts(::quadruped_mujoco::msg::ContactsStamped::_contacts_type arg)
  {
    msg_.contacts = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadruped_mujoco::msg::ContactsStamped msg_;
};

class Init_ContactsStamped_header
{
public:
  Init_ContactsStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ContactsStamped_contacts header(::quadruped_mujoco::msg::ContactsStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ContactsStamped_contacts(msg_);
  }

private:
  ::quadruped_mujoco::msg::ContactsStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadruped_mujoco::msg::ContactsStamped>()
{
  return quadruped_mujoco::msg::builder::Init_ContactsStamped_header();
}

}  // namespace quadruped_mujoco

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__BUILDER_HPP_
