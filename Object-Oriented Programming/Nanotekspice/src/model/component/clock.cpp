/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** clock
*/

#include "model/component/clock.hpp"

namespace nts {

    Clock::Clock(Tristate &state) : _state(state)
    {
    }

    Tristate Clock::compute(std::size_t pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });

        switch (_state)
        {
        case Tristate::True:
            _state = Tristate::False;
            break;
        case Tristate::False:
            _state = Tristate::True;
            break;
        default:
            break;
        }
        return _state;
    }

    void Clock::setLink(std::size_t pin, IComponent &other, std::size_t other_pin)
    {
        check_and_throw_if_wrong_pin(pin, { 1 });
        _links.emplace(pin, Link(other_pin, other));
    }

}