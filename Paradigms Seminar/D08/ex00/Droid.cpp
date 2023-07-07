/*
** EPITECH PROJECT, 2023
** day08
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _id(""), _energy(50),
    _attack(25), _toughness(15), status(new std::string("Standing by"))
{
    _id = id;
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid): _id(droid._id), _energy(droid._energy),
_attack(droid._attack), _toughness(droid._toughness)
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(void)
{
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

std::string Droid::getId(void) const
{
    return _id;
}

size_t Droid::getEnergy(void) const
{
    return _energy;
}

size_t Droid::getAttack(void) const
{
    return _attack;
}

size_t Droid::getToughness(void) const
{
    return _toughness;
}

std::string *Droid::getStatus(void) const
{
    return (this->status);
}

void Droid::setId(std::string id)
{
    _id = id;
}

void Droid::setEnergy(size_t energy)
{
    _energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->status = status;
}

Droid &Droid::operator<<(size_t &energy)
{
    if (_energy + energy > 100) {
        energy = _energy + energy - 100;
        _energy = 100;
    } else {
        _energy += energy;
        energy = 0;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &s, Droid &droid)
{
    return s << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
}

bool Droid::operator==(Droid const &droid) const
{
    return _id == droid._id && _energy == droid._energy &&
    _attack == droid._attack &&_toughness == droid._toughness &&
    status == droid.status;
}

bool Droid::operator!=(Droid const &droid) const
{
    return _id != droid._id || _energy != droid._energy ||
        _attack != droid._attack || _toughness != droid._toughness ||
        status != droid.status;
}

Droid &Droid::operator=(Droid const &droid)
{
    _id = droid._id;
    _energy = droid._energy;
    return *this;
}
