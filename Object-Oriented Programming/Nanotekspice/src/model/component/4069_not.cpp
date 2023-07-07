/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** 4069_not
*/

#include "model/component/4069_not.hpp"
#include "model/logic.hpp"

namespace nts {

    Tristate Not_4069::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 2, 4, 6, 8, 10, 12 });

        Tristate state;

        switch (pin) {
        case 2:
            state = compute_linked_component(1);
            break;
        case 4:
            state = compute_linked_component(3);
            break;
        case 6:
            state = compute_linked_component(5);
            break;
        case 8:
            state = compute_linked_component(9);
            break;
        case 10:
            state = compute_linked_component(11);
            break;
        case 12:
            state = compute_linked_component(13);
            break;
        default:
            return (nts::Tristate::Undefined);
        }
        return (Logic::compute_not(state));
    }

    void Not_4069::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13 });
        check_and_throw_if_used_pin(pin);
        _links.emplace(pin, Link(other_pin, other));
    }

}