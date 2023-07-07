/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** tile
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <utility>
#include <memory>
#include "inventory.hpp"
#include "part.hpp"
#include "player.hpp"

class Tile {
    public:
        Tile(sf::Color color, sf::Vector2f pos, std::pair<int, int> coo);
        ~Tile() = default;
        void display(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> itemsImages) const;
        void display(std::shared_ptr<sf::RenderWindow> window) const;
        void update(float time);
        void waveEffect();
        bool checkCollision(std::shared_ptr<sf::RenderWindow> window, sf::View mapView);
        void setHover(bool hover);
        void setTarget(bool target);
        Part getTopPart() const;
        std::pair<int, int> getCoo() const;
        sf::Vector2f getPos() const;
        void setInventory(objectType type, int quantity);
        Inventory getInventory() const;
    private:
        Inventory _inventory;
        sf::Color _color;
        Part _top;
        Part _left;
        Part _right;
        float _lastUpdateWave;
        std::pair<int, int> _wavePower;
        std::pair<int, int> _coo;
};
