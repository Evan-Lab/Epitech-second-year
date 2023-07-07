/*
** EPITECH PROJECT, 2023
** day09
** File description:
** ICharacter
*/

#pragma once
#include <string>

class ICharacter {
    public:
        virtual ~ICharacter() = default;
        virtual const std::string &getName() const = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;
        virtual void setHp(int hp) = 0;
        virtual void setPower(int power) = 0;
        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;
        virtual void Peasant_noPower(int power) = 0;
};
