/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** init_ressources_two
*/

#include "server.h"

void alloc_ressources_for_map_two(info_game_t *info_game, int i, int j)
{
    for (int k = 0; k < 7; k++) {
        info_game->map[i][j].ressources[k].name =
        strdup(info_game->ressources[k].name);
        info_game->map[i][j].ressources[k].quantity = 0;
    }
}

void alloc_ressources_for_map(info_game_t *info_game)
{
    for (int i = 0; i < info_game->map_height; i++) {
        for (int j = 0; j < info_game->map_width; j++) {
            info_game->map[i][j].ressources = malloc(sizeof(ressources_t) * 7);
            alloc_ressources_for_map_two(info_game, i, j);
        }
    }
}
