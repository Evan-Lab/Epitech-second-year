/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** And_nts
*/

#pragma once

#include "../component.hpp"

namespace nts {

    class And: public Component {
    public:
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t other_pin) override;
    };

}
