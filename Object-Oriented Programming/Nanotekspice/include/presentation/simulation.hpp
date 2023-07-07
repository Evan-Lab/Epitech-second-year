/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** simulation
*/

#pragma once

#include "model/circuit.hpp"

#include <cstdint>

namespace nts {

    class Simulation {
    public:
        Simulation(Circuit &circuit);
        void run_loop();

    private:
        Circuit &_circuit;
        std::size_t tick = 0;

        void display();
        void simulate();
        void set_input(const std::string &user_input);
    };

}