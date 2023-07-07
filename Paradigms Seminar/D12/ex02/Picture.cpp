/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Picture
*/

#include "Picture.hpp"
#include <iostream>
#include <fstream>

Picture::Picture()
{
    data = "";
}

Picture::~Picture()
{
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &File)
{
    std::ifstream file(File);
    std::string buff = "";
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            buff = buff + line + "\n";
        }
        file.close();
        data = buff;
        return true;
    }
    data = "ERROR";
    return false;
}