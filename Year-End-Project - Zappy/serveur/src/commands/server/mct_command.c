/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** mct_command
*/

#include "server.h"

void mct_command(client_t *client, info_serv_t *serv, char **arg)
{
    (void)arg;

    for (int y = 0; y < serv->info_game.map_height; y++) {
        for (int x = 0; x < serv->info_game.map_width; x++) {
            dprintf(client->socket, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
            serv->info_game.map[y][x].ressources[0].quantity,
            serv->info_game.map[y][x].ressources[1].quantity,
            serv->info_game.map[y][x].ressources[2].quantity,
            serv->info_game.map[y][x].ressources[3].quantity,
            serv->info_game.map[y][x].ressources[4].quantity,
            serv->info_game.map[y][x].ressources[5].quantity,
            serv->info_game.map[y][x].ressources[6].quantity);
        }
    }
}
