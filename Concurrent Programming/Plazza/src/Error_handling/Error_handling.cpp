/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Error_handling
*/

#include "Error_handling.hpp"

namespace Plazza {

    Error_handling::Error_handling(int argc, char **argv)
    {
        if (check_arg(argc, argv) == 84)
            throw Error_handling_exception("Wrong parameters -> ./Plazza [multiplier] [nb_cooks] [time]");
    }

    Error_handling::~Error_handling()
    {
    }

    int Error_handling::check_if_number(char **argv)
    {
        try {
            if (std::atoi(argv[1]) <= 0)
                return 84;
            if (std::atoi(argv[2]) <= 0)
                return 84;
            if (std::atoi(argv[3]) <= 0)
                return 84;
        }
        catch (const Error_handling_exception &e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }
        return 0;
    }

    int Error_handling::check_arg(int argc, char **argv)
    {
        try {
            if (argc != 4)
                return 84;
        }
        catch (const Error_handling_exception &e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }
        if (check_if_number(argv) == 84)
            return 84;
        return 0;
    }

    Error_handling_exception::Error_handling_exception(std::string msg)
    {
        _msg = "[ParametersError] " + msg;
    }

    const char *Error_handling_exception::what() const noexcept
    {
        return _msg.c_str();
    }

}