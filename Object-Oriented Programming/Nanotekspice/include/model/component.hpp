/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Component
*/

#pragma once

#include "IComponent.hpp"
#include "link.hpp"

#include <map>
#include <string>
#include <vector>

namespace nts {

    class Component: public IComponent {
    public:
        //Component(std::string &name, std::string &type);
        virtual ~Component() = default;

    protected:
        std::map<std::size_t, Link> _links;

        void check_and_throw_if_wrong_pin(std::size_t pin, std::vector<std::size_t> available_pins);
        void check_and_throw_if_used_pin(std::size_t pin);
        Tristate compute_linked_component(std::size_t pin);
    };

}
