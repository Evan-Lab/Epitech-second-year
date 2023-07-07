/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** connect_nbr_command
*/

#include "server.h"

void connect_nbr_commad(client_t *client, info_game_t *info, char *args)
{
    (void)args;
    int value = 0;
    list_client_t *current_client = info->list_client;
    teams_t *teams;

    while (current_client != NULL) {
        if (current_client->client->type == AI &&
        strcmp(current_client->client->team_name, client->team_name) == 0) {
            ++value;
        }
        current_client = current_client->next;
    }
    teams = get_teams_by_name(&info->teams_name, client->team_name);
    value = teams->nb_connection - value;
    dprintf(client->socket, "%d\n", value);
}
