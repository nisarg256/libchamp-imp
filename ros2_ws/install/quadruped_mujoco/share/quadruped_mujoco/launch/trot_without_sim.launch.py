from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_dir = get_package_share_directory('quadruped_mujoco')
    
    # Launch arguments
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    
    return LaunchDescription([
        # Arguments
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation clock'),

        # Robot state publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'use_sim_time': use_sim_time,
                'robot_description': open(os.path.join(pkg_dir, 'urdf', 'yobotics.urdf'), 'r').read()
            }]
        ),

        # Trot controller
        Node(
            package='quadruped_mujoco',
            executable='trot_node',
            name='trot_controller',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time}],
            remappings=[
                ('cmd_vel', '/cmd_vel'),
                ('joint_commands', '/joint_commands')
            ]
        )
    ]) 