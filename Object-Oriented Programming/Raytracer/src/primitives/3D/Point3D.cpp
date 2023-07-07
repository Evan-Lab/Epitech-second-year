/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Point3D
*/

#include "Point3D.hpp"

namespace Raytracer {


    Point3D::Point3D()
    {
    }

    Point3D::Point3D(double _x, double _y, double _z)
    {
        this->_x = _x;
        this->_y = _y;
        this->_z = _z;
    }

    Point3D::Point3D(const Point3D &other)
    {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
    }

    Point3D::Point3D(Point3D &&other) noexcept
    {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
    }

    void Point3D::setX(double x)
    {
        this->_x = x;
    }

    void Point3D::setY(double y)
    {
        this->_y = y;
    }

    void Point3D::setZ(double z)
    {
        this->_z = z;
    }

    void Point3D::setColor(const Raytracer::Color &color)
    {
        this->_color = color;
    }

    double Point3D::getX() const
    {
        return this->_x;
    }

    double Point3D::getY() const
    {
        return this->_y;
    }

    double Point3D::getZ() const
    {
        return this->_z;
    }

    Raytracer::Color Point3D::getColor() const
    {
        return this->_color;
    }

    Point3D &Point3D::operator=(const Point3D &other)
    {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
        return *this;
    }

    Point3D &Point3D::operator=(Point3D &&other) noexcept
    {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
        return *this;
    }

    Point3D Point3D::operator+(const Point3D &other) const
    {
        return Point3D(this->_x + other._x, this->_y + other._y, this->_z + other._z);
    }

    Point3D &Point3D::operator+=(const Point3D &other)
    {
        this->_x += other._x;
        this->_y += other._y;
        this->_z += other._z;
        return *this;
    }

    Point3D Point3D::operator-(const Point3D &other) const
    {
        return Point3D(this->_x - other._x, this->_y - other._y, this->_z - other._z);
    }

    Point3D &Point3D::operator-=(const Point3D &other)
    {
        this->_x -= other._x;
        this->_y -= other._y;
        this->_z -= other._z;
        return *this;
    }

    Point3D Point3D::operator*(const double scalar) const
    {
        return Point3D(this->_x * scalar, this->_y * scalar, this->_z * scalar);
    }

    Point3D Point3D::operator^(const Point3D &other) const
    {
        return Point3D(this->_y * other._z - this->_z * other._y, this->_z * other._x - this->_x * other._z, this->_x * other._y - this->_y * other._x);
    }

    double Point3D::length() const
    {
        return sqrt(pow(this->_x, 2) + pow(this->_y, 2) + pow(this->_z, 2));
    }

    double Point3D::length(const Point3D &other) const
    {
        return sqrt(pow(other.getX() - this->_x, 2) + pow(other.getY() - this->_y, 2) + pow(other.getZ() - this->_z, 2));
    }
}
