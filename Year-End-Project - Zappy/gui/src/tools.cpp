/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** tools
*/

#include "tools.hpp"

int randInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

bool collisionPoint(const sf::Vector2i point, const sf::FloatRect rect)
{
    return (point.x >= rect.left && point.x <= rect.left + rect.width &&
            point.y >= rect.top && point.y <= rect.top + rect.height);
}

std::vector<std::string> strToWordArray(std::string str, char c)
{
    size_t pos = 0;
    std::string token;
    std::vector<std::string> list;

    while ((pos = str.find(c)) != std::string::npos) {
        token = str.substr(0, pos);
        list.push_back(token);
        str.erase(0, pos + 1);
    }
    list.push_back(str);
    return list;
}
