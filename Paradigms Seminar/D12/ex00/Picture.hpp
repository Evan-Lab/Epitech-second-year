/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Picture
*/

#pragma once
#include <iostream>

class Picture {
    protected:
        std::string data;
        public:
        Picture();
        ~Picture();
        Picture(const std::string &file);
        bool getPictureFromFile(const std::string &File);
    private:
};
