libchamp-imp

Quadruped MuJoCo Simulation

This repository contains a MuJoCo simulation implementation of the CHAMP quadruped robot. It provides a ROS2 interface and accurate replication of CHAMP's kinematics and control.

## Features

- Full 12-DOF quadruped robot simulation in MuJoCo
- Accurate implementation of CHAMP's stance controller and kinematics
- ROS2 integration
- Position and velocity control for each joint
- Sensor feedback (IMU, foot force sensors)

## Prerequisites

- Ubuntu 22.04
- ROS2 Humble
- Python 3.8+
- MuJoCo 2.3.5+

## Installation

1. Create a ROS2 workspace:
```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
```

2. Clone this repository:
```bash
git clone https://github.com/yourusername/quadruped_mujoco.git
```

3. Install dependencies:
```bash
cd ~/ros2_ws
rosdep install --from-paths src --ignore-src -r -y
```

4. Build the workspace:
```bash
colcon build
source install/setup.bash
```

## Usage

1. Run the basic standing test:
```bash
python3 src/quadruped_mujoco/scripts/test_model.py
```

This will start the MuJoCo simulation with the quadruped in CHAMP's default standing pose:
- Hip angles: 0.0 rad
- Thigh angles: 0.5 rad
- Calf angles: -1.0 rad

## Implementation Details

### Joint Configuration
- Hip joints: Range [-0.7, 0.7] rad
- Thigh joints: Range [-1.6, 1.6] rad
- Calf joints: Range [-2.4, -0.4] rad

### Control
- Position control with Kp = 100.0
- Velocity damping with Kv = 1.0
- Control frequency: 1000 Hz

### Sensors
- IMU (accelerometer and gyroscope)
- Force sensors on each foot

## Project Structure
```
quadruped_mujoco/
├── models/
│   ├── meshes/         # Robot mesh files
│   └── mjcf/           # MuJoCo model definition
├── scripts/
│   └── test_model.py   # Basic standing test
├── launch/             # ROS2 launch files
├── include/            # C++ headers
└── src/               # C++ source files
```

## Contributing

Feel free to open issues or submit pull requests for any improvements.

## License

This project is licensed under the BSD License - see the LICENSE file for details.

## Acknowledgments

- CHAMP Quadruped Robot Project
- MuJoCo Physics Engine
- ROS2 Community
