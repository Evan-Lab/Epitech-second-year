/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** image
*/

#include "image.hpp"

Image::Image(std::string path, anchor anchor)
{
    if (!_texture.loadFromFile(path))
        return;
    setTexture(_texture);
    setAnchor(anchor);
}

void Image::setAnchor(anchor anchor)
{
    sf::FloatRect dim = getLocalBounds();

    if (anchor == TOPLEFT) {
        setOrigin(0, 0);
    } else if (anchor == TOPRIGHT) {
        setOrigin(dim.width, 0);
    } else if (anchor == BOTTOMLEFT) {
        setOrigin(0, dim.height);
    } else if (anchor == BOTTOMRIGHT) {
        setOrigin(dim.width, dim.height);
    } else if (anchor == CENTER) {
        setOrigin(dim.left + dim.width / 2.0f, dim.top + dim.height / 2.0f);
    }
}
