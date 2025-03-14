// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from quadruped_mujoco:msg/Contacts.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS__STRUCT_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__quadruped_mujoco__msg__Contacts __attribute__((deprecated))
#else
# define DEPRECATED__quadruped_mujoco__msg__Contacts __declspec(deprecated)
#endif

namespace quadruped_mujoco
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Contacts_
{
  using Type = Contacts_<ContainerAllocator>;

  explicit Contacts_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Contacts_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _contacts_type =
    std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>>;
  _contacts_type contacts;

  // setters for named parameter idiom
  Type & set__contacts(
    const std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>> & _arg)
  {
    this->contacts = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    quadruped_mujoco::msg::Contacts_<ContainerAllocator> *;
  using ConstRawPtr =
    const quadruped_mujoco::msg::Contacts_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<quadruped_mujoco::msg::Contacts_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<quadruped_mujoco::msg::Contacts_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      quadruped_mujoco::msg::Contacts_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<quadruped_mujoco::msg::Contacts_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      quadruped_mujoco::msg::Contacts_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<quadruped_mujoco::msg::Contacts_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<quadruped_mujoco::msg::Contacts_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<quadruped_mujoco::msg::Contacts_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__quadruped_mujoco__msg__Contacts
    std::shared_ptr<quadruped_mujoco::msg::Contacts_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__quadruped_mujoco__msg__Contacts
    std::shared_ptr<quadruped_mujoco::msg::Contacts_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Contacts_ & other) const
  {
    if (this->contacts != other.contacts) {
      return false;
    }
    return true;
  }
  bool operator!=(const Contacts_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Contacts_

// alias to use template instance with default allocator
using Contacts =
  quadruped_mujoco::msg::Contacts_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace quadruped_mujoco

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__CONTACTS__STRUCT_HPP_
