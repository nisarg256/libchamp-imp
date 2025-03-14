#ifndef MUJOCO_INTERFACE_HPP
#define MUJOCO_INTERFACE_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <mujoco/mujoco.h>

class MujocoInterface : public rclcpp::Node
{
public:
    MujocoInterface();
    ~MujocoInterface();

private:
    void loadModel();
    void step();
    void publishJointStates();
    void publishBasePose();

    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr base_pose_pub_;
    rclcpp::TimerBase::SharedPtr timer_;

    mjModel* model_;
    mjData* data_;
    std::string model_path_;
};

#endif
