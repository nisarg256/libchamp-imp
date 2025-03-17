#ifndef WAYPOINT_CONTROLLER_HPP
#define WAYPOINT_CONTROLLER_HPP

#include "quadruped_mujoco/controllers/quadruped_controller.hpp"
#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>

namespace champ
{
    class WaypointController : public QuadrupedController
    {
        private:
            float linear_vel_;
            float angular_vel_;
            
        public:
            WaypointController(rclcpp::Node::SharedPtr node) : 
                QuadrupedController(node),
                linear_vel_(0.3),
                angular_vel_(0.5)
            {
                // Initialize waypoint-specific parameters
            }

            void execute(const Velocities &req_vel) override
            {
                // Store the requested velocity
                req_vel_ = req_vel;
                
                // Apply velocity command to leg controller
                leg_controller_.velocityCommand(foot_positions_, req_vel_);
                
                // Calculate joint angles from foot positions
                for(int i = 0; i < 4; i++) {
                    float hip, upper, lower;
                    kinematics_.inverse(hip, upper, lower, *base_.legs[i], foot_positions_[i]);
                    target_joints_[i*3] = hip;
                    target_joints_[i*3 + 1] = upper;
                    target_joints_[i*3 + 2] = lower;
                }
                
                // Update and publish joint states
                updateJointStates();
            }

            void initializeGaitConfig() override
            {
                // CHAMP gait configuration parameters for waypoint navigation
                GaitConfig gait_config;
                gait_config.knee_orientation = ">>"; // Both legs knee pointing backward
                gait_config.pantograph_leg = false;  // Not using a pantograph leg mechanism
                gait_config.max_linear_velocity_x = 0.5;
                gait_config.max_linear_velocity_y = 0.25;
                gait_config.max_angular_velocity_z = 1.0;
                gait_config.stance_duration = 0.25;
                gait_config.stance_depth = 0.0;
                gait_config.swing_height = 0.04;
                
                // Set gait phases for walking gait
                base_.legs[0]->gait_phase(0); // Front Left
                base_.legs[1]->gait_phase(2); // Front Right
                base_.legs[2]->gait_phase(3); // Rear Left
                base_.legs[3]->gait_phase(1); // Rear Right
                
                // Set the gait configuration in the base
                base_.setGaitConfig(gait_config);
                
                RCLCPP_INFO(node_->get_logger(), "Waypoint controller gait configuration initialized");
            }
    };
}

#endif 