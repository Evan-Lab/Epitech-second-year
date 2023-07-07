/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** do_action
*/

#include "server.h"

void do_action(info_game_t *info, client_t *client, ia_action_t *action)
{
    time_t currentTime = time(NULL);

    if (action->status == 0) {
        if (strcmp(action->name, "Incantation") == 0)
            start_incantation(info, client);
        if (strcmp(action->name, "Fork") == 0)
            start_fork(client, info);
        client->timer->seconds = difftime(currentTime, info->timer->startTime);
        if (client->timer->seconds > (action->time / info->time_unit)) {
            action->function(client, info, action->args);
            client->timer->startTime = time(NULL);
            action->status = 1;
        }
    }
}

void check_ia_action(info_serv_t *info)
{
    list_client_t *head = info->info_game.list_client;
    list_action_t *action;

    while (head != NULL) {
        action = NULL;
        if (head->client->first_connection == 0 && head->client->type == AI)
            action = head->client->action;
        while (action != NULL) {
            do_action(&info->info_game, head->client, action->action);
            action = action->next;
        }
        player_death(head->client, info);
        head = head->next;
    }
}
