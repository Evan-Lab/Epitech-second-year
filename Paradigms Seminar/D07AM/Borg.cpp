/*
** EPITECH PROJECT, 2023
** day07-am
** File description:
** Borg
*/

#include "Borg.hpp"
#include "Federation.hpp"
#include "WarpSystem.hpp"
#include <iostream>
#include <fstream>

Borg::Ship::Ship() : _side(300), _maxWarp(9)
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore()
{
    if (_core->checkReactor()->isStable() == true)
        std::cout << "Everything is in order." << std::endl;
     else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    } else return false;
}

bool Borg::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    } else return false;
}

bool Borg::Ship::move()
{
    if (_core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    } else return false;
}
