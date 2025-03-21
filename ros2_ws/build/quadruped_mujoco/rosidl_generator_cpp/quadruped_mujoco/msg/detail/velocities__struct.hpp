// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from quadruped_mujoco:msg/Velocities.idl
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__STRUCT_HPP_
#define QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'linear'
// Member 'angular'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__quadruped_mujoco__msg__Velocities __attribute__((deprecated))
#else
# define DEPRECATED__quadruped_mujoco__msg__Velocities __declspec(deprecated)
#endif

namespace quadruped_mujoco
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Velocities_
{
  using Type = Velocities_<ContainerAllocator>;

  explicit Velocities_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : linear(_init),
    angular(_init)
  {
    (void)_init;
  }

  explicit Velocities_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : linear(_alloc, _init),
    angular(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _linear_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _linear_type linear;
  using _angular_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _angular_type angular;

  // setters for named parameter idiom
  Type & set__linear(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->linear = _arg;
    return *this;
  }
  Type & set__angular(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->angular = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    quadruped_mujoco::msg::Velocities_<ContainerAllocator> *;
  using ConstRawPtr =
    const quadruped_mujoco::msg::Velocities_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<quadruped_mujoco::msg::Velocities_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<quadruped_mujoco::msg::Velocities_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      quadruped_mujoco::msg::Velocities_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<quadruped_mujoco::msg::Velocities_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      quadruped_mujoco::msg::Velocities_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<quadruped_mujoco::msg::Velocities_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<quadruped_mujoco::msg::Velocities_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<quadruped_mujoco::msg::Velocities_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__quadruped_mujoco__msg__Velocities
    std::shared_ptr<quadruped_mujoco::msg::Velocities_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__quadruped_mujoco__msg__Velocities
    std::shared_ptr<quadruped_mujoco::msg::Velocities_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Velocities_ & other) const
  {
    if (this->linear != other.linear) {
      return false;
    }
    if (this->angular != other.angular) {
      return false;
    }
    return true;
  }
  bool operator!=(const Velocities_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Velocities_

// alias to use template instance with default allocator
using Velocities =
  quadruped_mujoco::msg::Velocities_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace quadruped_mujoco

#endif  // QUADRUPED_MUJOCO__MSG__DETAIL__VELOCITIES__STRUCT_HPP_
