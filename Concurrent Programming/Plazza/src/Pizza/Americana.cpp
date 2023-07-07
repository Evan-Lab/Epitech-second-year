/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Americana
*/

#include "Americana.hpp"

namespace Plazza
{

    PizzaAmericana::PizzaAmericana(PizzaSize size, double time, int id)
        : APizza(PizzaType::Americana, size, time, id)
    {
        _ingredient.push_back(Doe);
        _ingredient.push_back(Tomato);
        _ingredient.push_back(Gruyere);
        _ingredient.push_back(Steak);
        _ingredient.push_back(Mushrooms);
    }

    PizzaAmericana::~PizzaAmericana()
    {
    }
}