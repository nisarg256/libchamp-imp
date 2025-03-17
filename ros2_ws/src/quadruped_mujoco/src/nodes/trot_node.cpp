#include <rclcpp/rclcpp.hpp>
#include "quadruped_mujoco/controllers/trot_controller.hpp"
#include <sensor_msgs/msg/joint_state.hpp>

class TrotNode : public rclcpp::Node
{
    private:
        std::shared_ptr<champ::TrotController> controller_;
        rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_cmd_pub_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;

        void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
        {
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
            for (int i = 0; i < 12; i++) {
                joint_msg.position.push_back(joint_positions[i]);
            }
            
            joint_cmd_pub_->publish(joint_msg);
            RCLCPP_DEBUG(get_logger(), "Joint commands published");
        }

    public:
        TrotNode() : Node("trot_node")
        {
            RCLCPP_INFO(get_logger(), "Initializing Trot Node");
            
            // Create publishers first
            joint_cmd_pub_ = create_publisher<sensor_msgs::msg::JointState>(
                "joint_commands", 10);
                
            // Don't create the controller here! Move it to initialize()
            
            RCLCPP_INFO(get_logger(), "Trot node basic initialization completed");
        }

        void initialize()
        {
            // Create the controller now that the shared_ptr is fully constructed
            controller_ = std::make_shared<champ::TrotController>(shared_from_this());
            controller_->initializeGaitConfig();
            
            // Subscribe to cmd_vel last
            cmd_vel_sub_ = create_subscription<geometry_msgs::msg::Twist>(
                "cmd_vel", 10, 
                std::bind(&TrotNode::cmdVelCallback, this, std::placeholders::_1));
                
            RCLCPP_INFO(get_logger(), "Trot controller node fully initialized");
        }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    
    RCLCPP_INFO(rclcpp::get_logger("trot_node_main"), "Starting Trot Node");
    
    // Use this pattern to allow shared_from_this() to work correctly
    std::shared_ptr<TrotNode> node;
    try {
        node = std::make_shared<TrotNode>();
        node->initialize(); // This is where shared_from_this() is safe to use
        RCLCPP_INFO(rclcpp::get_logger("trot_node_main"), "Node created successfully");
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("trot_node_main"), "Exception during node creation: %s", e.what());
        return 1;
    }
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
} 