/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sphere
*/

#pragma once

#include "../Interfaces/Iprimitives.hpp"
#include "3D/Vector3D.hpp"
#include "3D/Point3D.hpp"
#include "3D/Ray.hpp"
#include "../material/color.hpp"

namespace Raytracer {

    class Sphere : public Iprimitives {
    public:
        Sphere();
        ~Sphere() = default;
        Sphere(Point3D center, double radius, Color color);

        bool hits(const Ray &ray, double &t);

        Point3D getIntersection(const Ray &ray) const;

        void setCenter(Point3D center);
        void setRadius(double radius);
        Point3D getCenter() const;
        double getRadius() const;
        Color getColor() const;


        double getDistance() const;
        double getX() const;
        double getY() const;
        double getTMin() const;
        double getTMax() const;

        void setX(double x);
        void setY(double y);
        void setTMin(double tMin);
        void setTMax(double tMax);

    private:
        Point3D _center;
        double _radius;
        Color _color;
        Ray _ray;
        double _tMin;
        double _tMax;
        double distance;
    };

}
