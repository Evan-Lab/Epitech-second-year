/*
** EPITECH PROJECT, 2023
** POOL
** File description:
** DisplayText
*/

#pragma once

#include "../abstract/ADisplay.hpp"
#include "../interfaces/IModule.hpp"

class DisplayText : public ADisplay {

    public:
        DisplayText(std::size_t height, std::size_t width) : ADisplay(height, width) {};
        ~DisplayText();

        const void displayMods() const override {};

    private:
        std::vector <IModule *> _modules;
};
