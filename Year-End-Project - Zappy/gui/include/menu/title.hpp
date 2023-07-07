/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** title
*/

#pragma once

#include <memory>
#include "text.hpp"
#include "tools.hpp"

class Title {
    public:
        Title() = default;
        Title(sf::Vector2f pos);
        ~Title() = default;
        void update(float time);
        void display(std::shared_ptr<sf::RenderWindow> window) const;
        void randomColor();
    private:
        std::shared_ptr<Text> _text;
        std::shared_ptr<Text> _leftCat;
        std::shared_ptr<Text> _rightCat;
        int _angle;
        float _lastUpdate;
};
