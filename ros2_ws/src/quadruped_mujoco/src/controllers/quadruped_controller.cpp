#include "quadruped_mujoco/controllers/quadruped_controller.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>

namespace champ
{
    QuadrupedController::QuadrupedController(rclcpp::Node::SharedPtr node) :
        node_(node),
        body_controller_(base_),
        leg_controller_(base_),
        kinematics_(),
        current_waypoint_(0),
        following_path_(false)
    {
        if (!node_) {
            throw std::runtime_error("Node pointer is null in QuadrupedController constructor");
        }
        
        RCLCPP_INFO(node_->get_logger(), "Initializing QuadrupedController");
        
        // Initialize member variables with defaults
        req_vel_ = Velocities();
        req_vel_.linear.x = 0.0;
        req_vel_.linear.y = 0.0;
        req_vel_.angular.z = 0.0;
        
        // Initialize legs with proper geometry (following CHAMP's structure)
        // Front Left
        geometry::Point fl_hip(0.2, 0.15, 0.0);
        geometry::Point fl_upper_leg(0.0, 0.0, -0.05);
        geometry::Point fl_lower_leg(0.0, 0.0, -0.2);
        geometry::Point fl_foot(0.0, 0.0, -0.2);
        base_.legs[0] = new QuadrupedLeg(fl_hip, fl_upper_leg, fl_lower_leg, fl_foot);
        
        // Front Right
        geometry::Point fr_hip(0.2, -0.15, 0.0);
        geometry::Point fr_upper_leg(0.0, 0.0, -0.05);
        geometry::Point fr_lower_leg(0.0, 0.0, -0.2);
        geometry::Point fr_foot(0.0, 0.0, -0.2);
        base_.legs[1] = new QuadrupedLeg(fr_hip, fr_upper_leg, fr_lower_leg, fr_foot);
        
        // Rear Left
        geometry::Point rl_hip(-0.2, 0.15, 0.0);
        geometry::Point rl_upper_leg(0.0, 0.0, -0.05);
        geometry::Point rl_lower_leg(0.0, 0.0, -0.2);
        geometry::Point rl_foot(0.0, 0.0, -0.2);
        base_.legs[2] = new QuadrupedLeg(rl_hip, rl_upper_leg, rl_lower_leg, rl_foot);
        
        // Rear Right
        geometry::Point rr_hip(-0.2, -0.15, 0.0);
        geometry::Point rr_upper_leg(0.0, 0.0, -0.05);
        geometry::Point rr_lower_leg(0.0, 0.0, -0.2);
        geometry::Point rr_foot(0.0, 0.0, -0.2);
        base_.legs[3] = new QuadrupedLeg(rr_hip, rr_upper_leg, rr_lower_leg, rr_foot);
        
        // Initialize foot positions to zero stance
        for (int i = 0; i < 4; i++) {
            foot_positions_[i] = base_.legs[i]->zero_stance();
            RCLCPP_DEBUG(node_->get_logger(), "Leg %d zero stance: x=%.2f, y=%.2f, z=%.2f", 
                i, foot_positions_[i].p.x(), foot_positions_[i].p.y(), foot_positions_[i].p.z());
        }
        
        // Initialize joint positions to default stance
        for (int i = 0; i < 12; i++) {
            target_joints_[i] = 0.0f;
        }
        
        // Set up ROS2 interfaces - publishers and subscribers
        joint_states_publisher_ = node_->create_publisher<sensor_msgs::msg::JointState>(
            "joint_states", 10);
            
        cmd_vel_subscriber_ = node_->create_subscription<geometry_msgs::msg::Twist>(
            "cmd_vel", 10,
            std::bind(&QuadrupedController::cmdVelCallback, this, std::placeholders::_1));
            
        cmd_pose_subscriber_ = node_->create_subscription<geometry_msgs::msg::Pose>(
            "cmd_pose", 10,
            std::bind(&QuadrupedController::cmdPoseCallback, this, std::placeholders::_1));
            
        path_subscriber_ = node_->create_subscription<nav_msgs::msg::Path>(
            "path", 10,
            std::bind(&QuadrupedController::pathCallback, this, std::placeholders::_1));
            
        // Initialize joint names
        joint_names_.resize(12);
        for (int i = 0; i < 4; i++) {
            joint_names_[i*3] = "leg" + std::to_string(i) + "_hip_joint";
            joint_names_[i*3 + 1] = "leg" + std::to_string(i) + "_upper_leg_joint";
            joint_names_[i*3 + 2] = "leg" + std::to_string(i) + "_lower_leg_joint";
        }
        
        RCLCPP_INFO(node_->get_logger(), "QuadrupedController initialized successfully");
    }

