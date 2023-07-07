/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** variables
*/

#pragma once

#include <cmath>

#define TILE_SIZE 250
#define WINDOW_WIDTH window->getSize().x
#define WINDOW_HEIGHT window->getSize().y
#define MAP_SIZE 10
#define MAP_POS_X WINDOW_WIDTH / 4
#define MAP_POS_Y WINDOW_HEIGHT / (MAP_SIZE)
#define WAVE_SPEED 75 //vitesse des vagues
#define WAVE_AMPLITUDE 100.0f //amplitude des vagues
#define WAVE_FREQUENCY 0.001f //fréquence des vagues
#define WAVE_VERTICAL_STEP 10 //nombre d'étape pour atteindre la hauteur max
#define WAVE_VERTICAL_MULT 1.2 //multiplicateur de la hauteur max (hauteur max = WAVE_VERTICAL_STEP * WAVE_VERTICAL_MULT)
#define WATER_COLOR sf::Color(0, 100, 200, 220)
