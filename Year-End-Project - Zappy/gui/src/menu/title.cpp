/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** title
*/

#include "title.hpp"

Title::Title(sf::Vector2f pos)
{
    _text = std::make_shared<Text>("Chappy", pos, 100, CENTER);
    int width = _text->getGlobalBounds().width;
    _leftCat = std::make_shared<Text>("`", sf::Vector2f(pos.x - width / 1.2, pos.y), 100, CENTER);
    _rightCat = std::make_shared<Text>("`", sf::Vector2f(pos.x + width / 1.2, pos.y), 100, CENTER);
    _angle = 45;
    _lastUpdate = 0;
}

void Title::update(float time)
{
    if (_lastUpdate + 1000 <= time) {
        _angle = - _angle;
        _leftCat->setRotation(_angle);
        _rightCat->setRotation(_angle);
        randomColor();
        _lastUpdate = time;
    }
}

void Title::display(std::shared_ptr<sf::RenderWindow> window) const
{
    window->draw(*_text);
    window->draw(*_leftCat);
    window->draw(*_rightCat);
}

void Title::randomColor()
{
    sf::Color color = sf::Color(randInt(0, 255), randInt(0, 255), randInt(0, 255));
    _text->setFillColor(color);
    _leftCat->setFillColor(color);
    _rightCat->setFillColor(color);
}
