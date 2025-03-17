#ifndef QUADRUPED_COMPONENTS_HPP
#define QUADRUPED_COMPONENTS_HPP

#include "quadruped_mujoco/geometry/geometry.hpp"
#include "quadruped_mujoco/quadruped_base/gait_config.hpp"

namespace champ
{
    struct Point
    {
        float x;
        float y;
        float z;
    };

    struct Orientation
    {
        float roll;
        float pitch;
        float yaw;
    };

    struct Pose
    {
        Point position;
        Orientation orientation;
    };

    struct Velocities
    {
        struct Linear
        {
            float x;
            float y;
            float z;
        } linear;

        struct Angular
        {
            float x;
            float y;
            float z;
        } angular;
    };

    class Linear
    {
        public:
            float x;
            float y;
            float z;
            Linear():
                x(0.0f),
                y(0.0f),
                z(0.0f)
            {}
    };

    class Angular
    {
        public:
            float x;
            float y;
            float z;
            Angular():
                x(0.0f),
                y(0.0f),
                z(0.0f)
            {}
    };

    class Quaternion
    {
        public:
            Quaternion():
                x(0.0f), 
                y(0.0f), 
                z(0.0f),
                w(0.0f)
            {}
            float x;
            float y;
            float z;
            float w;
    };

    class Accelerometer
    {
        public:
            Accelerometer():
                x(0.0f), 
                y(0.0f), 
                z(0.0f)
            {}
            float x;
            float y;
            float z;
    };

    class Gyroscope
    {
        public:
            Gyroscope():
                x(0.0f), 
                y(0.0f), 
                z(0.0f)
            {}
            float x;
            float y;
            float z;
    };

    class Magnetometer
    {
        public:
            Magnetometer():
                x(0.0f), 
                y(0.0f), 
                z(0.0f)
            {}
            float x;
            float y;
            float z;
    };

    class Euler
    {
        public:
            Euler():
                roll(0.0f), 
                pitch(0.0f), 
                yaw(0.0f)
            {}
            float roll;
            float pitch;
            float yaw;
    };
}

#endif