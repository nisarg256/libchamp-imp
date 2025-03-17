// quadruped_mujoco/include/quadruped_mujoco/quadruped_base/quadruped_base.hpp
#ifndef QUADRUPED_BASE_HPP
#define QUADRUPED_BASE_HPP

#include "quadruped_mujoco/quadruped_base/quadruped_leg.hpp"
#include "quadruped_mujoco/quadruped_base/quadruped_components.hpp"

namespace champ
{
    class QuadrupedBase
    {
        public:
            QuadrupedLeg *legs[4];
            GaitConfig gait_config_;

            QuadrupedBase()
            {
                for(unsigned int i = 0; i < 4; i++)
                    legs[i] = NULL;
            }
            
            void setGaitConfig(GaitConfig config)
            {
                gait_config_ = config;
            }

            void getFootPositions(geometry::Transformation (&foot_positions)[4])
            {
                for(unsigned int i = 0; i < 4; i++)
                {
                    foot_positions[i] = legs[i]->foot_from_base();
                }
            }

            void updateJointPositions(float joint_positions[12])
            {
                unsigned int total_joints = 0;

                for(unsigned int i = 0; i < 4; i++)
                {
                    for(unsigned int j = 0; j < 3; j++)
                    {
                        legs[i]->joint_positions[j] = joint_positions[total_joints];
                        total_joints++;
                    }
                }
            }

            Pose getCurrentPose() const 
            { 
                Pose current_pose;
                // Fill in current pose from base state
                return current_pose;
            }
    };
}

#endif