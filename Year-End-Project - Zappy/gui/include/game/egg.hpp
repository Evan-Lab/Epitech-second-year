/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** egg
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "image.hpp"
#include "text.hpp"

class Egg {
    public:
        Egg(int id, std::pair<std::string, sf::Color> team, std::pair<int, int> coo);
        ~Egg() = default;
        int getId() const;
        std::pair<std::string, sf::Color> getTeam() const;
        std::pair<int, int> getCoo() const;
        void displayOnTile(sf::Vector2f pos, std::shared_ptr<sf::RenderWindow> window);
        std::shared_ptr<Image> getImage() const;
    private:
        int _id;
        std::pair<std::string, sf::Color> _team;
        std::pair<int, int> _coo;
        sf::Vector2f _pos;
        std::shared_ptr<Image> _image;
};
