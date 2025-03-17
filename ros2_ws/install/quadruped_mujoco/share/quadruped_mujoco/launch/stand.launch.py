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
    model_path = LaunchConfiguration('model_path', default=os.path.join(pkg_dir, 'models', 'mjcf', 'yobotics.xml'))
    urdf_path = LaunchConfiguration('urdf_path', default=os.path.join(pkg_dir, 'urdf', 'yobotics.urdf'))
    
    # Files existence check - for debug
    print(f"Model file exists at: {os.path.join(pkg_dir, 'models/mjcf/yobotics.xml')}")
    print(f"URDF file exists at: {os.path.join(pkg_dir, 'urdf/yobotics.urdf')}")
    
    return LaunchDescription([
        # Arguments
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use simulation clock'),
            
        DeclareLaunchArgument(
            'model_path',
            default_value=os.path.join(pkg_dir, 'models', 'mjcf', 'yobotics.xml'),
            description='Path to MJCF model file'),
            
        DeclareLaunchArgument(
            'urdf_path',
            default_value=os.path.join(pkg_dir, 'urdf', 'yobotics.urdf'),
            description='Path to URDF file'),

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

        # MuJoCo simulation node
        Node(
            package='quadruped_mujoco',
            executable='mujoco_sim_node',
            name='mujoco_sim',
            output='screen',
            parameters=[{
                'use_sim_time': use_sim_time,
                'model_path': model_path,
                'timestep': 0.001,
                'use_visualization': True
            }]
        ),

        # Stand controller (simplified version of quadruped_controller)
        Node(
            package='quadruped_mujoco',
            executable='quadruped_controller_node',
            name='stand_controller',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time}],
            remappings=[
                ('cmd_vel', '/cmd_vel'),
                ('joint_commands', '/joint_commands')
            ]
        )
    ]) 