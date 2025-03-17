// quadruped_mujoco/include/quadruped_mujoco/geometry/geometry.hpp
#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "quadruped_mujoco/bla/basic_linear_algebra.h"
#include <cmath>

namespace geometry
{
    class Point 
    {
        private:
            float x_, y_, z_;

        public:
            Point(float x = 0.0f, float y = 0.0f, float z = 0.0f) : 
                x_(x), y_(y), z_(z) {}

            // Getter/setter methods
            float& x() { return x_; }
            float& y() { return y_; }
            float& z() { return z_; }

            const float& x() const { return x_; }
            const float& y() const { return y_; }
            const float& z() const { return z_; }

            // Operator overloads for vector operations
            Point operator+(const Point& other) const {
                return Point(x_ + other.x_, y_ + other.y_, z_ + other.z_);
            }

            Point operator-(const Point& other) const {
                return Point(x_ - other.x_, y_ - other.y_, z_ - other.z_);
            }

            // Uppercase X,Y,Z methods for compatibility
            float X() const { return x_; }
            float Y() const { return y_; }
            float Z() const { return z_; }
    };

    class Rotation : public Matrix<3,3>
    {
        public:
            Rotation() : Matrix<3,3>() 
            {
                Identity();
            }

            Rotation(const Rotation &obj) : Matrix<3,3>() 
            { 
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                        (*this)(i,j) = obj(i,j);
            }

            void RotateX(float angle)
            {
                float c = cos(angle);
                float s = sin(angle);
                
                (*this)(1,1) = c;  (*this)(1,2) = -s;
                (*this)(2,1) = s;  (*this)(2,2) = c;
            }

            void RotateY(float angle)
            {
                float c = cos(angle);
                float s = sin(angle);
                
                (*this)(0,0) = c;   (*this)(0,2) = s;
                (*this)(2,0) = -s;  (*this)(2,2) = c;
            }

            void RotateZ(float angle)
            {
                float c = cos(angle);
                float s = sin(angle);
                
                (*this)(0,0) = c;  (*this)(0,1) = -s;
                (*this)(1,0) = s;  (*this)(1,1) = c;
            }

            void Identity()
            {
                (*this)(0,0) = 1; (*this)(0,1) = 0; (*this)(0,2) = 0;
                (*this)(1,0) = 0; (*this)(1,1) = 1; (*this)(1,2) = 0;
                (*this)(2,0) = 0; (*this)(2,1) = 0; (*this)(2,2) = 1;
            }
    };

    class Transformation : public Matrix<4,4>
    {
        public:
            Rotation R;
            Point p;

            Transformation() : Matrix<4,4>() {
                Identity();
            }

            void Identity() {
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        (*this)(i,j) = (i == j) ? 1.0f : 0.0f;
            }

            void Translate(float x, float y, float z) {
                (*this)(0,3) += x;
                (*this)(1,3) += y;
                (*this)(2,3) += z;
            }

            void RotateX(float angle) {
                float c = cosf(angle);
                float s = sinf(angle);
                (*this)(1,1) = c;
                (*this)(1,2) = -s;
                (*this)(2,1) = s;
                (*this)(2,2) = c;
            }

            void RotateY(float angle) {
                float c = cosf(angle);
                float s = sinf(angle);
                (*this)(0,0) = c;
                (*this)(0,2) = s;
                (*this)(2,0) = -s;
                (*this)(2,2) = c;
            }

            void RotateZ(float angle) {
                float c = cosf(angle);
                float s = sinf(angle);
                (*this)(0,0) = c;
                (*this)(0,1) = -s;
                (*this)(1,0) = s;
                (*this)(1,1) = c;
            }
    };
}

#endif