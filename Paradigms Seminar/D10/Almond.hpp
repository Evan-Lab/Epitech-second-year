/*
** EPITECH PROJECT, 2023
** day10
** File description:
** Almond
*/

#pragma once
#include "ANut.hpp"

class Almond: public virtual IFruit, public virtual AFruit, public virtual ANut{
    public:
        Almond();
        ~Almond();
    protected:
    private:
};
