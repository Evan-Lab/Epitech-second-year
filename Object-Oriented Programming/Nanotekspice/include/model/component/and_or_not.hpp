/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** and_or_not
*/

#pragma once

#include "../component.hpp"

namespace nts {

    class And_or_not: public Component {
    public:
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t other_pin) override;
    };

}