/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** button
*/

#include "button.hpp"

Button::Button(std::string text, sf::Vector2f pos, int size, anchor anchor)
{
    _rect = Rectangle(sf::Vector2f(text.length() * size * 0.6, 120 * size / 100));
    _rect.setAnchor(anchor);
    _rect.setPosition(pos);
    _rect.setFillColor(sf::Color(randInt(0, 255), randInt(0, 255), randInt(0, 255), 200));
    _rect.setOutlineThickness(6);
    _rect.setOutlineColor(sf::Color::Transparent);
    sf::FloatRect rectBounds = _rect.getGlobalBounds();
    _text = std::make_shared<Text>(text, sf::Vector2f(rectBounds.left + rectBounds.width / 2, rectBounds.top + rectBounds.height / 2), size, CENTER);
    _text->setFillColor(sf::Color::White);
    _lastUpdate = 0;
    _isHover = false;
    _isActive = NONE;
}

void Button::update(sf::Vector2i mousePos, float time)
{
    if (_lastUpdate + 1000 <= time) {
        _rect.setFillColor(sf::Color(randInt(0, 255), randInt(0, 255), randInt(0, 255), 200));
        _lastUpdate = time;
    }
    if (collisionPoint(mousePos, _rect.getGlobalBounds())) {
        _rect.setOutlineColor(sf::Color(155, 155, 155));
        _isHover = true;
    } else if (_isActive == NONE) {
        _rect.setOutlineColor(sf::Color::Transparent);
        _isHover = false;
    } else {
        _rect.setOutlineColor((_isActive == ACTIVE) ? sf::Color::Green : sf::Color::Red);
        _isHover = false;
    }
}

void Button::display(std::shared_ptr<sf::RenderWindow> window) const
{
    window->draw(_rect);
    window->draw(*_text);
}

bool Button::isHover() const
{
    return _isHover;
}

buttonStatus Button::isActive() const
{
    return _isActive;
}

void Button::setActive(buttonStatus active)
{
    _isActive = active;
}
