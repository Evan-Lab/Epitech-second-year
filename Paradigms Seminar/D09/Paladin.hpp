/*
** EPITECH PROJECT, 2023
** day09
** File description:
** Paladin
*/

#pragma once
#include "Knight.hpp"
#include "Priest.hpp"
#include "Peasant.hpp"
#include "Enchanter.hpp"

class Paladin: virtual public Knight, Priest {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();
        int attack();
        int special();
        void rest();
    protected:
    private:
};
