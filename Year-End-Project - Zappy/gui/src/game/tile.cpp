/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** tile
*/

#include "tile.hpp"
#include "variables.hpp"

Tile::Tile(sf::Color color, sf::Vector2f pos, std::pair<int, int> coo) : _color(color), _coo(coo)
{
    _inventory = Inventory(TILE_INV);
    _inventory.setPos(pos);
    _top = Part(color, pos, TOP);
    _left = Part(color, pos, LEFT);
    _right = Part(color, pos, RIGHT);
    _lastUpdateWave = 0;
    _wavePower = std::make_pair(1, static_cast<int>(WAVE_AMPLITUDE * std::sin(WAVE_FREQUENCY * pos.x)));
}

void Tile::display(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> itemsImages) const
{
    _left.display(window);
    _right.display(window);
    _top.display(window);
    _inventory.displayForTile(window, itemsImages);
}

void Tile::display(std::shared_ptr<sf::RenderWindow> window) const
{
    _left.display(window);
    _right.display(window);
    _top.display(window);
}

void Tile::update(float time)
{
    if (_lastUpdateWave + WAVE_SPEED < time) {
         waveEffect();
         _lastUpdateWave = time;
    }
    _top.update();
    _top.setHover(false);
    _top.setTarget(false);
    _inventory.setPos(_top.getPos());
}

void Tile::waveEffect()
{
    if (_wavePower.second >= WAVE_VERTICAL_STEP) {
        _wavePower.first = -1;
    } else if (_wavePower.second <= 0) {
        _wavePower.first = 1;
    }
    _wavePower.second += _wavePower.first;
    _top.waveEffect(_wavePower);
    _left.waveEffect(_wavePower);
    _right.waveEffect(_wavePower);
}

bool Tile::checkCollision(std::shared_ptr<sf::RenderWindow> window, sf::View mapView)
{
    return _top.checkCollision(window, mapView);
}

void Tile::setHover(bool isHover)
{
    _top.setHover(isHover);
}

void Tile::setTarget(bool isTarget)
{
    _top.setTarget(isTarget);
}

std::pair<int, int> Tile::getCoo() const
{
    return _coo;
}

Part Tile::getTopPart() const
{
    return _top;
}

sf::Vector2f Tile::getPos() const
{
    return _top.getPos();
}

void Tile::setInventory(objectType type, int quantity)
{
    _inventory.setQuantity(type, quantity);
}

Inventory Tile::getInventory() const
{
    return _inventory;
}
