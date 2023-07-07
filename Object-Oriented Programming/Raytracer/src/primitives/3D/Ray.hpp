/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ray
*/

#pragma once

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace Raytracer {

    class Ray {
    public:
        Ray();
        Ray(const Point3D &origin, const Vector3D &direction, double tMin, double tMax);
        Ray(const Ray &other);
        Ray(Ray &&other) noexcept;

        void setOrigin(const Point3D &origin);
        void setDirection(const Vector3D &direction);
        void setTMin(double tMin);
        void setTMax(double tMax);
        const Point3D &getOrigin() const;
        const Vector3D &getDirection() const;
        double getTMin() const;
        double getTMax() const;

        Ray &operator=(const Ray &other);
        Ray &operator=(Ray &&other) noexcept;

        bool hits(const Ray &ray, double &t) const;

    private:
        double _tMin;
        double _tMax;
        Point3D _origin;
        Vector3D _direction;
    };
}