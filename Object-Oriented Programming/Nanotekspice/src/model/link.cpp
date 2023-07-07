/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** link
*/

#include "model/link.hpp"

namespace nts {

    Link::Link(std::size_t pin, IComponent &component): _pin(pin), _component(component)
    {
    }
    Tristate Link::compute()
    {
        return _component.compute(_pin);
    }
}