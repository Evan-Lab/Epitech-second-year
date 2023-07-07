/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Student
*/

#include <iostream>
#include "Student.hpp"

//Create Student

Student::Student(std::string name)
{
    _name = name;
    _energy_point = 100;
    std::cout << "Student " << _name << ": I'm ready to learn C++." << std::endl;
}

//Destroy Student

Student::~Student()
{
    std::cout << "Student " << _name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

//Replace by shit

void replace_all(std::string &str, const std::string &from, const std::string &to)
{
    size_t start_lenght = 0;
    while ((start_lenght = str.find(from, start_lenght)) != std::string::npos) {
        str.replace(start_lenght, from.length(), to);
        start_lenght += to.length();
    }
}

//Student drink for Energy

void Student::drink(std::string to_drink)
{
    if (to_drink == "Red Bull") {
        _energy_point += 32;
        if (_energy_point > 100)
            _energy_point = 100;
        std::cout << "Student " << _name << ": Red Bull gives you wings!" << std::endl;
    } else if (to_drink == "Monster") {
        _energy_point += 64;
        if (_energy_point > 100)
            _energy_point = 100;
        std::cout << "Student " << _name << ": Unleash The Beast!" << std::endl;
    } else {
        _energy_point += 1;
        if (_energy_point > 100)
            _energy_point = 100;
        std::cout << "Student " << _name << ": ah, yes... enslaved moisture." << std::endl;
    }
}

//Student learn lose Energy

bool Student::learn(std::string text)
{
    if (_energy_point - 42 < 0) {
        replace_all(text, "C++", "shit");
        std::cout << "Student " << _name << ": " << text << std::endl;
        return false;
    }
    _energy_point -= 42;
    std::cout << "Student " << _name << ": " << text << std::endl;
    return true;
}
