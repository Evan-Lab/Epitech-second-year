/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Error_handling
*/

#ifndef ERROR_HANDLING_HPP_
    #define ERROR_HANDLING_HPP_

    #include <iostream>
    #include <string>
    #include <exception>

namespace Plazza {

    class Error_handling {
    public:
        Error_handling(int argc, char **argv);
        ~Error_handling();

        int check_arg(int argc, char **argv);
        int check_if_number(char **argv);
    };

    class Error_handling_exception : public std::exception {
    public:
        Error_handling_exception(std::string msg);

        const char *what() const noexcept override;
    private:
        std::string _msg;
    };
}

#endif /* !ERROR_HANDLING_HPP_ */