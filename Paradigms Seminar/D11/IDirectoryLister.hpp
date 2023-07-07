/*
** EPITECH PROJECT, 2023
** day11
** File description:
** IDirectoryLister
*/

#pragma once
#include <string>
#include <dirent.h>

class IDirectoryLister {
    protected:
        DIR *dir;
        bool _hidden;
        std::string path;
    public:
        ~IDirectoryLister() = default;
        virtual bool open(const std::string& path, bool hidden) = 0;
        virtual std::string get() = 0;
};
