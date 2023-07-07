/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_

    #include "../Pizza/APizza.hpp"
    #include "../Parser/Parser.hpp"
    #include "../Pizza/Americana.hpp"
    #include "../Pizza/Regina.hpp"
    #include "../Pizza/Fantasia.hpp"
    #include "../Pizza/Margarita.hpp"
    #include "../Kitchen/Kitchen.hpp"

    #include <iostream>
    #include <unistd.h>
    #include <vector>
    #include <sys/types.h>
    #include <exception>

namespace Plazza
{

    class Reception
    {
    public:
        Reception(double factor, int nb_cooks, long double time/*, IPC ipc*/);
        ~Reception();

        void create_loop();
        void create_kitchen(long double time);
        void assign(std::vector<std::shared_ptr<IPizza>> pizza, long double time);

    private:
        std::vector<std::shared_ptr<IPizza>> convertCommand(Command cmd, long double time);
        std::vector<std::shared_ptr<IPizza>> _pizza;
        std::vector<std::vector<std::shared_ptr<IPizza>>> _command;
        double _factor;
        int _nb_cooks;
        long double _time;

        // std::vector<std::shared_ptr<Kitchen>> _kitchen;
        std::vector<pid_t> _listPid;
        IPC _ipc;
    };

    class Exception : public std::exception
    {
    public:
        Exception(std::string msg);
        const char *what() const noexcept override;

    private:
        std::string _message;
    };

};

#endif /* !RECEPTION_HPP_ */
