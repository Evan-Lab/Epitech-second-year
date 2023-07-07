/*
** EPITECH PROJECT, 2023
** day07-am
** File description:
** Federation
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"
#include <iostream>

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
    _age = 0;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

int Federation::Starfleet::Captain::getAge()
{
    return _age;
}

std::string Federation::Starfleet::Captain::getName()
{
    return _name;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    if (_core->checkReactor()->isStable() == true)
        std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
    else
        std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

void Federation::Ship::checkCore()
{
    if (_core->checkReactor()->isStable() == true)
        std::cout << _name << ": The core is stable at the time." << std::endl;
    else
        std::cout << _name << ": The core is unstable at the time." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    } else return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    } else return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    } else return false;
}

bool Federation::Starfleet::Ship::move()
{
    if (_home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    } else return false;
}
