/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** translation
*/

#include "translation.hpp"

Raytracer::Translation::Translation(sptr<Iprimitives> obj, Vector3D move)
    : _obj(obj), _move(move)
{

}

bool Raytracer::Translation::translate(const Ray& ray, double& t) const
{
    Point3D origin = ray.getOrigin();
    Point3D direction(this->_move.getX(), this->_move.getY(), this->_move.getZ());
    Ray translatedRay(origin - direction, ray.getDirection(), ray.getTMin(), ray.getTMax());

    if (_obj->hits(translatedRay, t)) {
        Point3D translatedOrigin = translatedRay.getOrigin();
        Point3D translatedDirection(translatedRay.getDirection().getX(), translatedRay.getDirection().getY(), translatedRay.getDirection().getZ());
        Point3D hitPoint = translatedOrigin + translatedDirection * t;
        hitPoint = hitPoint + direction;
        t = (hitPoint - origin).length();
        return true;
    } else {
        return false;
    }
}
