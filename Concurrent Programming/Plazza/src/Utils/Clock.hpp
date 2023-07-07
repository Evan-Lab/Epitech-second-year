/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** clock
*/

#ifndef CLOCK_HPP_
    #define CLOCK_HPP_

    #include <chrono>
    #include <unistd.h>
    #include <time.h>

typedef long double second_t;

namespace Plazza
{
    class Clock
    {
    public:
        Clock();
        ~Clock();
        second_t tick();
        long double getElapsedTime() const;
        void reset();

    private:
        second_t _second;
        std::chrono::high_resolution_clock::time_point _time;
    };
}

#endif /* !CLOCK_HPP_ */