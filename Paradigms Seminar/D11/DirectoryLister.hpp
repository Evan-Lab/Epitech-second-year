/*
** EPITECH PROJECT, 2023
** day11
** File description:
** DirectoryLister
*/

#pragma once
#include "IDirectoryLister.hpp"
#include <string>
#include <iostream>

class DirectoryLister : public IDirectoryLister {
    protected:
    public:
        DirectoryLister();
        DirectoryLister(const std::string& path, bool hidden);
        ~DirectoryLister();
        bool open(const std::string& path, bool hidden) override;
        std::string get() override;
};
