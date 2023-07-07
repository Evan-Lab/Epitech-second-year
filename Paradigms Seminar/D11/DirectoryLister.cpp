/*
** EPITECH PROJECT, 2023
** day11
** File description:
** DirectoryLister
*/

#include "IDirectoryLister.hpp"
#include "DirectoryLister.hpp"
#include <dirent.h>
#include <cstdio>
#include <string>
#include <iostream>

DirectoryLister::DirectoryLister()
{
}

DirectoryLister::~DirectoryLister()
{
    if (dir != nullptr)
        closedir(dir);
}

DirectoryLister::DirectoryLister(const std::string &path, bool hidden)
{
    dir = NULL;
    open(path, hidden);
}

bool DirectoryLister::open(const std::string &path, bool hidden)
{
    _hidden = hidden;
    if (dir != nullptr)
        closedir(dir);
    dir = opendir(path.c_str());
    if (dir == NULL) {
        perror(path.c_str());
        return false;
    }
    return true;
}

std::string DirectoryLister::get()
{
    if (!dir) {
        return "";
    }
    struct dirent *end;
    end = readdir(dir);
    if (_hidden == false)
        while (end != nullptr && end->d_name[0] == '.') {
            end = readdir(dir);
        }
    if (end != NULL)
        return end->d_name;
    return "";
}
