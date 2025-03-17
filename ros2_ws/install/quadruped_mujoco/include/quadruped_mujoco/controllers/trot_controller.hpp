#ifndef TROT_CONTROLLER_HPP
#define TROT_CONTROLLER_HPP

#include "quadruped_mujoco/controllers/quadruped_controller.hpp"

namespace champ
{
    class TrotController : public QuadrupedController
    {
        public:
            TrotController(rclcpp::Node::SharedPtr node) : 
                QuadrupedController(node)
            {
                // Initialize trot-specific parameters
            }

            void execute(const Velocities &req_vel) override
            {
                // Store the requested velocity
                req_vel_ = req_vel;
                
                // Implement trot gait execution
                leg_controller_.velocityCommand(foot_positions_, req_vel_);
                
                // Calculate joint angles for each leg
                for(int i = 0; i < 4; i++) {
                    float hip, upper, lower;
                    kinematics_.inverse(hip, upper, lower, *base_.legs[i], foot_positions_[i]);
                    target_joints_[i*3] = hip;
                    target_joints_[i*3 + 1] = upper;
                    target_joints_[i*3 + 2] = lower;
                }
                
                updateJointStates();
            }

            void initializeGaitConfig() override
            {
                // CHAMP gait configuration parameters for trot gait
                GaitConfig gait_config;
                gait_config.knee_orientation = ">>"; // Both legs knee pointing backward
                gait_config.pantograph_leg = false;  // Not using a pantograph leg mechanism
                gait_config.max_linear_velocity_x = 0.5;
                gait_config.max_linear_velocity_y = 0.25;
                gait_config.max_angular_velocity_z = 1.0;
                gait_config.stance_duration = 0.25;
                gait_config.stance_depth = 0.0;
                gait_config.swing_height = 0.04;
                
                // Set gait phases - check if this field exists in your GaitConfig
                // If not, you'll need to adjust how phase information is stored
                // gait_config.stance_phases = {0.0, 0.5, 0.5, 0.0}; // FL, FR, RL, RR phases for trot gait
                
                // For trot gait, set leg phases directly on each leg
                base_.legs[0]->gait_phase(0); // Front Left
                base_.legs[1]->gait_phase(1); // Front Right
                base_.legs[2]->gait_phase(1); // Rear Left
                base_.legs[3]->gait_phase(0); // Rear Right
                
                // Set the gait configuration in the base
                base_.setGaitConfig(gait_config);
                
                RCLCPP_INFO(node_->get_logger(), "Trot controller gait configuration initialized");
            }
    };
}

#endif 