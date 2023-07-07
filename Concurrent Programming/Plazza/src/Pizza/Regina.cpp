/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Regina
*/

#include "Regina.hpp"

namespace Plazza
{

    PizzaRegina::PizzaRegina(PizzaSize size, double time, int id)
        : APizza(PizzaType::Regina, size, time, id)
    {
        _ingredient.push_back(Doe);
        _ingredient.push_back(Tomato);
        _ingredient.push_back(Gruyere);
        _ingredient.push_back(Ham);
        _ingredient.push_back(Mushrooms);
        _time = 2.0 * time;
    }

    PizzaRegina::~PizzaRegina()
    {
    }

}