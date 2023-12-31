/*
** EPITECH PROJECT, 2023
** day10
** File description:
** iFruit
*/

#pragma once
#include <string>

class IFruit {
    public:
    virtual ~IFruit()= default;
    virtual unsigned int getVitamins() const = 0;
    virtual std::string getName() const = 0;
    virtual bool isPeeled() const = 0;
    virtual void peel() = 0;
};

std::ostream &operator<<(std::ostream &os, const IFruit &fruit);
