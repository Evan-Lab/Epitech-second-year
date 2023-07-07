/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** main
*/

#include "Utils/IPC.hpp"
#include "Pizza/IPizza.hpp"
#include "Reception/Reception.hpp"
#include "Error_handling/Error_handling.hpp"

int main(int argc, char **argv)
{
    try
    {
        Plazza::Error_handling error(argc, argv);

        double factor = std::stoi(argv[1]);
        int nb_cooks = std::stoi(argv[2]);
        double time = std::stoi(argv[3]);
        //Plazza::IPC ipc("/", 4);
        Plazza::Reception reception(factor, nb_cooks, time/*, ipc*/);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}