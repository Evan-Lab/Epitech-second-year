/*
** EPITECH PROJECT, 2022
** cpp_day7
** File description:
** Toy.hpp
*/
#pragma once
#include <iostream>
#include "Picture.hpp"

class Toy : public Picture {
    public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };
    Toy(ToyType type, const std::string &name, const std::string &file);
    Toy();
    ~Toy();
    ToyType getType() const;
    std::string getName() const;
    std::string getAscii() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &file);

    void speak(const std::string &statement);

    protected:
        ToyType _type;
        std::string _name;
};