/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ppm
*/

#pragma once

#include <vector>
#include <string>
#include "../material/color.hpp"

namespace Raytracer {
    class Ppm {
    public:
        Ppm(const std::vector<std::vector<Color>> &pixels);
        ~Ppm();
    };
}