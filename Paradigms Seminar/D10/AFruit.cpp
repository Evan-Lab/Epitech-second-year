/*
** EPITECH PROJECT, 2023
** day10
** File description:
** AFruit
*/

#include "AFruit.hpp"

unsigned int AFruit::getVitamins() const
{
    if (this->ispeeled == false)
        return 0;
    return _vitamins;
}

std::string AFruit::getName() const
{
    return _name;
}

bool AFruit::isPeeled() const
{
    return ispeeled;
}

void AFruit::peel()
{
    ispeeled = true;
}
