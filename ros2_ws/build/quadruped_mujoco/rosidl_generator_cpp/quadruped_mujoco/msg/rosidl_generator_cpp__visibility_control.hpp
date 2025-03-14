// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef QUADRUPED_MUJOCO__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define QUADRUPED_MUJOCO__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_quadruped_mujoco __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_quadruped_mujoco __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_quadruped_mujoco __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_quadruped_mujoco __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_quadruped_mujoco
    #define ROSIDL_GENERATOR_CPP_PUBLIC_quadruped_mujoco ROSIDL_GENERATOR_CPP_EXPORT_quadruped_mujoco
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_quadruped_mujoco ROSIDL_GENERATOR_CPP_IMPORT_quadruped_mujoco
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_quadruped_mujoco __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_quadruped_mujoco
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_quadruped_mujoco __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_quadruped_mujoco
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // QUADRUPED_MUJOCO__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