    void QuadrupedController::cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        Velocities vel;
        vel.linear.x = msg->linear.x;
        vel.linear.y = msg->linear.y;
        vel.angular.z = msg->angular.z;
        
        RCLCPP_INFO(node_->get_logger(), "QuadrupedController received velocity command: %.2f, %.2f, %.2f", 
            vel.linear.x, vel.linear.y, vel.angular.z);
        
        execute(vel);
    }

    void QuadrupedController::cmdPoseCallback(const geometry_msgs::msg::Pose::SharedPtr msg)
    {
        Pose pose;
        pose.position.x = msg->position.x;
        pose.position.y = msg->position.y;
        pose.position.z = msg->position.z;
        // Convert quaternion to euler angles
        tf2::Quaternion q(
            msg->orientation.x,
            msg->orientation.y,
            msg->orientation.z,
            msg->orientation.w);
        tf2::Matrix3x3 m(q);
        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw);
        pose.orientation.roll = roll;
        pose.orientation.pitch = pitch;
        pose.orientation.yaw = yaw;
        
        req_pose_ = pose;
    }

    void QuadrupedController::pathCallback(const nav_msgs::msg::Path::SharedPtr msg)
    {
        waypoints_ = msg->poses;
        current_waypoint_ = 0;
        following_path_ = true;
    }

    bool QuadrupedController::moveToWaypoint()
    {
        if (!following_path_ || current_waypoint_ >= waypoints_.size())
        {
            following_path_ = false;
            return false;
        }

        auto& target = waypoints_[current_waypoint_];
        
        // Calculate distance to target
        float dx = target.pose.position.x - base_.getCurrentPose().position.x;
        float dy = target.pose.position.y - base_.getCurrentPose().position.y;
        float distance = std::sqrt(dx*dx + dy*dy);

        // If we're close enough to current waypoint, move to next
        if (distance < 0.1)
        {
            current_waypoint_++;
            return true;
        }

        // Calculate desired velocity to reach waypoint
        float angle_to_target = std::atan2(dy, dx);
        float angle_diff = angle_to_target - base_.getCurrentPose().orientation.yaw;

        // Normalize angle difference
        while (angle_diff > M_PI) angle_diff -= 2*M_PI;
        while (angle_diff < -M_PI) angle_diff += 2*M_PI;

        // Create velocity command
        Velocities vel;
        vel.linear.x = 0.2; // Fixed forward speed
        vel.angular.z = 0.5 * angle_diff; // Proportional control for rotation

        execute(vel);
        return true;
    }

    void QuadrupedController::controlLoop()
    {
        if (following_path_)
        {
            moveToWaypoint();
        }
    }

    void QuadrupedController::updateJointStates()
    {
        RCLCPP_DEBUG(node_->get_logger(), "Updating joint states");
        
        sensor_msgs::msg::JointState joint_states;
        joint_states.header.stamp = node_->now();
        joint_states.name = joint_names_;
        
        for(int i = 0; i < 12; i++)
        {
            joint_states.position.push_back(target_joints_[i]);
            joint_states.velocity.push_back(0.0);
            joint_states.effort.push_back(0.0);
        }
        
        joint_states_publisher_->publish(joint_states);
    }

    void QuadrupedController::initializeGaitConfig()
    {
        // Implement gait configuration initialization
    }

    void QuadrupedController::execute(const Velocities &req_vel)
    {
        // Implement execution logic
    }
} 