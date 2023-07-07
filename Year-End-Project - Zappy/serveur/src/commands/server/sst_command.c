/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** stt_command
*/

#include "server.h"

void sst_command(client_t *client, info_serv_t *serv, char **args)
{
    char *argv2 = args[1];

    if (argv2 == NULL)
        return;

    serv->info_game.time_unit = atoi(argv2);
    dprintf(client->socket, "sst %d\n", serv->info_game.time_unit);
}
