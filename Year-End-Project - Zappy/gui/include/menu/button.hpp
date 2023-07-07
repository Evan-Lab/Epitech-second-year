/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** button
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "text.hpp"
#include "tools.hpp"
#include "rectangle.hpp"

class Button {
    public:
        Button() = default;
        Button(std::string text, sf::Vector2f pos, int size, anchor anchor = TOPLEFT);
        ~Button() = default;
        void update(sf::Vector2i mousePos, float time);
        void display(std::shared_ptr<sf::RenderWindow> window) const;
        bool isHover() const;
        buttonStatus isActive() const;
        void setActive(buttonStatus active);
    private:
        std::shared_ptr<Text> _text;
        Rectangle _rect;
        bool _isHover;
        float _lastUpdate;
        buttonStatus _isActive;
};
