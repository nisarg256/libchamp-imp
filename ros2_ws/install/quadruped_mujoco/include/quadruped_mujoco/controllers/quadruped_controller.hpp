// quadruped_mujoco/include/quadruped_mujoco/controllers/quadruped_controller.hpp
#ifndef QUADRUPED_CONTROLLER_HPP
#define QUADRUPED_CONTROLLER_HPP

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>

#include "quadruped_mujoco/msg/joints.hpp"
#include "quadruped_mujoco/msg/pose.hpp"
#include "quadruped_mujoco/msg/contacts_stamped.hpp"

#include <champ/body_controller/body_controller.h>
#include <champ/leg_controller/leg_controller.h>
#include <champ/kinematics/kinematics.h>

class QuadrupedController 
{
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr cmd_pose_subscriber_;
    
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_states_publisher_;   
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr joint_commands_publisher_;   
    rclcpp::Publisher<quadruped_mujoco::msg::ContactsStamped>::SharedPtr foot_contacts_publisher_;

    rclcpp::TimerBase::SharedPtr control_loop_timer_;

    champ::Velocities req_vel_;
    champ::Pose req_pose_;
    champ::GaitConfig gait_config_;

    champ::QuadrupedBase base_;
    champ::BodyController body_controller_;
    champ::LegController leg_controller_;
    champ::Kinematics kinematics_;

    std::vector<std::string> joint_names_;

    bool publish_foot_contacts_;
    bool publish_joint_states_;
    bool publish_joint_control_;
    bool in_mujoco_;

    void controlLoop();
    void publishJoints(float target_joints[12]);
    void publishFootContacts(bool foot_contacts[4]);
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
    void cmdPoseCallback(const geometry_msgs::msg::Pose::SharedPtr msg);

public:
    QuadrupedController(rclcpp::Node::SharedPtr node);
};

#endif