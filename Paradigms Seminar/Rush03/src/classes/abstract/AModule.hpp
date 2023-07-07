/*
** EPITECH PROJECT, 2023
** POOL
** File description:
** AModule
*/

#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "../interfaces/IModule.hpp"
#include "../data/Data.hpp"

class AModule : public IModule {

    public:

    private:
        Data _data;

        sf::RectangleShape _globalCard;
        sf::RectangleShape _valueCard;

        int _displayPosX;
        int _displayPosY;
        int _displayHeight;
        int _displayWidth;
};
