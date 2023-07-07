/*
** EPITECH PROJECT, 2023
** day09
** File description:
** Knight
*/

#include "Knight.hpp"
#include <string>
#include <iostream>

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << _name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else if (_power < 10)
        std::cout << _name << " is out of power." << std::endl;
    else {
        _power -= 10;
        std::cout << _name << " strikes with his sword." << std::endl;
        return 20;
    }
    return 0;
}

int Knight::special()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else if (_power < 30)
        std::cout << _name << " is out of power." << std::endl;
    else {
        _power -= 30;
        std::cout << _name << " impales his enemy." << std::endl;
        return 50;
    }
    return 0;
}

void Knight::rest()
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    } else if (_power + 50 > 100)
        _power = 100;
    else
        _power += 50;
    std::cout << _name << " eats." << std::endl;
}
