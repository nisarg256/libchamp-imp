#include <rclcpp/rclcpp.hpp>
#include "quadruped_mujoco/controllers/turn_controller.hpp"
#include <sensor_msgs/msg/joint_state.hpp>

class TurnNode : public rclcpp::Node
{
    private:
        std::shared_ptr<champ::TurnController> controller_;
        rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_cmd_pub_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;

        void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
        {
            champ::Velocities vel;
            vel.linear.x = msg->linear.x;
            vel.linear.y = msg->linear.y;
            vel.angular.z = msg->angular.z;
            
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
        }

    public:
        TurnNode() : Node("turn_node")
        {
            RCLCPP_INFO(get_logger(), "Initializing Turn Node");
            
            // Create publishers first
            joint_cmd_pub_ = create_publisher<sensor_msgs::msg::JointState>(
                "joint_commands", 10);
                
            // Don't create the controller here! Move it to initialize()
            
            RCLCPP_INFO(get_logger(), "Turn node basic initialization completed");
        }

        void initialize()
        {
            // Create the controller now that the shared_ptr is fully constructed
            controller_ = std::make_shared<champ::TurnController>(shared_from_this());
            controller_->initializeGaitConfig();
            
            // Create subscriptions last
            cmd_vel_sub_ = create_subscription<geometry_msgs::msg::Twist>(
                "cmd_vel", 10, 
                std::bind(&TurnNode::cmdVelCallback, this, std::placeholders::_1));
                
            RCLCPP_INFO(get_logger(), "Turn controller node fully initialized");
        }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurnNode>();
    node->initialize();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
} 