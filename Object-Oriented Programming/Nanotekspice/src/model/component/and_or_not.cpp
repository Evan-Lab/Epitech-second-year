/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** and_or_not
*/

#include "model/component/and_or_not.hpp"
#include "model/logic.hpp"

namespace nts {

    Tristate And_or_not::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 3, 6, 8, 11 });
        Tristate state_1;
        Tristate state_2;

        switch (pin) {
        case 3:
            state_1 = compute_linked_component(1);
            state_2 = compute_linked_component(2);
            break;
        case 6:
            state_1 = compute_linked_component(4);
            state_2 = compute_linked_component(5);
            break;
        case 8:
            state_1 = compute_linked_component(9);
            state_2 = compute_linked_component(10);
            break;
        case 11:
            state_1 = compute_linked_component(12);
            state_2 = compute_linked_component(13);
            break;
        default:
            return (nts::Tristate::Undefined);
        }
        return (Logic::compute_and_or_not(state_1, state_2, compute_linked_component(7)));
    }

    void And_or_not::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1, 2, 3, 4, 5, 6, 8, 9, 10 });
        check_and_throw_if_used_pin(pin);
        _links.emplace(pin, Link(other_pin, other));
    }

}