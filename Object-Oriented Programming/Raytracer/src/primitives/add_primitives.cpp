/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** add_primitives
*/

#include "add_primitives.hpp"

namespace Raytracer {

    AddPrimitivesScene::AddPrimitivesScene()
    {
    }

    void AddPrimitivesScene::setPrimitives(std::vector<Iprimitives *> primitives)
    {
        _primitives = primitives;
    }

    std::vector<Iprimitives *> AddPrimitivesScene::getPrimitives() const
    {
        return _primitives;
    }

}