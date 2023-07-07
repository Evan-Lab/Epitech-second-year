/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** tools
*/

#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>
#include "enum.hpp"

int randInt(int min, int max);
bool collisionPoint(const sf::Vector2i point, const sf::FloatRect rect);
std::vector<std::string> strToWordArray(std::string str, char c);
