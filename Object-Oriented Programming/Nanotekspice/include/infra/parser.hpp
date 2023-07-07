/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** parser
*/

#pragma once

#include "model/circuit.hpp"

#include <istream>

namespace nts {

    class Parser {
    public:
        static Circuit parse(std::istream &stream);
    };

}