/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** plane
*/

#pragma once

#include "../Interfaces/Iprimitives.hpp"
#include "3D/Point3D.hpp"
#include "3D/Vector3D.hpp"
#include "3D/Ray.hpp"

namespace Raytracer {

    class Plane : public Iprimitives {
    public:
        class Rectangle {
        public:
            Rectangle(const Point3D &origin, const Vector3D &bottom_side, const Vector3D &left_side, const Color &color);
            bool hits(const Ray &ray, double t_min, double t_max, double &t) const;

        private:
            Point3D origin;
            Vector3D bottom_side;
            Vector3D left_side;
            Color color;
        };

        class Triangle {
        public:
            Triangle(const Point3D &right_side, const Point3D &left_side, const Point3D &bottom_side, const Color &color);
            bool hits(const Ray &ray, double t_min, double t_max, double &t) const;

        private:
            Point3D right_side;
            Point3D left_side;
            Point3D bottom_side;
            Color color;
        };
        Plane(const Point3D &origin, const Vector3D &bottom_side, const Vector3D &left_side, const Color &color);
        Vector3D getNormalAt(const Point3D &point) const;
        bool hits(const Ray &ray, double &t);

        double getX() const;
        double getY() const;
        Color getColor() const;
        double getDistance() const;

        void setX(double x);
        void setY(double y);

        Point3D getOrigin() const;
        Point3D getIntersection(const Ray &ray)const;
    private:
        Point3D origin;
        Vector3D bottom_side;
        Vector3D left_side;
        Color color;
        double distance;
    };
}