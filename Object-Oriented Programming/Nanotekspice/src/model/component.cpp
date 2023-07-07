/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Component
*/


#include "model/component.hpp"

#include "cross_cutting/exception.hpp"

#include <algorithm>

namespace nts {

    void Component::check_and_throw_if_wrong_pin(std::size_t pin, std::vector <std::size_t>available_pins)
    {
        if (std::find(available_pins.begin(), available_pins.end(), pin) == available_pins.end()) {
            throw nts::Exception("Invalid pin:" + std::to_string(pin));
        }
    }

    void Component::check_and_throw_if_used_pin(std::size_t pin)
    {
        if (_links.contains(pin)) {
            throw nts::Exception("Pin already used:" + std::to_string(pin));
        }
    }

    Tristate Component::compute_linked_component(std::size_t pin)
    {
        return _links.contains(pin) ? _links.at(pin).compute() : Undefined;
    }

}