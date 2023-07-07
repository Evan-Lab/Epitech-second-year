/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ressources_quantity
*/

#include "server.h"

void create_map(info_game_t *info_game)
{
    int i = 0;
    int j = 0;
    info_game->map = malloc(sizeof(map_t *) * (info_game->map_height + 1));

    while (i < info_game->map_height) {
        info_game->map[i] = malloc(sizeof(map_t) * (info_game->map_width + 1));
        while (j < info_game->map_width) {
            info_game->map[i][j].client = NULL;
            info_game->map[i][j].ressources = NULL;
            info_game->map[i][j].eggs = NULL;
            info_game->map[i][j].egg = 0;
            j++;
        }
        j = 0;
        i++;
    }
    info_game->map[i] = NULL;
}
