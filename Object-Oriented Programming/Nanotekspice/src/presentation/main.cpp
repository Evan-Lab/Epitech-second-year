/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** main.cpp
*/

#include "model/circuit.hpp"
#include "infra/command_line_handler.hpp"
#include "cross_cutting/exception.hpp"
#include "infra/parser.hpp"
#include "presentation/simulation.hpp"

#include <iostream>

int main(int argc, char **argv)
{
  try {
    std::ifstream stream = nts::Command_line_handler::process_argument(argc, argv);
    nts::Circuit circuit = nts::Parser::parse(stream);
    nts::Simulation(circuit).run_loop();
  }
  catch (const nts::Exception &ex) {
    std::cerr << ex.what() << std::endl;
    return 84;
  }
  catch (const std::exception &ex) {
    std::cerr << "Unhandled exception: " << ex.what() << std::endl;
    return 84;
  }
  return 0;
}
