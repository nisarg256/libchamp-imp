#ifndef TRAJECTORY_PLANNER_HPP
#define TRAJECTORY_PLANNER_HPP

#include "quadruped_mujoco/quadruped_base/quadruped_leg.hpp"
#include "quadruped_mujoco/geometry/geometry.hpp"
#include <cmath>

namespace champ
{
    class TrajectoryPlanner
    {
        QuadrupedLeg *leg_;
        geometry::Point foot_position_;
        float step_length_;
        float rotation_;

        public:
            TrajectoryPlanner(QuadrupedLeg &leg):
                leg_(&leg),
                step_length_(0),
                rotation_(0)
            {
            }

            void generate(geometry::Transformation &foot_position, float step_length, float rotation,
                         float swing_phase_signal, float stance_phase_signal)
            {
                step_length_ = step_length;
                rotation_ = rotation;

                if(swing_phase_signal > 0.0f)
                {
                    float x = (step_length_ / 2) * cosf(M_PI * swing_phase_signal);
                    float y = leg_->gait_config->swing_height * sinf(M_PI * swing_phase_signal);

                    foot_position_ = leg_->zero_stance().p;
                    foot_position_.x() = foot_position_.x() + x;
                    foot_position_.z() = foot_position_.z() + y;
                }
                else
                {
                    float x = step_length_ * stance_phase_signal;
                    float y = -leg_->gait_config->stance_depth * 
                             cosf((M_PI * x) / step_length_);

                    foot_position_ = leg_->zero_stance().p;
                    foot_position_.x() = foot_position_.x() + x - (step_length_ / 2);
                    foot_position_.z() = foot_position_.z() + y;
                }

                foot_position.p = foot_position_;
            }
    };
}

#endif 