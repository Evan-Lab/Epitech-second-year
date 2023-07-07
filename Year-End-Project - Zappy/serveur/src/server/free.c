/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** free
*/

#include <stdlib.h>
#include "structure.h"

void free_all(info_serv_t *serv)
{
    list_client_t *current = serv->info_game.list_client;
    list_client_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(serv->info_game.teams_name);
    free(serv->info_game.timer);
}
