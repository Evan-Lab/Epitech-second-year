/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** IPC
*/

#ifndef IPC_HPP_
    #define IPC_HPP_

    #include <string>
    #include <exception>
    #include <iostream>
    #include <sys/msg.h>
    #include <sys/ipc.h>
    #include <memory>

    #include "../Parser/Parser.hpp"
    #include "../Pizza/Americana.hpp"
    #include "../Pizza/Fantasia.hpp"
    #include "../Pizza/Margarita.hpp"
    #include "../Pizza/Regina.hpp"
    #include "../Pizza/IPizza.hpp"
    #include "Clock.hpp"

namespace Plazza
{
    struct CommandPizza
    {
        PizzaType typePizza;
        PizzaSize sizePizza;
        std::shared_ptr<IPizza> stockPizza;
    };

    class Error : public std::exception
    {
    public:
        Error(std::string msg);
        ~Error();
        const char *what() const noexcept override;

    private:
        std::string _msg;
    };

    class IPC
    {
    public:
        IPC(const std::string &path, int id)
        {
            key_t key = ftok(path.c_str(), id);

            if (key == -1)
                throw Error("ftok failed");
            _msgId = msgget(key, IPC_CREAT | 0666);
            if (_msgId == -1)
                throw Error("msgget failed");
        };

        ~IPC(){};

        template <typename T>
        void send(T cmd, long type)
        {
            msg_buffer<T> msg_buff;

            msg_buff.mtype = type;
            msg_buff.cmd = cmd;

            int check = 0;

            //std::cout << "TYPE SEND: " << msg_buff.mtype << " " << type << " " << _msgId << std::endl;

            if ((check = msgsnd(_msgId, &msg_buff, sizeof(T), 0)) == -1)
                throw Error("msgsnd failed");

            //std::cout << "CHECK SEND: " << check << std::endl;
        };

        template <typename T>
        T receive(int timeout, long type)
        {
            Clock clock;
            long double elapsedTime = 0.0;
            msg_buffer<T> msg_buff;

           // std::cout << "TYPE RECEIVE: " << type << " " << _msgId << std::endl;

            // while (elapsedTime < timeout)
            // {
           // std::cout << "in while" << std::endl;
            if (msgrcv(_msgId, &msg_buff, sizeof(T), type, 0) != -1)
            {
                return msg_buff.cmd;
            }
           // std::cout << "after if" << std::endl;
            //         elapsedTime = clock.tick();
            // }

            throw Error("Receive timeout");
        };

    private:
        template <typename T>
        struct msg_buffer
        {
            long mtype;
            // CommandPizza cmd;
            T cmd;
        };
        int _id;
        int _msgId;
        Clock _clock;
    };
}

#endif /* !IPC_HPP_ */