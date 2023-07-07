/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** not
*/

#include "model/component/not.hpp"
#include "model/logic.hpp"

namespace nts {

    Tristate Not::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 2 });
        Tristate state_1 = compute_linked_component(1);
        return Logic::compute_not(state_1);
    }

    void Not::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        check_and_throw_if_wrong_pin(pin, { 1, 2 });
        _links.emplace(pin, Link(otherPin, other));
    }

}