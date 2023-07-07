/*
** EPITECH PROJECT, 2022
** cpp_day8
** File description:
** Buzz.cpp
*/
#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file) : Toy(BUZZ, name, file) {
    _type = BUZZ;
    _name = name;
    Picture::getPictureFromFile(file);
}

Buzz::~Buzz() {}

void Buzz::speak(const std::string &statement) {
    std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
}