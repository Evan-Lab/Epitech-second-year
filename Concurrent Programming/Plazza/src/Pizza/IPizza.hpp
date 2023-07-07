/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** IPizza
*/

#ifndef IPIZZA_HPP_
    #define IPIZZA_HPP_

    #include <vector>
    #include <string>
    #include "../../include/enum.hpp"

namespace Plazza
{
    class IPizza
    {
        public:
            virtual ~IPizza() = default;

            virtual PizzaType getType() const = 0;
            virtual PizzaSize getSize() const = 0;

            virtual std::vector<PizzaIngredient> getIngredient() const = 0;
            virtual std::string getName() const = 0;
            virtual double getTime() const = 0;

            virtual StatusPizza getStatus() const = 0;
            virtual void setStatus(StatusPizza status) = 0;

            virtual int getId() const = 0;
            virtual void setId(int id) = 0;
    };
}
#endif /* !IPIZZA_HPP_ */