/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** input_output
*/

#include "model/component/input_output.hpp"

namespace nts {

    Tristate Input_Output::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 2 });
        Tristate state = compute_linked_component(2);
        return state;
    }
    void Input_Output::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        check_and_throw_if_wrong_pin(pin, { 1, 2 });
        _links.emplace(pin, Link(otherPin, other));
    }

}
