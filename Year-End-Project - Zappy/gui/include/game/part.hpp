/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** part
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <utility>
#include <memory>
#include "variables.hpp"

enum PartType {
    TOP,
    LEFT,
    RIGHT
};

class Part {
    public:
        Part() = default;
        Part(sf::Color color, sf::Vector2f pos, PartType type);
        ~Part() = default;
        void update();
        void display(std::shared_ptr<sf::RenderWindow> window) const;
        void waveEffect(std::pair<int, int> wavePower);
        bool checkCollision(std::shared_ptr<sf::RenderWindow> window, sf::View mapView);
        void setHover(bool hover);
        void setTarget(bool target);
        sf::Vector2f getPos() const;
    private:
        sf::ConvexShape _shape;
        sf::Vector2f _pos;
        bool _isHover;
        bool _isTarget;
};
