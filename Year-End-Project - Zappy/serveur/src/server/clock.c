/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** clock
*/

#include "server.h"

void create_game_clock(info_game_t *info_game)
{
    info_game->timer = malloc(sizeof(clock_struct_t));

    info_game->timer->startTime = time(NULL);
    info_game->timer->seconds = 0;
}

void start_clock_client(list_client_t **list)
{
    list_client_t *head = *list;

    if (head == NULL)
        return;
    while (head != NULL) {
        if (get_len_list_action(head->client->action) > 1
            && head->client->type == AI)
            head->client->timer->startTime = time(NULL);
        head = head->next;
    }
}
