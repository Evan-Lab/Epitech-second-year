/*
** EPITECH PROJECT, 2023
** day09
** File description:
** Peasant
*/

#include "Peasant.hpp"
#include <iostream>

Peasant::Peasant(const std::string &name, int power): _name(name), _power(power), _hp(100)
{
    std::cout << name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return (this->_name);
}

int Peasant::getPower() const
{
    return (this->_power);
}

int Peasant::getHp() const
{
    return (this->_hp);
}

void Peasant::setHp(int hp)
{
    this->_hp = hp;
}

void Peasant::setPower(int power)
{
    this->_power = power;
}

void Peasant::Peasant_noPower(int power)
{
    if (power == 0)
        std::cout << _name << " is out of power." << std::endl;
}

int Peasant::attack()
{
    if (_hp <= 0) {
    std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    if (_power < 10) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    _power-=10;
    std::cout << _name << " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special()
{
    if (_hp == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << _name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    } else {
        std::cout << _name << " takes a nap." << std::endl;
        _power += 30;
        if (_power > 100)
            _power = 100;
    }
}

void Peasant::damage(int damage)
{
    if (_hp <= damage) {
        std::cout << _name << " is out of combat." << std::endl;
        _hp = 0;
        return;
    }
    std::cout << _name << " takes " << damage << " damage." << std::endl;
    _hp -= damage;
    return;
}

