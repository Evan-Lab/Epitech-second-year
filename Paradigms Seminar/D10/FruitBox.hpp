/*
** EPITECH PROJECT, 2023
** day10
** File description:
** FruitBox
*/

#pragma once
#include "IFruit.hpp"
#include <string>

class FruitBox {
    public:
        FruitBox(unsigned int size);
        ~FruitBox();
    unsigned getSize() const;
    unsigned int nbFruit() const;
    bool pushFruit(IFruit *);
    IFruit *popFruit();
    IFruit **MyFruit;
    private:
    int size;
    int nbFruits;
};

std::ostream &operator<<(std::ostream &os, const FruitBox &box);
