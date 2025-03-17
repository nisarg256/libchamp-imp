from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
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

        # Include the base simulation launch file
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                os.path.join(pkg_dir, 'launch', 'simulation.launch.py')
            ])
        ),
        
        # Turn controller node
        Node(
            package='quadruped_mujoco',
            executable='turn_node',
            name='turn_controller',
            output='screen',
            parameters=[{
                'use_sim_time': use_sim_time,
                'gait_config': os.path.join(pkg_dir, 'config', 'gait', 'turn.yaml')
            }]
        )
    ]) 