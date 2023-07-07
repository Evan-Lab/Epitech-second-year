/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** logic
*/

#include "model/logic.hpp"

namespace nts {

    Tristate Logic::compute_and(Tristate state_1, Tristate state_2)
    {
        if (state_1 == Tristate::True && state_2 == Tristate::True) {
            return Tristate::True;
        } else if (state_1 == Tristate::False || state_2 == Tristate::False) {
            return Tristate::False;
        } else {
            return Tristate::Undefined;
        }
    }

    Tristate Logic::compute_nand(Tristate state_1, Tristate state_2)
    {
        return (compute_not(compute_and(state_1, state_2)));
    }

    Tristate Logic::compute_and_or_not(Tristate state_1, Tristate state_2, Tristate state_3)
    {
        return (compute_not(compute_or(compute_and(state_1, state_2), state_3)));
    }

    Tristate Logic::compute_or(Tristate state_1, Tristate state_2)
    {
        if (state_1 == Tristate::True || state_2 == Tristate::True) {
            return (nts::Tristate::True);
        } else if (state_1 == Tristate::False && state_2 == Tristate::False) {
            return (nts::Tristate::False);
        } else {
            return (nts::Tristate::Undefined);
        }
    }

    Tristate Logic::compute_nor(Tristate state_1, Tristate state_2)
    {
        return (compute_not(compute_or(state_1, state_2)));
    }

    Tristate Logic::compute_xor(Tristate state_1, Tristate state_2)
    {
        if (state_1 == Tristate::True && state_2 == Tristate::False) {
            return (nts::Tristate::True);
        } else if (state_1 == Tristate::False && state_2 == Tristate::True) {
            return (nts::Tristate::True);
        } else if (state_1 == Tristate::Undefined || state_2 == Tristate::Undefined) {
            return (nts::Tristate::Undefined);
        } else {
            return (nts::Tristate::False);
        }
    }

    Tristate Logic::compute_not(Tristate state)
    {
        switch (state) {
        case Tristate::True:
            return (nts::Tristate::False);
        case Tristate::False:
            return (nts::Tristate::True);
        case Tristate::Undefined:
        default:
            return (nts::Tristate::Undefined);
        }
    }

}
