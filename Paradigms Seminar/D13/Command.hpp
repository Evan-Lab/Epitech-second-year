/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Command
*/

#pragma once
#include <map>
#include <string>
#include <functional>
#include <stdexcept>

class Command {
    public:
    class Error : public std::runtime_error {
    public:
        Error(const std::string& what) : std::runtime_error(what) {}
    };
    void registerCommand(const std::string& name, const std::function<void()>& function);
    void executeCommand(const std::string& name);
    private:
    std::map<std::string, std::function<void()>> commands;
};