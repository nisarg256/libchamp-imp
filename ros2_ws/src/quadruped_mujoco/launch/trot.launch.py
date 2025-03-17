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
    
    # Robot state publisher
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{
            'use_sim_time': use_sim_time,
            'robot_description': open(os.path.join(pkg_dir, 'urdf', 'yobotics.urdf'), 'r').read()
        }]
    )

    # MuJoCo simulation node
    mujoco_sim_node = Node(
        package='quadruped_mujoco',
        executable='mujoco_sim_node',
        name='mujoco_sim',
        output='screen',
        parameters=[
            {'use_sim_time': use_sim_time},
            {'model_path': os.path.join(pkg_dir, 'models/mjcf/yobotics.xml')},
            {'timestep': 0.001},
            {'use_visualization': False}
        ]
    )

    # Trot controller
    trot_controller_node = Node(
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

        robot_state_publisher_node,
        mujoco_sim_node,
        trot_controller_node
    ]) 