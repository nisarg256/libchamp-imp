#ifndef GAIT_CONFIG_HPP
#define GAIT_CONFIG_HPP

namespace champ
{
    struct GaitConfig
    {
        public:
            std::string knee_orientation;
            bool pantograph_leg;
            float max_linear_velocity_x;
            float max_linear_velocity_y;
            float max_angular_velocity_z;
            float stance_duration;
            float stance_depth;
            float swing_height;

            GaitConfig() :
                knee_orientation(">>"),
                pantograph_leg(false),
                max_linear_velocity_x(0.5f),
                max_linear_velocity_y(0.25f),
                max_angular_velocity_z(1.0f),
                stance_duration(0.25f),
                stance_depth(0.0f),
                swing_height(0.04f)
            {
            }
    };
}

#endif 