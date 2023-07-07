/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** ressources_printer
*/

#include "server.h"

void print_ressources_each_case_two(info_game_t *info_game, int i, int j)
{
    for (int k = 0; k < 7; k++) {
        printf("Ressource : %s, Quantité : %d\n",
        info_game->map[i][j].ressources[k].name,
        info_game->map[i][j].ressources[k].quantity);
    }
}

void print_ressources_each_case(info_game_t *info_game)
{
    for (int i = 0; i < info_game->map_height; i++) {
        for (int j = 0; j < info_game->map_width; j++) {
            printf("Case %d %d :\n", i, j);
            print_ressources_each_case_two(info_game, i, j);
        }
    }
}

void print_ressources_quantity(info_game_t *info_game)
{
    for (int i = 0; i < 7; i++) {
        printf("Ressource %s, Quantité : %d\n", info_game->ressources[i].name,
        info_game->ressources[i].quantity);
    }
}
