/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** exception
*/

#include "cross_cutting/exception.hpp"

namespace nts {

    Exception::Exception(const std::string &message)
    {
        _message = "[ERROR] " + message;
    }

    const char *Exception::what() const noexcept
    {
        return _message.c_str();
    }

}

//Faut gérer le cas ou les links et name c'est n'importe quoi
