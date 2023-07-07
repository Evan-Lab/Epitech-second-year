/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** IPC
*/

#include "IPC.hpp"

namespace Plazza
{

    Error::Error(std::string msg) : _msg(msg)
    {
    }

    Error::~Error()
    {
    }

    const char *Error::what() const noexcept
    {
        return _msg.c_str();
    }

}
