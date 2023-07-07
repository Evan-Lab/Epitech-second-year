/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** output
*/

#include "model/component/output.hpp"

#include "cross_cutting/exception.hpp"

namespace nts {

    Tristate Output::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });
        return compute_linked_component(pin);
    }

    void Output::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });
        check_and_throw_if_used_pin(pin);
        _links.emplace(pin, Link(other_pin, other));
    }

}
