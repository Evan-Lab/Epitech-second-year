/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** eggs
*/

#include <stdlib.h>
#include "structure.h"

void init_eggs(egg_t *eggs, int x, int y, int available)
{
    eggs->x = x;
    eggs->y = y;
    eggs->available = available;
    eggs->id = 0;
}

int check_id(int id, info_game_t *info)
{
    list_client_t *head = info->list_client;

    while (head != NULL) {
        if (head->client->type == AI &&
        head->client->number_client == id)
            return 0;
        head = head->next;
    }
    return 1;
}

void set_id_eggs(egg_t *eggs, info_game_t *info)
{
    int check = 0;
    static int id = 0;

    while (check == 0) {
        ++id;
        check = check_id(id, info);
    }
    eggs->id = id;
    ++id;
}

void add_eggs(list_egg_t **list, egg_t *egg)
{
    list_egg_t *node = malloc(sizeof(list_egg_t));
    list_egg_t *head = *list;

    node->egg = egg;
    node->next = NULL;
    if (*list == NULL) {
        *list = node;
        return;
    }
    while (head->next != NULL)
        head = head->next;
    head->next = node;
}
