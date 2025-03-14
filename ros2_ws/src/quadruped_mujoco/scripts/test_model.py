#!/usr/bin/env python3
# quadruped_mujoco/scripts/test_model.py
import mujoco
import mujoco.viewer
import numpy as np
import time
import os

# Get absolute paths
script_dir = os.path.dirname(os.path.abspath(__file__))
model_dir = os.path.join(script_dir, '..')
mesh_dir = os.path.join(model_dir, 'models', 'meshes')
model_path = os.path.join(model_dir, 'models', 'mjcf', 'yobotics.xml')

def compute_standing_pose():
    """
    CHAMP's exact initialization from:
    champ_config/include/quadruped_description.h
    
    #define KNEE_ORIENTATION ">>>"  // Forward-pointing knees
    #define INIT_LEG_ANGLES {0.0, 0.5, -1.0}  // hip, thigh, calf
    """
    joint_angles = {
        'FR': [0.0, 0.5, -1.0],  # hip, thigh, calf
        'FL': [0.0, 0.5, -1.0],
        'BR': [0.0, 0.5, -1.0], 
        'BL': [0.0, 0.5, -1.0]
    }
    return joint_angles

def debug_joint_state(model, data, prefix=""):
    """Print current joint positions, velocities, and applied torques"""
    legs = ['FR', 'FL', 'BR', 'BL']
    joints = ['hip', 'thigh', 'calf']
    
    print(f"\n{prefix} Joint States:")
    for leg in legs:
        leg_states = []
        for joint in joints:
            joint_name = f"{leg}_{joint}_joint"
            joint_id = mujoco.mj_name2id(model, mujoco.mjtObj.mjOBJ_JOINT, joint_name)
            if joint_id != -1:
                pos = data.qpos[joint_id]
                vel = data.qvel[joint_id]
                actuator_id = mujoco.mj_name2id(model, mujoco.mjtObj.mjOBJ_ACTUATOR, f"{leg}_{joint}_motor")
                torque = data.ctrl[actuator_id] if actuator_id != -1 else 0.0
                leg_states.append(f"{joint}={pos:.3f}(v={vel:.3f},τ={torque:.3f})")
        print(f"{leg}: {', '.join(leg_states)}")

def apply_joint_positions(model, data, joint_angles):
    """Apply joint positions exactly as CHAMP does"""
    print("\nApplying joint positions...")
    
    # Reset all state
    mujoco.mj_resetData(model, data)
    
    # Apply joint angles in CHAMP's order: hip, thigh, calf
    for leg in ['FR', 'FL', 'BR', 'BL']:
        for i, joint in enumerate(['hip', 'thigh', 'calf']):
            joint_name = f"{leg}_{joint}_joint"
            joint_id = mujoco.mj_name2id(model, mujoco.mjtObj.mjOBJ_JOINT, joint_name)
            if joint_id != -1:
                print(f"Setting {joint_name} to {joint_angles[leg][i]:.3f}")
                data.qpos[joint_id] = joint_angles[leg][i]
    
    # Run forward kinematics to update positions
    mujoco.mj_forward(model, data)

def main():
    try:
        # Load model
        model = mujoco.MjModel.from_xml_path(model_path)
        data = mujoco.MjData(model)
        
        # Get CHAMP's standing pose
        standing_pose = compute_standing_pose()
        
        # Initialize robot
        debug_joint_state(model, data, "Initial")
        apply_joint_positions(model, data, standing_pose)
        debug_joint_state(model, data, "After initialization")
        
        # Simulation loop
        print("\nStarting simulation...")
        with mujoco.viewer.launch_passive(model, data) as viewer:
            while viewer.is_running():
                for leg in ['FR', 'FL', 'BR', 'BL']:
                    for i, joint in enumerate(['hip', 'thigh', 'calf']):
                        joint_name = f"{leg}_{joint}_joint"
                        joint_id = mujoco.mj_name2id(model, mujoco.mjtObj.mjOBJ_JOINT, joint_name)
                        
                        if joint_id != -1:
                            target = standing_pose[leg][i]
                            
                            # Set position control
                            pos_actuator_id = mujoco.mj_name2id(model, mujoco.mjtObj.mjOBJ_ACTUATOR, f"{leg}_{joint}_pos")
                            if pos_actuator_id != -1:
                                data.ctrl[pos_actuator_id] = target
                            
                            # Set velocity control to 0 (damping)
                            vel_actuator_id = mujoco.mj_name2id(model, mujoco.mjtObj.mjOBJ_ACTUATOR, f"{leg}_{joint}_vel")
                            if vel_actuator_id != -1:
                                data.ctrl[vel_actuator_id] = 0

                mujoco.mj_step(model, data)
                viewer.sync()
                
                if data.time % 0.5 < model.opt.timestep:
                    debug_joint_state(model, data, f"Time: {data.time:.2f}")
                
                time.sleep(model.opt.timestep)

    except Exception as e:
        print(f"Error: {e}")
        import traceback
        traceback.print_exc()

if __name__ == "__main__":
    main()