from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
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
            description='Use simulation (MuJoCo) clock if true'),

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
        
        # Quadruped controller node
        Node(
            package='quadruped_mujoco',
            executable='quadruped_controller_node',
            name='quadruped_controller',
            output='screen',
            parameters=[{
                'use_sim_time': use_sim_time,
                'gait_config': os.path.join(pkg_dir, 'config', 'gait', 'trot.yaml')
            }]
        ),

        # MuJoCo interface node
        Node(
            package='quadruped_mujoco',
            executable='mujoco_interface_node',
            name='mujoco_interface',
            output='screen',
            parameters=[{
                'use_sim_time': use_sim_time
            }]
        ),

        # RViz
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', os.path.join(pkg_dir, 'config', 'navigation.rviz')],
            output='screen'
        )
    ]) 