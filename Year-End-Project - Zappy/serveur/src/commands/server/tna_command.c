/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tna_command
*/

#include "server.h"

void tna_command(client_t *client, info_serv_t *serv, char **arg)
{
    (void)arg;
    list_teams_t *head = serv->info_game.teams_name;

    while (head != NULL) {
        dprintf(client->socket, "tna %s\n", head->teams->name);
        head = head->next;
    }
}
