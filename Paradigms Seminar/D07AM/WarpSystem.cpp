/*
** EPITECH PROJECT, 2023
** day07-am
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"
#include "Federation.hpp"
#include <iostream>

bool WarpSystem::QuantumReactor::isStable()
{
    return _stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return _coreReactor;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor::QuantumReactor()
{
    _stability = true;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *coreReactor)
{
    _coreReactor = coreReactor;
}
