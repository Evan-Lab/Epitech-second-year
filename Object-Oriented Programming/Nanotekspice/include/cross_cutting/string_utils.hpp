/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** string_utils
*/

#pragma once

#include <string>

namespace nts {

    class String_utils {
        public:
        static std::pair<std::string, std::string> split(const std::string &str, char delimiter);
    };

}