#include <rclcpp/rclcpp.hpp>
#include "quadruped_mujoco/controllers/waypoint_controller.hpp"
#include <sensor_msgs/msg/joint_state.hpp>
#include <nav_msgs/msg/path.hpp>

class WaypointNavNode : public rclcpp::Node
{
    private:
        std::shared_ptr<champ::WaypointController> controller_;
        rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_cmd_pub_;
        rclcpp::TimerBase::SharedPtr control_timer_;
        rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr path_sub_;

        void controlLoop()
        {
            if (controller_) {
                // Create and publish joint state message
                auto joint_msg = sensor_msgs::msg::JointState();
                joint_msg.header.stamp = this->now();
                
                // Get joint positions from controller
                const float* joint_positions = controller_->getJointPositions();
                for (int i = 0; i < 12; i++) {
                    joint_msg.position.push_back(joint_positions[i]);
                }
                
                joint_cmd_pub_->publish(joint_msg);
            }
        }

        void pathCallback(const nav_msgs::msg::Path::SharedPtr msg)
        {
            // Implementation of pathCallback method
        }

    public:
        WaypointNavNode() : Node("waypoint_nav_node")
        {
            RCLCPP_INFO(get_logger(), "Waypoint navigation node initialized");
        }

        void initialize()
        {
            // Create the controller now that the shared_ptr is fully constructed
            controller_ = std::make_shared<champ::WaypointController>(shared_from_this());
            controller_->initializeGaitConfig();
            
            // Create subscriptions last
            path_sub_ = create_subscription<nav_msgs::msg::Path>(
                "path", 10, 
                std::bind(&WaypointNavNode::pathCallback, this, std::placeholders::_1));
                
            joint_cmd_pub_ = create_publisher<sensor_msgs::msg::JointState>(
                "joint_commands", 10);
                
            control_timer_ = create_wall_timer(
                std::chrono::milliseconds(10),
                std::bind(&WaypointNavNode::controlLoop, this));
                
            RCLCPP_INFO(get_logger(), "Waypoint controller node fully initialized");
        }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<WaypointNavNode>();
    node->initialize();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
} 