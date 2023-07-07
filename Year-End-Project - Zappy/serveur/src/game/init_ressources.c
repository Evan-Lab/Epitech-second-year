/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_ressources
*/

#include "server.h"

void ressources_distribution_two(info_game_t *info_game, int max_quantity,
int r)
{
    for (int quantity = 0; quantity < max_quantity; quantity++) {
        int x = rand() % info_game->map_width;
        int y = rand() % info_game->map_height;
        if (info_game->ressources[r].quantity > 0) {
            info_game->map[y][x].ressources[r].quantity++;
            info_game->ressources[r].quantity--;
        }
    }
}

void ressources_distribution(info_game_t *info_game)
{
    alloc_ressources_for_map(info_game);

    int num_resources = 7;
    int max_quantity = 500;

    for (int r = 0; r < num_resources; r++) {
        ressources_distribution_two(info_game, max_quantity, r);
    }
}

void init_ressources_two(info_game_t *info_game)
{
    info_game->ressources[3].name = "sibur";
    info_game->ressources[3].quantity = (info_game->map_width *
    info_game->map_height) * 0.1;
    info_game->ressources[4].name = "mendiane";
    info_game->ressources[4].quantity = (info_game->map_width *
    info_game->map_height) * 0.1;
    info_game->ressources[5].name = "phiras";
    info_game->ressources[5].quantity = (info_game->map_width *
    info_game->map_height) * 0.08;
    info_game->ressources[6].name = "thystame";
    info_game->ressources[6].quantity = (info_game->map_width *
    info_game->map_height) * 0.05;
}

void init_ressources(info_game_t *info_game)
{
    info_game->ressources[0].name = "food";
    info_game->ressources[0].quantity = (info_game->map_width *
    info_game->map_height) * 0.5;
    info_game->ressources[1].name = "linemate";
    info_game->ressources[1].quantity = (info_game->map_width *
    info_game->map_height) * 0.3;
    info_game->ressources[2].name = "deraumere";
    info_game->ressources[2].quantity = (info_game->map_width *
    info_game->map_height) * 0.15;
    init_ressources_two(info_game);
}
