/*
** EPITECH PROJECT, 2023
** day09
** File description:
** Priest
*/

#pragma once
#include "Enchanter.hpp"

class Priest: public virtual Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();
        void rest();
    protected:
    private:
};
