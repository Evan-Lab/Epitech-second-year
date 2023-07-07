/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Point3D
*/

#pragma once
#include <cmath>
#include "../../material/color.hpp"

namespace Raytracer {
    class Point3D {
    public:
        Point3D();
        Point3D(double _x, double _y, double _z);
        Point3D(const Point3D &other);
        Point3D(Point3D &&other) noexcept;

        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setColor(const Raytracer::Color& color);

        double getX() const ;
        double getY() const;
        double getZ() const;
        Raytracer::Color getColor() const;

        Point3D &operator=(const Point3D &other);
        Point3D &operator=(Point3D &&other) noexcept;
        Point3D operator+(const Point3D &other) const;
        Point3D &operator+=(const Point3D &other);
        Point3D operator-(const Point3D &other) const;
        Point3D &operator-=(const Point3D &other);
        Point3D operator*(const double scalar) const;
        Point3D operator^(const Point3D &other) const;

        double length() const;
        double length(const Point3D &other) const;

    private:
        double _x;
        double _y;
        double _z;
        Color _color;
    };
}