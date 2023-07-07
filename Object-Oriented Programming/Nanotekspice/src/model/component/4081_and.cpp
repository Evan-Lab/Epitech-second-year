/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** 4081_and
*/

#include "model/component/4081_and.hpp"
#include "model/logic.hpp"

namespace nts {

    Tristate And_4081::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 3, 4, 10, 11 });

        Tristate state_1;
        Tristate state_2;

        switch (pin) {
        case 3:
            state_1 = compute_linked_component(1);
            state_2 = compute_linked_component(2);
            break;
        case 4:
            state_1 = compute_linked_component(5);
            state_2 = compute_linked_component(6);
            break;
        case 10:
            state_1 = compute_linked_component(8);
            state_2 = compute_linked_component(9);
            break;
        case 11:
            state_1 = compute_linked_component(12);
            state_2 = compute_linked_component(13);
            break;
        default:
            return (nts::Tristate::Undefined);
        }
        return (Logic::compute_and(state_1, state_2));
    }

    void And_4081::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13 });
        check_and_throw_if_used_pin(pin);
        _links.emplace(pin, Link(other_pin, other));
    }
}
