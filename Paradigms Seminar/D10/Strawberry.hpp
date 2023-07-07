/*
** EPITECH PROJECT, 2023
** day10
** File description:
** Strawberry
*/

#pragma once
#include "ABerry.hpp"

class Strawberry : public virtual IFruit, public virtual AFruit, public virtual ABerry{
    protected:
    public:
        Strawberry();
        ~Strawberry();
    private:
};
