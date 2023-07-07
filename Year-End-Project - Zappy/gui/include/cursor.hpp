/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** cursor
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "tile.hpp"

class Cursor {
    public:
        Cursor();
        ~Cursor() = default;
        void display(std::shared_ptr<sf::RenderWindow> window) const;
        void update(std::shared_ptr<sf::RenderWindow> window);
        void setTarget(std::shared_ptr<Tile>target);
        std::shared_ptr<Tile> getTarget() const;
        void setHover(std::shared_ptr<Tile> hover);
        std::shared_ptr<Tile> getHover() const;
    private:
        sf::CircleShape _shape;
        std::shared_ptr<Tile> _target;
        std::shared_ptr<Tile> _hover;
};
