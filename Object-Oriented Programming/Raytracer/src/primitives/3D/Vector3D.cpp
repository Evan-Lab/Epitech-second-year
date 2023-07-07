/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

namespace Raytracer {

    Vector3D::Vector3D()
    {
    }

    Vector3D::Vector3D(double _x, double _y, double _z)
    {
        this->_x = _x;
        this->_y = _y;
        this->_z = _z;
    }

    Vector3D::Vector3D(const Vector3D &other)
    {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
    }

    Vector3D::Vector3D(Vector3D &&other) noexcept
    {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
    }

    void Vector3D::setX(double x)
    {
        this->_x = x;
    }

    void Vector3D::setY(double y)
    {
        this->_y = y;
    }

    void Vector3D::setZ(double z)
    {
        this->_z = z;
    }

    double Vector3D::getX() const
    {
        return this->_x;
    }

    double Vector3D::getY() const
    {
        return this->_y;
    }

    double Vector3D::getZ() const
    {
        return this->_z;
    }

    Vector3D &Vector3D::operator=(const Vector3D &other)
    {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
        return *this;
    }

    Vector3D &Vector3D::operator=(Vector3D &&other) noexcept
    {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
        return *this;
    }

    Vector3D Vector3D::operator+(const Vector3D &other) const
    {
        return Vector3D(this->_x + other._x, this->_y + other._y, this->_z + other._z);
    }

    Vector3D &Vector3D::operator+=(const Vector3D &other)
    {
        this->_x += other._x;
        this->_y += other._y;
        this->_z += other._z;
        return *this;
    }

    Vector3D Vector3D::operator-(const Point3D &other) const
    {
        return Vector3D(this->_x - other.getX(), this->_y - other.getY(), this->_z - other.getZ());
    }

    Vector3D Vector3D::operator-(const Vector3D &other) const
    {
        return Vector3D(this->_x - other._x, this->_y - other._y, this->_z - other._z);
    }

    Vector3D &Vector3D::operator-=(const Vector3D &other)
    {
        this->_x -= other._x;
        this->_y -= other._y;
        this->_z -= other._z;
        return *this;
    }

    Vector3D Vector3D::operator*(const double scalar) const
    {
        return Vector3D(this->_x * scalar, this->_y * scalar, this->_z * scalar);
    }

    Vector3D &Vector3D::operator*=(const double scalar)
    {
        this->_x *= scalar;
        this->_y *= scalar;
        this->_z *= scalar;
        return *this;
    }

    Vector3D Vector3D::operator/(const double scalar) const
    {
        return Vector3D(this->_x / scalar, this->_y / scalar, this->_z / scalar);
    }

    Vector3D &Vector3D::operator/=(const double scalar)
    {
        this->_x /= scalar;
        this->_y /= scalar;
        this->_z /= scalar;
        return *this;
    }

    Vector3D Vector3D::operator^(const Vector3D &other) const
    {
        double x = this->_y * other._z - this->_z * other._y;
        double y = this->_z * other._x - this->_x * other._z;
        double z = this->_x * other._y - this->_y * other._x;
        return Vector3D(x, y, z);
    }


    Vector3D Vector3D::normalize()
    {
        double length = this->length();
        return Vector3D(this->_x / length, this->_y / length, this->_z / length);
    }

    double Vector3D::dot()
    {
        return this->_x * this->_x + this->_y * this->_y + this->_z * this->_z;
    }

    double Vector3D::dot(const Vector3D &other) const
    {
        return this->_x * other._x + this->_y * other._y + this->_z * other._z;
    }

    double Vector3D::dot(const Vector3D &v1, const Vector3D &v2)
    {
        return v1._x * v2._x + v1._y * v2._y + v1._z * v2._z;
    }

    double Vector3D::length() const
    {
        return std::sqrt(_x * _x + _y * _y + _z * _z);
    }

    Vector3D Vector3D::cross(const Vector3D &other) const
    {
        double x = this->_y * other._z - this->_z * other._y;
        double y = this->_z * other._x - this->_x * other._z;
        double z = this->_x * other._y - this->_y * other._x;
        return Vector3D(x, y, z);
    }
}