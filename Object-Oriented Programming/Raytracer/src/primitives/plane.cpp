/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** plane
*/

#include "plane.hpp"

namespace Raytracer {

    Plane::Rectangle::Rectangle(const Point3D &origin, const Vector3D &bottom_side, const Vector3D &left_side, const Color &color)
    {
        this->origin = origin;
        this->bottom_side = bottom_side;
        this->left_side = left_side;
        this->color = color;
    }

    Plane::Triangle::Triangle(const Point3D &right_side, const Point3D &left_side, const Point3D &bottom_side, const Color &color)
    {
        this->right_side = right_side;
        this->left_side = left_side;
        this->bottom_side = bottom_side;
        this->color = color;
    }

    Raytracer::Plane::Plane(const Raytracer::Point3D &origin, const Raytracer::Vector3D &bottom_side, const Raytracer::Vector3D &left_side, const Raytracer::Color &color)
    {
        this->origin = origin;
        this->bottom_side = bottom_side;
        this->left_side = left_side;
        this->color = color;
    }

    Vector3D Plane::getNormalAt(const Raytracer::Point3D & /*point*/) const
    {
        return (this->bottom_side ^ this->left_side).normalize();
    }

    bool Plane::hits(const Raytracer::Ray &ray, double &t)
    {
        Vector3D normal(bottom_side.cross(left_side));
        double denominator = ray.getDirection().dot(normal);

        if (std::abs(denominator) > std::numeric_limits<double>::epsilon())
        {
            Vector3D test(origin.getX() - ray.getOrigin().getX(), origin.getY() - ray.getOrigin().getY(), origin.getZ() - ray.getOrigin().getZ());
            Vector3D originToPlane(test);

            t = originToPlane.dot(normal) / denominator;

            if (t >= 0)
            {
                distance = t;
                return true;
            }
        }

        return false;
    }

    bool Plane::Rectangle::hits(const Raytracer::Ray &ray, double t_min, double t_max, double &t) const
    {
        Plane plane = Plane(origin, bottom_side, left_side, color);
        Point3D hit_point = Point3D(ray.getOrigin().getX() + t * ray.getDirection().getX(), ray.getOrigin().getY() + t * ray.getDirection().getY(), ray.getOrigin().getZ() + t * ray.getDirection().getZ());
        Vector3D hit_origin = Vector3D(hit_point.getX(), hit_point.getY(), hit_point.getZ()) - Vector3D(origin.getX(), origin.getY(), origin.getZ());
        double dot1 = hit_origin.dot(bottom_side);
        double dot2 = hit_origin.dot(left_side);

        if (!plane.hits(ray, t))
            return false;
        if (t < t_min || t > t_max)
            return false;
        if (dot1 < 0 || dot1 > bottom_side.dot(bottom_side) || dot2 < 0 || dot2 > left_side.dot(left_side))
            return false;

        return true;
    }

    bool Plane::Triangle::hits(const Raytracer::Ray &ray, double t_min, double t_max, double &t) const
    {
        Vector3D left_vector = Vector3D(left_side.getX(), left_side.getY(), left_side.getZ());
        Vector3D right_vector = Vector3D(right_side.getX(), right_side.getY(), right_side.getZ());
        Vector3D bottom_vector = Vector3D(bottom_side.getX(), bottom_side.getY(), bottom_side.getZ());
        Vector3D normal = (left_vector - right_vector).cross(bottom_vector - right_vector).normalize();

        double tmp = normal.dot(ray.getDirection());

        if (tmp > 0) {
            Vector3D intersec = Vector3D(right_side.getX(), right_side.getY(), right_side.getZ()) - ray.getOrigin();
            t = intersec.dot(normal) / tmp;

            if (t >= t_min && t <= t_max) {
                Point3D intersecPoint = Point3D(ray.getOrigin().getX() + t * ray.getDirection().getX(), ray.getOrigin().getY() + t * ray.getDirection().getY(), ray.getOrigin().getZ() + t * ray.getDirection().getZ());
                Vector3D v0 = Vector3D(bottom_side.getX(), bottom_side.getY(), bottom_side.getZ()) - Vector3D(right_side.getX(), right_side.getY(), right_side.getZ());
                Vector3D v1 = Vector3D(left_side.getX(), left_side.getY(), left_side.getZ()) - Vector3D(right_side.getX(), right_side.getY(), right_side.getZ());
                Vector3D v2 = Vector3D(intersec.getX(), intersec.getY(), intersec.getZ()) - Vector3D(right_side.getX(), right_side.getY(), right_side.getZ());

                double dotv0v0 = v0.dot(v0);
                double dotv0v1 = v0.dot(v1);
                double dotv0v2 = v0.dot(v2);
                double dotv1v1 = v1.dot(v1);
                double dotv1v2 = v1.dot(v2);

                double inv = 1.0 / (dotv0v0 * dotv1v1 - dotv0v1 * dotv0v1);
                double u = (dotv1v1 * dotv0v2 - dotv0v1 * dotv1v2) * inv;
                double v = (dotv0v0 * dotv1v2 - dotv0v1 * dotv0v2) * inv;

                if (u >= 0 && v >= 0 && u + v <= 1)
                    return true;
            }
        }
        return false;
    }

    Point3D Plane::getOrigin() const
    {
        return origin;
    }

    double Plane::getX() const
    {
        return bottom_side.getX();
    }

    double Plane::getY() const
    {
        return left_side.getY();
    }

    Color Plane::getColor() const
    {
        return color;
    }

    double Plane::getDistance() const
    {
        return distance;
    }

    void Plane::setX(double x)
    {
        bottom_side.setX(x);
    }

    void Plane::setY(double y)
    {
        left_side.setY(y);
    }

    Point3D Plane::getIntersection(const Ray &ray) const
    {
        Vector3D normal = bottom_side.cross(left_side);
        Vector3D originCenter = Vector3D(origin.getX() - ray.getOrigin().getX(), origin.getY() - ray.getOrigin().getY(), origin.getZ() - ray.getOrigin().getZ());
        double denominator = ray.getDirection().dot(normal);
        double t = originCenter.dot(normal) / denominator;
        Vector3D point = Vector3D((ray.getDirection().getX() * t) + ray.getOrigin().getX(), (ray.getDirection().getY() * t) + ray.getOrigin().getY(), (ray.getDirection().getZ() * t) + ray.getOrigin().getZ());
        return Point3D(point.getX(), point.getY(), point.getZ());
    }
}