#ifndef KINEMATICS_HPP
#define KINEMATICS_HPP

#include "quadruped_mujoco/quadruped_base/quadruped_leg.hpp"
#include "quadruped_mujoco/geometry/geometry.hpp"
#include <cmath>

namespace champ
{
    class Kinematics
    {
        public:
            static void inverse(float &hip_joint, float &upper_leg_joint, float &lower_leg_joint, 
                              QuadrupedLeg &leg, geometry::Transformation &foot_position)
            {
                transformToHip(foot_position, leg);

                float x = foot_position.p.x();
                float y = foot_position.p.y();
                float z = foot_position.p.z();

                hip_joint = atan2f(y, z);

                float l1 = sqrtf(pow(leg.lower_leg.x(), 2) + pow(leg.lower_leg.z(), 2));
                float l2 = sqrtf(pow(leg.foot.x(), 2) + pow(leg.foot.z(), 2));

                float r = sqrtf(pow(x,2) + pow(z,2));

                upper_leg_joint = -acosf((pow(l1, 2) + pow(r, 2) - pow(l2, 2)) / (2 * l1 * r)) - 
                                 atan2f(x, z);

                lower_leg_joint = M_PI - acosf((pow(l1, 2) + pow(l2, 2) - pow(r, 2)) / (2 * l1 * l2));

                if(leg.knee_direction() < 0)
                    lower_leg_joint = -lower_leg_joint;
            }

            static void forward(geometry::Transformation &foot_position, const QuadrupedLeg &leg,
                              float hip_joint, float upper_leg_joint, float lower_leg_joint)
            {
                foot_position.Identity();
                
                foot_position.Translate(leg.foot.x(), leg.foot.y(), leg.foot.z());
                foot_position.RotateY(lower_leg_joint);
                
                foot_position.Translate(leg.lower_leg.x(), leg.lower_leg.y(), leg.lower_leg.z());
                foot_position.RotateY(upper_leg_joint);
                
                foot_position.Translate(leg.upper_leg.x(), leg.upper_leg.y(), leg.upper_leg.z());
                foot_position.RotateX(hip_joint);
                
                foot_position.Translate(leg.hip.x(), leg.hip.y(), leg.hip.z());
            }

        private:
            static void transformToHip(geometry::Transformation &foot_position, const QuadrupedLeg &leg)
            {
                foot_position.Translate(-leg.hip.x(), -leg.hip.y(), -leg.hip.z());
            }
    };
}

#endif 