#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <mujoco/mujoco.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

class MujocoSimNode : public rclcpp::Node
{
private:
    // MuJoCo model and data structures
    mjModel* m_model;
    mjData* m_data;
    
    // ROS parameters
    std::string model_path_;
    double timestep_;
    bool use_visualization_;
    
    // ROS publishers and subscribers
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_cmd_sub_;
    rclcpp::TimerBase::SharedPtr sim_timer_;
    
    void loadModel() {
        char error[1000] = "Could not load model";
        m_model = mj_loadXML(model_path_.c_str(), 0, error, 1000);
        
        if (!m_model) {
            RCLCPP_ERROR(get_logger(), "MuJoCo model load failed: %s", error);
            return;
        }
        
        RCLCPP_INFO(get_logger(), "MuJoCo model loaded successfully: %s", model_path_.c_str());
        m_data = mj_makeData(m_model);
    }
    
    void simulationStep() {
        if (!m_model || !m_data) {
            RCLCPP_WARN(get_logger(), "Model not loaded, skipping simulation step");
            return;
        }
        
        // Step the simulation
        mj_step(m_model, m_data);
        
        // Publish joint states
        publishJointStates();
    }
    
    void publishJointStates() {
        auto msg = sensor_msgs::msg::JointState();
        msg.header.stamp = this->now();
        
        // Add all joint names, positions, velocities
        for (int i = 0; i < m_model->njnt; i++) {
            if (m_model->jnt_type[i] != mjJNT_FREE) {  // Skip the free joint
                int joint_id = i;
                int joint_adr = m_model->jnt_qposadr[joint_id];
                
                std::string joint_name = mj_id2name(m_model, mjOBJ_JOINT, joint_id);
                msg.name.push_back(joint_name);
                msg.position.push_back(m_data->qpos[joint_adr]);
                msg.velocity.push_back(m_data->qvel[m_model->jnt_dofadr[joint_id]]);
            }
        }
        
        joint_state_pub_->publish(msg);
    }
    
    void jointCommandCallback(const sensor_msgs::msg::JointState::SharedPtr msg) {
        if (!m_model || !m_data) {
            RCLCPP_WARN(get_logger(), "Model not loaded, ignoring joint command");
            return;
        }
        
        // Apply joint commands
        for (size_t i = 0; i < msg->name.size(); i++) {
            int joint_id = mj_name2id(m_model, mjOBJ_JOINT, msg->name[i].c_str());
            if (joint_id >= 0) {
                int ctrl_adr = m_model->jnt_dofadr[joint_id];
                if (i < msg->position.size()) {
                    m_data->ctrl[ctrl_adr] = msg->position[i];
                }
            }
        }
    }

public:
    MujocoSimNode() : Node("mujoco_sim_node") {
        // Declare parameters
        declare_parameter("model_path", "");
        declare_parameter("timestep", 0.001);
        declare_parameter("use_visualization", false);
        
        // Get parameters
        model_path_ = get_parameter("model_path").as_string();
        timestep_ = get_parameter("timestep").as_double();
        use_visualization_ = get_parameter("use_visualization").as_bool();
        
        if (model_path_.empty()) {
            RCLCPP_ERROR(get_logger(), "No model path specified. Please set the 'model_path' parameter.");
            return;
        }
        
        // Create publishers
        joint_state_pub_ = create_publisher<sensor_msgs::msg::JointState>(
            "joint_states", 10);
            
        // Create subscribers
        joint_cmd_sub_ = create_subscription<sensor_msgs::msg::JointState>(
            "joint_commands", 10, 
            std::bind(&MujocoSimNode::jointCommandCallback, this, std::placeholders::_1));
            
        // Load the MuJoCo model
        loadModel();
        
        // Create timer for simulation steps
        sim_timer_ = create_wall_timer(
            std::chrono::duration<double>(timestep_),
            std::bind(&MujocoSimNode::simulationStep, this));
            
        RCLCPP_INFO(get_logger(), "MuJoCo simulation node initialized with timestep: %.4f", timestep_);
    }
    
    ~MujocoSimNode() {
        if (m_data) mj_deleteData(m_data);
        if (m_model) mj_deleteModel(m_model);
    }
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MujocoSimNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
} 