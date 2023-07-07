/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** btc_command
*/

#include "server.h"

void btc_command(client_t *client, info_serv_t *serv, char **args)
{
    if (args[1] == NULL || args[2] == NULL)
        return;
    int y = atoi(args[2]);
    int x = atoi(args[1]);

    if (x < 0 || y < 0 || x >= serv->info_game.map_width ||
    y >= serv->info_game.map_height) {
        dprintf(client->socket, "sbp\n");
        return;
    }

    dprintf(client->socket, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
    serv->info_game.map[y][x].ressources[0].quantity,
    serv->info_game.map[y][x].ressources[1].quantity,
    serv->info_game.map[y][x].ressources[2].quantity,
    serv->info_game.map[y][x].ressources[3].quantity,
    serv->info_game.map[y][x].ressources[4].quantity,
    serv->info_game.map[y][x].ressources[5].quantity,
    serv->info_game.map[y][x].ressources[6].quantity);
}
