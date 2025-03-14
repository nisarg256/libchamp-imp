# Find MuJoCo library
find_path(MUJOCO_INCLUDE_DIR
    NAMES mujoco/mujoco.h
    PATHS /usr/local/include
)

find_library(MUJOCO_LIBRARY
    NAMES mujoco
    PATHS /usr/local/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(mujoco DEFAULT_MSG
    MUJOCO_LIBRARY MUJOCO_INCLUDE_DIR)

if(MUJOCO_FOUND)
    set(MUJOCO_LIBRARIES ${MUJOCO_LIBRARY})
    set(MUJOCO_INCLUDE_DIRS ${MUJOCO_INCLUDE_DIR})
endif()

mark_as_advanced(MUJOCO_INCLUDE_DIR MUJOCO_LIBRARY) 