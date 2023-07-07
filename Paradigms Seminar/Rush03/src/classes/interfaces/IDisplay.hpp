/*
** EPITECH PROJECT, 2023
** POOL
** File description:
** IDisplay
*/


#pragma once

#include <vector>
#include "IModule.hpp"

class IDisplay {
    public:
        IDisplay() = default;
        virtual ~IDisplay() = default;

        virtual const void displayMods() const = 0;
};
