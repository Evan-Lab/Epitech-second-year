/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** part
*/

#include "part.hpp"

Part::Part(sf::Color color, sf::Vector2f pos, PartType type)
{
    float diagonalLength = TILE_SIZE / std::sqrt(2.f);
    float height = diagonalLength * std::sin(30 * M_PI / 180.f);

    _pos = pos;
    if (type == TOP) {
        _shape.setPointCount(4);
        _shape.setPoint(0, sf::Vector2f(pos.x, pos.y - height / 2));
        _shape.setPoint(1, sf::Vector2f(pos.x + TILE_SIZE / 2, pos.y));
        _shape.setPoint(2, sf::Vector2f(pos.x, pos.y + height / 2));
        _shape.setPoint(3, sf::Vector2f(pos.x - TILE_SIZE / 2, pos.y));
        _shape.setFillColor(color);
        _shape.setOutlineThickness(2);
    } else if (type == LEFT) {
        _shape.setPointCount(4);
        _shape.setPoint(0, sf::Vector2f(pos.x - TILE_SIZE / 2, pos.y)); //top left
        _shape.setPoint(1, sf::Vector2f(pos.x, pos.y + height / 2)); // top right
        _shape.setPoint(2, sf::Vector2f(pos.x, pos.y + height / 2 + diagonalLength - 25)); //bot right
        _shape.setPoint(3, sf::Vector2f(pos.x - TILE_SIZE / 2, pos.y + diagonalLength - 25)); //bot left
        _shape.setFillColor(sf::Color(color.r, color.g - 10, color.b - 10, color.a));
    } else if (type == RIGHT) {
        _shape.setPointCount(4);
        _shape.setPoint(0, sf::Vector2f(pos.x + TILE_SIZE / 2, pos.y)); //top left
        _shape.setPoint(1, sf::Vector2f(pos.x + TILE_SIZE / 2, pos.y + diagonalLength - 25)); //bot left
        _shape.setPoint(2, sf::Vector2f(pos.x, pos.y + height / 2 + diagonalLength - 25)); //bot right
        _shape.setPoint(3, sf::Vector2f(pos.x, pos.y + height / 2)); // top right
        _shape.setFillColor(sf::Color(color.r, color.g + 10, color.b + 10, color.a));
    }
    _isHover = false;
    _isTarget = false;
}

void Part::display(std::shared_ptr<sf::RenderWindow> window) const
{
    window->draw(_shape);
}

void Part::waveEffect(std::pair<int, int> wavePower)
{
    _shape.setPosition(_pos.x, _pos.y + wavePower.second * WAVE_VERTICAL_MULT);
}

bool Part::checkCollision(std::shared_ptr<sf::RenderWindow> window, sf::View mapView)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2f worldMousePosition = window->mapPixelToCoords(mousePosition, mapView);
    sf::FloatRect bounds = _shape.getGlobalBounds();
    if (!bounds.contains(worldMousePosition))
        return false;

    std::vector<sf::Vector2f> points;
    for (size_t i = 0; i < _shape.getPointCount(); ++i) {
        points.push_back(_shape.getTransform().transformPoint(_shape.getPoint(i)));
    }
    size_t count = _shape.getPointCount();

    for (size_t i = 0, j = count - 1; i < count; j = i++) {
        if (((points[i].y > worldMousePosition.y) != (points[j].y > worldMousePosition.y)) &&
            (worldMousePosition.x < (points[j].x - points[i].x) * (worldMousePosition.y - points[i].y) / (points[j].y - points[i].y) + points[i].x))
            return true;
    }
    return false;
}

void Part::setHover(bool hover)
{
    _isHover = hover;
}

void Part::setTarget(bool target)
{
    _isTarget = target;
}

void Part::update()
{
    if (_isTarget)
        _shape.setOutlineColor(sf::Color::White);
    else if (_isHover)
        _shape.setOutlineColor(sf::Color(155, 155, 155));
    else
        _shape.setOutlineColor(sf::Color::Transparent);
}

sf::Vector2f Part::getPos() const
{
    return _shape.getTransform().transformPoint(_shape.getPoint(0));
}
