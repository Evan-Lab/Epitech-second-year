/*
** EPITECH PROJECT, 2023
** day09
** File description:
** Paladin
*/

#include "Paladin.hpp"
#include <iostream>

Paladin::Paladin(const std::string &name, int power) : Peasant(name, power), Knight(name, power), Enchanter(name, power), Priest(name, power)
{
    std::cout << name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << _name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    return Knight::attack();
}

int Paladin::special()
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    return Priest::special();
}

void Paladin::rest()
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    Priest::rest();
}
