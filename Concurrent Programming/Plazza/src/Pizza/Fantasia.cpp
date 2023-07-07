/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Fantasia
*/

#include "Fantasia.hpp"

namespace Plazza {

    PizzaFantasia::PizzaFantasia(PizzaSize size, double time, int id)
        : APizza(PizzaType::Fantasia, size, time, id)
    {
        _ingredient.push_back(Doe);
        _ingredient.push_back(Tomato);
        _ingredient.push_back(Eggplant);
        _ingredient.push_back(GoatCheese);
        _ingredient.push_back(ChiefLove);
        _time = 4.0 * time;
    }

    PizzaFantasia::~PizzaFantasia()
    {

    }
}