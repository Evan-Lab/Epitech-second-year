/*
** EPITECH PROJECT, 2023
** day07-am
** File description:
** Borg
*/

#pragma once
#include <string>
#include "WarpSystem.hpp"
#include "Federation.hpp"
#include "Destination.hpp"

namespace Borg
{
    class Ship {
    public:
        int _side;
        short _maxWarp;
        bool _stability;
        Ship();
        ~Ship();
        WarpSystem::Core *_core;
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        Destination _location;
        Destination _home;
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
    };
}
