/*
** EPITECH PROJECT, 2023
** POOL
** File description:
** DisplayGraph
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "../abstract/ADisplay.hpp"
#include "../interfaces/IModule.hpp"

class DisplayGraph : public ADisplay {

    public:
        DisplayGraph(size_t height, size_t width) : ADisplay(height, width) {};
        ~DisplayGraph();

        const void displayMods() const override {};

    private:
        sf::RenderWindow _window;
};
