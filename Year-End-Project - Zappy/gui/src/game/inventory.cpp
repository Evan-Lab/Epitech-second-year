/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** inventory
*/

#include "inventory.hpp"

Inventory::Inventory(inventoryType type) : _type(type)
{
    _objects.push_back(std::make_pair(LINEMATE, 0));
    _objects.push_back(std::make_pair(DERAUMERE, 0));
    _objects.push_back(std::make_pair(SIBUR, 0));
    _objects.push_back(std::make_pair(MENDIANE, 0));
    _objects.push_back(std::make_pair(PHIRAS, 0));
    _objects.push_back(std::make_pair(THYSTAME, 0));
    if (_type == TILE_INV)
        _objects.push_back(std::make_pair(MILK, 0));
    setPos(sf::Vector2f(0, 0));
}

void Inventory::setQuantity(objectType type, int quantity)
{
    _objects[type].second = quantity;
}

int Inventory::getQuantity(objectType type) const
{
    return _objects[type].second;
}

void Inventory::displayForHud(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> itemsImages, std::shared_ptr<Image> egg) const
{
    int max = (_type == TILE_INV) ? 7 : 6;

    for (int i = 0; i < max; i++) {
        itemsImages[i].first->setScale(sf::Vector2f(0.1, 0.1));
        itemsImages[i].first->setPosition(_pos.x - 10 + (40 * i), _pos.y);
        itemsImages[i].second->setString(std::to_string(_objects[i].second));
        itemsImages[i].second->setPosition(_pos.x - 10 + (40 * i + 14), _pos.y + 10);
        window->draw(*itemsImages[i].first);
        window->draw(*itemsImages[i].second);
    }
    if (egg) {
        egg->setPosition(_pos.x - 10 + (40 * max), _pos.y);
        window->draw(*egg);
    }
}

void Inventory::displayForTile(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> itemsImages) const
{
    for (int i = 0; i < 7; i++) {
        if (_objects[i].second == 0)
            continue;
        itemsImages[i].first->setScale(sf::Vector2f(0.08, 0.08));
        if (i <= 3)
            itemsImages[i].first->setPosition(_pos.x - 70 + 22 * i, _pos.y + 45 + i * 9);
        else
            itemsImages[i].first->setPosition(_pos.x - 70 + 22 * i, _pos.y + 80 + (7 - i - 4) * 9);
        window->draw(*itemsImages[i].first);
    }
}

void Inventory::setPos(sf::Vector2f pos)
{
    _pos = pos;
}

void Inventory::setType(inventoryType type)
{
    _type = type;
}

void Inventory::setInventory(std::vector<std::pair<objectType, int>> inventory)
{
    _objects = inventory;
}
