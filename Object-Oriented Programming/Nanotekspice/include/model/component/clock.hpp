/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** clock
*/

#pragma once

#include "../component.hpp"
#include <stdbool.h>

namespace nts {

    class Clock : public Component {
    public:
        Clock(Tristate &state);
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t other_pin) override;
    private:
        Tristate &_state;
    };

}