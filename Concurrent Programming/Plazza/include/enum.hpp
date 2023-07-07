/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** enum
*/

#ifndef ENUM_HPP_
    #define ENUM_HPP_

namespace Plazza {

    enum PizzaType
    {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    enum PizzaIngredient
    {
        Doe,
        Tomato,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        Eggplant,
        GoatCheese,
        ChiefLove,
    };

    enum StatusPizza
    {
        ready,
        toAssign,
        inCook,
        inKitchen,
    };

}


#endif /* !ENUM_HPP_ */
