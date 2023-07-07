/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** egg
*/

#include "egg.hpp"

Egg::Egg(int id, std::pair<std::string, sf::Color> team, std::pair<int, int> coo) : _id(id), _team(team), _coo(coo)
{
    _image = std::make_shared<Image>("assets/images/egg.png", CENTER);
    _image->setScale(sf::Vector2f(0.1, 0.1));
    _image->setColor(team.second);
}

int Egg::getId() const
{
    return _id;
}

std::pair<int, int> Egg::getCoo() const
{
    return _coo;
}

std::pair<std::string, sf::Color> Egg::getTeam() const
{
    return _team;
}

void Egg::displayOnTile(sf::Vector2f pos, std::shared_ptr<sf::RenderWindow> window)
{
    _image->setPosition(pos.x - 70 + 22 * 7, pos.y + 80 + 4 * -9);
    window->draw(*_image);
}

std::shared_ptr<Image> Egg::getImage() const
{
    return _image;
}
