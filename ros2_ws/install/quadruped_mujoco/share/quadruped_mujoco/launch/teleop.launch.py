from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Get the repository path
    repo_path = os.path.expanduser('~/Documents/repo/libchamp-imp')
    model_path = os.path.join(repo_path, 'ros2_ws/src/quadruped_mujoco/models/mjcf/yobotics_complete.xml')
    
    # Get the package directory for URDF
    pkg_dir = get_package_share_directory('quadruped_mujoco')
    urdf_path = os.path.join(pkg_dir, 'urdf', 'yobotics.urdf')
    
    # Verify the paths exist
    if os.path.exists(model_path):
        print(f"Model file exists at: {model_path}")
    else:
        print(f"WARNING: Model file not found at: {model_path}")
        
    if os.path.exists(urdf_path):
        print(f"URDF file exists at: {urdf_path}")
    else:
        print(f"WARNING: URDF file not found at: {urdf_path}. Using a default URDF.")
        urdf_path = os.path.join(repo_path, 'ros2_ws/src/quadruped_mujoco/urdf/yobotics.urdf')
    
    # Launch arguments
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    
    # Robot state publisher
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{
            'use_sim_time': use_sim_time,
            'robot_description': open(urdf_path, 'r').read()
        }]
    )

    # MuJoCo simulation node 
    mujoco_sim_node = Node(
        package='quadruped_mujoco',
        executable='mujoco_sim_node',
        name='mujoco_sim',
        output='screen',
        parameters=[
            {'model_path': model_path},
            {'timestep': 0.001},
            {'use_visualization': True}
        ]
    )

    # Quadruped controller node
    quadruped_controller_node = Node(
        package='quadruped_mujoco',
        executable='quadruped_controller_node',
        name='quadruped_controller',
        output='screen'
    )

    # Teleop keyboard for direct control
    teleop_node = Node(
        package='teleop_twist_keyboard',
        executable='teleop_twist_keyboard',
        name='teleop_keyboard',
        prefix = 'xterm -e',
        output='screen'
    )

    return LaunchDescription([
        robot_state_publisher_node,
        mujoco_sim_node,
        quadruped_controller_node,
        teleop_node
    ]) 