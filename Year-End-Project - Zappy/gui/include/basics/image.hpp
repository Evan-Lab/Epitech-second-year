/*
** EPITECH PROJECT, 2023
** zappy_hud
** File description:
** image
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "enum.hpp"

class Image : public sf::Sprite {
    public:
        Image() = default;
        Image(std::string path, anchor anchor = TOPLEFT);
        ~Image() = default;
        void setAnchor(anchor anchor);
    private:
        sf::Texture _texture;
};
