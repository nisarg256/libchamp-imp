// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from quadruped_mujoco:msg/ContactsStamped.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__STRUCT_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'contacts'
#include "quadruped_mujoco/msg/detail/contacts__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__quadruped_mujoco__msg__ContactsStamped __attribute__((deprecated))
#else
# define DEPRECATED__quadruped_mujoco__msg__ContactsStamped __declspec(deprecated)
#endif

namespace quadruped_mujoco
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ContactsStamped_
{
  using Type = ContactsStamped_<ContainerAllocator>;

  explicit ContactsStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    contacts(_init)
  {
    (void)_init;
  }

  explicit ContactsStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    contacts(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _contacts_type =
    quadruped_mujoco::msg::Contacts_<ContainerAllocator>;
  _contacts_type contacts;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__contacts(
    const quadruped_mujoco::msg::Contacts_<ContainerAllocator> & _arg)
  {
    this->contacts = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__quadruped_mujoco__msg__ContactsStamped
    std::shared_ptr<quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__quadruped_mujoco__msg__ContactsStamped
    std::shared_ptr<quadruped_mujoco::msg::ContactsStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ContactsStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->contacts != other.contacts) {
      return false;
    }
    return true;
  }
  bool operator!=(const ContactsStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ContactsStamped_

// alias to use template instance with default allocator
using ContactsStamped =
  quadruped_mujoco::msg::ContactsStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace quadruped_mujoco

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS_STAMPED__STRUCT_HPP_
