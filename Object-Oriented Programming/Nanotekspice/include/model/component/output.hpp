/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** output
*/

#pragma once

#include "../component.hpp"

namespace nts {

    class Output: public Component {
    public:
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t other_pin) override;
    };

}