/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** exception
*/

#pragma once

#include <exception>
#include <string>

namespace nts {

    class Exception: public std::exception {
    public:
        Exception(const std::string &message);
        const char *what() const noexcept override;

    private:
        std::string _message;
    };

}