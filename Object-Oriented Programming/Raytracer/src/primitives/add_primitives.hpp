/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** add_primitives
*/

#pragma once

#include "../Interfaces/Isceneconfig.hpp"

namespace Raytracer {

    class AddPrimitivesScene : public Isceneconfig {
    public:
        AddPrimitivesScene();
        ~AddPrimitivesScene() = default;
        void setPrimitives(std::vector<Iprimitives *> primitives) override;
        std::vector<Iprimitives *> getPrimitives() const;
    private:
        std::vector<Iprimitives *> _primitives;
    };

}