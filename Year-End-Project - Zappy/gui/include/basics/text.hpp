/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** text
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "enum.hpp"

class Text : public sf::Text {
    public:
        Text() = default;
        Text(std::string text, sf::Vector2f pos, int size = 50, anchor anchor = TOPLEFT);
        ~Text() = default;
        void setAnchor(anchor anchor);
    private:
        sf::Font _font;
};
