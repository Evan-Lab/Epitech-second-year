/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Americana
*/

#ifndef AMERICANA_HPP_
    #define AMERICANA_HPP_

    #include "APizza.hpp"

    namespace Plazza
    {
        class PizzaAmericana : public APizza {
            public:
                PizzaAmericana(PizzaSize size, double time, int id);
                ~PizzaAmericana();
        };
    }

#endif /* !AMERICANA_HPP_ */