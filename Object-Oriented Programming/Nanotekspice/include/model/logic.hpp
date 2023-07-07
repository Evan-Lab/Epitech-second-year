/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** logic
*/

#pragma once

#include "IComponent.hpp"

namespace nts {

    class Logic {
    public:
        static Tristate compute_and(Tristate state_1, Tristate state_2);
        static Tristate compute_nand(Tristate state_1, Tristate state_2);
        static Tristate compute_or(Tristate state_1, Tristate state_2);
        static Tristate compute_nor(Tristate state_1, Tristate state_2);
        static Tristate compute_xor(Tristate state_1, Tristate state_2);
        static Tristate compute_and_or_not(Tristate state_1, Tristate state_2, Tristate state_3);

        static Tristate compute_not(Tristate state);
    };

}