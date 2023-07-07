/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** string_utils
*/

#include "cross_cutting/string_utils.hpp"

#include "cross_cutting/exception.hpp"

namespace nts {

    std::pair<std::string, std::string> String_utils::split(const std::string &str, char delimiter)
    {
        size_t pos = str.find(delimiter);
        if (pos == std::string::npos) {
            throw Exception("String_utils::split: delimiter not found");
        }
        return std::make_pair(str.substr(0, pos), str.substr(pos + 1));
    }
}
