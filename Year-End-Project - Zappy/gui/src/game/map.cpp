/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** map
*/

#include "map.hpp"

Map::Map(sf::Vector2i pos, int y, int x, bool isInteractive) : _x(x), _y(y), _isInteractive(isInteractive)
{
    _pos = pos;
    for (int l = 0; l < y; l++) {
        std::vector<std::shared_ptr<Tile>> tmp;
        for (int c = 0; c < x; c++) {
            tmp.push_back(std::make_shared<Tile>(sf::Color(WATER_COLOR), sf::Vector2f((l - c) * (TILE_SIZE / 4) + _pos.x, (l + c) * (TILE_SIZE / 8) + _pos.y), std::pair<int, int>(l, c)));
        }
        _tiles.push_back(tmp);
    }
}

void Map::display(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> itemsImages) const
{
    for (int i = 0; i < _y; i++)
        for (int j = 0; j < _x; j++)
            _tiles[i][j]->display(window, itemsImages);
}

void Map::display(std::shared_ptr<sf::RenderWindow> window) const
{
    for (int i = 0; i < _y; i++)
        for (int j = 0; j < _x; j++)
            _tiles[i][j]->display(window);
}

std::pair<int, int> Map::getSize() const
{
    return std::make_pair(_x, _y);
}

void Map::update(float time, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Cursor> cursor, sf::View mapView)
{
    cursor->setHover(nullptr);
    for (int i = 0; i < _y; i++)
        for (int j = 0; j < _x; j++) {
            _tiles[i][j]->update(time);
            if (_tiles[i][j]->checkCollision(window, mapView)) {
                cursor->setHover(_tiles[i][j]);
            }
    }
}

void Map::update(float time)
{
    for (int i = 0; i < _y; i++)
        for (int j = 0; j < _x; j++)
            _tiles[i][j]->update(time);
}

std::shared_ptr<Tile> Map::getTile(int x, int y) const
{
    return (_tiles[x][y]);
}
