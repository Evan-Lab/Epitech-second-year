/*
** EPITECH PROJECT, 2023
** day06
** File description:
** RetardUnitConverter
*/

#include <iostream>
#include <sstream>
#include <iomanip>

void operation(float degres, std::string send)
{
    float result;
    if (send == "Celsius") {
        result = degres * 9.0 / 5.0 + 32;
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << result << std::setw(16) << "Fahrenheit" << std::endl;
    } else if (send == "Fahrenheit") {
        result = (degres - 32) * 5.0 / 9.0;
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << result << std::setw(16) << "Celsius" << std::endl;
    }
}

int main(void) {

    std::string input;
    while (std::getline(std::cin, input)) {
        std::istringstream iss(input);
        int count = 0;
        float degres = 0;
        std::string word;

        while (!iss.eof()) {
            if (count == 2)
                break;
            iss >> word;
            if (count == 0) {
            try {
                degres = std::stof(word);
                } catch(std::invalid_argument&) {
                    break;
                }
            } else operation(degres, word);
            count++;
        }
    }
    return 0;
}
