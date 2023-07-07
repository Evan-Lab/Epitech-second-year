/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** clock
*/

#include "Clock.hpp"

namespace Plazza
{

    Clock::Clock()
    {
        reset();
        _second = 0;
    }

    Clock::~Clock()
    {
    }

    second_t Clock::tick()
    {
        long double elapsed = getElapsedTime();

        _second += elapsed / 10000;
        reset();

        return _second;
    }

    long double Clock::getElapsedTime() const
    {
        std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(now - _time).count();
    }

    void Clock::reset()
    {
        _time = std::chrono::high_resolution_clock::now();
    }
}