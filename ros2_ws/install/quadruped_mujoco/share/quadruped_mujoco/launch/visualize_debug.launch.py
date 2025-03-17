from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
    # Use absolute path for debugging - update this to your repo location
    repo_path = os.path.expanduser('~/Documents/repo/libchamp-imp')
    absolute_model_path = os.path.join(repo_path, 'ros2_ws/src/quadruped_mujoco/models/mjcf/simple_yobotics.xml')
    
    # Verify the path exists
    if os.path.exists(absolute_model_path):
        print(f"Model file exists at: {absolute_model_path}")
    else:
        print(f"WARNING: Model file not found at: {absolute_model_path}")
    
    # MuJoCo simulation node with visualization enabled
    mujoco_sim_node = Node(
        package='quadruped_mujoco',
        executable='mujoco_sim_node',
        name='mujoco_sim',
        output='screen',
        parameters=[
            {'model_path': absolute_model_path},
            {'timestep': 0.001},
            {'use_visualization': True}
        ]
    )

    return LaunchDescription([mujoco_sim_node]) 