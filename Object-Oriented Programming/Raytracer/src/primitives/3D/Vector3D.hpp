/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector3D
*/

#pragma once

#include "Point3D.hpp"
#include "cmath"

namespace Raytracer {
    class Vector3D {
    public:
        Vector3D();
        Vector3D(double _x, double _y, double _z);
        Vector3D(const Vector3D &other);
        Vector3D(Vector3D &&other) noexcept;

        void setX(double x);
        void setY(double y);
        void setZ(double z);
        double getX() const;
        double getY() const;
        double getZ() const;

        Vector3D &operator=(const Vector3D &other);
        Vector3D &operator=(Vector3D &&other) noexcept;
        Vector3D operator+(const Vector3D &other) const;
        Vector3D &operator+=(const Vector3D &other);

        Vector3D operator-(const Point3D &other) const;

        Vector3D operator-(const Vector3D &other) const;
        Vector3D &operator-=(const Vector3D &other);
        Vector3D operator*(const double scalar) const;
        Vector3D &operator*=(const double scalar);
        Vector3D operator/(const double scalar) const;
        Vector3D &operator/=(const double scalar);
        Vector3D operator^(const Vector3D &v) const;

        Vector3D normalize();
        double length() const;
        double dot();
        double dot(const Vector3D &v1, const Vector3D &v2);
        double dot(const Vector3D &other) const;
        Vector3D cross(const Vector3D &other) const;

    private:
        double _x;
        double _y;
        double _z;
    };
}