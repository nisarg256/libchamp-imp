// quadruped_mujoco/include/quadruped_mujoco/leg_controller/leg_controller.hpp
#ifndef LEG_CONTROLLER_HPP
#define LEG_CONTROLLER_HPP

#include "quadruped_mujoco/quadruped_base/quadruped_base.hpp"
#include "quadruped_mujoco/leg_controller/trajectory_planner.hpp"
#include "quadruped_mujoco/leg_controller/phase_generator.hpp"

namespace champ
{
    class LegController
    {
        QuadrupedBase *base_;
        champ::TrajectoryPlanner *trajectory_planners_[4];

        float capVelocities(float velocity, float min_velocity, float max_velocity)
        {
            return std::min(std::max(velocity, min_velocity), max_velocity);
        }

        public:
            LegController(QuadrupedBase &quadruped_base, PhaseGenerator::Time time = PhaseGenerator::now()):
                base_(&quadruped_base),     
                phase_generator(quadruped_base, time),
                lf(base_->lf),
                rf(base_->rf),
                lh(base_->lh),
                rh(base_->rh)
            {
                trajectory_planners_[0] = &lf;
                trajectory_planners_[1] = &rf;
                trajectory_planners_[2] = &lh;
                trajectory_planners_[3] = &rh;
            }

            void velocityCommand(geometry::Transformation (&foot_positions)[4], 
                               champ::Velocities &req_vel, 
                               PhaseGenerator::Time time = PhaseGenerator::now());

            champ::PhaseGenerator phase_generator;
            champ::TrajectoryPlanner lf;
            champ::TrajectoryPlanner rf;
            champ::TrajectoryPlanner lh;
            champ::TrajectoryPlanner rh;
    };
}

#endif