/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** circuit
*/

#pragma once

#include "IComponent.hpp"

#include <memory>
#include <string>
#include <vector>
#include <map>

namespace nts {

    struct Circuit {
        std::map <std::string, std::unique_ptr<IComponent>> _chipsets;
        std::map <std::string, Tristate> _inputs;
        std::map <std::string, Tristate> _outputs;

        void add_chipset(const std::string &type, const std::string &name);
    };


}