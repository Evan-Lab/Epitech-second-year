/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** translation
*/

#pragma once

#include "../Interfaces/Iprimitives.hpp"
#include "../primitives/3D/Point3D.hpp"
#include "../primitives/3D/Vector3D.hpp"
#include <memory>
#include <cmath>

namespace Raytracer {

    class Translation : public Iprimitives {
        template <typename T>
        using sptr = std::shared_ptr<T>;
    public:
        Translation(sptr<Iprimitives> obj, Vector3D move);
        ~Translation() = default;
        bool translate(const Ray &ray, double &t) const;
    private:
        sptr<Iprimitives> _obj;
        Vector3D _move;
    };
}
