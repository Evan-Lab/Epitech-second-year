/*
** EPITECH PROJECT, 2023
** day09
** File description:
** Enchanter
*/

#include "Enchanter.hpp"
#include <iostream>

Enchanter::Enchanter(const std::string &name, int power): Peasant(name, power)
{
    std::cout << name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << _name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else if (_power <= 0)
        std::cout << _name << " is out of power." << std::endl;
    else
        std::cout << _name << " doesn't know how to fight." << std::endl;
    return (0);
}

int Enchanter::special()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else if (_power < 50)
        std::cout << _name << " is out of power." << std::endl;
    else {
        _power -= 50;
        std::cout << _name << " casts a fireball." << std::endl;
        return 99;
    }
    return 0;
}

void Enchanter::rest()
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    _power = 100;
    std::cout << _name << " meditates." << std::endl;
}
