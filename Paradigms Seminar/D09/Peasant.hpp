/*
** EPITECH PROJECT, 2023
** day09
** File description:
** Peasant
*/

#pragma once
#include <string>
#include "ICharacter.hpp"

class Peasant : virtual public ICharacter {
        protected:
        public:
        Peasant(const std::string &name, int power);
        ~Peasant();
        const std::string &getName() const;
        virtual int getPower() const;
        virtual int getHp() const;
        virtual void setHp(int hp);
        virtual void setPower(int power);
        int attack();
        int special();
        void rest();
        void damage(int damage);
        void Peasant_noPower(int power);
        std::string _name;
        int _power;
        int _hp;
};
