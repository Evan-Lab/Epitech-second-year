/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** false
*/

#include "model/component/false.hpp"

namespace nts {

    Tristate My_False::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });
        return (nts::Tristate::False);

    }
    void My_False::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });
        check_and_throw_if_used_pin(pin);
        _links.emplace(pin, Link(other_pin, other));
    }

}