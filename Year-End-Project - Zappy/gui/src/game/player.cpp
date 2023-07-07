/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** player
*/

#include "player.hpp"

Player::Player(std::pair<std::string, sf::Color> team, std::pair<int, int> coo, int id, std::string name) : _team(team), _coo(coo), _id(id), _name(name)
{
    _status = WAITING;
    _flag = std::make_shared<Sprite>("assets/images/flags_sheet.png", sf::Vector2i(310, 310), CENTER);
    _flag->setScale(0.4, 0.4);
    _flag->setColor(_team.second);
    _ship = std::make_shared<Sprite>("assets/images/ship_sheet.png", sf::Vector2i(310, 310), CENTER);
    _ship->setScale(0.4, 0.4);
    _ship->setColor(_team.second);
    _food = 10;
    _level = 1;
    _orientation = NORTH;
    _inventory = Inventory(PLAYER_INV);
}

void Player::display(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*_ship);
    window->draw(*_flag);
}

void Player::moveTo(sf::Vector2f pos, std::pair<int, int> coo)
{
    _flag->setPosition(pos);
    _ship->setPosition(pos);
    _coo = coo;
}

void Player::setHeight(int height)
{
    _flag->setPosition(_flag->getPosition().x, height);
    _ship->setPosition(_ship->getPosition().x, height);
}

void Player::setLevel(int level)
{
    _level = level;
    _flag->moveRectV((_level - 1) * 310);
}

void Player::setFood(int quantity)
{
    _food = quantity;
}

void Player::setOrientation(orientation orientation)
{
    _orientation = orientation;
    _ship->moveRectH((_orientation - 1) * 310);
    _flag->moveRectH((_orientation - 1) * 310);
}

std::pair<int, int> Player::getCoo() const
{
    return _coo;
}

std::pair<std::string, sf::Color> Player::getTeam() const
{
    return _team;
}

int Player::getLevel() const
{
    return _level;
}

int Player::getFood() const
{
    return _food;
}

Inventory Player::getInventory() const
{
    return _inventory;
}

int Player::getId() const
{
    return _id;
}

void Player::setInventory(std::vector<std::pair<objectType, int>> inventory)
{
    _inventory.setInventory(inventory);
}

std::string Player::getName() const
{
    return _name;
}
