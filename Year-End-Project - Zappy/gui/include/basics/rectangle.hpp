/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** rectangle
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "enum.hpp"

class Rectangle : public sf::RectangleShape {
    public:
        Rectangle() = default;
        Rectangle(sf::Vector2f size, anchor anchor = TOPLEFT);
        ~Rectangle() = default;
        void setAnchor(anchor anchor);
};
