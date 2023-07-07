/*
** EPITECH PROJECT, 2023
** POOL
** File description:
** ADisplay
*/

#pragma once


#include "../interfaces/IDisplay.hpp"
#include "../interfaces/IModule.hpp"

class ADisplay : public IDisplay {

    public:
        ADisplay(std::size_t height, std::size_t width) : IDisplay(), _height(height), _width(width) {};
        ~ADisplay();

        const void displayMods() const override {};

    private:
        std::size_t _height;
        std::size_t _width;
};
