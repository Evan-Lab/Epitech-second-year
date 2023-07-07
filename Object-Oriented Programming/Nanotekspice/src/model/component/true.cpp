/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** true
*/

#include "model/component/true.hpp"

namespace nts {

    Tristate My_True::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });
        return (nts::Tristate::True);
    }

    void My_True::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });
        _links.emplace(pin, Link(other_pin, other));
    }

}
