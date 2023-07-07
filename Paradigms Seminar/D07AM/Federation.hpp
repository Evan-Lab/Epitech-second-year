/*
** EPITECH PROJECT, 2023
** day07-am
** File description:
** Federation
*/

#pragma once
#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Captain {
        public:
            Captain(std::string name);
            std::string _name;
            int _age;
            std::string getName();
            int getAge();
            void setAge(int age);
        };
        class Ensign {
        public:
            Ensign(std::string name);
            std::string _name;
        };
        class Ship {
        public:
            Ship(int length, int width, std::string name, short maxWarp);
            ~Ship();
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            void promote(Captain *captain);
            Destination _location;
            Destination _home;
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
        };
    };

    class Ship {
    public:
        Ship(int length, int width, std::string name);
        int _length;
        int _width;
        std::string _name;
        WarpSystem::Core *_core;
        void setupCore(WarpSystem::Core *core);
        void checkCore();
    };
}
