/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** cursor
*/

#include "cursor.hpp"

Cursor::Cursor()
{
    _shape.setRadius(10);
    _shape.setOrigin(10, 10);
    _shape.setFillColor(sf::Color::Transparent);
    _shape.setOutlineColor(sf::Color::Black);
    _shape.setOutlineThickness(2);
    _target = nullptr;
    _hover = nullptr;
}

void Cursor::display(std::shared_ptr<sf::RenderWindow> window) const
{
    window->draw(_shape);
}

void Cursor::update(std::shared_ptr<sf::RenderWindow> window)
{
    _shape.setPosition(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    if (_hover)
        _hover->setHover(true);
    if (_target)
        _target->setTarget(true);
}

void Cursor::setTarget(std::shared_ptr<Tile> target)
{
    _target = target;
}

std::shared_ptr<Tile> Cursor::getTarget() const
{
    return _target;
}

void Cursor::setHover(std::shared_ptr<Tile> hover)
{
    _hover = hover;
}

std::shared_ptr<Tile> Cursor::getHover() const
{
    return _hover;
}
