#ifndef LEG_CONTROLLER_HPP
#define LEG_CONTROLLER_HPP

#include "quadruped_mujoco/quadruped_base/quadruped_base.hpp"
#include "quadruped_mujoco/leg_controller/trajectory_planner.hpp"
#include "quadruped_mujoco/leg_controller/phase_generator.hpp"

namespace champ
{
    class LegController
    {
        public:
            LegController(QuadrupedBase &base, PhaseGenerator::Time time = PhaseGenerator::now()):
                base_(&base),
                phase_generator(*base_),
                lf(*base_->legs[0]),
                rf(*base_->legs[1]),
                lh(*base_->legs[2]),
                rh(*base_->legs[3])
            {
                trajectory_planners_[0] = &lf;
                trajectory_planners_[1] = &rf;
                trajectory_planners_[2] = &lh;
                trajectory_planners_[3] = &rh;
            }

            void velocityCommand(geometry::Transformation *foot_positions, const Velocities &req_vel,
                                PhaseGenerator::Time time = PhaseGenerator::now())
            {
                // If needed, make a copy of the velocity for internal modification
                Velocities vel_cmd = req_vel; 
                
                phase_generator.run(vel_cmd.linear.x, vel_cmd.linear.y, time);

                for(unsigned int i = 0; i < 4; i++)
                {
                    trajectory_planners_[i]->generate(foot_positions[i],
                                                    vel_cmd.linear.x,
                                                    vel_cmd.angular.z,
                                                    phase_generator.swing_phase_signal[i],
                                                    phase_generator.stance_phase_signal[i]);
                }
            }

        private:
            QuadrupedBase *base_;
            PhaseGenerator phase_generator;
            
            TrajectoryPlanner lf;
            TrajectoryPlanner rf;
            TrajectoryPlanner lh;
            TrajectoryPlanner rh;
            
            TrajectoryPlanner *trajectory_planners_[4];
    };
}

#endif 