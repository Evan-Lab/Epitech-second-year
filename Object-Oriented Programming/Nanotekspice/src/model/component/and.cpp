/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** And_nts
*/

#include "model/component/and.hpp"
#include "model/logic.hpp"

namespace nts {

    Tristate And::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 3 });
        Tristate state_1 = compute_linked_component(1);
        Tristate state_2 = compute_linked_component(2);
        return Logic::compute_and(state_1, state_2);
    }

    void And::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1, 2, 3 });
        check_and_throw_if_used_pin(pin);
        _links.emplace(pin, Link(other_pin, other));
    }

}
