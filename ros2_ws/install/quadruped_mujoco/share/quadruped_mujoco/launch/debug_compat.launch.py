from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_dir = get_package_share_directory('quadruped_mujoco')
    model_path = os.path.join(pkg_dir, 'models/mjcf/yobotics_compat.xml')
    
    # MuJoCo simulation node with debugging enabled
    mujoco_sim_node = Node(
        package='quadruped_mujoco',
        executable='mujoco_sim_node',
        name='mujoco_sim',
        output='screen',
        parameters=[
            {'model_path': model_path},
            {'timestep': 0.001},
            {'use_visualization': False}
        ]
    )

    return LaunchDescription([mujoco_sim_node]) 