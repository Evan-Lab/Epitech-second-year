/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Regina
*/

#ifndef REGINA_HPP_
    #define REGINA_HPP_

    #include "APizza.hpp"

namespace Plazza
{
    class PizzaRegina : public APizza
    {
    public:
        PizzaRegina(PizzaSize size, double time, int id);
        ~PizzaRegina();
    };
}
#endif /* !REGINA_HPP_ */