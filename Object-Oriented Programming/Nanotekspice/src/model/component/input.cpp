/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** input
*/

#include "model/component/input.hpp"

namespace nts {

    Input::Input(Tristate &state): _state(state)
    {
    }

    Tristate Input::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });
        return _state;

    }

    void Input::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });
        check_and_throw_if_used_pin(pin);
        _links.emplace(pin, Link(other_pin, other));
    }
}
