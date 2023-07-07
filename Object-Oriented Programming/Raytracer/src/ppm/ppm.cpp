/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ppm
*/

#include "ppm.hpp"
#include <fstream>
#include <iostream>

namespace Raytracer {

    Ppm::Ppm(const std::vector<std::vector<Color>> &pixels)
    {
        std::ofstream file("image.ppm", std::ios_base::out | std::ios_base::binary);
        file << "P3" << std::endl;
        file << pixels.size() << " " << pixels[0].size() << std::endl;
        file << "255" << std::endl;

        for (size_t i = 0; i < pixels.size(); i++) {
            for (size_t j = 0; j < pixels[i].size(); j++) {
                file << pixels[i][j].getR() << " " << pixels[i][j].getG() << " " << pixels[i][j].getB() << std::endl;
            }
        }
        file.close();
    }

    Ppm::~Ppm()
    {
    }
}

