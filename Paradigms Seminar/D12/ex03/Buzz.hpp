/*
** EPITECH PROJECT, 2022
** cpp_day8
** File description:
** Buzz.hpp
*/
#pragma once
#include <string>
#include <iostream>
#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(const std::string &name, const std::string &file = "buzz.txt");
        Buzz(const Buzz &buzz);
        ~Buzz();

        Buzz &operator=(const Buzz &buzz) = default;
        void speak(const std::string &statement);
};