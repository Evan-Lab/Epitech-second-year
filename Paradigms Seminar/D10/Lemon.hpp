/*
** EPITECH PROJECT, 2023
** day10
** File description:
** Lemon
*/

#pragma once
#include "ACitrus.hpp"

class Lemon : public virtual IFruit, public virtual AFruit, public virtual ACitrus{
    protected:
    public:
        Lemon();
        ~Lemon();
};
