#ifndef BODY_CONTROLLER_HPP
#define BODY_CONTROLLER_HPP

#include "quadruped_mujoco/quadruped_base/quadruped_base.hpp"
#include "quadruped_mujoco/geometry/geometry.hpp"
#include "quadruped_mujoco/quadruped_base/quadruped_components.hpp"

namespace champ
{
    class BodyController
    {
        QuadrupedBase *base_;
        geometry::Transformation foot_positions_[4];
        geometry::Transformation transformed_foot_positions_[4];
        geometry::Transformation temp_foot_positions_[4];

        public:
            BodyController(QuadrupedBase &base):
                base_(&base)
            {
            }

            void poseCommand(geometry::Transformation (&foot_positions)[4], const Pose &req_pose)
            {
                for(unsigned int i = 0; i < 4; i++)
                {
                    foot_positions_[i] = foot_positions[i];
                }

                // move body to desired pose
                geometry::Transformation body_pose;
                body_pose.p.x() = req_pose.position.x;
                body_pose.p.y() = req_pose.position.y;
                body_pose.p.z() = req_pose.position.z;

                body_pose.RotateZ(req_pose.orientation.yaw);
                body_pose.RotateY(req_pose.orientation.pitch);
                body_pose.RotateX(req_pose.orientation.roll);

                for(unsigned int i = 0; i < 4; i++)
                {
                    transformed_foot_positions_[i] = foot_positions_[i];
                    transformed_foot_positions_[i].RotateX(-req_pose.orientation.roll);
                    transformed_foot_positions_[i].RotateY(-req_pose.orientation.pitch);
                    transformed_foot_positions_[i].RotateZ(-req_pose.orientation.yaw);

                    transformed_foot_positions_[i].Translate(-req_pose.position.x,
                                                          -req_pose.position.y,
                                                          -req_pose.position.z);
                }

                for(unsigned int i = 0; i < 4; i++)
                {
                    foot_positions[i] = transformed_foot_positions_[i];
                }
            }

            void velocityCommand(geometry::Transformation (&foot_positions)[4], const Velocities &req_vel)
            {
                float delta_x = req_vel.linear.x * base_->gait_config_.stance_duration;
                float delta_y = req_vel.linear.y * base_->gait_config_.stance_duration;
                float delta_z = 0.0f;
                float delta_theta = req_vel.angular.z * base_->gait_config_.stance_duration;

                for(unsigned int i = 0; i < 4; i++)
                {
                    temp_foot_positions_[i] = foot_positions[i];
                }

                for(unsigned int i = 0; i < 4; i++)
                {
                    float x = temp_foot_positions_[i].p.x();
                    float y = temp_foot_positions_[i].p.y();

                    foot_positions[i].p.x() = x - delta_x;
                    foot_positions[i].p.y() = y - delta_y;
                    foot_positions[i].p.z() = delta_z;

                    // rotation
                    float theta = atan2(y, x);
                    float radius = sqrt(pow(x,2) + pow(y,2));

                    foot_positions[i].p.x() = radius * cos(theta + delta_theta);
                    foot_positions[i].p.y() = radius * sin(theta + delta_theta);
                }
            }
    };
}

#endif 