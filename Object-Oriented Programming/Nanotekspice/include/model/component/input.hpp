/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** input
*/

#pragma once

#include "../component.hpp"

namespace nts {

    class Input: public Component {
    public:
        Input(Tristate &state);
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t other_pin) override;
    private:
        Tristate &_state;
    };

}
