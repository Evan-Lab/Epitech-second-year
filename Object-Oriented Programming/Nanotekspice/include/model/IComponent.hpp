/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** IComponent
*/

#pragma once

#include <cstdint>

namespace nts {

    enum Tristate {
        Undefined,
        True,
        False
    };

    class IComponent {
    public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t) {}
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin) = 0;
    };

}