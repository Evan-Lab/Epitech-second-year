/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Toy
*/

#pragma once
#include "Picture.hpp"
#include <iostream>

class Toy : public Picture {
    public:
    enum ToyType {
        BASIC_TOY,
        ALIEN
    };
    Toy();
    ~Toy();
    Toy(ToyType type, const std::string &name, const std::string &file);
    ToyType getType() const;
    std::string getName() const;
    std::string getAscii() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &file);
    protected:
        ToyType _type;
        std::string _name;
    private:
};
