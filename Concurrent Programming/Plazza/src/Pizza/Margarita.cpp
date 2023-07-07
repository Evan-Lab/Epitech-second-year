/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Margarita
*/

#include "Margarita.hpp"

namespace Plazza {

    PizzaMargarita::PizzaMargarita(PizzaSize size, double time, int id)
        : APizza(PizzaType::Margarita, size, time, id)
    {
        _ingredient.push_back(Doe);
        _ingredient.push_back(Tomato);
        _ingredient.push_back(Gruyere);
        _time = 1.0 * time;
    }

    PizzaMargarita::~PizzaMargarita()
    {

    }
}