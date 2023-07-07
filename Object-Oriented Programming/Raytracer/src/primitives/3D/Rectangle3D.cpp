/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-raytracer-evan.labourdette
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

namespace Raytracer {

        Rectangle3D::Rectangle3D()
        {
        }

        Rectangle3D::~Rectangle3D()
        {
        }

        Point3D Rectangle3D::pointAt(double u, double v) const
        {
                double u_mapped = u - 0.5;
                double v_mapped = v - 0.5;

                Point3D bottomSide(bottom_side.getX(), bottom_side.getY(), bottom_side.getZ());
                Point3D leftSide(left_side.getX(), left_side.getY(), left_side.getZ());

                // Calculate the position of the point in 3D space
                Point3D point = origin + bottomSide * v_mapped + leftSide * u_mapped;

                return point;
        }
}
