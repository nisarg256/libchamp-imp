#include "quadruped_mujoco/mujoco_interface.hpp"
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <rclcpp/rclcpp.hpp>

MujocoInterface::MujocoInterface() : Node("mujoco_interface")
{
    // Get model path
    std::string pkg_path = ament_index_cpp::get_package_share_directory("quadruped_mujoco");
    model_path_ = pkg_path + "/models/mjcf/yobotics.xml";

    // Create publishers
    joint_state_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    base_pose_pub_ = this->create_publisher<geometry_msgs::msg::Pose>("base_pose", 10);

    // Initialize MuJoCo
    loadModel();

    // Create timer for simulation steps
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(10),
        std::bind(&MujocoInterface::step, this));
}

void MujocoInterface::loadModel()
{
    char error[1000];
    model_ = mj_loadXML(model_path_.c_str(), nullptr, error, 1000);
    if (!model_) {
        RCLCPP_ERROR(this->get_logger(), "Could not load model: %s", error);
        return;
    }
    data_ = mj_makeData(model_);
}

void MujocoInterface::step()
{
    mj_step(model_, data_);
    publishJointStates();
    publishBasePose();
}

void MujocoInterface::publishJointStates()
{
    auto msg = sensor_msgs::msg::JointState();
    msg.header.stamp = this->now();
    
    // Add joint names
    std::vector<std::string> joint_names = {
        "FR_hip_joint", "FR_thigh_joint", "FR_calf_joint",
        "FL_hip_joint", "FL_thigh_joint", "FL_calf_joint",
        "BR_hip_joint", "BR_thigh_joint", "BR_calf_joint",
        "BL_hip_joint", "BL_thigh_joint", "BL_calf_joint"
    };
    msg.name = joint_names;

    // Get joint positions
    msg.position.resize(12);
    for(int i = 0; i < 12; i++) {
        msg.position[i] = data_->qpos[i+7]; // +7 because first 7 DoFs are for base pose
    }
    
    joint_state_pub_->publish(msg);
}

void MujocoInterface::publishBasePose()
{
    auto msg = geometry_msgs::msg::Pose();
    
    // Base position
    msg.position.x = data_->qpos[0];
    msg.position.y = data_->qpos[1];
    msg.position.z = data_->qpos[2];
    
    // Base orientation (quaternion)
    msg.orientation.w = data_->qpos[3];
    msg.orientation.x = data_->qpos[4];
    msg.orientation.y = data_->qpos[5];
    msg.orientation.z = data_->qpos[6];
    
    base_pose_pub_->publish(msg);
}

MujocoInterface::~MujocoInterface()
{
    mj_deleteData(data_);
    mj_deleteModel(model_);
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MujocoInterface>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
