/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-raytracer-evan.labourdette
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
#define RECTANGLE3D_HPP_

#include "Vector3D.hpp"

namespace Raytracer {
    class Rectangle3D {
    public:
        Point3D origin;
        Vector3D bottom_side;
        Vector3D left_side;

        Rectangle3D();
        Rectangle3D(const Point3D &origin, const Vector3D &bottom_side, const Vector3D &left_side) : origin(origin), bottom_side(bottom_side), left_side(left_side) {}
        ~Rectangle3D();

        Point3D pointAt(double u, double v) const;
    };
}

#endif /* !RECTANGLE3D_HPP_ */
