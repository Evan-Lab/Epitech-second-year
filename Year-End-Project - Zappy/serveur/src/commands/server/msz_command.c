/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** msz_command
*/

#include "server.h"

void msz_command(client_t *client, info_serv_t *serv, char **arg)
{
    (void)arg;
    dprintf(client->socket, "msz %d %d\n", serv->info_game.map_width,
    serv->info_game.map_height);
}
