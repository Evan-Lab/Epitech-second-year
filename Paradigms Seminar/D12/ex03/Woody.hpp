/*
** EPITECH PROJECT, 2022
** cpp_day8
** File description:
** Woody.hpp
*/
#pragma once
#include "Toy.hpp"
#include <string>
#include <iostream>

class Woody : public Toy {
    public:
        Woody(const std::string &name, const std::string &file = "woody.txt");
        ~Woody();
        Woody &operator=(const Woody &woody) = default;
        void speak(const std::string &statement);
};