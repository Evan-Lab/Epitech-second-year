/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** APizza
*/

#include "APizza.hpp"

namespace Plazza
{
    APizza::APizza(PizzaType type, PizzaSize size, double time, int id)
    {
        _type = type;
        _size = size;
        _time = time;
        _status = StatusPizza::toAssign;

        _id = id;
    }

    APizza::~APizza()
    {
    }

    PizzaType APizza::getType() const
    {
        return _type;
    }

    PizzaSize APizza::getSize() const
    {
        return _size;
    }

    std::vector<PizzaIngredient> APizza::getIngredient() const
    {
        return _ingredient;
    }

    std::string APizza::getName() const
    {
        return _name;
    }

    double APizza::getTime() const
    {
        return _time;
    }

    StatusPizza APizza::getStatus() const
    {
        return _status;
    }

    void APizza::setStatus(StatusPizza status)
    {
        _status = status;
    }

    int APizza::getId() const
    {
        return _id;
    }

    void APizza::setId(int id)
    {
        _id = id;
    }

}