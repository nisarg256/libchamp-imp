#include <rclcpp/rclcpp.hpp>
#include "quadruped_mujoco/controllers/trot_controller.hpp"
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/twist.hpp>

class QuadrupedControllerNode : public rclcpp::Node
{
    private:
        std::shared_ptr<champ::TrotController> controller_;
        rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_cmd_pub_;
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_states_sub_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
        rclcpp::TimerBase::SharedPtr control_timer_;
        
        void jointStatesCallback(const sensor_msgs::msg::JointState::SharedPtr msg) {
            // Process joint state feedback if needed
            // This could be used for closed-loop control
        }
        
        void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg) {
            champ::Velocities vel;
            vel.linear.x = msg->linear.x;
            vel.linear.y = msg->linear.y;
            vel.angular.z = msg->angular.z;
            
            RCLCPP_INFO(get_logger(), "Velocity command received: linear x: %.2f, y: %.2f, angular z: %.2f",
                vel.linear.x, vel.linear.y, vel.angular.z);
            
            controller_->execute(vel);
            
            // Create and publish joint state message
            auto joint_msg = sensor_msgs::msg::JointState();
            joint_msg.header.stamp = this->now();
            
            // Get joint positions from controller
            const float* joint_positions = controller_->getJointPositions();
            
            // Add joint names
            joint_msg.name = {"FR_hip_joint", "FR_thigh_joint", "FR_calf_joint",
                             "FL_hip_joint", "FL_thigh_joint", "FL_calf_joint",
                             "RR_hip_joint", "RR_thigh_joint", "RR_calf_joint",
                             "RL_hip_joint", "RL_thigh_joint", "RL_calf_joint"};
            
            // Add joint positions
            for (int i = 0; i < 12; i++) {
                joint_msg.position.push_back(joint_positions[i]);
            }
            
            joint_cmd_pub_->publish(joint_msg);
        }
        
        void controlLoop() {
            // This can be used for periodic control tasks if needed
        }
        
    public:
        QuadrupedControllerNode() : Node("quadruped_controller_node")
        {
            RCLCPP_INFO(get_logger(), "Initializing quadruped controller node");
            
            // Create publishers
            joint_cmd_pub_ = create_publisher<sensor_msgs::msg::JointState>(
                "joint_commands", 10);
                
            // Don't create the controller here! Move it to initialize()
            
            RCLCPP_INFO(get_logger(), "Quadruped controller node basic initialization completed");
        }
        
        void initialize() {
            // Create the controller now that the shared_ptr is fully constructed
            controller_ = std::make_shared<champ::TrotController>(shared_from_this());
            controller_->initializeGaitConfig();
            
            // Create subscriptions
            joint_states_sub_ = create_subscription<sensor_msgs::msg::JointState>(
                "joint_states", 10, 
                std::bind(&QuadrupedControllerNode::jointStatesCallback, this, std::placeholders::_1));
                
            cmd_vel_sub_ = create_subscription<geometry_msgs::msg::Twist>(
                "cmd_vel", 10, 
                std::bind(&QuadrupedControllerNode::cmdVelCallback, this, std::placeholders::_1));
                
            // Create timer for control loop if needed
            control_timer_ = create_wall_timer(
                std::chrono::milliseconds(10),
                std::bind(&QuadrupedControllerNode::controlLoop, this));
                
            RCLCPP_INFO(get_logger(), "Quadruped controller node fully initialized");
        }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    
    RCLCPP_INFO(rclcpp::get_logger("quadruped_controller_main"), "Starting Quadruped Controller Node");
    
    // Use this pattern to allow shared_from_this() to work correctly
    std::shared_ptr<QuadrupedControllerNode> node;
    try {
        node = std::make_shared<QuadrupedControllerNode>();
        node->initialize(); // This is where shared_from_this() is safe to use
        RCLCPP_INFO(rclcpp::get_logger("quadruped_controller_main"), "Node created successfully");
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("quadruped_controller_main"), "Exception during node creation: %s", e.what());
        return 1;
    }
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
} 