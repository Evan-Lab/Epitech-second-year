/*
** EPITECH PROJECT, 2023
** day07-pm
** File description:
** Skat
*/

#include <iostream>
#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks) : _name(name), _stimPaks(stimPaks)
{
}

Skat::~Skat()
{
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}

const int &Skat::stimPaks()
{
    return _stimPaks;
}

const std::string &Skat::name() const
{
    return _name;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    _stimPaks += number;
}

void Skat::useStimPaks()
{
    if (_stimPaks > 0) {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        _stimPaks--;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::shareStimPaks(int number, Skat &stock)
{
    if (number > _stimPaks) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    stock._stimPaks += number;
    _stimPaks -= number;
    std::cout << "Keep the change" << std::endl;
}

int main ()
{
    Skat s("Junior", 5);
    std::cout << "Soldier " << s.name() << std::endl ;
    s.status() ;
    s.useStimPaks() ;
    return 0;
}
