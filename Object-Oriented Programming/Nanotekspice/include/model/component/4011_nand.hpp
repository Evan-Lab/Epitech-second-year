/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** 4011_nad
*/

#pragma once

#include "../component.hpp"

namespace nts {

    class Nand_4011: public Component {
    public:
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t other_pin) override;
    };

}