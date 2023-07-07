/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** command_line_handler
*/

#pragma once

#include <fstream>

namespace nts {
    class Command_line_handler {
    public:
        static std::ifstream process_argument(int argc, char **argv);
    };
}