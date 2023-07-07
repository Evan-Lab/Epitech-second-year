/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Iprimitives
*/

#pragma once

#include "../primitives/3D/Ray.hpp"
#include <cmath>

namespace Raytracer {

    class Iprimitives {
    public:
        virtual bool hits(const Ray &ray, double &t) = 0;
        virtual double getX() const = 0;
        virtual double getY() const = 0;
        virtual Color getColor() const = 0;

        virtual void setX(double x) = 0;
        virtual void setY(double y) = 0;
        virtual double getDistance() const = 0;
        virtual Point3D getIntersection(const Ray &ray) const = 0;
    };
}
