// quadruped_mujoco/include/quadruped_mujoco/controllers/quadruped_controller.hpp
#ifndef QUADRUPED_CONTROLLER_HPP
#define QUADRUPED_CONTROLLER_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <nav_msgs/msg/path.hpp>

#include "quadruped_mujoco/body_controller/body_controller.hpp"
#include "quadruped_mujoco/leg_controller/leg_controller.hpp"
#include "quadruped_mujoco/kinematics/kinematics.hpp"

namespace champ
{
    class QuadrupedController
    {
        protected:
            // ROS2 related members
            rclcpp::Node::SharedPtr node_;
            rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_states_publisher_;
            rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_subscriber_;
            rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr cmd_pose_subscriber_;
            rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr path_subscriber_;
            rclcpp::TimerBase::SharedPtr control_timer_;
            std::vector<std::string> joint_names_;

            // Robot components
            QuadrupedBase base_;
            BodyController body_controller_;
            LegController leg_controller_;
            Kinematics kinematics_;

            // State variables
            geometry::Transformation foot_positions_[4];
            float target_joints_[12];
            Velocities req_vel_;
            Pose req_pose_;

            // Path following variables
            std::vector<geometry_msgs::msg::PoseStamped> waypoints_;
            size_t current_waypoint_;
            bool following_path_;

            // Protected methods
            void updateJointStates();
            bool moveToWaypoint();
            void controlLoop();

            // Callbacks
            void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
            void cmdPoseCallback(const geometry_msgs::msg::Pose::SharedPtr msg);
            void pathCallback(const nav_msgs::msg::Path::SharedPtr msg);

        public:
            QuadrupedController(rclcpp::Node::SharedPtr node);
            virtual ~QuadrupedController() = default;
            
            virtual void initializeGaitConfig() = 0;
            virtual void execute(const Velocities &req_vel) = 0;

            const float* getJointPositions() const { return target_joints_; }
            const geometry::Transformation* getFootPositions() const { return foot_positions_; }
    };
}

#endif