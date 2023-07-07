/*
** EPITECH PROJECT, 2023
** day06
** File description:
** MyCat
*/

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {

    if (argc == 1) {
        std::string line;
        while (std::getline(std::cin, line))
            std::cout << line << std::endl;
    }
    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i]);
        if (!file.is_open()) {
            std::cerr << "MyCat: " << argv[i] << ": No such file or directory" << std::endl;
            return 84;
        }
        std::string line;
        while (getline(file, line))
            std::cout << line << std::endl;
        file.close();
    }
    return 0;
}
