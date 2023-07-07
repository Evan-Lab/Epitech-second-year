/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** rectangle
*/

#include "rectangle.hpp"

Rectangle::Rectangle(sf::Vector2f size, anchor anchor) : sf::RectangleShape(size)
{
    setAnchor(anchor);
};

void Rectangle::setAnchor(anchor anchor)
{
    if (anchor == TOPLEFT)
        setOrigin(0, 0);
    else if (anchor == TOPRIGHT)
        setOrigin(getSize().x, 0);
    else if (anchor == BOTTOMLEFT)
        setOrigin(0, getSize().y);
    else if (anchor == BOTTOMRIGHT)
        setOrigin(getSize().x, getSize().y);
    else if (anchor == CENTER)
        setOrigin(getSize().x / 2, getSize().y / 2);
}
