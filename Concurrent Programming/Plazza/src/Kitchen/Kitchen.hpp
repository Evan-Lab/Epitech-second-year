/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    #include "../Utils/Clock.hpp"
    #include "../Pizza/Americana.hpp"
    #include "../Pizza/Regina.hpp"
    #include "../Pizza/Fantasia.hpp"
    #include "../Pizza/Margarita.hpp"
    #include "../Utils/IPC.hpp"

    #include <mutex>
    #include <thread>
    #include <condition_variable>
    #include <sys/types.h>
    #include <unistd.h>
    #include <iostream>
    #include <signal.h>

namespace Plazza
{
    class Kitchen
    {
    public:
        Kitchen(pid_t pid, int nb_cooks, long double time);
        ~Kitchen();

        int getNumberCommand() const;
        void assign_cooks();
        void addPizza(std::shared_ptr<IPizza> pizza);
        void execute();

    private:
        pid_t _pid;
        bool _status;
        int _nb_cooks;
        long double _time;
        std::vector<std::thread> _threads;
        Clock _clock;
        std::vector<std::shared_ptr<IPizza>> _listPizza;
        IPC _ipc;

        struct Ingredient
        {
            PizzaIngredient ingredient;
            int number;
        };
        std::vector<Ingredient> _listIngredient;

        void cook(std::shared_ptr<IPizza> pizza);
        void regenIngredient();

        void deletePizza(int id);
    };
}

#endif /* !KITCHEN_HPP_ */
