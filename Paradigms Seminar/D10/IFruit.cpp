/*
** EPITECH PROJECT, 2023
** day10
** File description:
** IFruit
*/

#include "IFruit.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const IFruit &fruit)
{
    os << "[name: \"" << fruit.getName() << "\", vitamins: " << fruit.getVitamins() << ", " << (fruit.isPeeled() ? "peeled: true]" : "peeled: false]");
    return os;
}
