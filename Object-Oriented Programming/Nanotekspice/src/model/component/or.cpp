/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** or
*/

#include "model/component/or.hpp"
#include "model/logic.hpp"

namespace nts {

    Tristate Or::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 3 });
        Tristate state_1 = compute_linked_component(1);
        Tristate state_2 = compute_linked_component(2);
        return Logic::compute_or(state_1, state_2);
    }

    void Or::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1, 2, 3 });
        _links.emplace(pin, Link(other_pin, other));
    }
}