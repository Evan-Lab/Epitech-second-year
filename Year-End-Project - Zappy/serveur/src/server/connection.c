/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** type_client
*/

#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include "server.h"
#include "zappy_server.h"

int available_place_teams(list_client_t **list, char *teams)
{
    list_client_t *head = *list;
    int count = 0;

    while (head != NULL) {
        if (head->client->type == AI &&
        strcmp(teams, head->client->team_name) == 0)
            ++count;
        head = head->next;
    }
    return count;
}

int error_handling_teams(info_game_t *game, char *teams, int socket)
{
    char *teams_name = NULL;
    list_teams_t *head = game->teams_name;

    while (head != NULL) {
        if (strcmp(teams, head->teams->name) == 0) {
            teams_name = strdup(head->teams->name);
            break;
        }
        head = head->next;
    }
    if (available_place_teams(&game->list_client, teams_name)
        > game->client_max || teams_name == NULL) {
        dprintf(socket, "ko\n");
        return -1;
    }
    return 0;
}

void graphic_connection(client_t *client, info_serv_t *info)
{
    client->type = GUI;

    msz_command(client, info, NULL);
    sgt_command(client, info, NULL);
    mct_command(client, info, NULL);
    tna_command(client, info, NULL);
}

void first_connection(client_t *client, char *command, info_serv_t *info)
{
    if (client->first_connection == 0 || command == NULL)
        return;
    client->first_connection = 0;
    dprintf(1, "COMMAND: %s\n", command);
    if (strcmp(command, "GRAPHIC\n") == 0)
        graphic_connection(client, info);
    else {
        command = strdup(clean_str(command, '\r'));
        command = strdup(clean_str(command, '\n'));
        client->team_name = strdup(command);
        if (error_handling_teams(&info->info_game, command, client->socket)
        != -1) {
            init_player_ai(client, &info->info_game);
            client->type = AI;
            dprintf(1, "Adding client in teams success\n");
        } else {
            client->first_connection = 1;
            client->team_name = NULL;
        }
    }
}
