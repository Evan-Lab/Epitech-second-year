/*
** EPITECH PROJECT, 2023
** day09
** File description:
** Priest
*/

#include "Priest.hpp"
#include <iostream>

Priest::Priest(const std::string &name, int power): Peasant(name, power), Enchanter(name, power)
{
    std::cout << name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << _name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    _power = 100;
    _hp = 100;
    std::cout << _name << " prays." << std::endl;
}

