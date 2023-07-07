/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** textInput
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "text.hpp"
#include "tools.hpp"
#include "enum.hpp"
#include "rectangle.hpp"

class TextInput {
    public:
        TextInput() = default;
        TextInput(std::string prompt, sf::Vector2f pos, inputType type);
        ~TextInput() = default;
        void update(sf::Vector2i mousePos, float time);
        void display(std::shared_ptr<sf::RenderWindow> window) const;
        void manageEvent(sf::Event event);
        bool isHover() const;
        void setFocus(bool focus);
        bool isFocus() const;
        sf::FloatRect getGlobalBounds() const;
        std::string getInput() const;
    private:
        std::shared_ptr<Text> _prompt;
        std::shared_ptr<Text> _input;
        Rectangle _box;
        Rectangle _inputRect;
        float _lastUpdate;
        bool _isHover;
        bool _isFocus;
        int _maxInput;
        inputType _type;
};
