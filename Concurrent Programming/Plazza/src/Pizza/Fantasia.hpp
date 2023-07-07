/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Fantasia
*/

#ifndef FANTASIA_HPP_
    #define FANTASIA_HPP_

    #include "APizza.hpp"

namespace Plazza {
    class PizzaFantasia : public APizza {
        public:
            PizzaFantasia(PizzaSize size, double time, int id);
            ~PizzaFantasia();
    };
}

#endif /* !FANTASIA_HPP_ */