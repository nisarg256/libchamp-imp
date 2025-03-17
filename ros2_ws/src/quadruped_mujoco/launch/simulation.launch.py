from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess, DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_dir = get_package_share_directory('quadruped_mujoco')
    
    # Launch arguments
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    
    return LaunchDescription([
        # Arguments
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use simulation clock'),

        # Run Mujoco simulation - adjust the command as needed for your system
        ExecuteProcess(
            cmd=['mujoco_sim', '--headless=false'],
            output='screen',
        ),

        # Publish robot state (TF, joint states, etc)
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[
                {'use_sim_time': use_sim_time},
                {'robot_description': 'robot_description'}
            ]
        ),

        # MuJoCo interface node - keeping existing configuration
        Node(
            package='quadruped_mujoco',
            executable='mujoco_interface_node',
            name='mujoco_interface',
            output='screen',
            parameters=[{
                'use_sim_time': use_sim_time,
                'model_path': os.path.join(pkg_dir, 'models', 'mjcf', 'yobotics.xml')
            }]
        ),

        # Base quadruped controller
        Node(
            package='quadruped_mujoco',
            executable='quadruped_controller_node',
            name='quadruped_controller',
            output='screen',
            parameters=[{
                'use_sim_time': use_sim_time
            }]
        )
    ]) 