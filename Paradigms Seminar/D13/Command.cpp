/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Command
*/

#include "Command.hpp"

void Command::registerCommand(const std::string& name, const std::function<void()>& function)
{
    if (commands.count(name) > 0) {
        throw Error("Already registered command");
    }
    commands[name] = function;
}

void Command::executeCommand(const std::string& name)
{
    if (commands.count(name) == 0) {
        throw Error("Unknow command");
    }
    commands[name]();
}
