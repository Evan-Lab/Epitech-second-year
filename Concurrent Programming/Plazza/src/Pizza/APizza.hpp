/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** APizza
*/

#ifndef APIZZA_HPP_
    #define APIZZA_HPP_

    #include <vector>
    #include <string>
    #include "IPizza.hpp"

namespace Plazza
{
    class APizza : public IPizza
    {
    public:
        APizza(PizzaType type, PizzaSize size, double time, int id);
        virtual ~APizza() = 0;

        PizzaType getType() const override;
        PizzaSize getSize() const override;

        std::vector<PizzaIngredient> getIngredient() const override;
        std::string getName() const override;
        double getTime() const override;

        StatusPizza getStatus() const override;
        void setStatus(StatusPizza status) override;

        int getId() const override;
        void setId(int id) override;

    protected:
        PizzaType _type;
        PizzaSize _size;
        std::vector<PizzaIngredient> _ingredient;
        double _time;
        std::string _name;
        StatusPizza _status;

        int _id;
    };
}

#endif /* !APIZZA_HPP_ */
