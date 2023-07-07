/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ray
*/

#include "Ray.hpp"

namespace Raytracer {

    Ray::Ray()
    {
    }

    Ray::Ray(const Point3D &origin, const Raytracer::Vector3D &direction, double tMin, double tMax)
    {
        this->_origin = origin;
        this->_direction = direction;
        this->_tMin = tMin;
        this->_tMax = tMax;
    }

    Ray::Ray(const Ray &other)
    {
        this->_origin = other._origin;
        this->_direction = other._direction;
        this->_tMin = other._tMin;
        this->_tMax = other._tMax;
    }

    Ray::Ray(Ray &&other) noexcept
    {
        this->_origin = other._origin;
        this->_direction = other._direction;
        this->_tMin = other._tMin;
        this->_tMax = other._tMax;
    }

    void Ray::setOrigin(const Point3D &origin)
    {
        this->_origin = origin;
    }

    void Ray::setDirection(const Vector3D &direction)
    {
        this->_direction = direction;
    }

    void Ray::setTMin(double tMin)
    {
        this->_tMin = tMin;
    }

    void Ray::setTMax(double tMax)
    {
        this->_tMax = tMax;
    }

    const Point3D &Ray::getOrigin() const
    {
        return this->_origin;
    }

    const Vector3D &Ray::getDirection() const
    {
        return this->_direction;
    }

    double Ray::getTMin() const
    {
        return this->_tMin;
    }

    double Ray::getTMax() const
    {
        return this->_tMax;
    }

    Ray &Ray::operator=(const Ray &other)
    {
        this->_origin = other._origin;
        this->_direction = other._direction;
        this->_tMin = other._tMin;
        this->_tMax = other._tMax;
        return *this;
    }

    Ray &Ray::operator=(Ray &&other) noexcept
    {
        this->_origin = other._origin;
        this->_direction = other._direction;
        this->_tMin = other._tMin;
        this->_tMax = other._tMax;
        return *this;
    }

    bool Ray::hits(const Ray & /*ray*/, double & /*t*/) const
    {
        return false;
    }
}