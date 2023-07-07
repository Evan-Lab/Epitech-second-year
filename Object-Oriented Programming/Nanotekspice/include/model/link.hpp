/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** link
*/

#pragma once

#include "IComponent.hpp"

namespace nts {
    class Link {
    public:
        Link(std::size_t pin, IComponent &component);
        Tristate compute();
    private:
        std::size_t _pin;
        IComponent &_component;
    };
}