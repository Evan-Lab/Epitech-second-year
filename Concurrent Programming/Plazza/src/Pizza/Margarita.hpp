/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Margarita
*/

#ifndef MARGARITA_HPP_
    #define MARGARITA_HPP_

    #include "APizza.hpp"

namespace Plazza {
    class PizzaMargarita : public APizza {
        public:
            PizzaMargarita(PizzaSize size, double time, int id);
            ~PizzaMargarita();
    };
}

#endif /* !MARGARITA_HPP_ */