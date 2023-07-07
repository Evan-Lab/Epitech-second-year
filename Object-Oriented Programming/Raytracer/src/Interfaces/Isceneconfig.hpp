/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Isceneconfig
*/

#pragma once

#include "Iprimitives.hpp"

#include <vector>

namespace Raytracer {
    class Isceneconfig {
        public:
            virtual ~Isceneconfig() = default;
            virtual void setPrimitives(std::vector<Iprimitives *> primitives) = 0;
    };

}