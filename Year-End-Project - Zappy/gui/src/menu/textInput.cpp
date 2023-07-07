/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** textInput
*/

#include "textInput.hpp"

TextInput::TextInput(std::string prompt, sf::Vector2f pos, inputType type)
{
    int marginLeft = 10;
    int marginTop = 50;
    //background rectangle
    _box = Rectangle(sf::Vector2f(300, 100));
    sf::FloatRect boxDim = _box.getLocalBounds();
    _box.setAnchor(CENTER);
    _box.setPosition(pos);
    _box.setFillColor(sf::Color(0, 0, 0, 100));
    //input rectangle
    _inputRect = Rectangle(sf::Vector2f(280, 40));
    _inputRect.setPosition(pos.x - boxDim.width / 2 + marginLeft, pos.y - boxDim.height / 2 + marginTop);
    _inputRect.setFillColor(sf::Color(255, 255, 255, 255));
    _inputRect.setOutlineThickness(3);
    _inputRect.setOutlineColor(sf::Color::Transparent);
    //texts
    _prompt = std::make_shared<Text>(prompt, sf::Vector2f(pos.x - boxDim.width / 2 + marginLeft, pos.y - boxDim.height / 2), 35);
    _input = std::make_shared<Text>("", sf::Vector2f(pos.x - boxDim.width / 2 + marginLeft, pos.y - boxDim.height / 2 + marginTop), 35);
    //other
    _lastUpdate = 0;
    _isHover = false;
    _isFocus = false;
    _type = type;
    if (type == IP)
        _maxInput = 15;
    else if (type == PORT)
        _maxInput = 5;
}

void TextInput::update(sf::Vector2i mousePos, float time)
{
        if (_lastUpdate + 1000 <= time) {
        _box.setFillColor(sf::Color(randInt(0, 255), randInt(0, 255), randInt(0, 255), 200));
        _lastUpdate = time;
    }
    if (collisionPoint(mousePos, _inputRect.getGlobalBounds())) {
        _inputRect.setOutlineColor(sf::Color(155, 155, 155));
        _isHover = true;
    } else {
        _inputRect.setOutlineColor(sf::Color::Transparent);
        _isHover = false;
    }
    if (_isFocus)
        _inputRect.setOutlineColor(sf::Color::Black);
}

void TextInput::display(std::shared_ptr<sf::RenderWindow> window) const
{
    window->draw(_box);
    window->draw(_inputRect);
    window->draw(*_prompt);
    window->draw(*_input);
}

void TextInput::manageEvent(sf::Event event)
{
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 8 && _input->getString().toAnsiString().length() > 0)
            _input->setString(_input->getString().toAnsiString().substr(0, _input->getString().toAnsiString().length() - 1));
        else if (event.text.unicode < 128 && event.text.unicode != 8 && ((int) _input->getString().toAnsiString().length() < _maxInput || _maxInput == -1)) {
            if (_type == IP && ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 46))
                _input->setString(_input->getString() + static_cast<char>(event.text.unicode));
            else if (_type == PORT && event.text.unicode >= 48 && event.text.unicode <= 57)
                _input->setString(_input->getString() + static_cast<char>(event.text.unicode));
        }
    }
}

bool TextInput::isHover() const
{
    return _isHover;
}

void TextInput::setFocus(bool focus)
{
    _isFocus = focus;
    if (focus)
        _inputRect.setOutlineColor(sf::Color(0, 0, 0));
    else
        _inputRect.setOutlineColor(sf::Color::Transparent);
}

bool TextInput::isFocus() const
{
    return _isFocus;
}

sf::FloatRect TextInput::getGlobalBounds() const
{
    return _box.getGlobalBounds();
}

std::string TextInput::getInput() const
{
    return _input->getString();
}
