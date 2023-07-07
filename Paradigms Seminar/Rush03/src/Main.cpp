/*
** EPITECH PROJECT, 2023
** POOL
** File description:
** Main
*/

#include <iostream>
#include <string>
#include <vector>
#include "src/fonction.hpp"

bool selectMode(void)
{
    std::string answer;
    std::string value1;
    std::string value2;

    std::cout << "Select a display mode (Graph/Text) : ";
    getline(std::cin, answer);
    if (answer == "Graph") {
        display_sfml();
    } else if (answer == "Text") {
        std::cout << "get first PID : ";
        getline(std::cin, value1);
        std::cout << "get second PID : ";
        getline(std::cin, value2);
        run_ncurses(atoi(value1.c_str()), atoi(value2.c_str()));
    } else {
        std::cout << "Your answer \"" << answer << "\" is not valid." << std::endl;
        std::cout << "Please select a valid answer next time." << std::endl;
        return false;
    }
    return true;
}

void displayUsage(void)
{
    std::cout << "\t\t+-----------+" << std::endl;
    std::cout << "\t\t| MyGKrellm |" << std::endl;
    std::cout << "\t\t+-----------+" << std::endl << std::endl;
    std::cout << "EXECUTION" << std::endl;
    std::cout << "\t./MyGKrellm" << std::endl << std::endl;
    std::cout << "ARGS :" << std::endl;
    std::cout << "\tNothing" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc > 2)
        return 84;
    if (argc == 2) {
        std::string arg(argv[1]);
        if (arg == "-help") {
            displayUsage();
            return 0;
        }
    }
    if (selectMode() == false)
        std::cout << "For more information : ./MyGKrellm -help" << std::endl;
    return 0;
}
