/*
** EPITECH PROJECT, 2023
** day10
** File description:
** AFruit
*/

#pragma once
#include "IFruit.hpp"

class AFruit : public virtual IFruit {
    public:
    unsigned int getVitamins() const override;
    std::string getName() const override;
    bool isPeeled() const override;
    void peel();
    protected:
    std::string _name;
    unsigned int _vitamins;
    bool ispeeled;
};
