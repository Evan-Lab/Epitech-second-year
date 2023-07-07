/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** not
*/

#pragma once

#include "../component.hpp"

namespace nts {

    class Not: public Component {
    public:
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
    };
}