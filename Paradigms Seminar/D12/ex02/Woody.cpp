/*
** EPITECH PROJECT, 2022
** cpp_day8
** File description:
** Woody.cpp
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &file) : Toy(WOODY, name, file)
{
    _type = WOODY;
    _name = name;
    Picture::getPictureFromFile(file);
}

Woody::~Woody()
{
}

void Woody::speak(const std::string &statement)
{
    std::cout << "WOODY: " << _name << " \"" << statement << "\"" << std::endl;
}