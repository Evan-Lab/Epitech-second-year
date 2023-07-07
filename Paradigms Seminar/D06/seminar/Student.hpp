/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Student
*/

#include <bits/stdc++.h>

class Student{
    // Name & Energie
    std::string _name;
    int _energy_point;
    // Students status
    public:
    Student(std::string name);
    ~Student();
    // Actions
    bool learn(std::string text);
    void drink(std::string to_drink);
};
