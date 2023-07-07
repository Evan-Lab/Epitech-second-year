/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** simulation
*/

#include "presentation/simulation.hpp"

#include "cross_cutting/string_utils.hpp"

#include <iostream>

namespace {

    char tristate_to_char(nts::Tristate state)
    {
        switch (state) {
        case nts::Tristate::True:
            return '1';
        case nts::Tristate::False:
            return '0';
        case nts::Tristate::Undefined:
        default:
            return 'U';
        }
    }
    nts::Tristate char_to_tristate(char state)
    {
        switch (state) {
        case '1':
            return nts::Tristate::True;
        case '0':
            return nts::Tristate::False;
        case 'U':
        default:
            return nts::Tristate::Undefined;
        }
    }

}

namespace nts {

    Simulation::Simulation(Circuit &circuit) : _circuit(circuit)
    {
    }

    void Simulation::display()
    {
        std::cout << "tick: " << tick << std::endl;
        std::cout << "input(s):" << std::endl;
        for (const auto &[name, state] : _circuit._inputs) {
            std::cout << "  " << name << ": " << tristate_to_char(state) << std::endl;
        }
        std::cout << "output(s):" << std::endl;
        for (const auto &[name, state] : _circuit._outputs) {
            std::cout << "  " << name << ": " << tristate_to_char(state) << std::endl;
        }
    }

    void Simulation::simulate()
    {
        tick++;
        for (auto &[name, state] : _circuit._outputs) {
            state = _circuit._chipsets.at(name)->compute(1);
        }
    }


    void Simulation::set_input(const std::string &user_input)
    {
        auto [input_name, state] = String_utils::split(user_input, '=');
        if (!_circuit._inputs.contains(input_name)) {
            std::cout << "Unknown input" << std::endl;
            return;
        }
        _circuit._inputs[input_name] = char_to_tristate(state[0]);
    }

    void Simulation::run_loop()
    {
        simulate();
        tick = 0;
        std::string user_input;

        while (true) {
            std::cout << "> ";
            std::getline(std::cin, user_input);
            if (std::cin.eof()) {
                return;
            }
            if (user_input == "exit") {
                return;
            } else if (user_input == "display") {
                display();
            } else if (user_input == "simulate") {
                simulate();
            } else if (user_input == "loop") {
                while (true) {
                    simulate();
                    display();
                }
            } else if (user_input.find('=') != std::string::npos) {
                set_input(user_input);
            } else {
                std::cout << "Unknown command" << std::endl;
            }
        }
    }
}
