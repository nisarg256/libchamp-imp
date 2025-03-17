#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "quadruped_mujoco::quadruped_mujoco_lib" for configuration ""
set_property(TARGET quadruped_mujoco::quadruped_mujoco_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(quadruped_mujoco::quadruped_mujoco_lib PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libquadruped_mujoco_lib.so"
  IMPORTED_SONAME_NOCONFIG "libquadruped_mujoco_lib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS quadruped_mujoco::quadruped_mujoco_lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_quadruped_mujoco::quadruped_mujoco_lib "${_IMPORT_PREFIX}/lib/libquadruped_mujoco_lib.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
