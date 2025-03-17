#ifndef QUADRUPED_LEG_HPP
#define QUADRUPED_LEG_HPP

#include "quadruped_mujoco/geometry/geometry.hpp"
#include "quadruped_mujoco/quadruped_base/gait_config.hpp"

namespace champ
{
    class QuadrupedLeg
    {
        public:
            QuadrupedLeg(const geometry::Point &hip, const geometry::Point &upper_leg, 
                        const geometry::Point &lower_leg, const geometry::Point &foot):
                hip_(hip),
                upper_leg_(upper_leg),
                lower_leg_(lower_leg),
                foot_(foot),
                knee_direction_(1.0),
                gait_phase_(1)
            {
                joint_positions[0] = 0.0;
                joint_positions[1] = 0.0;
                joint_positions[2] = 0.0;
            }

            void transformToHip(geometry::Transformation &foot_position)
            {
                foot_position.Translate(-hip_.x(), -hip_.y(), -hip_.z());
            }

            void transformToBase(geometry::Transformation &foot_position)
            {
                foot_position.Translate(hip_.x(), hip_.y(), hip_.z());
            }

            geometry::Transformation zero_stance()
            {
                geometry::Transformation foot_position;
                foot_position.p.x() = hip_.x();
                foot_position.p.y() = hip_.y();
                foot_position.p.z() = -(std::abs(upper_leg_.z()) + std::abs(lower_leg_.z()) + std::abs(foot_.z()));
                return foot_position;
            }

            float knee_direction() { return knee_direction_; }
            void knee_direction(float direction) { knee_direction_ = direction; }

            unsigned int gait_phase() { return gait_phase_; }
            void gait_phase(unsigned int phase) { gait_phase_ = phase; }

            geometry::Point hip;
            geometry::Point upper_leg;
            geometry::Point lower_leg;
            geometry::Point foot;
            GaitConfig* gait_config;
            std::vector<geometry::Point*> joint_chain;

            float joint_positions[3];

            geometry::Transformation foot_from_base()
            {
                geometry::Transformation foot_position;
                foot_position.p = hip + upper_leg + lower_leg + foot;
                return foot_position;
            }

        private:
            geometry::Point hip_;
            geometry::Point upper_leg_;
            geometry::Point lower_leg_;
            geometry::Point foot_;

            float knee_direction_;
            unsigned int gait_phase_;
    };
}

#endif 