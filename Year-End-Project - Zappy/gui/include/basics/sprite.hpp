/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** sprite
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "enum.hpp"

class Sprite : public sf::Sprite
{
    public:
        Sprite() = default;
        Sprite(std::string path, sf::Vector2i rectDim, anchor anchor = TOPLEFT);
        ~Sprite() = default;
        void moveRectH(int height = -1);
        void moveRectV(int width = -1);
        sf::IntRect getRect() const;
        void setAnchor(anchor anchor);
    private:
        sf::Texture _texture;
        sf::IntRect _rect;
        sf::Vector2u _textureDim;
};
