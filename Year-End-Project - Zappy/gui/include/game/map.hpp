/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** map
*/

#pragma once

#include <utility>
#include <vector>
#include <SFML/Graphics.hpp>
#include "variables.hpp"
#include "tile.hpp"
#include "cursor.hpp"
#include "image.hpp"
#include "text.hpp"

enum weather {
    CLEAR,
    RAIN,
    STORM
};

class Map {
    public:
        Map() = default;
        Map(sf::Vector2i pos, int y, int x, bool isInteractive = true);
        ~Map() = default;
        void display(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> itemsImages) const;
        void display(std::shared_ptr<sf::RenderWindow> window) const;
        void update(float time, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Cursor> cursor, sf::View mapView);
        void update(float time);
        std::shared_ptr<Tile> getTile(int x, int y) const;
        std::pair<int, int> getSize() const;
    private:
        int _x;
        int _y;
        sf::Vector2i _pos;
        std::vector<std::vector<std::shared_ptr<Tile>>> _tiles;
        weather _weather;
        bool _isInteractive;
};
