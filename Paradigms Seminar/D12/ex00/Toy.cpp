/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Toy
*/

#include "Toy.hpp"
#include "fstream"

Toy::Toy(ToyType type, const std::string &name, const std::string &file) : Picture(file)
{
    _type = type;
    _name = name;
    Picture::getPictureFromFile(file);
}

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    data = "";
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const
{
    return _type;
}

std::string Toy::getName() const
{
    return _name;
}

std::string Toy::getAscii() const
{
    return data;
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &file) {
    std::ifstream ifs(file);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    if (ifs.fail()) {
        data = "ERROR";
        return false;
    }
    data = content;
    return true;
}