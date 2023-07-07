/*
** EPITECH PROJECT, 2023
** day09
** File description:
** Knight
*/

#pragma once
#include "Peasant.hpp"

class Knight : virtual public Peasant {
    public:
        Knight(const std::string &name, int power);
        ~Knight();
        int attack();
        int special();
        void rest();
    private:
};
