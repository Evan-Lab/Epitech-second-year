/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sphere
*/

#include "sphere.hpp"

namespace Raytracer
{

    Sphere::Sphere()
    {
    }

    Sphere::Sphere(Point3D center, double radius, Color color)
        : _center(center), _radius(radius), _color(color)
    {
    }

    void Sphere::setCenter(Point3D center)
    {
        _center = center;
    }

    void Sphere::setRadius(double radius)
    {
        _radius = radius;
    }

    Point3D Sphere::getCenter() const
    {
        return _center;
    }

    double Sphere::getRadius() const
    {
        return _radius;
    }

    Raytracer::Color Sphere::getColor() const
    {
        return _color;
    }

    double Sphere::getTMin() const
    {
        return _tMin;
    }

    double Sphere::getTMax() const
    {
        return _tMax;
    }

    void Sphere::setTMin(double tMin)
    {
        _tMin = tMin;
    }

    void Sphere::setTMax(double tMax)
    {
        _tMax = tMax;
    }

    double Sphere::getX() const
    {
        return _center.getX();
    }

    double Sphere::getY() const
    {
        return _center.getY();
    }

    void Sphere::setX(double x)
    {
        _center.setX(x);
    }

    void Sphere::setY(double y)
    {
        _center.setY(y);
    }

    double Sphere::getDistance() const
    {
        return distance;
    }

    bool Sphere::hits(const Ray &ray, double &t)
    {
        Point3D oc = ray.getOrigin() - _center;
        double a = ray.getDirection().getX() * ray.getDirection().getX() +
                   ray.getDirection().getY() * ray.getDirection().getY() +
                   ray.getDirection().getZ() * ray.getDirection().getZ();
        double b = 2.0 * (oc.getX() * ray.getDirection().getX() +
                          oc.getY() * ray.getDirection().getY() +
                          oc.getZ() * ray.getDirection().getZ());
        double c = oc.getX() * oc.getX() + oc.getY() * oc.getY() +
                   oc.getZ() * oc.getZ() - _radius * _radius;
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
        {
            return false;
        }
        else
        {
            t = (-b - sqrt(discriminant)) / (2.0 * a);
            if (t < 0)
            {
                t = (-b + sqrt(discriminant)) / (2.0 * a);
            }
            if (t >= 0)
                distance = t;
            return (t >= 0);
        }
    }

    Point3D Sphere::getIntersection(const Ray &ray) const
    {
        Vector3D originCenter = Vector3D(_center.getX() - ray.getOrigin().getX(), _center.getY() - ray.getOrigin().getY(), _center.getZ() - ray.getOrigin().getZ());
        double t = originCenter.dot(ray.getDirection());
        Vector3D point = Vector3D((ray.getDirection().getX() * t) + ray.getOrigin().getX(), (ray.getDirection().getY() * t) + ray.getOrigin().getY(), (ray.getDirection().getZ() * t) + ray.getOrigin().getZ());
        return Point3D(point.getX(), point.getY(), point.getZ());
    }
}